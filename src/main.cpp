#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "body/Body.hpp"


int main()
{
    Body planet(128, sf::Vector2f(100, 100));

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
