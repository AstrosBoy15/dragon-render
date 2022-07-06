#include "Texture.h"

Texture::Texture(unsigned int textureID, int width, int height)
	: textureID(textureID), width(width), height(height) {}

unsigned int Texture::getTextureID() {
	return textureID;
}

int Texture::getWidth() {
	return width;
}

int Texture::getHeight() {
	return height;
}