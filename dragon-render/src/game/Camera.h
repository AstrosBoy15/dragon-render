#pragma once

#include "Global.h"

class Camera {
private:
	glm::vec3 position = glm::vec3(0.0f);
	float zoom = 1.0f;
	float pitch = 0, yaw = 0, roll = 0;

public:
	void tick(glm::vec2 mouseDelta);
	void moveDirect(const glm::vec3& target, const float t);
	void moveRelative(const glm::vec3& add, const float t);
	glm::mat4 getViewMatrix();
	glm::vec3 getPosition();
	void setZoom(float zoom);
	float getZoom();
};