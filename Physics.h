//
// Created by Parth on 12/20/2019.
//

#ifndef PHYSICS_ENGINE_PHYSICS_H
#define PHYSICS_ENGINE_PHYSICS_H

#include "TransformObject.h"
#include "polygons/Rectangle.h"
#include "polygons/Circle.h"

class Physics {

    private:
        static float gravity[2];
        static bool rectangleCircleCollision(Rectangle* rectangle, Circle* circle, float &maxPenetration, int &faceIndex);
        static bool circleCircleCollision(Circle* circle1, Circle* circle2);

        static std::array<float, 2> getSupportPoint(Rectangle* rectangle, float axisX, float axisY);
        static float getPenetration(int &faceIndex, Rectangle* rectangle1, Rectangle* rectangle2);

        static std::array<float, 2> calculateContactPoint(Rectangle* rectangle1, Rectangle* rectangle2, float maxPenetration, int faceIndex);
        static std::array<float, 2> calculateContactPoint(Rectangle* rectangle, Circle* circle, float maxPenetration, int faceIndex);

    public:
        constexpr static float deltaTime = 0.01f;

        static void updatePosition(TransformObject &transformObject);
        static void updateRotation(TransformObject &transformObject);
        static void setGravity(float x, float y);
        static float getGravityX();
        static float getGravityY();
        static bool polygonCollisionDetected(TransformObject object1, TransformObject object2, float &maxPenetration1, float &maxPenetration2, int &faceIndex1, int &faceIndex2);
        static bool collisionDetected(TransformObject object1, TransformObject object2, float &maxPenetration, int &faceIndex);
        static void resolveCollision(TransformObject &object1, TransformObject &object2, float penetration, int faceIndex);
};


#endif //PHYSICS_ENGINE_PHYSICS_H
