/*Title: Clocks*/
//Matthew Krebs
//CS-210 C++ 
//3/19/22

#include<iostream>
#include <windows.h> //The header file Windows.h, is base header file for Win32 programming, its contain declaration of almost all basic windows macros and different typesdef
#include<thread> //Going to try to use thread for multi thread pourpose
#include<string>// for string data
#include<format> // dont think this was used. origionally was for padding of zeros
#include <iomanip> // for padding

using namespace std; //“using namespace std” means we use the namespace named std::

int hr;
int minute;
int second;
int twentyFourHr;
string amPm;
string menuSelect;
string exitProgram;
int addHr;
int addMin;
int addSec;
string exitKey; //if thread works


void getTime()
{


	cout << "Current Time is 00:00:00" << endl;
	cout << "Enter the Hour" << endl;
	cin >> hr;
	if (hr > 12)
	{
		cout << "Enter a number between 1 and 12" << endl;
		cin >> hr;
	}
	cout << "Enter the Minutes" << endl;
	cin >> minute;
	if (minute > 60)
	{
		cout << "Enter a number between 1 and 60" << endl;
		cin >> minute;
	}
	cout << "Enter the seconds" << endl;
	cin >> second;
	if (second > 60)
	{
		cout << "Enter a number between 1 and 60" << endl;
		cin >> second;
	}



	cout << "AM or PM?" << endl;
	cin >> amPm;
	if ((amPm != "am") && (amPm != "pm")) {
		cout << "must either enter \"am\" or \"pm\" " << endl;
		cin >> amPm;
	}
	if (amPm == "pm")
	{
		twentyFourHr = hr + 12;
	}
	if (twentyFourHr == 24) {
		twentyFourHr = 0;
		amPm = "am";
	}
	
	if (amPm == "am")
	{
		twentyFourHr = hr;
	}
	
	


	cout << "the time you entered is " << std::setw(2) << std::setfill('0') << hr << ":" << std::setw(2) << std::setfill('0') << minute << ":" << std::setw(2) << std::setfill('0') << second << " " << amPm << endl;
	cout << "or " << std::setw(2) << std::setfill('0') << twentyFourHr << ":" << std::setw(2) << std::setfill('0') << minute << ":" << std::setw(2) << std::setfill('0') << second << " " << amPm << " in a 24hr Clock." << endl;


}
void printTime() // prints the time after all of the input
{
	while (true)
	{
		system("cls");
		//printing time
		cout << "";
		cout << "_______________________________" << endl;
		cout << "      |" << std::setw(2) << std::setfill('0') << hr << " : " << std::setw(2) << std::setfill('0') << minute << " : " << std::setw(2) << std::setfill('0') << second << " " << amPm << " |" << endl;
		cout << "      |" << std::setw(2) << std::setfill('0') << twentyFourHr << " : " << std::setw(2) << std::setfill('0') << minute << " : " << std::setw(2) << std::setfill('0') << second << "      |" << endl;
		cout << "_______________________________" << endl;


		//increment sec min and hours	
		second++; //starts counting 
		if (second > 59)
		{
			second = 0;
			minute++; // if 59 is reached it will reset to 0
		}

		if (minute > 59)
		{
			minute = 0;
			hr++;// if 59 is reached it will reset to 0
		}


		if (hr > 12)
		{
			hr = 1;
		}
		else if (twentyFourHr >= 13) {
			amPm = "pm";
		}
		else if ((twentyFourHr == 24) && (twentyFourHr <= 12)) {
			amPm = "am";
		}
		
		
		else if (twentyFourHr == 24)
		{
			twentyFourHr = 0;
		}
		else if ((hr == 12) && (amPm == "am"))
		{
			twentyFourHr = 0;
		}
		else if ((hr == 12) && (amPm == "pm"))
		{
			twentyFourHr = 12;
		}
		else if ((hr == 1) && (amPm == "pm"))
		{
			twentyFourHr = hr + 12;
		}
		


		Sleep(1000); //keeps the second count by 1 second
	}



}


