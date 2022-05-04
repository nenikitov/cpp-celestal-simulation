#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "body/Body.hpp"
#include "utils/Utils.hpp"


int main()
{
    cs::Body planet(128, cs::Vector2d(0, 0));

    sf::RenderWindow window(sf::VideoMode(500, 500), "Celestial Simulation");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(planet.getShape());
        window.display();
    }

    return 0;
}
