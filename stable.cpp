#include "stable.h"
#include "user.h"
#include "horse.h"
#include <chrono>
#include <thread>
#include <string>

stable::stable() { // Default constructor
    max = 0;
    num_of_horses = 0;
    array = nullptr;
    
};

void stable::initialize() { // Function to initialise stable
    max = 10;
    num_of_horses = 0;
    array = new userhorse[max];
}

bool stable::add_horse(userhorse h) { // Function to add horse to stable

    if (num_of_horses<max) {
        array[num_of_horses] = h;
        num_of_horses++;
        return true;
    }
    return false;
}

userhorse* stable::get_horses() { // Function to get horses from stable
    return array;
}

void stable::print_stable() { // Function to print stable
    cout << endl;
    for (int i = 0; i < num_of_horses;i++) {
        cout << "*Horse " << i+1 << "*" << endl;
        array[i].print_horse();
        this_thread::sleep_for(chrono::seconds(2));
    }
}

int stable::get_current_num_horses() { // Function to get current number of horses in stable
    return num_of_horses;
}

bool stable::add_bred_horse(string _name) { // Function to add bred horse to stable
  // Getting parents times
  double p1max = p1.get_max();
  double p1min = p1.get_min();
  double p2max = p2.get_max();
  double p2min = p2.get_min();

  double bred_max = p1max + p2max; bred_max = bred_max/2;
  double bred_min = p1min + p2min; bred_min = bred_min/2;

  // Checking if parents are same gen
  if (p1.get_generation() == p2.get_generation()) {
    
    // Setting gen
    int gen = p1.get_generation() + 1;

    // Constructing horse and setting its variables
    bred_horse b1 = bred_horse();
    b1.set_bred_horse(_name, bred_max, bred_min, gen);
    b1.set_parents(p1.get_name(), p1.get_max(), p1.get_max(), p2.get_name(), p2.get_max(), p2.get_max());

    // Adding horse to stable
    if (num_of_horses<max){
        array[num_of_horses] = b1;
        num_of_horses++;
        return true;
    }

  } else {
    // If not same generation
    return false;
  }
  return false;
}

void stable::set_parents(){ // Function to set parents
    print_stable();
    p1 = userhorse();
    p2 = userhorse();
    int index_first = 0;
    cout << "\n\n";
    cout << "Select Parent 1 For Breeding: " << endl << endl;

    for (int i = 0; i < num_of_horses; i++) {
        cout << i << ": "<<array[i].get_name() << endl;
    }
    cout << "Enter Choice: ";
    cin >> index_first;

    while (index_first >= num_of_horses || index_first < 0) {
        cout << "Invalid Input" << endl << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Enter Choice: ";
        cin >> index_first;

    }

    p1 = array[index_first];

    int index_second = 0;

    cout << "\nSelect Parent 2 For Breeding" << endl << endl;


    for (int i = 0; i < num_of_horses; i++){
        if (i!=index_first) {
            cout << i << ": " << array[i].get_name() << endl;
        }
    }


    cout << "\n\nEnter Choice: ";
    cin >> index_second;

    while (index_second >= num_of_horses || index_second < 0 || index_first == index_second) { // Checking if input is valid
        cout << "Invalid Input" << endl << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Enter Choice: ";
        cin >> index_second;

    }

    p2 = array[index_second];

}

