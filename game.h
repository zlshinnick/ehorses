#ifndef GAME_H
#define GAME_H

class game{
    private:
    //choose what is happening in the game (ie. goto main menu)
        int choice;
    //know when game has started
        bool playing;


    public:
        game();

        //operators

        //functions
        void main_menu();

        //accecssors
        int get_playing();
        //modifys



};

#endif