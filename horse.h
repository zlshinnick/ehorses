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

    set_max(double max);
    set_min(double min);
    set_name(string n);
    set_level(int l);
    get_max();
    get_min();
    get_name();
    get_level();

};
#endif
