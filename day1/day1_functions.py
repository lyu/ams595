def foo(n):
    return 2 * n

def square(x):
    return x ** 2

def cubic(x):
    return x ** 3

print(square(cubic(2)))
print(cubic(square(2)))
