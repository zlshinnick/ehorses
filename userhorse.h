#ifndef USERHORSE_H
#define USERHORSE_H

#include <string>
#include "horse.h"

using namespace std;

class userhorse : public horse {

  public:

    userhorse(); // Default constructor

    // Setting userhorse variables (esstenitally a constructor)
    void set_userhorse(string _name, double max, double min);

    // Get and set each attribute
    void set_max(double max); // Sets max speed
    void set_min(double min); // Sets min speed
    void set_level(int l); // Sets level
    void set_price(int _price); // Sets price
    double get_max(); // Returns max speed
    double get_min(); // Returns min speed
    int get_level(); // Returns level 
    int get_wins(); // Returns number of wins 
    int get_price(); // Returns price
    int get_generation(); // Returns generation
    
    // Print functions
    void output_name(); // Outputs name
    void output_min(); // Outputs min speed
    void output_max(); // Outputs max speed
    void output_wins(); // Outputs number of wins

    // In game functions
    void increment_wins(); // Increments num_wins by 1
    void level_up(); // Levels up
    void add_boost(double t); // Adds boost

    // Sets random race time in max_speed to min_speed interval (call before each race)
    void set_rand_race_time();
    
    // Functions for when each division is won
    void win_D1(); // When division 1 is won
    void win_D2(); // When division 2 is won
    void win_D3(); // When division 3 is won

};

#endif