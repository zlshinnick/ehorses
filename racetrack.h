#include <iostream>
#include "comphorse_yifan.h"
#include <vector>
#include <ctime>
#include <string>

class Racetrack : public comphorse {
    public:
    Racetrack();
    double fastest_time;
    vector<string> fastest_horse;

    string winner;

    vector<double> racetrack_times;
    vector<string> racetrack_names;
    
    void get_winner(comphorse vec);
};
