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

  comphorse c1 = comphorse(1);
  comphorse c2 = comphorse(1);
  comphorse c3 = comphorse(2);
  comphorse c4 = comphorse(2);
  comphorse c5 = comphorse(3);
  comphorse c6 = comphorse(3);

  cout << c1.get_race_t() << endl;
  cout << c2.get_race_t() << endl;
  cout << c3.get_race_t() << endl;
  cout << c4.get_race_t() << endl;
  cout << c5.get_race_t() << endl;
  cout << c6.get_race_t() << endl;

  return 0;
}