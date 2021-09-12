#include <SFML/Graphics.hpp>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Player.h"
#include "platform.h"
#include "Menu.h"

int main()
{
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(400.0f,600.0f),"Tool Jump",sf::Style::Close);
    sf::RectangleShape background(sf::Vector2f(400.0f,600.0f));
    //////set menu////////////
    sf::Texture pic;
    pic.loadFromFile("toolman.jpg");
    Menu Menu(&pic,(float)window.getSize().x,(float)window.getSize().y);
    bool game=false;
    bool option=false;
    //////set player picture//////
    sf::Texture doodle;
    doodle.loadFromFile("tooldoodleee.png");
    Player tooldoodle(&doodle,sf::Vector2u(2,1),200.0f);
    //////set background picture//////
    sf::Texture bg;
    bg.loadFromFile("backgrond.png");
    background.setTexture(&bg);
    //////set stair//////////////////
    sf::Texture stair;
    stair.loadFromFile("finish.png");
    std::vector<platform> stairs;
    stairs.push_back(platform(&stair,200,590,0));
    for(int i=1; i<15; i++)
    {
        stairs.push_back(platform(&stair,float(rand()%304+48),float(-1*(rand()%50+40)),stairs[i-1].Getposition()));
    }
    ////////////////////////////////
    int SCORE=0;
    float deltatime=0.0f;
    sf::Clock clock;
    while(window.isOpen())
    {
        deltatime=clock.restart().asSeconds();
        if(deltatime>1.0f/20.0f)
        {
            deltatime=1.0f/20.0f;
        }
        sf::Event evnt;
        while(window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
            case sf::Event::KeyReleased:
            {
                switch(evnt.key.code)
                {
                case sf::Keyboard::Up:
                {
                    Menu.Moveup();
                    break;
                }
                case sf::Keyboard::Down:
                {
                    Menu.Movedown();
                    break;
                }

                case sf::Keyboard::Return:
                {
                    switch(Menu.GetPressitem())
                    {
                    case 0:
                        game=true;
                    case 1:
                        option=true;
                    }
                }
                }
            }
            break;
            case (sf::Event::Closed):
            {
                window.close();
                break;
            }
            }
        }
        ///////menu///////
        window.clear();
        window.draw(background);
        if(game==false&&option==false)
        {
            Menu.Draw(window);
        }
        //////option//////
        if(game==false&&option==true)
        {
            Menu.Drawoption(window);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
                option=false;
        }
        //////game start///////
        if(tooldoodle.GetPosition().y<625&&game==true)
        {
            sf::Vector2f derection;
            tooldoodle.Update(deltatime);
            /////stairs move//////
            if(tooldoodle.JumpTooHigh())
            {
                for(int i=0; i<15; i++)
                {
                    stairs[i].Move(tooldoodle.JumpTooHigh()+10);
                }
                for(int g=0; g<15; g++)
                {
                    if(stairs[g].Getposition()>600)
                    {
                        SCORE++;
                        stairs.erase(stairs.begin()+g);
                        stairs.push_back(platform(&stair,float(rand()%304+48),float(-1*(rand()%50+40)),stairs[stairs.size()-1].Getposition()));
                    }
                }
            }
            printf("%d\n",SCORE);
            ///////////////////////////////
            for(platform& platform : stairs)
            {
                if(platform.GetCollider().checkcollision(tooldoodle.GetCollider(),derection,0.0f)&&tooldoodle.velocity.y>0)
                    tooldoodle.Oncollition(derection);
            }
            for(int i=0; i<15; i++)
            {
                stairs[i].Draw(window);
            }
            tooldoodle.Draw(window);
        }
        ///////////reset/////////
        if(tooldoodle.GetPosition().y>625)
        {
            Menu.Drawdead(window);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                SCORE=0;
                stairs.clear();
                stairs.push_back(platform(&stair,200,590,0));
                for(int i=1; i<15; i++)
                {
                    stairs.push_back(platform(&stair,float(rand()%304+48),float(-1*(rand()%50+40)),stairs[i-1].Getposition()));
                }
                tooldoodle.Reset();
            }
        }
        window.display();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        {
            window.close();
        }
    }
    return 0;
}
