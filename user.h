#include "horse.h"
#include "stable.h"
#include "inventory.h"
#include <iostream>
#pragma once
#include <string>
using namespace std;

class User{
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
        User();

        //functions
        void initialize(string user_name);
        void level_up();
        string get_as_string();
        void initialize_stable();
        void print_user_stats();
        void level_up_menu();
        void add_to_hof();
    
        //accessors
        string get_name();
        double get_bank_account();
        double get_prize_money();
        int get_wins();
        int get_exp();
        int get_exp_next_level();
        int get_level();

        //stable funcitons
        void add_horse_to_stable(userhorse new_horse);
        int get_num_horses();
        void print_stables();
        void breeding();
        void call_stable_menu();

        //inventory functions
        void purchase_item(item item);
        void print_inventory();
        item boost_menu();

        //market functions
        void purchase_horse(userhorse horse);

        // racing win function
        void user_wonD1();
        void user_wonD2();
        void user_wonD3();
    


        userhorse* get_horse_for_race();
};