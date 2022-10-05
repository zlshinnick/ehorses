#ifndef MARKET_H
#define MARKET_H
#include <string>
#include <iostream>
#include  "userhorse.h"
#include<vector>
#include <algorithm>

using namespace std;

class market{
    private:
        vector<userhorse> storehorses;
        public:
        market();
        void initialize(userhorse horse1, userhorse horse2, userhorse horse3, userhorse horse4, userhorse horse5);
        userhorse get_horse();
        void print_market();

};

#endif 