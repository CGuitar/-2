#pragma once
#include"Identity.h"






class Teacher:public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���    ��������š�����������
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//ѧ��ѧ��
	int m_EmpId;


};

