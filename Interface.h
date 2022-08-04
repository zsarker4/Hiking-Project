/*
	Hello World

	Tran, Kim Thien
	Sarker, Zahradinee

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef INTERFACE_H
#define INTERFACE_H

#include "Reservations.h"
#include "HikeList.h"
#include "MemberList.h"

#include <string>

void displayMenu();

void processReservation(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);

void chooseByLocation(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);

void chooseByDuration(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);

void chooseByDifficulty(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);

void chooseByPrice(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);

int askIfMember(MemberList& memberList);

int addNewMember(MemberList& memberList);

void makeReservation(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);

void viewReservation(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);

void cancelReservation(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);

void askToReserve(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation);

#endif
