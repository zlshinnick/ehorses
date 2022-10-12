#include "comphorse_yifan.h"
#include "racetrack.h"
#include "userhorse.h"
#include "user.h"
#include "horse.h"
#include "stable.h"
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main () {

    srand(time(NULL));
    comphorse c1;
    userhorse u1;

    u1.set_min(10);
    u1.set_max(11);
    u1.set_name("yifan");

    c1.set_bot_names(3);
    c1.set_bot_race_times(3);

    c1.get_bot_info();

    Racetrack r1;

    r1.get_winner(c1);
}

