#ifndef Body_H
#define Body_H


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


class Body
{
    public:
        Body(float size, sf::Vector2f position, double density);
        Body(float size, sf::Vector2f position);
        Body() = delete;
        Body(Body& other) = delete;

        float getSize() const;
        double getDensity() const;
        const sf::Drawable& getShape() const;

        void tick(double deltaTime);
    private:
        const float size;
        const double density;
        sf::Vector2f position;
        sf::CircleShape shape;
};


#endif
