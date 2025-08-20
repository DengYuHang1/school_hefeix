import numpy as np


def f(x):
    if x == 0:
        return 1
    else:
        return np.sin(x) / x


def composite_simpson(a, b, n):
    h = (b - a) / n
    sum1 = 0
    sum2 = 0
    for i in range(1, n, 2):
        sum1 += f(a + i * h)
    for j in range(2, n - 1, 2):
        sum2 += f(a + j * h)
    return (h / 3) * (f(a) + f(b) + 4 * sum1 + 2 * sum2)


a = 0
b = 1
n = 4
result = composite_simpson(a, b, n)
print("", result)
