#ifndef Universe_H
#define Universe_H


#include <vector>

#include "entity/Entity.hpp"
#include "body/Body.hpp"


namespace cs
{
    class Universe : public cs::Entity
    {
        public:
            Universe(std::vector<cs::Body> bodies);
            Universe();

            const std::vector<cs::Body>& getBodies() const;
            const std::vector<cs::Body>& getBodies();

        protected:
            void physicsTick(double deltaTime);
            void graphicsTick();

        private:
            inline const static double M_G = 100;

            //const std::vector<cs::Body> bodies;
            std::vector<cs::Body> bodies;
    };
};


#endif
