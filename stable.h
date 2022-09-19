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
        vector<int> stable;

    public:
        userhorse breed_horses(userhorse, userhorse);
        vector add_horse();
                


};
#endif
