#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class LCSSolver {
private:
    string buildLCS(const vector<vector<int>> &dp, const string &str1, const string &str2, int i, int j) 
    {
        if (i == 0 || j == 0)
            return "";

        if (str1[i-1] == str2[j-1])
            return buildLCS(dp, str1, str2, i-1, j-1) + str1[i-1];      //构建LCS
        else
        {
            if (dp[i-1][j] > dp[i][j-1])        // 向左或上回溯找LCS
                return buildLCS(dp, str1, str2, i-1, j);
            else
                return buildLCS(dp, str1, str2, i, j-1);
        }
    }

public:
    string findLCS(const string &str1, const string &str2) 
    {
        int m = str1.length();
        int n = str2.length();
        
        // 创建 DP 表
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        // 填充 DP 表
        for (int i = 1; i <= m; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // 重构最长公共子序列
        return buildLCS(dp, str1, str2, m, n);
    }
};

int main() 
{
    string str1, str2;
    cout << "first string: ";
    cin >> str1;
    cout << "second string: ";
    cin >> str2;

    LCSSolver solver;
    string lcs = solver.findLCS(str1, str2);

    cout << "LCS: " << lcs << endl;
    cout << "Its length: " << lcs.length() << endl;

    return 0;
}