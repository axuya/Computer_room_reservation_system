#include"orderFile.h"

OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE,ios::in);

	string data;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;//预约状态

	this->m_Size = 0;//记录的条数

	while (ifs >> data && ifs >> interval && ifs >> stuId && 
		ifs >> stuName && ifs >> roomId && ifs >> status) {

		string key;
		string value;

		map<string, string> m;

		int pos = data.find(":");
		if (pos == -1) {
			key = data.substr(0, pos);
			value = data.substr(pos + 1, data.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = interval.find(":");
		if (pos == -1) {
			key = interval.substr(0, pos);               
			value = interval.substr(pos + 1, interval.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = stuId.find(":");//学号
		if (pos == -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);

			m.insert(make_pair(key, value));
		}		
		pos = stuName.find(":");//姓名
		if (pos == -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = roomId.find(":");//姓名
		if (pos == -1) {
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		pos = status.find(":");//姓名
		if (pos == -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();

}

void OrderFile::updataOrder() {
	if (this->m_Size == 0) {
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < m_Size; i++) {
		ofs << "data:" << this->m_orderData[i]["data"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
		
	}

	ofs.close();

}