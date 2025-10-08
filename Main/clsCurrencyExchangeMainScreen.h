#pragma once

#include<iostream>
#include<string>
#include <vector>
#include <fstream>
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"



class clsCurrencyExchangeMainScreen:protected clsScreen
{
private:
	enum enCurrenciesMainMenueOptions
	{
		eListCurrencies=1,
		eFindCurrency=2,
		eUpdateCurrencyRate =3,
		eCurrencyCalculator=4,
		eMainMenue=5,
	};

	static void _ShowCurrenciesListScreen()
	{
		//cout << " List Currencies Will Be Here.... " << endl;
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "Find Currency Will Be Here.... " << endl;
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		//cout << " Update Rate Will Be Here.... " << endl;
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		cout << "Currency Calculator Will Be Here.... " << endl;
		
	}

	static	void _GoBackToCurrenciesMenue()
	{
		cout << setw(37) << left << "" << "\n\nPress any key to go back to Currencies Menue....\n";

		system("pause>0");
		ShowCurrenciesMenue(); 
	}

	static	short _ReadCurrenciesMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do?[1 to 5]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number Between 1 To 5 ?");
		return Choice;
	}

	static	void _PerfromCurrenciesMainMenueOptions
	(enCurrenciesMainMenueOptions CurrenciesMainMenueOptions)
	{
		switch (CurrenciesMainMenueOptions)
		{
		case enCurrenciesMainMenueOptions::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case enCurrenciesMainMenueOptions::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case enCurrenciesMainMenueOptions::eUpdateCurrencyRate:
		{
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case enCurrenciesMainMenueOptions::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case enCurrenciesMainMenueOptions::eMainMenue:
		{
			
		} 
		}
	}


public:

	static void ShowCurrenciesMenue()
	{
		system("cls");
		_DrawScreenHeader("Currency Exchange Main Screen");



		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "    Currency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerfromCurrenciesMainMenueOptions
		((enCurrenciesMainMenueOptions)_ReadCurrenciesMainMenueOption());

	}





};

