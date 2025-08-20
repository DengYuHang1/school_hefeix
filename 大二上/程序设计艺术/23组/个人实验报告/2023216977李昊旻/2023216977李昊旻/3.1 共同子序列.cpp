/* 求两个字符串的最长公共子序列。
X的一个子序列是相应于X下标序列{1, 2, …, m}的一个子序列，求解两个序列的所有
子序列中长度最大的，例如输入：pear, peach输出：pea。 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string longestCommonSubsequences(string& X, string& Y)
{
    int m = X.length();//X的长度
    int n = Y.length();//Y的长度
    vector<vector<int> > a(m + 1, vector<int>(n + 1, 0));//初始化表格，并全赋值为0
    string lcs;//最长公共子序列

    //填共同子序列表
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])//当X与Y中有相同元素时
            {
                a[i][j] = a[i - 1][j - 1] + 1;
            }
            else
            {
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
            }
        }
    }

    // 建立最长公共子序列（此时为倒序）
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs += X[i - 1];
            i--;
            j--;
        }
        else if (a[i - 1][j] > a[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    // 输出结果
    reverse(lcs.begin(), lcs.end());//颠倒子序列顺序，原来为倒序
    return lcs;
}

int main() {
    string A;
    cin >> A;
    string B;
    cin >> B;
    string C = longestCommonSubsequences(A, B);//C为A和B的最长共同子序列
    cout << "最长公共子序列是： " << C << endl;
    return 0;
}
