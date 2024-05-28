#ifndef MULTAUDITORY_H
#define MULTAUDITORY_H
#include <iostream>
#include "Auditory.h"
using namespace std;

class MultAuditory: public Auditory
{
protected:
	string nameEquipment;
public :
	MultAuditory(int number, int area, int numTwoTable, int numThreeTable, string nameEquipment);
	void displayIntoFile(ostream& out) override;
	void saveWithSpaces(ostream& out) override;
	void display() override;
	void addNameEquipment(string newNameEquipment);
};
#endif // !MULTAUDITORY

