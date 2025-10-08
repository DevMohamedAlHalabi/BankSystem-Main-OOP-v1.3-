#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>



using namespace std;






class clsAddNewClientScreen:protected clsScreen
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

		cout << "\nEnter PinCode        :";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter Account Balance:";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();

		cout << "_____________________________________" << endl;

	}


public:

static	void AddNewClient()
	{

	if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
	{

		return;
	}

	_DrawScreenHeader("\t Add New Client Screen");

	

		string AccountNumber = "";

		cout << "\nPlease Enter Account Number :";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClients::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Is Already Used, Choose Another One:";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClients NewClient = clsBankClients::GetAddNewClientObject(AccountNumber);

		cout << "\n Add New Client Info :" << endl;
		_ReadClientInfo(NewClient);

		clsBankClients::enSaveResult SaveResult;
		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClients::svSuccesseded:
		{
			cout << "\nAccount Addeded  Successfully:-)" << endl;
			_PrintClient(NewClient);
			break;
		}

		case clsBankClients::svFaildEmpty:
		{
			cout << "\nError Account Was Not Saved Because It's Empty" << endl;
			break;
		}

		case clsBankClients::svFaildAccountNumber:
		{
			cout << "\nError Account Was Not Saved Because Account Number Is Used" << endl;
			break;
		}

		}
	}
};

