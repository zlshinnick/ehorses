#include "game.h"
#include "user.h"
#include "math.h"
int main(){
    srand(time(NULL));


    game game;
    game.initialize_game();
     
    while (game.get_playing()==true){
        game.main_menu();   

    }
}