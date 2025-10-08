#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


using namespace std;






class clsFindClientScreen : protected clsScreen
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
	static	void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{

			return;
		}

		_DrawScreenHeader("\tFind Client Screen");

	

		string AccountNumber="";

		cout << "\nPlease Enter Client Account Number :";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClients::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Not Found, Choose Another One:";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClients Client1 = clsBankClients::Find(AccountNumber);
		
		


		cout << "\nFind Client Info :" << endl;

		if (!Client1.IsEmpty())
		{
			cout << "\nClientFound:-)\n";
		}
		else
		{
			cout << "\nClient Was Not Found:-(\n";
		}
		_PrintClient(Client1);
		


		

	}


};

