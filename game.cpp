#include "game.h"
#include "functions.cpp"
#include <chrono>
#include <iostream>
#include <thread>
#include <string>

using namespace std;

game::game() {
  // Choice = 0;
  playing = true;
  file_name = "gamesave.txt";
}

int game::get_playing() { 
  return playing; 
}

void game::initialize_game() {
  // Setting up user
  welcome(); // Outputs welcome message
  string name;
  cout << "Enter Name For User: "; // Asks user for name
  getline(cin, name);
  user.initialize(name);

  // Setting up stables with first horse
  string horse_name;
  cout << "Enter Name For Your First Horse: "; // Asks user for horse name
  getline(cin, horse_name);

  userhorse h1 = userhorse();
  h1.set_userhorse(horse_name, 16.7, 12.2);
  user.add_horse_to_stable(h1);
  this_thread::sleep_for(chrono::seconds(2)); // Delays for 2 seconds
  cout << endl << h1.get_name() << " Has Been Added To Stables" << endl;
  this_thread::sleep_for(chrono::seconds(2));
  system("Clear");

  // Creating shop
  item Carrot = item("Carrot", 100, 0.5);  // Carrot makes slowest time faster
  item Sugar = item("Sugar", 250, 1);      // Sugar makes faster time faster
  item Saddle = item("Apple", 600, 2);     // Saddle increases both by 0.5
  shop.initialize(Carrot, Sugar, Saddle);

  // Creating market
  userhorse m1 = userhorse();
  userhorse m2 = userhorse();
  userhorse m3 = userhorse();
  userhorse m4 = userhorse();
  userhorse m5 = userhorse();

  m1.set_userhorse("Turtle", 8.5, 7);
  m1.set_price(100);
  m2.set_userhorse("Dog", 10.5, 7.9);
  m2.set_price(250);
  m3.set_userhorse("Legend", 15.5, 11.25);
  m3.set_price(600);
  m4.set_userhorse("Bullet", 18.5, 16.0);
  m4.set_price(1000);
  m5.set_userhorse("God", 20, 17.75);
  m5.set_price(3000);

  market.initialize(m1, m2, m3, m4, m5);
}

void game::travel_menu() {
  system("Clear");
  cout << "Where Would You Like to Travel?" << endl;
  cout << "1: Stables" << endl;
  cout << "2: Racetrack" << endl;
  cout << "3: Horse Market" << endl;
  cout << "4: Boost Store" << endl;
  cout << "5: Breeding Ground" << endl;
  cout << "9: Return to Main Menu" << endl;

  int user_choice_travel;
  string choice;

  bool input = false;

  while (input == false) {
        cout << "Choice:";
        cin >> choice;
      while(!check_number(choice)) {
        cout << "Invalid input, choose again: ";
        cin >> choice;
      }
        user_choice_travel = stoi(choice);
  
    if (user_choice_travel != 1 && user_choice_travel != 2 &&
        user_choice_travel != 3 && user_choice_travel != 4 &&
        user_choice_travel != 5 && user_choice_travel != 6 &&
        user_choice_travel != 9) {
      cout << "Invalid!\n\n";
      this_thread::sleep_for(chrono::seconds(1));

    } else {
      input = true;
    }
  }

  switch (user_choice_travel) { // Calls travel function
    case 1:
      user.call_stable_menu();
      break;
    case 2:
      racetrack_menu();
      break;
    case 3:
      market_menu();
      break;
    case 4:
      shop_menu();
      break;
    case 5:
      breed_menu();
      break;
    case 9:
      return;
  }
}

void game::shop_menu() {
  int return_shop;
  shop.print_store();
  item new_item = shop.get_item();
  if (new_item.get_name() != "") {
    user.purchase_item(new_item);
  }


bool input = false;
  string choice;
  while (input == false) {
    cout << "\n\nPress 9 to Return To Main Menu: ";
    cin >> choice;
      while(!check_number(choice)) {
        cout << "Invalid input, choose again: ";
        cin >> choice;
      }
        return_shop = stoi(choice);

    if (return_shop == 9) {
      return;
    }

    if (return_shop != 9) {
      cout << "Invalid Input!";
      this_thread::sleep_for(chrono::seconds(1));
    }
  }
}

