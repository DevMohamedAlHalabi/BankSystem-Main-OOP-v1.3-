//#pragma once
//
//#include<iostream>
//#include<string>
//#include<iomanip>
//#include<cctype>
//#include<ctime>
//#include<fstream>
//#include<cmath>
//#include<cstdlib>
//#include<vector>
//
//#include "clsPerson.h"
//
//using namespace std;
//
//
//
//
//
//class clsEmployee :public clsPerson
//{
//private:
//	string _Title;
//	int _Salary;
//	string _Department;
//
//public:
//
//	clsEmployee(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary)
//		: clsPerson(ID, FirstName, LastName, Email, Phone)
//	{
//		_Title = Title;
//		_Salary = Salary;
//		_Department = Department;
//	}
//
//	void SetTitle(string Title)
//	{
//		_Title = Title;
//	}
//
//	string Title()
//	{
//		return _Title;
//	}
//
//	void SetDepartment(string Department)
//	{
//		_Department = Department;
//	}
//
//	string Department()
//	{
//		return _Department;
//	}
//
//	void SetSalary(int Salary)
//	{
//		_Salary = Salary;
//	}
//
//	int Salary()
//	{
//		return _Salary;
//	}
//
//	void Print()
//	{
//		//clsPerson::Print();
//
//		cout << "Info:" << endl;
//		cout << "_____________________________________" << endl;
//		cout << "ID        :" << ID() << endl;
//		cout << "First Name:" << FirstName() << endl;
//		cout << "Last Name :" << LastName() << endl;
//		cout << "Full Name :" << FullName() << endl;
//		cout << "Email     :" << Email() << endl;
//		cout << "Phone     :" << Phone() << endl;
//
//
//
//		cout << "Title     :" << _Title << endl;
//		cout << "Department:" << _Department << endl;
//		cout << "Salary    :" << _Salary << endl;
//		cout << "_____________________________________" << endl;
//
//	}
//
//};