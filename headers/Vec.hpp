#ifndef Vec_h
#define Vec_h

#include <iostream>
class Vec2 {
public:
    float x , y; 
    ~Vec2();
    Vec2();
    Vec2(float x, float y);
    float operator *(Vec2 other) { return x * other.x + y * other.y; }
    Vec2 operator +(Vec2 other) { return Vec2(x + other.x,y + other.y); }
    Vec2 operator -(Vec2 other) { return Vec2(x - other.x,y - other.y); }
    void operator +=(Vec2 other) { x += other.x; y += other.y; }
    void operator -=(Vec2 other) { x -= other.x; y -= other.y; }
    void operator *=(float other) { x *= other; y *= other; }
    Vec2& operator = (Vec2 other) { x = other.x; y= other.y; return *this; }
    Vec2 normal() { return Vec2(-y,x); }
    float cross(Vec2 other) { return x*other.y - y*other.x; }
    Vec2 normalize();
};

#endif