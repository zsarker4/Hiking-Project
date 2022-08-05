#include "Reservations.h"
#include <iostream>
#include <iomanip>

using namespace std;

int Reservations::addReservation(int ID, const string& name)
{
	int tempID = RESERVATION_NUMBER;
	if (count == 0)
	{
		last = new Node(tempID, ID, name, nullptr, nullptr);
		first = last;
	}
	else
	{
		tempID = last->getRevNum() + 1;
		last = new Node(tempID, ID, name, last, nullptr);
		last->getPrev()->setNext(last);
	}
	count++;
	return tempID;
}

Node* Reservations::findReservation(int num) const
{
	Node* pNode = first;
	bool found = false;
	while (pNode != nullptr && !found)
	{
		if (pNode->getRevNum() == num)
		{
			found = true;
		}
		else
		{
			pNode = pNode->getNext();
		}
	}
	return pNode;
}

void Reservations::cancelReservation(int num)
{
	Node* pNode = findReservation(num);
	if (pNode == first)
	{
		if (count == 1)
		{
			delete first;
			first = nullptr;
			last = nullptr;
			pNode = nullptr;
		}
		else
		{
			first = first->getNext();
			first->setPrev(nullptr);
			delete pNode;
			pNode = nullptr;
		}
	}
	else if (pNode == last)
	{
		last = last->getPrev();
		last->setNext(nullptr);
		delete pNode;
		pNode = nullptr;
	}
	else
	{
		pNode->getPrev()->setNext(pNode->getNext());
		pNode->getNext()->setPrev(pNode->getPrev());
		delete pNode;
		pNode = nullptr;
	}
	cout << "Reservation #" << num << " has been canceled.\n\n";
	count--;
}

void Reservations::printReservation(int num, 
	HikeList& aHike, MemberList& aMember) const
{
	Node* pNode = findReservation(num);

	if (pNode == nullptr)
	{
		cout << "This reservation does not exist.\n\n";
	}
	else
	{
		string nameHike = pNode->getName();

		aHike.printByHikeName(nameHike);

		int points = aMember.getPoints(pNode->getID());

		double originalPrice = aHike.getPrice(pNode->getName());

		double price = points / 100;

		cout << fixed << setprecision(2);
		cout << "\n Discounted price using points: $"
			<< originalPrice - price << endl;
	}


}

void Reservations::clearList()
{
	last = nullptr;
	Node* temp = first;
	while (temp != nullptr) {
		first = first->getNext();
		delete temp;
		temp = first;
	}
	count = 0;
}

Reservations::~Reservations()
{
	clearList();
}

