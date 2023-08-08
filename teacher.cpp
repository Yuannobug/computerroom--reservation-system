#include"techaer.h"
#include"tool.h"

void teachermenu()
{
	cout << "————————————————" << endl;
	cout << "———      操作界面      ———" << endl;
	cout << "———    1. 查看预约     ———" << endl;
	cout << "———    2. 处理预约     ———" << endl;
	cout << "———      0. 退出       ———" << endl;
	cout << "————————————————" << endl;
}

bool teach_codeverify(vector<teacher>& teacherv, teacher& teach)
{
	string name; string code; bool choice = true;
	vector<teacher>::iterator it =teacherv.begin();
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
		for (it = teacherv.begin(); it != teacherv.end(); it++)
		{
			if (it->tea_name == name)
			{
				if (it->tea_code == code)
				{
					cout << "密码验证成功！" << endl;
					teach.tea_code = it->tea_code;
					teach.tea_uid = it->tea_uid;
					teach.tea_name = it->tea_name;
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

void addressapply(vector<student>& studentv)
{
	string uid; int choice;
	vector<student>::iterator it = studentv.begin();
	cout << "请输入您想要处理的学生编号：" << endl;
	cin >> uid;
	for (it = studentv.begin(); it != studentv.end(); it++)
	{
		if (it->stu_uid == uid)
		{
			cout << "学号:" << it->stu_uid << " 姓名:" << it->stu_name << " 日期:" << it->stu_day << " 时间:" << it->stu_time << " 机房：" << it->stu_room << " 状态:" << it->status << endl;
			cout << "请选择您对其信息的处理" << endl;
			cout << "1.通过  0.不通过" << endl;
			cin >> choice;
			if (choice == 0)
			{
				it->status = "未通过";
			}
			else
			{
				it->status = "通过";
			}
		}
	}
	
}

void teachermain()
{
	int choice = 1;
	vector<student> studentv;
	vector<teacher>teacherv;
	vector<room> roomv;
	teacher teach("\n", "\n", "\n");
	Initstudent(studentv);
	Initteacher(teacherv);
	Initroom(roomv);
	bool judge = teach_codeverify(teacherv,teach);
	if (judge == 0)
	{
		return;
	}
	system("pause");
	system("cls");
	while (choice)
	{
		teachermenu();
		cin >> choice;
		switch (choice)
		{
		case 0:cout << "欢迎下次使用" << endl; break;
		case 1:lookapply(studentv); break;
		case 2:addressapply(studentv); break;
		default:cout << "输入不合理，请重新输入" << endl;
		}
		reservenum(teacherv, studentv, roomv);
		system("pause");
		system("cls");
	}
}