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
        int user_wins;
        int exp;
        int exp_next_level;
        int level;
        int allowed_num_horses;


    public:
    //constructors
        user();
    //functions
    void level_up();
    //accessprs
    string get_name();
    double get_bank_account();
    int get_wins();
    int get_wins();
    int get_exp();
    int get_exp_next_level();
    int get_level();

    
    //modifiers
};
#endif
