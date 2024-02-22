#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Classes.h"

Warrior::Warrior(const string& name): Player(name){
    type = "Warrior";
    hitPoints += bonus;
    strength += bonus;
}

void Warrior::action(vector<Player*>& arena){
    
    for(Player*& player : arena){

        if(player != this && player->isAlive()){
            attacks(*player);
            return;
        }
    }
}

void Warrior::readSettings(ifstream& input){
    input >> bonus;
}

double Warrior::bonus = 0.0;

Vampire::Vampire(const string& name): Player(name){
    type = "Vampire";
}

void Vampire::action(vector<Player*>& arena){

    int temp;

    if(arena[0]->name == this->name)
        temp = 1;
    else
        temp = 0;

    for(int i = 0; i < (int)arena.size(); i++){

        if(arena[i]->getHP() > arena[temp]->getHP() && arena[i]->name != this->name)
            temp = i;
    }

    attacks(*arena[temp]);
}

void Vampire::readSettings(ifstream& input){
    input >> drain;
}

double Vampire::drain = 0.0;