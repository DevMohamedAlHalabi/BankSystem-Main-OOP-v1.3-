#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"



using namespace std;








class clsDepositScreen:protected clsScreen
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

	static	void ShowDepositScreen()
	{
		_DrawScreenHeader("\t  Deposit Screen");

		string AccountNumber = "";

		AccountNumber = _ReadAccountNumber();

		while (!clsBankClients::IsClientExist(AccountNumber))
		{
			cout << "\nClient With ["
				<< AccountNumber << "] Dose Not Exist.";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClients Client1 = clsBankClients::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease Enter Deposit Amount ? ";
		Amount = clsInputValidate::ReadDblNumber();

		char Answer = 'n';
		cout << "\nAre You Sure You Want To Perform This Transactions ?";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Client1.Deposit(Amount);
			cout << "\nAmount Deposited Successfully\n";
			cout << "\nNew Balance Is :" << Client1.AccountBalance;
		}
		else
			cout << "\nOperation Was Cancelled\n";
	}




};

