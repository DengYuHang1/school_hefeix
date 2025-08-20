#define _CRT_SECURE_NO_WARNINGS
#include "Courier.h"
#include<iostream>
//using namespace std;

//1.添加快递员函数
void Manage::addPerson(vector<Courier>& couriers) {

	Courier me("1", 0, "0");
	
	//添加具体快递员
	string name;
	cout << "请输入姓名：";
	std::cin >> name;
	me.name = name;

	cout << "请输入性别：" << endl;
	cout << "1.---男" << endl;
	cout << "2.---女" << endl;
	int sex = 0;
	while (true) {
		std::cin >> sex;
		if (sex == 1 || sex == 2) {
			me.gender = sex;
			break;
		}
		else { cout << "输入有误，请重新输入" << endl; }
	}

	cout << "请输入年龄：";
	int age = 0;
	std::cin >> age;
	me.age = age;

	cout << "请输入工号：";
	string number;
	std::cin >> number;
	me.number = number;

	cout << "请输入联系电话：";
	string phone;
	std::cin >> phone;
	me.phone = phone;


	couriers.push_back(me);
	cout << "添加成功！" << endl;
	std::system("pause");//请按任意键继续
	std::system("cls");//清屏操作


}

//2.显示快递员
void Manage::showPerson(vector<Courier>& couriers) {
	//判断通讯录中人数是否为0，如果不为0，则显示快递员信息
	if (couriers.empty()) {
		cout << "当前无快递员！";
	}
	else {
		for (int i = 0; i < couriers.size(); i++)
		{
			cout << "姓名：" << couriers[i].name << "\t";
			cout << "性别：" << (couriers[i].gender == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << couriers[i].age << "\t";
			cout << "工号：" << couriers[i].number << "\t";
			cout << "电话：" << couriers[i].phone<< endl;
		}
	}
	std::system("pause");//按任意键继续
	std::system("cls");//清屏
}

//检测快递员是否存在，如果存在，返回快递员所在数组中的具体位置
//参数1 通讯录 参数2 对比姓名
int Manage::isExist(vector<Courier>& couriers, string name) {
	for (int i = 0; i < couriers.size(); i++) {
		//找到用户输入的姓名了
		if (couriers[i].name == name) {
			return i;
		}
	}
	return -1;
}

//3、删除指定快递员
void Manage::deletePerson(vector<Courier>& couriers) {
	cout << "请输入删除快递员姓名：";
	string name;
	cin >> name;
	int ret = isExist(couriers, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
	}
	else {
		//查找到人，要进行删除操作
		couriers.erase(couriers.begin() + ret);
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

//4、查找指定快递员的信息
void Manage::findPerson(vector<Courier>& couriers) {
	cout << "请输入您要查找的快递员姓名：";
	string name;
	cin >> name;
	//判断指定的快递员是否在通讯录中
	int ret = isExist(couriers, name);
	if (ret != -1) {
		cout << "姓名：" << couriers[ret].name << "\t";
		cout << "性别：" << (couriers[ret].gender == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << couriers[ret].age << "\t";
		cout << "工号：" << couriers[ret].number << "\t";
		cout << "电话：" << couriers[ret].phone << endl;
	}
	else { cout << "查无此人！" << endl; }
	system("pause");
	system("cls");
}

//5、修改指定快递员信息
void Manage::modifyPerson(vector<Courier>& couriers) {
	cout << "请输入您要修改的快递员姓名：";
	string name;
	cin >> name;
	int ret = isExist(couriers, name);
	if (ret != -1) {
		cout << "提示：输入886可跳过修改" << endl;
		string name;
		cout << "请输入姓名：";
		cin >> name;
		if (name != "886")
		{
			couriers[ret].name = name;
		}

		cout << "请输入性别：" << endl;
		cout << "1.---男" << endl;
		cout << "2.---女" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex != 886) {
				if (sex == 1 || sex == 2) {
					couriers[ret].gender = sex;
					break;
				}
				else { cout << "输入有误，请重新输入！" << endl; }
			}
			else if (sex == 886) { break; }
		}

		cout << "请输入年龄：";
		int age = 0;
		cin >> age;
		if (age != 886) {
			couriers[ret].age = age;
		}

		cout << "请输入工号：";
		string job_number;
		cin >> job_number;
		if (job_number != "886") {
			couriers[ret].number = job_number;
		}

		cout << "请输入联系电话：";
		string phone;
		cin >> phone;
		if (phone != "886") {
			couriers[ret].phone = phone;
		}

	

	}
	else { cout << "查无此人！" << endl; }
	system("pause");
	system("cls");

}

//6、清空所有快递员
void Manage::cleanPerson(vector<Courier>& couriers) {
	//将当前记录快递员数量置为0，做逻辑清空
	while (true) {
		cout << "请确认是否清空？（输入1--是；2--否）" << endl;
		int a = 0;
		cin >> a;
		if (a == 1) {
			couriers.clear();
			cout << "已清空" << endl;
			break;
		}
		else if (a == 2) { break; }
		else { cout << "操作有误，请重新输入！" << endl; }
	}
	system("pause");
	system("cls");

}
//总菜单
void showMenu() {
	cout << "----------------------" << endl;
	cout << "-----1.添加快递员-----" << endl;
	cout << "-----2.显示快递员-----" << endl;
	cout << "-----3.删除快递员-----" << endl;
	cout << "-----4.查找快递员-----" << endl;
	cout << "-----5.修改快递员-----" << endl;
	cout << "-----6.清空快递员-----" << endl;
	cout << "-----0.返回登陆-------" << endl;
	cout << "-----e.退出程序-------" << endl;
	cout << "----------------------" << endl;
}