void game::market_menu() {
  int return_market;
  market.print_market();
  userhorse new_horse = market.get_horse();

  if (new_horse.get_name() != "") {
    user.purchase_horse(new_horse);
  }
    bool input = false;
  string choice;
  while (input == false) {
    cout << "\n\nPress 9 to Return To Main Menu: ";
    cin >> choice;
      while(!check_number(choice)) {
        cout << "Invalid input, choose again: ";
        cin >> choice;
      }
        return_market = stoi(choice);

    if (return_market == 9) {
      return;
    }

    if (return_market != 9) {
      cout << "Invalid Input!";
      this_thread::sleep_for(chrono::seconds(1));
    }
  }
}



void game::main_menu() {
  bool playing = true;
  while (playing == true) {
    system("Clear");
    cout << "********* MAIN MENU *********" << endl;
    cout << "1: Travel" << endl;
    cout << "2: Inventory" << endl;
    cout << "3: Level Up" << endl;
    cout << "4: User Stats" << endl;
    cout << "5: Save Game" << endl;
    cout << "6: Hooves Of Fame" << endl;
    cout << "9: Quit" << endl;
    cout << endl;

    int user_choice;
    string choice;

    bool input = false;

    while (input == false) {
      cout << "Choice:";
      cin >> choice;
      while(!check_number(choice)) {
        cout << "Invalid input, choose again: ";
        cin >> choice;
      }
        user_choice = stoi(choice);

      if (user_choice != 1 && user_choice != 2 && user_choice != 3 &&
          user_choice != 4 && user_choice != 5 && user_choice != 6 &&
          user_choice != 9) {
        cout << "Invalid!\n\n";
        this_thread::sleep_for(chrono::seconds(3));
        break;
      } else {
        input = true;
      }
    }
    switch (user_choice) {
      case 1:
        travel_menu();
        break;
      case 2:
        inventory_menu();
        break;
      case 3:
        get_level_up_menu();
        break;
      case 4:
        user_stats_menu();
        break;
      case 5:
        save_game();
        break;
      case 6:
        hof_menu();
        break;
      case 9:
        playing = false;
        break;
    }
  }
}

void game::save_game() {
  ofstream outFile(file_name, ios::app);

  if (outFile.is_open()) {
    outFile << user.get_as_string() << endl;
  }
  outFile.close();
}

void game::load_game() {
  ifstream outFile(file_name, ios::in);
  if (outFile.is_open()) {
  }
}

void game::breed_menu() {
  user.breeding();

  int return_breed;
  bool input = false;
  string choice;
  while (input == false) {
    cout << "\n\nPress 9 to Return To Main Menu: ";
    cin >> choice;
      while(!check_number(choice)) {
        cout << "Invalid input, choose again: ";
        cin >> choice;
      }
        return_breed = stoi(choice);

    if (return_breed == 9) {
      return;
    }

    if (return_breed != 9) {
      cout << "Invalid Input!";
      this_thread::sleep_for(chrono::seconds(1));
    }
  }
}

