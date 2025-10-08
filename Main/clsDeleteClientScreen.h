#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"



using namespace std;






class clsDeleteClientScreen:protected clsScreen
{
private:

	static	void _PrintClient(clsBankClients Client)
	{
		cout << "\nClient Card    :" << endl;
		cout << "_____________________________________" << endl;
		cout << "First Name     :" << Client.FirstName << endl;
		cout << "Last Name      :" << Client.LastName << endl;
		cout << "Full Name      :" << Client.FullName() << endl;
		cout << "Email          :" << Client.Email << endl;
		cout << "Phone          :" << Client.Phone << endl;
		cout << "Account Number :" << Client.AccountNumber() << endl;
		cout << "Password       :" << Client.PinCode << endl;
		cout << "Account Balance:" << Client.AccountBalance << endl;
		cout << "_____________________________________" << endl;


	}

public:

	static	void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{

			return;
		}

		_DrawScreenHeader("\tDelete Client Screen");

		

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number :";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClients::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Not Found, Choose Another One:";
			AccountNumber = clsInputValidate::ReadString();
		}


		clsBankClients DeleteClient = clsBankClients::Find(AccountNumber);
		_PrintClient(DeleteClient);

		char Answer = 'n';

		cout << "\nAre you sure you want delete this client? y/n ?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (DeleteClient.Delete())
			{
				cout << "\n\nClient Deleted Successfully:-)\n";
				_PrintClient(DeleteClient);
			}
			else
			{
				cout << "\nError Client Was Not Deleted\n";
			}

		}

	}






};

