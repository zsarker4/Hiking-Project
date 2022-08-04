/*
	Hello World

	Tran, Kim Thien
	Sarker, Zahradinee

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef RESERVATIONREADER_H
#define RESERVATIONREADER_H

#include "Reservations.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string RESERVATIONS_LIST = "reservations_database.txt";

void createReservationList(ifstream& infile, Reservations& reservationList)
{
	int ID;
	string revName;

	while (!infile.eof())
	{
		infile >> ID >> revName;
		reservationList.addReservation(ID, revName);
	}
}

void getReservationData(Reservations& reservationList)
{
	ifstream infile;

	infile.open(RESERVATIONS_LIST);

	if (!infile)
	{
		cerr << RESERVATIONS_LIST << " does not exist." << endl;
		exit(1); // terminates program
	}

	createReservationList(infile, reservationList);

	infile.close();
}

#endif
