#include "comphorse_yifan.h"
#include "racetrack.h"
#include "userhorse.h"
#include "user.h"
#include "horse.h"
#include "stable.h"
#include <iostream>
#include <cmath>
#include "raceGraphics.h"
#include <ctime>

using namespace std;

int main () {

    srand(time(NULL));
    comphorse c1;
    userhorse u1;
    graphics g1;

    u1.set_min(20);
    u1.set_max(22);
    u1.set_name("yifan");

    c1.set_bot_names(3);
    c1.set_bot_race_times(3);

    c1.get_bot_info();

    u1.output_name();
    u1.output_min();
    u1.output_max();

    Racetrack r1;

    r1.get_winner(c1, u1);

    u1.output_wins();
}

