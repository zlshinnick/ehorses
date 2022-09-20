#include "game.h"

int main(){
    game game;
    game.initialize_game();
    
    while (game.get_playing()==true){
        game.main_menu();   

    }
}