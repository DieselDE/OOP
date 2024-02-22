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

    void action(vector<Player*>&) override;

    static void readSettings(ifstream&);
};

class Vampire : public Player{
    static double drain;
public:
    Vampire(const string&);

    void action(vector<Player*>&) override;

    static void readSettings(ifstream&);
};
