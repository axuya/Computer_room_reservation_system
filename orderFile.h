#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include<map>
#include"globalFile.h"

class OrderFile {
public:
	OrderFile();//���캯��

	void updataOrder();

	map<int, map<string, string>> m_orderData;
	//��¼������ key����¼������ value�������¼�ļ�ֵ

	int m_Size;
};

