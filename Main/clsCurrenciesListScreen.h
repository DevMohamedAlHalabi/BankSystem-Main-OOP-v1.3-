#pragma once

#include<iostream>
#include<iomanip>
#include"clsCurrency.h"
#include"clsScreen.h"




class clsCurrenciesListScreen:protected clsScreen
{

private:
    static	void _PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(33) << left << Currency.CurrencyCode();
        cout << "| " << setw(20) << left << Currency.CurrencyName();
        cout << "| " << setw(5) << left << Currency.Rate();
    }

public:
    static	void ShowCurrenciesListScreen()
    {
        vector <clsCurrency> vCurrency = clsCurrency::GetCurrencyList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(33) << "Code";
        cout << "| " << left << setw(20) << "Name";
        cout << "| " << left << setw(5) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________\n" << endl;

        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency Currency : vCurrency)
            {

                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }




};

