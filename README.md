# VKMA: Vulkan Memory Allocator C++ Bindings
This header file is generated ([generator](https://github.com/Cvelth/vkma_generator)) using a [vulkan-hpp](https://github.com/KhronosGroup/Vulkan-Hpp) [fork](https://github.com/Cvelth/vkma_vulkan_hpp_fork), that's why the interface is so similar.

The binding header does not include original c header, so to use it, you still have to make sure that `vk_mem_alloc.h` is accessible (`#include "vk_mem_alloc.h"` is a valid line of code). An optimal way is to add its location to the include path of your preferred build system. You can get the header from the [original repository](https://github.com/GPUOpen-LibrariesAndSDKs/VulkanMemoryAllocator).

If you find any bugs or problems, I'd appreciate an issue either here or in the [generator repository](https://github.com/Cvelth/vkma_generator).

## Example
### Original VulkanMemoryAllocator (from [here](https://github.com/GPUOpen-LibrariesAndSDKs/VulkanMemoryAllocator#example))
```c++
VkBufferCreateInfo bufferInfo = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
bufferInfo.size = 65536;
bufferInfo.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;

VmaAllocationCreateInfo allocInfo = {};
allocInfo.usage = VMA_MEMORY_USAGE_GPU_ONLY;

VkBuffer buffer;
VmaAllocation allocation;
vmaCreateBuffer(allocator, &bufferInfo, &allocInfo, &buffer, &allocation, nullptr);
```
### vkma
```c++
vkma::BufferCreateInfo buffer_info = {
  .size = 65536,
  .usage = vk::BufferUsageFlagBits::eVertexBuffer | vk::BufferUsageFlagBits::eTransferDst,
};
vkma::AllocationCreateInfo allocation_info = {
  .usage = vkma::MemoryUsage::eGpuOnly
};
auto vkma_buffer = allocator.createUnique(buffer_info, allocation_info);
auto vk_buffer = vkma_buffer->get();
auto allocation = vkma_buffer->getAllocation();
```

## Breaking API changes
In order to simplify generation some functions were renamed:
- [`vmaDefragmentationBegin(...)`](https://gpuopen-librariesandsdks.github.io/VulkanMemoryAllocator/html/vk__mem__alloc_8h.html#a36ba776fd7fd5cb1e9359fdc0d8e6e8a) becomes  `allocator.createDefragmentationContext(...)` instead of `allocator.defragmentationBegin(...)`
- [`vmaDefragmentationEnd(...)`](https://gpuopen-librariesandsdks.github.io/VulkanMemoryAllocator/html/vk__mem__alloc_8h.html#a8774e20e91e245aae959ba63efa15dd2) becomes `allocator.destroyDefragmentationContext(...)` instead of `allocator.defragmentationEnd(...)`

## See also
- [The generator](https://github.com/Cvelth/vkma_generator)
- [VulkanMemoryAllocator](https://github.com/GPUOpen-LibrariesAndSDKs/VulkanMemoryAllocator)
- [Vulkan-Hpp](https://github.com/KhronosGroup/Vulkan-Hpp)
