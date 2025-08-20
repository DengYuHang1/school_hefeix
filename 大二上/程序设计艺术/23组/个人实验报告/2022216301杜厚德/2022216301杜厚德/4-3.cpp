#include<iostream>
#include<string>
using namespace std;
const int Max=101;
int n,m;
int a[Max][Max];

int main(){
    cout<<"请依次输入矩阵的行数和列数："<<endl;
    cin>>m>>n;
    cout<<"请输入矩阵："<<endl;
    for(int i=0;i<m;++i)
        for(int j=0;j<n;++j)
            cin>>a[i][j];

    int b[m+1][n];//辅助矩阵 b[i][j]代表a矩阵第j列中下标从0累加到i的和 
    for(int i =0;i<n;++i)
        b[0][i]=0;
    for(int j=0;j<n;++j)//a矩阵第j列中从下标为0开始累加
        for(int i=0;i<m;++i)
            b[i+1][j]=b[i][j]+a[i][j];
    int answer=0;
    for(int i=1;i<m+1;++i)
        for(int j=i;j<m+1;++j){
            int pre =0;
            for(int k=0;k<n;++k){
				pre=max(pre+b[j][k]-b[i-1][k],b[j][k]-b[i-1][k]);//最大子序列的和 
                answer=max(pre,answer);
            }
    	} 
    cout<<answer<<endl;
    return 0;
}
