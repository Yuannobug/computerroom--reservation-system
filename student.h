#pragma once

#include<iostream>
using namespace std;

#include<string>
#include<vector>

void studentmain();

class student
{
public:
	student(string uid, string name, string code,string day,string time,string myroom,string mystatus)
	{
		stu_uid = uid;
		stu_name = name;
		stu_code = code;
		stu_day=day;
		stu_time = time;
		stu_room = myroom;
		status = mystatus;
	}
	string stu_uid;
	string stu_name;
	string stu_code;
	string status;
	string stu_day;
	string stu_time;
	string stu_room;
};

