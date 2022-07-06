#pragma once

#include "Global.h"
#include "ModelData.h"
#include <unordered_map>

class ModelGeometries {
private:
	static inline std::unordered_map<int, ModelData*> spheres;

public:
	static inline ModelData* cube;
	static inline ModelData* sphere;

	static void generateCube();
	static void generateSphere(int detail);
	static ModelData* getSphere(int detail);
	static void cleanUp();
};

