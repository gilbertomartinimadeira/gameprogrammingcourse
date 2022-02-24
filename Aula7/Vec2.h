
class Vec2 
{        
    public:
    int x, y;
    Vec2(int _x, int _y);      
    Vec2 operator +  (const Vec2& v);
    Vec2 operator *  (float scale);
    bool operator == (const Vec2 & rhs);

    Vec2& scale ( float scale );
    Vec2& add   ( float value );

    std::string to_string();
        
    friend std::ostream& operator<<(std::ostream& stream,const Vec2& vec2);
};