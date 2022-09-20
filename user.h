#ifndef USER_H
#define USER_H
#include "horse.h"
#include "stable.h"
#include <iostream>
#include <string>
using namespace std;

class user{
    private:
        string name;
        double bank_account;
        int user_wins;
        double prize_money;
        int exp;
        int exp_next_level;
        int level;

        stable stable;
        horse horse;

        int num_horses;
        int allowed_num_horses;


    public:
    //constructors
    user();
    //functions
    void initialize(string user_name);
    void level_up();
    string get_as_string();

    void print_user_stats();
    //accessprs
    string get_name();
    double get_bank_account();
    double get_prize_money();
    int get_wins();
    int get_exp();
    int get_exp_next_level();
    int get_level();

    int get_num_horses();
    int get_allowed_num_horses();

    
    //modifiers
};
#endif
