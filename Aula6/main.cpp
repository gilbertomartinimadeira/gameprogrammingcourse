#include <iostream>
#include <memory>
#include <sstream>
#include <SFML/Graphics.hpp>

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map   <std::string, EntityVec>  EntityMap;

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

class CTransform
{
    public:
    Vec2 pos = {0,0};
    Vec2 velocity = {0,0};
    CTransform() {}
    CTransform(const Vec2 & p, const Vec2 & v )
        :pos(p), velocity(v) {}


};
class CName{};
class CShape
{
    public:
    sf::CircleShape shape;
    CShape(){}
};
class CBBox{}; 

class Entity
{
    const size_t      m_id   = 0;
    const std::string m_tag  = "Default";
    bool  m_alive            = true;

public:
    std::shared_ptr<CTransform> cTransform;
    std::shared_ptr<CName>      cName;
    std::shared_ptr<CShape>     cShape;
    std::shared_ptr<CBBox>      cBBox;
    Entity(const std::string& tag, size_t id)
    :m_id(id), m_tag(tag){}    
};

class EntityManager 
{
    EntityVec m_entities;
    EntityMap m_entityMap;
    size_t m_totalEntities = 0;
    public:
    EntityManager();
    std::shared_ptr<Entity> addEntity(const std::string& tag);
    EntityVec& getEntities(); 
    EntityVec& getEntities(const std::string& tag); 


};

int main(int argc,char * argv[])
{

    std::cout << "Hello lecture 6!\n";

}