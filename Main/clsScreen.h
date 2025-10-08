#pragma once



#include<iostream>
#include"clsGlobal.h"
#include"clsDate.h"

using namespace std;




class clsScreen
{
protected:

	

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {

        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\t User:" << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\t Date:"<<clsDate::DateToString(clsDate()) << endl;
        
    }

    static bool CheckAccessRights(clsUser::enPermissions Permissions)
    {
        if (!CurrentUser.CheckAccessPermission(Permissions))
        {
            cout << "Access Denied,\nYou dont Have Permission To Do This,\nPlease Conact Your Admin." << endl;
            return false;
        }
        else
            return true;
    }

};

