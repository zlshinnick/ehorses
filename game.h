#ifndef GAME_H
#define GAME_H
#include "user.h"
class game{
    private:
    //choose what is happening in the game (ie. goto main menu)
        int choice;
    //know when game has started
        bool playing;

        user user;


    public:
        game();

        //operators

        //functions
        void main_menu();
        void travel_menu();
        void initialize_game();

        //accecssors
        int get_playing();
        //modifys



};

#endif