#include <iostream>
#include <memory>
#include<SFML/Graphics.hpp>

class Vec2 
{        
    public:
    int x,
        y;
    Vec2(int _x, int _y)
      :x(_x),y(_y) {}
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

int main(int argc, char* argv[])
{
    std::cout << "Hello From Aula5 \n";

    std::vector<Entity> entities;
    
    Entity e;
    Vec2 p(100,100), v(10,10);

    e.cTransform = std::make_shared<Transform> (p,v);
    e.cName      = std::make_shared<Name>      ("Red box");

    entities.push_back(e);




}
