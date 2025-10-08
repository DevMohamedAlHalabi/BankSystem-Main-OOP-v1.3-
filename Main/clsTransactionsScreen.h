#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"

using namespace std;

 




class clsTransactionsScreen:protected clsScreen
{


private:

	enum enTransactionsMenueOptions
	{
		eDeposit = 1,
		eWithdraw = 2,
		eShowTotalBalances = 3,
		eTransfer=4,
		eTransferLog=5,
		eShowMainMenue = 6
	};

	static void _ShowDepositScreen()
	{
		//cout << " Deposit Will Be Here.... " << endl;
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithDrawScreen()
	{
		//cout << " With Draw Screen Will Be Here.... " << endl;
		clsWithDrawScreen::ShowWithDrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		//cout << " Total Balances Screen Will Be Here....  " << endl;
		clsTotalBalancesScreen::ShowTotalBalances();
	}

	static void _ShowTransferScreen()
	{
		//cout << " Transfer Screen Will Be Here....  " << endl;
		clsTransferScreen::ShowTransferScreen();	
	}

	static void _ShowTransferLogScreen()
	{
		//cout << " Transfer Log Screen Will Be Here....  " << endl;
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static	void _GoBackToTransactionMenue()
	{
		cout << setw(37) << left << "" << "\n\nPress any key to go back to Transactions Menue....\n";
		system("pause>0");
		ShowTransactionsMenue();
	}

	static	short _ReadTransactionalMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do?[1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 To 6 ?");
		return Choice;
	}

	static	void _PerfromTransactionsMenueOption
	(enTransactionsMenueOptions TransactionsMenueOptions)
	{
		switch (TransactionsMenueOptions)
		{
		case enTransactionsMenueOptions::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionsMenueOptions::eWithdraw:
		{
			system("cls");
			_ShowWithDrawScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionsMenueOptions::eShowTotalBalances:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionsMenueOptions::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionMenue();
			break;
		}
		case enTransactionsMenueOptions::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionMenue();
			break;
		}

		case enTransactionsMenueOptions::eShowMainMenue:
		{
			////// do nothing here the main screen will be handle it:-)
		}

		}
	}

	  
public:

	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{

			return;
		}
		system("cls");
		_DrawScreenHeader("\tTransactions Screen");

	

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tTransactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "[1] Deposit.\n";
		cout << setw(37) << left << "" << "[2] Withdraw.\n";
		cout << setw(37) << left << "" << "[3] Total Balances.\n";
		cout << setw(37) << left << "" << "[4] Transfer.\n";
		cout << setw(37) << left << "" << "[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";



		_PerfromTransactionsMenueOption
		((enTransactionsMenueOptions)_ReadTransactionalMenueOption());
	}
};

