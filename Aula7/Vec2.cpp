#include <Common.h>

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