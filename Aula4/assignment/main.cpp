#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <math.h>
#define _USE_MATH_DEFINES


//criar uma forma que foi lida no arquivo de configuração

class Shape
{
protected:
    
    int m_width;
    int m_height;    
    std::string m_name;
    std::string m_type;

    Shape(int width, 
          int height, 
          const std::string name, 
          const std::string type):
                                  m_width(width), 
                                  m_height(height),
                                  m_name(name),
                                  m_type(type){}
    

public:
    //virtual int getArea() = 0;
    const std::string toString()
    {
        return "\ntype: " + m_type + 
                "\nname: " + m_name + 
                "\nwidth:" + std::to_string(m_width) + 
                "\nheight: " + std::to_string(m_height) + "\n\n";
    }

};
// Derived classes
class Rectangle: public Shape 
{

public:
    int getArea() { 
        return (m_width * m_height); 
    }
    Rectangle(int width, 
              int height, 
              const std::string name, 
              const std::string type): Shape { width, height, name, type}{};
};

class Triangle: public Shape 
{
//    public:
//       int getArea() { 
//          return (m_width * m_height)/2; 
//       }
    //Triangle(int width, int height): Shape { width, height }{};
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
        
        std::string type, name ,
                    xPositionString,
                    yPositionString,
                    xSpeedString,
                    ySpeedString,
                    widthString,
                    heightString,
                    radiusString,
                    redString,
                    greenString,
                    blueString;

        int xPosition, yPosition, xSpeed, ySpeed, width, height, radius, red, green, blue;


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
                                   widthString >> 
                                   heightString >> 
                                   redString >> 
                                   greenString >> 
                                   blueString;            

                width = std::stoi(widthString); 
                height = std::stoi(heightString);


                shapes.push_back(Rectangle { width, height, name, type });
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
    
    for(int i = 0; i < shapes.size(); i++)
    {
        std::cout << shapes[i].toString();
    }
    
    return 0;
}