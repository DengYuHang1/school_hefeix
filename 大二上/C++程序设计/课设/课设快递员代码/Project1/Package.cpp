#define _CRT_SECURE_NO_WARNINGS
#include "Package.h"
#include <algorithm>
#include <iostream>
#include <Windows.h>

//using namespace std;


//总菜单
void show_PMenu() {
    cout << "--------------------" << endl;
    cout << "-----1.增加包裹-----" << endl;
    cout << "-----2.删除包裹-----" << endl;
    cout << "-----3.更改包裹-----" << endl;
    cout << "-----4.查找包裹-----" << endl;
    cout << "-----5.最大利润-----" << endl;
    cout << "-----6.清空包裹-----" << endl;
    cout << "-----0.返回登陆-----" << endl;
    cout << "-----e.退出程序-----" << endl;
    cout << "--------------------" << endl;
}


// 比较函数，用于按利润从高到低排序
bool compareProfit(const Package& a, const Package& b) {
    return a.profit > b.profit;
}


//返回最大利润
void maxProfit (vector<Package>& packages) {

    if (packages.empty())
    {
        cout << "您没有任何包裹！无法计算！" << endl;
        return;
    }

    cout << "正在计算中…………" << endl;

    // 按利润从高到低排
    std::sort(packages.begin(), packages.end(), compareProfit);

    // 找到最大的截止时间
    int maxDeadline = 0;
    for (const auto& pkg : packages) {
        if (pkg.deadline > maxDeadline) {
            maxDeadline = pkg.deadline;
        }
    }

    // 创建一个数组来记录每个时间段是否已经被占用
    std::vector<bool> timeSlots(maxDeadline + 1, false);

    int totalProfit = 0;    //利润

    // 遍历排序后的包裹列表
    for (const auto& pkg : packages) {
        // 找到一个可以安排该包裹的时间段
        for (int t = pkg.deadline; t > 0; --t) {
            if (!timeSlots[t]) {
                timeSlots[t] = true;
                totalProfit += pkg.profit;
                break;
            }
        }
    }

    for (int i = 0; i <= 20; i++)
    {
        cout << "■" << endl;
        cout << "\033[K";          //利用ANSI转义序列清除所在行
        cout << i * 5 << '%';
        cout << "\033[1A\r\033["<<i+1<<"C";//先回到上一行末尾
        Sleep(100);//延时100ms
    }
    cout << "\033[K\033[1A\r\033[K";//清除前两行
    cout << "计算成功！" << endl;
    //cout << endl;
    cout << "经过您一天努力后，能获得最大利润为" << totalProfit << "元"<<endl;
}

//改变包裹
void change(vector<Package>& packages)
{
    //packages.clear();   //清空包裹
    if (packages.empty())
    {
        cout << "您没有任何包裹，无法更改！" << endl;
        return;
    }

    int index;
    char flag;
    flag = 'N';
    do {
        cout << "请输入您要更改第几个包裹：";
        cin >> index;
        if (index > packages.size())
        {
            cout << "无法更改，包裹索引号过大！" << endl;
        }
        else if (index <1)
        {
            cout << "更改错误，索引号小于一" << endl;
        }
        else
        {

            cout << "包裹" << index << ':' << "截止时间" << setfill('0') << setw(2) << packages[index - 1].deadline / 60 << ':';
            cout << setfill('0') << setw(2) << packages[index - 1].deadline % 60 << "，利润" << packages[index - 1].profit<<' ';
            if (packages[index - 1].serve)
            {
                cout << "状态:" << "已送出";
            }
            else
            {
                cout << "状态:" << "未送出";
            }

            cout << endl;

            cout << "请问您是否要更改此包裹？[y|n](输入其他字母可退出此功能)";
            cin >> flag;

        }

    } while (flag=='N'||flag=='n');
    
    if (flag == 'Y' || flag == 'y')
    {
        Package my_package;
        int hour, minute;
        char a;
        cout << "请输入要更新的包裹数据，提示：输入886可跳过修改" << endl;
        
        string line;
        cout << "请输入时间：";
        cin >> line;
        if (line != "886")
        {
            sscanf(line.c_str(), "%d:%d", &hour, &minute);
            packages[index - 1].deadline = hour * 60 + minute;
        }

        cout << "请输入利润：";
        cin >> line;
        if (line != "886")
        {
            packages[index - 1].profit = stoi(line, 0, 10);
        }

        cout << "是否送达？[y|n]";
        cin >> line;
        if (line != "886")
        {
            packages[index - 1].serve = (line=="y")?1:0;
        }

        cout << "包裹重置成功！" << endl;
    }
    
}

