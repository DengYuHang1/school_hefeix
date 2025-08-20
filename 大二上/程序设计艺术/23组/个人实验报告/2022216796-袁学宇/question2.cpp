#include <iostream>
#include <vector>
using namespace std;

bool isvisited[200][200];
int v1, v2, L;
bool haveAns = false;
vector <int> path;
vector <int> ans;
string Method[8] = {
    "将B桶水排尽",
    "将A桶水排尽",
    "将B桶水装满",
    "将A桶水装满",
    "将B桶水全部装入A桶中",
    "将B桶水装入A桶中直至A桶满",
    "将A桶水全部装入B桶中",
    "将A桶水装入B桶中直至B桶满"
};
void dfsFindWay(int x, int y)//x为A桶水现在的升数，y为B桶水现在的升数
{
    if (!haveAns)
    {
        if (x == L || y == L)
        {
            if (x == L)
            {
                cout << "此时A桶水为:" << L << "升" << endl;
            }
            else
            {
                cout << "此时B桶水为:" << L << "升" << endl;
            }
            ans = path;
            haveAns = true;
            return;
        }
        if (isvisited[x][y])
        {
            return;
        }
        isvisited[x][y] = true;
        if (y != 0)
        {
            path.push_back(0);//将B桶水排尽
            dfsFindWay(x, 0);
            path.pop_back();
        }
        if (x != 0)
        {
            path.push_back(1);//将A桶水排尽
            dfsFindWay(0, y);
            path.pop_back();
        }
        if (y != v2)
        {
            path.push_back(2);//将B桶水装满
            dfsFindWay(x, v2);
            path.pop_back();
        }
        if (x != v1)
        {
            path.push_back(3);//将A桶水装满
            dfsFindWay(v1, y);
            path.pop_back();
        }
        if (x + y <= v1)
        {
            path.push_back(4);//B桶水全部装入A桶中
            dfsFindWay(x + y, 0);
            path.pop_back();
        }
        else
        {
            path.push_back(5);//将B桶水装入A桶中直至A桶满
            dfsFindWay(v1, x + y - v1);
            path.pop_back();
        }
        if (x + y <= v2)
        {
            path.push_back(6);//将A桶水全部装入B桶中
            dfsFindWay(0, x + y);
            path.pop_back();
        }
        else
        {
            path.push_back(7);//将A桶水装入B桶中直至B桶满
            dfsFindWay(x + y - v2, v2);
            path.pop_back();
        }
    }

}
int main()
{
    int i, s = 0;
    cout << "请输入第一个容器的容积v1:" << endl;
    cin >> v1;
    cout << "请输入第二个容器的容积v1:" << endl;
    cin >> v2;
    cout << "请输入装出的水升L:" << endl;
    cin >> L;
    dfsFindWay(0, 0);
    if (ans.size() == 0)
    {
        cout << "No Solution!";
    }
    else
    {
        for (vector <int>::iterator it = ans.begin(); it != ans.end(); it++)
        {
            cout << "第" << ++s << "步:     " << Method[*it] << endl;
        }
    }
    return 0;
}
