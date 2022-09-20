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

void game::initialize_game(){
    string name;
    cout<< "Enter name for user: ";
    cin>>name;
        user.initialize(name);

}

void game::main_menu(){
    cout<< "************ MAIN MENU ******"<<endl;
    cout<< "0: Travel"<<endl;;
    cout<< "1: Level Up"<<endl;
    cout<< "2: User Stats"<<endl;
    cout<< "9: Quit"<<endl;
    cout<<endl;
    cout<<"Choice:";



        cin>>choice;

        switch (choice){
            case 2:
                user.print_user_stats ();
                break;
            case 9:
                playing = false;
                break;
            default:
            break;
        }


}