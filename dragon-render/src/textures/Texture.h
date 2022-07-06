#pragma once

#include "Global.h"

enum TextureType {
	NONE = 0, NORMAL
};

class Texture {
public:
	Texture(unsigned int textureID, int width, int height);

	unsigned int getTextureID();
	int getWidth();
	int getHeight();

private:
	unsigned int textureID;
	int width, height;
};

