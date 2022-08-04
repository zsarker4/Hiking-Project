/*
	Hello World

	Tran, Kim Thien
	Sarker, Zahradinee

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#include "Interface.h"

#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu()
{
	cout << "***************************************************" << endl
		<< "\t \t HIKING IN THE US" << endl
		<< "***************************************************\n" << endl
		<< "\t 1. Browse by location" << endl
		<< "\t 2. Browse by duration" << endl
		<< "\t 3. Browse by difficulty" << endl
		<< "\t 4. Browse by price" << endl
		<< "\t 5. Make a reservation" << endl
		<< "\t 6. View reservation" << endl
		<< "\t 7. Cancel reservation" << endl
		<< "\t 8. Exit" << endl;
	cout << endl;
}

void processReservation(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation)
{
	cout << "Please make a selection: ";
	int ans = 1;
	cin >> ans;
	cout << "\n";
	while (ans != 8) {
		if (ans == 1) {
			chooseByLocation(hikeList, memberList, reservation);
		}
		else if (ans == 2) {
			chooseByDuration(hikeList, memberList, reservation);
		}
		else if (ans == 3) {
			chooseByDifficulty(hikeList, memberList, reservation);
		}
		else if (ans == 4) {
			chooseByPrice(hikeList, memberList, reservation);
		}
		else if (ans == 5) {
			makeReservation(hikeList, memberList, reservation);
		}
		else if (ans == 6) {
			viewReservation(hikeList, memberList, reservation);
		}
		else if (ans == 7) {
			cancelReservation(hikeList, memberList, reservation);
		}
		cout << "\n";
		system("Pause");
		displayMenu();
		cout << "Please make a selection: ";
		cin >> ans;
	}
	cout << "\nThank you for visiting!";
}

void chooseByLocation(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation)
{
	hikeList.printAllLocations();
	cout << "Choose a location: ";
	string location;
	cin >> location;
	cout << "\n";
	hikeList.printByLocation(location);
	askToReserve(hikeList, memberList, reservation);
}

void chooseByDuration(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation)
{
	cout << "\t(days)\n";
	hikeList.printByDuration();
	cout << "\n";
	cout << "How many days are you considering? ";
	int ans = 1;
	cin >> ans;
	cout << "\n";
	hikeList.printByDuration(ans);
	askToReserve(hikeList, memberList, reservation);
}

void chooseByDifficulty(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation)
{
	// TODO
	cout << "Choose difficulty level:\n" << endl;
	cout << "\te. easy\n"
		<< "\tm. moderate\n"
		<< "\ts. strenous\n";

	cout << "Your choice: ";
	char choice = 'a';
	cin >> choice;

	cout << "\n\t(diffculty level)\n";
	hikeList.printByDifficulty(choice);
	askToReserve(hikeList, memberList, reservation);
}

void chooseByPrice(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation)
{
	// TODO
	hikeList.printByPrice();
	askToReserve(hikeList, memberList, reservation);
}

int askIfMember(MemberList& memberList)
{
	// TODO
	cout << "Are you a member? (y/n) ";
	char ans = 'a';
	cin >> ans;
	cout << "\n";
	int id = 0;
	if (ans == 'y')
	{
		cout << "What is your member ID number? ";
		cin >> id;
		cout << "\n";
		cout << "What is your last name? ";
		string lName;
		cin >> lName;
		cout << "\n";
		memberList.printMember(id, lName);
	}
	else
	{
		id = addNewMember(memberList);
	}
	return id;
}

int addNewMember(MemberList& memberList)
{
	// TODO
	cout << "\tLet's add you to the member list!\n";
	cout << "\t\tWhat is your first name? ";
	string fName;
	cin >> fName;
	cout << "\t\tWhat is your last name? ";
	string lName;
	cin >> lName;
	cout << "\n\tWelcome to the club!\n";
	memberList.addMember(fName, lName);
	cout << "\t\tYour member ID number is: " 
		<< memberList.getLastID() << "\n\n";
	return memberList.getLastID();
}

void makeReservation(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation)
{
	// TODO
	int id = askIfMember(memberList);
	cout << "Which hike would you like to reserve (hike name)? ";
	string hikeName;
	cin >> hikeName;
	cout << "\n";
	hikeList.printByHikeName(hikeName);
	double originalPrice = hikeList.getPrice(hikeName);
	int points = memberList.getPoints(id);
	if (points != 0)
	{
		double discountedPrice = points / 100;
		cout << fixed << setprecision(2);
		cout << "\tDiscounted price using points: $" << originalPrice - discountedPrice << "\n\n";
	}
	int revNum = reservation.addReservation(id, hikeName);
	cout << "\tBefore proceeding, please make a note of your reservation order.\n"
		<< "\t  Reservation #: " << revNum << "\n\n";
	cout << "( *** Will continue to scheduling and payment. *** )" << "\n\n";
}

void viewReservation(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation)
{
	// TODO
	cout << "Enter reservation #: ";
	int revNumber = 0;
	cin >> revNumber;
	reservation.printReservation(revNumber, hikeList, memberList);
}

void cancelReservation(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation)
{
	// TODO
	cout << "Enter reservation #: ";
	int revNum = 0;
	cin >> revNum;
	reservation.printReservation(revNum, hikeList, memberList);
	cout << "Are you sure you want to cancel this reservation? (y/n) ";
	char ans = 'a';
	cin >> ans;
	cout << "\n";
	if (ans == 'y')
	{
		reservation.cancelReservation(revNum);
	}
}

void askToReserve(HikeList& hikeList, MemberList& memberList,
	Reservations& reservation)
{
	// TODO
	cout << "Would you like to make a reservation? (y/n): ";
	char ans = 'a';
	cin >> ans;
	cout << "\n";
	if (ans == 'y')
	{
		makeReservation(hikeList, memberList, reservation);
	}
}