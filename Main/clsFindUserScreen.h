#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"



using namespace std;













class clsFindUserScreen : protected clsScreen
{
private:

	static	void _PrintUser(clsUser User)
	{
		cout << "\nUser Card    :" << endl;
		cout << "_____________________________________" << endl;
		cout << "First Name     :" << User.FirstName << endl;
		cout << "Last Name      :" << User.LastName << endl;
		cout << "Full Name      :" << User.FullName() << endl;
		cout << "Email          :" << User.Email << endl;
		cout << "Phone          :" << User.Phone << endl;
		cout << "User  Name     :" << User.UserName << endl;
		cout << "Password       :" << User.Password << endl;
		cout << "Permissions    :" << User.Permissions << endl;
		cout << "_____________________________________" << endl;

	}

public:
	static	void ShowFindUserScreen()
	{

		_DrawScreenHeader("\t Find User Screen");

		string UserName = "";

		cout << "\nPlease Enter User Name :";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Is Not Found, Choose Another One:";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User1 = clsUser::Find(UserName);

		

		if (!User1.IsEmpty())
		{
			cout << "\nUser Found:-)\n";
		}
		else
		{
			cout << "\nUser Was Not Found:-(\n";
		}
		_PrintUser(User1);



	}


};

