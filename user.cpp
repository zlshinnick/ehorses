#include "user.h"
#include <math.h>
#include <chrono>
#include <thread>

user::user() {
    name = "";
    bank_account = 0;
    user_wins = 0;
    exp = 0;
    exp_next_level = 0; 
    prize_money=0.0;
}

void user::initialize(string user_name){
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

string user::get_name() { return name; }
double user::get_bank_account() { return bank_account; }
double user::get_prize_money() { return prize_money; }
int user::get_wins() { return user_wins; }
int user::get_exp() { return exp;}
int user::get_exp_next_level(){return exp_next_level;}
int user::get_level(){return level;}


void user::print_user_stats(){
    cout<< endl;
    cout << "*** Player Details ***"<<endl;
    cout << "* Name: "<<name<<endl;
    cout << "* Bank Account: "<<get_bank_account()<<endl;
    cout << "* Level: "<<get_level()<<endl;
    cout << "* Horses In Stable: "<<stable.get_current_num_horses()<<endl;
    cout <<"****************************"<<endl;
    cout << "* Exp: "<<get_exp()<<endl;
    cout << "* Exp For Next Level: "<<get_exp_next_level()<<endl;    
    cout << "* Total Wins: "<<get_wins()<<endl;
    cout << "* Prize Money: "<<get_prize_money()<<endl;
}

void user::level_up() {
    if(exp >= exp_next_level){
        level++;
        exp = exp-exp_next_level;
        exp_next_level =pow(level,2)*10;
    }
}

string user::get_as_string(){
  return name + " "
    + to_string(bank_account) + " "
    + to_string(user_wins) + " "
    + to_string(exp) + " "
    + to_string(exp_next_level) + " "
    + to_string(level) + " ";
}

void user::add_horse_to_stable(userhorse new_horse){
    stable.add_horse(new_horse);
}

int user::get_num_horses(){
    return stable.get_current_num_horses();
}

void user:: print_stables(){
    stable.print_stable();
}

void user::purchase_item(item item){
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

void user::print_inventory(){
   //cout<<"Being Called";
    if(inventory.get_num_items()!=0){
    inventory.print_inventory();
    }
}

void user::purchase_horse(userhorse horse){
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
        cout<<"\nTravel To Your Stables To Name Your New Horse";
        this_thread::sleep_for(chrono::seconds(1));

    }else {
        cout<<"Not Enough Funds For Purchase of "<<horse.get_name()<<endl;
    }
}

void user::breeding(){
    stable.breed();
    return;
}

void user::call_stable_menu(){
    stable.stable_menu();
    return;
}