void menuAndAdd() {
	while (true) {

		cout << "Menu: " << endl; //main menue
		cout << "Press 1 to add hour" << endl;
		cout << "Press 2 to add Minute" << endl;
		cout << "Press 3 to add second" << endl;
		cout << "Press 4 to keep current time" << endl;
		cout << "Press X to exit" << endl;
		cin >> menuSelect;
		if (menuSelect == "1") {
			cout << "How many Hours would you like to add?" << endl;
			cin >> addHr;
			hr = hr + addHr;
			printTime(); //print time after hour is added
		}
		else if (menuSelect == "2") {
			cout << "How many Minutes would you like to add?" << endl;
			cin >> addMin;
			minute = minute + addMin;
			printTime();// print time after minute is added
		}
		else if (menuSelect == "3") {
			cout << "How many Seconds would you like to add?" << endl;
			cin >> addSec;
			second = second + addSec;
			printTime();//print time after second added
		}
		else if (menuSelect == "4") {
			printTime();
		}
		else if (menuSelect == "x" || menuSelect == "X") {
			cout << "Program Exit.. Goodbye!" << endl;
			

			break;
		}
		else {
			cout <<"not a valid choice" << endl;
			menuAndAdd();
		}

		/*    **I origionally used this as the input for adding seconds but liked the menu better.
		* 
		* 
		* 
		cout << "Would you like to exit the program? yes/no" << endl;
		cin >> exitProgram;
		if (exitProgram == "yes")
		{
			cout << "End Program" << endl;
			break;
		}
		if (exitProgram == "no")
		{
			cout << "Would you like to add an hour?  yes/no" << endl;
			cin >> addHr;
			if (addHr == "yes")
			{
				hr = hr + 1;
				system("cls");
			}
			else if (addHr == "no")
			{
				cout << "Would you like to add Minute? yes/no" << endl;
				cin >> addMin;

				if (addMin == "yes")
				{
					minute = minute + 1;
					system("cls");
				}

				else if (addMin == "no")
				{
					cout << "Would you like to add a Second? yes/no" << endl;
					cin >> addSec;
					if (addSec == "yes")
					{
						second = second + 1;
						system("cls");
					}
					else if (addSec == "no")
					{
						system("cls");
						continue;

					}
					else {
						cout << "not valid answer" << endl;
					}

				}
				else {
					cout << "Not valid answer" << endl;
				}

			}
			else {
				cout << "Not valid answer" << endl;
			}
		}
	}
}
*/
	}
}
	void exitOut()//this would exit the program if x is pushed - requires multi threading
	{

		cout << "Press X to exit program" << endl;
		cin >> exitKey;
		while (true)
		{
			if (exitKey == "x") {
				break;
				system("cls");
			}
		}
	}
	


int main()
{
	system("cls");

	getTime();
	menuAndAdd();

	std::thread print1(printTime);//supposed to be a thread but its not really working... might be too advanced
	std::thread print2(exitOut);

	return 0;
}



	
	/* 
	cout<< "Menu: " << endl;
	cout << "Press 1 to add hour" << endl;
	cout << "Press 2 to add Minute" << endl;
	cout << "Press 3 to add second" << endl;
	cout << "Press 4 to keep current time"<<endl;
	cout << "Press X to exit" << endl;
	cin >> menuSelect;
	if (menuSelect =="1"){
		cout<< "How many Hours Minutes would you like to add?"<<endl;
		cin>>addHr;
		hr = hr + addHr;
		printTime();
	}
	else if (menuSelect == "2") {
		cout<< "How many Minutes would you like to add?"<<endl;
		cin>>addMin;
		minute = minute + addMin;
		printTime();
	}
	else if (menuSelect == "3") {
		cout<< "How many Seconds would you like to add?"<<endl;
		cin>>addSec;
		second = second + addSec
		printTime();
	}
	else if (menuSelect == "4") {
		printTime();
	}
	else if (menuSelect == "X"){
		cout << "Program Exit" << endl;
		system("cls");
	}

}*/


/*Top of chart begins : “Clear Screen”*/

/*
1. "Display Time in Two Formats".
2. "Display Menu"
a. "Add One Second"
i. "Wait One Second"
1. "Clear Screen"
3. "Read User Input"
a.User Input = Exit ?
i. "End Program"
b.If "No", go to "Add Hour"
i.If "Yes"
1. "Add One Hour"
2. "Clear Screen"
c.If "No", go to "Add Minute"
i.If "Yes"
1. "Add Minute"
2. "Clear Screen"
d.If "No", go to "Add Second"
i.If "Yes"
1. "Add Second"
2. "Clear Screen"
e.If "No"
i.Clear Screen"*/