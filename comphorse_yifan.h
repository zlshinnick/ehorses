#include <string>
#include <vector>

#include "horse.h"

#pragma once

using namespace std;

class comphorse : public horse {
  
  public:

    comphorse();
    void get_bot_info();
    void get_bot_times();
    int rand_num;
    
    vector<string> bot_names;
    vector<string> set_bot_names(int div);
    vector<double> bot_race_times;
    //calling this function will assign random time in an interval based on the division parameter
    vector<double> set_bot_race_times(int div);

    vector<comphorse> bot_times_and_names (int div);

    //virtual function in horse which needs definition
    void set_rand_race_time();
};

