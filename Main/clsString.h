#pragma once

#include<iostream>
#include<vector>


using namespace std;

class clsString
{
	
private:
	string _Value;


public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(put = SetValue, get = GetValue))string Value;

	static short Length(string S1)
	{
		return S1.length();
	}

	short Length()
	{
		return _Value.length();
	}

	static short CountWords(string S1)
	{
		string delimt = " ";
		short pos = 0;
		int Counter = 0;


		string sWord;

		while ((pos = S1.find(delimt)) != string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				Counter++;

			}
			S1.erase(0, pos + delimt.length());

		}
		if (S1 != "")
		{
			//it counts the last word of the string
			Counter++;
		}
		return Counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static void LetterWord(string S1)
	{
		bool isFirstLetter = true;

		cout << "\n First letters of this string: \n";

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				cout << S1[i] << endl;
			}
			//if The Condtion is Met He Will Delete The 
			//Character Until He Finds Space Then Print After Space  
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}

	}

	void LetterWord()
	{
		LetterWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string  S1)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}
			//if The Condtion is Met He Will Delete The 
			//Character Until He Finds Space Then Print After Space  
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}

	void UpperFirstLetterOfEachWord()
	{
		//No need to return value , this function will directly update the object value
		_Value = UpperFirstLetterOfEachWord(_Value);
	}


	static string LowerFirstLetterOfEachWord(string  S1)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}
			//if The Condtion is Met He Will Delete The 
			//Character Until He Finds Space Then Print After Space  
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}


	static string UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static char InvertLetterCase(char Char1)
	{
		return isupper(Char1) ? tolower(Char1) : toupper(Char1);
	}

	static 	string InvertAllLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);

		}
		return S1;
	}

	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		int Counter = 0;
		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		for (short i = 0; i < S1.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters
				&& isupper(S1[i]))
			{
				Counter++;
			}
			if (WhatToCount == enWhatToCount::SmallLetters
				&& islower(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}


	static short CountCapitalLetters(string S1)
	{

		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				Counter++;
		}
		return Counter;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string S1)
	{

		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))

				Counter++;
		}
		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{

		int Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Letter)

					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
				{
					Counter++;
				}
			}
		}
		return Counter;
	}

	short CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return	CountSpecificLetter(_Value, Letter, MatchCase);
	}

	
	static bool  IsVowel( char Ch1)
	{
		//We Change The Ch1 To Case Sensative Capital To Small
		Ch1 = tolower(Ch1);

		return  ((Ch1 == 'a') || (Ch1 == 'e')
			|| (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
	}


	static short CountVowels(string S1)
	{

		int Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))

				Counter++;
		}
		return Counter;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static vector <string>Split(string S1, string Delim)
	{
		vector<string>vString;


		short pos = 0;

		string sWord;

		while ((pos = S1.find(Delim)) != string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				vString.push_back(sWord);

			}
			S1.erase(0, pos + Delim.length());

		}
		//if (S1 != "")//
		{   //it adds last word of the string 
			vString.push_back(S1);
		}
		return vString;
	}

	vector <string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}


	static string TrimLeft(string S1)//
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				//In Substr Walk From First Letter Not Space
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}

	void TrimLeft()
	{
		_Value=TrimLeft(_Value);
	}

	static string TrimRight(string S1)//
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string S1)
	{
		return (TrimLeft(TrimRight(S1)));
	}

	void Trim()
	{
		_Value=Trim(_Value);
	}


	static string JoinString(vector<string>vString, string Delim)
	{
		string S1 = "";

		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}

	

	static string JoinString(string ArrString[], short Length, string Delim)
	{
		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + ArrString[i] + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}


	static string ReverseWordInString(string S1)
	{
		vector<string>vString;
		string S2 = "";

		vString = Split(S1, " ");

		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		//remove last space.
		S2 = S2.substr(0, S2.length() - 1);
		return S2;
	}

	void ReverseWordInString()
	{
		_Value= ReverseWordInString(_Value);
	}


	static string ReplaceWord
	(string S1, string StringToReplace, string sReplaceTo)
	{
		short pos = S1.find(StringToReplace);

		while (pos != string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
			pos = S1.find(StringToReplace);//find next
		}
		return S1;
	}

	string ReplaceWord(string StringToReplace, string sReplaceTo)
	{
		return ReplaceWord(_Value, StringToReplace, sReplaceTo);
	}



	static string RemovePauncuations(string S1)
	{
		string S2 = "";
		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			} 
		}
		return S2;
	}

	void RemovePauncuations()
	{
		_Value= RemovePauncuations(_Value);
	}

};

