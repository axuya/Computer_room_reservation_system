#include"teacher.h"

Teacher::Teacher() {


}

Teacher::Teacher(int empId, string name, string pwd) {
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;

}

void Teacher::operMenu() {
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "                                         " << endl;
	cout << "             1.�鿴����ԤԼ                  " << endl;
	cout << "                                         " << endl;
	cout << "             2.�� ��  Ԥ Լ                  " << endl;
	cout << "                                         " << endl;
	cout << "             0.ע ��  �� ¼                  " << endl;
	cout << "                                         " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "����������ѡ��                         " << endl;
}

void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << ". ";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
		cout << "���ڣ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << "ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << "������" << of.m_orderData[i]["stuName"];
		cout << "������" << of.m_orderData[i]["roomId"];

		string status = "״̬��";
		if (of.m_orderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "���δ�ɹ���ԤԼʧ�ܣ�";
		}
		else {
			status += "ԤԼ��ȡ����";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::validOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˼�¼���£�" << endl;

	vector<int> v;

	int index = 0;
	for (int i = 0; i < of.m_Size; i++) {
		if (of.m_orderData[i]["status"] == "1") {
			v.push_back(i);
			cout << ++index << endl;
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
			cout << "���ڣ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << "������" << of.m_orderData[i]["roomId"];
			string status = "״̬��";
			if (of.m_orderData[i]["status"] == "1") {
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1") {
				status += "���δ�ɹ���ԤԼʧ�ܣ�";
			}
			else {
				status += "ԤԼ��ȡ����";
			}
			cout << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼��0��������" << endl;
	int select = 0;
	int ret = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "��������˽��" << endl;
				cout << "1.ͨ��" << endl;
				cout << "2.��ͨ��" << endl;
				cin >> ret;

				if (ret == 1) {
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else {
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updataOrder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");

}