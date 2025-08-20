import numpy as np


def newton_interpolation(x, y, target_x):
    n = len(x)
    # 差商表
    fdd = np.zeros((n, n))
    for i in range(n):
        fdd[i, 0] = y[i]
    for j in range(1, n):
        for i in range(n - j):
            fdd[i, j] = (fdd[i + 1, j - 1] - fdd[i, j - 1]) / (x[i + j] - x[i])

    # 计算插值结果
    result = fdd[0, 0]
    term = 1
    for j in range(1, n):
        term *= (target_x - x[j - 1])
        result += fdd[0, j] * term
    return result


# 示例数据
x = np.array([1, 2, 4, 5, 6, 8])
y = np.array([0, 2, 8, 12, 18, 28])
target_x = 5.8
print(newton_interpolation(x, y, target_x))
