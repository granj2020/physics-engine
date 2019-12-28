//
// Created by Parth on 12/20/2019.
//

#include <cmath>
#include "TransformObject.h"

TransformObject::TransformObject() {
    hasPhysics = false;
    calculateCenterOfMass();
}

TransformObject::TransformObject(Polygon* shape) {
    polygon = shape;
    calculateCenterOfMass();
}

void TransformObject::setPosition(float x, float y) {
    position[0] = x;
    position[1] = y;
    polygon->setPosition(x, y);
}

float* TransformObject::getPosition() {
    return position;
}

void TransformObject::setVelocity(float x, float y) {
    velocity[0] = x;
    velocity[1] = y;
}

float* TransformObject::getVelocity() {
    return velocity;
}

void TransformObject::setAcceleration(float x, float y) {
    acceleration[0] = x;
    acceleration[1] = y;
}

float* TransformObject::getAcceleration() {
    return acceleration;
}

Polygon* TransformObject::getPolygon() {
    return polygon;
}

void TransformObject::addPhysics() {
    hasPhysics = true;
}

void TransformObject::addForce(const float force[2]) {
    float xAcceleration = ((mass * acceleration[0]) + force[0]) / mass;
    float yAcceleration = ((mass * acceleration[1]) + force[1]) / mass;
    setAcceleration(xAcceleration, yAcceleration);
}

void TransformObject::addForceAtPosition(float forcePosition[2], float force[2]) {
    float r[2] = {forcePosition[0] - centerOfMass[0], forcePosition[1] - centerOfMass[1]};
    float torque[2] = {r[0] * force[1], -r[1] * force[0]};
    addTorque(forcePosition, torque);
}

void TransformObject::addTorque(float torquePosition[2], float torque[2]) {
    float T = sqrt(pow(torque[0], 2) + pow(torque[1], 2));
    float r = sqrt(pow(torquePosition[0] - centerOfMass[0], 2) + pow(torquePosition[1] - centerOfMass[1], 2));
    float I = polygon->getMomentOfInertia() + (mass * pow(r, 2));
    angularAcceleration = T / I;
}

void TransformObject::calculateCenterOfMass() {
    float* vertices = polygon->getVertices();
    float xPositions = 0.0;
    float yPositions = 0.0;
    int vertexIndex = 0;
    for (int i = 0; i < polygon->numberOfVertices; i++) {
        xPositions += vertices[vertexIndex];
        yPositions += vertices[vertexIndex + 1];
        vertexIndex += 3;
    }
    centerOfMass[0] = xPositions / polygon->numberOfVertices;
    centerOfMass[1] = yPositions / polygon->numberOfVertices;
}

void TransformObject::setCenterOfMass(float x, float y) {
    centerOfMass[0] = x;
    centerOfMass[1] = y;
}

float* TransformObject::getCenterOfMass() {
    return centerOfMass;
}