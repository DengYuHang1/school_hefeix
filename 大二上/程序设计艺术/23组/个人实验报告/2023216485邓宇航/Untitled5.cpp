#include <iostream>
#include <vector>
#include <cmath>  // 用于 pow 函数

using namespace std;

double calculateTightWordRatio(int k, int n) {
    vector<vector<long long> > dp(n + 1, vector<long long>(k + 1, 0));

    // 初始化长度为1的tight word
    for (int j = 0; j <= k; ++j) {
        dp[1][j] = 1;
    }

    // 动态规划填充dp数组
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (j > 0) dp[i][j] += dp[i - 1][j - 1];
            if (j < k) dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] += dp[i - 1][j];
        }
    }

    // 计算所有长度为n的tight word的数量
    long long totalTightWords = 0;
    for (int j = 0; j <= k; ++j) {
        totalTightWords += dp[n][j];
    }

    // 计算所有可能的长度为n的word的总数
    long long totalWords = pow(k + 1, n);

    // 返回比率
    return (double)totalTightWords / totalWords;
}

int main() {
    int k, n;
    cout << "请输入k: ";
    cin >> k;
    cout << "请输入n: ";
    cin >> n;

    double ratio = calculateTightWordRatio(k, n);
    cout << fixed;  // 使用固定小数点表示法
    cout.precision(8);  // 设置小数点后8位
    cout << "长度为 " << n << " 的 tight word 在所有的 word 中的比率为: " << ratio << endl;

    return 0;
}
