#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <math.h>
#define _USE_MATH_DEFINES


class Configuration {
public:
    std::string m_type,
                m_name;

    int m_xPosition,
        m_yPosition,    
        m_red, 
        m_green,
        m_blue,
        m_width,
        m_height,
        m_radius;

    float m_xSpeed,
          m_ySpeed;
};

class Shape
{
protected:
    
    std::string m_type,
                m_name;

    int m_xPosition,
        m_yPosition,    
        m_red, 
        m_green,
        m_blue;

    float m_xSpeed,
          m_ySpeed;    

    Shape(
          const std::string type,
          const std::string name, 
          int xPosition,
          int yPosition,
          float xSpeed,
          float ySpeed,
          int red,
          int green,
          int blue
          ): 
            m_type(type),
            m_name(name),
            m_xPosition(xPosition),
            m_yPosition(yPosition),          
            m_xSpeed(xSpeed),
            m_ySpeed(ySpeed),
            m_red(red),
            m_green(green),
            m_blue(blue) 
            {                            
            }

public:
    virtual int getArea() = 0;
    std::string getType(){return m_type;}
    std::string getName(){return m_name;}

    int getPositionX(){ return m_xPosition;}
    int getPositionY(){ return m_yPosition;}
    float getSpeedX(){ return m_xSpeed;}
    float getSpeedY(){return m_ySpeed;}
    int getRed(){return m_red;}
    int getGreen(){return m_green;}
    int getBlue(){return m_blue;}
    
};

class Rectangle: public Shape 
{
private:
    int m_width,
        m_height;
public:
    int getArea() { 
        return (m_width * m_height); 
    }
    int getWidth() {return m_width;}
    int getHeight() {return m_height;}

    Rectangle(
                const std::string type,
                const std::string name,             
                int xPosition,
                int yPosition,
                float xSpeed,
                float ySpeed,
                int red,
                int green,
                int blue,
                int width, 
                int height) : Shape { type, 
                                      name,
                                      xPosition,
                                      yPosition,
                                      xSpeed,
                                      ySpeed,
                                      red,
                                      green,
                                      blue },
                                      m_width(width),
                                      m_height(height){}

    const std::string toString() 
    {
        return "\nType: " + m_type + 
               "\nName: " + m_name +                     
               "\nX Position: " + std::to_string(m_xPosition) + 
               "\nY Position: " + std::to_string(m_yPosition) +
               "\nX Speed: " + std::to_string(m_xSpeed) + 
               "\nY Speed: " + std::to_string(m_ySpeed) +
               "\nRed: " + std::to_string(m_red) +
               "\nGreen: " + std::to_string(m_green) +
               "\nBlue: " + std::to_string(m_blue) +        
               "\nWidth: " + std::to_string(m_width) + 
               "\nHeight: " + std::to_string(m_height);
    }
                         
};

class Circle : public Shape 
{
private:
    int m_radius;
    sf::CircleShape m_shape;
public:
    int getArea()
    {
        return M_PI * pow(m_radius,2);
    }
    int getRadius() 
    {
        return m_radius;
    }

    sf::CircleShape getShape()
    {
        return m_shape;
    }

    Circle(
        const std::string type,
        const std::string name,             
        int xPosition,
        int yPosition,
        float xSpeed,
        float ySpeed,
        int red,
        int green,
        int blue,
        int radius
        ) : m_radius(radius), Shape { type, 
                                     name,
                                     xPosition,
                                     yPosition,
                                     xSpeed,
                                     ySpeed,
                                     red,
                                     green,
                                     blue }
                    {                    
                        sf::Vector2f initialPosition(xPosition,yPosition);

                        m_shape = sf::CircleShape(m_radius, 20);
                        m_shape.setFillColor(sf::Color(m_red,m_green, m_blue));                                                                
                        m_shape.setPosition(initialPosition);                        
                    }
    const std::string toString() 
    {
        return "\nType: " + m_type + 
               "\nName: " + m_name +                     
               "\nX Position: " + std::to_string(m_xPosition) + 
               "\nY Position: " + std::to_string(m_yPosition) +
               "\nX Speed: " + std::to_string(m_xSpeed) + 
               "\nY Speed: " + std::to_string(m_ySpeed) +
               "\nRed: " + std::to_string(m_red) +
               "\nGreen: " + std::to_string(m_green) +
               "\nBlue: " + std::to_string(m_blue) +        
               "\nRadius: " + std::to_string(m_radius);
    }
    void setShape(sf::CircleShape shape)
    {
        m_shape = shape;
    }
    
