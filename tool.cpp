#include"tool.h"


void addmanager()
{
	int num = 0; int i = 0; string name; string code;
	ofstream ofs;
	ofs.open("manager.csv", ios::out);
	cout << "����������Ĺ���Ա��Ŀ" << endl;
	cin >> num;
	for (i = 0; i < num; i++)
	{
		cout << "����������" << endl;
		cin >> name;
		cout << "���������Ա����" << endl;
		cin >> code;
		ofs << name << "," << code << "," << endl;
	}
	ofs << endl;
	ofs.close();
}

void Initmanager(vector<manager>& managerv)
{
	ifstream ifs;
	ifs.open("manager.csv", ios::in);
	if (!ifs.is_open())//�ļ�������
	{
		cout << "���ݲ�����,���޸ĵײ���Ϣ" << endl;
		addmanager();
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//�ļ�Ϊ��
	{
		cout << "���ݲ�����,���޸ĵײ���Ϣ" << endl;
		addmanager();
	}
	ifs.close();
	ifs.open("manager.csv", ios::in);//�ļ����ڣ���ʼ¼��
	string buf;
	string tempname;
	string tempcode;
	int begin = 0;
	int judge = 0;
	while (ifs >> buf)
	{
		begin = 0;
		judge = 0;
		judge = buf.find(',', begin);
		tempname = buf.substr(begin, judge - begin);
		begin = judge + 1;
		judge = buf.find(',', begin);
		tempcode = buf.substr(begin, judge - begin);
		manager temp(tempname, tempcode);
		managerv.push_back(temp);
	}
	ifs.close();
}

void Initteacher(vector<teacher>& teacherv)
{
	ifstream ifs;
	ifs.open("teacher.csv", ios::in);
	if (!ifs.is_open())//�ļ�������
	{
		cout << "���ݲ�����" << endl;
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//�ļ�Ϊ��
	{
		cout << "���ݲ�����" << endl;
		return;
	}
	ifs.close();
	ifs.open("teacher.csv", ios::in);//�ļ����ڣ���ʼ¼��
	string buf;
	string tempuid;
	string tempname;
	string tempcode;
	int begin = 0;
	int judge = 0;
	while (ifs >> buf)
	{
		begin = 0;
		judge = 0;
		judge = buf.find(',', begin);
		tempuid = buf.substr(begin, judge - begin);
		begin = judge + 1;
		judge = buf.find(',', begin);
		tempname = buf.substr(begin, judge - begin);
		begin = judge + 1;
		judge = buf.find(',', begin);
		tempcode = buf.substr(begin, judge - begin);
		teacher temp(tempuid, tempname, tempcode);
		teacherv.push_back(temp);
	}
	ifs.close();
}

void Initstudent(vector<student>& studentv)
{
	ifstream ifs;
	ifs.open("student.csv", ios::in);
	if (!ifs.is_open())//�ļ�������
	{
		cout << "���ݲ�����" << endl;
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//�ļ�Ϊ��
	{
		cout << "���ݲ�����" << endl;
		return;
	}
	ifs.close();
	ifs.open("student.csv", ios::in);//�ļ����ڣ���ʼ¼��
	string buf;
	string tempuid;
	string tempname;
	string tempcode;
	string tempday;
	string temptime;
	string temproom;
	string tempstauts;
	int begin = 0;
	int judge = 0;
	while (ifs >> buf)
	{
		begin = 0;
		judge = 0;
		judge = buf.find(',', begin);
		tempuid = buf.substr(begin, judge - begin);
		begin = judge + 1;
		judge = buf.find(',', begin);
		tempname = buf.substr(begin, judge - begin);
		begin = judge + 1;
		judge = buf.find(',', begin);
		tempcode = buf.substr(begin, judge - begin);
		begin = judge + 1;
		judge = buf.find(',', begin);
		tempday = buf.substr(begin, judge - begin);
		begin = judge + 1;
		judge = buf.find(',', begin);
		temptime = buf.substr(begin, judge - begin);
		begin = judge + 1;
		judge = buf.find(',', begin);
		temproom = buf.substr(begin, judge - begin);
		begin = judge + 1;
		judge = buf.find(',', begin);
		tempstauts = buf.substr(begin, judge - begin);
		student temp(tempuid, tempname, tempcode, tempday, temptime, temproom,tempstauts);
		studentv.push_back(temp);
	}
	ifs.close();
}

void addroom()
{
	int num = 0; int i = 0; 
	string capacity; string id; string size = "0";
	ofstream ofs;
	ofs.open("room.csv", ios::out);
	cout << "����������ķ�����Ŀ" << endl;
	cin >> num;
	for (i = 0; i < num; i++)
	{
		cout << "�����뷿����" << endl;
		cin >>id;
		cout << "�����뷿���С" << endl;
		cin >> capacity;
		ofs << id << "," << capacity << "," << size <<"," << endl;
	}
	ofs << endl;
	ofs.close();
}

void Initroom(vector<room>& roomv)
{
	ifstream ifs;
	ifs.open("room.csv", ios::in);
	if (!ifs.is_open())//�ļ�������
	{
		cout << "���ݲ�����,���޸ĵײ���Ϣ" << endl;
		addroom();
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//�ļ�Ϊ��
	{
		cout << "���ݲ�����,���޸ĵײ���Ϣ" << endl;
		addroom();
	}
	ifs.close();
	ifs.open("room.csv", ios::in);//�ļ����ڣ���ʼ¼��
	string buf;
	string tempnum;
	string tempcapacity;
	string tempsize;
	int begin = 0;
	int judge = 0;
	while (ifs >> buf)
	{
		begin = 0;
		judge = 0;
		judge = buf.find(',', begin);
		tempnum = buf.substr(begin, judge - begin);
		begin = judge + 1;
		judge = buf.find(',', begin);
		tempcapacity = buf.substr(begin, judge - begin);
		begin = judge + 1;
		judge = buf.find(',', begin);
		tempsize = buf.substr(begin, judge - begin);
		room temp(tempnum, tempcapacity, tempsize);
		roomv.push_back(temp);

	}
	ifs.close();
}


void reservenum(vector<teacher> teacherv, vector<student> studentv, vector<room> roomv)
{
	ofstream ofs;
	vector<teacher>::iterator it1 = teacherv.begin();//��ʦ
	ofs.open("teacher.csv", ios::out);
	for (it1 = teacherv.begin(); it1 != teacherv.end(); it1++)
	{
		ofs << it1->tea_uid << "," << it1->tea_name << "," << it1->tea_code << ",";
		ofs << endl;
	}
	ofs.close();
	vector<student>::iterator it2 = studentv.begin();//ѧ��
	ofs.open("student.csv", ios::out);
	for (it2 = studentv.begin(); it2 != studentv.end(); it2++)
	{
		ofs << it2->stu_uid << "," << it2->stu_name << "," << it2->stu_code << "," << it2->stu_day << "," << it2->stu_time << "," << it2->stu_room << ","<< it2->status<<",";
		ofs << endl;
	}
	ofs.close();
	vector<room>::iterator it3 = roomv.begin();//ѧ��
	ofs.open("room.csv", ios::out);
	for (it3 = roomv.begin(); it3 != roomv.end(); it3++)
	{
		ofs << it3->room_num << "," << it3->room_capacity << "," << it3->room_size << ",";
		ofs << endl;
	}
	ofs.close();
	cout << "���ݱ���ɹ�" << endl;
}

void lookapply(vector<student> studentv)
{
	vector<student>::iterator it = studentv.begin();
	for (it = studentv.begin(); it != studentv.end(); it++)
	{
		cout << "ѧ��:" << it->stu_uid << " ����:" << it->stu_name << " ����:" << it->stu_day << " ʱ��:" << it->stu_time << " ������" << it->stu_room << " ״̬:" << it->status << endl;
	}
}
