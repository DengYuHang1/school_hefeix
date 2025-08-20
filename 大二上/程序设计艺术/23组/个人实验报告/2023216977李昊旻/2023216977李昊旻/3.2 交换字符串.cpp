#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string a,b;
    int s;//变换次数
    s = 0;
    cin >> a;
    cin >> b;
    //将b中元素全部填入a中
    for (int i = 0; i < b.size(); i++)
    {
        if (i<=a.size())
        {
            a[i] = b[i];
        }
        else
        {
            a.push_back(b[i]);
        }
        s++;//次数+1
        cout << a<<endl;//输出步骤
    }
    //若a有多余部分，则删除
    if (a.size() > b.size())
    {
        for (int j = b.size(); j < a.size(); j++)
        {
            a.pop_back();
            s++;//次数+1
            cout << a<<endl;//输出步骤
        }
    }
    cout << "输出最少" << s << "次能够将a变换成b";
    return 0;
}
