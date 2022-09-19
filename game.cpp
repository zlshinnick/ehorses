#include "game.h"
#include <iostream>
using namespace std;



game::game(){
    choice = 0;
    playing = true;
}



int game::get_playing(){
    return playing;
}

void game::main_menu(){
    cout<< "************MAIN MENU TESTTTTTT******"<<endl;
    cout<< "0: Stables"<<endl;;
    cout<< "1: Race"<<endl;
    cout<< "2: Buy Horses"<<endl;
    cout<< "3: Stables"<<endl;
    cout<< "4: User Stats"<<endl;
    cout<< "9: Quit"<<endl;
    cout<<endl;
    cout<<"Choice:";


        cin>>choice;

        switch (choice){
            case 9:
                playing = false;
                break;
            default:
            break;
        }


}