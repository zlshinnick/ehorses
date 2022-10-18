#ifndef STABLE_H
#define STABLE_H
#include "horse.h"
#include "userhorse.h"
#include "bred_horse.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>


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
        void stable_menu(double* bank);
        void change_name_menu();
        void level_up_menu(double* bank);

        userhorse* get_horse_for_race();
        //breeding functions 
        void set_parents();
      
        void breed();

        bool add_bred_horse(string _name);

        void breeding_ground_ascii();
        void get_horse_hof();
        void add_to_hof(int horse_choice);

};
#endif