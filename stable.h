#ifndef STABLE_H
#define STABLE_H
#include "horse.h"
#include "userhorse.h"
#include "bred_horse.h"
#include <algorithm>
#include <vector>
#include <iostream>

class stable{
    private:
        int num_of_horses;
        userhorse* array;
        int max;

        //breeding attributes
        userhorse p1;
        userhorse p2;

    public:
        stable();
        stable(int size);

        int get_current_num_horses();

        userhorse* get_horses();

        bool add_horse(userhorse h);

        void print_stable();
        void initialize();
        void stable_menu();

        //breeding functions 
        void set_parents();
      
        void breed();

        bool add_bred_horse(string _name);

        void breeding_ground_ascii();


};
#endif