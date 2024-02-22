#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Player.h"
#include "Classes.h"

using std::cout, std::endl, std::string, std::vector, std:: ostream;

int readSettings(){

    int rounds = 0;

    ifstream settings("settings.txt");
    if(!settings.is_open()){
        cout << "File could not be found" << endl;
        return rounds;
    }

    string param;

    while(settings >> param){
        if(param == "Player")
            Player::readSettings(settings);

        else if(param == "Warrior")
            Warrior::readSettings(settings);
        else if(param == "Vampire")
            Vampire::readSettings(settings);
        else if(param == "Round")
            settings >> rounds;
    }

    settings.close();

    return rounds;
}

vector<Player*> readPlayers(){

    vector<Player*> arena;
    
    ifstream players("players.txt");
    if (not players.is_open() ) {
        cout << "Could not open settings file" << endl;
        return arena;
    }

    string className;
    string name;

    while(players >> className){

        players >> name;

        if(className == "Warrior")
            arena.push_back(new Warrior(name));
        else
            arena.push_back(new Vampire(name));
    }

    players.close();

    return arena;
}

void printWinner(vector<Player*>& arena) {

    double maxHP = 0.0;
    vector<Player*> winners;

    for (Player*& p : arena) {
        if ( p->getHP() > maxHP) {
            winners.clear();
            winners.push_back(p);
            maxHP = p->getHP();
        }
        else if (p->getHP() <= maxHP && p->getHP() > 0) {
            winners.push_back(p);
        }   
    }

    if ( winners.size() == 1) {
        cout << "Winner is :" << endl;
        cout << "- " << *winners[0] << endl;
    }
    else {
        cout << "Winners are :" << endl;
        for (Player*& p : winners) {
            cout << "- " << *p << endl;
        }
    }
}


void roundAction(vector<Player*>& arena){

    for (Player*& player : arena){
        if ( player->isAlive() ) {
            player->action(arena);
        }
    }
}
