#pragma once

#include<iostream>
#include<string>




using namespace std;


class clsPerson
{

private:

	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;


public:

	clsPerson( string FirstName, string LastName, string Email, string Phone)
	{
		
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	string GetLastName()
	{
		return _LastName;
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	string GetPhone()
	{
		return _Phone;
	}

	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	__declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;
	__declspec(property(get = GetLastName, put = SetLastName))string LastName;
	__declspec(property(get = GetEmail, put = SetEmail))string Email;
	__declspec(property(get = GetPhone, put = SetPhone))string Phone;

	void Print()
	{
		cout << "Info:" << endl;
		cout << "_____________________________________" << endl;
		cout << "First Name:" << _FirstName << endl;
		cout << "Last Name :" << _LastName << endl;
		cout << "Full Name :" << FullName() << endl;
		cout << "Email     :" << _Email << endl;
		cout << "Phone     :" << _Phone << endl;
		cout << "_____________________________________" << endl;


	}

};
