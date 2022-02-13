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
    const std::string getTag() const
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
    EntityManager();
    std::shared_ptr<Entity> addEntity(const std::string& tag)
    {
        auto e = std::make_shared<Entity>("Player", m_totalEntities++);
        m_toAdd.push_back(e);    
        return e;
    }
    
    EntityVec& getEntities(); 
    EntityVec& getEntities(const std::string& tag);

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

class Person {
    std::string m_name = "N/A";
    bool m_isAlive     = true;
    public:

    Person(std::string name, bool alive): m_name(name),m_isAlive(alive){};

    const std::string getName() 
    {
        return m_name;
    }
    bool isAlive() const
    {
        return m_isAlive;
    }

};
int main(int argc,char * argv[])
{
    std::vector<std::shared_ptr<Person>> myFriends;     

    std::cout << "BEFORE REMOVE_IF: " <<"\n";
    auto friend1 = std::make_shared<Person>("leo",true);
    auto friend2 = std::make_shared<Person>("thiago",true);
    auto friend3 = std::make_shared<Person>("carolina",true);
    auto friend4 = std::make_shared<Person>("ezequiel",true);
    auto friend5 = std::make_shared<Person>("zezek",true);
    auto friend6 = std::make_shared<Person>("gallas",true);
    auto friend7 = std::make_shared<Person>("pedrão",true);
    auto friend8 = std::make_shared<Person>("marcão",true);
    auto friend9 = std::make_shared<Person>("valdeci",false);
    auto friend10 = std::make_shared<Person>("alex",false);
    auto friend11 = std::make_shared<Person>("wilson",false);
    myFriends.push_back(friend1);
    myFriends.push_back(friend2);
    myFriends.push_back(friend3);
    myFriends.push_back(friend4);
    myFriends.push_back(friend5);
    myFriends.push_back(friend6);
    myFriends.push_back(friend7);
    myFriends.push_back(friend8);
    myFriends.push_back(friend9);
    myFriends.push_back(friend10);
    myFriends.push_back(friend11);


    for(auto f : myFriends) std::cout << f->getName() <<"\n";        

    std::vector<std::shared_ptr<Person>> myCurrentFriends;

    for(auto f : myFriends) 
    {
        if(f-> isAlive())
        {
            myCurrentFriends.push_back(f);
        }
    }
    myFriends.clear();


    for(auto f : myCurrentFriends)
    {
        myFriends.push_back(f);
    } 

    std::cout << "After removing the dead ones the list is as it goes:" <<"\n";
    for(auto f : myFriends) std::cout << f->getName() <<"\n";        

    

    



}