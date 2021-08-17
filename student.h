#pragma once
#include<iostream>
#include<vector>
#include"computerRoom.h"
using namespace std;
#include"Identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"

class Student :public Identity {
public:
	//默认构造
	Student();

	//有参构造（学号，姓名，密码）
	Student(int id, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	int m_Id;//学生学号

	vector<ComputerRoom> vCom;
};