/*巧克力问题： 
有袋子里均匀地装着c种颜色的巧克力，每种巧克力均有无限多。每次从袋子里拿一块
放在桌子上，如果桌子上已经有一块颜色相同的巧克力，就把两块巧克力都吃掉。一共
取出了n块巧克力，问：最后桌子上有m块的概率为多大。例如c=5,n=100,m=2时，概
率为0.625。*/
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
double Probability(int a, int b, int c)
{
	vector<vector<double> > p(a+1, vector<double>(c+1, 0));//设置概率表并将表内元素全设为0
	p[0][0] = 1;//设第一步概率为1 
	for (int i = 1; i <= a; i++)
	{
		for (int j = 0; j <= c; j++)
		{
			if ((i + j) % 2 == 1)//抵消的行为数不能为奇数
			{
				continue;
			}
			if (j == 0)//原本桌上只有一个巧克力，现在吃掉了 
			{
				p[i][j] = p[i - 1][j + 1] * ((j + 1.0) / c);
			}
			else//没吃掉巧克力的概率加吃掉巧克力的概率 
			{
				if (j < c)
					p[i][j] = p[i - 1][j - 1] * ((c - (j - 1.0)) / c) + p[i - 1][j + 1] * ((j + 1.0) / c);
				else
					p[i][j] = p[i - 1][j - 1] * ((c - (j - 1.0)) / c);
			}
		}
	}

	return p[a][b];
}
int main()
{
	int c;//巧克力种类数
	int n;//一共取出的巧克力数
	int m;//最后桌子上剩下巧克力的数量
	cout << "巧克力种类数为：";
	cin >> c;
	if (c == 0)//种类数为0
	{
		cout << "输入错误！";
		return 0;
	}
	cout << "一共取出的巧克力数为：";
	cin >> n;
	cout << "最后桌子上剩下巧克力的数量为：";
	cin >> m;
	if(m>c)
	{
		cout<<"输入错误！";
		return 0;
	}
	cout << "概率为" << Probability(n, m, c);
	return 0;
}
