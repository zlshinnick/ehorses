#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <cmath>
#include "horse.h"
#include "comphorse.h"
using namespace std;


//calling this function will assign random time in an interval based on the division parameter
void comphorse::set_bot_race_t(int div) {

    //creates random number between 0.0 and 3.0
    double rand_n = (rand()%300)/10;
    rand_n /= 10;  //creates random number between 0.0 and 3.0

  if (div > 0 && div < 4) {    
    
    //assigning a time based on level
    if (div == 1) {
      //bots in division 1 will have a random time between 8 and 11 seconds
    
      this->race_time = rand_n + 8;

    } else if (div == 2) {
      //bots in division 2 will have a random time between 10 and 13 seconds
      this->race_time = rand_n + 10;

    } else if (div == 3) {
      //bots in division 3 will have a random time between 12 and 15 seconds
      this->race_time = rand_n + 12;
    }
    
  } else {
    //if invalid entry entered characteristics will be set to:
    cout << "Invalid Input" << endl;
    
    race_time;
  }
  }
