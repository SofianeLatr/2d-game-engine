#ifndef Body_h
#define Body_h

#include "Vec2.hpp"

class Shape{
public:
    Vec2 pos;
    float angle;

    Shape(Vec2 pos, float angle) : pos(pos), angle(angle) {};
}; 
class Body : public Shape {
public:

    Vec2 vel;
    float angVel;

    float mass;
    float invMass;
    float inertia;
    float invInertia;

    Vec2 force;
    float torque;

    ~Body(){};
    Body(Vec2 pos, float angle, float mass, bool isStatic) : Shape(pos, angle), mass(mass){
        if (isStatic) {
            invMass = 0;
            invInertia = 0;
        } else {
            invMass = 1.0f / mass;
            inertia = mass;
            invInertia = 1.0f / inertia;
        }
        vel = Vec2(0, 0);
        angVel = 0;
        force = Vec2(0, 0);
        torque = 0;
    }

    void applyForce(const Vec2& f){
        force += f;
    }
    void applyTorque(float t){
        torque += t;
    }
};

#endif