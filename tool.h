#pragma once

#include<iostream>
using namespace std;

#include"manager.h"
#include"techaer.h"
#include"student.h"
#include"room.h"

void reservenum(vector<teacher> teacherv, vector<student> studentv, vector<room> roomv);
void addmanager();
void Initmanager(vector<manager>& managerv);
void Initteacher(vector<teacher>& teacherv);
void Initstudent(vector<student>& studentv);
void addroom();
void Initroom(vector<room>& roomv);

void lookapply(vector<student> studentv);


