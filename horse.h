#ifndef HORSE_H
#define HORSE_H

#include <string>
using namespace std;

class horse {
// This is an abstract class for all horses
  
  public:

    // Attributes
	  string name;         // all horses
    double race_time;    // all horses

  	double max_speed;    // Userhorse
    double min_speed;    // Userhorse
    int level;           // Userhorse
    int num_wins;        // Userhorse
    int generation;      // Userhorse
    int price;           // Userhorse

    // Contructors
    horse();

    // Set and get for name and race_time attributes
    void set_name(string n);
    string get_name();
    void set_race_t(double t);
    double get_race_t();

    // Prints all of horses attributes(mainly for testing) 
    void print_horse();

    // Virtual function to set race time of comphorses and userhorses
    virtual void set_rand_race_time() = 0;
};

#endif
