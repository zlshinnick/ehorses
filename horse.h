#ifndef HORSE_H
#define HORSE_H
#include <string>
using namespace std;

class horse {
//this is a general class for all horses
  
  public:

    //attributes
	string name;
    int division;
    double race_time;    

    //contructors
    horse();
	horse(string _name, int div, double time);

    //set and get for each attributes
    void set_name(string n);
    string get_name();

    void set_div(int d);
    int get_div();

    double get_racet();

};
#endif
