#include "market.h"
#include <chrono>
#include <thread>

market::market() { // Default constructor
}

void market::initialize(userhorse horse1, userhorse horse2, userhorse horse3,userhorse horse4,userhorse horse5) { // Initialises market
    storehorses.push_back(horse1); // Adds horses to vector
    storehorses.push_back(horse2);
    storehorses.push_back(horse3);
    storehorses.push_back(horse4);
    storehorses.push_back(horse5);
}


void market::print_market() { // Outputs market vector

    welcome_market();

    cout<<"\n** Here Are The Horses Currently For Sale **\n" << endl;
        for (int i =0; i<storehorses.size();i++){
            cout<<"Horse: "<<storehorses[i].get_name() << endl;
            cout<<"Top Speed: "<<storehorses[i].get_max() << endl;
            cout<<"Level: "<<storehorses[i].get_level() << endl;
            cout<<"Price: "<<storehorses[i].get_price() << endl; // Need to make a better algorithm for price of horse
            this_thread::sleep_for(chrono::seconds(2));

            
            cout << endl;
        }
    }

userhorse market::get_horse(){ // Returns horse from market
    
    cout << "\nWhich Horse Would You Like To Purchase?" << endl;
    this_thread::sleep_for(chrono::seconds(1)); 

    int choice_horse;

    cout << "0: "<<storehorses[0].get_name() << endl;
    this_thread::sleep_for(chrono::seconds(1));

    cout << "1: "<<storehorses[1].get_name() << endl;
    this_thread::sleep_for(chrono::seconds(1));

    cout << "2: "<<storehorses[2].get_name() << endl;
    this_thread::sleep_for(chrono::seconds(1));

    cout << "3: "<<storehorses[3].get_name() << endl;
    this_thread::sleep_for(chrono::seconds(1));

    cout << "4: "<<storehorses[4].get_name() << endl << endl;
    this_thread::sleep_for(chrono::seconds(1));

    cout << "9: None" << endl << endl;
    this_thread::sleep_for(chrono::seconds(2));

    cout << "Horse To Purchase: ";
    cin >> choice_horse;
    this_thread::sleep_for(chrono::seconds(1));

    return storehorses[choice_horse];

}

void market::welcome_market() { // Welcome message for market
    system("Clear");
    cout << " /$$   /$$                                               /$$      /$$                     /$$                   /$$    " << endl;
    cout << "| $$  | $$                                              | $$$    /$$$                    | $$                  | $$    " << endl;
    cout << "| $$  | $$  /$$$$$$   /$$$$$$   /$$$$$$$  /$$$$$$       | $$$$  /$$$$  /$$$$$$   /$$$$$$ | $$   /$$  /$$$$$$  /$$$$$$  " << endl;
    cout << "| $$$$$$$$ /$$__  $$ /$$__  $$ /$$_____/ /$$__  $$      | $$ $$/$$ $$ |____  $$ /$$__  $$| $$  /$$/ /$$__  $$|_  $$_/  " << endl;
    cout << "| $$__  $$| $$  | $$| $$  |__/|  $$$$$$ | $$$$$$$$      | $$  $$$| $$  /$$$$$$$| $$  |__/| $$$$$$/ | $$$$$$$$  | $$    " << endl;
    cout << "| $$  | $$| $$  | $$| $$       |____  $$| $$_____/      | $$|  $ | $$ /$$__  $$| $$      | $$_  $$ | $$_____/  | $$ /$$" << endl;
    cout << "| $$  | $$|  $$$$$$/| $$       /$$$$$$$/|  $$$$$$$      | $$ ||  | $$|  $$$$$$$| $$      | $$ |  $$|  $$$$$$$  |  $$$$/" << endl;
    cout << "|__/  |__/ |______/ |__/      |_______/  |_______/      |__/     |__/ |_______/|__/      |__/  |__/ |_______/   |___/ " << endl;
    
    this_thread::sleep_for(chrono::seconds(2));

}