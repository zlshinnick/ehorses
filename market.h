#ifndef MARKET_H
#define MARKET_H
#include <string>
#include <iostream>
#include "userhorse.h"
#include<vector>
#include <algorithm>

using namespace std;

class market{
    private:
        vector<userhorse> storehorses; // Vector to store horses
        public:
        market(); // Default constructor
        void initialize(userhorse horse1, userhorse horse2, userhorse horse3, userhorse horse4, userhorse horse5); // Function to initialise market horses
        userhorse get_horse(); // Function to get a horse from the market
        void print_market(); // Function to print the market
        void welcome_market(); // Function to welcome the user to the market
};

#endif 