#include "game.h"

#include <iostream>
using namespace std;

game::game() {
  choice = 0;
  playing = true;
  file_name = "gamesave.txt";
}

int game::get_playing() { return playing; }

void game::initialize_game() {
  string name;
  cout << "Enter name for user: ";
  cin >> name;
  user.initialize(name);

  stable stable;
  stable.initialize();
  stable.add_horse(userhorse()) ;

  string horse_name;

  cout<<"What Would You Like To Name Your First Horse:";
  cin>>horse_name;
  stable[0].set_name(horse_name);
  cout<<stable[0].get_name()<<endl;
  
}

void game::travel_menu() {
  cout << endl;
  cout << "Where Would You Like to Travel?" << endl;
  cout << "1: Stables" << endl;
  cout << "2: Racetrack" << endl;
  cout << "3: Market" << endl;
  cout << "4: Blacksmith" << endl;
  cout << "9: Return to Main Menu" << endl;

  cout << endl;
  cout << "Choice:";

  cin >> choice;

  switch (choice) {
    case 1:
    cout<< "stables";
      break;
    case 2:
      break;
    case 3:
      break;
    default:
      break;
    case 9:
      main_menu();
  }
}

void game::main_menu() {
  cout << "************ MAIN MENU ******" << endl;
  cout << "0: Travel" << endl;
  ;
  cout << "1: Level Up" << endl;
  cout << "2: User Stats" << endl;
  cout << "3: Save Game" << endl;
  cout << "4: Load Game" << endl;

  cout << "9: Quit" << endl;
  cout << endl;
  cout << "Choice:";

  cin >> choice;

  switch (choice) {
    case 0:
      travel_menu();
      break;
    case 2:
      user.print_user_stats();
      cout << "9: Return to Main Menu" << endl;

      cout << endl;
      cout << "Choice:";
      cin >> choice;
      if (choice == 9) {
        main_menu();
      }

      break;
	case 3:
	save_game();
		break;

	case 4: 

		break;
    case 9:
      playing = false;
      break;
    default:
      break;
  }
}

void game::save_game(){
	ofstream outFile(file_name);

	if(outFile.is_open()){
		outFile<<user.get_as_string();
	}
	outFile.close();
}

void game::load_game(){
	
}