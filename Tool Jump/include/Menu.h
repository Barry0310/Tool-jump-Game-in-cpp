#pragma once
#include<SFML/Graphics.hpp>

class Menu
{
    public:
        Menu(sf::Texture* texture,float widght,float height);
        ~Menu();

        void Draw(sf::RenderWindow &window);
        void Moveup();
        void Movedown();
        int GetPressitem(){return index;}
        void Drawdead(sf::RenderWindow &window);
        void Drawoption(sf::RenderWindow &window);

    private:
        int index=0;
        sf::Font font;
        sf::Text title;
        sf::Text menn[2];
        sf::Text diee[4];
        sf::Text optoin[5];
        float widght;
        float height;
        sf::RectangleShape picc;
};
