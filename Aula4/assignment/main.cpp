#include <iostream>
#include <fstream>
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
    Shape(int width, int height):m_width(width), m_height(height){}

public:
    virtual int getArea() = 0;

};

// Derived classes
class Rectangle: public Shape 
{

public:
    int getArea() { 
        return (m_width * m_height); 
    }
    Rectangle(int width, int height): Shape { width, height }{};
};

class Triangle: public Shape 
{
   public:
      int getArea() { 
         return (m_width * m_height)/2; 
      }
    Triangle(int width, int height): Shape { width, height }{};
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

    Circle(int radius): m_radius(radius), Shape { m_width  = 0, m_height = 0}{};
    
};



class ConfigManager
{
    private:
    

    //todo: read config file into shape objects
    public:
    std::vector<Shape> loadShapesFromConfigFile(const std::string & fileName)
    {
        
        std::ifstream inputFileStream(fileName);
        
        std::string type, name ,position, speed,  width, height, radius, red, green, blue;

        std::vector<Shape> shapes;

        
    
        while(inputFileStream >> type)
        {
            if(type == "Window"){ }
            else if( type == "Font") {}
            else if( type == "Rectangle") {}
            else if( type == "Circle") {}
            else if( type == "Triangle") {}
            
        }
    
    }

};

int main(int argc, char * argv[])
{
    return 0;
}