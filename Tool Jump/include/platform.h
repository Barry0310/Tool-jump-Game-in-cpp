#pragma once
#include<SFML/Graphics.hpp>
#include "collision.h"

class platform
{
    public:
        platform(sf::Texture* texture,float randomx,float randomy,float point);
        ~platform();
        void Draw(sf::RenderWindow &window);
        /////stairs move//////
        void Move(float Movee);
        //////////////
        collision GetCollider(){return collision(stair);}
        float Getposition(){return stair.getPosition().y;}

    private:
        sf::RectangleShape stair;
};
