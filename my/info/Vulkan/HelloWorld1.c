#include <stdio.h>
#include <stdlib.h>
#include <vulkan/vulkan.h>

int main(void) {
    // Set up the application info
    VkApplicationInfo appInfo = {0};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pNext = NULL;
    appInfo.pApplicationName = "Hello Vulkan in C";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    // Set up the instance creation info struct
    VkInstanceCreateInfo createInfo = {0};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pNext = NULL;
    createInfo.flags = 0;
    createInfo.pApplicationInfo = &appInfo;
    createInfo.enabledLayerCount = 0;
    createInfo.ppEnabledLayerNames = NULL;
    createInfo.enabledExtensionCount = 0;
    createInfo.ppEnabledExtensionNames = NULL;

    // Create the Vulkan instance
    VkInstance instance;
    VkResult result = vkCreateInstance(&createInfo, NULL, &instance);
    if (result != VK_SUCCESS) {
        printf("Failed to create Vulkan instance: %d\n", result);
        return EXIT_FAILURE;
    }

    // Print the hello message
    printf("Hello Vulkan World in C!\n");

    // Clean up and destroy the Vulkan instance
    vkDestroyInstance(instance, NULL);
    
    return EXIT_SUCCESS;
}