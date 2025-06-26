#include <vulkan/vulkan.h>
#include <stdio.h>

int main() {
    VkInstance instance;
    VkResult result;

    // Create Vulkan instance
    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

    result = vkCreateInstance(&createInfo, NULL, &instance);
    if (result != VK_SUCCESS) {
        printf("Failed to create Vulkan instance!\n");
        return -1;
    }

    printf("Vulkan instance created successfully!\n");

    // Cleanup
    vkDestroyInstance(instance, NULL);
    return 0;
}