#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"




using namespace std;

















class clsDeleteUserScreen :protected clsScreen
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

	static	void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\tDelete User Screen");
		string UserName = "";

		cout << "\nPlease Enter User Number :";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name Is Not Found, Choose Another One:";
			UserName = clsInputValidate::ReadString();
		}


		clsUser User1 = clsUser::Find(UserName);
		_PrintUser(User1);

		char Answer = 'n';

		cout << "\nAre you sure you want delete this User? y/n ?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (User1.Delete())
			{
				cout << "\n\nUser Deleted Successfully:-)\n";
				_PrintUser(User1);
			}
			else
			{
				cout << "\nError User Was Not Deleted\n";
			}

		}

	}






};


