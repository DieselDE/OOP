#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Arena.h"

using std::string, std::vector, std:: ostream;

int main() {

    int nRounds = readSettings();
    vector<Player*> arena = readPlayers();

    for (int i = 0; i < nRounds; i++) {
        roundAction(arena);
    }
    printWinner(arena);
}
