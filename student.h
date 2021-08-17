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
	//Ĭ�Ϲ���
	Student();

	//�вι��죨ѧ�ţ����������룩
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	int m_Id;//ѧ��ѧ��

	vector<ComputerRoom> vCom;
};