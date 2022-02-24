#include <Common.h>

class CTransform
{
public:
    Vec2 pos       = { 0.0, 0.0 }; // position at the center
    Vec2 velocity  = { 0.0, 0.0 };
    float angle    = 0;

    CTransform(const Vec2 & p, const Vec2 & v, float a)
        :pos(p),velocity(v),angle(a){}  

};

class CShape
{
public:
    sf::CircleShape circle;

    CShape(float radius, int points, const sf::Color & fill, const sf::Color & outline, float thickness)
        :circle(radius, points)
        {
            circle.setFillColor(fill);
            circle.setOutlineColor(outline);
            circle.setOutlineThickness(thickness);
            circle.setOrigin(radius, radius);
        }
};

class CCollision
{
public:
    float radius = 0;
    CCollision(float r): radius(r){}

};

class CScore 
{
public:
    int score = 0; // número de lados * 100

    CScore(int s):score(s){}
};

class CLifespan
{
public:
                        // 100 total lifespan, alive for 30 frames
    int remaining = 0;  // amount of lifespan remaining on the entity
    int total     = 0;  // the total initial amount of lifespan
    CLifespan(int total) 
        :remaining(total), total(total){}
};

class CInput
{
public:
    bool up    = false;
    bool down  = false;
    bool left  = false;
    bool right = false;
    bool down  = false;
    bool shoot = false;

    CInput() {}  // attach to player, record  the key that was pressed
                 // look 

};