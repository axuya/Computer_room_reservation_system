#include"student.h"

//默认构造
Student::Student() {


}

//有参构造（学号，姓名，密码）
Student::Student(int id, string name, string pwd) {
	//初始化属性
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum) {
		vCom.push_back(com);//读取信息放入容器中
	}

	ifs.close();

}

//菜单界面
void Student::operMenu() {
	cout << "欢迎学生：" << this->m_Name << "登录！" << endl;
	cout << "                                         " << endl;
	cout << "             1.申 请  预 约                  " << endl;
	cout << "                                         " << endl;
	cout << "             2.查看我的预约                  " << endl;
	cout << "                                         " << endl;
	cout << "             3.查看所有预约                  " << endl;
	cout << "                                         " << endl;
	cout << "             4.取 消  预 约                  " << endl;
	cout << "                                         " << endl;
	cout << "             0.注 销  登 录                  " << endl;
	cout << "                                         " << endl;
	cout << "-----------------------------------------" << endl;
	cout << "请输入您的选择：                         " << endl;
}

//申请预约
void Student::applyOrder() {
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;

	int data;
	int interval = 0;//时间段
	int room = 0;

	while (true) {
		cin >> data;
		if (data >= 1 && data <= 5) {
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}

	cout << "请输入申请预约的时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;

	while (true) {
		cin >> interval;
		if (interval >= 1 && interval <= 2) {
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}

	cout << "请选择机房：" << endl;
	for (int i = 0; i < vCom.size(); i++) {
		cout << vCom[i].m_ComId << "号机房容量为：" << vCom[i].m_MaxNum << endl;
	}

	while (true) {
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	cout << "预约成功！审核中..." << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "data：" << data << "";
	ofs << " interval：" << interval << "";
	ofs << " stuId：" << this->m_Id << "";
	ofs << " stuName：" << this->m_Name << "";
	ofs << " roomId：" << room << "";
	ofs << " stutas：" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");

}

//查看我的预约
void Student::showMyOrder() {//未实现
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无任何预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}


	for (int i = 0; i < of.m_Size; i++) {
		if (this->m_Id==atoi(of.m_orderData[i]["stuId"].c_str())) {
			cout << "预约日期：周" << of.m_orderData[i]["data"];
			cout << "日期：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << "机房：" << of.m_orderData[i]["roomId"];
			string status = "状态：";
			if (of.m_orderData[i]["status"] == "1") {
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1") {
				status += "审核未成功，预约失败！";
			}
			else {
				status += "预约已取消！";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");



}

//查看所有预约
void Student::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++) {
		cout << i + 1 << ". ";
		cout << "预约日期：周" << of.m_orderData[i]["data"];
		cout << "日期：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << "学号：" << of.m_orderData[i]["stuId"];
		cout << "机房：" << of.m_orderData[i]["stuName"];
		cout << "机房：" << of.m_orderData[i]["roomId"];

		string status = "状态：";
		if (of.m_orderData[i]["status"] == "1") {
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1") {
			status += "审核未成功，预约失败！";
		}
		else {
			status += "预约已取消！";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//取消预约
void Student::cancelOrder() {
	OrderFile of;
	if (of.m_Size == 0) {
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "审核中以及预约成功的记录可以取消，请输入取消的记录" << endl;

	vector<int> v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				v.push_back(i);
				cout << index++ << ". ";
				cout << "预约日期：周" << of.m_orderData[i]["data"];
				cout << "时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << "机房：" << of.m_orderData[i]["roomId"];
				string status = "状态：";
				if (of.m_orderData[i]["status"] == "1") {
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "预约成功";
				}
				else if (of.m_orderData[i]["status"] == "-1") {
					status += "审核未成功，预约失败！";
				}
				else {
					status += "预约已取消！";
				}
				cout << status << endl;


			}
		}
	}
	cout << "请选择取消的记录，0表示返回" << endl;
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
				cout << "已取消预约！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");



}