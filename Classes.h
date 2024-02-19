#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Player.h"

using std::string, std::vector, std:: ostream;

class Warrior : public Player{
    static double bonus;
public:
    Warrior(const string&);

    virtual void action(vector<Player*>&) = 0;

    static void readSettings(ifstream&);
};

class Vampire : public Player{
    static double drain;
public:
    Vampire(const string&);

    virtual void action(vector<Player*>&) = 0;

    static void readSettings(ifstream&);
};
