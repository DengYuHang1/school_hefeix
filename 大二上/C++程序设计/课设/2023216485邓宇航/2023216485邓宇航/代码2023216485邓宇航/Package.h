#ifndef __Package_H__
#define __Package_H__
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

//包裹
struct Package {
public:
    Package()
    {
        profit = -1;
        deadline = -1;
        serve = 0;
    }
    int deadline; // 截止时间，以分钟为单位
    int profit;   // 利润
    bool serve;
};
void show_PMenu();                            //快递员指令总菜单
void extend(vector<Package>& packages);     //增加包裹
void del_package(vector<Package>& packages);  //删除包裹
void change(vector<Package>& packages);     //更改包裹
void display_package(vector<Package>& packages); //查找包裹,输入0则显示所有
void maxProfit(vector<Package>& packages);  //最大利润
void clear(vector<Package>& packages);      //清空包裹


#endif // !1

