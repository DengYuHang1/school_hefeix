#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minDistance(string a, string b)
{
    int** dp = new int* [b.length() + 1];  //dp[i][j]的意思是将有j个字母的字符串也就是a转换为有i个字母的字符串需要几步也就是b
    for (int i = 0; i < b.length() + 1; i++) {
        dp[i] = new int[a.length() + 1];
    }
    for (int j = 0; j <= a.length(); j++) {
        //初始化第一行为对应的j，有j个字母就要把j个字母全部删除
        dp[0][j] = j;
    }
    for (int i = 0; i <= b.length(); i++) {
        //初始化第一列为对应的i，有i个字母就要加上i个字母变成str2
        dp[i][0] = i;
    }

    for (int i = 1; i <= b.length(); i++) {
        for (int j = 1; j <= a.length(); j++) {
            //初始化表格
            dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), (a[j - 1] == b[i - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1));
            //如果是dp[i-1][j]的话就是按照dp[i-1][j]的方法，然后加上加上多出来的b的第i个字符这一步
            //如果是dp[i][j-1]的话就是按照dp[i][j-1]的方法处理，然后把多出来的a的第j个字符给删除
            //如果是从dp[i-1][j-1]出发的话就是要看a的第j个字符和b的第i个字符是否一样，若一样，则不用动那个字符，若不一样，则要再加上一步把字符改变的步骤
        }
    }

    return dp[b.length()][a.length()];
}

int main()
{
    string a, b;
    cout << "请输入需要转化的字符串a:" << endl;
    cin >> a;
    cout << "请输入目标字符串b:" << endl;
    cin >> b;
    cout << minDistance(a, b);
    return 0;
}
