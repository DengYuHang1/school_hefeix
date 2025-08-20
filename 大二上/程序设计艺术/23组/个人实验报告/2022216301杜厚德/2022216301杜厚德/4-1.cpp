#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXN 1010
char s1[MAXN],s2[MAXN];//存储1和2字符串
int dp[MAXN][MAXN];//状态数组

//公共子序列
void LCS(int i,int j){
    if(i == 0 || j == 0){
        return;
    }
    if(s1[i-1] == s2[j-1]){
        LCS(i-1,j-1);//斜右上方递归
        cout<<s1[i-1];
    }
    else if(dp[i][j-1] > dp[i-1][j]){//左边大
        LCS(i,j-1);
    }
    else{
        LCS(i-1,j);
    }
}

int main() {
    //读入字符串
    cin>>s1;
    cin>>s2;
    //获取两个字符串长度
    int len1,len2;
    len1=strlen(s1);
    len2=strlen(s2);
    //状态转移方程
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(s1[i-1]==s2[j-1]){//等于斜上方的值+1
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{//等于上方或者左方的最大值
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<"最大长度:"<<dp[len1][len2]<<endl;
    cout<<"最长公共子序列为:";
    LCS(len1,len2);
}
//时间复杂度O（mn）+O（m+n）
