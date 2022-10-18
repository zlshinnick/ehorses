#include "comphorse_yifan.h"
#include "racetrack.h"
#include "horse.h"
#include "user.h"
#pragma once
#include <SFML/Graphics.hpp>

class graphics : public Racetrack {
    graphics();

    void draw_horses(Racetrack track); // Function to draw horses
};    