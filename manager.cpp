#include"manager.h"

Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ������
	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);
	}
	ifs.close();
	cout << "��������Ϊ��" << vCom.size() << endl;

}

void Manager::operMenu() {
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "                                         " << endl;
	cout << "             1.����˺�                  " << endl;
	cout << "                                         " << endl;
	cout << "             2.�鿴�˺�                  " << endl;
	cout << "                                         " << endl;
	cout << "             3.�鿴����                  " << endl;
	cout << "                                         " << endl;
	cout << "             4.���ԤԼ                  " << endl;
	cout << "                                         " << endl;
	cout << "             0.ע����¼                  " << endl;
	cout << "                                         " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "����������ѡ��                         " << endl;

}//ѡ��˵�

void Manager::addPerson() {
	cout << "����������˺ŵ���Ϣ" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.��ӽ�ʦ" << endl;

	string fileName;//�����ļ���
	string tip;//��ʾ
	string errorTip;
	
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 1) {
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ������������룡";
	}
	else {
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";//����չ��ѭ��
		errorTip = "ְ������ظ������������룡";
	}
	//����׷�ӵķ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip << endl;

	while (true) {
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret) {
			cout << errorTip << endl;
		}
		else {
			break;
		}
	}




	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//���ó�ʼ�������ӿ�
	this->initVector();

}

void printStudent(Student& s) {
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t) {
	cout << "ְ����ţ�" << t.m_EmpId << " ������" << t.m_Name<< " ���룺" << t.m_Pwd << endl;
}


void Manager::showPerson() {
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴���н�ʦ" << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else {
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");

}

void Manager::showComputer() {
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {
		cout << "�������Ϊ��" << it->m_ComId;
		cout << " �������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");

}

void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.clear();
	
	cout << "���ԤԼ�ɹ���" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector() {
	
	vStu.clear();
	vTea.clear();
	//��ȡ��Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}

	cout << "��ǰѧ��������" << vStu.size() << endl;
	ifs.close();


	//��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {
		vTea.push_back(t);
	}


}

bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->m_Id) {
				return true;
			}
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->m_EmpId) {
				return true;
			}
		}

	}
}