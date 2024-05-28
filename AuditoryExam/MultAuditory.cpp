#include "MultAuditory.h"

MultAuditory::MultAuditory(int number, int area, int numTwoTable, int numThreeTable, string nameEquipment) 
	: Auditory(number, area, numTwoTable, numThreeTable), nameEquipment(nameEquipment){}

void MultAuditory::displayIntoFile(ostream& out)
{
	out << " Number: " << number << " Area: " << area << " NumTwoTable: " << numTwoTable
		<< " NumThreeTable: " << numThreeTable << " NameEquipment:"<< nameEquipment << endl;
}


void MultAuditory::display()
{
	cout << " Number: " << number << " Area: " << area << " NumTwoTable: " << numTwoTable
		<< " NumThreeTable: " << numThreeTable << " NameEquipment:" << nameEquipment << endl;
}