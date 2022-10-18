#include "user.h"
#include <math.h>
#include <chrono>
#include <thread>

User::User() { // Default constructor
    name = "";
    bank_account = 0;
    user_wins = 0;
    exp = 0;
    exp_next_level = 0; 
    prize_money = 0.0;
}

void User::initialize(string user_name) { // Function to initialise user
    name = user_name;
    bank_account = 10000;
    user_wins = 0;
    exp = 0;
    level = 1;
    stable.initialize();

    exp_next_level = static_cast <int> // Type casting to ensure its a int
      ((50 * pow(level, 3)) - 
       (150 * pow(level, 2)) + 
         (400 * level)) / 3;; 
    prize_money = 0.0;
}

string User::get_name() { // Returns name of user
    return name;
}

double User::get_bank_account() { // Returns bank account of user
    return bank_account;
}

double User::get_prize_money() { // Returns prize money of user
    return prize_money;
}

int User::get_wins() { // Returns wins
    return user_wins;
}

int User::get_exp() { // Returns exp
    return exp;
}

int User::get_exp_next_level() { // Returns exp to next level
    return exp_next_level;
}

int User::get_level() { // Returns level
    return level;
}



void User::print_user_stats() { // Function to print user stats
    cout << endl;
    cout << "*** Player Details ***" << endl;
    cout << "* Name: " << name << endl;
    cout << "* Bank Account: " << get_bank_account() << endl;
    cout << "* Level: " << get_level() << endl;
    cout << "* Horses In Stable: " << stable.get_current_num_horses() << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout <<"\n****************************\n" << endl;
    cout << "* Exp: " << get_exp() << endl;
    cout << "* Exp For Next Level: "<< get_exp_next_level() << endl;    
    cout << "* Total Wins: "<< get_wins() << endl;
    cout << "* Prize Money: "<< get_prize_money() << endl;
}

void User::level_up() { // Function to level up user
    if (exp >= exp_next_level) {
        level++;
        exp = exp-exp_next_level;
        exp_next_level = static_cast <int> 
            ((50 * pow(level, 3)) - 
            (150 * pow(level, 2)) + 
            (400 * level)) / 3;
    }
}

string User::get_as_string() { // Function to return stats as string
  return name + " "
    + to_string(bank_account) + " "
    + to_string(user_wins) + " "
    + to_string(exp) + " "
    + to_string(exp_next_level) + " "
    + to_string(level) + " ";
}

void User::add_horse_to_stable(userhorse new_horse) { // Function to add horse to stable
    stable.add_horse(new_horse);
}

int User::get_num_horses() { // Function to return number of horses in stable
    return stable.get_current_num_horses();
}

void User::print_stables() { // Function to print stable
    stable.print_stable();
}

void User::purchase_item(item item) { // Function to purchase item
    int price = item.get_price();

    if (bank_account >= price) {
        inventory.add_item(item);
        bank_account -= item.get_price();
        cout << "\nRemaining Bank Account is $" << bank_account << endl;
        this_thread::sleep_for(chrono::seconds(1));
    } else {
        cout << "Not Enough Funds For Purchase of " << item.get_name() << endl;
    }
}

void User::print_inventory() { // Function to print inventory
    if (inventory.get_num_items() != 0) {
        inventory.print_inventory();
    } else { 
        cout << "\nInventory is Empty!";
    }
}

void User::purchase_horse(userhorse horse) { // Function to purchase horse
    int price = horse.get_price();

        if (bank_account >= price) {
        stable.add_horse(horse);
        bank_account -= horse.get_price();
        cout << "\nA "<<horse.get_name() << " Horse Has Been Succesfully Purchased" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\nRemaining Bank Account is $" << bank_account << endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout << horse.get_name() << " Is Now In Your Stables" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\nTravel To Your Stables To Name Your New Horse\n\n";
        this_thread::sleep_for(chrono::seconds(1));

    } else {
        cout << "Not Enough Funds For Purchase of " << horse.get_name() << endl;
    }
}

void User::breeding() { // Function to breed horses
    stable.breed();
    return;
}

void User::call_stable_menu() { // Function to call stable menu
    stable.stable_menu(&bank_account);
    return;
}

void User::user_wonD1() { // Function to add exp and prize money if user wins division 1
    bank_account += 500;
    user_wins++;
    prize_money += 500;
    exp += 100;
}

void User::user_wonD2() { // Function to add exp and prize money if user wins division 2
    bank_account += 1000;
    user_wins++;
    prize_money += 1000;
    exp += 250;
}

void User::user_wonD3() { // Function to add exp and prize money if user wins division 3
    bank_account += 1500;
    user_wins++;
    prize_money += 1500;
    exp += 500;
}

userhorse* User::get_horse_for_race(){
    return stable.get_horse_for_race();
}


void User::level_up_menu() { // Function to level up menu
    system("Clear");
    cout << "** Level Up Menu **";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\n\nCurrent level: " << level;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\nCurrent EXP: " << exp;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\nRequired EXP to reach level " << level+1 << ": " << exp_next_level;
    this_thread::sleep_for(chrono::seconds(1));

    int level_choice;
    cout << "\n\nDo You Want To Level Up?";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\n1. Yes" << endl;
    cout << "2. No" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    
    bool input = false;

   
    while (input == false) { // While loop to check if input is valid
        cout<<"\nChoice: ";
        if (!(cin >> level_choice)){
            cin.clear();
            cin.ignore();
        }
    
        if (level_choice != 1 && level_choice != 2){
            cout << "Invalid Input!";
            this_thread::sleep_for(chrono::seconds(1));
         }

    switch (level_choice)
    {
        case 1:
            if (exp >= exp_next_level){
                level_up();
                cout << "\nLevel Up Succesful";
                this_thread::sleep_for(chrono::seconds(1));
                    
                } else {
                    cout << "\nNot Enough EXP To Level Up!"; 
                    this_thread::sleep_for(chrono::seconds(1));
                }
                
                break;
        case 2:
            return;
        }

    int leave;

     bool input2 = false;

    while (input2 == false) { // While loop to check if input is valid
        cout <<"\n\nPress 9 to Return To Main Menu: " ;

        if (!(cin >> leave)){
            cin.clear();
            cin.ignore();
        }

        if (leave==9){
            return;
        } else {
            cout<<"Invalid Input!";
            this_thread::sleep_for(chrono::seconds(1));
        }

    }
}

    return;
}


item User::boost_menu() { // Function to boost menu
    item boost = inventory.select_boost();
    return boost;
}

void User::add_to_hof() { // Function to add user to hooves of fame
    stable.get_horse_hof();
}

void User::delete_stable(){
    stable.~stable();
}