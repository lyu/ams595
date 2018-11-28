// Solving a 2D IBVP using the Peaceman-Rachford alternating direction
// implicit method, together with the Gauss–Seidel linear solver.
//
// On Linux, GCC's profile-guided optimization can result in a ~40%
// speedup, for this particular program.
//
// To generate the profile, compile with -fprofile-generate, and run the program once
// To use the generated profile, compile again with -fprofile-use
//
// Microsoft's MSVC also supports PGO, you can check their documentation.
#include <iostream>
#include <cmath>


void vec2mat(int I, int J, double* vec, double** mat) {
    for (int i = 0; i < I; i++)
        mat[i] = &(vec[i * J]);
}


// Assuming out is zero-filled
void mat_x_vec(int I, int J, double** mat, double* vec, double* out) {
    for (int i = 0; i < I; i++) {
        for (int j = 0; j < J; j++) {
            out[i] += mat[i][j] * vec[j];
        }
    }
}


void gauss_seidel(int n, double** A, double* b, double* x, double eps, int maxit) {
    for (int k = 0; k < maxit; k++) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            double dx = b[i];

            for (int j = 0; j < n; j++)
                dx -= A[i][j] * x[j];

            dx /= A[i][i];
            x[i] += dx;
            sum += std::abs(dx);
        }

        if (sum < eps)
            break;
    }
}


double err_2_norm(int n, double* x, double* y) {
    double norm = 0;

    for (int i = 0; i < n; i++) {
        double diff = std::abs(x[i] - y[i]);
        norm += diff * diff;
    }

    return std::sqrt(norm);
}


double err_infty_norm(int n, double* x, double* y) {
    double norm = 0;

    for (int i = 0; i < n; i++) {
        double diff = std::abs(x[i] - y[i]);
        norm = ((norm < diff) ? diff : norm);
    }

    return norm;
}


// Analytical solution
double V(double x, double y, double t) {
    return std::exp(-(x*x+y*y)/(2*t)) / t;
}


// RHS
double f(double x, double y, double t) {
    return std::exp(-(x*x+y*y)/(2*t)) * (2*t-x*x-y*y) / (2*t*t*t);
}


// Initial condition
double vi(double x, double y) {
    return 10 * std::exp(-5*x*x - 5*y*y);
}


// Horizontal BC
double bch(double x, double t) {
    return std::exp(-(x*x+1)/(2*t)) / t;
}


// Vertical BC
double bcv(double y, double t) {
    return std::exp(-(1+y*y)/(2*t)) / t;
}


