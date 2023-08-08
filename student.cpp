#include"student.h"
#include"manager.h"
#include"tool.h"

void studentmenu()
{
	cout << "————————————————" << endl;
	cout << "———      操作界面      ———" << endl;
	cout << "———    1. 申请预约     ———" << endl;
	cout << "———    2. 查看预约     ———" << endl;
	cout << "———    3. 预约总和     ———" << endl;
	cout << "———    4. 取消预约     ———" << endl;
	cout << "———      0. 退出       ———" << endl;
	cout << "————————————————" << endl;
}


bool stu_codeverify(vector<student>& studentv,student& stu)
{
	string name; string code; bool choice = true;
	vector<student>::iterator it = studentv.begin();
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
		for (it = studentv.begin(); it !=studentv.end(); it++)
		{
			if (it->stu_name == name)
			{
				if (it->stu_code == code)
				{
					cout << "密码验证成功！" << endl;
					stu.stu_code = it->stu_code;
					stu.stu_name = it->stu_name;
					stu.stu_uid = it->stu_uid;
					stu.status = it->status;
					stu.stu_room = it->stu_room;
					stu.stu_day = it->stu_day;
					stu.stu_time = it->stu_time;
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

int mypow(int x, int y)
{
	int i = 0; int sum = 1;
	for (i = 0; i < y; i++)
	{
		sum = sum * x;
	}
	return sum;
}

void addroomnum(string& sz)
{
	int i = 0; 
	int j = 0;
	int lenght = sz.size();
	int temp = 0;
	for (i = lenght-1; i >=0; i--)
	{
		temp += (sz[i] - '0') * mypow(10, i);
	}
	temp++;
	for (i = lenght - 1; i >= 0; i--)
	{
		sz[i] = temp/ mypow(10, j)%10 + '0';
		j++;
	}
}

void changev(student& stu, vector<student>& studentv)
{
	vector<student>::iterator it = studentv.begin();
	for (it = studentv.begin(); it != studentv.end(); it++)
	{
		if (it->stu_name == stu.stu_name)
		{
			it->status = stu.status;
			it->stu_day = stu.stu_day;
			it->stu_time = stu.stu_time;
			it->stu_room = stu.stu_room;
		}
	}
}


void subroomnum(string& sz)
{
	int i = 0;
	int j = 0;
	int lenght = sz.size();
	int temp = 0;
	for (i = lenght - 1; i >= 0; i--)
	{
		temp += (sz[i] - '0') * mypow(10, i);
	}
	temp--;
	for (i = lenght - 1; i >= 0; i--)
	{
		sz[i] = temp / mypow(10, j) % 10 + '0';
		j++;
	}
}


void apply(student& stu,vector<student>& studentv,vector<room>& roomv)
{
	int choice = 0;
	cout << "请选择预约的日期" << endl;
	cout << "1.周一 2.周二 3.周三 4.周四 5.周五" << endl;
	cout << "注：休息日不开放机房" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:stu.stu_day = "周一"; break;
	case 2:stu.stu_day = "周二"; break;
	case 3:stu.stu_day = "周三"; break;
	case 4:stu.stu_day = "周四"; break;
	case 5:stu.stu_day = "周五"; break;
	}
	cout << "请选择预约的时间段 " << endl;
	cout << "1.上午 2.下午" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:stu.stu_time = "上午"; break;
	case 2:stu.stu_time = "下午"; break;
	}
	cout << "请选择机房" << endl;
	cout << "1.机房1   2.机房2" << endl;//随初始化改变应改变
	cin >> choice;
	if (roomv[0].room_size == roomv[0].room_capacity)
	{
		cout << "机房1已满" << endl;
		choice = 2;
	}
	if (roomv[1].room_size == roomv[1].room_capacity)
	{
		cout << "机房1已满" << endl;
		choice = 1;
	}
	switch (choice)
	{
	case 1:stu.stu_room = "机房1";  addroomnum(roomv[0].room_size);  break;
	case 2:stu.stu_room = "机房2";  addroomnum(roomv[1].room_size); break;
	}
	stu.status = "待审核";
	changev(stu, studentv);
}

void showapply(student stu)
{
	cout << "学号:"<<stu.stu_uid << " 姓名:"<<stu.stu_name << " 日期:"<<stu.stu_day << " 时间:"<<stu.stu_time<<" 机房："<<stu.stu_room << " 状态:" << stu.status << endl;
}


void disapply(student& stu, vector<student>& studentv, vector<room>& roomv)
{
	int judge = 0;
	cout << "请确认是否取消预约" << endl;
	cout << "1. 是   0. 否" << endl;
	cin >> judge;
	if (judge == 0)
	{
		return;
	}
	else
	{
		if (stu.stu_room == "机房1")
		{
			subroomnum(roomv[0].room_size);
		}
		else
		{
			subroomnum(roomv[1].room_size);
		}
		stu.status = "未预约";
		stu.stu_day = "无";
		stu.stu_room = "无";
		stu.stu_time = "无";
		changev(stu, studentv);
	}
}

void studentmain()
{
	int choice = 1;
	vector<student> studentv;
	vector<teacher>teacherv;
	vector<room> roomv;
	student stu("\n", "\n", "\n", "\n", "\n", "\n", "\n");
	Initstudent(studentv);
	Initteacher(teacherv);
	Initroom(roomv);
	bool judge=stu_codeverify(studentv,stu);
	if (judge == 0)
	{
		return;
	}
	system("pause");
	system("cls");
	while (choice)
	{
		studentmenu();
		cin >> choice;
		switch (choice)
		{
		case 0:cout << "欢迎下次使用" << endl; break;
		case 1:apply(stu,studentv,roomv); break;
		case 2:showapply(stu); break;
		case 3:lookapply(studentv); break;
		case 4:disapply(stu, studentv,roomv); break;
		default:cout << "输入不合理，请重新输入" << endl;
		}
		reservenum(teacherv, studentv, roomv);
		system("pause");
		system("cls");
	}
}