void game::welcome() { // Welcome message
  system("Clear");
  cout << " /$$      /$$           /$$" << endl;
  cout << "| $$  /$ | $$          | $$" << endl;
  cout << "| $$ /$$$| $$  /$$$$$$ | $$  /$$$$$$$  /$$$$$$  /$$$$$$/$$$$   /$$$$$$ "<< endl;
  cout << "| $$/$$ $$ $$ /$$__  $$| $$ /$$_____/ /$$__  $$| $$_  $$_  $$ /$$__  $$"<< endl;
  cout << "| $$$$_  $$$$| $$$$$$$$| $$| $$      | $$  | $$| $$ | $$ | $$| $$$$$$$$"<< endl;
  cout << "| $$$/ |  $$$| $$_____/| $$| $$      | $$  | $$| $$ | $$ | $$| $$_____/"<< endl;
  cout << "| $$/   |  $$|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$ | $$ | $$|  $$$$$$$"<< endl;
  cout << "|__/     |_/ |_______/|__/ |_______/ |______/ |__/ |__/ |__/ |_______/"<< endl;
  this_thread::sleep_for(chrono::seconds(1));

  cout << "                       /$$$$$$$$   " << endl;
  cout << "                      |__  $$__/    " << endl;
  cout << "                          | $$  /$$$$$$ " << endl;
  cout << "                          | $$ /$$__  $$" << endl;
  cout << "                          | $$| $$  | $$" << endl;
  cout << "                          | $$| $$  | $$" << endl;
  cout << "                          | $$|  $$$$$$/" << endl;
  cout << "                          |__/|______/ " << endl;
  this_thread::sleep_for(chrono::seconds(1));

  cout << " /$$$$$$$$|      /$$   /$$  /$$$$$$  /$$$$$$$   /$$$$$$  /$$$$$$$$  /$$$$$$  /$$"<< endl;
  cout << "| $$_____/      | $$  | $$ /$$__  $$| $$__  $$ /$$__  $$| $$_____/ /$$__  $$| $$"<< endl;
  cout << "| $$            | $$  | $$| $$  | $$| $$  | $$| $$  |__/| $$      | $$  |__/| $$"<< endl;
  cout << "| $$$$$         | $$$$$$$$| $$  | $$| $$$$$$$/|  $$$$$$ | $$$$$   |  $$$$$$ | $$" << endl;
  cout << "| $$__/         | $$__  $$| $$  | $$| $$__  $$ |____  $$| $$__/   |____  $$|__/"<< endl;
  cout << "| $$            | $$  | $$| $$  | $$| $$  | $$ /$$  | $$| $$       /$$  | $$    "<< endl;
  cout << "| $$$$$$$$      | $$  | $$|  $$$$$$/| $$  | $$|  $$$$$$/| $$$$$$$$|  $$$$$$/ /$$"<<endl;
  cout << "|________/      |__/  |__/ |______/ |__/  |__/ |______/ |________/ |______/ |__/"<< endl;
  this_thread::sleep_for(chrono::seconds(3));
  system("Clear");
}

void game::inventory_menu() { // Displays inventory
  user.print_inventory();
  int leave;

  bool input = false;


  string choice;
  while (input == false) {
    cout << "\n\nPress 9 to Return To Main Menu: ";
    cin >> choice;
      while(!check_number(choice)) {
        cout << "Invalid input, choose again: ";
        cin >> choice;
      }
        leave = stoi(choice);

    if (leave == 9) {
      return;
    }

    if (leave != 9) {
      cout << "Invalid Input!";
      this_thread::sleep_for(chrono::seconds(1)); // Delays for one second
    }
  }
}

void game::user_stats_menu() { // Displays user stats
  int leave_stats;

  user.print_user_stats();
  bool input = false;
  string choice;
  while (input == false) {
    cout << "\n\nPress 9 to Return To Main Menu: ";
    cin >> choice;
      while(!check_number(choice)) {
        cout << "Invalid input, choose again: ";
        cin >> choice;
      }
        leave_stats = stoi(choice);

    if (leave_stats == 9) {
      return;
    }

    if (leave_stats != 9) {
      cout << "Invalid Input!";
      this_thread::sleep_for(chrono::seconds(1));
    }
  }
}

