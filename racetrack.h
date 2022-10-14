#include <iostream>
#include "comphorse_yifan.h"
#include <vector>
#include "userhorse.h"
#include <ctime>
#include <string>
#include "stable.h"
#include "user.h"
#pragma once

class Racetrack {
    public:
    Racetrack();
    double fastest_time;
    vector<string> fastest_horse;

    string winner;

    vector<double> racetrack_times;
    vector<string> racetrack_names;

    
    void get_winner(comphorse vec, userhorse* name, User* user);

    void clear_racetrack();
};
