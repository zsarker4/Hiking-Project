#ifndef MEMBER_H
#define MEMBER_H

#include <string>
class Member
{
public:
	Member() : id(0), points(0) {}

	Member(const std::string& FName, const std::string& LName) :
		id(0), points(0), fName(FName), lName(LName) {}

	int getID() const;

	std::string getlName() const;

	int getPoints() const;

	void addPoints(int thePoints);

	void setID(int newID);

	void printMember() const;

	bool operator<(const Member& other) const;

	// ~Member();
private:
	int id;
	std::string fName;
	std::string lName;
	int points;
};
#endif
