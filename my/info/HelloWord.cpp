/*
Below is an example of a minimal “Hello World” program using Vulkan in C++. This example creates a Vulkan instance and prints a message stating 
that Vulkan has been initialized. 
Note that this code only initializes Vulkan and doesn’t create any window or rendering surface. You’ll need to have the Vulkan SDK installed 
and properly set up on your system to compile and run this code.

### Hello Vulkan Example

```cpp
*/
#include <vulkan/vulkan.h>
#include <iostream>

int main() {
    // Set up application information
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Vulkan";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    // Create the Vulkan instance create info structure
    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    // Create the Vulkan instance
    VkInstance instance;
    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create Vulkan instance!" << std::endl;
        return -1;
    }

    // Print hello message after successful initialization
    std::cout << "Hello Vulkan World!" << std::endl;

    // Clean up the Vulkan instance
    vkDestroyInstance(instance, nullptr);
    return 0;
}
/*
```

### How It Works

1. **VkApplicationInfo Initialization:**  
   This structure provides information about your application. Although not strictly required, it can help the driver optimize for an application’s needs.

2. **VkInstanceCreateInfo Setup:**  
   This structure tells Vulkan how to create an instance using the provided application information.

3. **Instance Creation:**  
   The call to `vkCreateInstance` creates a new Vulkan instance. If the creation fails (i.e., the return value isn’t `VK_SUCCESS`), an error message is printed.

4. **Message Display:**  
   Once the Vulkan instance is successfully created, the program prints “Hello Vulkan World!” to confirm that initialization succeeded.

5. **Cleanup:**  
   Finally, the instance is destroyed using `vkDestroyInstance` before the application exits.

### Compilation

Make sure you have the Vulkan SDK installed. Then you can compile the program using a command like:

```bash
g++ -std=c++17 -o hello_vulkan hello_vulkan.cpp -lvulkan
```

Run the resulting executable, and you should see the "Hello Vulkan World!" message.

This sample serves as a starting point, and from here you can extend the program to create a window, setup a render pipeline, and eventually draw 
graphics using Vulkan. Enjoy exploring Vulkan!
/*