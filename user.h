#ifndef USER_H
#define USER_H
#include "horse.h"
#include "stable.h"
#include "inventory.h"
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

        inventory inventory;
        stable stable;

    public:
        //constructors
        user();

        //functions
        void initialize(string user_name);
        void level_up();
        string get_as_string();
        void initialize_stable();
        void print_user_stats();
    
        //accessors
        string get_name();
        double get_bank_account();
        double get_prize_money();
        int get_wins();
        int get_exp();
        int get_exp_next_level();
        int get_level();

        //stable funcitons
        void add_horse_to_stable(horse new_horse);
        int get_num_horses();
        void print_stables();

        //inventory functions
        void purchase_item(item item);
        void print_inventory();

};
#endif
