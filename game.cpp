#include "game.h"

#include <iostream>
using namespace std;

game::game() {
    choice = 0;
    playing = true;
    file_name = "gamesave.txt";
}

int game::get_playing() { return playing; }

void game::initialize_game() {
    //setting up user
     string name;
     cout << "Enter name for user: ";
     cin >> name;
     user.initialize(name);

    //setting up stables with first horse
    string horse_name;
    cout << "Enter name for Horse: ";
    cin >> horse_name; 
    userhorse h1 = userhorse();
    h1.set_userhorse(horse_name,10.5,13.5);
    user.add_horse_to_stable(h1);
    cout<<endl<<h1.get_name()<<" Has Been Added To Stables"<<endl;

    //creating shop
    item Carrot = item("Carrot",100,0.5,1); //carrot makes slowest time faster
    item Sugar = item("Sugar",100,0.5,1);   //sugar makes faster time faster
    item Saddle = item("Saddle",1000,0.5,10); //saddle increases both by 0.5
    shop.initialize(Carrot,Sugar,Saddle);


    //creating market
    userhorse m1 = userhorse();
    userhorse m2 = userhorse();
    userhorse m3 = userhorse();
    userhorse m4 = userhorse();
    userhorse m5 = userhorse();
    
    m1.set_userhorse("John",15.0,12.0);
    m1.set_price(100);
    m2.set_userhorse("Steve",14.75,12.0);
    m2.set_price(300);
    m3.set_userhorse("Bob",14.5,11.75);
    m3.set_price(600);
    m4.set_userhorse("Craig",14.25,11.5);
    m4.set_price(1000);

    m5.set_userhorse("Bullet",14,11);
    m5.set_price(1500);
    
    market.initialize(m1,m2,m3,m4,m5);

    
}



void game::travel_menu() {
    cout << endl;
    cout << "Where Would You Like to Travel?" << endl;
    cout << "1: Stables" << endl;
    cout << "2: Racetrack" << endl;
    cout << "3: Market" << endl;
    cout << "4: General Store" << endl;
    cout << "9: Return to Main Menu" << endl;

    cout << endl;
    cout << "Choice:";

   cin >> choice;

  switch (choice) {
        case 1:
            user.print_stables();
            cout << "9: Return to Main Menu" << endl;
            cout << endl;
            cout << "Choice:";
            cin >> choice;
            if (choice==9){
                main_menu();
            }
        case 2:
             break;
        case 3:
            market_menu();
             break;
        case 4:
            shop_menu();
             default:
            break;
        case 9:
             main_menu();
  }
}

void game::shop_menu(){
    shop.print_store();
    item new_item = shop.get_item();
    if(new_item.get_name()!=""){

    user.purchase_item(new_item);
}
}

void game::market_menu(){
    market.print_market();
    userhorse new_horse = market.get_horse();
  
    if(new_horse.get_name()!=""){

    user.purchase_horse(new_horse);
}
}


void game::main_menu() {
    cout<<"\n";
    cout << "************ MAIN MENU ******" << endl;
    cout << "0: Travel" << endl;
    cout << "1: Inventory" << endl;
    cout << "2: Level Up" << endl;
    cout << "3: User Stats" << endl;
    cout << "4: Save Game" << endl;
    cout << "5: Load Game" << endl;
    cout << "9: Quit" << endl;
    cout << endl;
    cout << "Choice:";

    cin >> choice;

    switch (choice) {
        case 0:
            travel_menu();

        case 1:
            user.print_inventory();

            cout << endl;
            cout << "9: Return to Main Menu" << endl;
            cout<<endl;
            
            cout << "Choice:";
            cin >> choice;
            if (choice == 9) {
                main_menu();
            }
            break;
        case 3:
            user.print_user_stats();
            cout << "9: Return to Main Menu" << endl;

            cout << endl;
            cout << "Choice:";
            cin >> choice;
            if (choice == 9) {
                main_menu();
            }

            break;
        case 4:
            save_game();
            break;
        case 5:
            break;
        case 9:
            playing = false;
            break;
        default:
            break;
    }
}

void game::save_game() {
    ofstream outFile(file_name);

    if (outFile.is_open()) {
        outFile << user.get_as_string();
    }
    outFile.close();
}

void game::load_game() {}