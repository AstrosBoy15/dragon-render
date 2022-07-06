#pragma once

#include "Global.h"
#include "game/WindowManager.h"
#include "render/shader/GenShader.h"
#include "RenderModes.h"
#include "textures/Texture.h"
#include "models/ModelData.h"
#include "models/ModelGeometries.h"

class RenderManager {
private:
	WindowManager* win_mgr;
	Shader* activeShader;

	GenShader* genShader;
	RenderModes renderMode = RenderModes::WORLD;

	void loadModel();
	void prepare(Shader* shader);
	void finish(Shader* shader);
	void loadGenUniforms(const glm::vec3& position, const glm::vec3& rotation_deg, const glm::vec2& scale, const glm::vec4& color);

public:
	glm::vec2 world_scale = glm::vec2(0.5f);

	RenderManager(WindowManager* win_mgr);
	~RenderManager();
	void render(ModelData* model, Texture* texture, const glm::vec3& position, const glm::vec3& rotation_deg, const glm::vec2& scale, const glm::vec4& color);
	//void render(Texture* texture, const glm::vec3& position, const glm::vec3& rotation_deg, const glm::vec2& scale);
	RenderModes getRenderMode();
	void setRenderMode(RenderModes renderMode);
};