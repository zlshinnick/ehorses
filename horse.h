#ifndef HORSE_H
#define HORSE_H
#include <string>
using namespace std;

class horse {
//this is a general class for all horses
  
  public:

    //attributes
	string name;
    double race_time; 
  	double max_speed;
    double min_speed;
    int level;
    int points;   
    int num_wins;

    //contructors
    horse();
	horse(string _name);

    //set and get for name and race_time attributes
    void set_name(string n);
    string get_name();
    void set_race_t(double t);
    double get_race_t();

};
#endif
