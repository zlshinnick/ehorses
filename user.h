#ifndef USER_H
#define USER_H

#include "horse.h"
#include "stable.h"
#include "inventory.h"
#include <iostream>
#include <string>
using namespace std;

class User {
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
        // Constructors
        User(); // Default constructor

        //functions
        void initialize(string user_name); // Function to initialise user
        void level_up(); // Function to level up user
        string get_as_string(); // Function to get user as string
        void initialize_stable(); // Function to initialise stable
        void print_user_stats(); // Function to print user stats
        void level_up_menu(); // Function to print level up menu
        void add_to_hof(); // Function to add user to hooves of fame
    
        // Accessors
        string get_name(); // Returns name of user
        double get_bank_account(); // Returns bank account of user
        double get_prize_money(); // Returns prize money of user
        int get_wins(); // Returns wins 
        int get_exp(); // Returns exp 
        int get_exp_next_level(); // Returns exp to next level
        int get_level(); // Returns level

        // Stable funcitons
        void add_horse_to_stable(userhorse new_horse); // Adds horse to stable
        int get_num_horses(); // Returns number of horses in stable
        void print_stables(); // Prints stables
        void breeding(); // Breeding function
        void call_stable_menu(); // Calls stable menu

        // Inventory functions
        void purchase_item(item item); // Purchases item
        void print_inventory(); // Prints inventory
        item boost_menu(); // Boost menu

        // Market functions
        void purchase_horse(userhorse horse); // Purchases horse

        // Racing win function
        void user_wonD1(); // Function to add to user stats if they win division 1
        void user_wonD2(); // Function to add to user stats if they win division 2
        void user_wonD3(); // Function to add to user stats if they win division 3
    

        void delete_stable(); // deleteing the dyanmic memory of stable
        userhorse* get_horse_for_race(); // Returns horse for race
};

#endif