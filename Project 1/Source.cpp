/*
* Name: Annamarie Cortes
* Date: 11/12/2023
* Class: CS-210
*/

using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
#include "Clock.h"


void printClocks();
void printMenu();


int main() {

	int hours = 0;
	int minutes =0;
	int seconds =0;
	
	//gettng userinput to set the time
	cout << "What is the initial time? (hh mm ss) in 24-hour format" << endl;
	cin >> hours >> minutes >> seconds;

	//checking for invalid input with userinput hours, minutes, seconds
	do {
		cout << "Invalid input. Please enter intitial time: " << endl;
		cin >> hours >> minutes >> seconds;

	} while (hours > 24 || minutes > 60 || seconds > 60);

	//calling the setTime method 
	setTime(hours, minutes, seconds);
	//calling the printClock method
	printClocks();

	
	int userChoice;

	//calling the printMenu method
	printMenu();

	do {
		//getting userinput choice
		cout << "Enter a menu selection: " << endl;
		cin >> userChoice;
		switch (userChoice) {
		//adding hours and displaying the clock
		case 1:
			addHour();
			printClocks();
			break;
		//adding minutes
		case 2:
			addMinute();
			printClocks();
			break;
		//ading seconds
		case 3:
			addSecond();
			printClocks();
			break;
		//exiting the program
		case 4:
			cout << "Goodbye" << endl;
			break;
		//checking for invalid outut
		default:
			cout << "Invalid input. Please enter a valid option." << endl;
			break;

		}
	} while (userChoice != 4);


	return 0;
}

//prints the clock
void printClocks()
{
	cout << "**************************" << endl;
	cout << "*      12-HOUR CLOCK     *" << endl;
	cout << "*       " << get12HourFormat() <<"      *" << endl;
	cout << "**************************" << endl;
	cout << "*      24-HOUR CLOCK     *" << endl; 
	cout << "*        " << get24HourFormat() << "        *" << endl;
	cout << "**************************" << endl;

}

//prints the menu
void printMenu()
{
	cout << endl;
	cout << "        MAIN MENU" << endl;
	cout << "**************************" << endl;
	cout << "*   1 - Add One Hour     *" << endl;
	cout << "*   2 - Add One Minute   *" << endl;
	cout << "*   3 - Add One Second   *" << endl;
	cout << "*   4 - Exit Program     *" << endl;
	cout << "**************************" << endl;

}
