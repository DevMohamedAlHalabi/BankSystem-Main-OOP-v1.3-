#pragma once

#include<iostream>
#include<string>
#include <vector>
#include <fstream>
#include "clsString.h"







class clsCurrency
{
private:
	enum enMode{EmptyMode=0,UpdateMode=1};
	enMode _Mode;

	string _Country;
	string _CurrencyName;
	string _CurrencyCode;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string>vCurrencyData;
		vCurrencyData = clsString::Split(Line, Seperator);

		return clsCurrency(enMode::UpdateMode,
			vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
			 stod(vCurrencyData[3]));
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode,"", "", "", 0);
	}

	static string _ConverCurrencyObjectToLine(clsCurrency  Currency, string Seperator = "#//#")
	{
		string sCurrencyRecord = "";

		sCurrencyRecord += Currency.Country() + Seperator;
		sCurrencyRecord += Currency.CurrencyName() + Seperator;
		sCurrencyRecord += Currency.CurrencyCode() + Seperator;
		sCurrencyRecord += to_string(Currency.Rate());
		

		return sCurrencyRecord;
	}

	static	vector<clsCurrency> _LoadCurrencyDataFromFile()
	{
		vector<clsCurrency>vCurrency;
		fstream MyFile;
		string Line;

		MyFile.open("Currencies.txt", ios::in);//read Mode  
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsCurrency	Currency = _ConvertLineToCurrencyObject(Line);
				vCurrency.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrency;
	}

	static void	_SaveCurrencyDataToFile(vector<clsCurrency>vCurrency)
	{
		string DataLine;
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);//overwrite
		if (MyFile.is_open())
		{
			for (clsCurrency& C : vCurrency)
			{
				
				
					//we only write records that are not marked for delete.
					DataLine = _ConverCurrencyObjectToLine(C);
					MyFile << DataLine << endl;
				
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector<clsCurrency>vCurrency
			= _LoadCurrencyDataFromFile();

		for (clsCurrency& C : vCurrency)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrency);
	}


public:

	clsCurrency(enMode Mode,string Country,string CurrencyCode,string CurrencyName,float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;

	}

	string Country()
	{
		return	_Country;
	}

	string CurrencyCode()
	{
		return	_CurrencyCode;
	}

	string CurrencyName()
	{
		return	_CurrencyName;
	}

	void  UpdateRate(float NewRate)
	{
		_Rate= NewRate;
		_Update(); 
	}

	float Rate()
	{
		return _Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static vector<clsCurrency>GetAllUSDRates()
	{
		return _LoadCurrencyDataFromFile();
	}

	static	clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);


		fstream MyFile;
		string Line;

		MyFile.open("Currencies.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsCurrency	Currency =
					_ConvertLineToCurrencyObject(Line);

				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static	clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);


		fstream MyFile;
		string Line;

		MyFile.open("Currencies.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsCurrency	Currency =
					_ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());//clsCurrency::
	}


	static vector<clsCurrency>GetCurrencyList()
	{
		return _LoadCurrencyDataFromFile();
	}





};