#ifndef HORSE_H
#define HORSE_H
#include <string>
using namespace std;

class horse {
public:

	string name;
	double max_speed;
    double min_speed;
    int level;

    horse();
	horse(string _name, double max, double min, int l);

    void set_max(double max);
    void set_min(double min);
    void set_name(string n);
    void set_level(int l);
    
    double get_max();
    double get_min();
    string get_name();
    int get_level();

};
#endif
