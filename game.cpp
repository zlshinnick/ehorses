#include "game.h"
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

game::game() {
    //choice = 0;
    playing = true;
    file_name = "gamesave.txt";
}

int game::get_playing() { return playing; }

void game::initialize_game() {
    //setting up user
     welcome();
     string name;
     cout << "Enter Name For User: ";
     cin >> name;
     user.initialize(name);

    //setting up stables with first horse
    string horse_name;
    cout << "Enter Name For Your First Horse: ";
    cin.ignore();
    getline (cin,horse_name);

    userhorse h1 = userhorse();
    h1.set_userhorse(horse_name,50.5,51.7);
    user.add_horse_to_stable(h1);
    this_thread::sleep_for(chrono::seconds(2));
    cout<<endl<<h1.get_name()<<" Has Been Added To Stables"<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    system("Clear");

    //creating shop
    item Carrot = item("Carrot",100,0.5); //carrot makes slowest time faster
    item Sugar = item("Sugar",100,0.5);   //sugar makes faster time faster
    item Saddle = item("Apple",1000,1); //saddle increases both by 0.5
    shop.initialize(Carrot,Sugar,Saddle);


    //creating market
    userhorse m1 = userhorse();
    userhorse m2 = userhorse();
    userhorse m3 = userhorse();
    userhorse m4 = userhorse();
    userhorse m5 = userhorse();
    
    m1.set_userhorse("Rookie",12.0,15.0);
    m1.set_price(100);
    m2.set_userhorse("Intermediate",12.0,14.75);
    m2.set_price(300);
    m3.set_userhorse("Superstar",11.75,14.5);
    m3.set_price(600);
    m4.set_userhorse("Ledgendary",11.5,14.25);
    m4.set_price(1000);
    m5.set_userhorse("Bullet",11,14);
    m5.set_price(1500);
    
    market.initialize(m1,m2,m3,m4,m5);

    
}


void game::travel_menu() {
    system("Clear");
    cout << "Where Would You Like to Travel?" << endl;
    cout << "1: Stables" << endl;
    cout << "2: Racetrack" << endl;
    cout << "3: Market" << endl;
    cout << "4: General Store" << endl;
    cout << "5: Breeding Ground"<<endl;
    cout << "9: Return to Main Menu" << endl;

    int user_choice_travel;
    bool input = false;

    while (input == false) {
        cout <<"Choice:" ;
        cin >> user_choice_travel;

        if (user_choice_travel != 1 && user_choice_travel != 2 && user_choice_travel != 3 && user_choice_travel != 4 && user_choice_travel != 5 && user_choice_travel != 6 && user_choice_travel != 9) {
            cout << "Invalid!\n\n";
            this_thread::sleep_for(chrono::seconds(1));
            
        } else {
            input = true;
        }
}

    switch (user_choice_travel) {
        case 1:
            user.call_stable_menu();
            break;
        case 2:
            racetrack_menu();
             break;
        case 3:
            market_menu();
             break;
        case 4:
            shop_menu();
            break;
        case 5: 
            breed_menu();
            break;
        case 9:
            return;
  }

}

void game::shop_menu(){
    int return_shop;
    shop.print_store();
    item new_item = shop.get_item();
    if(new_item.get_name()!=""){

    user.purchase_item(new_item);
}
    cout<<"Press 9 to Return To Main Menu: ";
    cin>>return_shop;

    if(return_shop==9){
        return;
    }

    while(return_shop!=9){
        cout<<"Invalid Input!";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"\n\nPress 9 to Return To Main Menu: ";
        cin>>return_shop;
    }
}

void game::market_menu(){
    
    int return_market;
    market.print_market();
    userhorse new_horse = market.get_horse();
  
    if(new_horse.get_name()!=""){
    user.purchase_horse(new_horse);

}
    cout<<"Press 9 to Return To Main Menu: ";
    cin>>return_market;

    if(return_market==9){
        return;
    }

    while(return_market!=9){
        cout<<"Invalid Input!";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"\n\nPress 9 to Return To Main Menu: ";
        cin>>return_market;
    }
}


