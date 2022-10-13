#include <string>
#include "horse.h"
#pragma once
using namespace std;

class userhorse : public horse {

  public:

    userhorse();
    int num_wins_test;

    //setting userhorse variables (esstenitally a constructor)
    void set_userhorse(string _name, double max, double min); //, string _gender);

    //get and set each attribute
    void set_max(double max);
    void set_min(double min);
    void set_level(int l);
    void set_points(int p);
    void set_price(int _price);
    double get_max();
    double get_min();
    int get_level();
    int get_points();
    int get_wins();
    int get_price();
    int get_generation();
    void output_name();
    void output_min();
    void output_max();
    void output_wins();
    //string get_gender();

    int increment_wins_test();

    //in game functions
    void increment_wins();
    void level_up();
    void add_boost(double t);

    //sets random race time in max_speed to min_speed interval (call before each race)
    void set_rand_race_time();
    
    void win_D1();
    void win_D2();
    void win_D3();
};