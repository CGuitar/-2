#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<fstream>
#include"globalFile.h"  //����ȫ��ͷ�ļ�




class Identity
{
public:
	//�����˵�   �����麯����
	virtual void operMenu() = 0;



	string m_Name;
	string m_Pwd;  //����

};