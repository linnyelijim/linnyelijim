//Fort Hays State University - CSCI 121
//Project 5 - "Top Down Concept"
//Author: Lindsey Jimenez
//Date: 10-13-2021

#include <iostream>
#include <string>
using namespace std;


void testMenu();
// post-condition: the test menu is displayed for choose

bool isLeapYear(int year);
// pre-condition: year entered is valid. 
// post-condition: returns true if year is a leap year, false otherwise.

int getCenturyValue(int year);
// pre-condition: year entered is valid.
// post-condition: returns centry value for entered year. 

int getYearValue(int year);
// pre-condition: year entered is valid.
// post-condition: returns year value for entered year. 

int getMonthValue(int month, int year);
// pre-condition: year and month entered are valid.
// post-condition: returns month value for entered year and month.

int dayOfWeek(int month, int day, int year);
// pre-condition: year, month, and day entered are valid.
// post-condition: returns day of week value for entered year, month, and day.

std::string dayOfWeek(int day);
// pre-condition: day has integer value 0, 1, 2, 3, 4, 5, or 6
/* post-condition: the name of the day of week is returned as a std::.
If day has value 0, then SUNDAY is returned; 1, then MONDAY is returned; and so on.*/

bool validCheck(int year);
// post-condition: returns true if year is valid, otherwise returns false.

bool validCheck(int month, int year);
// post-condition: returns true if year and month are valid, otherwise returns false.

bool validCheck(int month, int day, int year);
// post-condition: returns true if year, month, and day are valid, otherwise returns false.

void checkUserInput(int& year);
// pre-condition: user inputs a year.
// post-condition: if year is valid, continue. Otherwise, prompt invalid response. 

void checkUserInput(int& month, int& year);
// pre-condition: user inputs a year and month.
// post-condition: if year and month are valid, continue. Otherwise, prompt invalid response. 

void checkUserInput(int& month, int& day, int& year);
// pre-condition: user inputs a year, month, and day.
// post-condition: if year, month, and day are valid, continue. Otherwise, prompt invalid response. 



int main()
{
	using namespace std;
	int choice;
	int day, month, year;


	do
	{
		testMenu();
		cout << "Please choose from menu: ";
		cin >> choice;
		switch (choice)
		{
		case 1: // check if a given year is leap year
			cout << "Please enter a year: ";
			cin >> year;
			checkUserInput(year); // if false, will prompt with invalid year and ask again
			if (isLeapYear(year))
				cout << "Year " << year << " is a leap year" << endl;
			else
				cout << "Year " << year << " is NOT a leap year" << endl;
			break;
		case 2: // calculate the century value of a given year
			cout << "Please enter a year: ";
			cin >> year;
			checkUserInput(year); // if false, will prompt with invalid year and ask again
			cout << "The century value is: " << getCenturyValue(year) << endl;
			break;
		case 3: // calculate the year value of a given year
			cout << "Please enter a year: ";
			cin >> year;
			checkUserInput(year); // if false, will prompt with invalid year and ask again
			cout << "The year value is: " << getYearValue(year) << endl;
			break;
		case 4: // calculate the month value of a given month in a given year
			cout << "Please enter a year and month: ";
			cin >> year >> month;
			checkUserInput(month, year); // if false, will prompt with invalid month or year and ask again
			cout << "The month value is: " << getMonthValue(month, year) <<
				endl;
			break;
		case 5: // calculate the day of week of a given date
			cout << "Please enter a year, a month, and a day : ";
			cin >> year >> month >> day;
			checkUserInput(month, day, year); // if false, will prompt with invalid month, day, or year and ask again
			cout << "The day of the week is: " << dayOfWeek(month, day, year) << endl;
			break;
		case 6: // print out the name of a given day of week
			cout << "Please enter a day of week(0 for Sunday, 1 for Monday, etc): ";
				cin >> day;
			cout << "The name of the day of the week is: " << dayOfWeek(day) << endl;
			break;
		case 7:
			cout << "Did you tested all functions yet ? if not, please rerun the program\n";
				break;
		default:
			cout << "wrong option. Please choose from menu\n";
			break;
		}

		system("pause");

	} while (choice != 7);
}

