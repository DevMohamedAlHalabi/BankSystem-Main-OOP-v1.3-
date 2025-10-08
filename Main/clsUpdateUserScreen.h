#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;











class clsUpdateUserScreen :protected clsScreen
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


	static	void _ReadUserInfo(clsUser& User)
	{
		cout << "_____________________________________" << endl;

		cout << "\nEnter First Name     :";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name      :";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email          :";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone          :";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password       :";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions    :";
		User.Permissions = _ReadPermissionToSet();

		cout << "_____________________________________" << endl;

	}

	static	int _ReadPermissionToSet()
	{
		int Permissions = 0;
		char Answer = 'n';

		cout << "\nDo You want to give full access? y/n? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}
		cout << "\nDo You want to give access to: \n";

		cout << "\nShow Client List? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nShow Login Register? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pShowLoginRegister;
		}

		return Permissions;

	}



public:

	static	void ShowUpdateUsersScreen()
	{

		_DrawScreenHeader("\t Update User Screen");

		string UserName = "";

		cout << "\nPlease Enter User Name :";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nAccount Number Is Not Found, Choose Another One:";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User1 = clsUser::Find(UserName);
		_PrintUser(User1);

		char Answer = 'n';

		cout << "\nAre you sure you want Update this User? y/n ?";
		cin >> Answer;

		cout << "\n Update User Info :" << endl;

		if (Answer == 'y' || Answer == 'Y')
		{
			_ReadUserInfo(User1);

			clsUser::enSaveResult SaveResult;
			SaveResult = User1.Save();

			switch (SaveResult)
			{
			case clsUser::svSuccesseded:
			{
				cout << "\nUser Update  Successfully:-)" << endl;
				_PrintUser(User1);
				break;
			}

			case clsUser::svFaildEmpty:
			{
				cout << "\nError User Was Not Saved Because It's Empty" << endl;
				break;
			}
			}

		}
	}
};



