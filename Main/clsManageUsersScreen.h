#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListUsersScreen.h"
#include "clsAddNewUsersScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"




using namespace std;








class clsManageUsersScreen:protected clsScreen
{

private:
	enum enManageUsersMenueOptions
	{
		eListUsers = 1,
		eAddNewUser = 2,
		eDeleteUser = 3,
		eUpdateUser = 4,
		eFindUser = 5,
		eMainMenue = 6
	};

	static	short _ReadManageUsersMenueOption()
	{
		cout<< setw(37) << left << "" << "Choose what do you want to do?[1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 To 6 ?");
		return Choice;
	}

	static	void _GoBackToManageUsersMenue()
	{
		cout << "\n\nPress any key to go back to Manage Users  Menue....\n";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void  _ShowListUsersScreen()
	{
		//cout << "List User Will Be Here.... " << endl;
		clsListUsersScreen::ShowUsersList();
	}
	static void  _ShowAddNewUsersScreen()
	{
		//cout << " Add New User Will Be Here.... " << endl;
		clsAddNewUsersScreen::ShowAddNewUsersScreen();
	}
	static void  _ShowDeleteUsersScreen()
	{
		//cout << " Delete User Will Be Here....  " << endl;
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void  _ShowUpdateUsersScreen()
	{
		//cout << " Update User Will Be Here.... " << endl;
		clsUpdateUserScreen::ShowUpdateUsersScreen();
	}
	static void  _ShowFindUsersScreen()
	{
		//cout << "Find User Will Be Here.... " << endl;
		clsFindUserScreen::ShowFindUserScreen();
	}
	
	static	void _PerfromManageUsersMenueOption
	(enManageUsersMenueOptions ManageUsersMenueOptions)
	{
		switch (ManageUsersMenueOptions)
		{
		case enManageUsersMenueOptions::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eFindUser:
		{
			system("cls");
			_ShowFindUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		}
		case enManageUsersMenueOptions::eMainMenue:
		{
			////// do nothing here the main screen will be handle it:-)
		}
		}
	}

public:
	static	void ShowManageUsersMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{

			return;
		}
		system("cls");

		_DrawScreenHeader("\t  Manage Users Screen");

		

		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users .\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "==================================\n";
		
		_PerfromManageUsersMenueOption
		((enManageUsersMenueOptions)_ReadManageUsersMenueOption());

	}
};

