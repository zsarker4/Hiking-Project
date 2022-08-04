/*
    Hello World

    Tran, Kim Thien
    Sarker, Zahradinee

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/


#ifndef HIKE_H
#define HIKE_H

#include <string>
#include <iostream>

class Hike
{
    friend std::ostream& operator<<(std::ostream&, const Hike& aHike);
public:
    Hike() : duration(0), difficulty('a') {}

    Hike(const std::string& aLocation, const std::string& aName,
        int aDuration, char aDifficulty) : 
        location(aLocation), name(aName), duration(aDuration),
        difficulty(aDifficulty) {}

    std::string getLocation() const;

    int getDuration() const;

    std::string getName() const;

    char getDifficulty() const;

    bool operator<(const Hike& otherHike) const;

    // ~Hike();

private:
    std::string location;
    std::string name;
    int duration;
    char difficulty;
};
#endif
