#ifndef COLLISION_DETECTION_HPP
#define COLLISION_DETECTION_HPP

#include "Vec2.hpp"
#include <array>
#include <algorithm>
#include <limits>

struct CollisionInfo {
    float overlap;
    Vec2 normal;
};

CollisionInfo SAT(const std::array<Vec2, 4>& A, const std::array<Vec2, 4>& B)
{
    float minOverlap = 0;
    Vec2 normal;
    bool first = true;

    for (int shape = 0; shape < 2; shape++)
    {
        const auto& points = (shape == 0) ? A : B;

        for (int i = 0; i < 4; i++)
        {
            Vec2 edge = points[(i + 1) % 4] - points[i];
            Vec2 axis = edge.normal();

            float minA = A[0] * axis;
            float maxA = minA;

            for (const Vec2& point : A)
            {
                float p = point * axis;
                minA = std::min(minA, p);
                maxA = std::max(maxA, p);
            }

            float minB = B[0] * axis;
            float maxB = minB;

            for (const Vec2& point : B)
            {
                float p = point * axis;
                minB = std::min(minB, p);
                maxB = std::max(maxB, p);
            }

            if (maxA < minB || maxB < minA)
                return {0, Vec2(0, 0)};

            float overlap = std::min(maxA, maxB) - std::max(minA, minB);

            if (first || overlap < minOverlap)
            {
                minOverlap = overlap;
                normal = axis;
                first = false;
            }
        }
    }

    Vec2 direction = B[0] - A[0];

    if (direction * normal < 0)
        normal *= -1;

    return {minOverlap, normal};
}

#endif COLLISION_DETECTION_HPP