import numpy as np


# 拉格朗日插值多项式
def lagrange_interpolation(x, y, target_x):
    result = 0
    for i in range(len(x)):
        term = y[i]
        for j in range(len(x)):
            if j!= i:
                term *= (target_x - x[j]) / (x[i] - x[j])
        result += term
    return result


# 误差估计函数
def error_estimate(x, target_x):
    max_xi = max(x)
    min_xi = min(x)
    xi = max_xi
    if abs(target_x - min_xi) > abs(target_x - max_xi):
        xi = min_xi
    derivative_3 = 3 / (8 * xi ** 2 * np.sqrt(xi))
    product = 1
    for xi_ in x:
        product *= (target_x - xi_)
    return abs(1/6 * derivative_3 * product)


# 选择节点
x = np.array([100, 121, 144])
y = np.array([10, 11, 12])
target_x = 115
approx_value = lagrange_interpolation(x, y, target_x)
error = error_estimate(x, target_x)
print("Approximate value of sqrt(115):", approx_value)
print("Error estimate:", error)
