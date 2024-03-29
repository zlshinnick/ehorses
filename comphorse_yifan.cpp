#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <cmath>
#include <vector>
#include <algorithm>

#include "horse.h"
#include "comphorse_yifan.h"

using namespace std;

// Constructor
comphorse::comphorse () {
}

// Outputs the bot information (name: racetime)
void comphorse::get_bot_info() {

    for (int i = 0; i < 7; i++) {

        cout << bot_names[i] << ": " << bot_race_times[i] << " km/h" << endl;
    }
}

vector<string> comphorse::set_bot_names(int div) {

    if (div == 1) { // Sets horse names for first division
        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Send 'Em");
                break;

            case 1:
                bot_names.push_back("Aidan's Choice");
                break;

            case 2:
                bot_names.push_back("The Big Cheese");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Field Of Battle");
                break;

            case 1:
                bot_names.push_back("Just Dennis");
                break;

            case 2:
                bot_names.push_back("Ampitup Black");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Royal Accolade");
                break;

            case 1:
                bot_names.push_back("God's Moment");
                break;

            case 2:
                bot_names.push_back("Parions");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Starchienne");
                break;

            case 1:
                bot_names.push_back("Missile Storm");
                break;

            case 2:
                bot_names.push_back("Crooked Carrot");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Charcoal Chaos");
                break;

            case 1:
                bot_names.push_back("Queen's Gift");
                break;

            case 2:
                bot_names.push_back("Musqueam");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Hooah Havanna");
                break;

            case 1:
                bot_names.push_back("Compak");
                break;

            case 2:
                bot_names.push_back("Citino");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Malkar Pindari");
                break;

            case 1:
                bot_names.push_back("Yarralea");
                break;

            case 2:
                bot_names.push_back("Rockabye Bonny");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

    } else if (div == 2) { // Sets horse names for second division
        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Zenzero Bay");
                break;

            case 1:
                bot_names.push_back("To The Lookout");
                break;

            case 2:
                bot_names.push_back("Eye See Double");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Boltnmach");
                break;

            case 1:
                bot_names.push_back("Cinocal Jamane");
                break;

            case 2:
                bot_names.push_back("Starofremembrance");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Smile Lyle");
                break;

            case 1:
                bot_names.push_back("Midnight In Memphis Nz");
                break;

            case 2:
                bot_names.push_back("Brian Who");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("My Celebrity");
                break;

            case 1:
                bot_names.push_back("Kermadec");
                break;

            case 2:
                bot_names.push_back("Ultimate Me Nz");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Juniper");
                break;

            case 1:
                bot_names.push_back("Kilara Bugle");
                break;

            case 2:
                bot_names.push_back("Happy Tally");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Swift Lethal");
                break;

            case 1:
                bot_names.push_back("Russanda Bondi");
                break;

            case 2:
                bot_names.push_back("Donegal Jerry");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Toffee Trippett");
                break;

            case 1:
                bot_names.push_back("Hilldun Jet");
                break;

            case 2:
                bot_names.push_back("Knockglass Penny");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

    } else if (div == 3) { // Sets horse names for third division
        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Jazzy Mr");
                break;

            case 1:
                bot_names.push_back("Mo Slater");
                break;

            case 2:
                bot_names.push_back("Two Hands George");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Buster Bash");
                break;

            case 1:
                bot_names.push_back("Floyd");
                break;

            case 2:
                bot_names.push_back("Eeyore Wayz");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Savage One");
                break;

            case 1:
                bot_names.push_back("Friaresque");
                break;

            case 2:
                bot_names.push_back("Ration Aly");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Benji's");
                break;

            case 1:
                bot_names.push_back("Advanced");
                break;

            case 2:
                bot_names.push_back("Alsephina");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Constant Dreaming");
                break;

            case 1:
                bot_names.push_back("The Great One");
                break;

            case 2:
                bot_names.push_back("Daumier");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Best Of Bordeaux");
                break;

            case 1:
                bot_names.push_back("Jacquinot");
                break;

            case 2:
                bot_names.push_back("Sejardan");
                break;

            default:
                cout << "Error" << endl;
                break;
        }

        rand_num = rand() % 3;
        switch (rand_num) {
            case 0:
                bot_names.push_back("Political Debate");
                break;

            case 1:
                bot_names.push_back("Promitto");
                break;

            case 2:
                bot_names.push_back("Golden Mile");
                break;

            default: // Outputs "Error" for unexpected value
                cout << "Error" << endl;
                break;
        }

    } else { // Outputs "Error" for unexpected division value
        cout << "Invalid Input" << endl;
    }

    return bot_names;

}

int comphorse::set_div(int div) { // Sets the division for the virtual function
    divisionC = div;
    return divisionC;
}

void comphorse::set_rand_race_time() { // Virtual function to set the random race time
        // Assigning a time based on division
    if (divisionC == 1) {
      // Bots in division 1 will have a random time between 8 and 11 seconds
        for (int i = 0; i < 8; i++) {
            // Creates random number between 0.0 and 3.0
            double rand_n = (rand()%300)/10;
            rand_n /= 10;
            this -> race_time = rand_n + 8; // Speeds between 8 and 11  

            bot_race_times.push_back(race_time);
        }

    } else if (divisionC == 2) {

        for (int i = 0; i < 8; i++) {
            // Creates random number between 0.0 and 3.0
            double rand_n = (rand()%300)/10;
            rand_n /= 10;
            this -> race_time = rand_n + 12; // Speeds between 12 and 15

            bot_race_times.push_back(race_time);
        }

    } else if (divisionC == 3) {

        for (int i = 0; i < 8; i++) {
            // Creates random number between 0.0 and 3.0
            double rand_n = (rand()%300)/10;
            rand_n /= 10;
            this -> race_time = rand_n + 16; // Speeds between 16 and 19

            bot_race_times.push_back(race_time);
        }

    } else {

        cout << "Invalid Input" << endl; // Error for unexpected division value

    }
}