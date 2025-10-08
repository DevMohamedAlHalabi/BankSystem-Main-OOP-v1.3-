#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsBankClient.h"

using namespace std;




class clsTransferScreen :protected clsScreen
{



private:
	static	void _PrintClient(clsBankClients Client)
	{
		cout << "\nClient Card    :" << endl;
		cout << "_____________________________________" << endl;
		cout << "Full Name      :" << Client.FullName() << endl;
		cout << "Account Number :" << Client.AccountNumber() << endl;
		cout << "Account Balance:" << Client.AccountBalance << endl;
		cout << "_____________________________________" << endl;
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\n\nPlease Enter Account Number To Transfer From :";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClients::IsClientExist(AccountNumber))
		{
			cout << "Account Number Is Not Found choose Another One" << endl;
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static float _ReadAmount(clsBankClients SourceClient)
	{
		double Amount = 0;
		cout << "\nEnter Transfer Amount ? ";
		Amount = clsInputValidate::ReadFloatNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds The Available Balance, Enter Another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();

		}
		return Amount;
	}

public:

	static	void ShowTransferScreen()
	{
		

		_DrawScreenHeader("\t  Transfer Screen");

		string AccountNumber = "";

		clsBankClients SourceClient = clsBankClients::Find(_ReadAccountNumber());
		_PrintClient(SourceClient);

		clsBankClients DestinationClient = clsBankClients::Find(_ReadAccountNumber());
		_PrintClient(DestinationClient);

		float Amount = _ReadAmount(SourceClient);

		char Answer = 'n';
		cout << "\nAre You Sure You Want To Perform This Operation? Y/N? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount,DestinationClient,CurrentUser.UserName))
			{
			cout << "\nTransfer Done Successfully" << endl;
			}
			else
			{
				cout << "\nTransfer Faild\n";
			}
		}
			_PrintClient(SourceClient);
			_PrintClient(DestinationClient);
		

	}

	
};


