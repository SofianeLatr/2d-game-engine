#ifndef Body_h
#define Body_h

#include "Vec2.hpp"

class Body {
public:

    Vec2 pos;
    float angle;
    Vec2 vel;
    float angVel;

    float mass;
    float invMass;
    float inertia;
    float invInertia;

    Vec2 force;
    float torque;

    bool isStatic;

    ~Body(){};
    Body(Vec2 pos, float angle, float mass, bool isStatic) : pos(pos), angle(angle), mass(mass), isStatic(isStatic) {
        if (isStatic) {
            invMass = 0;
            invInertia = 0;
        } else {
            invMass = 1.0f / mass;
            inertia = mass * 1.0f;
            invInertia = 1.0f / inertia;
        }
        vel = Vec2(0, 0);
        angVel = 0;
        force = Vec2(0, 0);
        torque = 0;
    }

    void applyForce(Vec2 f){
        force += f;
    }
    void applyTorque(float t){
        torque += t;
    }
};

#endif