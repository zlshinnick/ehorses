#include <iostream>
#include <string>
#include <ctime>
#include "horse.h"
#include "userhorse.h"
using namespace std;

//default constructor
userhorse::userhorse() {
  this->name="";
  this->max_speed = 0;
  this->min_speed = 0;
  this->level = 1;
  this->points = 0;
  this->num_wins = 0;
  this->generation = 1;
  int num_wins_test = 0;
}

//setting userhorse variables (esstenitally a constructor)
void userhorse::set_userhorse(string _name, double max, double min) { //, string _gender) {
  this->name=_name;
  this->max_speed = max;
  this->min_speed = min;
  this->level = 1;
  this->points = 0;
  this->num_wins = 0;
  this->generation = 1;
  //this->gender=_gender;
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

void userhorse::set_price(int _price) { this->price = _price;}
int userhorse::get_price() { return price;}

int userhorse::get_wins() {return num_wins;}

int userhorse::get_generation() {return generation;}

void userhorse::output_name() {cout << name << endl;}

void userhorse::output_max() {cout << max_speed << endl;}

void userhorse::output_min() {cout << min_speed << endl;}

void userhorse::output_wins() {cout << num_wins_test << endl;}

//string userhorse:: get_gender() {return gender;}


//increments number of wins (call when race is won)
void userhorse::increment_wins() {this->num_wins++;}

int userhorse::increment_wins_test() {return num_wins_test++;}

//sets random race time in max_speed to min_speed interval (call before each race)
void userhorse::set_rand_race_time() {
  
  //getting min and max from horse
  double dmin = this->min_speed;
  double dmax = this->max_speed;

  //converting to int to generate random num  
  int min = dmin * 10;
  int max = dmax * 10;
  int range = max - min;

  //generate random num
  double random =min + (rand() % range);
  random = random / 10; //convert back to one decimal place

  //calling function to set_race_t
  set_race_t(random);
}

//for when user horse levels up
void userhorse::level_up() {
  if (level < 3) {
    this->max_speed = max_speed - 1;
    this->min_speed = min_speed - 1;
    this->level = level + 1;
    return;
  } else {
    return;
  }
}

void userhorse::add_boost(double t) {
    this->race_time = race_time - t;
}