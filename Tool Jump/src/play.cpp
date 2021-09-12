#include "play.h"
#include<math.h>
play::play(sf::Texture*texture,sf::Vector2u imagecount)
{
        this->imagecount=imagecount;
        currentimage.x=0;
        uvrect.width=texture->getSize().x/float(imagecount.x);
        uvrect.height=texture->getSize().y/float(imagecount.y);
}
play::~play()
{
}
void play::update(int row,bool toolright,float jump)
{
    currentimage.y=row;
    if(jump<0)
        currentimage.x=1;
    else
        currentimage.x=0;
    if(toolright)
    {
        uvrect.left=currentimage.x*abs(uvrect.width);
        uvrect.width=abs(uvrect.width);
    }
    else
    {
        uvrect.left=(currentimage.x+1)*abs(uvrect.width);
        uvrect.width=-abs(uvrect.width);
    }
    uvrect.top=currentimage.y*uvrect.height;
}
