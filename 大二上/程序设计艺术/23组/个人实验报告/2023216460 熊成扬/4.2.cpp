#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

// 回溯打印操作步骤
void printOperations(const vector<vector<int>> &dp, const string &a, const string &b) 
{
    int i = a.length();
    int j = b.length();
    stack<string> s;

    while (i > 0 && j > 0) 
    {
        if (a[i - 1] == b[j - 1]) 
        {
            i--;
            j--;
        } 
        else if (dp[i][j] == dp[i - 1][j - 1] + 1) 
        {
            s.push("Replace " + string(1, a[i - 1]) + " in string a with " + string(1, b[j - 1]));
            //cout << "Replace " << a[i - 1] << " in string a with " << b[j - 1] << endl;
            i--;
            j--;
        } 
        else if (dp[i][j] == dp[i - 1][j] + 1) 
        {
            s.push("Delete " + string(1, a[i -  1]) + " from string a");
            //cout << "Delete " << a[i - 1] << " from string a" << endl;
            i--;
        } 
        else 
        {
            s.push("Insert " + string(1,b[j - 1]) + " into string a");
            //cout << "Insert " << b[j - 1] << " into string a" << endl;
            j--;
        }
    }

    while (i > 0) 
    {
        s.push("Delete " + string(1, a[i-1]) + " from string a");
        //cout << "Delete " << a[i - 1] << " from string a" << endl;
        i--;
    }
    while (j > 0) 
    {
        s.push("Insert " + string(1, b[j-1]) + " into string a");
        //cout << "Insert " << b[j - 1] << " into string a" << endl;
        j--;
    }
    while (!s.empty())
    {
        string t = s.top();
        cout << t <<endl;
        s.pop();
    }
    
}

int minDistance(const string &a, const string &b) 
{
    int n = a.size();
    int m = b.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    
    // 将一个字符串转化为空字符串所需操作次数
    for (int i = 0; i <= n; i++) 
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) 
    {
        dp[0][j] = j;
    }
    
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            if (a[i - 1] == b[j - 1])           //字符相同不操作
            {
                dp[i][j] = dp[i - 1][j - 1];
            } 
            else                                //否则进行最小代价操作
            {
                dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
            }
        }
    }
    
    cout << "Mini operations: " << dp[n][m] << endl;
    
    printOperations(dp, a, b);
    
    return dp[n][m];
}

int main() 
{
    string a, b;
    cout << "string a: ";
    cin >> a;
    cout << "string b: ";
    cin >> b;
    
    minDistance(a, b);
    
    return 0;
}
