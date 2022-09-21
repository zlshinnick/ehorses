#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <vector>
#include <algorithm>
#include <cmath>
#include "horse.h"
#include "comphorse.h"

using namespace std;

int main () {
    vector<double> times;


    for (int i = 0; i < 8; i++) {
        double rand_n = (rand()%300)/10;
        rand_n /= 10;
        rand_n += 8;
        times.push_back(rand_n);
        cout << times[i] << endl;
    }

}