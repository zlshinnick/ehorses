#include <iostream>
#include <string>
#include "horse.h"
#include "userhorse.h"
using namespace std;

//default constructor
userhorse::userhorse() {         //TO DO
}

userhorse::userhorse(double max, double min, int l) {    //TO DO
}

//get and set functions
void userhorse::set_max(double max){ max_speed = max;}
double userhorse::get_max() { return max_speed;}

void userhorse::set_min(double min) { min_speed = min;}
double userhorse::get_min() { return min_speed;}

void userhorse::set_level(int l) { level = l;}
int userhorse::get_level() { return level;}