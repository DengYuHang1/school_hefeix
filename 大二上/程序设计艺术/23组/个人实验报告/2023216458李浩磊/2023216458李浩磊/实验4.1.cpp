#include <stdio.h>
#include <string.h>

void LCS(char *X, char *Y, int m, int n);

int main() {
    char X[1000], Y[1000];
    printf("字符串1: ");
    scanf("%s", X);
    printf("字符串2: ");
    scanf("%s", Y);
    int m = strlen(X);
    int n = strlen(Y);
    LCS(X, Y, m, n);
    return 0;
}

void LCS(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];

    // 构建L[m+1][n+1]，其中L[i][j]包含X[0..i-1]和Y[0..j-1]的LCS的长度
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    // 通过L[m][n]回溯找到LCS
    int index = L[m][n];
    char LCS[index + 1];
    LCS[index] = '\0'; // 设置字符串结束符

    // 从L[m][n]开始回溯
    int i = m, j = n;
    while (i > 0 && j > 0) {
        // 如果当前字符在X和Y中相同，则它是LCS的一部分
        if (X[i - 1] == Y[j - 1]) {
            LCS[index - 1] = X[i - 1]; // 将字符放在LCS的当前位置
            i--;
            j--;
            index--; // 移动到下一个位置
        }
        // 如果不同，则从L[i-1][j]和L[i][j-1]中选择较大的一个
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }
    printf("%s\n", LCS);
}

