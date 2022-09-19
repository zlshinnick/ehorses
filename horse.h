#ifndef HORSE_H
#define HORSE_H
#include <string>
using namespace std;

class horse {
public:

    //attributes
	string name;
    int division;
    double race_time;    //note: race time will be left uninitialised until sub_class

    //contructors
    horse();
    horse(string _name, int d);

    //set each attribuye
    void set_name(string n);
    string get_name();

    void set_div(int d);
    int get_div();


};
#endif
