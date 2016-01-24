#include <iostream>
#include <string>

using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
public:
	//Constructors
	Date();										//default constructor; sets m=01, d=01, y=0001
	Date(unsigned m, unsigned d, unsigned y);	//explicit-value constructor to set date equal to today's date.
												//Use 2-digits for month (m) and day (d), and 4-digits for year (y).
												//This function should print a message if a leap year.
	//Getters
	void display() const;		//output Date object to the screen
	int getMonth() const;		//accessor to output the month
	int getDay() const;			//accessor to output the day
	int getYear() const;		//accessor to output the year
	
	//Setters
	void setMonth(unsigned m);	//mutator to change the month
	void setDay(unsigned d);	//mutator to change the day
	void setYear(unsigned y);	//mutation to change the year

	friend ostream & operator<<(ostream & out, const Date & dateObj); //overloaded operator<< as a friend function with chaining

																	  //you may add other functions if necessary
private:
	int myMonth, myDay, myYear; //month, day, and year of a Date obj respectively
};

#endif