void stable::breed(){ // Function to breed horses
    system("Clear");
    breeding_ground_ascii();    // ASCII art
    if(num_of_horses<2){ // Checking user has atleast 2 horses
        cout<<"You Can Not Breed, You Need At Least 2 Horses";
        this_thread::sleep_for(chrono::seconds(1));
        return;
    }


    int choice =1 ;
    cout<<"Do You Want To Breed Horses"<<endl<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"1. Yes"<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"2. No";
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"\n\nChoice: ";

    cin>>choice;

    if(choice ==2 ){
        return;
    }

    set_parents();  // Setting parents

    string name;
    cout<<"Set Foal Name: ";
    cin.ignore();
    cin.clear();
    getline (cin,name);

    bool baby =  add_bred_horse(name);

    if(baby == true){
        this_thread::sleep_for(chrono::seconds(1));
        cout<<p1.get_name()<<" And "<<p2.get_name()<<" Are Breeding Please Wait"<<endl<<endl;
        this_thread::sleep_for(chrono::seconds(3));
        cout<<p1.get_name()<<" Has Given Birth"<<endl<<endl;
        this_thread::sleep_for(chrono::seconds(2));


        cout<<name<<" Has Been Born And Added To Stables"<<endl<<endl;
        this_thread::sleep_for(chrono::seconds(2));
    }

    if(baby == false){
        cout<<" Baby Not Born, Parents Cant Be Same Generation!";
    }
}
void stable::stable_menu(double* bank) { // Function to display stable menu
    system("Clear");
    cout << "  /$$$$$$   /$$               /$$       /$$                    " << endl;
    cout << " /$$__  $$ | $$              | $$      | $$                     " << endl;
    cout << "| $$  |__//$$$$$$    /$$$$$$ | $$$$$$$ | $$  /$$$$$$   /$$$$$$$" << endl;
    cout << "|  $$$$$$|_  $$_/   |____  $$| $$__  $$| $$ /$$__  $$ /$$_____/" << endl;
    cout << "|____  $$ | $$      /$$$$$$$| $$  | $$| $$| $$$$$$$$|  $$$$$$  " << endl;
    cout << " /$$ | $$ | $$ /$$ /$$__  $$| $$  | $$| $$| $$_____/ |____  $$" << endl;
    cout << "|  $$$$$$/ |  $$$$/|  $$$$$$$| $$$$$$$/| $$|  $$$$$$$ /$$$$$$$/" << endl;
    cout << " |______/   |___/   |_______/|_______/ |__/ |_______/|_______/ " << endl;

    this_thread::sleep_for(chrono::seconds(2));

    int choice;

    cout << "\n** What Would You Like To Do? **\n" << endl; // Displaying menu
    this_thread::sleep_for(chrono::seconds(1));
    cout << "1. View Your Horses " << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "2. Change The Name of A Horse" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "3. Upgrade A Horse" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout << "9. Return To Main Menu";
    this_thread::sleep_for(chrono::seconds(1));

    cout << "\n\nChoice: ";
    cin >> choice;
    this_thread::sleep_for(chrono::seconds(1));

    switch (choice) // Switch statement to call functions
    {
    case 1:
        print_stable();
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\nPress 9 to Return To Main Menu: ";
        cin >> choice;
        break;
    case 2:
        change_name_menu();
        cout << "\nPress 9 to Return To Main Menu: ";
        cin >> choice;
        break;
    case 3:
        level_up_menu(bank);
        break;
    case 9:
        return;
    default:
        break;
    }
return;
}

void stable::breeding_ground_ascii() { // Function to display ASCII art
    cout << " /$$$$$$$                                      /$$ /$$                            /$$$$$$                                                /$$" << endl;
    cout << "| $$__  $$                                    | $$|__/                           /$$__  $$                                              | $$" << endl;
    cout << "| $$  | $$  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$$ /$$ /$$$$$$$   /$$$$$$       | $$  |__/  /$$$$$$   /$$$$$$  /$$   /$$ /$$$$$$$   /$$$$$$$" << endl;
    cout << "| $$$$$$$  /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$| $$| $$__  $$ /$$__  $$      | $$ /$$$$ /$$__  $$ /$$__  $$| $$  | $$| $$__  $$ /$$__  $$" << endl;
    cout << "| $$__  $$| $$  |__/| $$$$$$$$| $$$$$$$$| $$  | $$| $$| $$  | $$| $$  | $$      | $$|_  $$| $$  |__/| $$  | $$| $$  | $$| $$  | $$| $$  | $$" << endl;
    cout << "| $$  | $$| $$      | $$_____/| $$_____/| $$  | $$| $$| $$  | $$| $$  | $$      | $$  | $$| $$      | $$  | $$| $$  | $$| $$  | $$| $$  | $$" << endl;
    cout << "| $$$$$$$/| $$      |  $$$$$$$|  $$$$$$$|  $$$$$$$| $$| $$  | $$|  $$$$$$$      |  $$$$$$/| $$      |  $$$$$$/|  $$$$$$/| $$  | $$|  $$$$$$$" << endl;
    cout << "|_______/ |__/       |_______/ |_______/ |_______/|__/|__/  |__/ |____  $$       |______/ |__/       |______/  |______/ |__/  |__/ |_______/" << endl;
    cout << "                                                                 /$$  | $$                                                                  " << endl;
    cout << "                                                                |  $$$$$$/                                                                  " << endl;
    cout << "                                                                 |______/                                                                   " << endl;

    this_thread::sleep_for(chrono::seconds(1));
}

