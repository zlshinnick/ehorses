#include "game.h"
#include "user.h"
#include "math.h"
#include "stable.h"
int main() {

    srand(time(NULL)); // Seed random number generator

    game game; // Create game object
    game.initialize_game(); // Initialise game
    game.main_menu(); // Display main menu

    
}