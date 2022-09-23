#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class item{
    private:
        string name;
        int price;
        double boost;
        int length_of_boost; //how many races the boost will last for

    public:
        item();
        item(string name, int price, double boost,int length_of_boost);
        string get_name();
        int get_price();
        double get_boost();


};
#endif 