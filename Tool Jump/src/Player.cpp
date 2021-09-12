#include "Player.h"
#include"../position.h"
#include <math.h>
Player::Player(sf::Texture* texture,sf::Vector2u imagecount,float speed):
    play(texture,imagecount)
{
    this->speed=speed;
    tool.setSize(sf::Vector2f(widght,height));
    tool.setOrigin(tool.getSize().x/3.0f*2.0f,tool.getSize().y/2.0f);
    tool.setPosition(x,y);
    tool.setTexture(texture);
}
Player::~Player()
{
}
void Player::Update(float deltatime)
{
    ////////////////set position///////////////
    TooHigh=0;
    x=tool.getPosition().x;
    velocity.x=Xposition(&x,speed,deltatime,&toolright);

    if(toolright)
        tool.setOrigin(tool.getSize().x/3.0f,tool.getSize().y/2.0f);
    else
        tool.setOrigin(tool.getSize().x/3.0f*2.0f,tool.getSize().y/2.0f);

    if(tool.getPosition().x+velocity.x>=400||tool.getPosition().x+velocity.x<=0)
    {
        tool.setPosition(x,tool.getPosition().y);
    }
    velocity.y+=0.0981f*deltatime;
    /////////////////////////need fix///////////////////////////////////////
    if(canjump)
    {
        velocity.y+=Yposition(movee,deltatime);
        canjump=false;
        if(tool.getPosition().y-295<200)
        {
            TooHigh=200-(tool.getPosition().y-295);
        }
        else
            TooHigh=0;
    }
    if(tool.getPosition().y+velocity.y<=295)
    {
        //velocity.y=295-tool.getPosition().y;
        //tool.setPosition(tool.getPosition().x,295);
        velocity.y+=0.0981f*deltatime*4;
    }
    ///////////////////////////////////////////////////////////
    play.update(0,toolright,velocity.y);
    tool.move(velocity);
    tool.setTextureRect(play.uvrect);
}
void Player::Oncollition(sf::Vector2f derection)
{
    if(derection.y<0.0f)
    {
        velocity.y=0;
        canjump=true;
    }
}
float Player::JumpTooHigh()
{
    return TooHigh;
}
void Player::Draw(sf::RenderWindow &window)
{
    window.draw(tool);
}
void Player::Reset()
{
    tool.setPosition(200,545);
}
