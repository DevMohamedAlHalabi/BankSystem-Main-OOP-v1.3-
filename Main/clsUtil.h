#pragma once

#include <iostream>
#include <string>
#include "clsDate.h"


using namespace std;

class clsUtil
{
public:

	enum enCharType
	{
		SmallLetter = 1, CapitalLetter = 2,Digit = 3,
		MixChars=4,SpicalCharacter = 5 
	};

	static void Srand()
	{
		//Seeds the random number generator in C++, called only once
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		//Function to generate a random number
		int RandNumber = rand() % (To - From + 1) + From;
		return RandNumber;
	}


	static char GetRandomCharacter(enCharType CharType)
	{
		//Update This Method To Accept Mixchars
		if (CharType==MixChars)
		{
			//Capital/Samll/Digits Only
			CharType = (enCharType)RandomNumber(1, 3);
		}

		switch (CharType)
		{
		case enCharType::SmallLetter:
			return char(RandomNumber(97, 122));
			break;
		case enCharType::CapitalLetter:
			return char(RandomNumber(65, 90));
			break;
		case enCharType::Digit:
			return char(RandomNumber(48, 57));
			break;
		case enCharType::MixChars:
			return char(RandomNumber(48, 122));
			break;
		case enCharType::SpicalCharacter:
			return char(RandomNumber(33, 47));
			break;



		default:
			return char(RandomNumber(65, 90));
			break;
		}
	}

	static 	 string GenerateWord(enCharType CharType, short Length)
	{
		string Word = "";
		for (int i = 1; i <= Length; i++)
		{
			Word = Word + GetRandomCharacter(CharType);
		}
		return Word;
	}

static	string GenerateKey(enCharType CharType)
	{
	string Key = "";

		Key = GenerateWord(CharType, 4) + "_";
		Key = Key + GenerateWord(CharType, 4) + "_";
		Key = Key + GenerateWord(CharType, 4) + "_";
		Key = Key + GenerateWord(CharType, 4);

		return Key;
	}

static	void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] ";
			cout << GenerateKey( CharType) << endl;
		}
	}


	static	 void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
	{

		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = RandomNumber(1, 100);
		}
	}

	static	 void FillArrayWithRandomWords(string Arr[100], int ArrLength, enCharType CharType, int WordLength)
	{
		for (int i = 0; i < ArrLength; i++)
		{
			Arr[i] = GenerateWord(CharType,WordLength);
		}
	}

	static	 void FillArrayWithRandomKeys(string Arr[100], int ArrLength, enCharType CharType)
	{
		for (int i = 0; i < ArrLength; i++)
		{
			Arr[i] = GenerateKey(CharType);
		}
	}
		
	static	 void Swap(int& A, int& B)
	{
		int Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static	 void Swap(double& A, double& B)
	{
		double Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static	 void Swap(bool& A, bool& B)
	{
		bool Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static	 void Swap(char& A, char& B)
	{
		char Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static	 void Swap(string& A, string& B)
	{
		string Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static	 void Swap(clsDate& A, clsDate& B)
	{
		clsDate::SwapDates(A, B);
	}

	static	 void ShuffleArray(int Arr[100], int ArrLength)
	{
		for (int i = 0; i < ArrLength; i++)
		{
			Swap(Arr[RandomNumber(1, ArrLength) - 1],
				Arr[RandomNumber(1, ArrLength) - 1]);
		}
	}

	static	 void ShuffleArray(string Arr[100], int ArrLength)
	{
		for (int i = 0; i < ArrLength; i++)
		{
			Swap(Arr[RandomNumber(1, ArrLength) - 1],
				Arr[RandomNumber(1, ArrLength) - 1]);
		}
	}

	static	string Tabs(short NumberOfTabs)
	{
		string t = "";
		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + '\t';
			cout << t;
		}
		return t;
	}

	static	string EncryptText(string Text, short EncryptionKey=2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text;
	}

	static	string DecryptText(string Text, short EncryptionKey=2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

	static	string NumberToText(int Number)
	{
		if (Number == 0)
		{
			return "";
		}
		if (Number >= 1 && Number <= 19)
		{
			string arr[] =
			{ "", "One","Two","Three",
			"Four","Five","Six","Seven",
			"Eight","Nine","Ten","Eleven",
			"Twelve","Thirteen","Fourteen",
			"Fifteen","Sixteen","Seventeen",
			"Eighteen","Nineteen" };

			return arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty",
				"Forty","Fifty","Sixty","Seventy",
				"Eighty","Ninety" };
			return arr[Number / 10] + " "
				+ NumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + NumberToText(Number % 100);
		}
		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "Hundreds " +
				NumberToText(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToText(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "Thousand " +
				NumberToText(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumberToText(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + "Millions " +
				NumberToText(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return NumberToText(Number / 1000000000) + "Billions " +
				NumberToText(Number % 1000000000);
		}
	}
	
};

