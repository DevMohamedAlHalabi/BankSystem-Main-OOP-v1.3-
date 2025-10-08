#pragma once

#pragma warning(disable : 4996)

#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
#include<ctime>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<vector>
#include"clsString.h"
#include"clsDate.h"	


using namespace std;




class clsPeriod
{

public:

	clsDate StartDate;
	clsDate EndDate;

	clsPeriod(clsDate StartDate,clsDate EndDate)
	{
		this->StartDate = StartDate;
		this->EndDate = EndDate;
	}


	static	bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
	{
		if (    //Period2 is small And Period1 Is Grater
			clsDate::CompareDates(Period2.EndDate, Period1.StartDate)
			== clsDate::enDateCompare::Before
			|| //Period2 Is Grater Than Period1
			clsDate::CompareDates(Period2.StartDate, Period1.EndDate)
			== clsDate::enDateCompare::After
			)
			// After Is Mean Period2 Grater Than Period1 Attention
			//As Long As It Is Period2 Outside Period1 
			// This Mean Don't Intersect Her Answer Is false 
			return false;
		else
			return true;
	}

	bool IsOverlapPeriods(clsPeriod Period2)
	{
		return IsOverlapPeriods(*this, Period2);
	}

	static	int PeriodLengthInDays(clsPeriod Period, bool IncludeEndDate = false)
	{
		return clsDate:: GetDifferenceInDays
		(Period.StartDate, Period.EndDate, IncludeEndDate);
	}

	int PeriodLengthInDays(bool IncludeEndDate = false)
	{
		return PeriodLengthInDays(*this);
	}

	static	bool isDateInPeriod(clsDate Date, clsPeriod Period)
	{
		return   //Small
			!(clsDate:: CompareDates(Date, Period.StartDate)
				== clsDate::enDateCompare::Before
				||     //Large
				clsDate::CompareDates(Date, Period.EndDate)
				== clsDate::enDateCompare::After
				);

	}

	//bool isDateInPeriod(clsPeriod Period)//
	//{
	//	return isDateInPeriod(*this,Period);//
	//}


	static	int CountOverlapDays(clsPeriod Period1, clsPeriod Period2)
	{
		int CountDays = 0;

		if (!IsOverlapPeriods(Period1, Period2))
			return CountDays;

		while (!clsDate::IsDate1EqualDate2(Period2.StartDate, Period1.EndDate))
		{
			Period2.StartDate = clsDate::AddOneDay(Period2.StartDate);
			CountDays++;
		}
		return CountDays;
	}

	int CountOverlapDays(clsPeriod Period2)
	{
		return CountOverlapDays(*this, Period2);
	}


	void Print()
	{
		cout << "Period Start: ";
		StartDate.Print();

		cout << "Period End: ";
		EndDate.Print();
	}

};

