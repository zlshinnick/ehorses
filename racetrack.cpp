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

void Racetrack::get_winner(comphorse vec, userhorse* name, User* user) {

    //calling function for user to select the horse they want to race
    // userhorse users_racer = get_users_horse();
    //calling function to randomise race_time attribute
    // users_racer.set_rand_race_time();  

    name->set_rand_race_time();
    bool first = true;

    for (int i = 0; i < 7; i++) {

        racetrack_times.push_back(vec.bot_race_times[i]);
        racetrack_names.push_back(vec.bot_names[i]);

    }

    racetrack_times.push_back(name->get_race_t());
    racetrack_names.push_back(name->get_name());

    fastest_time = *max_element(racetrack_times.begin(), racetrack_times.end()); // might put this outside of loop


    for (int i = 0; i < racetrack_times.size(); i++) {

        if (racetrack_times[i] == fastest_time) {

            fastest_horse.push_back(racetrack_names[i]);


        }
    }
    for (int i = 0; i < racetrack_times.size(); i++) {
        cout << racetrack_names[i] << ": " << racetrack_times[i] << "km/h" << endl;
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

    if (fastest_time == name->get_race_t()) {

        if ((vec.bot_race_times[0] >= 8) && (vec.bot_race_times[0] <= 11)) { // win d1
            user->user_wonD1();
            name->win_D1();
        } else if ((vec.bot_race_times[0] >= 12) && (vec.bot_race_times[0] <= 15)) { // win d2
            user->user_wonD2();
            name->win_D2();
        } else if ((vec.bot_race_times[0] >= 16) && (vec.bot_race_times[0] <= 19)) { // win d3
            user->user_wonD3();
            name->win_D3();
        } else {
            cout << "error" << endl;
        }
    }
    clear_racetrack();

}

void Racetrack::clear_racetrack(){
    fastest_horse.clear();
    racetrack_times.clear();
    racetrack_names.clear();
}