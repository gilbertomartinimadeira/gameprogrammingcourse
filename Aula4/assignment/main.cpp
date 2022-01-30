#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <math.h>
#define _USE_MATH_DEFINES


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
    //virtual int getArea() = 0;

    virtual const std::string toString()
    {
        return "\ntype: " + m_type + 
                "\nname: " + m_name +                     
                "\nX Position: " + std::to_string(m_xPosition) + 
                "\nY Position: " + std::to_string(m_yPosition) +
                "\nX Speed: " + std::to_string(m_xSpeed) + 
                "\nY Speed: " + std::to_string(m_ySpeed) +
                "\nRed: " + std::to_string(m_red) +
                "\nGreen: " + std::to_string(m_green) +
                "\nBlue: " + std::to_string(m_blue);
                
                //TODO: Adicionar ao toString do retangulo

                // "\nwidth: " + std::to_string(m_width) + 
                // "\nheight: " + std::to_string(m_height) +
    }

};
// Derived classes
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
             
              
};


class Circle : public Shape 
{
    private:
    int m_radius;

    // public:
    // int getArea()
    // {
    //     return M_PI * pow(m_radius,2);
    // }

    //Circle(int radius): m_radius(radius), Shape { m_width  = 0, m_height = 0}{};
    
};


class ConfigManager
{
    public:
    static std::vector<Shape> loadShapesFromConfigFile(const std::string & fileName)
    {        
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

        std::vector<Shape> shapes;

        
        while(inputFileStream >> type)
        {        
            if( type == "Rectangle") 
            {
                inputFileStream >> name >> 
                                   xPositionString >> 
                                   yPositionString >> 
                                   xSpeedString >> 
                                   ySpeedString >>                                 
                                   redString >> 
                                   greenString >> 
                                   blueString >>
                                   widthString >> 
                                   heightString;            
            
                xPosition = std::stoi(xPositionString);
                yPosition = std::stoi(yPositionString);
                xSpeed = std::stof(xSpeedString);
                ySpeed = std::stof(xSpeedString);
                red = std::stoi(redString);
                green = std::stoi(greenString);
                blue = std::stoi(blueString);
                width = std::stoi(widthString); 
                height = std::stoi(heightString);


                shapes.push_back(Rectangle {type, 
                                            name, 
                                            xPosition, 
                                            yPosition,
                                            xSpeed, 
                                            ySpeed,
                                            red, 
                                            green, 
                                            blue, 
                                            width, 
                                            height });
            }

            else if( type == "Circle") {

            }
            
        }
        return shapes;
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

    std::vector<Shape> shapes = ConfigManager::loadShapesFromConfigFile("config.txt");
    
    for(int i = 0; i < shapes.size(); i++) std::cout << shapes[i].toString() << "\n";
    
    return 0;
}