void testMenu()
{
	cout << "*************************************"<< endl;
	cout << " * Test Menu *" << endl;
	cout << " * 1. isLeapYear *" << endl;
	cout << " * 2. getCenturyValue *" << endl;
	cout << " * 3. getYearValue *" << endl;
	cout << " * 4. getMonthValue *" << endl;
	cout << " * 5. dayOfWeek(month, day, year) *" << endl;
	cout << " * 6. dayOfWeek(day) *" << endl;
	cout << " * 7. Quit *" << endl;
	cout << "*************************************"<< endl;
}

bool validCheck(int year)
{
	return year > 1582;
}
//checks validity of year input

bool validCheck(int month, int year)
{
	return (validCheck(year) && month >= 1 && month <= 12);
}
// checks validity of month and year input

bool validCheck(int month, int day, int year)
{
	bool validCheckDay;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		validCheckDay = day >= 1 && day <= 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		validCheckDay = day >= 1 && day <= 30;
		break;
	case 2:
		validCheckDay = isLeapYear(year) ? (day >= 1 && day <= 29) : (day >= 1 && day <= 28);
		break;
	default:
		validCheckDay = false;
	}
	return validCheckDay && validCheck(month, year);
}
// checks the validity of month, day, and year input

void checkUserInput(int&year)
{
	while (validCheck(year) == false)
	{
		cout << "Year is invalid. Please enter a year after 1582: ";
		cin >> year;
	}
}
// prompt response when year in invalid

void checkUserInput(int& month, int& year)
{
	while (validCheck(month, year) == false)
	{
		cout << "One or both of your inputs is invalid. Please enter a month between 1-12 and a year after 1582: ";
		cin >> year >> month;
	}
}
// prompt response when year and/ or month is invalid

void checkUserInput(int& month, int& day, int& year)
{
	while (validCheck(month, day, year) == false)
	{
		cout << "At least one of your inputs is invalid. Please enter a year after 1582, a month between 1-12, and a day between 0-31: ";
		cin >> year >> month >> day;
	}
}
// prompt response when year and/ or month and/ or day is invalid

bool isLeapYear(int year)
{
	return((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}
// equation to find leap year

int getCenturyValue(int year)
{
	return (2 * (3 - (year / 100) % 4));
}
// equation to find century value

int getYearValue(int year)
{
	return ((year % 100) + (year % 100 / 4));
}
// equation to find year value

int getMonthValue(int month, int year)
{
	int monthValue;
	switch (month)
	{
	case 1:
		if(isLeapYear(year))
			monthValue = 6;
		else
			monthValue = 0;
		break;
	case 2:
		if(isLeapYear(year))
			monthValue = 2;
		else
			monthValue = 3;
		break;
	case 3: monthValue = 3;
		break;
	case 4: monthValue = 6;
		break;
	case 5: monthValue = 1;
		break;
	case 6: monthValue = 4;
		break;
	case 7: monthValue = 6;
		break;
	case 8: monthValue = 2;
		break;
	case 9: monthValue = 5;
		break;
	case 11: monthValue = 3;
		break;
	case 12: monthValue = 5;
		break;
	default: monthValue = 0;
		break;
	}
	return monthValue;
}
// function to find month value

int dayOfWeek(int month, int day, int year)
{
	return (getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year) + day) % 7;
}
// equation to find day of the week 

std::string dayOfWeek(int day)
{
	string dayValue;

	switch (day)
	{
	case 0: dayValue = "Sunday";
		break;
	case 1: dayValue = "Monday";
		break;
	case 2: dayValue = "Tuesday";
		break;
	case 3: dayValue = "Wednesday";
		break;
	case 4: dayValue = "Thursday";
		break;
	case 5: dayValue = "Friday";
		break;
	case 6: dayValue = "Saturday";
		break;
	default: dayValue = "Invalid day. Please try again.";
		break;
	}
	return dayValue;
}
// funtion that assigns strings to day values
