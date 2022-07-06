#pragma once

#include "Global.h"

namespace dragon {
	static glm::vec3 lerp(const glm::vec3& start, const glm::vec3& end, const float t) {
		return start * (1.0f - t) + end * t;
	}

	static glm::vec3 generateNormal(const glm::vec3& first, const glm::vec3& second, const glm::vec3& third) {
		glm::vec3 vector1 = first - second;
		glm::vec3 vector2 = third - second;

		glm::vec3 normal = glm::normalize(glm::cross(vector1, vector2));

		return normal;
	}

	static glm::vec3 cubeToSpherePoint(const glm::vec3& point) {
		float x2 = glm::pow(point.x, 2);
		float y2 = glm::pow(point.y, 2);
		float z2 = glm::pow(point.z, 2);

		float xp = point.x * glm::sqrt(1 - y2 / 2 - z2 / 2 + y2 * z2 / 3);
		float yp = point.y * glm::sqrt(1 - z2 / 2 - x2 / 2 + z2 * x2 / 3);
		float zp = point.z * glm::sqrt(1 - x2 / 2 - y2 / 2 + x2 * y2 / 3);

		return { xp, yp, zp };
	}
}