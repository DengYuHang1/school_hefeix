#include<iostream>
#include<vector>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include"file.h"

using namespace std;

void write(vector<Courier>& couriers)
{
    fstream afile;

    afile.open("Courier.txt", ios::out);//将courier数据写入文件中
    if (!afile.is_open())
    {
        cout << "Courier文件打开失败!" << endl;
    }
    else
    {
        for (int i = 0; i < couriers.size(); i++)
        {
            afile << couriers[i].name << " " << couriers[i].age << " " << couriers[i].number;
            afile << "  " << couriers[i].gender << "  " << couriers[i].phone << endl;
        }
    }
    afile.close();

    afile.open("Package.txt", ios::out);
    if (!afile.is_open())
    {
        cout << "Package文件打开失败!" << endl;
    }
    else
    {
        for (int i = 0; i < couriers.size(); i++)
        {
            afile << couriers[i].name << " " << couriers[i].packages.size() << endl;
            for (int j = 0; j < couriers[i].packages.size(); j++)
            {
                afile << setfill('0') << setw(2) << couriers[i].packages[j].deadline / 60 << ':';
                afile << setfill('0') << setw(2) << couriers[i].packages[j].deadline % 60 << " " << std::left << setw(3) << couriers[i].packages[j].profit;
                afile << "  " << couriers[i].packages[j].serve << endl;
            }
        }
    }
    afile.close();
}

void read(vector<Courier>& couriers, vector<Package>& packages,Manage& boss)
{
    fstream afile;  //先检查package和Courier对应的文件
    afile.open("Courier.txt", ios::in);
    if (!afile.is_open())
    {
        cout << "Courier文件打开失败!" << endl;
    }
    else
    {
        while (!afile.eof())
        {
            string name, number, phone, line;
            int age, gender;
            getline(afile, line);
            istringstream iss(line);
            if (iss >> name >> age >> number >> gender >> phone)
            {
                Courier me(name, age, number);
                me.gender = gender;
                me.phone = phone;
                couriers.push_back(me);
            }
            else
            {
                if(name!="")cout << name << "Courier解析失败" << endl;
            }
        }
    }
    afile.close();

    afile.open("Package.txt", ios::in);
    if (!afile.is_open())
    {
        cout << "Package文件打开失败!" << endl;
    }
    else
    {
        while (!afile.eof())
        {
            string name;
            int sum, ret;
            afile >> name >> sum;
            //cout << name << sum<<endl;
            afile.get();
            ret = boss.isExist(couriers, name);
            for (int i = 0; i < sum && ret != -1; i++)
            {
                Package my_package;
                string line;
                getline(afile, line);// 每次读取一行
                int hour, minute, profit;
                int served;
                if (sscanf_s(line.c_str(), "%d:%d%d%d", &hour, &minute, &profit, &served) == 4) {
                    my_package.deadline = hour * 60 + minute;
                    my_package.profit = profit;
                    my_package.serve = served;
                    couriers[ret].packages.push_back(my_package);
                }
                else {
                    cout << "Package解析失败: " << line << i << "\n";
                    //可以回到行开头？
                    break;
                }
                //afile.get();
            }
        }
    }
    afile.close();
}