#ifndef  AUDITORY_H
#define AUDITORY_H
#include <iostream>
using namespace std;

class Auditory
{
protected:
	int number;
	int area;
	int numTwoTable;
	int numThreeTable;
public:
	Auditory(int number, int area, int numTwoTable, int numThreeTable);
	virtual void displayIntoFile(ostream& out);
	virtual void display();
	int getNumberOfPlaces();
	int getNumber();
	int getArea();
	int getFloor();
	virtual void saveWithSpaces(ostream& out);

};
#endif // ! AUDITORY

