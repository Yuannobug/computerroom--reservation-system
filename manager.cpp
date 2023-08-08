#include"manager.h"
#include"tool.h"

bool codeverify(vector<manager> managerv)
{
	string name; string code; bool choice=true;
	vector<manager>::iterator it = managerv.begin();
	while (1)
	{
		cout << "————————————————" << endl;
		cout << "———      身份验证      ———" << endl;
		cout << "———     请输入姓名     ———" << endl;
		cout << "————————————————" << endl;
		cin >> name;
		cout << "———     请输入密码     ———" << endl;
		cout << "————————————————" << endl;
		cin >> code;
		for (it = managerv.begin(); it != managerv.end(); it++)
		{
			if (it->man_name == name)
			{
				if (it->man_code == code)
				{
					cout << "密码验证成功！" << endl;
					return true;
				}
				else
				{
					cout << "密码验证失败！账号或密码错误" << endl;
				}
			}
		}
		cout << "密码验证失败！账号或密码错误" << endl;
		cout << "是否继续验证" << endl;
		cout << " 1.是   0.否" << endl;
		cin >> choice;
		if (choice == false)
		{
			return choice;
		}
	}
}

void managermenu()
{
	cout << "————————————————" << endl;
	cout << "———      操作界面      ———" << endl;
	cout << "———    1. 添加账号     ———" << endl;
	cout << "———    2. 查看账号     ———" << endl;
	cout << "———    3. 查看机房     ———" << endl;
	cout << "———    4. 清空预约     ———" << endl;
	cout << "———      0. 退出       ———" << endl;
	cout << "————————————————" << endl;
}

void addteacher(vector<teacher>& teacherv)
{
	string uid; string name; string code;
	cout << "请输入教师姓名" << endl;
	cin >> name;
	cout << "请输入教师编号" << endl;
	cin >> uid;
	cout << "请输入教师密码" << endl;
	cin >> code;
	teacher temp(uid,name, code);
	teacherv.push_back(temp);
}

void addstudent(vector<student>& studentv)
{
	vector<student>::iterator it = studentv.begin();
	string uid ; string name; string code ;
	cout << "请输入学生姓名" << endl;
	cin >> name;
	cout << "请输入学生编号" << endl;
	cin >> uid;
	for (; it != studentv.end(); it++)
	{
		if (it->stu_uid == uid)
		{
			cout << "用户编号重复，请重新输入" << endl;
			return;
		}
	}
	cout << "请输入学生密码" << endl;
	cin >> code;
	student temp(uid, name, code,"无", "无", "无", "未预约");
	studentv.push_back(temp);
}

void add(vector<teacher>& teacherv, vector<student>& studentv)
{
	int choice = 1;
	while (choice)
	{
		cout << "————————————————" << endl;
		cout << "———      操作界面      ———" << endl;
		cout << "———    1. 添加教师     ———" << endl;
		cout << "———    2. 添加学生     ———" << endl;
		cout << "———      0. 退出       ———" << endl;
		cout << "————————————————" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:addteacher(teacherv); break;
		case 2:addstudent(studentv); break;
		case 0:cout << "欢迎下次使用" << endl; break;
		default:cout << "输入不合理，请重新输入" << endl;
		}
	}


}

void showpeople(vector<teacher> teacherv, vector<student> studentv)
{
	vector<teacher>::iterator it1 = teacherv.begin();
	vector<student>::iterator it2 = studentv.begin();
	if (teacherv.size() == 0 )
	{
		cout << "教师信息为空" << endl;
	}
	else
	{
		cout << "——————————————" << endl;
		cout << "———  教师信息      ———" << endl;
		cout << "——————————————" << endl;
		for (it1 = teacherv.begin(); it1 != teacherv.end(); it1++)
		{
			cout << "教师编号:" << it1->tea_uid << "  教师姓名:" << it1->tea_name << endl;
		}
	}
	if (studentv.size() == 0)
	{
		cout << "学生信息为空" << endl;
	}
	else
	{
		cout << "——————————————" << endl;
		cout << "———  学生信息      ———" << endl;
		cout << "——————————————" << endl;
		for (it2 = studentv.begin(); it2 != studentv.end(); it2++)
		{
			cout << "学生编号:" << it2->stu_uid << "  学生姓名:" << it2->stu_name << "  状态:" << it2->status << endl;
		}
	}
}

void showroom(vector<room> roomv)
{
	vector<room>::iterator it = roomv.begin();
	for (it = roomv.begin(); it != roomv.end(); it++)
	{
		cout << "机房编号" << it->room_num << "   " << "机房容量" << it->room_capacity << endl;
	}
}



void clean(vector<student>& studentv,vector<room>& roomv)
{
	vector<student>::iterator it1 = studentv.begin();//学生
	for (it1 = studentv.begin(); it1 != studentv.end(); it1++)
	{
		it1->stu_room = "无";
		it1->stu_time = "无";
		it1->stu_day = "无";
		it1->status = "未预约";
	}
	vector<room>::iterator it2 = roomv.begin();
	for (it2 = roomv.begin(); it2 != roomv.end(); it2++)
	{
		it2->room_size = "0";
	}	
}

void managermain()
{
	int choice = 1; int judge = 1;
	vector<manager> managerv;
	vector<teacher> teacherv;
	vector<student> studentv;
	vector<room> roomv;
	Initmanager(managerv);
	Initteacher(teacherv);
	Initstudent(studentv);
	Initroom(roomv);
	judge=codeverify(managerv);
	if (judge == 0)
	{
		return;
	}
	system("pause");
	system("cls");
	while (choice)
	{
		managermenu();
		cin >> choice;
		switch (choice)
		{
		case 1:add(teacherv,studentv); break;
		case 2:showpeople(teacherv, studentv); break;
		case 3:showroom(roomv); break;
		case 4:clean(studentv,roomv); break;
		case 0:cout << "欢迎下次使用" << endl; break;
		default:cout << "输入不合理，请重新输入" << endl;
		}
		system("pause");
		system("cls");
	}
	reservenum(teacherv, studentv,roomv);
}