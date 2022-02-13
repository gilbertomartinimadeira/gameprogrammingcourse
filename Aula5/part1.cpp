
#include <iostream>
#include <memory>
#include<SFML/Graphics.hpp>
#include <sstream>

class Vec2 
{        
    public:
    int x,
        y;
    Vec2(int _x, int _y)
      :x(_x),y(_y) {}

    Vec2 operator +  (const Vec2& v)     { return Vec2(x + v.x, y + v.y);}
    Vec2 operator *  (float scale)       { return Vec2( x * scale, y * scale ); }
    bool operator == (const Vec2 & rhs)  { return x == rhs.x && y == rhs.y; }    

    Vec2& scale ( float scale )         { x *= scale; y *= scale; return *this; }
    Vec2& add   ( float value )         { x += value; y += value; return *this; }

    std::string to_string()
    {
        std::stringstream ss;

        ss << "Vector details: { x:" << x <<", y:" << y <<" }\n";
        return ss.str();
    }


    friend std::ostream& operator<<(std::ostream& stream,const Vec2& vec2)
    {
        return stream << vec2.x << " " << vec2.y <<"\n";
    }
};

class Transform
{
    public:
    Vec2 pos = {0,0};
    Vec2 velocity = {0,0};
    Transform() {}
    Transform(const Vec2 & p, const Vec2 & v )
        :pos(p), velocity(v) {}


};
class Name{};
class Shape
{
    public:
    sf::CircleShape shape;
    Shape(){}
};
class BBox{};

typedef std::shared_ptr<Transform> CTransform;
typedef std::shared_ptr<Name> CName;
typedef std::shared_ptr<Shape> CShape;
typedef std::shared_ptr<BBox> CBBox;


class Entity
{
public:
    CTransform cTransform;
    CName cName;
    CShape cShape;
    CBBox cCBBox;

    Entity(){};

};

//we don't want to copy the vector!!!!! thus use a REFERENCE!!!
// void sMovement(std::vector<Entity> & entities)
// {
//     for(auto & e : entities)
//     {   
//         e.cTransform->pos += e.cTransform->velocity;    
//     }
// }

int main()
{
    std::vector<Entity> entities;
    
    Entity e;
    Vec2 p(100,100), v(10,10);

    e.cTransform = std::make_shared<Transform> (p,v);
    //e.cName      = std::make_shared<Name>      ("Red box");

    entities.push_back(e);

}


