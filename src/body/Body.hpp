#ifndef Body_H
#define Body_H


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "entity/Entity.hpp"
#include "utils/Utils.hpp"


namespace cs
{
    class Body : public cs::Entity
    {
        public:
            Body(double size, double density, cs::sfVector2d position, cs::sfVector2d velocity);
            Body(double size, cs::sfVector2d position, double density);
            Body(double size, cs::sfVector2d position, cs::sfVector2d velocity);
            Body(double size, cs::sfVector2d position);
            Body() = delete;

            const cs::sfVector2d& getPosition() const;
            const sf::Shape& getShape() const;

            double getMass() const;
            void applyForce(const cs::sfVector2d& force, double deltaTime);

        protected:
            void physicsTick(double deltaTime);
            void graphicsTick();

        private:
            inline static const int RES_VERTICES = 4;
            inline static const int MIN_VERTICES = 3;
            inline static const int MAX_VERTICES = 256;

            const double size;
            const double density;
            cs::sfVector2d position;
            cs::sfVector2d acceleration;
            cs::sfVector2d velocity;
            sf::CircleShape shape;
        private:
            inline static int getPointCount(float size);
    };
};


#endif
