# daxpy: double-precision a times x plus y
# Python is dog slow
# Yes, I know numpy is fast, but numpy is written in C/C++
def daxpy(a, x, y, N):
    for i in range(N):
        y[i] = a * x[i] + y[i]

N = 2 ** 25
x = [0] * N
y = [0] * N

for i in range(N):
    x[i] = float(i)
    y[i] = -float(i)

daxpy(1.2, x, y, N)

print(y[1])
