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

class CCollision{};
