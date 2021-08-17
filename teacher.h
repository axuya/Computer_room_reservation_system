#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
#include"Identity.h"
#include"orderFile.h"

class Teacher :public Identity {
public:

	Teacher();

	Teacher(int empId, string name, string pwd);

	virtual void operMenu();

	void showAllOrder();

	void validOrder();//…Û∫À‘§‘º

	int m_EmpId;
};