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
    int divisionC;
    
    vector<string> bot_names; // Vector to store bot names
    vector<string> set_bot_names(int div); // Function to set bot names
    int set_div(int div); // Function to set division to be used by virtual function
    vector<double> bot_race_times; // Vector to store bot race times
    void set_rand_race_time(); // Virtual function to set bot race times
};

