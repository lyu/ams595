import dis

def foo(a, len):
    for i in range(len):
        a[i] = i

def bar(a, len):
    result = 0
    if a[len - 1] < 5:
        result = -1
    elif a[len - 1] > 7:
        result = 0
    else:
        result = 1
    return result

N = 8
a = [0] * N
foo(a, N)
print(bar(a, N))

print("\n===== foo function =====")

dis.dis(foo)

print("\n===== bar function =====")

dis.dis(bar)
