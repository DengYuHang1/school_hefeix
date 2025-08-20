#include <stdio.h>
#include <math.h>

double start(int k, int n) {
    // 初始化动态规划数组
    long long dp[n+1][k+1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = 0;
        }
    }
    
    // 初始化长度为1的tight word
    for (int j = 0; j <= k; ++j) {
        dp[1][j] = 1;
    }
    
    // 计算所有长度为n的tight word
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = dp[i-1][j]; // 当前数字
            if (j > 0) dp[i][j] += dp[i-1][j-1]; // 前一个数字
            if (j < k) dp[i][j] += dp[i-1][j+1]; // 后一个数字
        }
    }
    
    // 计算tight word的总数
    long long tight_word_count = 0;
    for (int j = 0; j <= k; ++j) {
        tight_word_count += dp[n][j];
    }
    
    // 计算所有可能的word的总数
    double all_word_count = pow(k+1, n);
    
    // 计算比率
    return tight_word_count / all_word_count;
}

int main() {
    int k, n;
    printf("k,n=");
    scanf("%d %d", &k, &n);
    double rate = start(k, n);
    rate*=100;
    printf("%.5f\n", rate);
    return 0;
}
