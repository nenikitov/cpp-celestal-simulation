#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "body/Body.hpp"


int main()
{
    Body planet(100, sf::Vector2f(100, 100));

    sf::RenderWindow window(sf::VideoMode(500, 500), "Celestial Simulation");
    sf::CircleShape shape(planet.getSize());
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
