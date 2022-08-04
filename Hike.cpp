/*
    Hello World

    Tran, Kim Thien
    Sarker, Zahradinee

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#include "Hike.h"

using namespace std;

ostream& operator<<(ostream& out, const Hike& aHike) {
    out << "\t" << aHike.name << " (" << aHike.location << ")" << endl
        << "\t  Difficulty: ";
    if (aHike.difficulty == 'e') {
        out << "easy" << endl;
    }
    else if (aHike.difficulty == 'm') {
        out << "moderate" << endl;
    }
    else if (aHike.difficulty == 's') {
        out << "strenuous" << endl;
    }
    out << "\t  Duration: " << aHike.duration << " day(s)";
    return out;
}

string Hike::getLocation() const {
    return location;
}

int Hike::getDuration() const {
    return duration;
}

string Hike::getName() const {
    return name;
}

char Hike::getDifficulty() const {
    return difficulty;
}

bool Hike::operator<(const Hike& otherHike) const
{
    return location < otherHike.location;
}