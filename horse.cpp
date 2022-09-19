#include <iostream>
#include <string>
#include "horse.h"
using namespace std;

	horse::horse() {
      name = "";
      max_speed = 0;
      min_speed = 0;
      level = 1;  
    }

	horse::horse(string _name, double max, double min, int l) {
      name = _name;
      max_speed = max;
      min_speed = min;
      level = l;  
    }

    void horse::set_max(double max){ max_speed = max;}
    void horse::set_min(double min) { min_speed = min;}
    void horse::set_name(string n) { name = n;}
    void horse::set_level(int l) { level = l;}

    double horse::get_max() { return max_speed;}
    double horse::get_min() { return min_speed;}
    string horse::get_name() { return name;}
    int horse::get_level() { return level;}