//增加包裹
void extend(vector<Package>& packages)
{
    Package my_package;
    int hour, minute,serve,profit;
    cout << "请输入增加的包裹列表，每个包裹包括截止时间和利润及是否送出（1表示送出，0表示未送出）" << endl;
    cout << "如\"12:00 100 1\"表示截止时间为12点的包裹，利润为100并且已送出" << endl;
    cout << "当输入的利润为负数时，表示输入停止" << endl;
    while (scanf("%d:%d%d%d", &hour, &minute, &profit, &serve) != 4)
    {
        cout << "输入格式有误，请重新输入！" << endl;
    }

    while (profit >= 0)
    {
        my_package.profit = profit;
        my_package.deadline = hour * 60 + minute;
        my_package.serve = (bool)serve;
        packages.push_back(my_package);
        while (scanf("%d:%d%d%d", &hour, &minute, &profit, &serve) != 4)
        {
            cout << "输入格式有误，请重新输入！" << endl;
        }
    }
    
    cout << "包裹增加成功！" << endl;
}

//删除指定包裹,index为第几个包裹
void del_package(vector<Package>& packages)
{
    if (packages.empty())
    {
        cout << "您没有任何包裹！" << endl;
        return;
    }

    int index;
    char flag;
    flag = 'N';
    do {
        cout << "请输入您要删除第几个包裹：";
        cin >> index;
        if (index > packages.size())
        {
            cout << "无法删除，包裹索引号过大！" << endl;
        }
        else if (index <= 0)
        {
            cout << "删除错误，索引号小于一" << endl;
        }
        else
        {

            cout << "包裹" << index << ':' << "截止时间" << setfill('0') << setw(2) << packages[index - 1].deadline / 60 << ':';
            cout << setfill('0') << setw(2) << packages[index - 1].deadline % 60 << "，利润" << packages[index - 1].profit << ' ';
            if (packages[index - 1].serve)
            {
                cout << "状态:" << "已送出";
            }
            else
            {
                cout << "状态:" << "未送出";
            }

            cout << endl;

            cout << "请问您是否要删除此包裹？[y|n](输入其他字母可退出此功能)";
            cin >> flag;
        }

    } while (flag == 'N' || flag == 'n');

    if (flag == 'y' || flag == 'Y')
    {
        packages.erase(packages.begin()+index-1);
         cout << "删除成功！" << endl;
    }
        
    
}

//查找包裹
void display_package(vector<Package>& packages)
{
    if (packages.empty())
    {
        cout << "您没有任何包裹！" << endl;
        return;
    }

    int index;
    cout << "请输入您要查找第几个包裹，输入0则显示所有包裹" << endl;
    cin >> index;

    if (index > packages.size())
    {
        cout << "无法查找，包裹索引号过大！" << endl;
    }
    else if (index <0)
    {
        cout << "查找错误，索引号小于零" << endl;
    }
    else if (index == 0)
    {

        for (int i = 0; i < packages.size(); i++)
        {
            cout << "包裹" << i + 1 << ':' << "截止时间" << setfill('0') << setw(2) << packages[i].deadline / 60 << ':';
            cout << setfill('0') << setw(2) << packages[i].deadline % 60 << "，利润" << std::left << setw(3)<<packages[i].profit<<" ";
            if (packages[i].serve)
            {
                cout<<"状态:"<<"已送出";
            }
            else
            {
                cout << "状态:" << "未送出";
            }

            cout << endl;

        }

    }
    else
    {
       
        cout << "包裹" << index << ':' << "截止时间" << setfill('0') << setw(2) << packages[index - 1].deadline / 60 << ':';
        cout<< setfill('0') << setw(2) << packages[index - 1].deadline % 60 << "，利润  " << packages[index - 1].profit ;
        if (packages[index-1].serve)
        {
            cout << "状态:" << "已送出";
        }
        else
        {
            cout << "状态:" << "未送出";
        }

        cout << endl;
    }


}

void clear(vector<Package>& packages)
{
    char flag;
    cout << "请问您是否要删除所有包裹？[y|n]";
    cin >> flag;
    if (flag == 'y' || flag == 'Y')
    {
        packages.clear();
        cout << "清空包裹成功！" << endl;
    }
    
}
