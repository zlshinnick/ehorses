#include <iostream>
#include <string>
#include "horse.h"
using namespace std;

// Default constructor (not to be used)
horse::horse() {
  name = "THIS IS AN ERROR";
}

// Get and set each attribute
void horse::set_name(string n) { this->name = n;}
string horse::get_name() { return name;}

void horse::set_race_t(double t) { this->race_time = t;}
double horse::get_race_t() {return race_time;}

// General print horse function
void horse::print_horse() {
  cout << "Name: " << name << endl;
  cout << "Top Speed: " << max_speed << endl;
  cout << "Level: " << level << endl;
  cout << "Number of Wins: " << num_wins << endl;
  cout << "Generation: Gen " << generation <<endl<<endl;
}

    


    

