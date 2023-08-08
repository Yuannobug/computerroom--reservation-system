#include<iostream>
using namespace std;

#include"student.h"
#include"manager.h"
#include"techaer.h"

void showmenu()
{
	cout << "————————————————" << endl;
	cout << "———      登陆界面      ———" << endl;
	cout << "———      1. 学生       ———" << endl;
	cout << "———      2. 老师       ———" << endl;
	cout << "———      3. 管理员     ———" << endl;
	cout << "———      0. 退出       ———" << endl;
	cout << "————————————————" << endl;
}

int main()
{
	int choice = 1;
	while (choice)
	{
		showmenu();
		cin >> choice;
		switch (choice)
		{
		case 1:studentmain(); break;
		case 2:teachermain(); break;
		case 3:managermain(); break;
		case 0:cout << "欢迎下次使用" << endl; break;
		default:cout << "输入不合理，请重新输入" << endl;
		}
	}

	system("pause");
	return 0;
}