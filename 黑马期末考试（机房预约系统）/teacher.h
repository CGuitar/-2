#pragma once
#include"Identity.h"






class Teacher:public Identity
{
public:
	//默认构造
	Teacher();

	//有参构造    参数：编号、姓名、密码
	Teacher(int empId, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//学生学号
	int m_EmpId;


};

