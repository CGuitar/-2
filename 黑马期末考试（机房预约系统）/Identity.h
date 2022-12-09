#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<fstream>
#include"globalFile.h"  //包含全局头文件




class Identity
{
public:
	//操作菜单   （纯虚函数）
	virtual void operMenu() = 0;



	string m_Name;
	string m_Pwd;  //密码

};