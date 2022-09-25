#include "comphorse_yifan.h"
#include "racetrack.h"

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main () {

    srand(time(NULL));
    comphorse c1; 

    c1.set_bot_names(3);
    c1.set_bot_race_times(3);

    c1.get_bot_info();

    Racetrack r1;

    r1.get_winner(c1);
}

