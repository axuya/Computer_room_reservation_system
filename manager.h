#pragma once
#include<iostream>
#include<vector>
#include"student.h"
#include"teacher.h"
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;
#include"Identity.h"
#include"computerRoom.h"
#include"globalFile.h"

class Manager :public Identity {
public:

	Manager();

	Manager(string name, string pwd);

	virtual void operMenu();

	void addPerson();

	void showPerson();

	void showComputer();

	void cleanFile();

	void initVector();//³õÊ¼»¯ÈÝÆ÷

	bool checkRepeat(int id, int type);

	vector<Student> vStu;

	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;
};