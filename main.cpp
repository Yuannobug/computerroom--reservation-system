#include<iostream>
using namespace std;

#include"student.h"
#include"manager.h"
#include"techaer.h"

void showmenu()
{
	cout << "��������������������������������" << endl;
	cout << "������      ��½����      ������" << endl;
	cout << "������      1. ѧ��       ������" << endl;
	cout << "������      2. ��ʦ       ������" << endl;
	cout << "������      3. ����Ա     ������" << endl;
	cout << "������      0. �˳�       ������" << endl;
	cout << "��������������������������������" << endl;
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
		case 0:cout << "��ӭ�´�ʹ��" << endl; break;
		default:cout << "���벻��������������" << endl;
		}
	}

	system("pause");
	return 0;
}