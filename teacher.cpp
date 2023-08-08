#include"techaer.h"
#include"tool.h"

void teachermenu()
{
	cout << "��������������������������������" << endl;
	cout << "������      ��������      ������" << endl;
	cout << "������    1. �鿴ԤԼ     ������" << endl;
	cout << "������    2. ����ԤԼ     ������" << endl;
	cout << "������      0. �˳�       ������" << endl;
	cout << "��������������������������������" << endl;
}

bool teach_codeverify(vector<teacher>& teacherv, teacher& teach)
{
	string name; string code; bool choice = true;
	vector<teacher>::iterator it =teacherv.begin();
	while (1)
	{
		cout << "��������������������������������" << endl;
		cout << "������      �����֤      ������" << endl;
		cout << "������     ����������     ������" << endl;
		cout << "��������������������������������" << endl;
		cin >> name;
		cout << "������     ����������     ������" << endl;
		cout << "��������������������������������" << endl;
		cin >> code;
		for (it = teacherv.begin(); it != teacherv.end(); it++)
		{
			if (it->tea_name == name)
			{
				if (it->tea_code == code)
				{
					cout << "������֤�ɹ���" << endl;
					teach.tea_code = it->tea_code;
					teach.tea_uid = it->tea_uid;
					teach.tea_name = it->tea_name;
					return true;
				}
				else
				{
					cout << "������֤ʧ�ܣ��˺Ż��������" << endl;
				}
			}
		}
		cout << "������֤ʧ�ܣ��˺Ż��������" << endl;
		cout << "�Ƿ������֤" << endl;
		cout << " 1.��   0.��" << endl;
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
	cout << "����������Ҫ�����ѧ����ţ�" << endl;
	cin >> uid;
	for (it = studentv.begin(); it != studentv.end(); it++)
	{
		if (it->stu_uid == uid)
		{
			cout << "ѧ��:" << it->stu_uid << " ����:" << it->stu_name << " ����:" << it->stu_day << " ʱ��:" << it->stu_time << " ������" << it->stu_room << " ״̬:" << it->status << endl;
			cout << "��ѡ����������Ϣ�Ĵ���" << endl;
			cout << "1.ͨ��  0.��ͨ��" << endl;
			cin >> choice;
			if (choice == 0)
			{
				it->status = "δͨ��";
			}
			else
			{
				it->status = "ͨ��";
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
		case 0:cout << "��ӭ�´�ʹ��" << endl; break;
		case 1:lookapply(studentv); break;
		case 2:addressapply(studentv); break;
		default:cout << "���벻��������������" << endl;
		}
		reservenum(teacherv, studentv, roomv);
		system("pause");
		system("cls");
	}
}