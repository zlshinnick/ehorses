#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class item{
    private:
        string name;
        int price;
        double boost;

    public:
        item();
        item(string name, int price, double boost);
        string get_name();
        int get_price();
        double get_boost();


};
#endif 