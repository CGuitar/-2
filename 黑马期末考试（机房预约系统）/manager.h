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
	//默认构造
	Manager();

	//有参构造    参数：姓名、密码
	Manager(string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//去除重复信息
	void initVector();

	//学生容器
	vector<Student>vStu;

	//教师容器
	vector<Teacher>vTea;

	//检测是否重复   参数：（传入id，传入类型） 返回值：（true代表有重复）
	bool checkRepeat(int id, int type);

	//机房信息
	vector<ComputerRoom>vCom;
};