#include "Member.h"
#include <iostream>

using namespace std;

int Member::getID() const {
	return id;
}

string Member::getlName() const {
	return lName;
}

int Member::getPoints() const {
	return points;
}

void Member::addPoints(int thePoints) {
	points += thePoints;
}

void Member::setID(int newID) {
	id = newID;
}

void Member::printMember() const {
	cout << "\t" << lName << ", " << fName << "\n"
		<< "\tPoints available: " << points << endl;
}

bool Member::operator<(const Member& other) const
{
	return id < other.id;
}
