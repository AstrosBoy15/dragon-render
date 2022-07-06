#pragma once

#include "Global.h"
#include "game/state/GameState.h"
#include "game/WindowManager.h"
#include "render/RenderManager.h"
#include "util/Loader.h"
#include "main/Assets.h"
#include "textures/Texture.h"
#include "models/ModelGeometries.h"

#include <vector>

class PlayState : public GameState{
private:
	float zoom = 1.0f;
	float rotation = 0.0f;

public:
	PlayState(WindowManager* win_mgr, RenderManager* renderer, Loader* loader);
	~PlayState();

	void init() override;
	void tick() override;
	void render() override;
	void stop() override;
};