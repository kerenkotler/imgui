/*! \file imgui_impl.h
 *  \brief Enter description here.
 *  \author Georgi Gerganov
 */

#pragma once

#if (defined(__EMSCRIPTEN__))
#define IMGUI_IMPL_OPENGL_LOADER_GLEW
#endif

#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"

#if defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)
#include <GL/gl3w.h>    // Initialize with gl3wInit()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLEW)
#include <GL/glew.h>    // Initialize with glewInit()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
#include <glad/glad.h>  // Initialize with gladLoadGL()
#else
#include IMGUI_IMPL_OPENGL_LOADER_CUSTOM
#endif

#include <GLFW/glfw3.h>

struct GLFWwindow;

bool ImGui_Init(GLFWwindow* window, bool install_callbacks) {
    // Decide GL+GLSL versions
#if __APPLE__
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Initialize OpenGL loader
#if defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)
    bool err = gl3wInit() != 0;
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLEW)
    bool err = glewInit() != GLEW_OK;
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
    bool err = gladLoadGL() == 0;
#else
    bool err = false; // If you use IMGUI_IMPL_OPENGL_LOADER_CUSTOM, your loader is likely to requires some form of initialization.
#endif
    if (err) {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return false;
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;   // Enable Gamepad Controls

    // Setup Platform/Renderer bindings
    bool res = true;
    res &= ImGui_ImplGlfw_InitForOpenGL(window, install_callbacks);

#ifdef __EMSCRIPTEN__
    res &= ImGui_ImplOpenGL3_Init("#version 300 es");
#else
    res &= ImGui_ImplOpenGL3_Init(glsl_version);
#endif

    return res;
}

void ImGui_Shutdown() { ImGui_ImplOpenGL3_Shutdown(); ImGui_ImplGlfw_Shutdown(); }
void ImGui_NewFrame() { ImGui_ImplOpenGL3_NewFrame(); ImGui_ImplGlfw_NewFrame(); ImGui::NewFrame(); }

void ImGui_RenderDrawData(ImDrawData* draw_data)    { ImGui_ImplOpenGL3_RenderDrawData(draw_data); }

bool ImGui_CreateFontsTexture()     { return ImGui_ImplOpenGL3_CreateFontsTexture(); }
void ImGui_DestroyFontsTexture()    { ImGui_ImplOpenGL3_DestroyFontsTexture(); }
bool ImGui_CreateDeviceObjects()    { return ImGui_ImplOpenGL3_CreateDeviceObjects(); }
void ImGui_DestroyDeviceObjects()   { ImGui_ImplOpenGL3_DestroyDeviceObjects(); }
