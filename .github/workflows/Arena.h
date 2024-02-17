#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <Player.h>
#include <Classes.h>

using std::string, std::vector, std:: ostream;

int readSettings(){

    int rounds = 0;

    ifstream settings;

    settings.open("settings.txt");
    if(!settings.is_open()){
        cout << "File could not be found" << endl;
        return rounds;
    }

    string param;

    while(settings >> param){
        if(param == "Player")
            Player::readSettings();

        else if(param == "Warrior")
            Warrior::readSettings();
        else if(param == "Vampire")
            Vampire::readSettings();
        else if(param == "Round")
            settings >> rounds;
    }

    return rounds;
}

vector<Player*> readPlayers(){

    vector<Player*> arena;
    
    ifstream players("players.txt");
    if (not inputFile.is_open() ) {
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

    return arena;
}

void printWinner(vector<Player*>);

void roundAction(vector<Player*>& arena) {
    for (Player*& player : arena){
        if ( player->isAlive() ) {
            player->action(arena);
        }
    }
}
