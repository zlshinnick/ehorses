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

    cout << "\np1 name: " << p1.get_name() << endl;
    cout <<  "p1 Max Speed: " << p1.get_max() << endl;
    cout <<  "p1 Min Speed: " << p1.get_min() << endl;

    cout << "\np2 name: " << p2.get_name() << endl;
    cout <<  "p2 Max Speed: " << p2.get_max() << endl;
    cout <<  "p2 Min Speed: " << p2.get_min() << endl;

    double max_ave = p1.get_max() + p2.get_max(); max_ave = max_ave / 2;
    double min_ave = p1.get_min() + p2.get_min(); min_ave = min_ave / 2;
    int gen = p1.get_generation() + 1;

    //testing initialising bred_horse
    cout << "\n\ninitialising bred_horse:" << endl;
    bred_horse b1;
    b1.print_horse();
    b1.print_parents();

    
    cout << "\nsetting with parents" << endl;
    b1.set_bred_horse("baby", max_ave, min_ave, gen);
    b1.set_parents(p1.get_name(),p1.get_max(), p1.get_min(), p2.get_name(), p2.get_max(), p2.get_min());

    b1.print_horse();
    cout << "output  parents:" << endl;
    b1.print_parents(); 
    
}