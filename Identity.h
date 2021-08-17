#pragma once
#include<iostream>
using namespace std;

class Identity {
public:


	//操作系统
	virtual void operMenu() = 0;//纯虚函数

	string m_Name;//用户名
	string m_Pwd;//密码



};