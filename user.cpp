#include "user.h"
#include <math.h>

user::user() {
  name = "";
  bank_account = 0;
  user_wins = 0;
  exp = 0;
  exp_next_level = 0; 
  allowed_num_horses = 0;
  prize_money=0.0;
}

void user::initialize(string user_name){
  name = user_name;
  bank_account = 100;
  user_wins = 0;
  exp = 0;
  level = 1;

//next level exp gets expoentially harder
  exp_next_level = static_cast <int> //type casting to ensure its a int
      ((50 * pow(level, 3)) - 
       (150 * pow(level, 2)) + 
         (400 * level)) / 3;; 


  allowed_num_horses = 1;
  prize_money=0.0;
}

string user::get_name() { return name; }
double user::get_bank_account() { return bank_account; }
double user::get_prize_money() { return prize_money; }
int user::get_wins() { return user_wins; }
int user::get_exp() { return exp;}
int user::get_exp_next_level(){return exp_next_level;}
int user::get_level(){return level;}
int user::get_allowed_num_horses(){return allowed_num_horses;}
int user::get_num_horses(){return num_horses;}

void user::print_user_stats(){
    cout<< endl;
    cout << "*** Player Details ***"<<endl;
    cout << "* Name: "<<name<<endl;
    cout << "* Bank Account: "<<get_bank_account()<<endl;
    cout << "* Level: "<<get_level()<<endl;
    cout << "* Horses In Stable: "<<get_num_horses();
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
        allowed_num_horses++;
    }
}