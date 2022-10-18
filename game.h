#ifndef GAME_H
#define GAME_H

#include "user.h"
#include "shop.h"
#include "item.h"
#include <fstream>
#include "market.h"
#include "racetrack.h"

class game{
    private:
    // Choose what is happening in the game (ie. goto main menu)
        int choice;
    // Know when game has started
        bool playing;

        market market;
        User user; 
        shop shop;
        string file_name;
        Racetrack racetrack;

    public:
        game();
        // Functions
        void main_menu(); // Displays main menu
        void travel_menu(); // Displays travel menu
        void initialize_game(); // Initialises game
        void save_game(); // Saves game
        void load_game(); // Loads game
        void shop_menu(); // Displays shop menu
        void market_menu(); // Displays market menu
        void breed_menu(); // Displays breed menu
        void welcome(); // Displays welcome message
        void inventory_menu(); // Displays inventory menu
        void user_stats_menu(); // Displays user stats menu
        void get_level_up_menu(); // Displays level up menu
        void hof_menu(); // Displays hooves of fame menu
        
        void racetrack_menu(); // Displays racetrack menu
        // Accessors
        int get_playing(); // Returns playing status
};

#endif