
/*
	Hello World

	Tran, Kim Thien
	Sarker, Zahradinee

	Spring 2022
	CS A250 - C++ 2
	Project: Hiking in the US
*/

#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include "HikeList.h"
#include "MemberList.h"
#include <string>

const int RESERVATION_NUMBER = 50001;

class Node
{
public:
	Node() : revNum(0), id(0), prev(nullptr), next(nullptr) {}

	Node(int number, int anID, const std::string& aName,
		Node* prevLink, Node* nextLink) :
		revNum(number), id(anID), name(aName), prev(prevLink), next(nextLink) {}

	int getRevNum() const { return revNum; }

	int getID() const { return id; }

	std::string getName() const { return name; }

	Node* getPrev() const { return prev; }

	Node* getNext() const { return next; }

	void setNum(int number) { revNum = number; }

	void setID(int newID) { id = newID; }

	void setName(const std::string& hikeName) { name = hikeName; }

	void setPrev(Node* prevLink) { prev = prevLink; }

	void setNext(Node* nextLink) { next = nextLink; }

	~Node() {}
private:
	int revNum;
	int id;
	std::string name;
	Node* prev;
	Node* next;
};

class Reservations
{
public:
	Reservations() : first(nullptr), last(nullptr), count(0) {}

	int addReservation(int ID, const std::string& name);

	void cancelReservation(int num);

	void printReservation(int num, HikeList& aHike,
		MemberList& aMember) const;

	void clearList();

	~Reservations();
private:
	Node* findReservation(int num) const;
	Node* first;
	Node* last;
	int count;
};
#endif