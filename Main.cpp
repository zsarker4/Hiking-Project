/*
    Hello World

    Tran, Kim Thien
    Sarker, Zahradinee

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/


#include <iostream>
#include <utility>
#include "Interface.h"
#include "HikeReader.h"
#include "MemberReader.h"
#include "ReservationReader.h"

using namespace std;

int main()
{
    MemberList memberList;
    HikeList hikeList;
    Reservations reservations;
    getMemberData(memberList);
    getHikeData(hikeList);
    getReservationData(reservations);
    displayMenu();
    processReservation(hikeList, memberList, reservations);
}