void game::racetrack_menu() { // Displays racetrack menu
  system("Clear");

  cout << " /$$$$$$$                                      /$$$$$$$$                           /$$       "<< endl;
  cout << "| $$__  $$                                    |__  $$__/                          | $$       "<< endl;
  cout << "| $$  | $$  /$$$$$$   /$$$$$$$  /$$$$$$          | $$  /$$$$$$  /$$$$$$   /$$$$$$$| $$   /$$"<< endl;
  cout << "| $$$$$$$/ |____  $$ /$$_____/ /$$__  $$         | $$ /$$__  $$|____  $$ /$$_____/| $$  /$$/"<< endl;
  cout << "| $$__  $$  /$$$$$$$| $$      | $$$$$$$$         | $$| $$  |__/ /$$$$$$$| $$      | $$$$$$/  "<< endl;
  cout << "| $$  | $$ /$$__  $$| $$      | $$_____/         | $$| $$      /$$__  $$| $$      | $$_  $$  "<< endl;
  cout << "| $$  | $$|  $$$$$$$|  $$$$$$$|  $$$$$$$         | $$| $$     |  $$$$$$$|  $$$$$$$| $$ |  $$"<< endl;
  cout << "|__/  |__/ |_______/ |_______/ |_______/         |__/|__/      |_______/ |_______/|__/  |__/" << endl;
  // Get division to pass into functions
  int division;
  bool input = false;

  this_thread::sleep_for(chrono::seconds(1));
  cout << "\n** Choose The Division You Wish To Race In **";
  this_thread::sleep_for(chrono::seconds(1));
  cout << "\n\n* Division 1: Easy \n* Division 2: Medium \n* Division 3: Hard\n\n";

  this_thread::sleep_for(chrono::seconds(1));
  cout << "* Division 1 *"; // Winnings for divison 1
  cout << "\nPrize Money = 500 for win";
  cout << "\nExp = 100 for win\n\n";
  this_thread::sleep_for(chrono::seconds(1));

  cout << "* Division 2 *"; // Winnings for division 2
  cout << "\nPrize Money = 1000 for win";
  cout << "\nExp = 250 for win\n\n";
  this_thread::sleep_for(chrono::seconds(1));

  cout << "* Division 3 *"; // Winnings for division 3
  cout << "\nPrize Money = 1500 for win";
  cout << "\nExp = 500 for win\n\n";
  this_thread::sleep_for(chrono::seconds(1));

  while (input == false) {
    cout << "Choose Your Race Division: ";
    if (!(cin >> division)) {
      cin.clear();
      cin.ignore();
    }

    if (division != 1 && division != 2 && division != 3) {
      cout << "Invalid\n\n";
    } else {
      input = true;
    }
  }

  cout << "\n\nYour stables: " << endl;
  this_thread::sleep_for(chrono::seconds(1));
  userhorse* ptr = user.get_horse_for_race();
  
  double boost_amount;

  int boost_choice;
  bool input2 = false;
  string choice;
  while (input2 == false) {
      cout << "\n Do You Want To Add A Boost To Your Horse ";
      
      cout << "\n 1. Yes";
      cout << "\n 2. No\n\n";
      this_thread::sleep_for(chrono::seconds(1));
      cout << "Choice: ";
      cin >> choice;

    while(!check_number(choice)) {
          cout << "Invalid input, choose again: ";
          cin >> choice;
        }
    boost_choice = stoi(choice);
      
      if (boost_choice != 1 && boost_choice !=2) {
        cout << "Invalid Input!";
        this_thread::sleep_for(chrono::seconds(1));
      }

      if (boost_choice == 1) {
          item boost = user.boost_menu();
          boost_amount = boost.get_boost();

        if(boost_amount>0){
          cout << "Boost of " << boost_amount << " Has Been Applied!\n" << endl;
          this_thread::sleep_for(chrono::seconds(1));
          input2 = true;

        } else  {
        cout<<"No Boost Applied\n"<<endl;
          input2 = true;

      }
    }
    }

  srand(time(NULL));
  comphorse c1;

  c1.set_div(division); // Sets division for computer horses
  c1.set_bot_names(division); // Sets computer horse names
  c1.set_rand_race_time(); // Sets random race time (virtual function)
  ptr->set_rand_race_time(); 
  

  ptr->add_boost(boost_amount);

  User* user_ptr = &user;

  cout << "\nHorses are racing..." << endl;
  this_thread::sleep_for(chrono::seconds(2));
  cout << "..." << endl;
  this_thread::sleep_for(chrono::seconds(2));
  cout << "..." << endl << endl;
  this_thread::sleep_for(chrono::seconds(2));

  racetrack.get_winner(c1, ptr, user_ptr);
  this_thread::sleep_for(chrono::seconds(1));

  return;
}

