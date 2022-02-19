#include <iostream>
#include <memory>
#include <sstream>
#include <SFML/Graphics.hpp>

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
    const std::string& getTag() const
    {
        return m_tag;
    }
    bool is_alive() const
    {
        return m_alive;
    }

    size_t getId() const 
    {
        return m_id;
    }
    void destroy()
    {
        m_alive = false;
    }

    Entity(const std::string& tag, size_t id)
    :m_id(id), m_tag(tag){}    
};
typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map   <std::string, EntityVec>  EntityMap;

class EntityManager 
{
    EntityVec m_entities;
    EntityVec m_toAdd; 
    EntityMap m_entityMap;
    size_t m_totalEntities = 0;

    public:
    EntityManager()
    {
        m_entities = std::vector<std::shared_ptr<Entity>>();
    }
    
    std::shared_ptr<Entity> addEntity(const std::string& tag)
    {
        auto e = std::make_shared<Entity>("Player", m_totalEntities++);
        m_toAdd.push_back(e);    
        return e;
    }
    
    EntityVec& getEntities()
    {
        return m_entities;
    }
    EntityVec& getEntities(const std::string& tag)
    {
        return m_entityMap[tag];
    }

    void update()
    {
        // called at beginning of each frame by game engine
        // entities added by the last frame will now be available to the current frame

        for(auto e : m_toAdd)
        {
            m_entities.push_back(e);
            m_entityMap[e->getTag()].push_back(e);
        }
        std::vector<std::shared_ptr<Entity>> aliveEntities;

        for(auto e : m_entities)
        {                
            if(e->is_alive())
            {                
               aliveEntities.push_back(e); 
            }
        }
        m_entities.clear();
        m_entityMap.clear();
        
        for(auto e : aliveEntities)
        {
            m_entities.push_back(e);
            m_entityMap[e->getTag()].push_back(e);
        }
        
        m_toAdd.clear();
    }
    
};
class Scene
{
    EntityManager m_entities;

    void spawnEnemy()
    {
        auto e = m_entities.addEntity("enemy");
        e->cTransform = std::make_shared<CTransform>(Vec2(100,100),Vec2(10,10));
        e->cShape = std::make_shared<CShape>();
    }
    void collisions()
    {
        for(auto b : m_entities.getEntities("bullet"))
            for(auto e : m_entities.getEntities("enemy"))
                if(/*Physics::CheckCollision(b,e)*/false){ b->destroy(), e->destroy();}

    }
};

int main(int argc,char * argv[])
{
    
    //scene 1:
    EntityManager em1;

    em1.addEntity("player1");
    em1.addEntity("player2");

    em1.update();
    auto entities = em1.getEntities();

    for(auto e : entities)
    {
        std::cout << e->getId()<< ", " << e->getTag() << "\n";
    }
    
}