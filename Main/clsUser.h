#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include"clsDate.h"
#include <vector>
#include <fstream>
#include"clsBankClient.h"
#include"clsUtil.h"


using namespace std;


class clsUser:public clsPerson
{


	private:
		enum  enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
		enMode _Mode;

		string _UserName;
		string _Password;
		float _Permissions;
		bool _MarkForDelete = false;


		static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
		{
			vector<string>vUserData;
			vUserData = clsString::Split(Line, Seperator);

			return clsUser(enMode::UpdateMode,
				vUserData[0],
				vUserData[1], 
				vUserData[2],
				vUserData[3], 
				vUserData[4],
			clsUtil::DecryptText(vUserData[5]), 
				stoi(vUserData[6]));
		}

		static clsUser _GetEmptyUserObject()
		{
			return clsUser
			(enMode::EmptyMode, "", "", "", "", "", "", 0);
		}

		static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
		{
			string sUserRecord = "";

			sUserRecord += User.FirstName + Seperator;
			sUserRecord += User.LastName + Seperator;
			sUserRecord += User.Email + Seperator;
			sUserRecord += User.Phone + Seperator;
			sUserRecord += User.UserName + Seperator;
			//Here We Encypt Store The Encrypted Password Not The Real One.
			sUserRecord +=clsUtil::EncryptText( User.Password) + Seperator;
			sUserRecord += to_string(User.Permissions);

			return sUserRecord;
		}

		static void	_SaveUserDataToFile(vector<clsUser>vUser)
		{
			string DataLine;
			fstream MyFile;//
			MyFile.open("Users.txt", ios::out);//overwrite
			if (MyFile.is_open())
			{
				for (clsUser& U : vUser)
				{
					if (U.MarkedForDeleted() == false)
					{
						//we only write records that are not marked for delete.
						DataLine = _ConverUserObjectToLine(U);
						MyFile << DataLine << endl;
					}
				}
				MyFile.close();
			}
		}

		static	vector<clsUser> _LoadUserDataFromFile()
		{
			vector<clsUser>vUser;
			fstream MyFile;
			string Line;

			MyFile.open("Users.txt", ios::in);//read mode
			if (MyFile.is_open())
			{
				while (getline(MyFile, Line))
				{
					clsUser	User = _ConvertLineToUserObject(Line);
					vUser.push_back(User);
				}
				MyFile.close();
			}
			return vUser;
		}

		void _Update()
		{
			vector<clsUser>vUser
				= _LoadUserDataFromFile();

			for (clsUser& U : vUser)
			{
				if (U.UserName == _UserName)
				{
					U = *this;
					break;
				}
			}
			_SaveUserDataToFile(vUser);
		}

		void _AddNew()
		{
			_AddDataLineToFile(_ConverUserObjectToLine(*this));
		}

		void _AddDataLineToFile(string sDataLine)
		{
			fstream MyFile;
			MyFile.open("Users.txt", ios::out | ios::app);

			if (MyFile.is_open())
			{
				MyFile << sDataLine << endl;
				MyFile.close();
			}
		}

		 string _PrepareLogInRecord(string Seperator = "#//#")
		{
			string LoginRecord = "";

			LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
			LoginRecord += UserName + Seperator;
			//Here We Encypt Store The Encrypted Password Not The Real One.
			LoginRecord +=clsUtil::EncryptText(Password) + Seperator;

			LoginRecord += to_string(Permissions);

			return LoginRecord;
		}

		 struct stLoginRegisterRecord;
		 static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
		 {
			 stLoginRegisterRecord  LoginRegisterRecord;

			 vector<string>LoginRegisterDataLine= clsString::Split(Line, Seperator);
			 LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
			 LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
			 LoginRegisterRecord.Password = clsUtil::DecryptText( LoginRegisterDataLine[2]);
			 LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);
 
