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
