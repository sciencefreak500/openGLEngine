#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>


class Camera
{
private:
    glm::mat4 ViewMatrix;
    glm::mat4 ProjectionMatrix;
public:
    Camera();
    ~Camera();

    void computeMatricesFromInputs();
    glm::mat4 getViewMatrix();
    glm::mat4 getProjectionMatrix();

};


#endif
