#include "student.h"

Student::Student()
{


}

Student::Student(int id, string name, string pwd)
{
	//��ʼ������
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;


	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}

	ifs.close();

}

void Student::operMenu()
{
	cout << "��ӭѧ����" << this->m_Name << "��¼��" << endl;
	cout << "\t\t----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           1������ԤԼ           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           2���鿴�ҵ�ԤԼ       |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           3���鿴����ԤԼ       |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           4��ȡ��ԤԼ           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           0��ע����¼           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t----------------------------------\n";
	cout << "��ѡ����Ĳ�����" << endl;
}


//����ԤԼ
void Student::applyOrder()
{
	cout << "�������ŵ�ʱ��Ϊ��һ~���壡" << endl;
	cout << "������ԤԼʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;


	int data = 0;   //����
	int interval = 0;  //ʱ���
	int room = 0;  //������


	while (true)
	{
		cin >> data;
		if (data >= 1 && data <= 5)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}

	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "����������������룡" << endl;
	}

	cout << "��ѡ�������" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "�Ż���������Ϊ��" << vCom[i].m_MaxNum << endl;
	}

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "�����������������룡" << endl;
	}

	cout << "ԤԼ�ɹ�������У�" << endl;



	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);   //׷�ӵķ�ʽ���ļ�

	ofs << "data��" << data << "  ";
	ofs << "interval��" << interval << "  ";
	ofs << "stuId��" << this->m_Id << "  ";
	ofs << "stuName��" << this->m_Name << "  ";
	ofs << "roomId��" << room << "  ";
	ofs << "status��" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

void Student::showOrder()
{
}

void Student::showAllOrder()
{
}

void Student::cancelOrder()
{
}
