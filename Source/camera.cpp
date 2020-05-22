#include "camera.h"

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;


Camera::Camera(/* args */)
{
    position = glm::vec3( 0, 0, 5 );
	speed = 3.0f; 
}

Camera::~Camera()
{
}

void Camera::computeMatricesFromInputs()
{
    float mouseSpeed = 0.005f;
    float horizontalAngle = 3.14f, verticalAngle = 0.0f;

    // Compute new orientation
	// horizontalAngle += mouseSpeed * float(w/2 - mouseX );
	// verticalAngle   += mouseSpeed * float( h/2 - mouseY );

	direction = glm::vec3(
		cos(verticalAngle) * sin(horizontalAngle), 
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
	);

	right = glm::vec3(
		sin(horizontalAngle - 3.14f/2.0f), 
		0,
		cos(horizontalAngle - 3.14f/2.0f)
	);
    
}

mat4 Camera::getViewMatrix()
{

}

mat4 Camera::getProjectionMatrix()
{

}

void Camera::moveForward()
{
    // position += direction * deltaTime * speed;
}

void Camera::moveBackward()
{
    // position -= direction * deltaTime * speed;
}

void Camera::moveLeft()
{
    // position -= right * deltaTime * speed;
}

void Camera::moveRight()
{
    // position += right * deltaTime * speed;
}


