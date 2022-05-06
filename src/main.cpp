#include <iostream>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "body/Body.hpp"
#include "universe/Universe.hpp"
#include "utils/Vector2/Vector2.hpp"
#include "utils/Utils.hpp"


int main()
{
    cs::Vector2d test(3, 4);
    std::cout << test.length() << std::endl;

    cs::Universe universe({
        cs::Body(32, 6, cs::sfVector2d(500, 360), cs::sfVector2d(0, 0)),    // Big
        cs::Body(8,  3, cs::sfVector2d(700, 360), cs::sfVector2d(0, 3e-1)),  // Small
        cs::Body(16,  1, cs::sfVector2d(800, 360), cs::sfVector2d(0, 0))  // Small
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


        universe.tick(0.02);


        window.clear();
        for (cs::Body body : universe.getBodies())
        {
            window.draw(body.getShape());
        }
        window.display();
    }

    return 0;
}
