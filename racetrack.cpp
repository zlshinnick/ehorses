#include <iostream>
#include "racetrack.h"

Racetrack::Racetrack() {}

Racetrack::~Racetrack() {}

comphorse* Racetrack::generate_track (int div){ // adds enemy horses to the track
    comphorse* ptr = &horses[0];

    for (int i = 0; i < 8; i++) {
        horses.push_back(comphorse(div));
    }

    return ptr;
}

string Racetrack::get_winner () {
    fastest_comp = horses[0].race_time;
    winner = horses[0].name;

    for (int i = 0; i < horses.size(); i++) {
        if (horses[i].race_time < fastest_comp) {
            fastest_comp = horses[i].race_time;
            winner = horses[i].name;
        }
    }

    if (fastest_comp < horse::race_time) {
        winner = horse::name;

        cout << "You Won!" << endl;
    } else {
        cout << "You Lost" << endl;
    }
}