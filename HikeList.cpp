#include "HikeList.h"

#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

HikeList::HikeList()
{

}

void HikeList::addHike(const Hike& newHike, double price)
{
    hikeList.insert(pair<Hike, double>(newHike, price));
}

void HikeList::addHike(const std::string& location, const std::string& hikeName,
    int duration, char difficulty, double price)
{
    Hike newHike(location, hikeName, duration, difficulty);
    hikeList.insert(pair<Hike, double>(newHike, price));
}

double HikeList::getPrice(const std::string& nameHike) const
{
    auto position = find_if(hikeList.begin(), hikeList.end(), 
        [nameHike] (const pair<Hike, double>& pair) { return pair.first.getName() == nameHike; });
    return (*position).second;
}
void HikeList::printAllLocations() const
{
    auto iter = hikeList.begin();
    Hike firstHike = (*iter).first;
    auto iterUp = hikeList.upper_bound(firstHike);
    auto iterLast = hikeList.end();
    while (iter != iterLast)
    {
        cout << "\t" << (*iter).first.getLocation() << endl;
        iter = hikeList.upper_bound((*iter).first);
    }
    cout << endl;
}
void HikeList::printByLocation(const std::string& location) const
{
    auto iter = find_if(hikeList.begin(), hikeList.end(), 
        [location](const pair<Hike, double>& hike) 
        { return hike.first.getLocation() == location; });
    auto iterUp = hikeList.upper_bound((*iter).first);
    cout << fixed << setprecision(2);
    while (iter != iterUp)
    {
        cout << (*iter).first << endl;
        cout << "\t  Price (per person): $ " << (*iter).second << endl;
        cout << endl;
        ++iter;
    }
}

void HikeList::printByDuration() const
{
    multimap<int, string> temp;
    auto iter = hikeList.begin();
    auto iterLast = hikeList.end();
    while (iter != iterLast)
    {
        Hike tempHike = (*iter).first;
        temp.insert(pair<int, string>(tempHike.getDuration(), tempHike.getName() + ", " + tempHike.getLocation()));
        iter++;
    }
    for_each(temp.begin(), temp.end(),
        [](const pair<int, string>& tempPair)
        { cout << "\t(" << tempPair.first << ") " << tempPair.second << endl; });
    cout << "\n";
}

void HikeList::printByDuration(int duration) const
{
    for (const pair<Hike, double>& pair : hikeList)
    {
        if (pair.first.getDuration() == duration)
        {
            cout << pair.first << endl;
        }
    }
    cout << "\n";
}


void HikeList::printByDifficulty(char difficulty) const
{
    for (const auto& tempPair : hikeList)
    {
        Hike tempHike = tempPair.first;
        if (tempHike.getDifficulty() == difficulty)
        {
            cout << "\t(" << tempHike.getDifficulty() << ") "
                << tempHike.getName() << ", "
                << tempHike.getLocation() << endl;
        }
    }
}
void HikeList::printByPrice() const
{
    multimap<double, pair<string, string>> temp;
    auto iter = hikeList.begin();
    auto last = hikeList.end();
    cout << fixed << showpoint << setprecision(2);
    while (iter != last)
    {
        Hike tempHike = (*iter).first;
        double price = (*iter).second;
        temp.emplace(price, pair<string, string>(tempHike.getLocation(), tempHike.getName()));
        ++iter;
    }
    for (const auto& pair : temp)
    {
        cout << "\t$ " << setw(7) << pair.first << " - " << pair.second.first
            << " (" << pair.second.second << ")" << endl;
    }
}

void HikeList::printByHikeName(const std::string& nameHike) const
{
    auto found = find_if(hikeList.begin(), hikeList.end(),
        [nameHike](const pair<Hike, double>& tempPair)
        { return nameHike == tempPair.first.getName(); });
    cout << "\n";
    cout << fixed << setprecision(2);
    cout << (*found).first << endl;
    cout << "\t  $" << (*found).second << "\n\n";
}

void HikeList::clearList()
{
    hikeList.clear();
}

HikeList::~HikeList() {
    clearList();
}
