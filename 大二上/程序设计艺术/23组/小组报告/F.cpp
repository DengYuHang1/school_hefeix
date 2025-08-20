#include<iostream>
using namespace std;
struct GetMaxEdge
{
	int f;//一端的序号
	int b;//另一端的序号
	int eWeight;//两端节点对应的值相乘所得的权值
};
typedef struct GetMaxEdge SetEdge;
int main()
{
	//设置所有变量
	int n;
	SetEdge SE[1000000];//每条道路的信息
	int w[1000000];//每个节点的权值
	int mostw, t, s;
	t = 0;
	s = 0;
	//输入节点个数
	cin >> n;
	//输入SE[]中每条道路两端节点的序号
	for (int i = 0; i < n - 1; i++)
	{
		cin >> SE[i].f >> SE[i].b;
	}
	//输入每个节点的权值
	for (int j = 0; j < n; j++)
		cin >> w[j];
	//计算得出SE[]中每条道路的权值
	for (int k = 0; k < n - 1; k++)
	{
		SE[k].eWeight = w[SE[k].f - 1] * w[SE[k].b - 1];
	}
	for (int q = 0; q < n - 1; q++)
	{
		mostw = 0;
		for (int p = 0; p < n - 1; p++)
		{
			if (mostw < SE[p].eWeight && w[SE[p].f - 1] != 0 && w[SE[p].b - 1] != 0)
			{
				mostw = SE[p].eWeight;
				t = p;
			}
		}
		//将得到的SE[]道路权值依次相加
		s += mostw;
		//将得到过的节点的权值设计为0
		w[SE[t].f - 1] = 0;
		w[SE[t].b - 1] = 0;
	}
	cout << s;
	return 0;
}