void stable::change_name_menu() { // Function to change the name of a horse
    cout << "** Which Horse Would You Like To Change The Name Of **" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    for (int i =0; i < num_of_horses; i++){
        cout << i << ". " << array[i].get_name();
        cout << "\n\n";
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "9. None";
    this_thread::sleep_for(chrono::seconds(1));
    int choice;
    cout << "\n\nSelect Horse: ";
    cin >> choice;

    while (choice != 9) {

        if (choice >= 0 && choice < num_of_horses) { // If the user selects a valid horse
            string name;
            cout << "What Would You Like To Change The Horses Name To: ";
            cin.ignore();
            getline (cin,name);
            array[choice].set_name(name);
            this_thread::sleep_for(chrono::seconds(1));
            cout << "\n\nThe Horses Name is Now " << array[choice].get_name();
            this_thread::sleep_for(chrono::seconds(2));

            return;
        } else {
            cout << "** Invalid Input **";
            this_thread::sleep_for(chrono::seconds(2));
            cout << "\n\nSelect Horse:";
            cin >> choice;
        }
    }
    return;
}

userhorse* stable::get_horse_for_race() { // Function to get a horse for race
    print_stable();

    this_thread::sleep_for(chrono::seconds(1));
    cout << "Which Horse Would You Like To Select\n\n";
    
    this_thread::sleep_for(chrono::seconds(1));

    for (int i = 0; i < num_of_horses; i++){
        cout << i <<": "<<array[i].get_name() << endl;
    }

    int index;

    this_thread::sleep_for(chrono::seconds(1));
    cout << "\nEnter Choice: ";
    cin >> index;

    while (index >= num_of_horses || index < 0){
        cout << "Invalid Input" << endl << endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Enter Choice: ";
        cin >> index;

    }

    userhorse* horse_for_race = &array[index]; // Pointer to the horse that the user selects
    
    return horse_for_race;
}

void stable::level_up_menu(double* bank) { // Function to level up a horse
    system("Clear");
    cout << "** Which Horse Would You Like To Upgrade ** ";
    this_thread::sleep_for(chrono::seconds(1));
    for (int i = 0; i < num_of_horses; i++) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\n\n" << array[i].get_name() << endl;
        cout << "Level: " << array[i].get_level() << endl;
        cout << "Max Speed: "<<array[i].get_max() << endl;;
    }

    cout << "\n";

    for (int i = 0; i < num_of_horses; i++) { // For loop to display the horses stats
        cout << i << ": " << array[i].get_name() << endl;
        this_thread::sleep_for(chrono::seconds(1));

    }

    bool input = false;
    int horse_choice;
    while (input == false) {
        this_thread::sleep_for(chrono::seconds(1));

        cout <<"\nChoice:" ;
        if (!(cin >> horse_choice)){
            cin.clear();
            cin.ignore();
        }
        if (horse_choice < 0 || horse_choice > num_of_horses) { // If the user selects a horse that is not in the stable
            cout << "Invalid!\n\n";
            this_thread::sleep_for(chrono::seconds(1));
            
        } else {
            input = true;
        }

        cout << array[horse_choice].get_name()<<" Has Been Selected\n";

        int level_choice;
        switch (array[horse_choice].get_level()) { // Switch statement to display the horses stats and level up
            case 1:
                cout << "\n" << array[horse_choice].get_name() << " Is Level 1\n\n";
                this_thread::sleep_for(chrono::seconds(1));
                cout << "To Upgrade To Level 2 is $500" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "\nWould You Like To Upgrade? ";
                this_thread::sleep_for(chrono::seconds(1));

                
                cout << "\n\n 1. Yes";
                cout << "\n 2. No";
                this_thread::sleep_for(chrono::seconds(1));

                cout << "\n\n Choice: ";
                cin >> level_choice;

                if (level_choice == 2) {
                    break;
                } else if (level_choice == 1) {
                    if ( *bank > 500){
                    array[horse_choice].level_up();
                    *bank -= 500;
                    } else{
                        cout<<"\nInsufficent Funds!"<<endl;
                        this_thread::sleep_for(chrono::seconds(2));

                    }
                }
                break;
            case 2: 
                cout << "\n"<< array[horse_choice].get_name()<< " Is Level 2\n";
                this_thread::sleep_for(chrono::seconds(1));
                cout << "To Upgrade To Level 3 is $100" << endl;
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Would You Like To Upgrade? ";
                this_thread::sleep_for(chrono::seconds(1));

                cout << "\n\n 1. Yes";
                cout << "\n 2. No";
                cout << "\n\n Choice: ";
                cin >> level_choice;

                if(level_choice==2){
                    break;
                } else if(level_choice == 1){
                    if( *bank > 1000){
                    array[horse_choice].level_up();
                    *bank -= 1000;
                    }
                }
                break;

            case 3:
                cout << "\n" << array[horse_choice].get_name() << " Is Max Level \n";
                this_thread::sleep_for(chrono::seconds(1));
                break;
        }

    }
    
     int return_level_up;
     bool inputing = false;

    while (inputing == false) {
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\nPress 9 to Return To Main Menu: " ;

        if(!(cin >> return_level_up)){
            cin.clear();
            cin.ignore();
        }
        if(return_level_up==9){
            return;
         }

    if(return_level_up!=9){
        cout << "Invalid Input!";
        this_thread::sleep_for(chrono::seconds(1));
    }
}

}

