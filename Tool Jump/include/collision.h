#pragma once
#include<SFML/Graphics.hpp>

class collision
{
    public:
        collision(sf::RectangleShape& body);
        ~collision();

        void Move(float dx,float dy){body.move(dx,dy);}
        bool checkcollision(collision  other,sf::Vector2f& derection,float push);

        sf::Vector2f GetPosition(){return body.getPosition();}
        sf::Vector2f GetHalfsize(){return body.getSize()/2.0f;}

    private:
        sf::RectangleShape& body;
};
