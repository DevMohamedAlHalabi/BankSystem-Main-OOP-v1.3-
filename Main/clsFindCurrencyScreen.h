#pragma once

#include<iostream>
#include<iomanip>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"






class clsFindCurrencyScreen :protected clsScreen
{

private:

	static	void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:" << endl;
		cout << "_____________________________________" << endl;
		cout << "\nCountry     : " << Currency.Country();
		cout << "\nCode        : " << Currency.CurrencyCode();
		cout << "\nName        : " << Currency.CurrencyName();
		cout << "\nRate/(1$) = : " << Currency.Rate();
		cout << "\n_____________________________________" << endl;
	}

	static	void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found:-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was Not Found:-(\n";
		}
	}

public:
	static	void ShowFindCurrencyScreen()
	{

		_DrawScreenHeader("\t Find Currency Screen");
		

		cout  << "Find By: [1] Code Or [2] Country ? ";
		short Answer= 1;

		cin >> Answer;
		

		if (Answer== 1 )
		{
			string CurrencyCode;
			cout << "\nPlease Enter CurrencyCode : ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency	Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResult(Currency);
		}
		else
		{
			string Country;
			cout << "\nPlease Enter Country Name : ";
			Country = clsInputValidate::ReadString();
			clsCurrency	Currency = clsCurrency::FindByCountry(Country);
			_ShowResult(Currency);

		}

	}
};




