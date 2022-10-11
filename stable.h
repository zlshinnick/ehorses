#ifndef STABLE_H
#define STABLE_H
#include "horse.h"
#include "userhorse.h"
#include <algorithm>
#include <vector>
#include <iostream>

class stable{
    private:
        int num_of_horses;
        userhorse* array;
        int max;
        userhorse mum;
        userhorse dad;

    public:
        stable();
        stable(int size);

        int get_current_num_horses();

        userhorse* get_horses();

        bool add_horse(userhorse h);

        void print_stable();
        void initialize();

        void set_dad();
        void set_mum();
        bool add_bred_horse();

};
#endif