#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include<map>
#include"globalFile.h"

class OrderFile {
public:
	OrderFile();//构造函数

	void updataOrder();

	map<int, map<string, string>> m_orderData;
	//记录的容器 key：记录的条数 value：具体记录的键值

	int m_Size;
};

