#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>  // 用于INT_MAX

using namespace std;

int minDistance(const string& a, const string& b) {
    int m = a.size(), n = b.size();
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    // 初始化边界条件
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;  // 将a的前i个字符变成空串需要i次删除
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;  // 将空串变成b的前j个字符需要j次插入
    }

    // 填充DP表
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // 字符相同，不需要额外操作
            } else {
                // 使用INT_MAX来简化最小值计算
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string a, b;
    cout << "请输入字符串a: ";
    cin >> a;
    cout << "请输入字符串b: ";
    cin >> b;

    int result = minDistance(a, b);
    cout << "将字符串a变为字符串b所需的最少操作次数是: " << result << endl;

    return 0;
}
