#include<iostream>
#include <vector>
#include"login.h"
using namespace std;

void setwindow()
{
	system("title 快递公司管理系统");
	system("color f0");
}

int fun_classify(vector<Courier>& couriers)
{
    cout << "姓名：";
    string myname;
    cin >> myname;
    cout << "工号：";
   
    string job_number;

    if (myname == "manage")
    {
        char password[11];
        char key;
        int i = 0;
        while ((key = _getch()) != '\r')
        {
            if (key == '\b' && i > 0) 
            {
                std::cout << "\b \b"; 
                i--; 
            }
            else if (key != '\b')
            {
                password[i] = key;
                i++;
                putchar('*');
            }
        }
        password[i] = '\0';
        cout << endl;
         job_number=string(password);
    }
    else
    {
        cin >> job_number;
    }

    if (myname == "-1" && job_number == "-1")
    {
        return -1;   //返回退出程序信号
    }
    else if (myname == Manage_name && job_number == Manage_secret)
    {
        return -2;  //返回管理员权限信号
    }
    else
    {
        unsigned int i;
        for (i = 0; i < couriers.size(); i++)
        {
            if (myname == couriers[i].name && job_number == couriers[i].number)
            {
                break;
            }
        }

        if (i < couriers.size())
        {
            return i;   //返回快递员索引号
        }
        else
        {
            return -3;  //返回输入错误信号
        }

    }
}