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

    //contructors
    horse();
	horse(string _name);

    //set and get for each attributes
    void set_name(string n);
    string get_name();

    void set_race_t(double t);
    double get_race_t();

};
#endif
