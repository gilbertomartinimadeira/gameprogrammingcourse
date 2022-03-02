
class Vec2 
{       
    
 
public:
    float x = 0;
    float y = 0;
    
    Vec2();
    Vec2(float xin, float yin);      

    bool operator == (const Vec2 & rhs) const;
    bool operator != (const Vec2 & rhs) const;
    
    Vec2 operator +  (const Vec2& rhs) const;
    Vec2 operator -  (const Vec2& rhs) const;
    Vec2 operator *  (const float val) const;
    Vec2 operator /  (const float val) const;

    void operator +=(const Vec2& rhs);
    void operator -=(const Vec2& rhs);
    void operator *=(const Vec2& rhs);
    void operator /=(const Vec2& rhs);

    float dist(const Vec2 & rhs) const;
        
    friend std::ostream& operator<<(std::ostream& stream,const Vec2& vec2);
};