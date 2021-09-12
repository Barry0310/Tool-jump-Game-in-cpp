#include "platform.h"
#include <stdlib.h>
platform::platform(sf::Texture* texture,float randomx,float randomy,float point)
{
    stair.setTexture(texture);
    stair.setPosition(randomx,point+randomy);
    stair.setSize(sf::Vector2f(60.0f,15.0f));
    stair.setOrigin(stair.getSize()/2.0f);
}
platform::~platform()
{
}
void platform::Move(float Movee)
{
    sf::Vector2f jj;
    jj.x=0.0f;
    jj.y=Movee;
    stair.move(jj);
}
void platform::Draw(sf::RenderWindow &window)
{
    window.draw(stair);
}
