#include <iostream>
#include <string>
using namespace std;
#include "horse.h"
#include "userhorse.h"

int main() {
system("Clear");

    //driver function to test userhorse
    system("Clear");
    cout << endl; cout << endl;

    //testing default constructor
    userhorse bill;
    cout<<"initialising userhorse: "<<endl;
    bill.print_horse();
    cout<<endl;

    //testing setting variables function
    bill.set_userhorse("billy bob", 18, 12);
    cout<<"after setting userhorse: "<<endl;
    bill.print_horse();
    cout<<endl;

    //testing virtual function which sets random race time
    cout<<"testing random race time: "<<endl;
    bill.set_rand_race_time();
    cout << "race time 1: " << bill.get_race_t() << endl;
    bill.set_rand_race_time();
    cout << "race time 2: " << bill.get_race_t() << endl;
    bill.set_rand_race_time();
    cout << "race time 3: " << bill.get_race_t() << endl;
    bill.set_rand_race_time();
    cout << "race time 4: " << bill.get_race_t() << endl; cout << endl;

    //testing adding a boost
    cout<<"testing adding a boost: "<<endl;
    bill.set_rand_race_time();
    cout << "random race time before boost:    " << bill.get_race_t() << endl; 
    bill.add_boost(2);
    cout << "random race time after boost (2): " << bill.get_race_t() << endl; cout << endl;

    //testing level up
    cout << "testing level up: " << endl;
    cout << "horse level before: " << bill.get_level() << endl;
    cout << "horse max speed before: " << bill.get_max() << endl;
    bill.level_up();
    cout << "horse level after: " << bill.get_level() << endl;
    cout << "horse max speed after: " << bill.get_max() << endl;
    bill.level_up();
    cout << "horse level after: " << bill.get_level() << endl;
    cout << "horse max speed after: " << bill.get_max() << endl;
    bill.level_up();
    cout << "horse level after: " << bill.get_level() << endl;
    cout << "horse max speed after: " << bill.get_max() << endl << endl;

    //testing incremement wins
    cout << "testing incrementing wins: " << endl;
    cout << "horse wins before: " << bill.get_wins() << endl;
    bill.increment_wins();
    cout << "horse wins after: " << bill.get_wins() << endl << endl;

}