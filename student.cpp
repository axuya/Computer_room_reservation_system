#include"student.h"

//Ĭ�Ϲ���
Student::Student() {


}

//�вι��죨ѧ�ţ����������룩
Student::Student(int id, string name, string pwd) {
	//��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);//��ȡ��Ϣ����������
	}

	ifs.close();

}

//�˵�����
void Student::operMenu() {
	cout << "��ӭѧ����" << this->m_Name << "��¼��" << endl;
	cout << "                                         " << endl;
	cout << "             1.�� ��  Ԥ Լ                  " << endl;
	cout << "                                         " << endl;
	cout << "             2.�鿴�ҵ�ԤԼ                  " << endl;
	cout << "                                         " << endl;
	cout << "             3.�鿴����ԤԼ                  " << endl;
	cout << "                                         " << endl;
	cout << "             4.ȡ ��  Ԥ Լ                  " << endl;
	cout << "                                         " << endl;
	cout << "             0.ע ��  �� ¼                  " << endl;
	cout << "                                         " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "����������ѡ��                         " << endl;
}

//����ԤԼ
void Student::applyOrder() {
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

	int data;
	int interval = 0;//ʱ���
	int room = 0;

	while (true) {
		cin >> data;
		if (data >= 1 && data <= 5) {
			break;
		}
		cout << "�����������������룡" << endl;
	}

	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;

	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "�����������������룡" << endl;
	}

	cout << "��ѡ�������" << endl;
	for (int i = 0; i < vCom.size(); i++) {
		cout << vCom[i].m_ComId << "�Ż�������Ϊ��" << vCom[i].m_MaxNum << endl;
	}

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "�����������������룡" << endl;
	}
	cout << "ԤԼ�ɹ��������..." << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "data��" << data << "";
	ofs << " interval��" << interval << "";
	ofs << " stuId��" << this->m_Id << "";
	ofs << " stuName��" << this->m_Name << "";
	ofs << " roomId��" << room << "";
	ofs << " stutas��" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");

}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder() {//δʵ��
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "���κ�ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}


	for (int i = 0; i < of.m_Size; i++) {
		if (this->m_Id==atoi(of.m_orderData[i]["stuId"].c_str())) {
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
	system("pause");
	system("cls");



}

//�鿴����ԤԼ
void Student::showAllOrder() {
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

//ȡ��ԤԼ
void Student::cancelOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "��ԤԼ��¼��" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "������Լ�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				v.push_back(i);
				cout << index++ << ". ";
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["data"];
				cout << "ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
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
	}
	cout << "��ѡ��ȡ���ļ�¼��0��ʾ����" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updataOrder();
				cout << "��ȡ��ԤԼ��" << endl;
				break;
			}
		}
		cout << "�����������������룡" << endl;
	}
	system("pause");
	system("cls");



}