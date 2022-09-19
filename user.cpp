#include "user.h"
#include <math.h>
user::user() {
  name = "";
  bank_account = 0;
  user_wins = 0;
  exp = 0;
  exp_next_level = pow(level,2)*10; //make a equation that will forever increase with player xp;
  level = 0;
  allowed_num_horses = 1;
}

string user::get_name() { return name; }
double user::get_bank_account() { return bank_account; }
int user::get_wins() { return user_wins; }
int user::get_exp() { return exp;}
int user::get_exp_next_level(){return exp_next_level;}
int user::get_level(){return level;}

void user::level_up() {
    if(exp >= exp_next_level){
        level++;
        exp = exp-exp_next_level;
        exp_next_level =pow(level,2)*10;

    }
}