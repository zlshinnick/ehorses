#include "horse.h"
#include "userhorse.h"
//#include "comphorse.h"
#include <iostream>
#include <string>
#include <ctime>
#include <random>
using namespace std;

int main() {

  srand(time(NULL));

  userhorse u1;  
  u1.set_userhorse("Bill", 14.1, 12.2);
  u1.set_rand_race_time();
  u1.print_horse();

  cout << "before: " << u1.get_race_t() << endl << endl;
  
  u1.level_up();
  u1.level_up();
  u1.level_up();
  u1.increment_wins();
  u1.add_boost(2);

  cout << "after: " << u1.get_race_t() << endl << endl;
  u1.print_horse();
  
  

  return 0;
}