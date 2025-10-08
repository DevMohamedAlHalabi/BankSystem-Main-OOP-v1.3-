#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"





using namespace std;








class clsUpdateClientScreen:protected clsScreen
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


	static	void _ReadClientInfo(clsBankClients& Client)
	{
		cout << "_____________________________________" << endl;

		cout << "\nEnter First Name     :";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name      :";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email          :";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone          :";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password        :";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance:";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();

		cout << "_____________________________________" << endl;

	}

public:
	static	void 	ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{

			return;
		}
		_DrawScreenHeader("\tUpDate Client Screen");

		

		string AccountNumber = "";

		cout << "\nPlease Enter Client Account Number :";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClients::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Not Found, Choose Another One:";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClients Client1 = clsBankClients::Find(AccountNumber);
			_PrintClient(Client1);
		

		cout << "\nUpdate Client Info :" << endl;
		_ReadClientInfo(Client1);

		clsBankClients::enSaveResult SaveResult;
		SaveResult = Client1.Save();

		switch (SaveResult)
		{
		case clsBankClients::enSaveResult::svSuccesseded:
			cout << "\nAccount Updated Successfully:-)" << endl;
			_PrintClient(Client1);
			break;

		case clsBankClients::enSaveResult::svFaildEmpty:
			cout << "\nError Account Was Not Saved Because It's Empty" << endl;
			break;

		}
	}

};

