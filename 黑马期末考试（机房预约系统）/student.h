#pragma once
#include"Identity.h"
#include"computerRoom.h"

//ѧ����
class Student:public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���    ������ѧ�š�����������
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴����ԤԼ
	void showOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_Id;

	//����ԤԼʱ��ѧ�����Է��ʻ�������Ϣ
	vector<ComputerRoom>vCom;

};

