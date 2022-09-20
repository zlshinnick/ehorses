#include <iostream>
#include <string>
#include "horse.h"
using namespace std;

	horse::horse() {
      name = "";
      division = 3;
      race_time = 15;
    }

	horse::horse(string _name, int div, double time) {
      name = _name;
      division = div;  
      race_time = time;
    }

    void horse::set_name(string n) { name = n;}
    string horse::get_name() { return name;}

    void horse::set_div(int d) { division = d;}
    int horse::get_div() { return division;}
    double horse::get_racet() {return race_time;}

