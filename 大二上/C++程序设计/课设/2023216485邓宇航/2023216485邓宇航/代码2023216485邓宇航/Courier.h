#ifndef __Courier_H__
#define __Courier_H__
#include <string>
#include "Package.h"
using namespace std;

class Manage;

//快递员
struct Courier {
    friend struct Manage;
    //friend int main();
    friend void write(vector<Courier>& couriers);
    friend void read(vector<Courier>& couriers, vector<Package>& packages, Manage& boss);
public:
    Courier() = default;
    Courier(string name, int age, string number)
    {
        this->name = name;
        this->age = age;
        this->number = number;
        this->gender = 0;
        this->phone = "无";
    }

    string name;  //姓名
    int age;       //年龄
    string number;     //工号
    int gender;  //性别
    vector<Package> packages;//包裹

private:
    string phone;   //电话号码
};

//管理者
struct Manage
{
public:
    void addPerson(vector<Courier>& couriers);
    void showPerson(vector<Courier>& couriers);
    int isExist(vector<Courier>& couriers, string name);
    void deletePerson(vector<Courier>& couriers);
    void findPerson(vector<Courier>& couriers);
    void modifyPerson(vector<Courier>& couriers);
    void cleanPerson(vector<Courier>& couriers);

};

const string Manage_name = "manage";
const string Manage_secret = "88888888";

void showMenu();

#endif