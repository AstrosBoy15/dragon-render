#include "Camera.h"

void Camera::tick(glm::vec2 mouseDelta) {
	yaw += mouseDelta.x * 0.1;
	pitch += mouseDelta.y * 0.1;

	if (pitch > 90) pitch = 90;
	if (pitch < -90) pitch = -90;
}

void Camera::moveDirect(const glm::vec3& target, const float t) {
	position = dragon::lerp(position, target, t);
}

void Camera::moveRelative(const glm::vec3& add, const float t) {
	glm::mat4 transform = glm::mat4(1.0f);
	transform = glm::rotate(transform, glm::radians(yaw), glm::vec3(0.0f, -1.0f, 0.0f));
	glm::vec3 dir = glm::vec3(transform * glm::vec4(add, 1.0f));
	position = dragon::lerp(position, position + dir, t);
}

glm::mat4 Camera::getViewMatrix() {
	glm::mat4 view = glm::mat4(1.0f);
	view = glm::scale(view, glm::vec3(zoom));
	view = glm::rotate(view, glm::radians(pitch), glm::vec3(1.0, 0.0, 0.0));
	view = glm::rotate(view, glm::radians(yaw), glm::vec3(0.0, 1.0, 0.0));
	view = glm::rotate(view, glm::radians(roll), glm::vec3(0.0, 0.0, 1.0));
	view = glm::translate(view, glm::vec3(-position));
	return view;
}

glm::vec3 Camera::getPosition() {
	return position;
}

void Camera::setZoom(float zoom) {
	this->zoom = glm::exp(zoom);
}

float Camera::getZoom() {
	return zoom;
}