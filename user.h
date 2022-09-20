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
        double prize_money;
        int exp;
        int exp_next_level;
        int level;

        int num_horses;
        int allowed_num_horses;


    public:
    //constructors
    user();
    //functions
    void initialize(string user_name);
    void level_up();

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
