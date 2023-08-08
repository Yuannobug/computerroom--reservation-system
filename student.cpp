#include"student.h"
#include"manager.h"
#include"tool.h"

void studentmenu()
{
	cout << "��������������������������������" << endl;
	cout << "������      ��������      ������" << endl;
	cout << "������    1. ����ԤԼ     ������" << endl;
	cout << "������    2. �鿴ԤԼ     ������" << endl;
	cout << "������    3. ԤԼ�ܺ�     ������" << endl;
	cout << "������    4. ȡ��ԤԼ     ������" << endl;
	cout << "������      0. �˳�       ������" << endl;
	cout << "��������������������������������" << endl;
}


bool stu_codeverify(vector<student>& studentv,student& stu)
{
	string name; string code; bool choice = true;
	vector<student>::iterator it = studentv.begin();
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
		for (it = studentv.begin(); it !=studentv.end(); it++)
		{
			if (it->stu_name == name)
			{
				if (it->stu_code == code)
				{
					cout << "������֤�ɹ���" << endl;
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
	cout << "��ѡ��ԤԼ������" << endl;
	cout << "1.��һ 2.�ܶ� 3.���� 4.���� 5.����" << endl;
	cout << "ע����Ϣ�ղ����Ż���" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:stu.stu_day = "��һ"; break;
	case 2:stu.stu_day = "�ܶ�"; break;
	case 3:stu.stu_day = "����"; break;
	case 4:stu.stu_day = "����"; break;
	case 5:stu.stu_day = "����"; break;
	}
	cout << "��ѡ��ԤԼ��ʱ��� " << endl;
	cout << "1.���� 2.����" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:stu.stu_time = "����"; break;
	case 2:stu.stu_time = "����"; break;
	}
	cout << "��ѡ�����" << endl;
	cout << "1.����1   2.����2" << endl;//���ʼ���ı�Ӧ�ı�
	cin >> choice;
	if (roomv[0].room_size == roomv[0].room_capacity)
	{
		cout << "����1����" << endl;
		choice = 2;
	}
	if (roomv[1].room_size == roomv[1].room_capacity)
	{
		cout << "����1����" << endl;
		choice = 1;
	}
	switch (choice)
	{
	case 1:stu.stu_room = "����1";  addroomnum(roomv[0].room_size);  break;
	case 2:stu.stu_room = "����2";  addroomnum(roomv[1].room_size); break;
	}
	stu.status = "�����";
	changev(stu, studentv);
}

void showapply(student stu)
{
	cout << "ѧ��:"<<stu.stu_uid << " ����:"<<stu.stu_name << " ����:"<<stu.stu_day << " ʱ��:"<<stu.stu_time<<" ������"<<stu.stu_room << " ״̬:" << stu.status << endl;
}


void disapply(student& stu, vector<student>& studentv, vector<room>& roomv)
{
	int judge = 0;
	cout << "��ȷ���Ƿ�ȡ��ԤԼ" << endl;
	cout << "1. ��   0. ��" << endl;
	cin >> judge;
	if (judge == 0)
	{
		return;
	}
	else
	{
		if (stu.stu_room == "����1")
		{
			subroomnum(roomv[0].room_size);
		}
		else
		{
			subroomnum(roomv[1].room_size);
		}
		stu.status = "δԤԼ";
		stu.stu_day = "��";
		stu.stu_room = "��";
		stu.stu_time = "��";
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
		case 0:cout << "��ӭ�´�ʹ��" << endl; break;
		case 1:apply(stu,studentv,roomv); break;
		case 2:showapply(stu); break;
		case 3:lookapply(studentv); break;
		case 4:disapply(stu, studentv,roomv); break;
		default:cout << "���벻��������������" << endl;
		}
		reservenum(teacherv, studentv, roomv);
		system("pause");
		system("cls");
	}
}