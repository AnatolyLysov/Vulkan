/*
Below is an example of a minimal "Hello Vulkan" program written in C. This program creates a Vulkan instance and prints 
the message "Hello Vulkan World in C!" to the console. Make sure the Vulkan SDK is installed and properly configured on your system.

### Vulkan Hello World in C

```c
*/
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
```
/*
### How It Works

1. **VkApplicationInfo Initialization:**  
   This structure provides information about your application to Vulkan. Although it's optional, it helps the driver optimize for your application's needs.

2. **VkInstanceCreateInfo Setup:**  
   This structure specifies details for creating a Vulkan instance. In this example, no layers or extensions are enabled.

3. **Instance Creation:**  
   `vkCreateInstance` is called to create a new Vulkan instance. If the call fails, the program prints an error message and exits.

4. **Printing the Message:**  
   Once the Vulkan instance is successfully created, the program prints "Hello Vulkan World in C!" to confirm that initialization succeeded.

5. **Cleanup:**  
   Finally, the Vulkan instance is destroyed with `vkDestroyInstance` before the program exits.

### Compilation

Make sure you have the Vulkan SDK installed, then compile the code using a command similar to:

```bash
gcc -std=c11 -o hello_vulkan hello_vulkan.c -lvulkan
```

Run the resulting executable, and you should see the printed message confirming that your Vulkan instance was created successfully. 
Enjoy experimenting with Vulkan in C!
*/