#pragma once

#include "Global.h"
#include "WindowManager.h"
#include "render/RenderManager.h"
#include "util/Loader.h"
#include "game/state/GameState.h"
#include "game/state/SplashState.h"
#include "game/state/MenuState.h"
#include "game/state/PlayState.h"

class GameStateManager {
private:
	WindowManager* win_mgr;
	RenderManager* renderer;
	Loader* loader;

	GameState* activeState;
	SplashState* splashState;
	MenuState* menuState;
	PlayState* playState;

public:
	GameStateManager(WindowManager* win_mgr, RenderManager* renderer, Loader* loader);
	~GameStateManager();
	void update();
	void setActiveState(States state);
};