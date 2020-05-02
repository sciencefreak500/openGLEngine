#ifndef CAMERA_H
#define CAMERA_H

#include "application.h"
#include <glm/glm.hpp>


class Camera : public Application
{
private:
    glm::mat4 ViewMatrix;
    glm::mat4 ProjectionMatrix;

    // direction the camera is facing
    glm::vec3 direction;

    // right facing vector from horizontal direction angle
    glm::vec3 right;

    // position of camera
    glm::vec3 position;

    // 3 units / second
    float speed;

public:
    Camera();
    ~Camera();

    void computeMatricesFromInputs();
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();

    void moveForward();
    void moveLeft();
    void moveRight();
    void moveBackward();

};


#endif
