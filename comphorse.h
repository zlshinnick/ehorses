#ifndef COMPHORSE_H
#define COMPHORSE_H
#include <string>
#include "horse.h"
using namespace std;

class comphorse : public horse {
/*this is a class for bot race horses which will be generated at the start of each race to compete against
users horse. each bot horse will be randomly generated based on division */
  
  public:

    comphorse(int div);    //constructs a horse for a respective race

};
#endif
