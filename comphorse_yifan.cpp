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
    bot_names = {};
}

vector<double> comphorse::set_bot_race_times (int div) {

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

    return bot_race_times;
}

void comphorse::get_bot_info() {

    for (int i = 0; i < 8; i++) {

        cout << bot_names[i] << ": " << bot_race_times[i] << endl;
    }

}

vector<string> comphorse::set_bot_names(int div) {

    if (div == 1) {

        bot_names = {};

        bot_names.push_back("Send 'Em");
        bot_names.push_back("Aidan's Choice");
        bot_names.push_back("Field Of Battle");
        bot_names.push_back("Just Dennis");
        bot_names.push_back("Ampitup Black");
        bot_names.push_back("Royal Accolade");
        bot_names.push_back("God's Moment");

    } else if (div == 2) {
        
        bot_names = {};

        bot_names.push_back("Parions");
        bot_names.push_back("Starchienne");
        bot_names.push_back("Missile Storm");
        bot_names.push_back("Crooked Carrot");
        bot_names.push_back("Charcoal Chaos");
        bot_names.push_back("Queen's Gift");
        bot_names.push_back("Musqueam");
        
    } else if (div == 3) {
        
        bot_names = {};

        bot_names.push_back("Hooah Havanna");
        bot_names.push_back("Compak");
        bot_names.push_back("Citino");
        bot_names.push_back("Malkar Pindari");
        bot_names.push_back("Yarralea");
        bot_names.push_back("Rockabye Bonny");
        bot_names.push_back("Zenzero Bay");

    } else {

        cout << "Invalid Input" << endl;
        bot_names = {};

    }

    return bot_names;
}