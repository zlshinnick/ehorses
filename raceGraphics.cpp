#include <SFML/Graphics.hpp>
#include "comphorse_yifan.h"

 int main ()
{
    sf::RenderWindow window(sf::VideoMode(1800, 440), "My Program");
    window.setFramerateLimit(60);
 
    sf::RectangleShape horse1;
    sf::RectangleShape horse2;
    sf::RectangleShape horse3;
    sf::RectangleShape horse4;
    sf::RectangleShape horse5;
    sf::RectangleShape horse6;
    sf::RectangleShape horse7;
    sf::RectangleShape horse8;

    horse8.setFillColor(sf::Color::Green);

 
    sf::Vector2f rectanglePosition7(0, 0);
    sf::Vector2f rectanglePosition6(0, 55);
    sf::Vector2f rectanglePosition3(0, 110);
    sf::Vector2f rectanglePosition8(0, 165);
    sf::Vector2f rectanglePosition5(0, 220);
    sf::Vector2f rectanglePosition2(0, 275);
    sf::Vector2f rectanglePosition1(0, 330);
    sf::Vector2f rectanglePosition4(0, 385);

 
    horse1.setPosition(rectanglePosition1);
    horse1.setSize(sf::Vector2f(100, 50));
    horse2.setPosition(rectanglePosition2);
    horse2.setSize(sf::Vector2f(100, 50));
    horse3.setPosition(rectanglePosition3);
    horse3.setSize(sf::Vector2f(100, 50));
    horse4.setPosition(rectanglePosition4);
    horse4.setSize(sf::Vector2f(100, 50));
    horse5.setPosition(rectanglePosition5);
    horse5.setSize(sf::Vector2f(100, 50));
    horse6.setPosition(rectanglePosition6);
    horse6.setSize(sf::Vector2f(100, 50));
    horse7.setPosition(rectanglePosition7);
    horse7.setSize(sf::Vector2f(100, 50));
    horse8.setPosition(rectanglePosition8);
    horse8.setSize(sf::Vector2f(100, 50));
 
    float xVelocity1 = 4.5;
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
        //"physics"
 
        rectanglePosition1.x += xVelocity1;
        horse1.setPosition(rectanglePosition1);

        rectanglePosition2.x += xVelocity2;
        horse2.setPosition(rectanglePosition2);

        rectanglePosition3.x += xVelocity3;
        horse3.setPosition(rectanglePosition3);

        rectanglePosition4.x += xVelocity4;
        horse4.setPosition(rectanglePosition4);

        rectanglePosition5.x += xVelocity5;
        horse5.setPosition(rectanglePosition5);

        rectanglePosition6.x += xVelocity6;
        horse6.setPosition(rectanglePosition6);

        rectanglePosition7.x += xVelocity7;
        horse7.setPosition(rectanglePosition7);

        rectanglePosition8.x += xVelocity8;
        horse8.setPosition(rectanglePosition8);
 
        //render
        window.clear();
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