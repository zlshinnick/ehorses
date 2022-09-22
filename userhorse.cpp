#include <iostream>
#include <string>
#include <ctime>
#include "horse.h"
#include "userhorse.h"
using namespace std;

//setting userhorse variables (esstenitally a constructor)
void userhorse::set_userhorse(double max, double min) {
  max_speed = max;
  min_speed = min;
  level=0;
  points=0;
}


//get and set functions
void userhorse::set_max(double max){ this->max_speed = max;}
double userhorse::get_max() { return max_speed;}

void userhorse::set_min(double min) { this->min_speed = min;}
double userhorse::get_min() { return min_speed;}

void userhorse::set_level(int l) { this->level = l;}
int userhorse::get_level() { return level;}

void userhorse::set_points(int p) { this->points = p;}
int userhorse::get_points() {return points;}

int userhorse::get_wins() {return num_wins;}

//increments number of wins (call when race is won)
void userhorse::increment_wins() {this->num_wins++;}


//sets random race time in max_speed to min_speed interval (call before each race)
void userhorse::set_rand_race_time() { //TO DO
  
  double rand_n; 
  //method which assigns rand_n a val between max and min

  race_time = rand_n;
}