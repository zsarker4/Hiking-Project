#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "Member.h"
#include <set>
#include <string>

const int startID = 111;

class MemberList
{
public:
    MemberList();

    void addMember(const std::string& fName, const std::string& lName);

    void addMember(const std::string& fName, const std::string& lName,
        int points);

    int getLastID() const;

    int getPoints(int memberID) const;

    void printMember(int memberID, const std::string& lName) const;

    void clearList();

    ~MemberList();
private:
    std::set<Member>* memberList;
};
#endif
