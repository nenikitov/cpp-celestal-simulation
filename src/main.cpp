#include <iostream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "body/Body.hpp"
#include "universe/Universe.hpp"
#include "utils/Utils.hpp"


int main()
{
    cs::Universe universe({
        cs::Body(32, 5.98, cs::Vector2d(500, 360), cs::Vector2d(0, 0)),       // Big
        cs::Body(8,  3.37, cs::Vector2d(678, 360), cs::Vector2d(0, 6.827e-2)) // Small
    });

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Celestial Simulation");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        universe.tick(0.0001);


        window.clear();
        for (cs::Body body : universe.getBodies())
        {
            window.draw(body.getShape());
        }
        window.display();
    }

    return 0;
}
