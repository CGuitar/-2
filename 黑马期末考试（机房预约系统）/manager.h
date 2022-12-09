#pragma once
#include"Identity.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"globalFile.h"
#include<fstream>
#include"computerRoom.h"

class Manager: public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���    ����������������
	Manager(string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//ȥ���ظ���Ϣ
	void initVector();

	//ѧ������
	vector<Student>vStu;

	//��ʦ����
	vector<Teacher>vTea;

	//����Ƿ��ظ�   ������������id���������ͣ� ����ֵ����true�������ظ���
	bool checkRepeat(int id, int type);

	//������Ϣ
	vector<ComputerRoom>vCom;
};