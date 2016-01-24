/**********************************************************************************************
Name: Marco Pallavicini		Z#: 23248259
Course: Date Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date: January 26, 2016	Due Time: 8:00pm
Total Points: 100
Assignment 3: Date program

Description:

**********************************************************************************************/

#include <iostream>
#include <string>
#include "date.h"

using namespace std;

int main()
{
	//Demonstrate functionality of the default constructor
	Date myDate;
	myDate.display();
	cout << endl;

	//Demonstrate functionality of the explicit-value constructor
	Date yourDate(12, 31, 1957);
	yourDate.display();
	cout << endl;

	//Should display error message that 15 is an invalid month
	Date test1Date(15, 1, 1962);
	cout << endl;

	//Should display error message for leap year
	Date test2Date(2, 29, 1956);
	cout << endl;

	//Should display error message that 2 is an invalid year
	Date test3Date(2, 30, 1955);
	cout << endl;

	//Should display error message that 0000 is an invalid year
	Date test4Date(12, 31, 0000);
	cout << endl;

	//Should display error message that month, day, and year are invalid
	Date test5Date(80, 40, 0000);
	cout << endl;

	cout << yourDate.getMonth() << endl;
	cout << yourDate.getDay() << endl;
	cout << yourDate.getYear() << endl;

	//myDate.setMonth(11); 
	//myDate.setDay(12);
	//myDate.setYear(2015);
	//cout<<"myDate: "<<myDate<<" test2Date: "<<test2Date<<" yourDate: "<<yourDate<<endl;

	return 0;

}
