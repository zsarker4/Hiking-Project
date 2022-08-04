/*
    Hello World

    Tran, Kim Thien
    Sarker, Zahradinee

    Spring 2022
    CS A250 - C++ 2
    Project: Hiking in the US
*/

#ifndef HIKELIST_H
#define HIKELIST_H

#include "Hike.h"
#include <map>
#include <string>

class HikeList
{
public:
    HikeList();

    void addHike(const Hike& newHike, double price);

    void addHike(const std::string& location, const std::string& hikeName,
        int duration, char difficulty, double price);

    double getPrice(const std::string& nameHike) const;

    void printAllLocations() const;

    void printByLocation(const std::string& nameHike) const;

    void printByDuration() const;

    void printByDuration(int duration) const;

    void printByDifficulty(char difficulty) const;

    void printByPrice() const;

    void printByHikeName(const std::string& nameHike) const;

    void clearList();

    ~HikeList();
private:
    std::multimap<Hike, double> hikeList;
};

#endif