			 return LoginRegisterRecord;
		 }



	public:

		struct stLoginRegisterRecord
		{
			string DateTime;
			string UserName;
			string Password;
			int Permissions;
		};

		enum enPermissions
		{
			eAll = -1,
			pListClients = 1,
			pAddNewClient = 2,
			pDeleteClient = 4,
			pUpdateClients = 8,
			pFindClient = 16,
			pTranactions = 32,
			pManageUsers = 64,
			pShowLoginRegister =128
		};


		clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, int Permissions)
			:clsPerson(FirstName, LastName, Email, Phone)
		{
			_Mode = Mode;
			_UserName = UserName;
			_Password = Password;
			_Permissions = Permissions;
		}

		bool IsEmpty()
		{
			return (_Mode == enMode::EmptyMode);
		}

		bool MarkedForDeleted()
		{
			return _MarkForDelete;
		}

		void SetUserName(string UserName)
		{
			_UserName = UserName;
		}

		string GetUserName()
		{
			return _UserName;
		}

		void SetPassword(string Password)
		{
			_Password = Password;
		}

		string GetPassword()
		{
			return _Password;
		}	

		void SetPermissions(int Permissions)
		{
			_Permissions = Permissions;
		}

		int GetPermissions()
		{
			return _Permissions;
		}

		__declspec(property(get = GetUserName, put = SetUserName))string UserName;
		__declspec(property(get = GetPassword, put = SetPassword))string Password;
		__declspec(property(get = GetPermissions, put = SetPermissions))int Permissions;

		static	clsUser Find(string UserName)
		{
			//vector<clsBankClients>vClient;
			fstream MyFile;
			string Line;

			MyFile.open("Users.txt", ios::in);//read Mode
			if (MyFile.is_open())
			{
				while (getline(MyFile, Line))
				{
					clsUser	User =
						_ConvertLineToUserObject(Line);
					if (User.UserName == UserName)
					{
						MyFile.close();
						return User;
					}
					//vClient.push_back(Client);
				}
				MyFile.close();
			}

			return _GetEmptyUserObject();
		}

		static	clsUser Find(string UserName, string Password)
		{
			//vector<clsBankClients>vClient;
			fstream MyFile;
			string Line;

			MyFile.open("Users.txt", ios::in);//read Mode
			if (MyFile.is_open())
			{
				while (getline(MyFile, Line))
				{
					clsUser	User =
						_ConvertLineToUserObject(Line);
					if (User.UserName == UserName && User.Password == Password)
					{
						MyFile.close();
						return User;
					}
					//vClient.push_back(Client);
				}
				MyFile.close();
			}

			return _GetEmptyUserObject();
		}

		static bool IsUserExist(string UserName)
		{
			clsUser User = Find(UserName);
			return (!User.IsEmpty());
		}

		static clsUser GetAddNewUserObject(string UserName)
		{
			return clsUser
			(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
		}

		enum enSaveResult { svFaildEmpty = 0, svSuccesseded = 1, svFaildUserExists = 2 };

		enSaveResult Save()
		{
			switch (_Mode)
			{
			case enMode::EmptyMode:
				if (IsEmpty())
				{
					return enSaveResult::svFaildEmpty;
				}


			case enMode::UpdateMode:
				_Update();
				return enSaveResult::svSuccesseded;


			case enMode::AddNewMode:

				//This Will Add New Record To File Or Database
				if (clsUser::IsUserExist(_UserName))
				{
					return enSaveResult::svFaildUserExists;
				}
				else
				{
					_AddNew();

					//We Need To Set The Mode To Update After Add New
					_Mode = enMode::UpdateMode;
					return enSaveResult::svSuccesseded;
				}
			}
		}

		bool Delete()
		{
			vector<clsUser>vUser;

			vUser = _LoadUserDataFromFile();

			for (clsUser& U : vUser)
			{
				if (U.UserName == _UserName)
				{
					U._MarkForDelete = true;
					break;
				}
			}
			_SaveUserDataToFile(vUser);

			*this = _GetEmptyUserObject();
			return true;
		}

		static vector<clsUser>GetUsersList()
		{
			return _LoadUserDataFromFile();
		}

		bool CheckAccessPermission(enPermissions Permission)
		{
			//Permissions Start From pListClients=1..2..4..8..16 
			//Here If Equal -1 This Give Permission For All System
			if (this->Permissions == enPermissions::eAll)
				return true;

			//The Bitwise Compare Between Tow Number And The 
			//Result Sum Of CurrentUser.Permissions For Example
			//1&49 This Mean Result = 1             For Permission
			if ((Permission & this->Permissions) == Permission)
				return true;
			else 
				return false;
		}

		void RegisterLogIn()
		{
			;
			string sDataLine = _PrepareLogInRecord();
			fstream MyFile;
			MyFile.open("LoginRegister.txt", ios::out | ios::app);

			if (MyFile.is_open())
			{
				MyFile << sDataLine << endl;
				MyFile.close();
			}
		}
		
		static	vector<stLoginRegisterRecord> GetLoginRegisterList()
		{
			vector<stLoginRegisterRecord>vLoginRegisterRecord;
			fstream MyFile;

			MyFile.open("LoginRegister.txt", ios::in);//read Mode
			if (MyFile.is_open())
			{
				string Line;
				stLoginRegisterRecord LoginRegisterRecord;

				while (getline(MyFile, Line))
				{
					 LoginRegisterRecord =_ConvertLoginRegisterLineToRecord(Line);
					vLoginRegisterRecord.push_back(LoginRegisterRecord);
				}

				MyFile.close();
			}
			return vLoginRegisterRecord;
		}

		

};

