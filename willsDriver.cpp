#include "horse.h"
#include "userhorse.h"
#include "comphorse.h"
#include <iostream>
#include <string>
#include <ctime>
#include <random>
using namespace std;

int main() {

  srand(time(NULL)); //tried adding this to fix it

  //generating 3 horses then setting their race time to be div 1 using comphorse function
  comphorse c1; c1.set_bot_race_t(1);
  comphorse c2; c2.set_bot_race_t(1);
  comphorse c3; c3.set_bot_race_t(1);
  //doing same but div 2
  comphorse c4; c4.set_bot_race_t(2);
  comphorse c5; c5.set_bot_race_t(2);
  comphorse c6; c6.set_bot_race_t(2);
  //doing same but div 3
  comphorse c7; c7.set_bot_race_t(3);
  comphorse c8; c8.set_bot_race_t(3);
  comphorse c9; c9.set_bot_race_t(3);     

  //outputting each horse time
  cout << c1.get_race_t() << endl;
  cout << c2.get_race_t() << endl;
  cout << c3.get_race_t() << endl;
  cout << c4.get_race_t() << endl;
  cout << c5.get_race_t() << endl;
  cout << c6.get_race_t() << endl;
  cout << c7.get_race_t() << endl;
  cout << c8.get_race_t() << endl;
  cout << c9.get_race_t() << endl;  

  return 0;
}