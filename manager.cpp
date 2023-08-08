#include"manager.h"
#include"tool.h"

bool codeverify(vector<manager> managerv)
{
	string name; string code; bool choice=true;
	vector<manager>::iterator it = managerv.begin();
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
		for (it = managerv.begin(); it != managerv.end(); it++)
		{
			if (it->man_name == name)
			{
				if (it->man_code == code)
				{
					cout << "������֤�ɹ���" << endl;
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

void managermenu()
{
	cout << "��������������������������������" << endl;
	cout << "������      ��������      ������" << endl;
	cout << "������    1. ����˺�     ������" << endl;
	cout << "������    2. �鿴�˺�     ������" << endl;
	cout << "������    3. �鿴����     ������" << endl;
	cout << "������    4. ���ԤԼ     ������" << endl;
	cout << "������      0. �˳�       ������" << endl;
	cout << "��������������������������������" << endl;
}

void addteacher(vector<teacher>& teacherv)
{
	string uid; string name; string code;
	cout << "�������ʦ����" << endl;
	cin >> name;
	cout << "�������ʦ���" << endl;
	cin >> uid;
	cout << "�������ʦ����" << endl;
	cin >> code;
	teacher temp(uid,name, code);
	teacherv.push_back(temp);
}

void addstudent(vector<student>& studentv)
{
	vector<student>::iterator it = studentv.begin();
	string uid ; string name; string code ;
	cout << "������ѧ������" << endl;
	cin >> name;
	cout << "������ѧ�����" << endl;
	cin >> uid;
	for (; it != studentv.end(); it++)
	{
		if (it->stu_uid == uid)
		{
			cout << "�û�����ظ�������������" << endl;
			return;
		}
	}
	cout << "������ѧ������" << endl;
	cin >> code;
	student temp(uid, name, code,"��", "��", "��", "δԤԼ");
	studentv.push_back(temp);
}

void add(vector<teacher>& teacherv, vector<student>& studentv)
{
	int choice = 1;
	while (choice)
	{
		cout << "��������������������������������" << endl;
		cout << "������      ��������      ������" << endl;
		cout << "������    1. ��ӽ�ʦ     ������" << endl;
		cout << "������    2. ���ѧ��     ������" << endl;
		cout << "������      0. �˳�       ������" << endl;
		cout << "��������������������������������" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:addteacher(teacherv); break;
		case 2:addstudent(studentv); break;
		case 0:cout << "��ӭ�´�ʹ��" << endl; break;
		default:cout << "���벻��������������" << endl;
		}
	}


}

void showpeople(vector<teacher> teacherv, vector<student> studentv)
{
	vector<teacher>::iterator it1 = teacherv.begin();
	vector<student>::iterator it2 = studentv.begin();
	if (teacherv.size() == 0 )
	{
		cout << "��ʦ��ϢΪ��" << endl;
	}
	else
	{
		cout << "����������������������������" << endl;
		cout << "������  ��ʦ��Ϣ      ������" << endl;
		cout << "����������������������������" << endl;
		for (it1 = teacherv.begin(); it1 != teacherv.end(); it1++)
		{
			cout << "��ʦ���:" << it1->tea_uid << "  ��ʦ����:" << it1->tea_name << endl;
		}
	}
	if (studentv.size() == 0)
	{
		cout << "ѧ����ϢΪ��" << endl;
	}
	else
	{
		cout << "����������������������������" << endl;
		cout << "������  ѧ����Ϣ      ������" << endl;
		cout << "����������������������������" << endl;
		for (it2 = studentv.begin(); it2 != studentv.end(); it2++)
		{
			cout << "ѧ�����:" << it2->stu_uid << "  ѧ������:" << it2->stu_name << "  ״̬:" << it2->status << endl;
		}
	}
}

void showroom(vector<room> roomv)
{
	vector<room>::iterator it = roomv.begin();
	for (it = roomv.begin(); it != roomv.end(); it++)
	{
		cout << "�������" << it->room_num << "   " << "��������" << it->room_capacity << endl;
	}
}



void clean(vector<student>& studentv,vector<room>& roomv)
{
	vector<student>::iterator it1 = studentv.begin();//ѧ��
	for (it1 = studentv.begin(); it1 != studentv.end(); it1++)
	{
		it1->stu_room = "��";
		it1->stu_time = "��";
		it1->stu_day = "��";
		it1->status = "δԤԼ";
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
		case 0:cout << "��ӭ�´�ʹ��" << endl; break;
		default:cout << "���벻��������������" << endl;
		}
		system("pause");
		system("cls");
	}
	reservenum(teacherv, studentv,roomv);
}