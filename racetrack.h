#ifndef RACETRACK_H
#define RACETRACK_H

#include <iostream>
#include "comphorse_yifan.h"
#include <vector>
#include "userhorse.h"
#include <ctime>
#include <string>
#include "stable.h"
#include "user.h"

class Racetrack {
    public:
    Racetrack(); // Default constructor
    double fastest_time; // Variable to store fastest time
    vector<string> fastest_horse; // Vector to store fastest horse

    string winner; // Variable to store winner

    vector<double> racetrack_times; // Vector to store horse times/speeds
    vector<string> racetrack_names; // Vector to store horse names

    
    void get_winner(comphorse vec, userhorse* name, User* user); // Function to get winner

    void clear_racetrack(); // Function to clear racetrack stats
};

#endif