#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,a[10],x,b,c;
	cin >> n;//表示输入的数据组数
	for (int i = 0; i < n; i++)
	{
		cin >> x; //输入所询问的项数
		//得到相应的a[i]
		if (x == 1)
			a[i] = 3;
		else
		{
			b = (x - 1) / 3;
			c = (x - 1) % 3;
			if (c == 2)
				a[i] = (b + 1) * 4 + 3;
			else
				a[i] = (b + 1) * 4 + c;
		}
	}
	//依次输出a[j]的数值
	for (int j = 0; j < n; j++)
		cout << a[j] << endl;
	return 0;
}