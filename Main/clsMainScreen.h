#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include"clsFindClinetScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginScreen.h"
#include "clsGlobal.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyExchangeMainScreen.h"





using namespace std;



class clsMainScreen:protected clsScreen
{

private:

	enum enMainMenueOptions
	{
		eListClients = 1,
		eAddNewClient = 2,
		eDeleteClient = 3,
		eUpdateClientInfo = 4,
		eFindClient = 5,
		eShowTransactionsMenue = 6,
		eManageUsers=7,
		eLoginRegister=8,
		eCurrencyExchange=9,
		eExit = 10
	};

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen()
	{
		//cout << " Add New Clients Will Be Here.... " << endl;
		clsAddNewClientScreen::AddNewClient();
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << " Delete Client Will Be Here....  " << endl;
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen()
	{
		//cout << " Update Client Will Be Here.... " << endl;
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen()
	{
		//cout << "Find Client Will Be Here.... " << endl;
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsMenue()
	{
		//cout << " Transactions Will Be Here.... " << endl;
		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowManageUsersMenue()
	{
		//cout << "Manage Users Will Be Here.... " << endl;
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	/*static void _ShowEndScreen()
	{
		cout << "End Screen Will Be Here...." << endl;
	}*/

	static void _ShowLoginRegisterScreen()
	{
		//cout << "Login Register Will Be Here.... " << endl;
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeMainScreen()
	{
		//cout << "Currency Exchange Will Be Here.... " << endl;
		clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
	}



	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
	}

	static	void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\nPress any key to go back to Main Menue....\n";
		
		system("pause>0");
		ShowMainMenue();
	}

	static	short _ReadMainMenueOption()
	{
		cout << setw(37) << left<<"" << "Choose what do you want to do?[1 to 10]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number Between 1 To 10 ?");
		return Choice;
	}

	static	void _PerfromMainMenueOption
	(enMainMenueOptions MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOptions::eListClients:
		{
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eAddNewClient:
		{
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eDeleteClient:
		{
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eUpdateClientInfo:
		{
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eFindClient:
		{
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eShowTransactionsMenue:
		{
			system("cls");
			_ShowTransactionsMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eManageUsers:
		{
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eLoginRegister:
		{
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eCurrencyExchange:
		{
			system("cls");
			_ShowCurrencyExchangeMainScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eExit:
		{
			system("cls");
			_Logout();
			break;
		}
		}
	}


public:

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromMainMenueOption
		((enMainMenueOptions)_ReadMainMenueOption());

	}



};

