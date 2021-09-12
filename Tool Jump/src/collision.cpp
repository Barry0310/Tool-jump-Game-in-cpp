#include "collision.h"
#include <math.h>

collision::collision(sf::RectangleShape& body):
    body(body)
{
}

collision::~collision()
{
}

bool collision::checkcollision(collision  other,sf::Vector2f& derection,float push)
{
    sf::Vector2f otherposition=other.GetPosition();
    sf::Vector2f otherhalfsize=other.GetHalfsize();
    sf::Vector2f thisposition=GetPosition();
    sf::Vector2f thishalfsize=GetHalfsize();

    float deltaX=otherposition.x-thisposition.x;
    float deltaY=otherposition.y-thisposition.y;
    float intersectX=abs(deltaX)-(otherhalfsize.x+thishalfsize.x);
    float intersectY=abs(deltaY)-(otherhalfsize.y+thishalfsize.y);

    if(intersectX<0&&intersectY<0&&deltaY<-25)
    {
        push=std::min(std::max(push,0.0f),1.0f);
        other.Move(0.0f,intersectY*push);
        derection.y=-1.0f;
        return true;
    }
    return false;
}
