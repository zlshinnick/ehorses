#include <iostream>
#include "comphorse_yifan.h"
#include <vector>
#include "userhorse.h"
#include <ctime>
#include <string>

class Racetrack : public comphorse, public userhorse {
    public:
    Racetrack();
    double fastest_time;
    vector<string> fastest_horse;

    string winner;

    vector<double> racetrack_times;
    vector<string> racetrack_names;

    userhorse get_users_horse();  //for zach
    
    void get_winner(comphorse vec, userhorse name);
};
