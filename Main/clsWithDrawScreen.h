#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"



using namespace std;





class clsWithDrawScreen:protected clsScreen
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

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\n\nPlease Enter Account Number:";

		cin >> AccountNumber;
		return AccountNumber;
	}

public:

	static	void ShowWithDrawScreen()
	{
		_DrawScreenHeader("\t  WithDraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClients::IsClientExist(AccountNumber))
		{
			cout << "\nClient With ["
				<< AccountNumber << "] Dose Not Exist.";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClients Client1 = clsBankClients::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease Enter WithDraw Amount ? ";
		Amount = clsInputValidate::ReadDblNumber();

		char Answer = 'n';
		cout << "\nAre You Sure You Want To Perform This Transactions ?";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client1.Withdraw(Amount))
			{
				cout << "\nAmount WithDraw Successfully\n";
				cout << "\nNew Balance Is :" << Client1.AccountBalance;
			}
			else
			{
				cout << "\nCannot WithDraw,Inffecient Balance!\n";
				cout << "\nAmount To WithDraw Is :" << Amount;
				cout << "\nYour Balance Is :" << Client1.AccountBalance;
			}
		}
		else
			cout << "\nOperation Was Cancelled\n";
	}
};

