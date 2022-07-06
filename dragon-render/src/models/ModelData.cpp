#include "ModelData.h"


ModelData::ModelData(std::vector<float> positionCoords, std::vector<float> textureCoords, std::vector<float> normalCoords, std::vector<int> indices) : positionCoords(positionCoords), textureCoords(textureCoords), normalCoords(normalCoords), indices(indices) {
	createVao();
	storeAtribute(positionCoords, 0, 3);
	storeAtribute(textureCoords, 1, 2);
	storeAtribute(normalCoords, 2, 3);
	storeIndices();
	unbindVao();
}

ModelData::~ModelData() {
	for (unsigned int& vbo : vbos) {
		glDeleteBuffers(1, &vbo);
	}

	glDeleteVertexArrays(1, &vao);
}

void ModelData::createVao() {
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}

void ModelData::bindVao() {
	glBindVertexArray(vao);
}

void ModelData::unbindVao() {
	glBindVertexArray(0);
}

void ModelData::storeAtribute(std::vector<float>& attrib, int attribNumber, int attribSize) {
	unsigned int vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, attrib.size() * sizeof(float), attrib.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(attribNumber, attribSize, GL_FLOAT, GL_FALSE, 0, 0);

	vbos.push_back(vbo);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ModelData::storeIndices() {
	unsigned int vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), indices.data(), GL_STATIC_DRAW);

	vbos.push_back(vbo);
}

int ModelData::getVertexCount() {
	return indices.size();
}