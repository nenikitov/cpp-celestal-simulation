#ifndef Body_H
#define Body_H


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "utils/Utils.hpp"


class Body
{
    public:
        Body(double size, double density, cs::Vector2d position, cs::Vector2d velocity);
        Body(double size, cs::Vector2d position, double density);
        Body(double size, cs::Vector2d position);
        Body() = delete;
        Body(Body& other) = delete;

        const sf::Shape& getShape() const;

        void tick(double deltaTime);
        void applyForce(const cs::Vector2d& force);
    private:
        inline static const int RES_VERTICES = 2;
        inline static const int MIN_VERTICES = 3;
        inline static const int MAX_VERTICES = 256;

        const double size;
        const double density;
        cs::Vector2d position;
        cs::Vector2d acceleration;
        cs::Vector2d velocity;
        sf::CircleShape shape;
    private:
        inline static int getPointCount(float size);
        double getMass() const;
};


#endif
