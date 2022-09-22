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
        horse* array;
        int max;

    public:
        stable();
        stable(int size);

        int get_current_num_horses();

        horse* get_horses();

        bool add_horse(horse h);

        void print_stable();

};
#endif