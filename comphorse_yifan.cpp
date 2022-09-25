#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <cmath>
#include <vector>
#include <algorithm>

#include "horse.h"
#include "comphorse_yifan.h"

using namespace std;

comphorse::comphorse () {
    bot_race_times = {};
}


//calling this function will assign random time in an interval based on the division parameter
vector<double> comphorse::set_bot_race_times(int div) {

  if (div > 0 && div < 4) {    
    
    //assigning a time based on level
    if (div == 1) {
      //bots in division 1 will have a random time between 8 and 11 seconds
    
        for (int i = 0; i < 8; i++) {
            //creates random number between 0.0 and 3.0
            double rand_n = (rand()%300)/10;
            rand_n /= 10;  //creates random number between 0.0 and 3.0

            this -> race_time = rand_n + 8;

            bot_race_times.push_back(race_time);
        }

    } else if (div == 2) {

        for (int i = 0; i < 8; i++) {
            //creates random number between 0.0 and 3.0
            double rand_n = (rand()%300)/10;
            rand_n /= 10;  //creates random number between 0.0 and 3.0

            this -> race_time = rand_n + 10;

            bot_race_times.push_back(race_time);
        }
        
    } else if (div == 3) {

        for (int i = 0; i < 8; i++) {
            //creates random number between 0.0 and 3.0
            double rand_n = (rand()%300)/10;
            rand_n /= 10;  //creates random number between 0.0 and 3.0

            this -> race_time = rand_n + 12;

            bot_race_times.push_back(race_time);
        }

    } else {

        cout << "Invalid Input" << endl;

        bot_race_times = {};
    }
}
}

void comphorse::get_bot_race_times() {

    for (int i = 0; i < 8; i++) {

        cout << bot_race_times[i] << endl;
    }

}