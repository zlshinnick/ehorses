#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main () {

    srand(time(NULL));

    int num;

    num = rand() % 3;

    cout << num << endl;
}