void game::get_level_up_menu() { user.level_up_menu(); }

void game::hof_menu() {
  system("Clear");
  cout << " /$$   /$$                                                          /$$$$$$   /$$$$$$        /$$$$$$$$ "<< endl;
  cout << "| $$  | $$                                                         /$$__  $$ /$$__  $$      | $$_____/ "<< endl;
  cout << "| $$  | $$  /$$$$$$   /$$$$$$  /$$    /$$ /$$$$$$   /$$$$$$$      | $$  | $$| $$  |__/      | $$    /$$$$$$  /$$$$$$/$$$$   /$$$$$$  "<< endl;
  cout << "| $$$$$$$$ /$$__  $$ /$$__  $$|  $$  /$$//$$__  $$ /$$_____/      | $$  | $$| $$$$          | $$$$$|____  $$| $$_  $$_  $$ /$$__  $$ "<< endl;
  cout << "| $$__  $$| $$  | $$| $$  | $$ |  $$/$$/| $$$$$$$$|  $$$$$$       | $$  | $$| $$_/          | $$__/ /$$$$$$$| $$ | $$ | $$| $$$$$$$$ "<< endl;
  cout << "| $$  | $$| $$  | $$| $$  | $$  |  $$$/ | $$_____/ |____  $$      | $$  | $$| $$            | $$   /$$__  $$| $$ | $$ | $$| $$_____/ "<< endl;
  cout << "| $$  | $$|  $$$$$$/|  $$$$$$/   |  $/  |  $$$$$$$ /$$$$$$$/      |  $$$$$$/| $$            | $$  |  $$$$$$$| $$ | $$ | $$|  $$$$$$$"<< endl;
  cout << "|__/  |__/ |______/  |______/     |_/    |_______/|_______/        |______/ |__/            |__/   |_______/|__/ |__/ |__/ |_______/ "<< endl;

  this_thread::sleep_for(chrono::seconds(1));
  cout << "\n\n1. View Hooves Of Fame" << endl;
  cout << "2. Add Horse To Hall Of Fame" << endl;
  cout << "\n9. Return To Main Menu";

  bool input = false;
  int hof_choice;
  while (input == false) {
    cout << "\nChoice: " << endl;
    if (!(cin >> hof_choice)) {
      cin.clear();
      cin.ignore();
    }

    if (hof_choice == 9) {
      return;
    }

    if (hof_choice != 1 && hof_choice != 2 && hof_choice != 9) {
      cout << "Invalid\n\n";
    } else {
      input = true;
    }
  }
  if (hof_choice == 1) {
    fstream myFile;
    myFile.open("halloffame.txt", ios::in);
    if (myFile.is_open()) {
      string line;
      system("Clear");
      cout << "** Hooves Of Fame List **\n" << endl;

      while (getline(myFile, line)) {
        cout << line << endl;
      }
      myFile.close();
    }
    bool input = false;
    int leave_view;
    while (input == false) {
      cout << "\n\nPress 9 to Return To Main Menu: ";

      if (!(cin >> leave_view)) {
        cin.clear();
        cin.ignore();
      }
      if (leave_view == 9) {
        return;
      } else {
        cout << "Invalid Input!";
        this_thread::sleep_for(chrono::seconds(1));
      }
    }
  }

  else if (hof_choice == 2) {
    user.add_to_hof();
    return;
  }
}