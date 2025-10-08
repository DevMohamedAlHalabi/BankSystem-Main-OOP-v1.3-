#pragma once


#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsUser.h"
#include"clsGlobal.h"



using namespace std;


 


class clsLoginScreen :protected clsScreen
{
private:
	static	bool _Login()
	{
		bool LoginFaild = false;
		short FaildLoginCount = 0;

		string UserName, Password;


		do
		{
			if (LoginFaild)
			{
				FaildLoginCount++;
				cout << "\nInvlaid Username/Password!";
				cout << "\nYou Have " << (3-FaildLoginCount) << " Trials To Login.\n\n";
			}

			if (FaildLoginCount ==3)
			{
				cout << "\nYour Are Locked After 3 Faild Trails" << endl;
				return false;
			}

			cout << "Enter UserName? ";
			cin >> UserName;

			cout << "Enter Password? ";
			cin >> Password;


			CurrentUser = clsUser::Find(UserName, Password);

			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RegisterLogIn();

		clsMainScreen::ShowMainMenue();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();

	}
};

