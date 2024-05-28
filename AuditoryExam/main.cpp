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
	auditories.clear(); 
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
			auditories.push_back(new Auditory(number, area, numTwoTable, numThreeTable));
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
		cout << "4 - output the the biggest" << endl;
		cout << "5 - output with the most count of places" << endl;
		cout << "6 - get number of places of second floor" << endl;
		cout << "7 - get overall area" << endl;
		cout << "8 - get each floor number of auditories" << endl;
		cout << "9 - exit" << endl;
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
			cout << "Enter type Auditory or MultAuditory: ";
			cin >> type;
			if (type == "Auditory")
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
				cout << "Enter nameEquipment";
				cin >> nameEquipment;
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
			Auditory* theBiggest = new Auditory(0, 0, 0, 0);
			for (auto a : auditories)
			{
				if (a->getArea() > theBiggest->getArea())
				{
					theBiggest = a;
				}
			}
			cout << "The biggest auditory: ";
			theBiggest->display();
			cout << endl;
		}
		else if (choice == 5)
		{
			loadFromFile(auditories, "input.txt");
			Auditory* theMostCountOfPlaces = new Auditory(0, 0, 0, 0);
			for (auto a : auditories)
			{
				if (a->getNumberOfPlaces() > theMostCountOfPlaces->getNumberOfPlaces())
				{
					theMostCountOfPlaces = a;
				}
			}
			cout << "The auditory with the most count of places: ";
			theMostCountOfPlaces->display();
			cout << endl;
		}
		else if (choice == 6)
		{
			// для кожної аудиторії на 2 поверсі, добавте 10 квадратних метрів до площі
			//loadFromFile(auditories, "input.txt");
			//for (auto a : auditories)
			//{
			//	if (a->getFloor() == 2)
			//	{
			//		a->setArea(a->getArea() + 10);
			//	}
			//}

			loadFromFile(auditories, "input.txt");
			int totalPlacesOfSecondFloor = 0;
			for (auto a : auditories)
			{
				if (a->getFloor() == 2)
				{
					totalPlacesOfSecondFloor += a->getNumberOfPlaces();
				}
			}
			cout << "Total number of places of second floor is: " << totalPlacesOfSecondFloor << endl;
		}
		else if (choice == 7)
		{
			loadFromFile(auditories, "input.txt");
			int overallArea = 0;
			for (auto a : auditories)
			{
				overallArea += a->getArea();
			}
			cout << "Overall area is: " << overallArea << endl;
		}
		else if (choice == 8)
		{
			loadFromFile(auditories, "input.txt");
			int firstFloorCount = 0;
			int secondFloorCount = 0;
			int threeFloorCount = 0;
			for (auto a : auditories)
			{
				if (a->getFloor() == 1)
				{
					firstFloorCount += 1;
				}
				else if (a->getFloor() == 2)
				{
					secondFloorCount += 1;
				}
				if (a->getFloor() == 3)
				{
					threeFloorCount += 1;
				}
			}
			cout << "1 floor: " << firstFloorCount << " 2 floor: " << secondFloorCount << " 3 floor: " << threeFloorCount << endl;

			ifstream file("input.txt");
			int number, area, numTwoTable, numThreeTable;
			string nameEquipment;
			string type;
			while (file >> type >> number >> area >> numTwoTable >> numThreeTable)
			{
				if (type == "MultAuditory")
				{
					cout << number / 100;
				}
			}
		}
		else if (choice == 9)
		{
			break;
		}
		else
		{
			cout << "You entered wrong!" << endl;
		}
	}
}