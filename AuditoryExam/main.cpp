#include <iostream>
#include <algorithm>
#include "Auditory.h"
#include "MultAuditory.h"
#include <vector>
#include <fstream>
#include <set>


void displayAuditory(vector<Auditory*>& auditories)
{
	for (auto auditory : auditories)
	{
		auditory->display();
	}
}


void saveToFile(vector <Auditory*>& auditories, string filename)
{
	ofstream file(filename);
	for (auto auditory : auditories)
	{
		auditory->displayIntoFile(file);
	}
}


void loadFromFile(vector <Auditory*>& auditories, string filename)
{
	ifstream file(filename);
	int number, area, numTwoTable, numThreeTable;
	string nameEquipment;
	string type;
	while (file >> type >> number >> area >> numTwoTable >> numThreeTable)
	{
		if (type == "Auditory")
		{
			auditories.push_back(new Auditory (number, area, numTwoTable, numThreeTable));
		}
		else if (type == "MultAuditory")
		{
			file >> nameEquipment;
			auditories.push_back(new MultAuditory(number, area, numTwoTable, numThreeTable, nameEquipment));
		}
	}
}

int main()
{
	vector <Auditory*> auditories;
	ofstream file("input.txt", ios::app);
	int choice;
	while (true)
	{
		cout << "Enter action u wanna to do:" << endl;
		cout << "1 - load from file and print" << endl;
		cout << "2 - add object to file" << endl;
		cout << "3 - print objects into file" << endl;
		cout << "4 - output without duplications" << endl;
		cout << "5 - get number of places" << endl;
		cout << "6 - get floor" << endl;
		cout << "7 - exit" << endl;
		cin >> choice;
		if (choice == 1)
		{
			loadFromFile(auditories, "input.txt");
			displayAuditory(auditories);
		}
		else if (choice == 2)
		{
			int number, area, numTwoTable, numThreeTable;
			string nameEquipment;
			string type;
			cout << "Enter tepe Auditory or MultAuditory: ";
			cin >> type;
			if (type == "Flat")
			{
				cout << "Enter number : ";
				cin >> number;
				cout << "Enter area: ";
				cin >> area;
				cout << "Enter numTwoTable: ";
				cin >> numTwoTable;
				cout << "Enter numThreeTable : ";
				cin >> numThreeTable;
				Auditory* c = new Auditory(number, area, numTwoTable, numThreeTable);
				c->saveWithSpaces(file);
			}
			else if (type == "MultAuditory")
			{
				cout << "Enter number : ";
				cin >> number;
				cout << "Enter area: ";
				cin >> area;
				cout << "Enter numTwoTable: ";
				cin >> numTwoTable;
				cout << "Enter numThreeTable : ";
				cin >> numThreeTable;
				cout << "Enter nameEquipment"
				MultAuditory* e = new MultAuditory(number, area, numTwoTable, numThreeTable, nameEquipment);
				e->saveWithSpaces(file);
			}
			else
			{
				cout << "You entered wrong!" << endl;
				break;
			}
		}
		else if (choice == 3)
		{
			loadFromFile(auditories, "input.txt");
			saveToFile(auditories, "output.txt");
		}
		else if (choice == 4)
		{
			loadFromFile(auditories, "input.txt");
			set <string> unique;
			for (auto a : auditories)
			{
				unique.insert(a->getArea());
			}

			for (auto u : unique)
			{
				cout << u << " ";
			}
			cout << endl;
		}
		
		else if (choice == 5)
		{
			
			int numTwoTable;
			int numThreeTable;
			return numTwoTable * 2 + numThreeTable * 3;
			//Auditory auditories(numTwoTable, numThreeTable);
			//int numOfPlaces = auditories.getNumberOfPlaces();
			//cout << "Num of places: " << numOfPlaces << endl;
		}

		else if (choice == 6)
		{
			void displayFloor()
			{
				cout << "The auditory is located on floor: " << getFloor() << endl;
			}
		}
		
		else if (choice == 7)
		{
			break;
		}
		else
		{
			cout << "You entered wrong!" << endl;
		}
	}
}