void solve_heat_equn(int N, int Nl, double* u, double* v) {
    double ds = 2.0 / (N - 1);

    // Number of time steps, computed so that R ~ 0.5
    int M = std::ceil(1 / (ds * ds));
    double t0 = 0.1;
    double dt = 1.0 / M;

    double R = dt / (2 * ds * ds);


    for (int k = 0; k < Nl; k++) {
        int i = std::ceil((k + 1.0) / (N - 2.0));
        int j = k + 1 - (N - 2) * (i - 1);
        u[k] = vi(i * ds - 1, 1 - j * ds);
        v[k] = V(i * ds - 1, 1 - j * ds, t0 + M * dt);
    }

    double* P1_data = new double[Nl * Nl]();
    double* P2_data = new double[Nl * Nl]();
    double* Q1_data = new double[Nl * Nl]();
    double* Q2_data = new double[Nl * Nl]();

    double** P1 = new double*[Nl];
    double** P2 = new double*[Nl];
    double** Q1 = new double*[Nl];
    double** Q2 = new double*[Nl];

    vec2mat(Nl, Nl, P1_data, P1);
    vec2mat(Nl, Nl, P2_data, P2);
    vec2mat(Nl, Nl, Q1_data, Q1);
    vec2mat(Nl, Nl, Q2_data, Q2);

        for (int i = 0; i < Nl; i++) {
            P1[i][i] = 1 + 2 * R;
            Q2[i][i] = 1 - 2 * R;
        }

        for (int i = 0; i < N*N-5*N+6; i++) {
            P1[i + N - 2][i] = -R;
            P1[i][i + N - 2] = -R;
            Q2[i + N - 2][i] = R;
            Q2[i][i + N - 2] = R;
        }

        for (int i = 0; i < Nl; i++) {
            Q1[i][i] = 1 - 2 * R;
            P2[i][i] = 1 + 2 * R;
        }

        for (int i = 0; i < Nl - 1; i++) {
            Q1[i + 1][i] = R;
            Q1[i][i + 1] = R;
            P2[i + 1][i] = -R;
            P2[i][i + 1] = -R;
        }

    // This part will cause data race if put in the above parallel block
    for (int i = 1; i < N - 2; i++) {
        int shift = i * (N - 2);
        Q1[shift][shift - 1] = 0;
        Q1[shift - 1][shift] = 0;
        P2[shift][shift - 1] = 0;
        P2[shift - 1][shift] = 0;
    }


    double eps = 0.000001;
    int maxit = 1000;

    for (int n = 0; n < M; n++) {
        double* RHSn = new double[Nl]();
        double* RHSm = new double[Nl]();
        double* um = new double[Nl]();

        double t = t0 + n * dt;
        double tm = t + dt / 2;
        double tn = t + dt;

        mat_x_vec(Nl, Nl, Q1, u, RHSn);

        for (int k = 0; k < N - 2; k++) {
            double BC = bch((k + 1) * ds - 1, t);
            RHSn[k * (N - 2)] += R * BC;
            RHSn[(k + 1) * (N - 2) - 1] += R * BC;

            BC = bcv(1 - (k + 1) * ds, tm);
            RHSn[k] += R * BC;
            RHSn[(N - 3) * (N - 2) + k] += R * BC;
        }

        for (int k = 0; k < Nl; k++) {
            int i = std::ceil((k + 1.0) / (N - 2.0));
            int j = k + 1 - (N - 2) * (i - 1);
            RHSn[k] += dt / 2 * f(i * ds - 1, 1 - j * ds, tm);
        }

        gauss_seidel(Nl, P1, RHSn, um, eps, maxit);

        mat_x_vec(Nl, Nl, Q2, um, RHSm);

        for (int k = 0; k < N - 2; k++) {
            double BC = bcv(1 - (k + 1) * ds, tm);
            RHSm[k] += R * BC;
            RHSm[(N - 3) * (N - 2) + k] += R * BC;

            BC = bch((k + 1) * ds - 1, tn);
            RHSm[k * (N - 2)] += R * BC;
            RHSm[(k + 1) * (N - 2) - 1] += R * BC;
        }

        for (int k = 0; k < Nl; k++) {
            int i = std::ceil((k + 1.0) / (N - 2.0));
            int j = k + 1 - (N - 2) * (i - 1);
            RHSm[k] += dt / 2 * f(i * ds - 1, 1 - j * ds, tn);
        }

        for (int i = 0; i < Nl; i++)
            u[i] = 0;

        gauss_seidel(Nl, P2, RHSm, u, eps, maxit);

        delete[] RHSm;
        delete[] RHSn;
        delete[] um;
    }


    delete[] P1;
    delete[] P2;
    delete[] Q1;
    delete[] Q2;
    delete[] P1_data;
    delete[] P2_data;
    delete[] Q1_data;
    delete[] Q2_data;
}


int main() {
    // Number of points in one dimension, including the points at the boundary
    int N = 32;

    int Nl = (N - 2) * (N - 2);
    double* u = new double[Nl];
    double* v = new double[Nl];

    solve_heat_equn(N, Nl, u, v);

    std::cout << std::fixed << "Scaled 2-norm error: "
              << err_2_norm(Nl, u, v) / (N - 2)
              << "\nInfinity-norm error: " << err_infty_norm(Nl, u, v) << '\n';

    delete[] u;
    delete[] v;
}
