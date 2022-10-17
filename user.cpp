#include "user.h"
#include <math.h>
#include <chrono>
#include <thread>

User::User() {
    name = "";
    bank_account = 0;
    user_wins = 0;
    exp = 0;
    exp_next_level = 0; 
    prize_money=0.0;
}

void User::initialize(string user_name){
    name = user_name;
    bank_account = 1000;
    user_wins = 0;
    exp = 0;
    level = 1;
    stable.initialize();

    exp_next_level = static_cast <int> //type casting to ensure its a int
      ((50 * pow(level, 3)) - 
       (150 * pow(level, 2)) + 
         (400 * level)) / 3;; 
    prize_money=0.0;
}

string User::get_name() { return name; }
double User::get_bank_account() { return bank_account; }
double User::get_prize_money() { return prize_money; }
int User::get_wins() { return user_wins; }
int User::get_exp() { return exp;}
int User::get_exp_next_level(){return exp_next_level;}
int User::get_level(){return level;}


void User::print_user_stats(){
    cout<< endl;
    cout << "*** Player Details ***"<<endl;
    cout << "* Name: "<<name<<endl;
    cout << "* Bank Account: "<<get_bank_account()<<endl;
    cout << "* Level: "<<get_level()<<endl;
    cout << "* Horses In Stable: "<<stable.get_current_num_horses()<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout <<"\n****************************\n"<<endl;
    cout << "* Exp: "<<get_exp()<<endl;
    cout << "* Exp For Next Level: "<<get_exp_next_level()<<endl;    
    cout << "* Total Wins: "<<get_wins()<<endl;
    cout << "* Prize Money: "<<get_prize_money()<<endl;
}

void User::level_up() {
    if(exp >= exp_next_level){
        level++;
        exp = exp-exp_next_level;
        exp_next_level =static_cast <int> 
                         ((50 * pow(level, 3)) - 
                         (150 * pow(level, 2)) + 
                         (400 * level)) / 3;
    }
}

string User::get_as_string(){
  return name + " "
    + to_string(bank_account) + " "
    + to_string(user_wins) + " "
    + to_string(exp) + " "
    + to_string(exp_next_level) + " "
    + to_string(level) + " ";
}

void User::add_horse_to_stable(userhorse new_horse){
    stable.add_horse(new_horse);
}

int User::get_num_horses(){
    return stable.get_current_num_horses();
}

void User:: print_stables(){
    stable.print_stable();
}

void User::purchase_item(item item){
    int price = item.get_price();

    if (bank_account>=price){
        inventory.add_item(item);
        bank_account-=item.get_price();
        cout<<"\nRemaining Bank Account is $"<<bank_account<<endl<<endl;
        this_thread::sleep_for(chrono::seconds(1));
    } else {
        cout<<"Not Enough Funds For Purchase of "<<item.get_name()<<endl;
    }
}

void User::print_inventory(){
   //cout<<"Being Called";
    if(inventory.get_num_items()!=0){
        inventory.print_inventory();
    }else{
        cout<<"\nInventory is Empty!";
    }
}

void User::purchase_horse(userhorse horse){
    int price = horse.get_price();

        if (bank_account>=price){
        stable.add_horse(horse);
        bank_account-=horse.get_price();
        cout<<"\nA "<<horse.get_name()<<" Horse Has Been Succesfully Purchased"<<endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"\nRemaining Bank Account is $"<<bank_account<<endl<<endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout<<horse.get_name()<<" Is Now In Your Stables"<<endl;
        this_thread::sleep_for(chrono::seconds(1));
        cout<<"\nTravel To Your Stables To Name Your New Horse\n\n";
        this_thread::sleep_for(chrono::seconds(1));

    }else {
        cout<<"Not Enough Funds For Purchase of "<<horse.get_name()<<endl;
    }
}

void User::breeding(){
    stable.breed();
    return;
}

void User::call_stable_menu(){
    cout<<"hello"<<endl;
    stable.stable_menu();
    
    return;
}

void User::user_wonD1(){
    bank_account += 500;
    user_wins++;
    prize_money += 500;
    exp+=100;
}

void User::user_wonD2() {
    bank_account += 1000;
    user_wins++;
    prize_money += 1000;
    exp+=250;
}

void User::user_wonD3() {
    bank_account += 1500;
    user_wins++;
    prize_money += 1500;
    exp+=500;
}

userhorse* User::get_horse_for_race(){
    return stable.get_horse_for_race();
}


void User::level_up_menu(){
    system("Clear");
    cout<<"** Level Up Menu **";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\n\nCurrent level: " << level;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\nCurrent EXP: " << exp;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\nRequired EXP to reach level " << level+1 << ": " << exp_next_level;
    this_thread::sleep_for(chrono::seconds(1));

    int level_choice;
    cout<<"\n\nDo You Want To Level Up?";
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"\n1. Yes"<<endl;
    cout<<"2. No"<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    
    bool input = false;

   
    while (input == false) {
        cout<<"\nChoice: ";
        if(!(cin >> level_choice)){
            cin.clear();
            cin.ignore();
        }
    
        if(level_choice!=1 && level_choice!=2){
            cout<<"Invalid Input!";
            this_thread::sleep_for(chrono::seconds(1));
         }

    switch (level_choice)
    {
        case 1:
            if(exp>=exp_next_level){
                level_up();
                cout<<"\nLevel Up Succesful";
                this_thread::sleep_for(chrono::seconds(1));
                    
                } else {
                    cout<<"\nNot Enough EXP To Level Up!"; 
                    this_thread::sleep_for(chrono::seconds(1));
                }
                
                break;
        case 2:
            return;
        }

    int leave;

     bool input2 = false;

    while (input2 == false) {
        cout <<"\n\nPress 9 to Return To Main Menu: " ;

        if(!(cin >> leave)){
            cin.clear();
            cin.ignore();
        }

        if(leave==9){
            return;
        } else {
            cout<<"Invalid Input!";
            this_thread::sleep_for(chrono::seconds(1));
        }

     }
}

    return;
}


item User::boost_menu(){
    item boost = inventory.select_boost();
    return boost;
}