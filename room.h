#pragma once

#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>

#include"student.h"
#include"tool.h"

class room
{
public:
	room(string num, string capacity,string size)
	{
		room_num=num;
		room_capacity=capacity;
		room_size = size;
	}
	string room_num;
	string room_capacity;
	string room_size;
};
