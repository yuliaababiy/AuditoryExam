#include "Auditory.h"

Auditory::Auditory(int number, int area, int numTwoTable, int numThreeTable)
	: number(number), area(area), numTwoTable(numTwoTable), numThreeTable(numThreeTable) {}

void Auditory::displayIntoFile(ostream& out)
{
	out << "Number: " << number << " Area: " << area << " NumTwoTable: " << numTwoTable
		<< " NumThreeTable: " << numThreeTable << endl;
}


void Auditory::display()
{
	cout << "Number: " << number << " Area: " << area << " NumTwoTable: " << numTwoTable
		<< " NumThreeTable: " << numThreeTable << endl;
}

void Auditory::saveWithSpaces(ostream& out)
{
	out << "Auditory: " << number << " " << area << " " << numTwoTable << " " << numThreeTable << endl;
}

int Auditory::getNumber()
{
	return number;
}

int Auditory::getNumberOfPlaces()
{
	return numTwoTable * 2 + numThreeTable * 3;
}

int Auditory::getArea()
{
	return area;
}

int Auditory::getFloor()
{
	return number / 100;
}
