#include <iostream>
#include <string>
#include "horse.h"
using namespace std;

  //default constructor (not to be used)
	horse::horse() {
      name = "";
      race_time = 15;
    }

  //normal constructor (use this if creating horse)
	horse::horse(string _name) {
      name = _name; 
      race_time = 15;
    }

  //get and set each attribute
    void horse::set_name(string n) { this->name = n;}
    string horse::get_name() { return name;}

    void horse::set_race_t(double t) { this->race_time = t;}
    double horse::get_race_t() {return race_time;}

    

