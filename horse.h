#pragma once
#include <string>
using namespace std;

class horse {
//this is a abstract class for all horses
  
  public:

    //attributes
	  string name;         //all horses
    double race_time;    //all horses

  	double max_speed;    //userhorse
    double min_speed;    //userhorse
    int level;           //userhorse
    int num_wins;        //userhorse
    int generation;      //userhorse
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

    //virtual function to set race time of comphorses and userhorses
    virtual void set_rand_race_time() = 0;

};
