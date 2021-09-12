#include <SFML/Graphics.hpp>
#include <math.h>
float Xposition(float *x,float speed,float deltatime,bool *toolright)
{
    float movex=0;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        movex-=speed*deltatime;
        *toolright=true;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        movex+=speed*deltatime;
        *toolright=false;
    }
    if(*x+movex>=400)
    {
        movex=*x+movex-400;
        *x=0;
    }
    if(*x+movex<=0)
    {
        movex=*x+movex;
        *x=400;
    }
    return movex;
}
//////need fix
float Yposition(float movee,float deltatime)
{
    //movee*-1*deltatime*1.5;
    return -sqrt(2.0f*0.0981f*movee*deltatime);
}

