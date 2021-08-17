#include<iostream>
#include"Identity.h"
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<fstream>
#include<string>
using namespace std;
//进入教师的子菜单界面
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
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入学生的子菜单界面
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
		}//取消预约
		else {
			delete student;
			cout << "注销登录成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}



}



//进入管理员的子菜单
void managerMenu(Identity* &manager) {
	while (true) {
		//调用管理员子菜单
		manager->operMenu();

		//将父类指针转为子类指针，调用子类里的其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接收用户的选择
		cin >> select;
		if (select == 1) {
			//cout << "添加账号" << endl;
			man->addPerson();
		}//添加账号
		else if (select == 2) {
			//cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			//cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			//cout << "清空预约" << endl;
			man->cleanFile();
		}
		else {
			delete manager;//
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}


	}
}

//登录
void LoginIn(string fileName, int type) {
	Identity* person = NULL;//父类指针 指向子类对象

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	//准备接收用户信息
	int id = 0;
	string name;
	string pwd;


	if (type == 1) {
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1) {
		//学生身份验证
		int fId;//从文件中读取的id
		string fName;//从文件中获取的姓名;
		string fPwd;
		while (ifs>>fId&&ifs>>fName&&ifs>>fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd) {
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");

				person = new Student(id,name,pwd);

				//进入到学生的子菜单
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
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, pwd);
				//进入教师的子菜单
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
				cout << "管理员登录成功！" << endl;
				system("pause");
				system("cls");

				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}



	}

	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");

	return;

}












int main() {

	int select = 0;//用于接收用户的选择

	while (true) {
		cout << "**********欢迎登录学校机房系统**********" << endl;
		cout << endl << "请输入您的身份信息：" << endl;
		cout << "                                         " << endl;
		cout << "             1.学生代表                  " << endl;
		cout << "                                         " << endl;
		cout << "             2.教    师                  " << endl;
		cout << "                                         " << endl;
		cout << "             3.管 理 员                  " << endl;
		cout << "                                         " << endl;
		cout << "             0.退    出                  " << endl;
		cout << "                                         " << endl;
		cout << "-----------------------------------------" << endl;
		cout << "请输入您的选择：                         " << endl;

		cin >> select;

		switch (select) {

		case 1://学生

			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://教师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;//退出整个系统
			break;
		default:
			cout << "输入有误，请重新输入！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}



	system("pause");
	return 0;
}