#pragma once
#include"Identity.h"
#include"computerRoom.h"

//学生类
class Student:public Identity
{
public:
	//默认构造
	Student();

	//有参构造    参数：学号、姓名、密码
	Student(int id, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

	//查看自身预约
	void showOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//学生学号
	int m_Id;

	//申请预约时，学生可以访问机房的信息
	vector<ComputerRoom>vCom;

};

