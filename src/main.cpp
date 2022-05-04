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
        cs::Body(128, cs::Vector2d(480, 500)),                      // Big
        cs::Body(20, cs::Vector2d(900, 500), cs::Vector2d(0, -1))   // Small
    });

    sf::RenderWindow window(sf::VideoMode(960, 1080), "Celestial Simulation");

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


        universe.tick(1);


        window.clear();
        for (cs::Body body : universe.getBodies())
        {
            window.draw(body.getShape());
        }
        window.display();
    }

    return 0;
}
