#include "game.h"
#include "user.h"
#include "math.h"
#include "stable.h"
int main(){
    srand(time(NULL));


    game game;
    game.initialize_game();


    //making horse and adding to stable is working 
    horse h1 =  horse("horse1");
    stable user_stables = stable();



    user_stables.add_horse(h1);
    user_stables.print_stable();

    while (game.get_playing()==true){
        game.main_menu();   

    }
}