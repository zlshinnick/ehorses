#include <SFML/Graphics.hpp>
#include "comphorse_yifan.h"
#include "userhorse.h"
#include "racetrack.h"
#include "user.h"
#include "horse.h"

 int main ()
{
    sf::RenderWindow window(sf::VideoMode(1800, 440), "My Program");
    window.setFramerateLimit(60);

    sf::Texture horse;
    horse.loadFromFile("horse2.png");

    sf::Texture horseSheet;
    horseSheet.loadFromFile("croppedSheet.png");

    sf::Texture background;
    background.loadFromFile("grass2.png");
    background.setRepeated(true);

    sf::IntRect backgroundRect(0, 0, 1800, 440);

    sf::Sprite backgrounds(background, backgroundRect);

    sf::IntRect rectSourceSprite(0, 0, 225, 150);

    sf::Sprite horse1(horseSheet, rectSourceSprite);
    sf::Sprite horse2(horseSheet, rectSourceSprite);
    sf::Sprite horse3(horseSheet, rectSourceSprite);
    sf::Sprite horse4(horseSheet, rectSourceSprite);
    sf::Sprite horse5(horseSheet, rectSourceSprite);
    sf::Sprite horse6(horseSheet, rectSourceSprite);
    sf::Sprite horse7(horseSheet, rectSourceSprite);
    sf::Sprite horse8(horseSheet, rectSourceSprite);

    sf::Clock clock;

    horse1.setColor(sf::Color(255, 0, 0, 255));

    horse2.setColor(sf::Color(0, 0, 0, 255));
    horse3.setColor(sf::Color(0, 0, 0, 255));
    horse4.setColor(sf::Color(0, 0, 0, 255));
    horse5.setColor(sf::Color(0, 0, 0, 255));
    horse6.setColor(sf::Color(0, 0, 0, 255));
    horse7.setColor(sf::Color(0, 0, 0, 255));
    horse8.setColor(sf::Color(0, 0, 0, 255));
 
    sf::Vector2f Position7(0, 0);
    sf::Vector2f Position6(0, 55);
    sf::Vector2f Position3(0, 110);
    sf::Vector2f Position8(0, 165);
    sf::Vector2f Position5(0, 220);
    sf::Vector2f Position2(0, 275);
    sf::Vector2f Position1(0, 330);
    sf::Vector2f Position4(0, 385);

 
    horse1.setPosition(0, 330);
    horse1.setScale(0.5, 0.5);
    horse2.setPosition(Position2);
    horse2.setScale(0.5, 0.5);
    horse3.setPosition(Position3);
    horse3.setScale(0.5, 0.5);
    horse4.setPosition(Position4);
    horse4.setScale(0.5, 0.5);
    horse5.setPosition(Position5);
    horse5.setScale(0.5, 0.5);
    horse6.setPosition(Position6);
    horse6.setScale(0.5, 0.5);
    horse7.setPosition(Position7);
    horse7.setScale(0.5, 0.5);
    horse8.setPosition(Position8);
    horse8.setScale(0.5, 0.5);
 
    float xVelocity1 = racetrack_times[0];
    float xVelocity2 = 6;
    float xVelocity3 = 5; 
    float xVelocity4 = 7; 
    float xVelocity5 = 5.5; 
    float xVelocity6 = 6.6; 
    float xVelocity7 = 5.3; 
    float xVelocity8 = 7.2; 

 
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) window.close();
 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }

        if(clock.getElapsedTime().asSeconds() > 0.07f) {
            if (rectSourceSprite.left >= 1350)
                rectSourceSprite.left = 0;
            else
                rectSourceSprite.left += 225;
            horse1.setTextureRect(rectSourceSprite);
            horse2.setTextureRect(rectSourceSprite);
            horse3.setTextureRect(rectSourceSprite);
            horse4.setTextureRect(rectSourceSprite);
            horse5.setTextureRect(rectSourceSprite);
            horse6.setTextureRect(rectSourceSprite);
            horse7.setTextureRect(rectSourceSprite);
            horse8.setTextureRect(rectSourceSprite);
            clock.restart();
        }
        //"physics"
 
        Position1.x += xVelocity1;
        horse1.setPosition(Position1);

        Position2.x += xVelocity2;
        horse2.setPosition(Position2);

        Position3.x += xVelocity3;
        horse3.setPosition(Position3);

        Position4.x += xVelocity4;
        horse4.setPosition(Position4);

        Position5.x += xVelocity5;
        horse5.setPosition(Position5);

        Position6.x += xVelocity6;
        horse6.setPosition(Position6);

        Position7.x += xVelocity7;
        horse7.setPosition(Position7);

        Position8.x += xVelocity8;
        horse8.setPosition(Position8);
 
        //render
        window.clear();
                window.draw(backgrounds);

        window.draw(horse1);
        window.draw(horse2);
        window.draw(horse3);
        window.draw(horse4);
        window.draw(horse5);
        window.draw(horse6);
        window.draw(horse7);
        window.draw(horse8);

        window.display();
    }
 
  
 
    return 0;
}