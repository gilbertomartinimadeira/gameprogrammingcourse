#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <math.h>
#define _USE_MATH_DEFINES


class ShapeDTO {
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
            m_blue(blue) {}

public:
    virtual int getArea() = 0;
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

    public:
    int getArea()
    {
        return M_PI * pow(m_radius,2);
    }
public:
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
        int radius) : Shape { type, 
                              name,
                              xPosition,
                              yPosition,
                              xSpeed,
                              ySpeed,
                              red,
                              green,
                              blue },
                              m_radius(radius){}
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
    
};

class ConfigManager
{
    public:
    static std::vector<ShapeDTO> loadConfiguration(const std::string & fileName)
    {        
        std::vector<ShapeDTO> shapeDTOs;

        std::ifstream inputFileStream(fileName);
        
        std::string type, 
                    name ,
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
                inputFileStream >> widthString >> 
                                   heightString;    

                
                width = std::stoi(widthString); 
                height = std::stoi(heightString);            
            }

            else if( type == "Circle") {
                inputFileStream >> radiusString;
                radius = std::stoi(radiusString);
            }   

            else continue;

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
                        
            ShapeDTO dto;
            dto.m_type = type;
            dto.m_name = name;
            dto.m_xPosition = xPosition;
            dto.m_yPosition = yPosition;
            dto.m_xSpeed = xSpeed;
            dto.m_xSpeed = ySpeed;
            dto.m_red = red;
            dto.m_green = green;
            dto.m_blue = blue;
            dto.m_width = width;
            dto.m_height = height;
            dto.m_radius = radius;

            shapeDTOs.push_back(dto);        
        }
        return shapeDTOs;
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
    std::vector<ShapeDTO> dtos = ConfigManager::loadConfiguration("config.txt");

    std::vector<Rectangle> rectangles;
    std::vector<Circle> circles;

    for (auto dto : dtos)
    {
        if(dto.m_type == "Rectangle")
        {
            std::cout << "Rectangle found, adding to vector...\n";
            rectangles.push_back(Rectangle( 
                                            dto.m_type, 
                                            dto.m_name,
                                            dto.m_xPosition,
                                            dto.m_yPosition,
                                            dto.m_xSpeed,
                                            dto.m_ySpeed,
                                            dto.m_red,
                                            dto.m_green,
                                            dto.m_blue,
                                            dto.m_width,
                                            dto.m_height));
        } 
        else if(dto.m_type == "Circle") 
        {
            std::cout << "Circle found! adding to vector...\n";
            circles.push_back(Circle( 
                                    dto.m_type, 
                                    dto.m_name,
                                    dto.m_xPosition,
                                    dto.m_yPosition,
                                    dto.m_xSpeed,
                                    dto.m_ySpeed,
                                    dto.m_red,
                                    dto.m_green,
                                    dto.m_blue,
                                    dto.m_radius));
        }
        
    }

    for(auto c : circles)
    {
        std::cout << c.toString() << "\n";
    }
    for(auto r : rectangles)
    {
        std::cout << r.toString() << "\n";
    }
        
    return 0;
}