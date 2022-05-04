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
        const sf::Shape& getShape() const;

        void tick(double deltaTime);
    private:
        inline static const int RES_VERTICES = 2;
        inline static const int MIN_VERTICES = 3;
        inline static const int MAX_VERTICES = 256;

        const float size;
        const double density;
        sf::Vector2f position;
        sf::CircleShape shape;
    private:
        inline static int getPointCount(float size);
};


#endif
