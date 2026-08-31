#ifndef Rect_h
#define Rect_h

#include "Body.hpp"
#include <array>

class Rect : public Body {
public:
    std::array<Vec2, 4> points;
    Vec2 size;

    ~Rect(){};
    Rect(Vec2 pos, Vec2 size, float angle, float mass, bool isStatic);    

    const std::array<Vec2, 4>& getPoints();
    const float getInertia() { return (1.0f / 12.0f) * mass * (size.x * size.x + size.y * size.y); };
};

#endif