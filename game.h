
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
    //choose what is happening in the game (ie. goto main menu)
        int choice;
    //know when game has started
        bool playing;

        market market;
        User user; 
        shop shop;
        string file_name;
        Racetrack racetrack;

    public:
        game();
        int division;

        //operators

        //functions
        void main_menu();
        void travel_menu();
        void initialize_game();
        void save_game();
        void load_game();
        void shop_menu();
        void market_menu();
        void breed_menu();
        void welcome();
        void inventory_menu();
        void user_stats_menu();
        void get_level_up_menu();
        
        void racetrack_menu();
        //accecssors
        int get_playing();
        //modifys



};

#endif