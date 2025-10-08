#pragma once

#include<iostream>
#include<iomanip>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"







class clsUpdateCurrencyRateScreen :protected clsScreen
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

	static	float _ReadRate()
	{
		float NewRate;
		cout << "\nEnter New Rate: ";
		

		NewRate = clsInputValidate::ReadFloatNumber();
		return 	NewRate;
	}

public:
	static	void ShowUpdateCurrencyRateScreen()
	{

		_DrawScreenHeader("\t Update Currency Screen");

		string CurrencyCode="";

		cout << "\nPlease Enter CurrencyCode : ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Is Not Found, Choose Another One:";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency	Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);

		cout << "\nAre You Sure You Want To Update The Rate Of This Currency Y/N? ";
		
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\nUpdate Currency Rate:" << endl;
			cout << "\n_______________________" << endl;

			Currency.UpdateRate(_ReadRate());
			cout << "\nCurrency Rate Updated Successfully :-)\n";
			_PrintCurrency(Currency);
		}
	}
};

