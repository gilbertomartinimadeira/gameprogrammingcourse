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

    sf::CircleShape circle(60);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(wWidth/2, wHeight/2);
    float circleMoveSpeed  = -0.04f;

    sf::Font myFont;

    if(!myFont.loadFromFile("fonts/arial.ttf"))
    {
        std::cerr << "Could not load font from file \n";
        exit(-1);
    }

        

    int counter = 0;

    while(window.isOpen())
    {          
        auto circlePositionTextString = "Circle Position: (" + std::to_string(circle.getPosition().x) +","+ std::to_string(circle.getPosition().y) + ")";      
        sf::Text circlePositionText(circlePositionTextString, myFont,16);
        circlePositionText.setPosition(10, wHeight - (float)circlePositionText.getCharacterSize() - 2) ;

        auto circleLocalBounds = circle.getLocalBounds();
        
        
        auto circleBoundingBoxTextString = " Circle Local Bounds \n width: " + std::to_string(circleLocalBounds.width)
                                        +  " \n height: " + std::to_string(circleLocalBounds.height)
                                        +  " \n top: " + std::to_string(circleLocalBounds.top) 
                                        +  " \n left: " + std::to_string(circleLocalBounds.left);
                                          
        sf::Text circleBoundingBoxText(circleBoundingBoxTextString,myFont,16);
        circleBoundingBoxText.setPosition(circlePositionText.getPosition().x + 10, (float)circleBoundingBoxText.getCharacterSize() - 2);

        sf::Event event;

        circlePositionText.setString(circlePositionTextString);
        circleBoundingBoxText.setString(circleBoundingBoxTextString);

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                std::cout << "Key pressed! " << event.key.code << "\n";
                if(event.key.code == sf::Keyboard::X)
                    circle.setFillColor(sf::Color::Red);                
                
            }    
            if(event.type == sf::Event::MouseButtonPressed)
            {
                std::cout << "Mouse pressed! " << event.mouseButton.button << "\n";            
                switch(event.mouseButton.button){
                    case 0: circle.setFillColor(sf::Color::Yellow);  
                    break;        
                    case 1: circleMoveSpeed *= -1;      
                    break;                
                }
            }
        }
        
        sf::Vector2f previousCirclePosition = circle.getPosition(); 
        sf::Vector2f movement(circleMoveSpeed, circleMoveSpeed);
        sf::Vector2f newPosition = previousCirclePosition + movement;
        circle.setPosition(newPosition);
    
        window.clear();
        window.draw(circle);
        window.draw(circlePositionText);
        window.draw(circleBoundingBoxText);
        window.display();
    }

}