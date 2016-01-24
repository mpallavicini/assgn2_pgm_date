#include <iostream>
#include <string>
#include "date.h"
#include <iomanip>

using namespace std;

/**********************************************************************************************/
//Name:				Date (default constructor)
//Precondition:		The state of the object has not been initialized
//Postcondition:	The state has been initialized to 01/01/0001
//Description:		Initializes the state of the class to the default value of 01/01/0001
Date::Date()
{
	cout << "Default constructor has been called." << endl;
	myMonth = 01;
	myDay = 01;
	myYear = 0001;
}

/**********************************************************************************************/
//Name:				Date (explicit-value constructor)
//Precondition:		The state of the object has not been initialized
//Postcondition:	The state has been initalized to the defined values
//Description:		Initilizes the state ofthe class to the explicitly defined values
Date::Date(unsigned m, unsigned d, unsigned y)
{
	cout << "Explicit-value constructor has been called." << endl;
	setMonth(m);
	setYear(y); //year is set before day in order to determine leap year
	setDay(d);
}

/**********************************************************************************************/
//Name:				Display
//Precondition:		The state of the object has been initalized.
//Postcondition:	The date is displayed on screen as mm/dd/yyyy with preceding 0s where necessary.
//Description:		Displays the date as saved in the state of a Date object.
void Date::display() const
{
	cout << setfill('0'); //precede with 0s where necessary
	cout << setw(2) << myMonth << "/" << setw(2) << myDay << "/" << setw(4) << myYear << endl;
}

/**********************************************************************************************/
//Name:				getMonth
//Precondition:		The month of the object has been initalized.
//Postcondition:	The month of the object is passed to the function call.
//Description:		Retreives the month from the state of the object and returns it.
int Date::getMonth() const
{
	return myMonth;
}

/**********************************************************************************************/
//Name:				getDay
//Precondition:		The day of the object has been initalized.
//Postcondition:	The day of the object is passed to the function call.
//Description:		Retrieves the day from the state of the object and returns it.
int Date::getDay() const
{
	return myDay;
}

/**********************************************************************************************/
//Name:				getYear
//Precondition:		The year of the object has been initalized.
//Postcondition:	The year of the object is passed to the function call.
//Description:		Retrieves the day from the state of the object and returns it.
int Date::getYear() const
{
	return myYear;
}

/**********************************************************************************************/
//Name:				setMonth
//Precondition:		The object has been declared.
//Postcondition:	The month of the object is modified to the defined value.
//Description:		Checks the validity of the specified month and stores it in the state of the object.
//					Displays an error message if month is invalid (less than 1 or greater than 12).
void Date::setMonth(unsigned m)
{
	myMonth = m;

	if ((myMonth > 12) | (myMonth < 1)) //test for month being 1-12; display error message if invalid
	{
		cout << m << " is an invalid month." << endl;
	}
}

/**********************************************************************************************/
//Name:				setDay
//Precondition:		The object has been declared.
//Postcondition:	The day of the object is modified to the defined value.
//Description:		Checks the validity of the specified day and stores it in the state of the object.
//					Displays an error message if day is invalid per # of days in the specified month (including for leap years).
//					Displays an error message if day cannot be validated because the month is invalid.
void Date::setDay(unsigned d)
{
	myDay = d;
	
	if ((myMonth == 1) | (myMonth == 3) | (myMonth == 5) | (myMonth == 7) | (myMonth == 8) | (myMonth == 10) | (myMonth == 12)) //31 day months
	{
		if ((myDay > 31) | (myDay < 1)) //test for day being 1-31; display error message if invalid
		{
			this->display(); //display the entered date
			cout << myDay << " is an invalid day for this month." << endl;
		}		
	}
	else if ((myMonth == 4) | (myMonth == 6) | (myMonth == 9) | (myMonth == 11)) //30 day months
	{
		if ((myDay > 30) | (myDay < 1)) //test for day being 1-30; display error message if invalid
		{
			this->display(); //display the entered date
			cout << myDay << " is an invalid day for this month." << endl;
		}
	}
	else if (myMonth == 2) //February
	{
		if ((myYear % 4) == 0) //check for leap year
		{
			if ((myDay > 28) | (myDay < 1)) //test for day being 1-28; display error message if invalid
			{
				this->display(); //display the entered date
				cout << myDay << " is an invalid day for February. " << setfill('0') << setw(4) << myYear << " is a leap year." << endl;
			}
		}
		else
		{
			if ((myDay > 28) | (myDay < 1)) //test for day being 1-29; display error message if invalid
			{
				this->display(); //display the entered date
				cout << myDay << " is an invalid day for this month." << endl;
			}
		}
	}
	else
	{
		cout << "Month is invalid, therefore " << myDay << " is an invalid day." << endl;
	}
}

/**********************************************************************************************/
//Name:				setYear
//Precondition:		The object has been decalred.
//Postcondition:	The year of the object is modified to the defined value.
//Description:		Checks the validity of the specified year and stores it in the state of the object.
//					Displays an error message if year is invalid (less than or equal to 0).
void Date::setYear(unsigned y)
{
	myYear = y;

	if (myYear <= 0)
	{
		cout << setfill('0') << setw(4) << myYear << " is an invalid year." << endl;
	}
}

/**********************************************************************************************/
//Name:				operator<< overload
//Precondition:		The object has been initalized.
//Postcondition:	The date is displayed on screen as mm/dd/yyyy with preceding 0s where necessary.
//Description:		Displays the date as saved in the state of a Date object.
ostream & operator<<(ostream & out, const Date & dateObj)
{
	out << setfill('0'); //precede with 0s where necessary
	out << setw(2) << dateObj.myMonth << "/" << setw(2) << dateObj.myDay << "/" << setw(4) << dateObj.myYear;
	return out;
}