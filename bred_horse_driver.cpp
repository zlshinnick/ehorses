#include <iostream>
#include <string>
using namespace std;
#include "horse.h"
#include "userhorse.h"
#include "bred_horse.h"

int main() {
system("Clear");

    //creating parents
    cout << "creating parents: " << endl;
    userhorse p1; 
    p1.set_userhorse("dad", 20, 10);
    userhorse p2; 
    p2.set_userhorse("mum", 22, 12);

    cout << "\np1 name:" << p1.get_name() << endl;
    cout <<  "p1 Max Speed:" << p1.get_max() << endl;
    cout <<  "p1 Min Speed:" << p1.get_min() << endl;

    cout << "\np2 name:" << p2.get_name() << endl;
    cout <<  "p2 Max Speed:" << p2.get_max() << endl;
    cout <<  "p2 Min Speed:" << p2.get_min() << endl;

    //testing initialising bred_horse
    cout << "\ninitialising bred_horse:" << endl;
    cout <<
    //bred_horse 

    
}