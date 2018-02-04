#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
bool pass = false;
string password = "Luc";
string entered = "";
int attempts = 4;
 
int main()
{
/*	std::string _Line;
	fstream _myFile("C:\\Users\\Diego\\Desktop\\hiddden.txt");
	std::getline(_myFile, _Line);
	std::cout << _Line << std::endl; */

	while (pass == false)
	{
		cout << "Please Enter Your Password" << endl << "Password: ";
		cin >> entered;
		if (entered == password)
		{
			cout << endl << "That is the Correct Password!" << endl;
			int attemps = 4;
			bool pass = true;
			std::string read;
			fstream textFile("C:\\Users\\Diego\\Desktop\\hiddden.txt");
			std::getline(textFile, read);
			std::cout << read << std::endl;

			return 0;
		}
		else
		{
			if (attempts == 0)
			{
				cout << endl << "Unfortunately, You Suck, You Have Tried Too Many Times to Get Access to My Account and Have Now Been Locked Out!" << endl;
				break;
			}
			else if (attempts == 1) 
			{
				cout << endl << "That Password is Incorrect! This is Your Last Chance." << endl << endl;
				attempts--;
			}
			else
			{
				cout << endl << "That Password is Incorrect! You have " << attempts << " attempts remaining." << endl << endl;
				attempts--;
			}
		}
	}
}