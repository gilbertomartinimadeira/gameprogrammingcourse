/**
 * @file main.cpp
 * @author Gilberto Martini Madeira <gilmartmd@gmail.com>
 * @brief as a sign of appreciation, I'm quoting Dave Churchill, who is an excellent instructor, hope someday he'll read it!
 * @version 0.1
 * @date 2022-01-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

int main(int argc, char * argv[])
{
    const int wWidth = 800;
    const int wHeight = 600;

    sf::RenderWindow window(sf::VideoMode(wWidth,wHeight), "SFML Funciona!");

    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(wWidth/2, wHeight/2);
    float circleMoveSpeed  = -0.02f;

    sf::Font myFont;

    if(!myFont.loadFromFile("fonts/arial.ttf"))
    {
        std::cerr << "Could not load font from file \n";
        exit(-1);
    }

    sf::Text myText("Eu Aqui seguindo o curso de programacao de jogos com c++ e SFML",myFont,18);

    myText.setPosition(0, wHeight - (float)myText.getCharacterSize() - 2) ;

    int counter = 0;

    while(window.isOpen())
    {
        sf::Vector2f previousCirclePosition = circle.getPosition(); 
        sf::Vector2f movement(circleMoveSpeed,circleMoveSpeed);
        sf::Vector2f newPosition = previousCirclePosition + movement;

        sf::Event event;
        

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                std::cout << "Key pressed! " << event.key.code << "\n";
                if(event.key.code == 23)
                {
                    circle.setFillColor(sf::Color::Red);                
                }
            }    
            if(event.type == sf::Event::MouseButtonPressed)
            {
                std::cout << "Mouse pressed! " << event.mouseButton.button << "\n";            
                if(event.mouseButton.button == 0)
                circle.setFillColor(sf::Color::Yellow);                
            }
        }
        

        circle.setPosition(newPosition);
    
        window.clear(sf::Color::White);
        window.draw(circle);
        window.draw(myText);
        window.display();
    }

}