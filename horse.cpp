#include <iostream>
#include <string>
#include "horse.h"
using namespace std;

  //default constructor (not to be used)
	horse::horse() {
      name = "THIS IS AN ERROR";
    }

  //get and set each attribute
    void horse::set_name(string n) { this->name = n;}
    string horse::get_name() { return name;}

    void horse::set_race_t(double t) { this->race_time = t;}
    double horse::get_race_t() {return race_time;}

    void horse::print_horse() {
      cout << "Name: " << name << endl;
      cout << "Max Speed: " << max_speed << endl;
      cout << "Level: " << level << endl;
      cout << "Points: " << points << endl;
      cout << "Number of Wins: " << num_wins << endl<<endl;

    }

    


    