void stable::get_horse_hof(){
cout << "\n** Select Which Horse You Would Like To Add **\n\n";
this_thread::sleep_for(chrono::seconds(1));
for (int i = 0; i < num_of_horses; i++){
    cout << i << ": " << array[i].get_name();
    this_thread::sleep_for(chrono::seconds(1));
    if (array[i].get_wins() >= 5){
        cout << ": Eligible" << endl;
    } else {
        cout << ": Not Eleigible" << endl;
    }
}

    bool input = false;
    int horse_choice;
    while (input == false) {
        this_thread::sleep_for(chrono::seconds(1));

        cout << "\nChoice:" ; 
        if (!(cin >> horse_choice)){
            cin.clear();
            cin.ignore();
        }
        if (horse_choice < 0 || horse_choice > num_of_horses) {
            cout << "Invalid!\n\n";
            this_thread::sleep_for(chrono::seconds(1));
            
        } else {
            input = true;
        }
    }


    if (array[horse_choice].get_wins() < 5) { // If the horse has not won 5
        cout << "This Horse Does Not Have 5 Wins and Can Not Be Added To Hall Of Fame!" << endl;
        } else {
        add_to_hof(horse_choice);
        this_thread::sleep_for(chrono::seconds(1));
        cout << "\n"<<array[horse_choice].get_name()<<" Has Been Added To The Hall Of Fame " << endl;
        this_thread::sleep_for(chrono::seconds(1));

    }
    

    int return_hof;
    bool inputing = false;

    while (inputing == false) { // While loop to return to the main menu
        this_thread::sleep_for(chrono::seconds(1));
        cout <<"\nPress 9 to Return To Main Menu: " ;

        if (!(cin >> return_hof)){
            cin.clear();
            cin.ignore();
        }
        if (return_hof==9){
            return;
        }

    if (return_hof!=9){
        cout << "Invalid Input!";
        this_thread::sleep_for(chrono::seconds(1));
    }
}
}

void stable::add_to_hof(int horse_choice){ // Adds the horse to the hall of fame
        ofstream outFile("halloffame.txt",ios::app);

        if (outFile.is_open()) {
            outFile << array[horse_choice].get_name() << endl;
        }
    outFile.close();
}

stable::~stable(){
    delete[] array;
}