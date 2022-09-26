
#ifndef GAME_H
#define GAME_H
#include "user.h"
#include "shop.h"
#include "item.h"
#include <fstream>

class game{
    private:
    //choose what is happening in the game (ie. goto main menu)
        int choice;
    //know when game has started
        bool playing;

        user user; 
        shop shop;
        string file_name;

    public:
        game();

        //operators

        //functions
        void main_menu();
        void travel_menu();
        void initialize_game();
        void save_game();
        void load_game();
        void shop_menu();

        //accecssors
        int get_playing();
        //modifys



};

#endif