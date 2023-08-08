#pragma once

#include<iostream>
using namespace std;


void teachermain();

class teacher
{
public:
	teacher(string uid, string name, string code)
	{
		tea_uid = uid;
		tea_name = name;
		tea_code = code;
	}
	string tea_uid;
	string tea_name;
	string tea_code;	
};