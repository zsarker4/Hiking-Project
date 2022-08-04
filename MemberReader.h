/*
    Hello World

    Tran, Kim Thien
    Sarker, Zahradinee

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef MEMBERREADER_H
#define MEMBERREADER_H

#include "MemberList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string MEMBERS_FILE = "members_database.txt";

void createMemberList(ifstream& infile, MemberList& memberList)
{
    string fName, lName;
    int points = 0;

    while (!infile.eof())
    {
        infile >> fName >> lName >> points;
        memberList.addMember(fName, lName, points);
    }
}

void getMemberData(MemberList& memberList)
{
    ifstream infile;
    infile.open(MEMBERS_FILE);
    if (!infile)
    {
        cerr << MEMBERS_FILE << " does not exist." << endl;
        exit(1);
    }

    createMemberList(infile, memberList);

    infile.close();
}

#endif
