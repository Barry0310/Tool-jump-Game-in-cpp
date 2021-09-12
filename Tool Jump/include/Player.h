#pragma once
#include <SFML/Graphics.hpp>
#include"play.h"
#include "collision.h"

class Player
{
    public:
        Player(sf::Texture* texture,sf::Vector2u imagecount,float speed);
        ~Player();
        void Update(float deltatime);
        void Draw(sf::RenderWindow &window);
        void Oncollition(sf::Vector2f derection);

        float JumpTooHigh();

        void Reset();

        sf::Vector2f GetPosition(){return tool.getPosition();}
        collision GetCollider(){return collision(tool);}
        sf::Vector2f velocity={};

    private:
        play play;
        sf::RectangleShape tool;
        bool toolright;
        float speed;
        float widght=63,height=60;
        float x=200,y=530;
        float movee=200;
        float TooHigh;
        bool canjump=false;
};
