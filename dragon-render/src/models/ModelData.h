#pragma once

#include "Global.h"
#include <vector>

class ModelData {
private:
	std::vector<float> positionCoords;
	std::vector<float> textureCoords;
	std::vector<float> normalCoords;
	std::vector<int> indices;

	unsigned int vao;
	std::vector<unsigned int> vbos;

	void createVao();
	void storeAtribute(std::vector<float>& attrib, int attribNumber, int attribSize);
	void storeIndices();

public:
	ModelData(std::vector<float> positionCoords, std::vector<float> textureCoords, std::vector<float> normalCoords, std::vector<int> indices);
	~ModelData();

	void bindVao();
	void unbindVao();
	int getVertexCount();
};

