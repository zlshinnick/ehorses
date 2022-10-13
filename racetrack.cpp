#include <iostream>
#include "racetrack.h"
#include "userhorse.h"
#include "user.h"
#include "horse.h"
#include <algorithm>
#include <vector>

Racetrack::Racetrack() {}

// userhorse Racetrack::get_users_horse(stable user_stable) {
//     cout<<"Select Horse To Race"<<endl<<endl;
//     user_stable.print_stable();

//     int user_horse_choice;
//     cout<<"Select Horse: ";
//     cin >>user_horse_choice;

//     userhorse* stable_accessor = user_stable.get_horses();
//     return stable_accessor[user_horse_choice-1];
// }

void Racetrack::get_winner(comphorse vec, userhorse name) {

    //calling function for user to select the horse they want to race
    // userhorse users_racer = get_users_horse();
    //calling function to randomise race_time attribute
    // users_racer.set_rand_race_time();  

    user_time = name.set_rand_race_time();
    bool first = true;

    for (int i = 0; i < 7; i++) {

        racetrack_times.push_back(vec.bot_race_times[i]);
        racetrack_names.push_back(vec.bot_names[i]);

    }

    racetrack_times.push_back(name.get_race_t());
    racetrack_names.push_back(name.get_name());

    fastest_time = *max_element(racetrack_times.begin(), racetrack_times.end()); // might put this outside of loop


    for (int i = 0; i < racetrack_times.size(); i++) {

        if (racetrack_times[i] == fastest_time) {

            fastest_horse.push_back(racetrack_names[i]);

            racetrack_times.erase(racetrack_times.begin() + i);
            racetrack_names.erase(racetrack_names.begin() + i);
        }
    }

    if (fastest_horse.size() == 1) {

        cout << fastest_horse[0] << " is the winner with a speed of " << fastest_time << " km/h!" << endl;

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
        
        cout << " with a speed of " << fastest_time << " km/h!" << endl;
    }

    if (fastest_time == user_time) {
        name.increment_wins();
    }
}