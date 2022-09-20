#ifndef COMPHORSE_H
#define COMPHORSE_H
#include <string>
#include "horse.h"
using namespace std;

class comphorse : public horse {
  
  public:
    //calling this function will assign random time in an interval based on the division parameter
    void set_bot_race_t(int div);

};
#endif
