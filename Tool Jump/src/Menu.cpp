#include "Menu.h"

Menu::Menu(sf::Texture* texture,float widght,float height)
{
    this->widght=widght;
    this->height=height;
    if(!font.loadFromFile("Exo2-ExtraLightItalic.otf"))
    {
        printf("no found");
        return;
    }
    title.setFont(font);
    title.setColor(sf::Color::Black);
    title.setString("Tool Jump");
    title.setPosition(sf::Vector2f(widght/3*0.8,height/5*0.5));
    title.setCharacterSize(40);

    menn[0].setFont(font);
    menn[0].setColor(sf::Color::Red);
    menn[0].setString("play");
    menn[0].setPosition(sf::Vector2f(widght/3*1.35,height/4*2.5));

    menn[1].setFont(font);
    menn[1].setColor(sf::Color::Black);
    menn[1].setString("option");
    menn[1].setPosition(sf::Vector2f(widght/3*1.2,height/4*3));

    picc.setSize(sf::Vector2f(130.0f,150.0f));
    picc.setTexture(texture);
    picc.setPosition(140,210);

}

Menu::~Menu()
{
}

void Menu::Moveup()
{
    if(index-1>=0)
    {
        menn[index].setColor(sf::Color::Black);
        index--;
        menn[index].setColor(sf::Color::Red);
    }
    else
    {
        menn[index].setColor(sf::Color::Black);
        index=1;
        menn[index].setColor(sf::Color::Red);
    }
}

void Menu::Movedown()
{
    if(index+1<2)
    {
        menn[index].setColor(sf::Color::Black);
        index++;
        menn[index].setColor(sf::Color::Red);
    }
    else
    {
        menn[index].setColor(sf::Color::Black);
        index=0;
        menn[index].setColor(sf::Color::Red);
    }
}

void Menu::Draw(sf::RenderWindow &window)
{
    for(int i=0;i<2;i++)
        window.draw(menn[i]);
    window.draw(picc);
    window.draw(title);
}

void Menu::Drawdead(sf::RenderWindow &window)
{
    diee[0].setFont(font);
    diee[0].setColor(sf::Color::Black);
    diee[0].setString("What a simple game");
    diee[0].setPosition(sf::Vector2f(widght/6*1,height/4*0.5));

    diee[1].setFont(font);
    diee[1].setColor(sf::Color::Black);
    diee[1].setString("But you die");
    diee[1].setPosition(sf::Vector2f(widght/4*1.3,height/4*1));

    diee[2].setFont(font);
    diee[2].setColor(sf::Color::Black);
    diee[2].setString("QQ");
    diee[2].setPosition(sf::Vector2f(widght/3*1.3,height/4*2));
    diee[2].setCharacterSize(45);

    diee[3].setFont(font);
    diee[3].setColor(sf::Color::Black);
    diee[3].setString("Press R to restart");
    diee[3].setPosition(sf::Vector2f(widght/6*1.3,height/5*4));

    for(int i=0;i<4;i++)
    {
        window.draw(diee[i]);
    }
}

void Menu::Drawoption(sf::RenderWindow &window)
{
    optoin[0].setFont(font);
    optoin[0].setColor(sf::Color::Black);
    optoin[0].setString("Option");
    optoin[0].setPosition(sf::Vector2f(widght/3*1.2,height/4*0.5));

    optoin[1].setFont(font);
    optoin[1].setColor(sf::Color::Black);
    optoin[1].setString("Press Left to move to left");
    optoin[1].setPosition(sf::Vector2f(widght/6*1,height/4*1.5));
    optoin[1].setCharacterSize(25);

    optoin[2].setFont(font);
    optoin[2].setColor(sf::Color::Black);
    optoin[2].setString("Press Left to move to right");
    optoin[2].setPosition(sf::Vector2f(widght/6*1,height/4*2));
    optoin[2].setCharacterSize(25);

    optoin[3].setFont(font);
    optoin[3].setColor(sf::Color::Black);
    optoin[3].setString("Press E to close the game");
    optoin[3].setPosition(sf::Vector2f(widght/6*1,height/4*2.5));
    optoin[3].setCharacterSize(25);

    optoin[4].setFont(font);
    optoin[4].setColor(sf::Color::Black);
    optoin[4].setString("Press B back to menu");
    optoin[4].setPosition(sf::Vector2f(widght/6*1.1,height/4*3.5));
    optoin[4].setCharacterSize(29);

    for(int i=0;i<5;i++)
    {
        window.draw(optoin[i]);
    }
}
