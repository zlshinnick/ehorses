#ifndef USER_H
#define USER_H
#include "horse.h"
#include <iostream>
#include <string>
using namespace std;

class user{
    private:
        string name;
        double bank_account;
    public:
        user();
        double update_bank();
        int feed_horse();
        int place_bet();
 
};
#endif
