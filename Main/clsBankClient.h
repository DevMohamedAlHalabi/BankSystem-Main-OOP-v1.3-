#pragma once



#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include"clsDate.h"



using namespace std;






class clsBankClients :public clsPerson
{
private:
	enum  enMode{EmptyMode=0,UpdateMode=1,AddNewMode=2};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkForDelete = false;


	static clsBankClients _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string>vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClients(enMode::UpdateMode,
			vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4],
			vClientData[5], stod(vClientData[6]));
	}

	static clsBankClients _GetEmptyClientObject()
	{
		return clsBankClients
		(enMode::EmptyMode, "", "", "", "", "", "",0);
	}

	static string _ConverClientObjectToLine(clsBankClients Client, string Seperator = "#//#")
	{
		string sClientRecord = "";

		sClientRecord += Client.FirstName + Seperator;
		sClientRecord += Client.LastName + Seperator;
		sClientRecord += Client.Email + Seperator;
		sClientRecord += Client.Phone + Seperator;
		sClientRecord += Client.AccountNumber() + Seperator;
		sClientRecord += Client.PinCode + Seperator;
		sClientRecord += to_string(Client._AccountBalance);

		return sClientRecord;
	}

	static void	_SaveClientDataToFile(vector<clsBankClients>vClients)
	{
		string DataLine;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite
		if (MyFile.is_open())
		{
			for (clsBankClients& C : vClients)
			{	
				if(C.MarkedForDeleted()==false)
				{
					//we only write records that are not marked for delete.
					DataLine = _ConverClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	static	vector<clsBankClients> _LoadClientDataFromFile()
	{
		vector<clsBankClients>vClient;
		fstream MyFile;
		string Line;

		MyFile.open("Clients.txt", ios::in);//read Mode  
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
		clsBankClients	Client = _ConvertLineToClientObject(Line);
				vClient.push_back(Client);
			}
			MyFile.close();
		}
		return vClient;
	}
	
	void _Update()
	{
		vector<clsBankClients>vClients
			= _LoadClientDataFromFile();

		for (clsBankClients& C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(vClients);
	}
	 
	void _AddNew()
	{
		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string sDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << sDataLine << endl;
			MyFile.close();
		}
	}

	 string _PrepareTransferLogRecord	
	 (float Amount, clsBankClients& DestinationClient, string UserName,string  Seperator = "#//#")
	{

		string TransferLogRecord = "";

		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += AccountNumber() + Seperator;
		TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
		TransferLogRecord += to_string(Amount)+Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		TransferLogRecord += UserName;
	
		return TransferLogRecord;
	}

	void _RegisterTransferLog(float Amount, clsBankClients DestinationClient, string UserName)
	{
		string sDataLine = _PrepareTransferLogRecord
		(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << sDataLine << endl;
			MyFile.close();
		}
	}


public:

	struct stTransferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float SrcBalanceAfter;
		float DestBalanceAfter;
		string UserName;
	};

	clsBankClients(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDeleted()
	{
		return _MarkForDelete;
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	void SetAccountBalace(float AccountBalace)
	{
		_AccountBalance = AccountBalace;
	}

	float GetAccoutBalace()
	{
		return _AccountBalance;
	}

	__declspec(property(get= GetPinCode, put = SetPinCode))string PinCode;
	__declspec(property(get= GetAccoutBalace, put = SetAccountBalace))float AccountBalance;

	static	clsBankClients Find(string AccountNumber)
	{
		vector<clsBankClients>vClient;
		fstream MyFile;
		string Line;

		MyFile.open("Clients.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
			clsBankClients	Client =
				_ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClient.push_back(Client);
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static	clsBankClients Find(string AccountNumber,string PinCode)
	{
		vector<clsBankClients>vClient;
		fstream MyFile;
		string Line;

		MyFile.open("Clients.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
			clsBankClients	Client =
				_ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber&&Client.GetPinCode()==PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClient.push_back(Client);
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClients Clint1 = Find(AccountNumber);
		return (!Clint1.IsEmpty());
	}

	static clsBankClients GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClients
		(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0 );
	}

	enum enSaveResult{svFaildEmpty=0,svSuccesseded=1,svFaildAccountNumber=2};

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
			if (clsBankClients::IsClientExist(_AccountNumber))
			{
				return enSaveResult::svFaildAccountNumber;
			}
			else
			{
				_AddNew();

				//We Need To Set The Mode To Update After Add New
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSuccesseded;//svFaildEmpty
			}
		}
	}

	bool Delete()
	{
		vector<clsBankClients>vClients;

		vClients = _LoadClientDataFromFile();

		for (clsBankClients& C : vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C._MarkForDelete = true;
				break;
			}
		}
				_SaveClientDataToFile(vClients);

				*this = _GetEmptyClientObject();
		return true;
	}

	static vector<clsBankClients>GetClientList()
	{
		return _LoadClientDataFromFile();
	}

	static double GetTotalBalance()
	{
		vector<clsBankClients>vClients 
			= clsBankClients::GetClientList();

		double TotalBalance = 0;

		for (clsBankClients &Client : vClients)
		{
			
			TotalBalance += Client.AccountBalance;
			
		}
		return TotalBalance;
	}

	void Deposit(double Amount) 
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount>_AccountBalance)
		{
			return false;
		}
		else
		{
		_AccountBalance -= Amount;
		Save();
		}
	} 

	bool Transfer(float Amount, clsBankClients& DestinationClient,string UserName)
	{
		if (Amount>AccountBalance)
		{
			return false;
		}
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, UserName);
		return true;
	}


	static stTransferLogRecord _ConvertTransferLogLineToRecord( string Line, string Seperator = "#//#")
	{
		stTransferLogRecord TransferLogRecord;

		vector<string>vTransferLogRecord;
		vTransferLogRecord = clsString::Split(Line, Seperator);

		TransferLogRecord.DateTime = vTransferLogRecord[0];
		TransferLogRecord.SourceAccountNumber = vTransferLogRecord[1];
		TransferLogRecord.DestinationAccountNumber = vTransferLogRecord[2];
		TransferLogRecord.Amount = stod(vTransferLogRecord[3]);
		TransferLogRecord.SrcBalanceAfter = stod(vTransferLogRecord[4]);
		TransferLogRecord.DestBalanceAfter = stod(vTransferLogRecord[5]);
		TransferLogRecord.UserName = vTransferLogRecord[6];
		
		return TransferLogRecord;
	}
	 
	static	vector<stTransferLogRecord> GetTransferLogList()
	{
		vector<stTransferLogRecord>vTransferLogRecord;
		fstream MyFile;
		string Line;

		MyFile.open("TransferLog.txt", ios::in);//read Mode  
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				stTransferLogRecord	TransferRecord = 
				_ConvertTransferLogLineToRecord(Line);

				vTransferLogRecord.push_back(TransferRecord);
			}
			MyFile.close();
		}
		return vTransferLogRecord;
	}

};