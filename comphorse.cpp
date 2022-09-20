#include <iostream>
#include <string>
#include <ctime>
#include "horse.h"
#include "comphorse.h"
using namespace std;


//constuctor of bot horse
comphorse::comphorse(int div) {
srand(time(NULL));  
  if (div > 0 && div < 4) {    
    
    //setting initial name & level of horse
    name = "tba";
    
    //creates random number between 0.0 and 3.0
    //srand(time(NULL));
    double rand_n = (rand()%300)/10; rand_n = (rand_n/10);   //creates random number between 0.0 and 3.0
    
    //assigning a time based on level
    if (div == 1) {
      //bots in division 1 will have a random time between 8 and 11 seconds
      race_time = rand_n + 8;

    } else if (div == 2) {
      //bots in division 2 will have a random time between 10 and 13 seconds
      race_time = rand_n + 10;

    } else if (div == 3) {
      //bots in division 3 will have a random time between 12 and 15 seconds
      race_time = rand_n + 12;
    }
    
  } else {
    //if invalid entry entered characteristics will be set to:
    name = "invalid";
    race_time = 0;
  }

}
