#include<iostream>
#include<cstring> 
using namespace std;
double c, n, m;          
double dp[10000][10000];      //用于保存之前算出来的结果，避免重复计算
double dp_vis[10000][10000];  //可能为0,0的话不好当做判断语句,多用一个二维矩阵来作为判断条件
double gailu(int n, int m) {
	if (dp_vis[n][m] != 0 || n == 1 || n == 2)
		return dp[n][m];
	else {
		double a = gailu(n - 1, m - 1) * (c - m + 1) / c;
		double b = gailu(n - 1, m + 1) * (m + 1) / c;
		dp[n][m] = a + b;
		dp_vis[n][m] = 1;
		return dp[n][m];
	}
}
 
int main() {
	printf("c,n,m=");
	scanf("%lf%lf%lf",&c,&n,&m);
	memset(dp, 0, sizeof(dp));
	memset(dp_vis, 0, sizeof(dp_vis));
 
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[2][2] = 0.5;
	dp[2][0] = 0.5;
 
	dp_vis[1][0] = dp_vis[1][1] = dp_vis[2][2] = dp_vis[2][0] = 1;
 
	double ans = gailu(n, m);
	cout << ans;
 
	return 0;
}
