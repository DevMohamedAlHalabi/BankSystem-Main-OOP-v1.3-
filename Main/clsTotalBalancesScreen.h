#pragma once

#pragma warning(disable : 4996)

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"

using namespace std;




class clsTotalBalancesScreen:protected clsScreen
{


private:
    static	void _PrintClientRecordBalancesLine(clsBankClients Client)
    {

        cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(40) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }




public:
    static	void ShowTotalBalances()
    {
        vector <clsBankClients> vClients = clsBankClients::GetClientList();
        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(25) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        double TotalBalances = clsBankClients::GetTotalBalance();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClients Client : vClients)
            {

                _PrintClientRecordBalancesLine(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t\t\t\t\t\t\t     (" << clsUtil::NumberToText(TotalBalances) << ")";
    }
};

