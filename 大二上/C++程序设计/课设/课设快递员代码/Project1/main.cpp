#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include"file.h"
#include "login.h"
using namespace std;

int main() {
    vector<Package> packages(0);//创建包裹容器
    vector<Courier> couriers(0);//创建快递员容器
    Manage boss;//创建管理者对象

    read(couriers,packages,boss);//文件流读取数据

    setwindow();
    
    while (true)
    {
        cout << "您好！欢迎进入快递员服务系统!" << endl;
        cout << "请输入您的姓名和工号，以便进行查询(工号和姓名均输入-1表示退出)" << endl;

        //功能分类
        int flag;
        do {
            switch (flag = fun_classify(couriers))
            {
            case -1:
                cout << "欢迎下次使用" << endl;
                write(couriers);
                system("pause");
                return 0;
            case -2:
                
                break;
            case -3:
                cout << "输入错误，请重新输入！" << endl;
                break;
            }

        } while (flag == -3);

        system("cls");//清屏操作
        
        if (flag >= 0)//快递员服务：增删改查包裹
        {
            int index = flag;
            cout << couriers[index].name << "您好！请输入功能对应的序号以进入相应功能" << endl;
            
            string select = "s";//创建用户选择输入的变量
            char key;
            int flag_courier = 1;
            while (flag_courier)
            {
                show_PMenu();
                cout << ">>>>";
                cin >> select;
                //while ((key = _getch()) != '\r')
                switch (select[0]) {
                case '1'://增加包裹
                    extend(couriers[index].packages);
                    break;
                case '2'://删除包裹
                    del_package(couriers[index].packages);
                    break;
                case '3'://重置包裹
                    change(couriers[index].packages);
                    break;
                case '4'://查找包裹
                    display_package(couriers[index].packages);
                    break;
                case '5'://最大利润
                    maxProfit(couriers[index].packages);
                    break;
                case '6'://清空包裹
                    clear(couriers[index].packages);
                    break;
                case '0':flag_courier = 0;
                    cout << "返回登陆界面" << endl;
                    break;
                case 'e':
                    cout << "欢迎下次使用！祝您工作顺心，万事如意" << endl;
                    write(couriers);
                    system("pause");
                    return 0;
                default:
                    break;
                }
                system("pause");
                system("cls");//清屏操作
            }

        }
        else if (flag == -2)
        {
            cout << "管理者您好！请输入功能对应的序号以进入相应功能" << endl;
            
            char select = 0;//创建用户选择输入的变量
            int flag_Manage = 1;
            while (flag_Manage)
            {//菜单的调用
                showMenu();
                cout << ">>>>";
                cin >> select;
                //string name;
                switch (select) {
                case '1'://添加邮递员
                    boss.addPerson(couriers);
                    break;
                case '2'://显示邮递员
                    boss.showPerson(couriers);
                    break;
                case '3'://删除邮递员
                    boss.deletePerson(couriers);
                    break;
                case '4'://查找邮递员
                    boss.findPerson(couriers);
                    break;
                case '5'://修改邮递员
                    boss.modifyPerson(couriers);
                    break;
                case '6'://清空邮递员
                    boss.cleanPerson(couriers);
                    break;
                case '0':
                    flag_Manage = 0;
                    cout << "返回登陆界面" << endl;
                    system("pause");
                    system("cls");
                    break;
                case 'e':cout << "欢迎下次使用!祝您财源滚滚，日进斗金"<<endl;
                    write(couriers);
                    system("pause");
                    return 0;
                    break;
                default:break;
                }
            }
        }
    
    }
    write(couriers);
    return 0;
}

/*
10:00 100
11:30 120
10:45 150
12:00 180
0:0 -1
包裹重置成功！*/