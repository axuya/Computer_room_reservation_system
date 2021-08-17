#include<iostream>
#include"Identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<fstream>
#include<string>
using namespace std;
//�����ʦ���Ӳ˵�����
void teacherMenu(Identity*& teacher) {
	while (true) {
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;
		if (select == 1) {
			tea->showAllOrder();
		}
		else if (select == 2) {
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����ѧ�����Ӳ˵�����
void studentMenu(Identity* &student) {
	while (true)
	{
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1) {
			stu->applyOrder();
		}
		else if (select == 2) {
			stu->showMyOrder();
		}
		else if (select == 3) {
			stu->showAllOrder();
		}
		else if (select == 4) {
			stu->cancelOrder();
		}//ȡ��ԤԼ
		else {
			delete student;
			cout << "ע����¼�ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
	}



}



//�������Ա���Ӳ˵�
void managerMenu(Identity* &manager) {
	while (true) {
		//���ù���Ա�Ӳ˵�
		manager->operMenu();

		//������ָ��תΪ����ָ�룬����������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û���ѡ��
		cin >> select;
		if (select == 1) {
			//cout << "����˺�" << endl;
			man->addPerson();
		}//����˺�
		else if (select == 2) {
			//cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			//cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			//cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else {
			delete manager;//
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}


	}
}

//��¼
void LoginIn(string fileName, int type) {
	Identity* person = NULL;//����ָ�� ָ���������

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;


	if (type == 1) {
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1) {
		//ѧ�������֤
		int fId;//���ļ��ж�ȡ��id
		string fName;//���ļ��л�ȡ������;
		string fPwd;
		while (ifs>>fId&&ifs>>fName&&ifs>>fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Student(id,name,pwd);

				//���뵽ѧ�����Ӳ˵�
				studentMenu(person);

				return;
			}
		}


	}
	else if (type == 2) {
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				//�����ʦ���Ӳ˵�
				teacherMenu(person);
				
				return;


			}
		}

	}
	else if (type == 3) {
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (name == fName && pwd == fPwd) {
				cout << "����Ա��¼�ɹ���" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}



	}

	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");

	return;

}












int main() {

	int select = 0;//���ڽ����û���ѡ��

	while (true) {
		cout << "**********��ӭ��¼ѧУ����ϵͳ**********" << endl;
		cout << endl << "���������������Ϣ��" << endl;
		cout << "                                         " << endl;
		cout << "             1.ѧ������                  " << endl;
		cout << "                                         " << endl;
		cout << "             2.��    ʦ                  " << endl;
		cout << "                                         " << endl;
		cout << "             3.�� �� Ա                  " << endl;
		cout << "                                         " << endl;
		cout << "             0.��    ��                  " << endl;
		cout << "                                         " << endl;
		cout << "-----------------------------------------" << endl;
		cout << "����������ѡ��                         " << endl;

		cin >> select;

		switch (select) {

		case 1://ѧ��

			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;//�˳�����ϵͳ
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}



	system("pause");
	return 0;
}