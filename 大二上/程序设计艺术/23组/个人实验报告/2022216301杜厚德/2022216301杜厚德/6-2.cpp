#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 乘法函数，将大数 a 乘以整数 b
vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++) {
        t = t + a[i] * b;
        c.push_back(t % 10); // 取个位数
        t = t / 10; // 进位
    }
    while (t) {
        c.push_back(t % 10);
        t = t / 10;
    }
    return c;
}

// 除法函数，将大数 A 除以整数 b，返回商和余数
vector<int> div(vector<int>& A, int b, int& r)
{
    vector<int> c;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
        r = r * 10 + A[i];
        c.push_back(r / b); // 取商
        r = r % b; // 取余数
    }
    // 倒转结果
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0) {
        c.pop_back();
    }
    return c;
}

int main()
{
    int n, m;
    cout << "请输入五块钱和十块钱的个数：";
    cin >> n >> m;
    // 当五块钱比十块钱少的时候，不存在合法情况
    if (n < m)
    {
        cout << "不存在合法情况！\n";
        return 0;
    }
    int r;
    vector<int> res; // 储存结果的容器
    res.push_back(1);
    // 卡特兰数 (C(n+m,n) - C(n+m,n-1)) * n! * m!
    for (int i = 2; i <= n + m; i++)
    {
        res = mul(res, i);
    }
    res = mul(res, n + 1 - m);
    res = div(res, n + 1, r);
    cout << "可能的买票序列的个数：";
    for (int i = res.size() - 1; i >= 0; i--) {
        printf("%d", res[i]);
    }
    return 0;
}
