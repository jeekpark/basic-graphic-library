#pragma once

#include <vector>

using VkInstance = struct VkInstance_T*;
using VkSurfaceKHR = struct VkSurfaceKHR_T*;

struct VkAllocationCallbacks;

namespace bgl
{

using VulkanFunctionPointer = void (*)();

namespace Vulkan
{
    bool isAvailable(bool requireGraphics = true);
    VulkanFunctionPointer getFunction(const char* name);
    const std::vector<const char*>& getGraphicsRequiredInstanceExtensions();
} // namespace Vulkan

} // namespace bgl;