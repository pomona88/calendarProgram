/************************************************************************************************
Programmer:  Andrew Thompson
Class:  CS10
Date of completion:  3/19/13
Instructor:  Dave Harden
File:  a8.2.cpp

This program prints a calendar for one year, given the day of the week on which January 1 falls.

The user is queried for the year and the first day of the year.  A for loop is used to print a 
header for each month as well as the dates in each month.  Inside the for loop, a value-returning 
function (getNumOfDays) is called to determine the number of dates in a given month, and within 
that function, a Boolean value-returning function (isLeapYear) is used to check whether the year 
in question is a leap year.  
*************************************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;


void getUserInput(int& year, int& day);
void printHeader(int currentMonth);
void printMonthName(int monthNumber);
void printMonth(int& firstPosition, int numOfDays);
int getNumOfDays(int monthNumber, int year);
bool isLeapYear(int year);

const int WEEK = 7;  // used for modular division
const int MIN_DAYS = 28;  // minimum number of days in a month


int main() {

	int year, firstPosition;

	getUserInput(year, firstPosition);

	cout << "           " << year << endl;

	for (int i = 1; i <= 12; i++) {
		printHeader(i);
		printMonth(firstPosition, getNumOfDays(i, year));
	}

	system("pause");
}












/************************************************************************************************
Pre: Reference parameters year and day have been declared in main but not assigned values.
Post: year and day have been assigned values by user.

This function queries the user for the year, which is displayed at the top of the calendar and
which determines the number of days in February.  The function also queries the user for the day
of the week on which January 1 falls.
************************************************************************************************/
void getUserInput (int& year, int& day) {
	cout << "What year do you want a calendar for? ";
	cin >> year;
	cout << "What day of the week does January 1 fall on (0 for Sunday, 1 for Monday, etc.)? ";
	cin >> day;
}












/************************************************************************************************
Pre: Value parameter currentMonth has been assigned a value by the for loop that invokes
printHeader.
Post: The name of the month, letters indicating the days of the week, and a dashed line are
output as a header.

printHeader invokes printMonthName to convert the number of the month to the name of the month.
************************************************************************************************/
void printHeader(int currentMonth) {
		cout << "\n        ";
		printMonthName(currentMonth);
		cout << "\n  S  M  T  W  T  F  S" << endl;
		cout << "---------------------" << endl;
}












/************************************************************************************************
Pre: Value parameter monthNumber has been assigned a value by the function call to getUserInput 
in main.
Post: The name of the month equivalent to the input month number is output.  For example, 
"January" is output for monthNumber 1.

This function uses a switch statement to determine the name of the month to be output.
************************************************************************************************/
void printMonthName(int monthNumber) {
	switch (monthNumber) {
		case 1: cout << "January";
				break;
		case 2: cout << "February";
				break;
		case 3: cout << "March";
				break;
		case 4: cout << "April";
				break;
		case 5: cout << "May";
				break;
		case 6: cout << "June";
				break;
		case 7: cout << "July";
				break;
		case 8: cout << "August";
				break;
		case 9: cout << "September";
				break;
		case 10: cout << "October";
				break;
		case 11: cout << "November";
				break;
		case 12: cout << "December";
				break;
	}
}












/************************************************************************************************
Pre: Reference parameter firstPosition has been assigned a value either by getUserInput or by the 
immediately preceding call to printMonth.  numOfDays has been assigned a value in the function
call for printMonth, which contains a call to getNumOfDays.
Post: Any necessary leading space as well as all of the dates of the given month have been output.
The starting position for the next month has been calculated.

The first for loop inserts any necessary leading space if the month does not begin on Sunday.  

The second for loop prints the dates of the month, up to the maximum number of dates, which depends 
on the month.  At the end of any interation where the day of the week is Saturday, a newline is 
created so the next date outputs in the Sunday position.

If a month has 28 days, the next month starts on the same day of the week.  If a month has 29 days,
the next month starts one day of the week later, etc.  So the starting position for the next month 
is equal to the starting position for the current month plus any additional days over 28.  At the 
end of printMonth, firstPosition is updated using this formula, and modulus division by 7 prevents 
dates from extending past Saturday.
************************************************************************************************/
void printMonth(int& firstPosition, int numOfDays) {

	for (int i = 0; i < firstPosition; i++) {
		cout << setw(3) << " ";
	}

	for (int j = 1; j <= numOfDays; j++) {
		cout << setw(3) << j;
		if ((j + firstPosition) % WEEK == 0) {
			cout << endl;
		}
	}

	cout << endl;

	firstPosition = (firstPosition + numOfDays - MIN_DAYS) % WEEK;
}












/************************************************************************************************
Pre: Value parameter monthNumber has been assigned a value by the for loop in main that invokes
getNumOfDays as one of the arguments for printMonth.  Value parameter year has been assigned a 
by the function call to getUserInput in main.
Post: A value for the number of days in the month is returned.

This function uses a switch statement to determine the number of days to be returned.  The case
for February calls the Boolean value-returning function isLeapYear to determine whether the month
has 28 or 29 days.
************************************************************************************************/
int getNumOfDays(int monthNumber, int year) {
	switch (monthNumber) {
		case 1: return 31;
		case 2: if (isLeapYear(year)) {
					return 29;
				} else {
					return 28;
				}
		case 3: return 31;
		case 4: return 30;
		case 5: return 31;
		case 6: return 30;
		case 7: return 31;
		case 8: return 31;
		case 9: return 30;
		case 10: return 31;
		case 11: return 30;
		case 12: return 31;
	}
}












/************************************************************************************************
Pre: The value parameter year has been assigned a value in the call to getUserInput.
Post: A Boolean value is returned based on whether or not the input year is a leap year.

A series of if statements returns either true or false, using criteria to determine whether a
year is a leap year.
************************************************************************************************/
bool isLeapYear(int year) {
    if (year % 400 == 0){    
        return true;
    }

    if (year % 100 == 0){    
        return false;
    }

    return year % 4 == 0;
}