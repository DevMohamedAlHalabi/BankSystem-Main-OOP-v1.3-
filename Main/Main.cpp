#pragma once

#include <iostream>

//This Library Include All Others Library Because Story Them
//#include"clsCurrency.h"
#include"clsLoginScreen.h"


int main()
{
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{

			break;
		}
	}
}









































//static void _PrintCurrency(clsCurrency Currency)
//{
//	cout << "\n\nCurrency Card    :" << endl;
//	cout << "_____________________________________" << endl;
//	cout << "Country    : " << Currency.Country() << endl;
//	cout << "Code       : " << Currency.CurrencyCode() << endl;
//	cout << "Name       : " << Currency.CurrencyName() << endl;
//	cout << "Rate(1$) = : " << Currency.Rate() << endl;
//	cout << "_____________________________________" << endl;
//
//}
//  
//
//int main()
//{
//	clsCurrency Currency1 = Currency1.FindByCode("jod");
//
//	if (Currency1.IsEmpty())
//	{
//		cout << "\nCurrency Is Not Found!\n";
//	}
//	else
//		_PrintCurrency(Currency1);
//
//	clsCurrency Currency2 = Currency2.FindByCountry("Egypt");
//	if (Currency2.IsEmpty())
//	{
//		cout << "\nCurrency Is Not Foun!\n";
//	}
//	else
//		_PrintCurrency(Currency2);
//
//
//	cout << "\nCurrency1 After Updating Rate:";
//	Currency1.UpdateRate(0.71);
//	_PrintCurrency(Currency1);
//
//}
 









//int main()
//{
//	int Number;
//	cout << "Enter Number";
//	cin >> Number;
//
//	float* ptr;
//
//	ptr = new float[Number];
//
//	for (size_t i = 0; i < Number; i++)
//	{
//		cin >> *(ptr + i);
//	}
//
//	for (size_t i = 0; i < Number; i++)
//	{
//		cout<<*(ptr + i);
//	}
//
//}
//
//int main()
//{
//	int* ptr1;
//	float* ptr2;
//
//	ptr1 = new int;
//	ptr2 = new float;
//
//	*ptr1 = 10;
//	*ptr2 = 20;
//
//	cout << *ptr1 << endl;
//	cout << *ptr2 << endl;
//
//	delete ptr1;
//	delete ptr2;
//}