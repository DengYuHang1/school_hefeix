#include <iostream>
#include <vector>
using namespace std;
int available(vector<int>, int);
int play(vector<int>&, int);
void myshow(vector<int>,int);
int main()
{
    vector<int> queen;//初始化棋盘行栈
    int n,s;
    cin>>n;//设置棋盘大小以及皇后数
    s = play(queen, n);
    cout <<"共有"<<s<<"种解法" << endl;//列出棋盘并计算总数
    return 0;
}
int play(vector<int>& v,int n)//下棋
{
    int sum = 0;
    for (int i = 0; i < n; i++)//每一列 
    {
        if (available(v, i) && v.size() < n-1) //前几行
        {
            v.push_back(i);
            sum += play(v,n);
            v.pop_back();
        }
        if (available(v, i) && v.size() == n-1)//最后一行
        {
            sum += 1;
            v.push_back(i);
            myshow(v,n);
            v.pop_back();
        }
    }
    return sum;
}
int available(vector<int> v, int k)//判断该位置是否能够下棋
{
    int pos = v.size();//当前行
    for (int i = 0; i < v.size(); i++)
        if (v[i] == k || (v[i] + i) == (k + pos) || (i - v[i]) == (pos - k))//判断该列、左右对角线上是否有棋
            return 0;

    return 1;
}
void myshow(vector<int> v,int n)//显示棋盘
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i] == j)
                cout << 'Q';
            else
                cout << '.';
        }
        cout << endl;
    }
    cout << endl;
}
