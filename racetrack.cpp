#include <iostream>
#include "racetrack.h"
#include "userhorse.h"
#include "user.h"
#include "horse.h"
#include <algorithm>
#include <vector>
#include <chrono>
#include <thread>

Racetrack::Racetrack() {}

void Racetrack::get_winner(comphorse vec, userhorse* name, User* user) { // Function to get winner

    bool first = true;

    for (int i = 0; i < 7; i++) {

        racetrack_times.push_back(vec.bot_race_times[i]); // Adds bot times to race vector
        racetrack_names.push_back(vec.bot_names[i]); // Adds bot names to race vector

    }

    racetrack_times.push_back(name -> get_race_t()); // Adds user time to race vector
    racetrack_names.push_back(name -> get_name()); // Adds user name to race vector

    fastest_time = *max_element(racetrack_times.begin(), racetrack_times.end()); // Finds fastest time (highest speed)


    for (int i = 0; i < racetrack_times.size(); i++) { // Loops through race times vector to check for fastest time

        if (racetrack_times[i] == fastest_time) { // If fastest time is found

            fastest_horse.push_back(racetrack_names[i]); // Adds horse name to fastest horse vector


        }
    }

    for (int i = 0; i < racetrack_times.size(); i++) { // Loops through and outputs fastest horse
        cout << racetrack_names[i] << ": " << racetrack_times[i] << "km/h" << endl;
    }
    if (fastest_horse.size() == 1) { // If only one horse is fastest

        cout << "\n" << fastest_horse[0] << " is the winner with a speed of " << fastest_time << " km/h!" << endl;

    } else { // If more than one horse is fastest (tie)

        cout << "\nThere is a tie between ";
        
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

    if (fastest_time == name->get_race_t()) { // If user wins

        if ((vec.bot_race_times[0] >= 8) && (vec.bot_race_times[0] <= 11)) { // win d1
            user -> user_wonD1(); // Adds win to user
            name -> win_D1(); // Adds win to horse
        } else if ((vec.bot_race_times[0] >= 12) && (vec.bot_race_times[0] <= 15)) { // win d2
            user -> user_wonD2();
            name -> win_D2();
        } else if ((vec.bot_race_times[0] >= 16) && (vec.bot_race_times[0] <= 19)) { // win d3
            user -> user_wonD3();
            name -> win_D3();
        } else {
            cout << "error" << endl; // Error
        }
    }

    clear_racetrack(); // Empties vectors
    int return_race;
    bool inputing = false;

    while (inputing == false) { // Loops until user inputs valid input
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\nPress 9 to Return To Main Menu: " ;

        if (!(cin >> return_race)){
            cin.clear();
            cin.ignore();
        }
        if (return_race == 9){
            return;
         }

    if (return_race != 9){ // If input is not 9
        cout << "Invalid Input!";
        this_thread::sleep_for(chrono::seconds(1));
    }
}


}

void Racetrack::clear_racetrack() {
    fastest_horse.clear(); // Clears fastest horse vector
    racetrack_times.clear(); // Clears racetrack times vector
    racetrack_names.clear(); // Clears racetrack names vector
}