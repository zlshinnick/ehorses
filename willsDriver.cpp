#include "horse.h"
#include "userhorse.h"
#include "comphorse.h"
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
  
  userhorse u2;  
  u2.set_userhorse("Will", 14.1, 12.2);
  u2.set_rand_race_time();

  userhorse u3;  
  u3.set_userhorse("Zill", 14.1, 12.2);
  u3.set_rand_race_time();

  userhorse u4;  
  u4.set_userhorse("jill", 10, 8.2);
  u4.set_rand_race_time();

  userhorse u5;  
  u5.set_userhorse("kill", 10, 8.2);
  u5.set_rand_race_time();

  userhorse u6;  
  u6.set_userhorse("Mill", 6, 2);
  u6.set_rand_race_time();

  cout << u1.get_name() << " :" << u1.get_race_t() << endl;
  cout << u2.get_name() << " :" << u2.get_race_t() << endl;
  cout << u3.get_name() << " :" << u3.get_race_t() << endl;
  cout << u4.get_name() << " :" << u4.get_race_t() << endl;
  cout << u5.get_name() << " :" << u5.get_race_t() << endl;
  cout << u6.get_name() << " :" << u6.get_race_t() << endl; 


  return 0;
}