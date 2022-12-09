#include<iostream>
using namespace std;
#include"Identity.h"
#include<fstream>
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"







//进入学生的子菜单界面
void studentMenu(Identity* &student)
{
	while (true)
	{
		//调用学生子菜单
		student->operMenu();  //一级菜单
		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1)  //申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)  //查看自身预约
		{
			stu->showOrder();
		}
		else if (select == 3)   //查看所有预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)   //取消预约
		{
			stu->cancelOrder();
		}
		else   //退出学生二级菜单
		{
			delete student;    //开辟到堆区的指针要手动清理
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}

	}

}

















//进入管理员子菜单界面
void managerMenu(Identity*& manager)   //传入父类指针
{
	while (true)
	{
		//调用管理员的子菜单
		manager->operMenu();
		
		//将父类指针转为子类指针，调用子类里的其他接口
		Manager* man = (Manager*)manager;

		int select = 0;

		//接受用户选择
		cin >> select;
		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else  //注销
		{
			delete manager;   //销毁堆区对象
			cout << "注销成功！" << endl;

			system("pause");
			system("cls");
			return;
		}  
	}
}




//登入功能   参数一：操作文件名    参数二：操作身份类型
void LoginIn(string fileName, int type)
{
	//父类指针指向子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	//准备接受用户信息 
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)//学生：
	{
		cout << "请输入学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fId;  //从文件中获取的id
		string fName;
		string fPwd;

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//与用户信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//进入学生身份的子菜单
				studentMenu(person);

				return;
			}

		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师子菜单


				return;
			}
		}

	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员登录成功！" << endl;
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name, pwd);


				//进入管理员子菜单
				managerMenu(person);

				return;
			}
		}
	}


	cout << "验证失败！" << endl;
	system("pause");
	system("cls");
	return;
}







void showMenu()   //一级窗口
{
	cout << "===========欢迎来到机房预约系统========" << endl;
	cout << endl << "请输入你的身份" << endl;
	cout << "\t\t----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           1、学生代表           |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           2、老师               |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           3、管理员             |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|           0、退出               |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t----------------------------------\n";
	cout << "请输入你的选择：" << endl;
}


int main()
{
	int select = 0;     //接受用户选择

	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;

		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;

		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;

		case 0:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	

	system("pause");
	return 0;
}