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
        vector  <horse> stables;
        int capacity;

    public:
        stable();
        ~stable();
        void stable_initalize();
        userhorse breed_horses(userhorse, userhorse);
        void add_horse(horse);
                


};
#endif
