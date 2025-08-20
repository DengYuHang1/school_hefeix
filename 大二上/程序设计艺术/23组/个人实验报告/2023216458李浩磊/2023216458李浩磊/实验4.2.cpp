#include <stdio.h>

#define MAXN 100

int main() {
    int n;
    int matrix[MAXN][MAXN];
    int maxSum = 0;

    // 输入矩阵的大小
    printf("输入n: ");
    scanf("%d", &n);

    // 输入矩阵的元素
    printf("输入矩阵的元素:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 遍历所有可能的子矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < n; l++) {
                    int sum = 0;
                    // 计算子矩阵(i, j)到(k, l)的和
                    for (int m = i; m <= k; m++) {
                        for (int n = j; n <= l; n++) {
                            sum += matrix[m][n];
                        }
                    }
                    // 更新最大和
                    if (sum > maxSum) {
                        maxSum = sum;
                    }
                }
            }
        }
    }

    // 输出最大和
    printf("%d\n", maxSum);

    return 0;
}
