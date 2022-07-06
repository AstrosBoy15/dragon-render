#include "PlayState.h"

PlayState::PlayState(WindowManager* win_mgr, RenderManager* renderer, Loader* loader) : GameState(win_mgr, renderer, loader) {

}

PlayState::~PlayState() {

}

void PlayState::init() {
	std::cout << "Init playstate" << std::endl;
	std::cout << Assets::isLoaded << std::endl;
}

void PlayState::tick() {
	glm::vec3 position = glm::vec3(0.0f);

	if (win_mgr->isKeyDown(GLFW_KEY_MINUS)) {
		zoom += 0.05f;
	}

	if (win_mgr->isKeyDown(GLFW_KEY_EQUAL)) {
		zoom -= 0.05f;
	}

	if (win_mgr->isKeyDown(GLFW_KEY_A)) {
		position.x -= 1;
	}

	if (win_mgr->isKeyDown(GLFW_KEY_D)) {
		position.x += 1;
	}

	if (win_mgr->isKeyDown(GLFW_KEY_W)) {
		position.z -= 1;
	}

	if (win_mgr->isKeyDown(GLFW_KEY_S)) {
		position.z += 1;
	}

	if (win_mgr->isKeyDown(GLFW_KEY_LEFT_SHIFT)) {
		position.y -= 1;
	}

	if (win_mgr->isKeyDown(GLFW_KEY_SPACE)) {
		position.y += 1;
	}

	if (zoom > 2.0f) zoom = 2.0f;
	if (zoom < 0.4f) zoom = 0.4f;

	win_mgr->camera->tick(win_mgr->getMouseDelta());
	win_mgr->camera->setZoom(zoom);
	win_mgr->camera->moveRelative(position, 0.09f);

	rotation += 0.3f;
	if (rotation > 360) {
		rotation -= 360;
	}
}

void PlayState::render() {
	renderer->render(ModelGeometries::getSphere(20), nullptr, glm::vec3(0, 0, -5), glm::vec3(0, 0, 0), glm::vec2(1.0f, 1.0f), glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));

	renderer->render(ModelGeometries::cube, nullptr, glm::vec3(3, 0, -5), glm::vec3(0, 0, 0), glm::vec2(1.0f, 1.0f), glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
}

void PlayState::stop() {
	GameState::stop();
}