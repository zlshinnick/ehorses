#pragma once
#include <string>
using namespace std;

class horse {
//this is a general class for all horses
  
  public:

    //attributes
	  string name;         //all horses
    double race_time;    //all horses
  	double max_speed;    //userhorse
    double min_speed;    //userhorse
    int level;           //userhorse
    int points;          //userhorse    //probably will delete points
    int num_wins;        //userhorse
    string generation;   //userhorse
    int price;           //userhorse

    //contructors
    horse();

    //set and get for name and race_time attributes
    void set_name(string n);
    string get_name();

    void set_race_t(double t);
    double get_race_t();

    //prints all of horses attributes(mainly for testing) 
    void print_horse();

    virtual void set_rand_race_time() = 0;

};
