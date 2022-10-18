#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
#include <thread>
#include "horse.h"
#include "userhorse.h"
using namespace std;

// Default constructor
userhorse::userhorse() {
  this->name = "";
  this->max_speed = 0;
  this->min_speed = 0;
  this->level = 1;
  this->num_wins = 0;
  this->generation = 1;
  int num_wins_test = 0;
}

// Setting userhorse variables (esstenitally a constructor)
void userhorse::set_userhorse(string _name, double max, double min) {
  this->name = _name;
  this->max_speed = max;
  this->min_speed = min;
  this->level = 1;
  this->num_wins = 0;
  this->generation = 1;
}

// Get and set functions for attributes of userhorse
void userhorse::set_max(double max){ this->max_speed = max;}
double userhorse::get_max() { return max_speed;}

void userhorse::set_min(double min) { this->min_speed = min;}
double userhorse::get_min() { return min_speed;}

void userhorse::set_level(int l) { this->level = l;}
int userhorse::get_level() { return level;}

void userhorse::set_price(int _price) { this->price = _price;}
int userhorse::get_price() { return price;}

int userhorse::get_wins() {return num_wins;}
int userhorse::get_generation() {return generation;}

// Print functions
void userhorse::output_name() {cout << name << endl;} // Outputs name
void userhorse::output_max() {cout << max_speed << endl;} // Outputs max speed
void userhorse::output_min() {cout << min_speed << endl;} // Outputs min speed
void userhorse::output_wins() {cout << num_wins << endl;} // Outputs number of wins

// Functions for in game features
void userhorse::increment_wins() {this->num_wins++;} // Increments num_wins by 1

void userhorse::level_up() { // Levels up
  if (level < 3) {
    this->max_speed = max_speed + 1;
    this->min_speed = min_speed + 1;
    this->level = level + 1;
    cout << "\nLevel Up Success! " << endl;;
    return;
  } else {
    cout << "Horse Is Already Maximum Level!";
    this_thread::sleep_for(chrono::seconds(1));\
    return;
  }
}

void userhorse::add_boost(double t) {
    this->race_time += t;
}

// Virtual function which sets random race time before each race
void userhorse::set_rand_race_time() {
  
  // Getting min and max from horse
  double dmin = this->min_speed;
  double dmax = this->max_speed;

  // Converting to int to generate random num  
  int min = dmin * 10;
  int max = dmax * 10;
  int range = max - min;

  // Generate random num
  double random =min + (rand() % range);
  random = random / 10; // Convert back to one decimal place

  // Calling function to set_race_t
  set_race_t(random);
}

// Functions for when horse wins a respective race
void userhorse::win_D1() {this->num_wins += 1;}
void userhorse::win_D2() {this->num_wins += 1;}
void userhorse::win_D3() {this->num_wins += 1;}