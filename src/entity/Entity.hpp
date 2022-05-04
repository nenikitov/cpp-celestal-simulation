#ifndef Entity_H
#define Entity_H


namespace cs
{
    class Entity
    {
        public:
            void tick(double deltaTime);

        protected:
            virtual void physicsTick(double deltaTime) = 0;
            virtual void graphicsTick() = 0;
    };
};


#endif