    void updatePosition()
    {
        auto currentPosition = m_shape.getPosition();
        auto movement = sf::Vector2f(m_xSpeed, m_ySpeed);
        auto newPosition = currentPosition + movement;

        m_shape.setPosition(newPosition);

    }
};

class ConfigManager
{
    public:
    static std::vector<Configuration> loadConfiguration(const std::string & fileName)
    {        
        std::vector<Configuration> configurations;

        std::ifstream inputFileStream(fileName);
        
        std::string type, 
                    name,
                    xPositionString,
                    yPositionString,
                    xSpeedString,
                    ySpeedString,
                    redString,
                    greenString,
                    blueString,
                    widthString,
                    heightString,
                    radiusString;

        int xPosition,
            yPosition,
            red,
            green,
            blue,
            width,
            height,
            radius;

        float xSpeed,
              ySpeed;

        while(inputFileStream >> type)
        {        
            inputFileStream >> name >> 
                                xPositionString >>
                                yPositionString >>
                                xSpeedString >>
                                ySpeedString >>                                 
                                redString >> 
                                greenString >> 
                                blueString;
                                   
            if( type == "Rectangle") 
            {
                inputFileStream >> widthString >> heightString;    

                
                width = std::stoi(widthString); 
                height = std::stoi(heightString);            
            }

            else if( type == "Circle") {
                inputFileStream >> radiusString;
                radius = std::stoi(radiusString);
            } else continue;              

            try
            {
                xPosition = std::stoi(xPositionString);
                yPosition = std::stoi(yPositionString);
                xSpeed = std::stof(xSpeedString);
                ySpeed = std::stof(ySpeedString);
                red = std::stoi(redString);
                green = std::stoi(greenString);
                blue = std::stoi(blueString);                                
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
                        
            Configuration config;
            config.m_type = type;
            config.m_name = name;
            config.m_xPosition = xPosition;
            config.m_yPosition = yPosition;
            config.m_xSpeed = xSpeed;
            config.m_ySpeed = ySpeed;
            config.m_red = red;
            config.m_green = green;
            config.m_blue = blue;
            config.m_width = width;
            config.m_height = height;
            config.m_radius = radius;

            configurations.push_back(config);        
        }

        return configurations;
    }

};

int setupWindow()
{
    auto type = "Window";
    
    if(type == "Window"){ }
            else if( type == "Font") {}

            return 0;
}

int main(int argc, char * argv[])
{

    std::vector<Configuration> configs = ConfigManager::loadConfiguration("config.txt");
    std::vector<Rectangle> rectangles;
    std::vector<Circle> circles;

    std::vector<sf::CircleShape> circleShapes;    

    for (auto config : configs)
    {
        if(config.m_type == "Rectangle")
        {            
            rectangles.push_back(Rectangle( 
                                            config.m_type, 
                                            config.m_name,
                                            config.m_xPosition,
                                            config.m_yPosition,
                                            config.m_xSpeed,
                                            config.m_ySpeed,
                                            config.m_red,
                                            config.m_green,
                                            config.m_blue,
                                            config.m_width,
                                            config.m_height));
        } 
        else if(config.m_type == "Circle") 
        {        
            circles.push_back(Circle( 
                                    config.m_type, 
                                    config.m_name,
                                    config.m_xPosition,
                                    config.m_yPosition,
                                    config.m_xSpeed,
                                    config.m_ySpeed,
                                    config.m_red,
                                    config.m_green,
                                    config.m_blue,
                                    config.m_radius));
        }
        
    }
        
    int wWidth = 640, wHeight = 480;
    
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight),"Assignment 1");
    sf::Color screenColor(64,64,64);
    
    while(window.isOpen())
    {
      
        window.clear(screenColor);
        
        for(auto & circle : circles) 
        {
            circle.updatePosition();
            window.draw(circle.getShape());

        }        

        window.display();

    }
        
}