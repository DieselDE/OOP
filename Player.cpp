#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Player.h"

using std::string, std::vector, std:: ostream, std::ifstream;

Player::Player(const string& name):
    name(name), type("Player"), hitPoints(baseHitPoints), strength(baseStrength) {}

bool Player::isAlive(){
    return hitPoints > 0;
}

double Player::getHP(){
    return hitPoints;
}

void Player::readSettings(ifstream& input){
    input >> baseHitPoints >> baseStrength;
}

ostream& operator<<(ostream& out, const Player& p) {
    return out << p.name << " (" << p.type << ", " << p.hitPoints << "HP, " << p.strength << "S)";
}

bool Player::attacks(Player& other){
    if(other.isAlive()){
        if(other.hitPoints < strength)
            other.hitPoints = 0;
        else{
            other.hitPoints -= strength;
        }

        return true;
    }

    return false;
}

double Player::baseHitPoints = 0.0;
double Player::baseStrength = 0.0;