void game::main_menu() {
    bool playing = true;
    while (playing == true){
    system("Clear");
    cout << "************ MAIN MENU ******" << endl;
    cout << "1: Travel" << endl;
    cout << "2: Inventory" << endl;
    cout << "3: Level Up" << endl;
    cout << "4: User Stats" << endl;
    cout << "5: Save Game" << endl;
    cout << "6: Load Game" << endl;
    cout << "9: Quit" << endl;
    cout << endl;
    

    int user_choice;

    bool input = false;

    while (input == false) {
        cout <<"Choice:" ;
        cin >> user_choice;

        if (user_choice != 1 && user_choice != 2 && user_choice != 3 && user_choice != 4 && user_choice != 5 && user_choice != 6 && user_choice != 9) {
            cout << "Invalid!\n\n";
            this_thread::sleep_for(chrono::seconds(3));
            break;
        } else {
            input = true;
        }
}
    switch (user_choice) {
        case 1:
            travel_menu();
            break;
        case 2:
            inventory_menu();
            break;
        case 3:
            get_level_up_menu();
            break;
        case 4:
            user_stats_menu();
            break;
        case 5:
            save_game();
            break;
        case 6:
            break;
        case 9:
            playing = false;
            break;
    }
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

void game::breed_menu(){
    int return_breed;
    user.breeding();

    cout<<"\n\nPress 9--- to Return To Main Menu: ";
    cin>>return_breed;
    if(return_breed==9){
        return;
    }

    while(return_breed!=9){
        cout<<"Invalid Input!";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"\n\nPress 9 to Return To Main Menu: ";
        cin>>return_breed;
    }
}

void game::welcome(){
    
    system("Clear");
    cout<< "/$$      /$$           /$$"   <<endl;
    cout<< "| $$  /$ | $$          | $$" <<endl;
    cout<< "| $$ /$$$| $$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$ "<<endl;
    cout<< "| $$/$$ $$ $$ /$$__  $$| $$ /$$_____/ /$$__  $$| $$_  $$_  $$ /$$__  $$" <<endl;
    cout<< "| $$$$_  $$$$| $$$$$$$$| $$| $$      | $$  | $$| $$ | $$ | $$| $$$$$$$$"<<endl;
    cout<< "| $$$/ |  $$$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/" <<endl;
    cout<< "| $$/   |  $$|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  $$$$$$$" <<endl;
    cout<< "|__/     |_/ |_______/|__/ |_______/ |______/ |__/ |__/ |__/ |_______/" <<endl;
    this_thread::sleep_for(chrono::seconds(1));

    cout<< "                       /$$$$$$$$   "<<endl;
    cout<< "                      |__  $$__/    "<<endl;
    cout<<"                          | $$  /$$$$$$ "<<endl;
    cout<<"                          | $$ /$$__  $$"<<endl;
    cout<<"                          | $$| $$  | $$"<<endl;
    cout<<"                          | $$| $$  | $$"<<endl;
    cout<<"                          | $$|  $$$$$$/"<<endl;
    cout<<"                          |__/|______/ "<<endl;
    this_thread::sleep_for(chrono::seconds(1));

    cout<<"/$$$$$$$$|      /$$   /$$  /$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$$$  /$$$$$$  /$$"<<endl;
    cout<<"| $$_____/      | $$  | $$ /$$__  $$| $$__  $$ /$$__  $$| $$_____/ /$$__  $$| $$"<<endl;
    cout<<"| $$            | $$  | $$| $$  | $$| $$  | $$| $$  |__/| $$      | $$  |__/| $$"<<endl;
    cout<<"| $$$$$         | $$$$$$$$| $$  | $$| $$$$$$$/|  $$$$$$ | $$$$$   |  $$$$$$ | $$"<<endl;
    cout<<"| $$__/         | $$__  $$| $$  | $$| $$__  $$ |____  $$| $$__/   |____  $$|__/"<< endl;
    cout<<"| $$            | $$  | $$| $$  | $$| $$  | $$ /$$  | $$| $$       /$$  | $$    "<<endl;
    cout<<"| $$$$$$$$      | $$  | $$|  $$$$$$/| $$  | $$|  $$$$$$/| $$$$$$$$|  $$$$$$/ /$$"<<endl;
    cout<<"|________/      |__/  |__/ |______/ |__/  |__/ |______/ |________/ |______/ |__/"<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    system("Clear");
}

void game::inventory_menu(){
    user.print_inventory();
    int leave;

    cout<<"\n\nPress 9 to Return To Main Menu: ";
    cin>>leave;
    if(leave==9){
        return;
    }

    while(leave!=9){
        cout<<"Invalid Input!";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"\n\nPress 9 to Return To Main Menu: ";
        cin>>leave;
    }
}

void game::user_stats_menu(){
    
    int leave_stats;
    
    user.print_user_stats();

    cout<<"\n\nPress 9 to Return To Main Menu: ";
    cin>>leave_stats;
    if(leave_stats==9){
        return;
    }

    while(leave_stats!=9){
        cout<<"Invalid Input!";
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"\n\nPress 9 to Return To Main Menu: ";
        cin>>leave_stats;
    }
}

void game::racetrack_menu(){
    system("Clear");
    
    cout<<"** Welcome To The Racetrack **\n\n";

    //get division to pass into functions
    int division;
bool input = false;

while (input == false) {
    cout<<"\n** Choose The Division You Wish To Race In **";
    this_thread::sleep_for(chrono::seconds(1));
    cout<< "\n\n* Divison 1: Easy \n* Division 2: Medium \n* Division 3: Hard";

    this_thread::sleep_for(chrono::seconds(1));
    cout<<"\n\n* Divison 1 *";
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"\nPrize Money = 500 for win";
    cout<<"\nExp = 100 for win";
    
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"\n\n* Divison 2 *";
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"\nPrize Money = 1000 for win";
    cout<<"\nExp = 250 for win";

    this_thread::sleep_for(chrono::seconds(1));
    cout<<"\n\n* Divison 3 *";
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"\nPrize Money = 1500 for win";
    cout<<"\nExp = 500 for win";

    this_thread::sleep_for(chrono::seconds(1));
    cout << "\n\nChoose Your Race Division: " << endl;
    cin >> division;

    if (division != 1 && division != 2 && division != 3) {
            cout << "Invalid\n\n";
    } else {
        input = true;
    }
}
    userhorse* ptr = user.get_horse_for_race();

    cout<<"\n Do You Want To Add A Boost To Your Horse ";
    int boost_choice;
    cout<<"\n\n 1. Yes";
    cout<<"\n 2. No";
    cout<<"\n\n Choice: ";
    cin>>boost_choice;
    // add while to check if valid inout

    double boost_amount;
    if(boost_choice == 1){
        item boost = user.boost_menu();
        boost_amount = boost.get_boost();
    }

    srand(time(NULL));
    comphorse c1;
    
    c1.set_div(division);
    c1.set_bot_names(division);
    c1.set_rand_race_time();

    User* user_ptr = &user;

    racetrack.get_winner(c1, ptr, user_ptr, boost_amount);
    this_thread::sleep_for(chrono::seconds(5));

    return;
}

void game:: get_level_up_menu() {
    user.level_up_menu();
}