/*
    Hello World

    Tran, Kim Thien
    Sarker, Zahradinee

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#include "MemberList.h"

#include <algorithm>
#include <iostream>

using namespace std;

MemberList::MemberList()
{
    memberList = new set<Member>;
}

void MemberList::addMember(const std::string& fName, 
    const std::string& lName)
{
    int len = static_cast<int>(memberList->size());
    Member newMem(fName, lName);
    int newID = startID + len;
    newMem.setID(newID);
    memberList->insert(newMem);
}

void MemberList::addMember(const std::string& fName, 
    const std::string& lName, int points)
{
    int len = static_cast<int>(memberList->size());
    Member newMem(fName, lName);
    int newID = startID + len;
    newMem.setID(newID);
    newMem.addPoints(points);
    memberList->insert(newMem);
}

int MemberList::getLastID() const
{
    return  (*(memberList->rbegin())).getID();
}

int MemberList::getPoints(int memberID) const
{
    auto found = find_if(memberList->begin(), memberList->end(),
        [memberID](const Member& tempMem)
        { return memberID == tempMem.getID(); });
    int points = (*found).getPoints();
    return points;
}

void MemberList::printMember(int memberID, const std::string& lName) const
{
    auto found = find_if(memberList->begin(), memberList->end(),
        [memberID](const Member& tempMem)
        { return tempMem.getID() == memberID; });
    if (found != memberList->end())
    {
        if (lName == (*found).getlName())
        {
            (*found).printMember();
            cout << "\tMembership # " << (*found).getID() << "\n\n";
        }
    }
}

void MemberList::clearList()
{
    memberList->clear();
}

MemberList::~MemberList()
{
    delete memberList;
    memberList = nullptr;
}