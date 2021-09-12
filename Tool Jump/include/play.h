#pragma once
#include <SFML/Graphics.hpp>

class play
{
    public:
        play(sf::Texture* texture,sf::Vector2u imagecount);
        ~play();
        void update(int row,bool toolright,float jump);
    public:
        sf::IntRect uvrect;
    private:
        sf::Vector2u imagecount,currentimage;
};

