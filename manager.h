#pragma once

#include<iostream>
using namespace std;

#include<string>
#include<vector>
#include<fstream>



void managermain();

class manager
{
public:
	manager(string name, string code)
	{
		man_name = name;
		man_code = code;
	}
	string man_name;
	string man_code;
};
