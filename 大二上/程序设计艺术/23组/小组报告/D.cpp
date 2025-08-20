#include <iostream>
#include <vector>

using namespace std;

// 求缩小道路范围时损失的人流量
int losing_citizens(int cut_crossing, int n, bool front, const vector<vector<int>> &traffic)
{
    int los_citi = 0;
    if (front)            // 从头缩
        for (int i = 0; i <= cut_crossing; i++)       // 所有从cut_crossing与路头间的流量被损失
            los_citi += traffic[i][cut_crossing-i];
    else              //从尾缩
        for (int j = n-1; j >= cut_crossing; j--)       // 所有从cut_crossing与路尾间的流量被损失
            los_citi += traffic[cut_crossing-1][j-cut_crossing];
        
    return los_citi;
}

int max_citizens(int n, int k) 
{
    int sum = 0;       // 经过该道路的总人数
    // 存储每对路口的通行市民数量
    vector<vector<int>> traffic(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        traffic[i].resize(n - i - 1);
        for (int j = 0; j < n - i - 1; ++j) {
            cin >> traffic[i][j];               // 输入每对路口之间的通行市民数量
            sum += traffic[i][j];               //记录总人流量
        }
    }

    int front = 0, rear = n-1;

    while(rear-front > k)            // front和rear之间正好可以放k个装置时退出循环
    {
        int los = 0;
        int f = losing_citizens(front, n, true, traffic);        //如果从剩余路口的头部去除一个路口损失的人流量
        int r = losing_citizens(rear, n, false, traffic);        //尾部
        
        // 去除损失人流量小的路口
        if (f < r)
        {
            los = f;
            front++;
        }
        else
        {
            los = r;
            rear--;
        }

        sum -= los;
    }
    
    return sum;
}

int main() 
{
    int n, k;
    // 输入路口数量 n 和装置数量 k
    cin >> n >> k;
    if (k>=n)
        exit(1);           //输入不合法
    
    cout << max_citizens(n, k) << endl;

    return 0;
}