#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using std::string, std::vector, std:: ostream, std::ifstream;

class Player {
    static double baseHitPoints;
    static double baseStrength;

protected:
    string type;
    double hitPoints;
    double strength;

public:
    string name;

public:
    Player(const string& name);

    virtual void action(vector<Player*>&) = 0;

    bool isAlive();

    double getHP();

    static void readSettings(ifstream&);

    friend ostream& operator<<(ostream&, const Player&);

protected:
    bool attacks(Player& other);
};