#include "game.h"
#include "user.h"
#include "math.h"
#include "stable.h"
int main(){
    srand(time(NULL));


    game game;
    game.initialize_game();
    game.main_menu();   

    
}