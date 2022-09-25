#include <iostream>
#include "racetrack.h"
#include <algorithm>
#include <vector>

Racetrack::Racetrack() {}

void Racetrack::get_winner(comphorse vec) {

    bool first = true;

    for (int i = 0; i < 7; i++) {

        racetrack_times.push_back(vec.bot_race_times[i]);
        racetrack_names.push_back(vec.bot_names[i]);


        fastest_time = *min_element(racetrack_times.begin(), racetrack_times.end());

    }

    /* PUSHBACK USER STATS HERE */

    for (int i = 0; i < racetrack_times.size(); i++) {

        if (racetrack_times[i] == fastest_time) {

            fastest_horse.push_back(racetrack_names[i]);
        }
    }

    if (fastest_horse.size() == 1) {

        cout << fastest_horse[0] << " is the winner with a time of " << fastest_time << " seconds!" << endl;

    } else {

        cout << "There is a tie between ";
        
        for (int i = 0; i < fastest_horse.size(); i++) {

            if (first == true) {

                cout << fastest_horse[i];
                first = false;

            } else {

                cout << " and " << fastest_horse[i];

            }

        } 
        
        cout << " with a time of " << fastest_time << " seconds!" << endl;
    }
}