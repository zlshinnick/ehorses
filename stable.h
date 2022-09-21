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
        vector  <userhorse> stables;
        int capacity;

    public:
        stable();
        userhorse breed_horses(userhorse, userhorse);
        void add_horse(userhorse);
        userhorse operator[](const int index);
        void initialize();

};
#endif