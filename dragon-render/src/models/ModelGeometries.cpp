#include "ModelGeometries.h"


void ModelGeometries::generateCube() {
	std::vector<float> vertices = {
		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,0.5f,-0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,-0.5f,0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		0.5f,0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,0.5f,
		-0.5f,0.5f,0.5f,

		-0.5f,0.5f,0.5f,
		-0.5f,0.5f,-0.5f,
		0.5f,0.5f,-0.5f,
		0.5f,0.5f,0.5f,

		-0.5f,-0.5f,0.5f,
		-0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,-0.5f,
		0.5f,-0.5f,0.5f
	};

	std::vector<float> textureCoords = {
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0,
		0,0,
		0,1,
		1,1,
		1,0
	};

	std::vector<float> normalCoords = {
		0.0, 0.0, -1.0,
		0.0, 0.0, -1.0,
		0.0, 0.0, -1.0,
		0.0, 0.0, -1.0,

		0.0, 0.0, 1.0,
		0.0, 0.0, 1.0,
		0.0, 0.0, 1.0,
		0.0, 0.0, 1.0,

		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,
		1.0, 0.0, 0.0,

		-1.0, 0.0, 0.0,
		-1.0, 0.0, 0.0,
		-1.0, 0.0, 0.0,
		-1.0, 0.0, 0.0,

		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 1.0, 0.0,

		0.0, -1.0, 0.0,
		0.0, -1.0, 0.0,
		0.0, -1.0, 0.0,
		0.0, -1.0, 0.0,
	};

	std::vector<int> indices = {
		0,1,3,
		3,1,2,
		4,5,7,
		7,5,6,
		8,9,11,
		11,9,10,
		12,13,15,
		15,13,14,
		16,17,19,
		19,17,18,
		20,21,23,
		23,21,22
	};

	cube = new ModelData(vertices, textureCoords, normalCoords, indices);
}

void ModelGeometries::generateSphere(int detail) {
	std::vector<float> vertices, textureCoords, normalCoords;
	std::vector<int> indices;

	std::vector<glm::vec3> rotations = {
		{0, 0, 0},
		{0, 90, 0},
		{0, 180, 0},
		{0, -90, 0},
		{90, 0, 0},
		{-90, 0, 0}
	};

	float z = 1;
	int index = 0;

	for (glm::vec3& rotation : rotations) {
		glm::mat4 transform(1.0f);
		transform = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
		transform = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
		transform = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

		for (int i = 0; i < detail; i++) {
			float y = i * 2 / (float)detail - 1;

			for (int j = 0; j < detail; j++) {
				float x = j * 2 / (float)detail - 1;
				glm::vec3 p0 = dragon::cubeToSpherePoint(transform * glm::vec4(x, y, z, 1.0f));
				glm::vec3 p1 = dragon::cubeToSpherePoint(transform * glm::vec4(x, y + 2 / (float)detail, z, 1.0f));
				glm::vec3 p2 = dragon::cubeToSpherePoint(transform * glm::vec4(x + 2 / (float)detail, y, z, 1.0f));
				glm::vec3 p3 = dragon::cubeToSpherePoint(transform * glm::vec4(x + 2 / (float)detail, y + 2 / (float)detail, z, 1.0f));


				//TODO Fix so that each vertex is only added once in total
				vertices.insert(vertices.end(), { p0.x, p0.y, p0.z });
				vertices.insert(vertices.end(), { p2.x, p2.y, p2.z });
				vertices.insert(vertices.end(), { p1.x, p1.y, p1.z });
				vertices.insert(vertices.end(), { p1.x, p1.y, p1.z });
				vertices.insert(vertices.end(), { p2.x, p2.y, p2.z });
				vertices.insert(vertices.end(), { p3.x, p3.y, p3.z });

				normalCoords.insert(normalCoords.end(), { p0.x, p0.y, p0.z });
				normalCoords.insert(normalCoords.end(), { p2.x, p2.y, p2.z });
				normalCoords.insert(normalCoords.end(), { p1.x, p1.y, p1.z });
				normalCoords.insert(normalCoords.end(), { p1.x, p1.y, p1.z });
				normalCoords.insert(normalCoords.end(), { p2.x, p2.y, p2.z });
				normalCoords.insert(normalCoords.end(), { p3.x, p3.y, p3.z });

				indices.insert(indices.end(), { index, index + 1, index + 2, index + 3, index + 4, index + 5 });

				index += 6;
			}
		}
	}

	textureCoords = { 0 };

	ModelData* sphere = new ModelData(vertices, textureCoords, normalCoords, indices);
	spheres.insert({ detail, sphere });
}

ModelData* ModelGeometries::getSphere(int detail) {
	return spheres[detail];
}

void ModelGeometries::cleanUp() {
	delete cube;

	for (auto& sphere : spheres) {
		delete sphere.second;
	}

	spheres.clear();
}