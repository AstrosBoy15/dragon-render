#pragma once

#include <string>

#include "Global.h"
#include "game/Camera.h"

class WindowManager {
private:
    GLFWwindow* window;
    GLFWmonitor* monitor;
    const GLFWvidmode* mode;

    int window_width = 800;
    int window_height = 600;
    const std::string TITLE = "Butterfly Example App";
    const double VERSION = 0.1;

    bool fullscreen = false;
    int startup_width;
    double content_scale;

    bool keys[GLFW_KEY_LAST];
    bool buttons[3];

    glm::vec2 lastMousePos;

    void updateInput();
    void updateWindowFunctions();
public:
    Camera* camera;

    WindowManager();
    ~WindowManager();

    bool isKeyDown(int key);
    bool isKeyPressed(int key);
    bool isKeyReleased(int key);

    bool isMouseButtonDown(int button);
    bool isMouseButtonPressed(int button);
    bool isMouseButtonReleased(int button);

    glm::vec2 getMousePosition();
    glm::vec2 getMouseDelta();
    void setCursorPosition(glm::vec2 position);
    glm::vec2 getMouseWorldPosition(glm::vec2 world_scale);

    void updateWindow();

    GLFWwindow* createWindow();
    GLFWwindow* getWindow();

    int getWindowWidth();
    int getWindowHeight();
    float getContentScale();
};