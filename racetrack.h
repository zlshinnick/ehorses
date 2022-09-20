#include <iostream>
#include "comphorse.h"
#include <vector>
#include <ctime>

class Racetrack : public horse {
    public:
    int div = division;
    double fastest_comp;
    string winner;
    
    vector<comphorse> horses;
    comphorse* generate_track (int div);
    string get_winner();
};

