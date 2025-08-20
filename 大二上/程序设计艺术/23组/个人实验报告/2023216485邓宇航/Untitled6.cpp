#include<iostream>
#include<cstring> 
using namespace std;
int c;          //c种颜色
double dp[10000][10000];      //用于保存之前算出来的结果，避免重复计算
double dp_vis[10000][10000];  //因为dp矩阵存储的是概率，可能为0,0的话不好当做判断语句。所以多用一个二维矩阵来作为判断条件
 
double probability(int n, int m) {
	if (dp_vis[n][m] != 0 || n == 1 || n == 2)
		return dp[n][m];
	else {
		double a = probability(n - 1, m - 1) * (c - m + 1) / c;
		double b = probability(n - 1, m + 1) * (m + 1) / c;
		dp[n][m] = a + b;
		dp_vis[n][m] = 1;
		return dp[n][m];
	}
}
 
int main() {
	int m,n;
	cout<<"c=";
	cin>>c;
	cout<<"n=";
	cin>>n;
	cout<<"m=";
	cin>>m;
	memset(dp, 0, sizeof(dp));
	memset(dp_vis, 0, sizeof(dp_vis));
 
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[2][2] = 0.5;
	dp[2][0] = 0.5;
 
	dp_vis[1][0] = dp_vis[1][1] = dp_vis[2][2] = dp_vis[2][0] = 1;
 
	double ans = probability(n, m);
	cout << ans;
 
	return 0;
}
