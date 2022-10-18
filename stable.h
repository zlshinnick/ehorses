#ifndef STABLE_H
#define STABLE_H
#include "horse.h"
#include "userhorse.h"
#include "bred_horse.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>


class stable{
    private:
        int num_of_horses;
        userhorse* array;
        int max;

        // Breeding attributes
        userhorse p1;
        userhorse p2;

    public:
        stable(); // Default constructor
        stable(int size); // Constructor

        int get_current_num_horses(); // Returns number of horses in stable

        userhorse* get_horses(); // Returns array of horses in stable

        bool add_horse(userhorse h); // Adds horse to stable if there is space

        void print_stable(); // Prints stable
        void initialize(); // Initialises stable
        void stable_menu(double* bank); // Stable menu
        void change_name_menu(); // Change name menu
        void level_up_menu(double* bank); // Level up menu

        userhorse* get_horse_for_race(); // Returns horse for race
        
        // Breeding functions 
        void set_parents(); // Sets parents for breeding

        void breed(); // Breeds horses

        bool add_bred_horse(string _name); // Adds bred horse to stable

        void breeding_ground_ascii(); // Prints ascii art for breeding ground
        void get_horse_hof(); // Gets horse for hooves of fame
        void add_to_hof(int horse_choice); // Adds horse to hooves of fame


        void ~stable();
};

#endif