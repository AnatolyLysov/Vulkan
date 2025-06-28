#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

const int WIDTH = 800;
const int HEIGHT = 600;

typedef struct {
    GLFWwindow* window;
    VkInstance instance;
} VulkanApp;

void initWindow(VulkanApp* app) {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    app->window = glfwCreateWindow(WIDTH, HEIGHT, "Simple Vulkan Game", NULL, NULL);
}

void createInstance(VulkanApp* app) {
    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

    if (vkCreateInstance(&createInfo, NULL, &app->instance) != VK_SUCCESS) {
        fprintf(stderr, "Failed to create Vulkan instance!\n");
        exit(EXIT_FAILURE);
    }
}

void mainLoop(VulkanApp* app) {
    while (!glfwWindowShouldClose(app->window)) {
        glfwPollEvents();
    }
}

void cleanup(VulkanApp* app) {
    vkDestroyInstance(app->instance, NULL);
    glfwDestroyWindow(app->window);
    glfwTerminate();
}

int main() {
    VulkanApp app;

    initWindow(&app);
    createInstance(&app);
    mainLoop(&app);
    cleanup(&app);

    return 0;
}