#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

double solver(int k, int n) 
{
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));
    
    // 长度为1的数字有1种表示方法
    for (int j = 0; j <= k; j++) 
    {
        dp[1][j] = 1;
    }
    
    // 动态规划
    for (int i = 2; i <= n; i++) 
    {
        for (int j = 0; j <= k; j++) 
        {
            dp[i][j] = dp[i-1][j]; // 自身
            if (j > 0) 
                dp[i][j] += dp[i-1][j-1]; // 前一个数字为 j-1
            if (j < k) 
                dp[i][j] += dp[i-1][j+1]; // 前一个数字为 j+1
        }
    }
    
    // 计算符合条件的单词总数
    long long validWords = 0;
    for (int j = 0; j <= k; j++) 
    {
        validWords += dp[n][j];
    }
    
    // 返回符合条件的单词比率
    return (double)validWords / pow(k+1, n) * 100;
}

int main() 
{
    int k, n;
    cout << "Enter k and n: ";
    cin >> k >> n;
    
    // 输出结果，保留5位小数
    cout << fixed << setprecision(5) << solver(k, n) << endl;
    
    return 0;
}
