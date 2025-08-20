#include<iostream>
#include<cstring>
#include<stdio.h>
#define N 8
using namespace std;
int ans;
int dis[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};//方向数组
int num[N][N];//标记骑士走过的路线
bool vis[N][N];//判断是否经过 

void shownum()
{
    int i,j;
	cout<<"No."<<ans<<endl;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            cout<<num[i][j]<<'\t';
        cout<<endl;
    }
    cout<<endl;
}

void dfs(int x,int y,int t)
{
	if(ans==10)
		return;
    if(t>N*N)
    {
        ans++;
        shownum();
        return ;
    }
    int i,j,x1,y1;
    for(i=0;i<8;i++)
    {
        x1=x+dis[i][0];
        y1=y+dis[i][1];
        if(x1>=0 && x1<N && y1>=0 && y1<N && !vis[x1][y1])
        {
            vis[x1][y1]=true;
            num[x1][y1]=t;
            dfs(x1,y1,t+1);
            vis[x1][y1]=false;
        }
    }
}

int main()
{
    int x,y;//初始位置
    cout<<"请输入初始坐标："; 
    cin>>x>>y;
    ans=0;
    memset(vis,false,sizeof(vis));
    memset(num,0,sizeof(num));
    vis[x][y]=true;
    num[x][y]=1;
    dfs(x,y,2);
    return 0;
}

