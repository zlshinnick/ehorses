#include <iostream>
#include <string>
#include "horse.h"
using namespace std;

	horse::horse() {
      name = "";
      division = 1;  
    }

	horse::horse(string _name, int d) {
      name = _name;
      division = d;  
    }


    void horse::set_name(string n) { name = n;}
    string horse::get_name() { return name;}

    void horse::set_div(int d) { division = d;}
    int horse::get_div() { return division;}
