// Copyright (c) 2021 Cvelth (cvelth.mail@gmail.com)
// SPDX-License-Identifier: Unlicense.

// This header is generated using [Vulkan-Hpp](https://github.com/KhronosGroup/Vulkan-Hpp)'s
// [fork](https://github.com/Cvelth/vkma_vulkan_hpp_fork).

#ifndef VKMA
#define VKMA

#if defined(_MSVC_LANG)
  #define VKMA_CPLUSPLUS _MSVC_LANG
#else
  #define VKMA_CPLUSPLUS __cplusplus
#endif

#if 201703L < VKMA_CPLUSPLUS
  #define VKMA_CPP_VERSION 20
#elif 201402L < VKMA_CPLUSPLUS
  #define VKMA_CPP_VERSION 17
#elif 201103L < VKMA_CPLUSPLUS
  #define VKMA_CPP_VERSION 14
#elif 199711L < VKMA_CPLUSPLUS
  #define VKMA_CPP_VERSION 11
#else
  #error "vkma.hpp needs at least c++ standard version 11"
#endif

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <functional>
#include <initializer_list>
#include <sstream>
#include <string>
#include <system_error>
#include <tuple>
#include <type_traits>

#if 17 <= VKMA_CPP_VERSION
  #include <string_view>
#endif

#if defined(VKMA_DISABLE_ENHANCED_MODE)
  #if !defined(VKMA_NO_SMART_HANDLE)
    #define VKMA_NO_SMART_HANDLE
  #endif
#else
  #include <memory>
  #include <vector>
#endif

#if !defined(VKMA_ASSERT)
  #include <cassert>
  #define VKMA_ASSERT assert
#endif

#if !defined(VKMA_ASSERT_ON_RESULT)
  #define VKMA_ASSERT_ON_RESULT VKMA_ASSERT
#endif

#if !defined(VKMA_ENABLE_DYNAMIC_LOADER_TOOL)
  #define VKMA_ENABLE_DYNAMIC_LOADER_TOOL 1
#endif

#if VKMA_ENABLE_DYNAMIC_LOADER_TOOL == 1
  #if defined(__linux__) || defined(__APPLE__)
    #include <dlfcn.h>
  #elif defined(_WIN32)
typedef struct HINSTANCE__ *HINSTANCE;
    #if defined(_WIN64)
typedef int64_t(__stdcall *FARPROC)();
    #else
typedef int(__stdcall *FARPROC)();
    #endif
extern "C" __declspec(dllimport) HINSTANCE __stdcall LoadLibraryA(char const *lpLibFileName);
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(HINSTANCE hLibModule);
extern "C" __declspec(dllimport) FARPROC
  __stdcall GetProcAddress(HINSTANCE hModule, const char *lpProcName);
  #endif
#endif

#if !defined(__has_include)
  #define __has_include(x) false
#endif

#if (201711 <= __cpp_impl_three_way_comparison) && __has_include(<compare> ) && !defined( VKMA_NO_SPACESHIP_OPERATOR )
  #define VKMA_HAS_SPACESHIP_OPERATOR
#endif
#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
  #include <compare>
#endif

// External bindings file:
#ifndef VKMA_BINDINGS_HPP
  #define VKMA_BINDINGS_HPP

  #ifdef VKMA_IMPLEMENTATION
    #define VMA_IMPLEMENTATION
  #endif

  /*
  In every place where you want to use Vulkan Memory Allocator, define appropriate
  macros if you want to configure the library and then include its header to
  include all public interface declarations. Example:
  */

  //#define VMA_HEAVY_ASSERT(expr) assert(expr)
  //#define VMA_USE_STL_CONTAINERS 1
  //#define VMA_DEDICATED_ALLOCATION 0
  //#define VMA_DEBUG_MARGIN 16
  //#define VMA_DEBUG_DETECT_CORRUPTION 1
  //#define VMA_DEBUG_INITIALIZE_ALLOCATIONS 1
  //#define VMA_RECORDING_ENABLED 1
  //#define VMA_DEBUG_MIN_BUFFER_IMAGE_GRANULARITY 256
  //#define VMA_USE_STL_SHARED_MUTEX 0
  //#define VMA_DEBUG_GLOBAL_MUTEX 1
  //#define VMA_MEMORY_BUDGET 0
  //#define VMA_STATIC_VULKAN_FUNCTIONS 0
  //#define VMA_DYNAMIC_VULKAN_FUNCTIONS 1

  //#define VMA_VULKAN_VERSION 1002000 // Vulkan 1.2
  //#define VMA_VULKAN_VERSION 1001000 // Vulkan 1.1
  //#define VMA_VULKAN_VERSION 1000000 // Vulkan 1.0

  /*
  #define VMA_DEBUG_LOG(format, ...) do { \
          printf(format, __VA_ARGS__); \
          printf("\n"); \
      } while(false)
  */

  #ifdef _MSVC_LANG
    #pragma warning(push, 4)
    #pragma warning(disable : 4127) // conditional expression is constant
    #pragma warning(disable : 4100) // unreferenced formal parameter
    #pragma warning(disable : 4189) // local variable is initialized but not referenced
    #pragma warning(disable : 4324) // structure was padded due to alignment specifier
  #endif
  #ifdef __clang__
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored                                                               \
      "-Wtautological-compare" // comparison of unsigned expression < 0 is always false
    #pragma clang diagnostic ignored "-Wunused-private-field"
    #pragma clang diagnostic ignored "-Wunused-parameter"
    #pragma clang diagnostic ignored "-Wmissing-field-initializers"
    #pragma clang diagnostic ignored "-Wnullability-completeness"
  #endif

  #include "vk_mem_alloc.h"

  #ifdef __clang__
    #pragma clang diagnostic pop
  #endif
  #ifdef _MSVC_LANG
    #pragma warning(pop)
  #endif

  #ifndef VKMA_ASSERT
    #define VKMA_ASSERT VMA_ASSERT
  #endif

  #define VKMA_NULL_HANDLE VK_NULL_HANDLE

VK_DEFINE_HANDLE(VkmaAllocator)                               // parent: none
VK_DEFINE_HANDLE(VkmaBuffer)                                  // parent: VkmaAllocator
VK_DEFINE_HANDLE(VkmaImage)                                   // parent: VkmaAllocator
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkmaAllocation)             // parent: VkmaAllocator
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkmaDefragmentationContext) // parent: VkmaAllocator
VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkmaPool)                   // parent: VkmaAllocator

struct VkmaBuffer_T {
  VkBuffer buffer;
  VkmaAllocation allocation;
};
static_assert(sizeof(VkmaBuffer_T) == sizeof(VkBuffer) + sizeof(VkmaAllocation),
              "struct and wrapper have different size!");
static_assert(std::is_standard_layout<VkmaBuffer_T>::value,
              "struct wrapper is not a standard layout!");

struct VkmaImage_T {
  VkImage image;
  VkmaAllocation allocation;
};
static_assert(sizeof(VkmaImage_T) == sizeof(VkImage) + sizeof(VkmaAllocation),
              "struct and wrapper have different size!");
static_assert(std::is_standard_layout<VkmaImage_T>::value,
              "struct wrapper is not a standard layout!");

using VkmaResult = VkResult;

using VkmaAllocatorCreateFlagBits = VmaAllocatorCreateFlagBits;
using VkmaRecordFlagBits = VmaRecordFlagBits;
using VkmaMemoryUsage = VmaMemoryUsage;
using VkmaAllocationCreateFlagBits = VmaAllocationCreateFlagBits;
using VkmaPoolCreateFlagBits = VmaPoolCreateFlagBits;
using VkmaDefragmentationFlagBits = VmaDefragmentationFlagBits;

using VkmaAllocatorCreateFlags = VmaAllocatorCreateFlags;
using VkmaRecordFlags = VmaRecordFlags;
using VkmaAllocationCreateFlags = VmaAllocationCreateFlags;
using VkmaPoolCreateFlags = VmaPoolCreateFlags;
using VkmaDefragmentationFlags = VmaDefragmentationFlags;

typedef void(VKAPI_PTR *PFN_vkmaAllocateDeviceMemoryFunction)(VkmaAllocator allocator,
                                                              uint32_t memoryType,
                                                              VkDeviceMemory memory,
                                                              VkDeviceSize size, void *pUserData);
typedef void(VKAPI_PTR *PFN_vkmaFreeDeviceMemoryFunction)(VkmaAllocator allocator,
                                                          uint32_t memoryType,
                                                          VkDeviceMemory memory, VkDeviceSize size,
                                                          void *pUserData);

using VkmaAllocationInfo = VmaAllocationInfo;
using VkmaBudget = VmaBudget;
using VkmaDefragmentationStats = VmaDefragmentationStats;
using VkmaPoolStats = VmaPoolStats;
using VkmaStatInfo = VmaStatInfo;

typedef struct VkmaAllocationCreateInfo {
  VkmaAllocationCreateFlags flags;
  VkmaMemoryUsage usage;
  VkMemoryPropertyFlags requiredFlags;
  VkMemoryPropertyFlags preferredFlags;
  uint32_t memoryTypeBits;
  VkmaPool VMA_NULLABLE pool;
  void *VMA_NULLABLE pUserData;
  float priority;
} VkmaAllocationCreateInfo;
static_assert(sizeof(VkmaAllocationCreateInfo) == sizeof(VmaAllocationCreateInfo),
              "struct and wrapper have different size!");
static_assert(std::is_standard_layout<VkmaAllocationCreateInfo>::value,
              "struct wrapper is not a standard layout!");

typedef struct VkmaDeviceMemoryCallbacks {
  PFN_vkmaAllocateDeviceMemoryFunction VMA_NULLABLE pfnAllocate;
  PFN_vkmaFreeDeviceMemoryFunction VMA_NULLABLE pfnFree;
  void *VMA_NULLABLE pUserData;
} VkmaDeviceMemoryCallbacks;
static_assert(sizeof(VkmaDeviceMemoryCallbacks) == sizeof(VmaDeviceMemoryCallbacks),
              "struct and wrapper have different size!");
static_assert(std::is_standard_layout<VkmaDeviceMemoryCallbacks>::value,
              "struct wrapper is not a standard layout!");

typedef struct VkmaRecordSettings {
  VkmaRecordFlags flags;
  const char *VMA_NOT_NULL pFilePath;
} VkmaRecordSettings;
static_assert(sizeof(VkmaRecordSettings) == sizeof(VmaRecordSettings),
              "struct and wrapper have different size!");
static_assert(std::is_standard_layout<VkmaRecordSettings>::value,
              "struct wrapper is not a standard layout!");

typedef struct VkmaVulkanFunctions {
  PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties;
  PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties;
  PFN_vkAllocateMemory vkAllocateMemory;
  PFN_vkFreeMemory vkFreeMemory;
  PFN_vkMapMemory vkMapMemory;
  PFN_vkUnmapMemory vkUnmapMemory;
  PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges;
  PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges;
  PFN_vkBindBufferMemory vkBindBufferMemory;
  PFN_vkBindImageMemory vkBindImageMemory;
  PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements;
  PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements;
  PFN_vkCreateBuffer vkCreateBuffer;
  PFN_vkDestroyBuffer vkDestroyBuffer;
  PFN_vkCreateImage vkCreateImage;
  PFN_vkDestroyImage vkDestroyImage;
  PFN_vkCmdCopyBuffer vkCmdCopyBuffer;

  PFN_vkGetBufferMemoryRequirements2KHR vkGetBufferMemoryRequirements2KHR;
  PFN_vkGetImageMemoryRequirements2KHR vkGetImageMemoryRequirements2KHR;

  PFN_vkBindBufferMemory2KHR vkBindBufferMemory2KHR;
  PFN_vkBindImageMemory2KHR vkBindImageMemory2KHR;

  PFN_vkGetPhysicalDeviceMemoryProperties2KHR vkGetPhysicalDeviceMemoryProperties2KHR;
} VkmaVulkanFunctions;
static_assert(sizeof(VkmaVulkanFunctions) >= sizeof(VmaVulkanFunctions),
              "struct and wrapper have different size!");
static_assert(std::is_standard_layout<VkmaVulkanFunctions>::value,
              "struct wrapper is not a standard layout!");

typedef struct VkmaAllocatorCreateInfo {
  VkmaAllocatorCreateFlags flags;
  VkPhysicalDevice VMA_NOT_NULL physicalDevice;
  VkDevice VMA_NOT_NULL device;
  VkDeviceSize preferredLargeHeapBlockSize;
  const VkAllocationCallbacks *VMA_NULLABLE pAllocationCallbacks;
  const VkmaDeviceMemoryCallbacks *VMA_NULLABLE pDeviceMemoryCallbacks;
  uint32_t frameInUseCount;
  const VkDeviceSize *VMA_NULLABLE
    VMA_LEN_IF_NOT_NULL("VkPhysicalDeviceMemoryProperties::memoryHeapCount") pHeapSizeLimit;
  const VkmaVulkanFunctions *VMA_NULLABLE pVulkanFunctions;
  const VkmaRecordSettings *VMA_NULLABLE pRecordSettings;
  VkInstance VMA_NOT_NULL instance;
  uint32_t vulkanApiVersion;
} VkmaAllocatorCreateInfo;
static_assert(sizeof(VkmaAllocatorCreateInfo) == sizeof(VmaAllocatorCreateInfo),
              "struct and wrapper have different size!");
static_assert(std::is_standard_layout<VkmaAllocatorCreateInfo>::value,
              "struct wrapper is not a standard layout!");

typedef struct VkmaDefragmentationInfo2 {
  VkmaDefragmentationFlags flags;
  uint32_t allocationCount;
  const VkmaAllocation VMA_NOT_NULL *VMA_NULLABLE VMA_LEN_IF_NOT_NULL(allocationCount) pAllocations;
  VkBool32 *VMA_NULLABLE VMA_LEN_IF_NOT_NULL(allocationCount) pAllocationsChanged;
  uint32_t poolCount;
  const VkmaPool VMA_NOT_NULL *VMA_NULLABLE VMA_LEN_IF_NOT_NULL(poolCount) pPools;
  VkDeviceSize maxCpuBytesToMove;
  uint32_t maxCpuAllocationsToMove;
  VkDeviceSize maxGpuBytesToMove;
  uint32_t maxGpuAllocationsToMove;
  VkCommandBuffer VMA_NULLABLE commandBuffer;
} VkmaDefragmentationInfo2;
static_assert(sizeof(VkmaDefragmentationInfo2) == sizeof(VmaDefragmentationInfo2),
              "struct and wrapper have different size!");
static_assert(std::is_standard_layout<VkmaDefragmentationInfo2>::value,
              "struct wrapper is not a standard layout!");

typedef struct VkmaPoolCreateInfo {
  uint32_t memoryTypeIndex;
  VkmaPoolCreateFlags flags;
  VkDeviceSize blockSize;
  size_t minBlockCount;
  size_t maxBlockCount;
  uint32_t frameInUseCount;
  float priority;
} VkmaPoolCreateInfo;
static_assert(sizeof(VkmaPoolCreateInfo) == sizeof(VmaPoolCreateInfo),
              "struct and wrapper have different size!");
static_assert(std::is_standard_layout<VkmaPoolCreateInfo>::value,
              "struct wrapper is not a standard layout!");

typedef struct VkmaStats {
  VkmaStatInfo memoryType[VK_MAX_MEMORY_TYPES];
  VkmaStatInfo memoryHeap[VK_MAX_MEMORY_HEAPS];
  VkmaStatInfo total;
} VkmaStats;
static_assert(sizeof(VkmaStats) == sizeof(VmaStats), "struct and wrapper have different size!");
static_assert(std::is_standard_layout<VkmaStats>::value,
              "struct wrapper is not a standard layout!");

// [[deprecated]]
// using VkmaDefragmentationInfo = VmaDefragmentationInfo;

inline VkmaResult vkmaCreateAllocator(const VkmaAllocatorCreateInfo *pCreateInfo,
                                      VkmaAllocator *pAllocator) {
  return vmaCreateAllocator(reinterpret_cast<const VmaAllocatorCreateInfo *>(pCreateInfo),
                            reinterpret_cast<VmaAllocator *>(pAllocator));
}
inline void vkmaDestroyAllocator(VkmaAllocator allocator) {
  return vmaDestroyAllocator(reinterpret_cast<VmaAllocator>(allocator));
}

inline void vkmaGetPhysicalDeviceProperties(VkmaAllocator allocator,
                                            VkPhysicalDeviceProperties *pPhysicalDeviceProperties) {
  VKMA_ASSERT(pPhysicalDeviceProperties);
  const VkPhysicalDeviceProperties *temp = nullptr;
  vmaGetPhysicalDeviceProperties(reinterpret_cast<VmaAllocator>(allocator), &temp);

  VKMA_ASSERT(temp);
  memcpy(pPhysicalDeviceProperties, temp, sizeof(VkPhysicalDeviceProperties));
}
inline void vkmaGetMemoryProperties(
  VkmaAllocator allocator, VkPhysicalDeviceMemoryProperties *pPhysicalDeviceMemoryProperties) {
  VKMA_ASSERT(pPhysicalDeviceMemoryProperties);
  const VkPhysicalDeviceMemoryProperties *temp = nullptr;
  vmaGetMemoryProperties(reinterpret_cast<VmaAllocator>(allocator), &temp);

  VKMA_ASSERT(temp);
  memcpy(pPhysicalDeviceMemoryProperties, temp, sizeof(VkPhysicalDeviceMemoryProperties));
}
inline void vkmaGetMemoryTypeProperties(VkmaAllocator allocator, uint32_t memoryTypeIndex,
                                        VkMemoryPropertyFlags *pFlags) {
  vmaGetMemoryTypeProperties(reinterpret_cast<VmaAllocator>(allocator), memoryTypeIndex, pFlags);
}

inline void vkmaSetCurrentFrameIndex(VkmaAllocator allocator, uint32_t frameIndex) {
  vmaSetCurrentFrameIndex(reinterpret_cast<VmaAllocator>(allocator), frameIndex);
}

inline void vkmaCalculateStats(VkmaAllocator allocator, VkmaStats *pStats) {
  vmaCalculateStats(reinterpret_cast<VmaAllocator>(allocator),
                    reinterpret_cast<VmaStats *>(pStats));
}
inline void vkmaGetBudget(VkmaAllocator allocator, VkmaBudget *pBudget) {
  vmaGetBudget(reinterpret_cast<VmaAllocator>(allocator), pBudget);
}
inline void vkmaBuildStatsString(VkmaAllocator allocator, VkBool32 detailedMap,
                                 char **ppStatsString) {
  vmaBuildStatsString(reinterpret_cast<VmaAllocator>(allocator), ppStatsString, detailedMap);
}
inline void vkmaFreeStatsString(VkmaAllocator allocator, const char *pStatsString) {
  vmaFreeStatsString(reinterpret_cast<VmaAllocator>(allocator), const_cast<char *>(pStatsString));
}

inline VkmaResult vkmaFindMemoryTypeIndex(VkmaAllocator allocator, uint32_t memoryTypeBits,
                                          const VkmaAllocationCreateInfo *pAllocationCreateInfo,
                                          uint32_t *pMemoryTypeIndex) {
  return vmaFindMemoryTypeIndex(reinterpret_cast<VmaAllocator>(allocator), memoryTypeBits,
                                reinterpret_cast<const VmaAllocationCreateInfo *>(
                                  pAllocationCreateInfo),
                                pMemoryTypeIndex);
}
inline VkmaResult vkmaFindMemoryTypeIndexForBufferInfo(
  VkmaAllocator allocator, const VkBufferCreateInfo *pBufferCreateInfo,
  const VkmaAllocationCreateInfo *pAllocationCreateInfo, uint32_t *pMemoryTypeIndex) {
  return vmaFindMemoryTypeIndexForBufferInfo(reinterpret_cast<VmaAllocator>(allocator),
                                             pBufferCreateInfo,
                                             reinterpret_cast<const VmaAllocationCreateInfo *>(
                                               pAllocationCreateInfo),
                                             pMemoryTypeIndex);
}
inline VkmaResult vkmaFindMemoryTypeIndexForImageInfo(
  VkmaAllocator allocator, const VkImageCreateInfo *pImageCreateInfo,
  const VkmaAllocationCreateInfo *pAllocationCreateInfo, uint32_t *pMemoryTypeIndex) {
  return vmaFindMemoryTypeIndexForImageInfo(reinterpret_cast<VmaAllocator>(allocator),
                                            pImageCreateInfo,
                                            reinterpret_cast<const VmaAllocationCreateInfo *>(
                                              pAllocationCreateInfo),
                                            pMemoryTypeIndex);
}

inline VkmaResult vkmaCreatePool(VkmaAllocator allocator, const VkmaPoolCreateInfo *pCreateInfo,
                                 VkmaPool *pPool) {
  return vmaCreatePool(reinterpret_cast<VmaAllocator>(allocator),
                       reinterpret_cast<const VmaPoolCreateInfo *>(pCreateInfo),
                       reinterpret_cast<VmaPool *>(pPool));
}
inline void vkmaDestroyPool(VkmaAllocator allocator, VkmaPool pool) {
  vmaDestroyPool(reinterpret_cast<VmaAllocator>(allocator), reinterpret_cast<VmaPool>(pool));
}
inline void vkmaGetPoolStats(VkmaAllocator allocator, VkmaPool pool, VkmaPoolStats *pPoolStats) {
  vmaGetPoolStats(reinterpret_cast<VmaAllocator>(allocator), reinterpret_cast<VmaPool>(pool),
                  pPoolStats);
}
inline void vkmaMakePoolAllocationsLost(VkmaAllocator allocator, VkmaPool pool,
                                        size_t *pLostAllocationCount) {
  vmaMakePoolAllocationsLost(reinterpret_cast<VmaAllocator>(allocator),
                             reinterpret_cast<VmaPool>(pool), pLostAllocationCount);
}
inline VkmaResult vkmaCheckPoolCorruption(VkmaAllocator allocator, VkmaPool pool) {
  return vmaCheckPoolCorruption(reinterpret_cast<VmaAllocator>(allocator),
                                reinterpret_cast<VmaPool>(pool));
}
inline void vkmaGetPoolName(VkmaAllocator allocator, VkmaPool pool, const char **ppName) {
  vmaGetPoolName(reinterpret_cast<VmaAllocator>(allocator), reinterpret_cast<VmaPool>(pool),
                 ppName);
}
inline void vkmaSetPoolName(VkmaAllocator allocator, VkmaPool pool, const char *pName) {
  vmaSetPoolName(reinterpret_cast<VmaAllocator>(allocator), reinterpret_cast<VmaPool>(pool), pName);
}

inline VkmaResult vkmaAllocateMemory(VkmaAllocator allocator,
                                     const VkMemoryRequirements *pVkMemoryRequirements,
                                     const VkmaAllocationCreateInfo *pCreateInfo,
                                     VkmaAllocation *pAllocation) {
  return vmaAllocateMemory(reinterpret_cast<VmaAllocator>(allocator), pVkMemoryRequirements,
                           reinterpret_cast<const VmaAllocationCreateInfo *>(pCreateInfo),
                           reinterpret_cast<VmaAllocation *>(pAllocation), nullptr);
}
inline VkmaResult vkmaAllocateMemoryPages(VkmaAllocator allocator,
                                          const VkMemoryRequirements *pVkMemoryRequirements,
                                          const VkmaAllocationCreateInfo *pCreateInfo,
                                          size_t allocationCount, VkmaAllocation *pAllocations) {
  return vmaAllocateMemoryPages(reinterpret_cast<VmaAllocator>(allocator), pVkMemoryRequirements,
                                reinterpret_cast<const VmaAllocationCreateInfo *>(pCreateInfo),
                                allocationCount, reinterpret_cast<VmaAllocation *>(pAllocations),
                                nullptr);
}
inline VkmaResult vkmaAllocateMemoryForBuffer(VkmaAllocator allocator, VkBuffer buffer,
                                              const VkmaAllocationCreateInfo *pCreateInfo,
                                              VkmaAllocation *pAllocation) {
  return vmaAllocateMemoryForBuffer(reinterpret_cast<VmaAllocator>(allocator), buffer,
                                    reinterpret_cast<const VmaAllocationCreateInfo *>(pCreateInfo),
                                    reinterpret_cast<VmaAllocation *>(pAllocation), nullptr);
}
inline VkmaResult vkmaAllocateMemoryForImage(VkmaAllocator allocator, VkImage image,
                                             const VkmaAllocationCreateInfo *pCreateInfo,
                                             VkmaAllocation *pAllocation) {
  return vmaAllocateMemoryForImage(reinterpret_cast<VmaAllocator>(allocator), image,
                                   reinterpret_cast<const VmaAllocationCreateInfo *>(pCreateInfo),
                                   reinterpret_cast<VmaAllocation *>(pAllocation), nullptr);
}
inline void vkmaFreeMemory(VkmaAllocator allocator, const VkmaAllocation allocation) {
  vmaFreeMemory(reinterpret_cast<VmaAllocator>(allocator),
                reinterpret_cast<VmaAllocation>(allocation));
}
inline void vkmaFreeMemoryPages(VkmaAllocator allocator, size_t allocationCount,
                                const VkmaAllocation *pAllocations) {
  vmaFreeMemoryPages(reinterpret_cast<VmaAllocator>(allocator), allocationCount,
                     reinterpret_cast<const VmaAllocation *>(pAllocations));
}
inline VkmaResult vkmaResizeAllocation(VkmaAllocator allocator, VkmaAllocation allocation,
                                       VkDeviceSize newSize) {
  return vmaResizeAllocation(reinterpret_cast<VmaAllocator>(allocator),
                             reinterpret_cast<VmaAllocation>(allocation), newSize);
}
inline void vkmaGetAllocationInfo(VkmaAllocator allocator, VkmaAllocation allocation,
                                  VkmaAllocationInfo *pAllocationInfo) {
  vmaGetAllocationInfo(reinterpret_cast<VmaAllocator>(allocator),
                       reinterpret_cast<VmaAllocation>(allocation), pAllocationInfo);
}
inline VkBool32 vkmaTouchAllocation(VkmaAllocator allocator, VkmaAllocation allocation) {
  return vmaTouchAllocation(reinterpret_cast<VmaAllocator>(allocator),
                            reinterpret_cast<VmaAllocation>(allocation));
}
inline void vkmaSetAllocationUserData(VkmaAllocator allocator, VkmaAllocation allocation,
                                      const void *pUserData) {
  vmaSetAllocationUserData(reinterpret_cast<VmaAllocator>(allocator),
                           reinterpret_cast<VmaAllocation>(allocation),
                           const_cast<void *>(pUserData));
}
inline VkmaResult vkmaCreateLostAllocation(VkmaAllocator allocator, VkmaAllocation *pAllocation) {
  vmaCreateLostAllocation(reinterpret_cast<VmaAllocator>(allocator),
                          reinterpret_cast<VmaAllocation *>(pAllocation));
  return VK_SUCCESS;
}
inline VkmaResult vkmaMapMemory(VkmaAllocator allocator, VkmaAllocation allocation, void **ppData) {
  return vmaMapMemory(reinterpret_cast<VmaAllocator>(allocator),
                      reinterpret_cast<VmaAllocation>(allocation), ppData);
}
inline void vkmaUnmapMemory(VkmaAllocator allocator, VkmaAllocation allocation) {
  vmaUnmapMemory(reinterpret_cast<VmaAllocator>(allocator),
                 reinterpret_cast<VmaAllocation>(allocation));
}
inline VkmaResult vkmaFlushAllocation(VkmaAllocator allocator, VkmaAllocation allocation,
                                      VkDeviceSize offset, VkDeviceSize size) {
  return vmaFlushAllocation(reinterpret_cast<VmaAllocator>(allocator),
                            reinterpret_cast<VmaAllocation>(allocation), offset, size);
}
inline VkmaResult vkmaInvalidateAllocation(VkmaAllocator allocator, VkmaAllocation allocation,
                                           VkDeviceSize offset, VkDeviceSize size) {
  return vmaInvalidateAllocation(reinterpret_cast<VmaAllocator>(allocator),
                                 reinterpret_cast<VmaAllocation>(allocation), offset, size);
}

inline VkmaResult vkmaCheckCorruption(VkmaAllocator allocator, uint32_t memoryTypeBits) {
  return vmaCheckCorruption(reinterpret_cast<VmaAllocator>(allocator), memoryTypeBits);
}
inline VkmaResult vkmaBeginDefragmentation(VkmaAllocator allocator,
                                           const VkmaDefragmentationInfo2 *pInfo,
                                           VkmaDefragmentationContext *pContext) {
  return vmaDefragmentationBegin(reinterpret_cast<VmaAllocator>(allocator),
                                 reinterpret_cast<const VmaDefragmentationInfo2 *>(pInfo), nullptr,
                                 reinterpret_cast<VmaDefragmentationContext *>(pContext));
}
inline VkmaResult vkmaEndDefragmentation(VkmaAllocator allocator,
                                         VkmaDefragmentationContext context) {
  return vmaDefragmentationEnd(reinterpret_cast<VmaAllocator>(allocator),
                               reinterpret_cast<VmaDefragmentationContext>(context));
}

inline VkmaResult vkmaBindBufferMemory(VkmaAllocator allocator, VkmaAllocation allocation,
                                       VkBuffer buffer) {
  return vmaBindBufferMemory(reinterpret_cast<VmaAllocator>(allocator),
                             reinterpret_cast<VmaAllocation>(allocation), buffer);
}
inline VkmaResult vkmaBindBufferMemory2(VkmaAllocator allocator, VkmaAllocation allocation,
                                        VkDeviceSize allocationLocalOffset, VkBuffer buffer,
                                        const void *pNext) {
  return vmaBindBufferMemory2(reinterpret_cast<VmaAllocator>(allocator),
                              reinterpret_cast<VmaAllocation>(allocation), allocationLocalOffset,
                              buffer, pNext);
}
inline VkmaResult vkmaBindImageMemory(VkmaAllocator allocator, VkmaAllocation allocation,
                                      VkImage image) {
  return vmaBindImageMemory(reinterpret_cast<VmaAllocator>(allocator),
                            reinterpret_cast<VmaAllocation>(allocation), image);
}
inline VkmaResult vkmaBindImageMemory2(VkmaAllocator allocator, VkmaAllocation allocation,
                                       VkDeviceSize allocationLocalOffset, VkImage image,
                                       const void *pNext) {
  return vmaBindImageMemory2(reinterpret_cast<VmaAllocator>(allocator),
                             reinterpret_cast<VmaAllocation>(allocation), allocationLocalOffset,
                             image, pNext);
}

inline VkmaResult vkmaCreateBuffer(VkmaAllocator allocator,
                                   const VkBufferCreateInfo *pBufferCreateInfo,
                                   const VkmaAllocationCreateInfo *pAllocationCreateInfo,
                                   VkmaBuffer *pBuffer) {
  VKMA_ASSERT(pBuffer);
  *pBuffer = reinterpret_cast<VkmaBuffer>(new VkmaBuffer_T{});
  return vmaCreateBuffer(reinterpret_cast<VmaAllocator>(allocator), pBufferCreateInfo,
                         reinterpret_cast<const VmaAllocationCreateInfo *>(pAllocationCreateInfo),
                         &reinterpret_cast<VkmaBuffer_T *>(*pBuffer)->buffer,
                         reinterpret_cast<VmaAllocation *>(
                           &reinterpret_cast<VkmaBuffer_T *>(*pBuffer)->allocation),
                         nullptr);
}
inline void vkmaDestroyBuffer(VkmaAllocator allocator, VkmaBuffer buffer) {
  VKMA_ASSERT(buffer);
  vmaDestroyBuffer(reinterpret_cast<VmaAllocator>(allocator),
                   reinterpret_cast<VkmaBuffer_T *>(buffer)->buffer,
                   reinterpret_cast<VmaAllocation>(
                     reinterpret_cast<VkmaBuffer_T *>(buffer)->allocation));
  delete reinterpret_cast<VkmaBuffer_T *>(buffer);
}
inline VkmaResult vkmaCreateImage(VkmaAllocator allocator,
                                  const VkImageCreateInfo *pImageCreateInfo,
                                  const VkmaAllocationCreateInfo *pAllocationCreateInfo,
                                  VkmaImage *pImage) {
  VKMA_ASSERT(pImage);
  *pImage = reinterpret_cast<VkmaImage>(new VkmaImage_T{});
  return vmaCreateImage(reinterpret_cast<VmaAllocator>(allocator), pImageCreateInfo,
                        reinterpret_cast<const VmaAllocationCreateInfo *>(pAllocationCreateInfo),
                        &reinterpret_cast<VkmaImage_T *>(*pImage)->image,
                        reinterpret_cast<VmaAllocation *>(
                          &reinterpret_cast<VkmaImage_T *>(*pImage)->allocation),
                        nullptr);
}
inline void vkmaDestroyImage(VkmaAllocator allocator, VkmaImage image) {
  VKMA_ASSERT(image);
  vmaDestroyImage(reinterpret_cast<VmaAllocator>(allocator),
                  reinterpret_cast<VkmaImage_T *>(image)->image,
                  reinterpret_cast<VmaAllocation>(
                    reinterpret_cast<VkmaImage_T *>(image)->allocation));
  delete reinterpret_cast<VkmaImage_T *>(image);
}

inline void vkmaGetBuffer(VkmaBuffer buffer, VkBuffer *pBuffer) {
  VKMA_ASSERT(pBuffer);
  *pBuffer = reinterpret_cast<VkmaBuffer_T *>(buffer)->buffer;
}
inline void vkmaGetBufferAllocation(VkmaBuffer buffer, VkmaAllocation *pAllocation) {
  VKMA_ASSERT(pAllocation);
  *pAllocation = reinterpret_cast<VkmaBuffer_T *>(buffer)->allocation;
}
inline void vkmaGetImage(VkmaImage image, VkImage *pImage) {
  VKMA_ASSERT(pImage);
  *pImage = reinterpret_cast<VkmaImage_T *>(image)->image;
}
inline void vkmaGetImageAllocation(VkmaImage image, VkmaAllocation *pAllocation) {
  VKMA_ASSERT(pAllocation);
  *pAllocation = reinterpret_cast<VkmaImage_T *>(image)->allocation;
}

#endif // VKMA_BINDINGS_HPP

// The end of an external bindings file.

// 32-bit vulkan is not typesafe for handles, so don't allow copy constructors on this platform by
// default. To enable this feature on 32-bit platforms please define VKMA_TYPESAFE_CONVERSION
#if !defined(VKMA_TYPESAFE_CONVERSION)
  #define VKMA_TYPESAFE_CONVERSION
#endif

// <tuple> includes <sys/sysmacros.h> through some other header
// this results in major(x) being resolved to gnu_dev_major(x)
// which is an expression in a constructor initializer list.
#if defined(major)
  #undef major
#endif
#if defined(minor)
  #undef minor
#endif

// Windows defines MemoryBarrier which is deprecated and collides
// with the VKMA_NAMESPACE::MemoryBarrier struct.
#if defined(MemoryBarrier)
  #undef MemoryBarrier
#endif

#if !defined(VKMA_HAS_UNRESTRICTED_UNIONS)
  #if defined(__clang__)
    #if __has_feature(cxx_unrestricted_unions)
      #define VKMA_HAS_UNRESTRICTED_UNIONS
    #endif
  #elif defined(__GNUC__)
    #define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
    #if 40600 <= GCC_VERSION
      #define VKMA_HAS_UNRESTRICTED_UNIONS
    #endif
  #elif defined(_MSC_VER)
    #if 1900 <= _MSC_VER
      #define VKMA_HAS_UNRESTRICTED_UNIONS
    #endif
  #endif
#endif

#if !defined(VKMA_INLINE)
  #if defined(__clang__)
    #if __has_attribute(always_inline)
      #define VKMA_INLINE __attribute__((always_inline)) __inline__
    #else
      #define VKMA_INLINE inline
    #endif
  #elif defined(__GNUC__)
    #define VKMA_INLINE __attribute__((always_inline)) __inline__
  #elif defined(_MSC_VER)
    #define VKMA_INLINE inline
  #else
    #define VKMA_INLINE inline
  #endif
#endif

#if defined(VKMA_TYPESAFE_CONVERSION)
  #define VKMA_TYPESAFE_EXPLICIT
#else
  #define VKMA_TYPESAFE_EXPLICIT explicit
#endif

#if defined(__cpp_constexpr)
  #define VKMA_CONSTEXPR constexpr
  #if __cpp_constexpr >= 201304
    #define VKMA_CONSTEXPR_14 constexpr
  #else
    #define VKMA_CONSTEXPR_14
  #endif
  #define VKMA_CONST_OR_CONSTEXPR constexpr
#else
  #define VKMA_CONSTEXPR
  #define VKMA_CONSTEXPR_14
  #define VKMA_CONST_OR_CONSTEXPR const
#endif

#if !defined(VKMA_NOEXCEPT)
  #if defined(_MSC_VER) && (_MSC_VER <= 1800)
    #define VKMA_NOEXCEPT
  #else
    #define VKMA_NOEXCEPT     noexcept
    #define VKMA_HAS_NOEXCEPT 1
    #if defined(VKMA_NO_EXCEPTIONS)
      #define VKMA_NOEXCEPT_WHEN_NO_EXCEPTIONS noexcept
    #else
      #define VKMA_NOEXCEPT_WHEN_NO_EXCEPTIONS
    #endif
  #endif
#endif

#if 14 <= VKMA_CPP_VERSION
  #define VKMA_DEPRECATED(msg) [[deprecated(msg)]]
#else
  #define VKMA_DEPRECATED(msg)
#endif

#if (17 <= VKMA_CPP_VERSION) && !defined(VKMA_NO_NODISCARD_WARNINGS)
  #define VKMA_NODISCARD [[nodiscard]]
  #if defined(VKMA_NO_EXCEPTIONS)
    #define VKMA_NODISCARD_WHEN_NO_EXCEPTIONS [[nodiscard]]
  #else
    #define VKMA_NODISCARD_WHEN_NO_EXCEPTIONS
  #endif
#else
  #define VKMA_NODISCARD
  #define VKMA_NODISCARD_WHEN_NO_EXCEPTIONS
#endif

#if !defined(VKMA_NAMESPACE)
  #define VKMA_NAMESPACE vkma
#endif

#define VKMA_STRINGIFY2(text) #text
#define VKMA_STRINGIFY(text)  VKMA_STRINGIFY2(text)
#define VKMA_NAMESPACE_STRING VKMA_STRINGIFY(VKMA_NAMESPACE)

namespace VKMA_NAMESPACE {

#if !defined(VKMA_DISABLE_ENHANCED_MODE)
  template <typename T> class ArrayProxy {
  public:
    VKMA_CONSTEXPR ArrayProxy() VKMA_NOEXCEPT : m_count(0), m_ptr(nullptr) {}

    VKMA_CONSTEXPR ArrayProxy(std::nullptr_t) VKMA_NOEXCEPT : m_count(0), m_ptr(nullptr) {}

    ArrayProxy(T &value) VKMA_NOEXCEPT : m_count(1), m_ptr(&value) {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy(typename std::remove_const<T>::type &value) VKMA_NOEXCEPT : m_count(1),
                                                                           m_ptr(&value) {}

    ArrayProxy(uint32_t count, T *ptr) VKMA_NOEXCEPT : m_count(count), m_ptr(ptr) {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy(uint32_t count, typename std::remove_const<T>::type *ptr) VKMA_NOEXCEPT
      : m_count(count),
        m_ptr(ptr) {}

  #if __GNUC__ >= 9
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Winit-list-lifetime"
  #endif

    ArrayProxy(std::initializer_list<T> const &list) VKMA_NOEXCEPT
      : m_count(static_cast<uint32_t>(list.size())),
        m_ptr(list.begin()) {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy(std::initializer_list<typename std::remove_const<T>::type> const &list) VKMA_NOEXCEPT
      : m_count(static_cast<uint32_t>(list.size())),
        m_ptr(list.begin()) {}

    ArrayProxy(std::initializer_list<T> &list) VKMA_NOEXCEPT
      : m_count(static_cast<uint32_t>(list.size())),
        m_ptr(list.begin()) {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy(std::initializer_list<typename std::remove_const<T>::type> &list) VKMA_NOEXCEPT
      : m_count(static_cast<uint32_t>(list.size())),
        m_ptr(list.begin()) {}

  #if __GNUC__ >= 9
    #pragma GCC diagnostic pop
  #endif

    template <size_t N>
    ArrayProxy(std::array<T, N> const &data) VKMA_NOEXCEPT : m_count(N), m_ptr(data.data()) {}

    template <size_t N, typename B = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy(std::array<typename std::remove_const<T>::type, N> const &data) VKMA_NOEXCEPT
      : m_count(N),
        m_ptr(data.data()) {}

    template <size_t N>
    ArrayProxy(std::array<T, N> &data) VKMA_NOEXCEPT : m_count(N), m_ptr(data.data()) {}

    template <size_t N, typename B = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy(std::array<typename std::remove_const<T>::type, N> &data) VKMA_NOEXCEPT
      : m_count(N),
        m_ptr(data.data()) {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxy(std::vector<T, Allocator> const &data) VKMA_NOEXCEPT
      : m_count(static_cast<uint32_t>(data.size())),
        m_ptr(data.data()) {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>, typename B = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy(std::vector<typename std::remove_const<T>::type, Allocator> const &data)
      VKMA_NOEXCEPT : m_count(static_cast<uint32_t>(data.size())),
                      m_ptr(data.data()) {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxy(std::vector<T, Allocator> &data) VKMA_NOEXCEPT
      : m_count(static_cast<uint32_t>(data.size())),
        m_ptr(data.data()) {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>, typename B = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy(std::vector<typename std::remove_const<T>::type, Allocator> &data) VKMA_NOEXCEPT
      : m_count(static_cast<uint32_t>(data.size())),
        m_ptr(data.data()) {}

    const T *begin() const VKMA_NOEXCEPT { return m_ptr; }

    const T *end() const VKMA_NOEXCEPT { return m_ptr + m_count; }

    const T &front() const VKMA_NOEXCEPT {
      VKMA_ASSERT(m_count && m_ptr);
      return *m_ptr;
    }

    const T &back() const VKMA_NOEXCEPT {
      VKMA_ASSERT(m_count && m_ptr);
      return *(m_ptr + m_count - 1);
    }

    bool empty() const VKMA_NOEXCEPT { return (m_count == 0); }

    uint32_t size() const VKMA_NOEXCEPT { return m_count; }

    T *data() const VKMA_NOEXCEPT { return m_ptr; }

  private:
    uint32_t m_count;
    T *m_ptr;
  };

  template <typename T> class ArrayProxyNoTemporaries {
  public:
    VKMA_CONSTEXPR ArrayProxyNoTemporaries() VKMA_NOEXCEPT : m_count(0), m_ptr(nullptr) {}

    VKMA_CONSTEXPR ArrayProxyNoTemporaries(std::nullptr_t) VKMA_NOEXCEPT : m_count(0),
                                                                           m_ptr(nullptr) {}

    ArrayProxyNoTemporaries(T &value) VKMA_NOEXCEPT : m_count(1), m_ptr(&value) {}

    ArrayProxyNoTemporaries(T &&value) = delete;

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(typename std::remove_const<T>::type &value) VKMA_NOEXCEPT
      : m_count(1),
        m_ptr(&value) {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(typename std::remove_const<T>::type &&value) = delete;

    ArrayProxyNoTemporaries(uint32_t count, T *ptr) VKMA_NOEXCEPT : m_count(count), m_ptr(ptr) {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(uint32_t count, typename std::remove_const<T>::type *ptr) VKMA_NOEXCEPT
      : m_count(count),
        m_ptr(ptr) {}

    ArrayProxyNoTemporaries(std::initializer_list<T> const &list) VKMA_NOEXCEPT
      : m_count(static_cast<uint32_t>(list.size())),
        m_ptr(list.begin()) {}

    ArrayProxyNoTemporaries(std::initializer_list<T> const &&list) = delete;

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(std::initializer_list<typename std::remove_const<T>::type> const &list)
      VKMA_NOEXCEPT : m_count(static_cast<uint32_t>(list.size())),
                      m_ptr(list.begin()) {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(std::initializer_list<typename std::remove_const<T>::type> const &&list)
      = delete;

    ArrayProxyNoTemporaries(std::initializer_list<T> &list) VKMA_NOEXCEPT
      : m_count(static_cast<uint32_t>(list.size())),
        m_ptr(list.begin()) {}

    ArrayProxyNoTemporaries(std::initializer_list<T> &&list) = delete;

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(std::initializer_list<typename std::remove_const<T>::type> &list)
      VKMA_NOEXCEPT : m_count(static_cast<uint32_t>(list.size())),
                      m_ptr(list.begin()) {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(std::initializer_list<typename std::remove_const<T>::type> &&list)
      = delete;

    template <size_t N>
    ArrayProxyNoTemporaries(std::array<T, N> const &data) VKMA_NOEXCEPT : m_count(N),
                                                                          m_ptr(data.data()) {}

    template <size_t N> ArrayProxyNoTemporaries(std::array<T, N> const &&data) = delete;

    template <size_t N, typename B = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(std::array<typename std::remove_const<T>::type, N> const &data)
      VKMA_NOEXCEPT : m_count(N),
                      m_ptr(data.data()) {}

    template <size_t N, typename B = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(std::array<typename std::remove_const<T>::type, N> const &&data)
      = delete;

    template <size_t N>
    ArrayProxyNoTemporaries(std::array<T, N> &data) VKMA_NOEXCEPT : m_count(N),
                                                                    m_ptr(data.data()) {}

    template <size_t N> ArrayProxyNoTemporaries(std::array<T, N> &&data) = delete;

    template <size_t N, typename B = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(std::array<typename std::remove_const<T>::type, N> &data) VKMA_NOEXCEPT
      : m_count(N),
        m_ptr(data.data()) {}

    template <size_t N, typename B = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(std::array<typename std::remove_const<T>::type, N> &&data) = delete;

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxyNoTemporaries(std::vector<T, Allocator> const &data) VKMA_NOEXCEPT
      : m_count(static_cast<uint32_t>(data.size())),
        m_ptr(data.data()) {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxyNoTemporaries(std::vector<T, Allocator> const &&data) = delete;

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>, typename B = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(std::vector<typename std::remove_const<T>::type, Allocator> const &data)
      VKMA_NOEXCEPT : m_count(static_cast<uint32_t>(data.size())),
                      m_ptr(data.data()) {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>, typename B = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(
      std::vector<typename std::remove_const<T>::type, Allocator> const &&data)
      = delete;

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxyNoTemporaries(std::vector<T, Allocator> &data) VKMA_NOEXCEPT
      : m_count(static_cast<uint32_t>(data.size())),
        m_ptr(data.data()) {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxyNoTemporaries(std::vector<T, Allocator> &&data) = delete;

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>, typename B = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(std::vector<typename std::remove_const<T>::type, Allocator> &data)
      VKMA_NOEXCEPT : m_count(static_cast<uint32_t>(data.size())),
                      m_ptr(data.data()) {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>, typename B = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries(std::vector<typename std::remove_const<T>::type, Allocator> &&data)
      = delete;

    const T *begin() const VKMA_NOEXCEPT { return m_ptr; }

    const T *end() const VKMA_NOEXCEPT { return m_ptr + m_count; }

    const T &front() const VKMA_NOEXCEPT {
      VKMA_ASSERT(m_count && m_ptr);
      return *m_ptr;
    }

    const T &back() const VKMA_NOEXCEPT {
      VKMA_ASSERT(m_count && m_ptr);
      return *(m_ptr + m_count - 1);
    }

    bool empty() const VKMA_NOEXCEPT { return (m_count == 0); }

    uint32_t size() const VKMA_NOEXCEPT { return m_count; }

    T *data() const VKMA_NOEXCEPT { return m_ptr; }

  private:
    uint32_t m_count;
    T *m_ptr;
  };
#endif

  template <typename T, size_t N> class ArrayWrapper1D : public std::array<T, N> {
  public:
    VKMA_CONSTEXPR ArrayWrapper1D() VKMA_NOEXCEPT : std::array<T, N>() {}

    VKMA_CONSTEXPR ArrayWrapper1D(std::array<T, N> const &data) VKMA_NOEXCEPT
      : std::array<T, N>(data) {}

#if defined(_WIN32) && !defined(_WIN64)
    VKMA_CONSTEXPR T const &operator[](int index) const VKMA_NOEXCEPT {
      return std::array<T, N>::operator[](index);
    }

    T &operator[](int index) VKMA_NOEXCEPT { return std::array<T, N>::operator[](index); }
#endif

    operator T const *() const VKMA_NOEXCEPT { return this->data(); }

    operator T *() VKMA_NOEXCEPT { return this->data(); }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    operator std::string() const {
      return std::string(this->data());
    }

#if 17 <= VKMA_CPP_VERSION
    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    operator std::string_view() const {
      return std::string_view(this->data());
    }
#endif

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator<(ArrayWrapper1D<char, N> const &rhs) const VKMA_NOEXCEPT {
      return *static_cast<std::array<char, N> const *>(this)
           < *static_cast<std::array<char, N> const *>(&rhs);
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator<=(ArrayWrapper1D<char, N> const &rhs) const VKMA_NOEXCEPT {
      return *static_cast<std::array<char, N> const *>(this)
          <= *static_cast<std::array<char, N> const *>(&rhs);
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator>(ArrayWrapper1D<char, N> const &rhs) const VKMA_NOEXCEPT {
      return *static_cast<std::array<char, N> const *>(this)
           > *static_cast<std::array<char, N> const *>(&rhs);
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator>=(ArrayWrapper1D<char, N> const &rhs) const VKMA_NOEXCEPT {
      return *static_cast<std::array<char, N> const *>(this)
          >= *static_cast<std::array<char, N> const *>(&rhs);
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator==(ArrayWrapper1D<char, N> const &rhs) const VKMA_NOEXCEPT {
      return *static_cast<std::array<char, N> const *>(this)
          == *static_cast<std::array<char, N> const *>(&rhs);
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator!=(ArrayWrapper1D<char, N> const &rhs) const VKMA_NOEXCEPT {
      return *static_cast<std::array<char, N> const *>(this)
          != *static_cast<std::array<char, N> const *>(&rhs);
    }
  };

  // specialization of relational operators between std::string and arrays of chars
  template <size_t N>
  bool operator<(std::string const &lhs, ArrayWrapper1D<char, N> const &rhs) VKMA_NOEXCEPT {
    return lhs < rhs.data();
  }

  template <size_t N>
  bool operator<=(std::string const &lhs, ArrayWrapper1D<char, N> const &rhs) VKMA_NOEXCEPT {
    return lhs <= rhs.data();
  }

  template <size_t N>
  bool operator>(std::string const &lhs, ArrayWrapper1D<char, N> const &rhs) VKMA_NOEXCEPT {
    return lhs > rhs.data();
  }

  template <size_t N>
  bool operator>=(std::string const &lhs, ArrayWrapper1D<char, N> const &rhs) VKMA_NOEXCEPT {
    return lhs >= rhs.data();
  }

  template <size_t N>
  bool operator==(std::string const &lhs, ArrayWrapper1D<char, N> const &rhs) VKMA_NOEXCEPT {
    return lhs == rhs.data();
  }

  template <size_t N>
  bool operator!=(std::string const &lhs, ArrayWrapper1D<char, N> const &rhs) VKMA_NOEXCEPT {
    return lhs != rhs.data();
  }

  template <typename T, size_t N, size_t M>
  class ArrayWrapper2D : public std::array<ArrayWrapper1D<T, M>, N> {
  public:
    VKMA_CONSTEXPR ArrayWrapper2D() VKMA_NOEXCEPT : std::array<ArrayWrapper1D<T, M>, N>() {}

    VKMA_CONSTEXPR ArrayWrapper2D(std::array<std::array<T, M>, N> const &data) VKMA_NOEXCEPT
      : std::array<ArrayWrapper1D<T, M>, N>(
          *reinterpret_cast<std::array<ArrayWrapper1D<T, M>, N> const *>(&data)) {}
  };

  template <typename FlagBitsType> struct FlagTraits {
    enum { allFlags = 0 };
  };

  template <typename BitType> class Flags {
  public:
    using MaskType = typename std::underlying_type<BitType>::type;

    // constructors
    VKMA_CONSTEXPR Flags() VKMA_NOEXCEPT : m_mask(0) {}

    VKMA_CONSTEXPR Flags(BitType bit) VKMA_NOEXCEPT : m_mask(static_cast<MaskType>(bit)) {}

    VKMA_CONSTEXPR Flags(Flags<BitType> const &rhs) VKMA_NOEXCEPT = default;

    VKMA_CONSTEXPR explicit Flags(MaskType flags) VKMA_NOEXCEPT : m_mask(flags) {}

    // relational operators
#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(Flags<BitType> const &) const = default;
#else
    VKMA_CONSTEXPR bool operator<(Flags<BitType> const &rhs) const VKMA_NOEXCEPT {
      return m_mask < rhs.m_mask;
    }

    VKMA_CONSTEXPR bool operator<=(Flags<BitType> const &rhs) const VKMA_NOEXCEPT {
      return m_mask <= rhs.m_mask;
    }

    VKMA_CONSTEXPR bool operator>(Flags<BitType> const &rhs) const VKMA_NOEXCEPT {
      return m_mask > rhs.m_mask;
    }

    VKMA_CONSTEXPR bool operator>=(Flags<BitType> const &rhs) const VKMA_NOEXCEPT {
      return m_mask >= rhs.m_mask;
    }

    VKMA_CONSTEXPR bool operator==(Flags<BitType> const &rhs) const VKMA_NOEXCEPT {
      return m_mask == rhs.m_mask;
    }

    VKMA_CONSTEXPR bool operator!=(Flags<BitType> const &rhs) const VKMA_NOEXCEPT {
      return m_mask != rhs.m_mask;
    }
#endif

    // logical operator
    VKMA_CONSTEXPR bool operator!() const VKMA_NOEXCEPT { return !m_mask; }

    // bitwise operators
    VKMA_CONSTEXPR Flags<BitType> operator&(Flags<BitType> const &rhs) const VKMA_NOEXCEPT {
      return Flags<BitType>(m_mask & rhs.m_mask);
    }

    VKMA_CONSTEXPR Flags<BitType> operator|(Flags<BitType> const &rhs) const VKMA_NOEXCEPT {
      return Flags<BitType>(m_mask | rhs.m_mask);
    }

    VKMA_CONSTEXPR Flags<BitType> operator^(Flags<BitType> const &rhs) const VKMA_NOEXCEPT {
      return Flags<BitType>(m_mask ^ rhs.m_mask);
    }

    VKMA_CONSTEXPR Flags<BitType> operator~() const VKMA_NOEXCEPT {
      return Flags<BitType>(m_mask ^ FlagTraits<BitType>::allFlags);
    }

    // assignment operators
    VKMA_CONSTEXPR_14 Flags<BitType> &operator=(Flags<BitType> const &rhs) VKMA_NOEXCEPT = default;

    VKMA_CONSTEXPR_14 Flags<BitType> &operator|=(Flags<BitType> const &rhs) VKMA_NOEXCEPT {
      m_mask |= rhs.m_mask;
      return *this;
    }

    VKMA_CONSTEXPR_14 Flags<BitType> &operator&=(Flags<BitType> const &rhs) VKMA_NOEXCEPT {
      m_mask &= rhs.m_mask;
      return *this;
    }

    VKMA_CONSTEXPR_14 Flags<BitType> &operator^=(Flags<BitType> const &rhs) VKMA_NOEXCEPT {
      m_mask ^= rhs.m_mask;
      return *this;
    }

    // cast operators
    explicit VKMA_CONSTEXPR operator bool() const VKMA_NOEXCEPT { return !!m_mask; }

    explicit VKMA_CONSTEXPR operator MaskType() const VKMA_NOEXCEPT { return m_mask; }

#if defined(VKMA_FLAGS_MASK_TYPE_AS_PUBLIC)
  public:
#else
  private:
#endif
    MaskType m_mask;
  };

#if !defined(VKMA_HAS_SPACESHIP_OPERATOR)
  // relational operators only needed for pre C++20
  template <typename BitType>
  VKMA_CONSTEXPR bool operator<(BitType bit, Flags<BitType> const &flags) VKMA_NOEXCEPT {
    return flags.operator>(bit);
  }

  template <typename BitType>
  VKMA_CONSTEXPR bool operator<=(BitType bit, Flags<BitType> const &flags) VKMA_NOEXCEPT {
    return flags.operator>=(bit);
  }

  template <typename BitType>
  VKMA_CONSTEXPR bool operator>(BitType bit, Flags<BitType> const &flags) VKMA_NOEXCEPT {
    return flags.operator<(bit);
  }

  template <typename BitType>
  VKMA_CONSTEXPR bool operator>=(BitType bit, Flags<BitType> const &flags) VKMA_NOEXCEPT {
    return flags.operator<=(bit);
  }

  template <typename BitType>
  VKMA_CONSTEXPR bool operator==(BitType bit, Flags<BitType> const &flags) VKMA_NOEXCEPT {
    return flags.operator==(bit);
  }

  template <typename BitType>
  VKMA_CONSTEXPR bool operator!=(BitType bit, Flags<BitType> const &flags) VKMA_NOEXCEPT {
    return flags.operator!=(bit);
  }
#endif

  // bitwise operators
  template <typename BitType>
  VKMA_CONSTEXPR Flags<BitType> operator&(BitType bit, Flags<BitType> const &flags) VKMA_NOEXCEPT {
    return flags.operator&(bit);
  }

  template <typename BitType>
  VKMA_CONSTEXPR Flags<BitType> operator|(BitType bit, Flags<BitType> const &flags) VKMA_NOEXCEPT {
    return flags.operator|(bit);
  }

  template <typename BitType>
  VKMA_CONSTEXPR Flags<BitType> operator^(BitType bit, Flags<BitType> const &flags) VKMA_NOEXCEPT {
    return flags.operator^(bit);
  }

  template <typename RefType> class Optional {
  public:
    Optional(RefType &reference) VKMA_NOEXCEPT { m_ptr = &reference; }
    Optional(RefType *ptr) VKMA_NOEXCEPT { m_ptr = ptr; }
    Optional(std::nullptr_t) VKMA_NOEXCEPT { m_ptr = nullptr; }

    operator RefType *() const VKMA_NOEXCEPT { return m_ptr; }
    RefType const *operator->() const VKMA_NOEXCEPT { return m_ptr; }
    explicit operator bool() const VKMA_NOEXCEPT { return !!m_ptr; }

  private:
    RefType *m_ptr;
  };

#if !defined(VKMA_NO_SMART_HANDLE)
  template <typename Type> class UniqueHandleTraits;

  template <typename Type> class UniqueHandle : public UniqueHandleTraits<Type>::deleter {
  private:
    using Deleter = typename UniqueHandleTraits<Type>::deleter;

  public:
    using element_type = Type;

    UniqueHandle() : Deleter(), m_value() {}

    explicit UniqueHandle(Type const &value, Deleter const &deleter = Deleter()) VKMA_NOEXCEPT
      : Deleter(deleter),
        m_value(value) {}

    UniqueHandle(UniqueHandle const &) = delete;

    UniqueHandle(UniqueHandle &&other) VKMA_NOEXCEPT
      : Deleter(std::move(static_cast<Deleter &>(other))),
        m_value(other.release()) {}

    ~UniqueHandle() VKMA_NOEXCEPT {
      if (m_value)
        this->destroy(m_value);
    }

    UniqueHandle &operator=(UniqueHandle const &) = delete;

    UniqueHandle &operator=(UniqueHandle &&other) VKMA_NOEXCEPT {
      reset(other.release());
      *static_cast<Deleter *>(this) = std::move(static_cast<Deleter &>(other));
      return *this;
    }

    explicit operator bool() const VKMA_NOEXCEPT { return m_value.operator bool(); }

    Type const *operator->() const VKMA_NOEXCEPT { return &m_value; }

    Type *operator->() VKMA_NOEXCEPT { return &m_value; }

    Type const &operator*() const VKMA_NOEXCEPT { return m_value; }

    Type &operator*() VKMA_NOEXCEPT { return m_value; }

    const Type &get() const VKMA_NOEXCEPT { return m_value; }

    Type &get() VKMA_NOEXCEPT { return m_value; }

    void reset(Type const &value = Type()) VKMA_NOEXCEPT {
      if (m_value != value) {
        if (m_value)
          this->destroy(m_value);
        m_value = value;
      }
    }

    Type release() VKMA_NOEXCEPT {
      Type value = m_value;
      m_value = nullptr;
      return value;
    }

    void swap(UniqueHandle<Type> &rhs) VKMA_NOEXCEPT {
      std::swap(m_value, rhs.m_value);
      std::swap(static_cast<Deleter &>(*this), static_cast<Deleter &>(rhs));
    }

  private:
    Type m_value;
  };

  template <typename UniqueType>
  VKMA_INLINE std::vector<typename UniqueType::element_type>
  uniqueToRaw(std::vector<UniqueType> const &handles) {
    std::vector<typename UniqueType::element_type> newBuffer(handles.size());
    std::transform(handles.begin(), handles.end(), newBuffer.begin(),
                   [](UniqueType const &handle) { return handle.get(); });
    return newBuffer;
  }

  template <typename Type>
  VKMA_INLINE void swap(UniqueHandle<Type> &lhs, UniqueHandle<Type> &rhs) VKMA_NOEXCEPT {
    lhs.swap(rhs);
  }
#endif
#define VKMA_DEFAULT_ARGUMENT_ASSIGNMENT         = {}
#define VKMA_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT = nullptr

  template <typename OwnerType> class ObjectDestroy {
  public:
    ObjectDestroy() = default;

    ObjectDestroy(OwnerType owner) VKMA_NOEXCEPT : m_owner(owner) {}

    OwnerType getOwner() const VKMA_NOEXCEPT { return m_owner; }

  protected:
    template <typename T> void destroy(T t) VKMA_NOEXCEPT {
      VKMA_ASSERT(m_owner);
      m_owner.destroy(t);
    }

  private:
    OwnerType m_owner = {};
  };

  class NoParent;

  template <> class ObjectDestroy<NoParent> {
  public:
    ObjectDestroy() = default;

  protected:
    template <typename T> void destroy(T t) VKMA_NOEXCEPT { t.destroy(); }

  private:
  };

  template <typename OwnerType> class ObjectFree {
  public:
    ObjectFree() = default;

    ObjectFree(OwnerType owner) VKMA_NOEXCEPT : m_owner(owner) {}

    OwnerType getOwner() const VKMA_NOEXCEPT { return m_owner; }

  protected:
    template <typename T> void destroy(T t) VKMA_NOEXCEPT {
      VKMA_ASSERT(m_owner);
      m_owner.free(t);
    }

  private:
    OwnerType m_owner = {};
  };

  template <typename OwnerType> class ObjectEnd {
  public:
    ObjectEnd() = default;

    ObjectEnd(OwnerType owner) VKMA_NOEXCEPT : m_owner(owner) {}

    OwnerType getOwner() const VKMA_NOEXCEPT { return m_owner; }

  protected:
    template <typename T> void destroy(T t) VKMA_NOEXCEPT {
      VKMA_ASSERT(m_owner);
      m_owner.end(t);
    }

  private:
    OwnerType m_owner = {};
  };

  template <typename OwnerType> class ObjectRelease {
  public:
    ObjectRelease() = default;

    ObjectRelease(OwnerType owner) VKMA_NOEXCEPT : m_owner(owner) {}

    OwnerType getOwner() const VKMA_NOEXCEPT { return m_owner; }

  protected:
    template <typename T> void destroy(T t) VKMA_NOEXCEPT {
      VKMA_ASSERT(m_owner);
      m_owner.release(t);
    }

  private:
    OwnerType m_owner = {};
  };

  template <typename OwnerType, typename PoolType> class PoolFree {
  public:
    PoolFree() = default;

    PoolFree(OwnerType owner, PoolType pool) VKMA_NOEXCEPT : m_owner(owner), m_pool(pool) {}

    OwnerType getOwner() const VKMA_NOEXCEPT { return m_owner; }
    PoolType getPool() const VKMA_NOEXCEPT { return m_pool; }

  protected:
    template <typename T> void destroy(T t) VKMA_NOEXCEPT { m_owner.free(m_pool, t); }

  private:
    OwnerType m_owner = OwnerType();
    PoolType m_pool = PoolType();
  };

  using VkBool32 = uint32_t;
  using VkDeviceSize = uint64_t;
  using VkMemoryPropertyFlags = VkFlags;

  template <typename EnumType, EnumType value> struct CppType {};

  template <typename Type> struct isVulkanHandleType {
    static VKMA_CONST_OR_CONSTEXPR bool value = false;
  };

  VKMA_INLINE std::string toHexString(uint32_t value) {
    std::stringstream stream;
    stream << std::hex << value;
    return stream.str();
  }

  enum class AllocationCreateFlagBits : VkmaAllocationCreateFlags {
    eDedicatedMemory = VMA_ALLOCATION_CREATE_DEDICATED_MEMORY_BIT,
    eNeverAllocate = VMA_ALLOCATION_CREATE_NEVER_ALLOCATE_BIT,
    eMapped = VMA_ALLOCATION_CREATE_MAPPED_BIT,
    eUserDataCopyString = VMA_ALLOCATION_CREATE_USER_DATA_COPY_STRING_BIT,
    eUpperAddress = VMA_ALLOCATION_CREATE_UPPER_ADDRESS_BIT,
    eDontBind = VMA_ALLOCATION_CREATE_DONT_BIND_BIT,
    eWithinBudget = VMA_ALLOCATION_CREATE_WITHIN_BUDGET_BIT,
    eCanAlias = VMA_ALLOCATION_CREATE_CAN_ALIAS_BIT,
    eHostAccessSequentialWrite = VMA_ALLOCATION_CREATE_HOST_ACCESS_SEQUENTIAL_WRITE_BIT,
    eHostAccessRandom = VMA_ALLOCATION_CREATE_HOST_ACCESS_RANDOM_BIT,
    eHostAccessAllowTransferInstead = VMA_ALLOCATION_CREATE_HOST_ACCESS_ALLOW_TRANSFER_INSTEAD_BIT,
    eStrategyMinMemory = VMA_ALLOCATION_CREATE_STRATEGY_MIN_MEMORY_BIT,
    eStrategyMinTime = VMA_ALLOCATION_CREATE_STRATEGY_MIN_TIME_BIT,
    eStrategyMinOffset = VMA_ALLOCATION_CREATE_STRATEGY_MIN_OFFSET_BIT,
    eStrategyMask = VMA_ALLOCATION_CREATE_STRATEGY_MASK,
    eStrategyBestFit = VMA_ALLOCATION_CREATE_STRATEGY_BEST_FIT_BIT,
    eStrategyFirstFit = VMA_ALLOCATION_CREATE_STRATEGY_FIRST_FIT_BIT
  };

  VKMA_INLINE std::string to_string(AllocationCreateFlagBits value) {
    switch (value) {
    case AllocationCreateFlagBits::eDedicatedMemory: return "DedicatedMemory";
    case AllocationCreateFlagBits::eNeverAllocate: return "NeverAllocate";
    case AllocationCreateFlagBits::eMapped: return "Mapped";
    case AllocationCreateFlagBits::eUserDataCopyString: return "UserDataCopyString";
    case AllocationCreateFlagBits::eUpperAddress: return "UpperAddress";
    case AllocationCreateFlagBits::eDontBind: return "DontBind";
    case AllocationCreateFlagBits::eWithinBudget: return "WithinBudget";
    case AllocationCreateFlagBits::eCanAlias: return "CanAlias";
    case AllocationCreateFlagBits::eHostAccessSequentialWrite: return "HostAccessSequentialWrite";
    case AllocationCreateFlagBits::eHostAccessRandom: return "HostAccessRandom";
    case AllocationCreateFlagBits::eHostAccessAllowTransferInstead:
      return "HostAccessAllowTransferInstead";
    case AllocationCreateFlagBits::eStrategyMinMemory: return "StrategyMinMemory";
    case AllocationCreateFlagBits::eStrategyMinTime: return "StrategyMinTime";
    case AllocationCreateFlagBits::eStrategyMinOffset: return "StrategyMinOffset";
    case AllocationCreateFlagBits::eStrategyMask: return "StrategyMask";
    default: return "invalid ( " + VKMA_NAMESPACE::toHexString(static_cast<uint32_t>(value)) + " )";
    }
  }

  enum class AllocatorCreateFlagBits : VkmaAllocatorCreateFlags {
    eExternallySynchronized = VMA_ALLOCATOR_CREATE_EXTERNALLY_SYNCHRONIZED_BIT,
    eKhrDedicatedAllocation = VMA_ALLOCATOR_CREATE_KHR_DEDICATED_ALLOCATION_BIT,
    eKhrBindMemory2 = VMA_ALLOCATOR_CREATE_KHR_BIND_MEMORY2_BIT,
    eExtMemoryBudget = VMA_ALLOCATOR_CREATE_EXT_MEMORY_BUDGET_BIT,
    eAmdDeviceCoherentMemory = VMA_ALLOCATOR_CREATE_AMD_DEVICE_COHERENT_MEMORY_BIT,
    eBufferDeviceAddress = VMA_ALLOCATOR_CREATE_BUFFER_DEVICE_ADDRESS_BIT,
    eExtMemoryPriority = VMA_ALLOCATOR_CREATE_EXT_MEMORY_PRIORITY_BIT
  };

  VKMA_INLINE std::string to_string(AllocatorCreateFlagBits value) {
    switch (value) {
    case AllocatorCreateFlagBits::eExternallySynchronized: return "ExternallySynchronized";
    case AllocatorCreateFlagBits::eKhrDedicatedAllocation: return "KhrDedicatedAllocation";
    case AllocatorCreateFlagBits::eKhrBindMemory2: return "KhrBindMemory2";
    case AllocatorCreateFlagBits::eExtMemoryBudget: return "ExtMemoryBudget";
    case AllocatorCreateFlagBits::eAmdDeviceCoherentMemory: return "AmdDeviceCoherentMemory";
    case AllocatorCreateFlagBits::eBufferDeviceAddress: return "BufferDeviceAddress";
    case AllocatorCreateFlagBits::eExtMemoryPriority: return "ExtMemoryPriority";
    default: return "invalid ( " + VKMA_NAMESPACE::toHexString(static_cast<uint32_t>(value)) + " )";
    }
  }

  enum class DefragmentationFlagBits : VkmaDefragmentationFlags {
    eFlagAlgorithmFast = VMA_DEFRAGMENTATION_FLAG_ALGORITHM_FAST_BIT,
    eFlagAlgorithmBalanced = VMA_DEFRAGMENTATION_FLAG_ALGORITHM_BALANCED_BIT,
    eFlagAlgorithmFull = VMA_DEFRAGMENTATION_FLAG_ALGORITHM_FULL_BIT,
    eFlagAlgorithmExtensive = VMA_DEFRAGMENTATION_FLAG_ALGORITHM_EXTENSIVE_BIT,
    eFlagAlgorithmMask = VMA_DEFRAGMENTATION_FLAG_ALGORITHM_MASK
  };

  VKMA_INLINE std::string to_string(DefragmentationFlagBits value) {
    switch (value) {
    case DefragmentationFlagBits::eFlagAlgorithmFast: return "FlagAlgorithmFast";
    case DefragmentationFlagBits::eFlagAlgorithmBalanced: return "FlagAlgorithmBalanced";
    case DefragmentationFlagBits::eFlagAlgorithmFull: return "FlagAlgorithmFull";
    case DefragmentationFlagBits::eFlagAlgorithmExtensive: return "FlagAlgorithmExtensive";
    case DefragmentationFlagBits::eFlagAlgorithmMask: return "FlagAlgorithmMask";
    default: return "invalid ( " + VKMA_NAMESPACE::toHexString(static_cast<uint32_t>(value)) + " )";
    }
  }

  enum class DefragmentationMoveOperation {
    eCopy = VMA_DEFRAGMENTATION_MOVE_OPERATION_COPY,
    eIgnore = VMA_DEFRAGMENTATION_MOVE_OPERATION_IGNORE,
    eDestroy = VMA_DEFRAGMENTATION_MOVE_OPERATION_DESTROY
  };

  VKMA_INLINE std::string to_string(DefragmentationMoveOperation value) {
    switch (value) {
    case DefragmentationMoveOperation::eCopy: return "Copy";
    case DefragmentationMoveOperation::eIgnore: return "Ignore";
    case DefragmentationMoveOperation::eDestroy: return "Destroy";
    default: return "invalid ( " + VKMA_NAMESPACE::toHexString(static_cast<uint32_t>(value)) + " )";
    }
  }

  enum class MemoryUsage {
    eUnknown = VMA_MEMORY_USAGE_UNKNOWN,
    eGpuOnly = VMA_MEMORY_USAGE_GPU_ONLY,
    eCpuOnly = VMA_MEMORY_USAGE_CPU_ONLY,
    eCpuToGpu = VMA_MEMORY_USAGE_CPU_TO_GPU,
    eGpuToCpu = VMA_MEMORY_USAGE_GPU_TO_CPU,
    eCpuCopy = VMA_MEMORY_USAGE_CPU_COPY,
    eGpuLazilyAllocated = VMA_MEMORY_USAGE_GPU_LAZILY_ALLOCATED,
    eAuto = VMA_MEMORY_USAGE_AUTO,
    eAutoPreferDevice = VMA_MEMORY_USAGE_AUTO_PREFER_DEVICE,
    eAutoPreferHost = VMA_MEMORY_USAGE_AUTO_PREFER_HOST
  };

  VKMA_INLINE std::string to_string(MemoryUsage value) {
    switch (value) {
    case MemoryUsage::eUnknown: return "Unknown";
    case MemoryUsage::eGpuOnly: return "GpuOnly";
    case MemoryUsage::eCpuOnly: return "CpuOnly";
    case MemoryUsage::eCpuToGpu: return "CpuToGpu";
    case MemoryUsage::eGpuToCpu: return "GpuToCpu";
    case MemoryUsage::eCpuCopy: return "CpuCopy";
    case MemoryUsage::eGpuLazilyAllocated: return "GpuLazilyAllocated";
    case MemoryUsage::eAuto: return "Auto";
    case MemoryUsage::eAutoPreferDevice: return "AutoPreferDevice";
    case MemoryUsage::eAutoPreferHost: return "AutoPreferHost";
    default: return "invalid ( " + VKMA_NAMESPACE::toHexString(static_cast<uint32_t>(value)) + " )";
    }
  }

  enum class PoolCreateFlagBits : VkmaPoolCreateFlags {
    eIgnoreBufferImageGranularity = VMA_POOL_CREATE_IGNORE_BUFFER_IMAGE_GRANULARITY_BIT,
    eLinearAlgorithm = VMA_POOL_CREATE_LINEAR_ALGORITHM_BIT,
    eAlgorithmMask = VMA_POOL_CREATE_ALGORITHM_MASK
  };

  VKMA_INLINE std::string to_string(PoolCreateFlagBits value) {
    switch (value) {
    case PoolCreateFlagBits::eIgnoreBufferImageGranularity: return "IgnoreBufferImageGranularity";
    case PoolCreateFlagBits::eLinearAlgorithm: return "LinearAlgorithm";
    default: return "invalid ( " + VKMA_NAMESPACE::toHexString(static_cast<uint32_t>(value)) + " )";
    }
  }

  enum class Result {
    eSuccess = VK_SUCCESS,
    eNotReady = VK_NOT_READY,
    eTimeout = VK_TIMEOUT,
    eEventSet = VK_EVENT_SET,
    eEventReset = VK_EVENT_RESET,
    eIncomplete = VK_INCOMPLETE,
    eErrorOutOfHostMemory = VK_ERROR_OUT_OF_HOST_MEMORY,
    eErrorOutOfDeviceMemory = VK_ERROR_OUT_OF_DEVICE_MEMORY,
    eErrorInitializationFailed = VK_ERROR_INITIALIZATION_FAILED,
    eErrorDeviceLost = VK_ERROR_DEVICE_LOST,
    eErrorMemoryMapFailed = VK_ERROR_MEMORY_MAP_FAILED,
    eErrorLayerNotPresent = VK_ERROR_LAYER_NOT_PRESENT,
    eErrorExtensionNotPresent = VK_ERROR_EXTENSION_NOT_PRESENT,
    eErrorFeatureNotPresent = VK_ERROR_FEATURE_NOT_PRESENT,
    eErrorIncompatibleDriver = VK_ERROR_INCOMPATIBLE_DRIVER,
    eErrorTooManyObjects = VK_ERROR_TOO_MANY_OBJECTS,
    eErrorFormatNotSupported = VK_ERROR_FORMAT_NOT_SUPPORTED,
    eErrorFragmentedPool = VK_ERROR_FRAGMENTED_POOL,
    eErrorUnknown = VK_ERROR_UNKNOWN,
    eErrorOutOfPoolMemory = VK_ERROR_OUT_OF_POOL_MEMORY,
    eErrorInvalidExternalHandle = VK_ERROR_INVALID_EXTERNAL_HANDLE,
    eErrorFragmentation = VK_ERROR_FRAGMENTATION,
    eErrorInvalidOpaqueCaptureAddress = VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS,
    eErrorSurfaceLostKhr = VK_ERROR_SURFACE_LOST_KHR,
    eErrorNativeWindowInUseKhr = VK_ERROR_NATIVE_WINDOW_IN_USE_KHR,
    eSuboptimalKhr = VK_SUBOPTIMAL_KHR,
    eErrorOutOfDateKhr = VK_ERROR_OUT_OF_DATE_KHR,
    eErrorIncompatibleDisplayKhr = VK_ERROR_INCOMPATIBLE_DISPLAY_KHR,
    eErrorValidationFailedExt = VK_ERROR_VALIDATION_FAILED_EXT,
    eErrorInvalidShaderNv = VK_ERROR_INVALID_SHADER_NV,
    eErrorInvalidDrmFormatModifierPlaneLayoutExt
    = VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT,
    eErrorNotPermittedExt = VK_ERROR_NOT_PERMITTED_EXT,
    eErrorFullScreenExclusiveModeLostExt = VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT,
    eThreadIdleKhr = VK_THREAD_IDLE_KHR,
    eThreadDoneKhr = VK_THREAD_DONE_KHR,
    eOperationDeferredKhr = VK_OPERATION_DEFERRED_KHR,
    eOperationNotDeferredKhr = VK_OPERATION_NOT_DEFERRED_KHR,
    ePipelineCompileRequiredExt = VK_PIPELINE_COMPILE_REQUIRED_EXT,
    eErrorFragmentationExt = VK_ERROR_FRAGMENTATION_EXT,
    eErrorInvalidDeviceAddressExt = VK_ERROR_INVALID_DEVICE_ADDRESS_EXT,
    eErrorInvalidExternalHandleKhr = VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR,
    eErrorInvalidOpaqueCaptureAddressKhr = VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR,
    eErrorOutOfPoolMemoryKhr = VK_ERROR_OUT_OF_POOL_MEMORY_KHR,
    eErrorPipelineCompileRequiredExt = VK_ERROR_PIPELINE_COMPILE_REQUIRED_EXT
  };

  VKMA_INLINE std::string to_string(Result value) {
    switch (value) {
    case Result::eSuccess: return "Success";
    case Result::eNotReady: return "NotReady";
    case Result::eTimeout: return "Timeout";
    case Result::eEventSet: return "EventSet";
    case Result::eEventReset: return "EventReset";
    case Result::eIncomplete: return "Incomplete";
    case Result::eErrorOutOfHostMemory: return "ErrorOutOfHostMemory";
    case Result::eErrorOutOfDeviceMemory: return "ErrorOutOfDeviceMemory";
    case Result::eErrorInitializationFailed: return "ErrorInitializationFailed";
    case Result::eErrorDeviceLost: return "ErrorDeviceLost";
    case Result::eErrorMemoryMapFailed: return "ErrorMemoryMapFailed";
    case Result::eErrorLayerNotPresent: return "ErrorLayerNotPresent";
    case Result::eErrorExtensionNotPresent: return "ErrorExtensionNotPresent";
    case Result::eErrorFeatureNotPresent: return "ErrorFeatureNotPresent";
    case Result::eErrorIncompatibleDriver: return "ErrorIncompatibleDriver";
    case Result::eErrorTooManyObjects: return "ErrorTooManyObjects";
    case Result::eErrorFormatNotSupported: return "ErrorFormatNotSupported";
    case Result::eErrorFragmentedPool: return "ErrorFragmentedPool";
    case Result::eErrorUnknown: return "ErrorUnknown";
    case Result::eErrorOutOfPoolMemory: return "ErrorOutOfPoolMemory";
    case Result::eErrorInvalidExternalHandle: return "ErrorInvalidExternalHandle";
    case Result::eErrorFragmentation: return "ErrorFragmentation";
    case Result::eErrorInvalidOpaqueCaptureAddress: return "ErrorInvalidOpaqueCaptureAddress";
    case Result::eErrorSurfaceLostKhr: return "ErrorSurfaceLostKhr";
    case Result::eErrorNativeWindowInUseKhr: return "ErrorNativeWindowInUseKhr";
    case Result::eSuboptimalKhr: return "SuboptimalKhr";
    case Result::eErrorOutOfDateKhr: return "ErrorOutOfDateKhr";
    case Result::eErrorIncompatibleDisplayKhr: return "ErrorIncompatibleDisplayKhr";
    case Result::eErrorValidationFailedExt: return "ErrorValidationFailedExt";
    case Result::eErrorInvalidShaderNv: return "ErrorInvalidShaderNv";
    case Result::eErrorInvalidDrmFormatModifierPlaneLayoutExt:
      return "ErrorInvalidDrmFormatModifierPlaneLayoutExt";
    case Result::eErrorNotPermittedExt: return "ErrorNotPermittedExt";
    case Result::eErrorFullScreenExclusiveModeLostExt: return "ErrorFullScreenExclusiveModeLostExt";
    case Result::eThreadIdleKhr: return "ThreadIdleKhr";
    case Result::eThreadDoneKhr: return "ThreadDoneKhr";
    case Result::eOperationDeferredKhr: return "OperationDeferredKhr";
    case Result::eOperationNotDeferredKhr: return "OperationNotDeferredKhr";
    case Result::ePipelineCompileRequiredExt: return "PipelineCompileRequiredExt";
    default: return "invalid ( " + VKMA_NAMESPACE::toHexString(static_cast<uint32_t>(value)) + " )";
    }
  }

  enum class VirtualAllocationCreateFlagBits : VkmaVirtualAllocationCreateFlags {
    eUpperAddress = VMA_VIRTUAL_ALLOCATION_CREATE_UPPER_ADDRESS_BIT,
    eStrategyMinMemory = VMA_VIRTUAL_ALLOCATION_CREATE_STRATEGY_MIN_MEMORY_BIT,
    eStrategyMinTime = VMA_VIRTUAL_ALLOCATION_CREATE_STRATEGY_MIN_TIME_BIT,
    eStrategyMinOffset = VMA_VIRTUAL_ALLOCATION_CREATE_STRATEGY_MIN_OFFSET_BIT,
    eStrategyMask = VMA_VIRTUAL_ALLOCATION_CREATE_STRATEGY_MASK
  };

  VKMA_INLINE std::string to_string(VirtualAllocationCreateFlagBits value) {
    switch (value) {
    case VirtualAllocationCreateFlagBits::eUpperAddress: return "UpperAddress";
    case VirtualAllocationCreateFlagBits::eStrategyMinMemory: return "StrategyMinMemory";
    case VirtualAllocationCreateFlagBits::eStrategyMinTime: return "StrategyMinTime";
    case VirtualAllocationCreateFlagBits::eStrategyMinOffset: return "StrategyMinOffset";
    case VirtualAllocationCreateFlagBits::eStrategyMask: return "StrategyMask";
    default: return "invalid ( " + VKMA_NAMESPACE::toHexString(static_cast<uint32_t>(value)) + " )";
    }
  }

  enum class VirtualBlockCreateFlagBits : VkmaVirtualBlockCreateFlags {
    eLinearAlgorithm = VMA_VIRTUAL_BLOCK_CREATE_LINEAR_ALGORITHM_BIT,
    eAlgorithmMask = VMA_VIRTUAL_BLOCK_CREATE_ALGORITHM_MASK
  };

  VKMA_INLINE std::string to_string(VirtualBlockCreateFlagBits value) {
    switch (value) {
    case VirtualBlockCreateFlagBits::eLinearAlgorithm: return "LinearAlgorithm";
    default: return "invalid ( " + VKMA_NAMESPACE::toHexString(static_cast<uint32_t>(value)) + " )";
    }
  }

  using AllocationCreateFlags = Flags<AllocationCreateFlagBits>;

  template <> struct FlagTraits<AllocationCreateFlagBits> {
    enum : VkFlags {
      allFlags = VkFlags(AllocationCreateFlagBits::eDedicatedMemory)
               | VkFlags(AllocationCreateFlagBits::eNeverAllocate)
               | VkFlags(AllocationCreateFlagBits::eMapped)
               | VkFlags(AllocationCreateFlagBits::eUserDataCopyString)
               | VkFlags(AllocationCreateFlagBits::eUpperAddress)
               | VkFlags(AllocationCreateFlagBits::eDontBind)
               | VkFlags(AllocationCreateFlagBits::eWithinBudget)
               | VkFlags(AllocationCreateFlagBits::eCanAlias)
               | VkFlags(AllocationCreateFlagBits::eHostAccessSequentialWrite)
               | VkFlags(AllocationCreateFlagBits::eHostAccessRandom)
               | VkFlags(AllocationCreateFlagBits::eHostAccessAllowTransferInstead)
               | VkFlags(AllocationCreateFlagBits::eStrategyMinMemory)
               | VkFlags(AllocationCreateFlagBits::eStrategyMinTime)
               | VkFlags(AllocationCreateFlagBits::eStrategyMinOffset)
               | VkFlags(AllocationCreateFlagBits::eStrategyMask)
    };
  };

  VKMA_INLINE VKMA_CONSTEXPR AllocationCreateFlags
  operator|(AllocationCreateFlagBits bit0, AllocationCreateFlagBits bit1) VKMA_NOEXCEPT {
    return AllocationCreateFlags(bit0) | bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR AllocationCreateFlags
  operator&(AllocationCreateFlagBits bit0, AllocationCreateFlagBits bit1) VKMA_NOEXCEPT {
    return AllocationCreateFlags(bit0) & bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR AllocationCreateFlags
  operator^(AllocationCreateFlagBits bit0, AllocationCreateFlagBits bit1) VKMA_NOEXCEPT {
    return AllocationCreateFlags(bit0) ^ bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR AllocationCreateFlags operator~(AllocationCreateFlagBits bits)
    VKMA_NOEXCEPT {
    return ~(AllocationCreateFlags(bits));
  }

  VKMA_INLINE std::string to_string(AllocationCreateFlags value) {
    if (!value)
      return "{}";
    std::string result;

    return "{ " + result.substr(0, result.size() - 3) + " }";
  }

  using AllocatorCreateFlags = Flags<AllocatorCreateFlagBits>;

  template <> struct FlagTraits<AllocatorCreateFlagBits> {
    enum : VkFlags {
      allFlags = VkFlags(AllocatorCreateFlagBits::eExternallySynchronized)
               | VkFlags(AllocatorCreateFlagBits::eKhrDedicatedAllocation)
               | VkFlags(AllocatorCreateFlagBits::eKhrBindMemory2)
               | VkFlags(AllocatorCreateFlagBits::eExtMemoryBudget)
               | VkFlags(AllocatorCreateFlagBits::eAmdDeviceCoherentMemory)
               | VkFlags(AllocatorCreateFlagBits::eBufferDeviceAddress)
               | VkFlags(AllocatorCreateFlagBits::eExtMemoryPriority)
    };
  };

  VKMA_INLINE VKMA_CONSTEXPR AllocatorCreateFlags
  operator|(AllocatorCreateFlagBits bit0, AllocatorCreateFlagBits bit1) VKMA_NOEXCEPT {
    return AllocatorCreateFlags(bit0) | bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR AllocatorCreateFlags
  operator&(AllocatorCreateFlagBits bit0, AllocatorCreateFlagBits bit1) VKMA_NOEXCEPT {
    return AllocatorCreateFlags(bit0) & bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR AllocatorCreateFlags
  operator^(AllocatorCreateFlagBits bit0, AllocatorCreateFlagBits bit1) VKMA_NOEXCEPT {
    return AllocatorCreateFlags(bit0) ^ bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR AllocatorCreateFlags operator~(AllocatorCreateFlagBits bits)
    VKMA_NOEXCEPT {
    return ~(AllocatorCreateFlags(bits));
  }

  VKMA_INLINE std::string to_string(AllocatorCreateFlags value) {
    if (!value)
      return "{}";
    std::string result;

    return "{ " + result.substr(0, result.size() - 3) + " }";
  }

  using DefragmentationFlags = Flags<DefragmentationFlagBits>;

  template <> struct FlagTraits<DefragmentationFlagBits> {
    enum : VkFlags {
      allFlags = VkFlags(DefragmentationFlagBits::eFlagAlgorithmFast)
               | VkFlags(DefragmentationFlagBits::eFlagAlgorithmBalanced)
               | VkFlags(DefragmentationFlagBits::eFlagAlgorithmFull)
               | VkFlags(DefragmentationFlagBits::eFlagAlgorithmExtensive)
               | VkFlags(DefragmentationFlagBits::eFlagAlgorithmMask)
    };
  };

  VKMA_INLINE VKMA_CONSTEXPR DefragmentationFlags
  operator|(DefragmentationFlagBits bit0, DefragmentationFlagBits bit1) VKMA_NOEXCEPT {
    return DefragmentationFlags(bit0) | bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR DefragmentationFlags
  operator&(DefragmentationFlagBits bit0, DefragmentationFlagBits bit1) VKMA_NOEXCEPT {
    return DefragmentationFlags(bit0) & bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR DefragmentationFlags
  operator^(DefragmentationFlagBits bit0, DefragmentationFlagBits bit1) VKMA_NOEXCEPT {
    return DefragmentationFlags(bit0) ^ bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR DefragmentationFlags operator~(DefragmentationFlagBits bits)
    VKMA_NOEXCEPT {
    return ~(DefragmentationFlags(bits));
  }

  VKMA_INLINE std::string to_string(DefragmentationFlags value) {
    if (!value)
      return "{}";
    std::string result;

    return "{ " + result.substr(0, result.size() - 3) + " }";
  }

  using PoolCreateFlags = Flags<PoolCreateFlagBits>;

  template <> struct FlagTraits<PoolCreateFlagBits> {
    enum : VkFlags {
      allFlags = VkFlags(PoolCreateFlagBits::eIgnoreBufferImageGranularity)
               | VkFlags(PoolCreateFlagBits::eLinearAlgorithm)
    };
  };

  VKMA_INLINE VKMA_CONSTEXPR PoolCreateFlags operator|(PoolCreateFlagBits bit0,
                                                       PoolCreateFlagBits bit1) VKMA_NOEXCEPT {
    return PoolCreateFlags(bit0) | bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR PoolCreateFlags operator&(PoolCreateFlagBits bit0,
                                                       PoolCreateFlagBits bit1) VKMA_NOEXCEPT {
    return PoolCreateFlags(bit0) & bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR PoolCreateFlags operator^(PoolCreateFlagBits bit0,
                                                       PoolCreateFlagBits bit1) VKMA_NOEXCEPT {
    return PoolCreateFlags(bit0) ^ bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR PoolCreateFlags operator~(PoolCreateFlagBits bits) VKMA_NOEXCEPT {
    return ~(PoolCreateFlags(bits));
  }

  VKMA_INLINE std::string to_string(PoolCreateFlags value) {
    if (!value)
      return "{}";
    std::string result;

    return "{ " + result.substr(0, result.size() - 3) + " }";
  }

  using VirtualAllocationCreateFlags = Flags<VirtualAllocationCreateFlagBits>;

  template <> struct FlagTraits<VirtualAllocationCreateFlagBits> {
    enum : VkFlags {
      allFlags = VkFlags(VirtualAllocationCreateFlagBits::eUpperAddress)
               | VkFlags(VirtualAllocationCreateFlagBits::eStrategyMinMemory)
               | VkFlags(VirtualAllocationCreateFlagBits::eStrategyMinTime)
               | VkFlags(VirtualAllocationCreateFlagBits::eStrategyMinOffset)
               | VkFlags(VirtualAllocationCreateFlagBits::eStrategyMask)
    };
  };

  VKMA_INLINE VKMA_CONSTEXPR VirtualAllocationCreateFlags operator|(
    VirtualAllocationCreateFlagBits bit0, VirtualAllocationCreateFlagBits bit1) VKMA_NOEXCEPT {
    return VirtualAllocationCreateFlags(bit0) | bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR VirtualAllocationCreateFlags operator&(
    VirtualAllocationCreateFlagBits bit0, VirtualAllocationCreateFlagBits bit1) VKMA_NOEXCEPT {
    return VirtualAllocationCreateFlags(bit0) & bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR VirtualAllocationCreateFlags operator^(
    VirtualAllocationCreateFlagBits bit0, VirtualAllocationCreateFlagBits bit1) VKMA_NOEXCEPT {
    return VirtualAllocationCreateFlags(bit0) ^ bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR VirtualAllocationCreateFlags
  operator~(VirtualAllocationCreateFlagBits bits) VKMA_NOEXCEPT {
    return ~(VirtualAllocationCreateFlags(bits));
  }

  VKMA_INLINE std::string to_string(VirtualAllocationCreateFlags value) {
    if (!value)
      return "{}";
    std::string result;

    return "{ " + result.substr(0, result.size() - 3) + " }";
  }

  using VirtualBlockCreateFlags = Flags<VirtualBlockCreateFlagBits>;

  template <> struct FlagTraits<VirtualBlockCreateFlagBits> {
    enum : VkFlags { allFlags = VkFlags(VirtualBlockCreateFlagBits::eLinearAlgorithm) };
  };

  VKMA_INLINE VKMA_CONSTEXPR VirtualBlockCreateFlags
  operator|(VirtualBlockCreateFlagBits bit0, VirtualBlockCreateFlagBits bit1) VKMA_NOEXCEPT {
    return VirtualBlockCreateFlags(bit0) | bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR VirtualBlockCreateFlags
  operator&(VirtualBlockCreateFlagBits bit0, VirtualBlockCreateFlagBits bit1) VKMA_NOEXCEPT {
    return VirtualBlockCreateFlags(bit0) & bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR VirtualBlockCreateFlags
  operator^(VirtualBlockCreateFlagBits bit0, VirtualBlockCreateFlagBits bit1) VKMA_NOEXCEPT {
    return VirtualBlockCreateFlags(bit0) ^ bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR VirtualBlockCreateFlags operator~(VirtualBlockCreateFlagBits bits)
    VKMA_NOEXCEPT {
    return ~(VirtualBlockCreateFlags(bits));
  }

  VKMA_INLINE std::string to_string(VirtualBlockCreateFlags value) {
    if (!value)
      return "{}";
    std::string result;

    return "{ " + result.substr(0, result.size() - 3) + " }";
  }
} // namespace VKMA_NAMESPACE

#ifndef VKMA_NO_EXCEPTIONS
namespace std {
  template <> struct is_error_code_enum<VKMA_NAMESPACE::Result> : public true_type {};
} // namespace std
#endif

namespace VKMA_NAMESPACE {
#ifndef VKMA_NO_EXCEPTIONS
  class ErrorCategoryImpl : public std::error_category {
  public:
    virtual const char *name() const VKMA_NOEXCEPT override {
      return VKMA_NAMESPACE_STRING "::Result";
    }
    virtual std::string message(int ev) const override {
      return to_string(static_cast<Result>(ev));
    }
  };

  class Error {
  public:
    Error() VKMA_NOEXCEPT = default;
    Error(const Error &) VKMA_NOEXCEPT = default;
    virtual ~Error() VKMA_NOEXCEPT = default;

    virtual const char *what() const VKMA_NOEXCEPT = 0;
  };

  class LogicError : public Error, public std::logic_error {
  public:
    explicit LogicError(const std::string &what) : Error(), std::logic_error(what) {}
    explicit LogicError(char const *what) : Error(), std::logic_error(what) {}

    virtual const char *what() const VKMA_NOEXCEPT { return std::logic_error::what(); }
  };

  class SystemError : public Error, public std::system_error {
  public:
    SystemError(std::error_code ec) : Error(), std::system_error(ec) {}
    SystemError(std::error_code ec, std::string const &what)
      : Error(), std::system_error(ec, what) {}
    SystemError(std::error_code ec, char const *what) : Error(), std::system_error(ec, what) {}
    SystemError(int ev, std::error_category const &ecat) : Error(), std::system_error(ev, ecat) {}
    SystemError(int ev, std::error_category const &ecat, std::string const &what)
      : Error(), std::system_error(ev, ecat, what) {}
    SystemError(int ev, std::error_category const &ecat, char const *what)
      : Error(), std::system_error(ev, ecat, what) {}

    virtual const char *what() const VKMA_NOEXCEPT { return std::system_error::what(); }
  };

  VKMA_INLINE const std::error_category &errorCategory() VKMA_NOEXCEPT {
    static ErrorCategoryImpl instance;
    return instance;
  }

  VKMA_INLINE std::error_code make_error_code(Result e) VKMA_NOEXCEPT {
    return std::error_code(static_cast<int>(e), errorCategory());
  }

  VKMA_INLINE std::error_condition make_error_condition(Result e) VKMA_NOEXCEPT {
    return std::error_condition(static_cast<int>(e), errorCategory());
  }

  class OutOfHostMemoryError : public SystemError {
  public:
    OutOfHostMemoryError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorOutOfHostMemory), message) {}
    OutOfHostMemoryError(char const *message)
      : SystemError(make_error_code(Result::eErrorOutOfHostMemory), message) {}
  };

  class OutOfDeviceMemoryError : public SystemError {
  public:
    OutOfDeviceMemoryError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorOutOfDeviceMemory), message) {}
    OutOfDeviceMemoryError(char const *message)
      : SystemError(make_error_code(Result::eErrorOutOfDeviceMemory), message) {}
  };

  class InitializationFailedError : public SystemError {
  public:
    InitializationFailedError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorInitializationFailed), message) {}
    InitializationFailedError(char const *message)
      : SystemError(make_error_code(Result::eErrorInitializationFailed), message) {}
  };

  class DeviceLostError : public SystemError {
  public:
    DeviceLostError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorDeviceLost), message) {}
    DeviceLostError(char const *message)
      : SystemError(make_error_code(Result::eErrorDeviceLost), message) {}
  };

  class MemoryMapFailedError : public SystemError {
  public:
    MemoryMapFailedError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorMemoryMapFailed), message) {}
    MemoryMapFailedError(char const *message)
      : SystemError(make_error_code(Result::eErrorMemoryMapFailed), message) {}
  };

  class LayerNotPresentError : public SystemError {
  public:
    LayerNotPresentError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorLayerNotPresent), message) {}
    LayerNotPresentError(char const *message)
      : SystemError(make_error_code(Result::eErrorLayerNotPresent), message) {}
  };

  class ExtensionNotPresentError : public SystemError {
  public:
    ExtensionNotPresentError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorExtensionNotPresent), message) {}
    ExtensionNotPresentError(char const *message)
      : SystemError(make_error_code(Result::eErrorExtensionNotPresent), message) {}
  };

  class FeatureNotPresentError : public SystemError {
  public:
    FeatureNotPresentError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorFeatureNotPresent), message) {}
    FeatureNotPresentError(char const *message)
      : SystemError(make_error_code(Result::eErrorFeatureNotPresent), message) {}
  };

  class IncompatibleDriverError : public SystemError {
  public:
    IncompatibleDriverError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorIncompatibleDriver), message) {}
    IncompatibleDriverError(char const *message)
      : SystemError(make_error_code(Result::eErrorIncompatibleDriver), message) {}
  };

  class TooManyObjectsError : public SystemError {
  public:
    TooManyObjectsError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorTooManyObjects), message) {}
    TooManyObjectsError(char const *message)
      : SystemError(make_error_code(Result::eErrorTooManyObjects), message) {}
  };

  class FormatNotSupportedError : public SystemError {
  public:
    FormatNotSupportedError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorFormatNotSupported), message) {}
    FormatNotSupportedError(char const *message)
      : SystemError(make_error_code(Result::eErrorFormatNotSupported), message) {}
  };

  class FragmentedPoolError : public SystemError {
  public:
    FragmentedPoolError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorFragmentedPool), message) {}
    FragmentedPoolError(char const *message)
      : SystemError(make_error_code(Result::eErrorFragmentedPool), message) {}
  };

  class UnknownError : public SystemError {
  public:
    UnknownError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorUnknown), message) {}
    UnknownError(char const *message)
      : SystemError(make_error_code(Result::eErrorUnknown), message) {}
  };

  class OutOfPoolMemoryError : public SystemError {
  public:
    OutOfPoolMemoryError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorOutOfPoolMemory), message) {}
    OutOfPoolMemoryError(char const *message)
      : SystemError(make_error_code(Result::eErrorOutOfPoolMemory), message) {}
  };

  class InvalidExternalHandleError : public SystemError {
  public:
    InvalidExternalHandleError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorInvalidExternalHandle), message) {}
    InvalidExternalHandleError(char const *message)
      : SystemError(make_error_code(Result::eErrorInvalidExternalHandle), message) {}
  };

  class FragmentationError : public SystemError {
  public:
    FragmentationError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorFragmentation), message) {}
    FragmentationError(char const *message)
      : SystemError(make_error_code(Result::eErrorFragmentation), message) {}
  };

  class InvalidOpaqueCaptureAddressError : public SystemError {
  public:
    InvalidOpaqueCaptureAddressError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorInvalidOpaqueCaptureAddress), message) {}
    InvalidOpaqueCaptureAddressError(char const *message)
      : SystemError(make_error_code(Result::eErrorInvalidOpaqueCaptureAddress), message) {}
  };

  class SurfaceLostKhrError : public SystemError {
  public:
    SurfaceLostKhrError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorSurfaceLostKhr), message) {}
    SurfaceLostKhrError(char const *message)
      : SystemError(make_error_code(Result::eErrorSurfaceLostKhr), message) {}
  };

  class NativeWindowInUseKhrError : public SystemError {
  public:
    NativeWindowInUseKhrError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorNativeWindowInUseKhr), message) {}
    NativeWindowInUseKhrError(char const *message)
      : SystemError(make_error_code(Result::eErrorNativeWindowInUseKhr), message) {}
  };

  class OutOfDateKhrError : public SystemError {
  public:
    OutOfDateKhrError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorOutOfDateKhr), message) {}
    OutOfDateKhrError(char const *message)
      : SystemError(make_error_code(Result::eErrorOutOfDateKhr), message) {}
  };

  class IncompatibleDisplayKhrError : public SystemError {
  public:
    IncompatibleDisplayKhrError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorIncompatibleDisplayKhr), message) {}
    IncompatibleDisplayKhrError(char const *message)
      : SystemError(make_error_code(Result::eErrorIncompatibleDisplayKhr), message) {}
  };

  class ValidationFailedExtError : public SystemError {
  public:
    ValidationFailedExtError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorValidationFailedExt), message) {}
    ValidationFailedExtError(char const *message)
      : SystemError(make_error_code(Result::eErrorValidationFailedExt), message) {}
  };

  class InvalidShaderNvError : public SystemError {
  public:
    InvalidShaderNvError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorInvalidShaderNv), message) {}
    InvalidShaderNvError(char const *message)
      : SystemError(make_error_code(Result::eErrorInvalidShaderNv), message) {}
  };

  class InvalidDrmFormatModifierPlaneLayoutExtError : public SystemError {
  public:
    InvalidDrmFormatModifierPlaneLayoutExtError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorInvalidDrmFormatModifierPlaneLayoutExt),
                    message) {}
    InvalidDrmFormatModifierPlaneLayoutExtError(char const *message)
      : SystemError(make_error_code(Result::eErrorInvalidDrmFormatModifierPlaneLayoutExt),
                    message) {}
  };

  class NotPermittedExtError : public SystemError {
  public:
    NotPermittedExtError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorNotPermittedExt), message) {}
    NotPermittedExtError(char const *message)
      : SystemError(make_error_code(Result::eErrorNotPermittedExt), message) {}
  };

  class FullScreenExclusiveModeLostExtError : public SystemError {
  public:
    FullScreenExclusiveModeLostExtError(std::string const &message)
      : SystemError(make_error_code(Result::eErrorFullScreenExclusiveModeLostExt), message) {}
    FullScreenExclusiveModeLostExtError(char const *message)
      : SystemError(make_error_code(Result::eErrorFullScreenExclusiveModeLostExt), message) {}
  };

  [[noreturn]] static void throwResultException(Result result, char const *message) {
    switch (result) {
    case Result::eErrorOutOfHostMemory: throw OutOfHostMemoryError(message);
    case Result::eErrorOutOfDeviceMemory: throw OutOfDeviceMemoryError(message);
    case Result::eErrorInitializationFailed: throw InitializationFailedError(message);
    case Result::eErrorDeviceLost: throw DeviceLostError(message);
    case Result::eErrorMemoryMapFailed: throw MemoryMapFailedError(message);
    case Result::eErrorLayerNotPresent: throw LayerNotPresentError(message);
    case Result::eErrorExtensionNotPresent: throw ExtensionNotPresentError(message);
    case Result::eErrorFeatureNotPresent: throw FeatureNotPresentError(message);
    case Result::eErrorIncompatibleDriver: throw IncompatibleDriverError(message);
    case Result::eErrorTooManyObjects: throw TooManyObjectsError(message);
    case Result::eErrorFormatNotSupported: throw FormatNotSupportedError(message);
    case Result::eErrorFragmentedPool: throw FragmentedPoolError(message);
    case Result::eErrorUnknown: throw UnknownError(message);
    case Result::eErrorOutOfPoolMemory: throw OutOfPoolMemoryError(message);
    case Result::eErrorInvalidExternalHandle: throw InvalidExternalHandleError(message);
    case Result::eErrorFragmentation: throw FragmentationError(message);
    case Result::eErrorInvalidOpaqueCaptureAddress: throw InvalidOpaqueCaptureAddressError(message);
    case Result::eErrorSurfaceLostKhr: throw SurfaceLostKhrError(message);
    case Result::eErrorNativeWindowInUseKhr: throw NativeWindowInUseKhrError(message);
    case Result::eErrorOutOfDateKhr: throw OutOfDateKhrError(message);
    case Result::eErrorIncompatibleDisplayKhr: throw IncompatibleDisplayKhrError(message);
    case Result::eErrorValidationFailedExt: throw ValidationFailedExtError(message);
    case Result::eErrorInvalidShaderNv: throw InvalidShaderNvError(message);
    case Result::eErrorInvalidDrmFormatModifierPlaneLayoutExt:
      throw InvalidDrmFormatModifierPlaneLayoutExtError(message);
    case Result::eErrorNotPermittedExt: throw NotPermittedExtError(message);
    case Result::eErrorFullScreenExclusiveModeLostExt:
      throw FullScreenExclusiveModeLostExtError(message);
    default: throw SystemError(make_error_code(result));
    }
  }
#endif

  template <typename T> void ignore(T const &) VKMA_NOEXCEPT {}

  template <typename T> struct ResultValue {
#ifdef VKMA_HAS_NOEXCEPT
    ResultValue(Result r, T &v) VKMA_NOEXCEPT(VKMA_NOEXCEPT(T(v)))
#else
    ResultValue(Result r, T &v)
#endif
      : result(r), value(v) {
    }

#ifdef VKMA_HAS_NOEXCEPT
    ResultValue(Result r, T &&v) VKMA_NOEXCEPT(VKMA_NOEXCEPT(T(std::move(v))))
#else
    ResultValue(Result r, T &&v)
#endif
      : result(r), value(std::move(v)) {
    }

    Result result;
    T value;

    operator std::tuple<Result &, T &>() VKMA_NOEXCEPT {
      return std::tuple<Result &, T &>(result, value);
    }

#if !defined(VKMA_DISABLE_IMPLICIT_RESULT_VALUE_CAST)
    VKMA_DEPRECATED("Implicit-cast operators on vkma::ResultValue are deprecated. Explicitly "
                    "access the value as member of ResultValue.")
    operator T const &() const &VKMA_NOEXCEPT { return value; }

    VKMA_DEPRECATED("Implicit-cast operators on vkma::ResultValue are deprecated. Explicitly "
                    "access the value as member of ResultValue.")
    operator T &() & VKMA_NOEXCEPT { return value; }

    VKMA_DEPRECATED("Implicit-cast operators on vkma::ResultValue are deprecated. Explicitly "
                    "access the value as member of ResultValue.")
    operator T const &&() const &&VKMA_NOEXCEPT { return std::move(value); }

    VKMA_DEPRECATED("Implicit-cast operators on vkma::ResultValue are deprecated. Explicitly "
                    "access the value as member of ResultValue.")
    operator T &&() && VKMA_NOEXCEPT { return std::move(value); }
#endif
  };

#if !defined(VKMA_NO_SMART_HANDLE)
  template <typename Type> struct ResultValue<UniqueHandle<Type>> {
  #ifdef VKMA_HAS_NOEXCEPT
    ResultValue(Result r, UniqueHandle<Type> &&v) VKMA_NOEXCEPT
  #else
    ResultValue(Result r, UniqueHandle<Type> &&v)
  #endif
      : result(r),
        value(std::move(v)) {
    }

    std::tuple<Result, UniqueHandle<Type>> asTuple() {
      return std::make_tuple(result, std::move(value));
    }

  #if !defined(VKMA_DISABLE_IMPLICIT_RESULT_VALUE_CAST)
    VKMA_DEPRECATED("Implicit-cast operators on vkma::ResultValue are deprecated. Explicitly "
                    "access the value as member of ResultValue.")
    operator UniqueHandle<Type> &() & VKMA_NOEXCEPT { return value; }

    VKMA_DEPRECATED("Implicit-cast operators on vkma::ResultValue are deprecated. Explicitly "
                    "access the value as member of ResultValue.")
    operator UniqueHandle<Type>() VKMA_NOEXCEPT { return std::move(value); }
  #endif

    Result result;
    UniqueHandle<Type> value;
  };

  template <typename Type> struct ResultValue<std::vector<UniqueHandle<Type>>> {
  #ifdef VKMA_HAS_NOEXCEPT
    ResultValue(Result r, std::vector<UniqueHandle<Type>> &&v) VKMA_NOEXCEPT
  #else
    ResultValue(Result r, std::vector<UniqueHandle<Type>> &&v)
  #endif
      : result(r),
        value(std::move(v)) {
    }

    Result result;
    std::vector<UniqueHandle<Type>> value;

    operator std::tuple<Result &, std::vector<UniqueHandle<Type>> &>() VKMA_NOEXCEPT {
      return std::tuple<Result &, std::vector<UniqueHandle<Type>> &>(result, value);
    }
  };
#endif

  template <typename T> struct ResultValueType {
#ifdef VKMA_NO_EXCEPTIONS
    typedef ResultValue<T> type;
#else
    typedef T type;
#endif
  };

  template <> struct ResultValueType<void> {
#ifdef VKMA_NO_EXCEPTIONS
    typedef Result type;
#else
    typedef void type;
#endif
  };

  VKMA_INLINE ResultValueType<void>::type createResultValue(Result result, char const *message) {
#ifdef VKMA_NO_EXCEPTIONS
    ignore(message);
    VKMA_ASSERT_ON_RESULT(result == Result::eSuccess);
    return result;
#else
    if (result != Result::eSuccess) {
      throwResultException(result, message);
    }
#endif
  }

  template <typename T>
  VKMA_INLINE typename ResultValueType<T>::type createResultValue(Result result, T &data,
                                                                  char const *message) {
#ifdef VKMA_NO_EXCEPTIONS
    ignore(message);
    VKMA_ASSERT_ON_RESULT(result == Result::eSuccess);
    return ResultValue<T>(result, std::move(data));
#else
    if (result != Result::eSuccess) {
      throwResultException(result, message);
    }
    return std::move(data);
#endif
  }

  VKMA_INLINE Result createResultValue(Result result, char const *message,
                                       std::initializer_list<Result> successCodes) {
#ifdef VKMA_NO_EXCEPTIONS
    ignore(message);
    ignore(successCodes); // just in case VKMA_ASSERT_ON_RESULT is empty
    VKMA_ASSERT_ON_RESULT(std::find(successCodes.begin(), successCodes.end(), result)
                          != successCodes.end());
#else
    if (std::find(successCodes.begin(), successCodes.end(), result) == successCodes.end()) {
      throwResultException(result, message);
    }
#endif
    return result;
  }

  template <typename T>
  VKMA_INLINE ResultValue<T> createResultValue(Result result, T &data, char const *message,
                                               std::initializer_list<Result> successCodes) {
#ifdef VKMA_NO_EXCEPTIONS
    ignore(message);
    ignore(successCodes); // just in case VKMA_ASSERT_ON_RESULT is empty
    VKMA_ASSERT_ON_RESULT(std::find(successCodes.begin(), successCodes.end(), result)
                          != successCodes.end());
#else
    if (std::find(successCodes.begin(), successCodes.end(), result) == successCodes.end()) {
      throwResultException(result, message);
    }
#endif
    return ResultValue<T>(result, data);
  }

#ifndef VKMA_NO_SMART_HANDLE
  template <typename T>
  VKMA_INLINE typename ResultValueType<UniqueHandle<T>>::type
  createResultValue(Result result, T &data, char const *message,
                    typename UniqueHandleTraits<T>::deleter const &deleter) {
  #ifdef VKMA_NO_EXCEPTIONS
    ignore(message);
    VKMA_ASSERT_ON_RESULT(result == Result::eSuccess);
    return ResultValue<UniqueHandle<T>>(result, UniqueHandle<T>(data, deleter));
  #else
    if (result != Result::eSuccess) {
      throwResultException(result, message);
    }
    return UniqueHandle<T>(data, deleter);
  #endif
  }

  template <typename T>
  VKMA_INLINE ResultValue<UniqueHandle<T>> createResultValue(
    Result result, T &data, char const *message, std::initializer_list<Result> successCodes,
    typename UniqueHandleTraits<T>::deleter const &deleter) {
  #ifdef VKMA_NO_EXCEPTIONS
    ignore(message);
    ignore(successCodes); // just in case VKMA_ASSERT_ON_RESULT is empty
    VKMA_ASSERT_ON_RESULT(std::find(successCodes.begin(), successCodes.end(), result)
                          != successCodes.end());
  #else
    if (std::find(successCodes.begin(), successCodes.end(), result) == successCodes.end()) {
      throwResultException(result, message);
    }
  #endif
    return ResultValue<UniqueHandle<T>>(result, UniqueHandle<T>(data, deleter));
  }

  template <typename T>
  VKMA_INLINE typename ResultValueType<std::vector<UniqueHandle<T>>>::type
  createResultValue(Result result, std::vector<UniqueHandle<T>> &&data, char const *message) {
  #ifdef VKMA_NO_EXCEPTIONS
    ignore(message);
    VKMA_ASSERT_ON_RESULT(result == Result::eSuccess);
    return ResultValue<std::vector<UniqueHandle<T>>>(result, std::move(data));
  #else
    if (result != Result::eSuccess) {
      throwResultException(result, message);
    }
    return std::move(data);
  #endif
  }

  template <typename T>
  VKMA_INLINE ResultValue<std::vector<UniqueHandle<T>>>
  createResultValue(Result result, std::vector<UniqueHandle<T>> &&data, char const *message,
                    std::initializer_list<Result> successCodes) {
  #ifdef VKMA_NO_EXCEPTIONS
    ignore(message);
    ignore(successCodes); // just in case VKMA_ASSERT_ON_RESULT is empty
    VKMA_ASSERT_ON_RESULT(std::find(successCodes.begin(), successCodes.end(), result)
                          != successCodes.end());
  #else
    if (std::find(successCodes.begin(), successCodes.end(), result) == successCodes.end()) {
      throwResultException(result, message);
    }
  #endif
    return ResultValue<std::vector<UniqueHandle<T>>>(result, std::move(data));
  }
#endif

  class Pool {
  public:
    using CType = VkmaPool;

  public:
    VKMA_CONSTEXPR Pool() VKMA_NOEXCEPT : m_pool(VKMA_NULL_HANDLE) {}

    VKMA_CONSTEXPR Pool(std::nullptr_t) VKMA_NOEXCEPT : m_pool(VKMA_NULL_HANDLE) {}

    VKMA_TYPESAFE_EXPLICIT Pool(VkmaPool pool) VKMA_NOEXCEPT : m_pool(pool) {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    Pool &operator=(VkmaPool pool) VKMA_NOEXCEPT {
      m_pool = pool;
      return *this;
    }
#endif

    Pool &operator=(std::nullptr_t) VKMA_NOEXCEPT {
      m_pool = VKMA_NULL_HANDLE;
      return *this;
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(Pool const &) const = default;
#else
    bool operator==(Pool const &rhs) const VKMA_NOEXCEPT { return m_pool == rhs.m_pool; }

    bool operator!=(Pool const &rhs) const VKMA_NOEXCEPT { return m_pool != rhs.m_pool; }

    bool operator<(Pool const &rhs) const VKMA_NOEXCEPT { return m_pool < rhs.m_pool; }
#endif

    VKMA_TYPESAFE_EXPLICIT operator VkmaPool() const VKMA_NOEXCEPT { return m_pool; }

    explicit operator bool() const VKMA_NOEXCEPT { return m_pool != VKMA_NULL_HANDLE; }

    bool operator!() const VKMA_NOEXCEPT { return m_pool == VKMA_NULL_HANDLE; }

  private:
    VkmaPool m_pool;
  };
  static_assert(sizeof(VKMA_NAMESPACE::Pool) == sizeof(VkmaPool),
                "handle and wrapper have different size!");

  template <> struct isVulkanHandleType<VKMA_NAMESPACE::Pool> {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

  struct AllocationCreateInfo {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR AllocationCreateInfo(AllocationCreateFlags flags_ = {},
                                        MemoryUsage usage_ = VKMA_NAMESPACE::MemoryUsage::eUnknown,
                                        VkMemoryPropertyFlags requiredFlags_ = {},
                                        VkMemoryPropertyFlags preferredFlags_ = {},
                                        uint32_t memoryTypeBits_ = {}, Pool pool_ = {},
                                        void *pUserData_ = {}, float priority_ = {}) VKMA_NOEXCEPT
      : flags(flags_),
        usage(usage_),
        requiredFlags(requiredFlags_),
        preferredFlags(preferredFlags_),
        memoryTypeBits(memoryTypeBits_),
        pool(pool_),
        pUserData(pUserData_),
        priority(priority_) {}

    VKMA_CONSTEXPR AllocationCreateInfo(AllocationCreateInfo const &rhs) VKMA_NOEXCEPT = default;

    AllocationCreateInfo(VkmaAllocationCreateInfo const &rhs) VKMA_NOEXCEPT
      : AllocationCreateInfo(*reinterpret_cast<AllocationCreateInfo const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 AllocationCreateInfo &operator=(AllocationCreateInfo const &rhs)
      VKMA_NOEXCEPT = default;

    AllocationCreateInfo &operator=(VkmaAllocationCreateInfo const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::AllocationCreateInfo const *>(&rhs);
      return *this;
    }

    AllocationCreateInfo &setFlags(AllocationCreateFlags flags_) VKMA_NOEXCEPT {
      flags = flags_;
      return *this;
    }

    AllocationCreateInfo &setUsage(MemoryUsage usage_) VKMA_NOEXCEPT {
      usage = usage_;
      return *this;
    }

    AllocationCreateInfo &setRequiredFlags(VkMemoryPropertyFlags requiredFlags_) VKMA_NOEXCEPT {
      requiredFlags = requiredFlags_;
      return *this;
    }

    AllocationCreateInfo &setPreferredFlags(VkMemoryPropertyFlags preferredFlags_) VKMA_NOEXCEPT {
      preferredFlags = preferredFlags_;
      return *this;
    }

    AllocationCreateInfo &setMemoryTypeBits(uint32_t memoryTypeBits_) VKMA_NOEXCEPT {
      memoryTypeBits = memoryTypeBits_;
      return *this;
    }

    AllocationCreateInfo &setPool(Pool pool_) VKMA_NOEXCEPT {
      pool = pool_;
      return *this;
    }

    AllocationCreateInfo &setPUserData(void *pUserData_) VKMA_NOEXCEPT {
      pUserData = pUserData_;
      return *this;
    }

    AllocationCreateInfo &setPriority(float priority_) VKMA_NOEXCEPT {
      priority = priority_;
      return *this;
    }

    operator VkmaAllocationCreateInfo const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaAllocationCreateInfo *>(this);
    }

    operator VkmaAllocationCreateInfo &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaAllocationCreateInfo *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(AllocationCreateInfo const &) const = default;
#else
    bool operator==(AllocationCreateInfo const &rhs) const VKMA_NOEXCEPT {
      return (flags == rhs.flags) && (usage == rhs.usage) && (requiredFlags == rhs.requiredFlags)
          && (preferredFlags == rhs.preferredFlags) && (memoryTypeBits == rhs.memoryTypeBits)
          && (pool == rhs.pool) && (pUserData == rhs.pUserData) && (priority == rhs.priority);
    }

    bool operator!=(AllocationCreateInfo const &rhs) const VKMA_NOEXCEPT {
      return !operator==(rhs);
    }
#endif

  public:
    AllocationCreateFlags flags = {};
    MemoryUsage usage = VKMA_NAMESPACE::MemoryUsage::eUnknown;
    VkMemoryPropertyFlags requiredFlags = {};
    VkMemoryPropertyFlags preferredFlags = {};
    uint32_t memoryTypeBits = {};
    Pool pool = {};
    void *pUserData = {};
    float priority = {};
  };
  static_assert(sizeof(AllocationCreateInfo) == sizeof(VkmaAllocationCreateInfo),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<AllocationCreateInfo>::value,
                "struct wrapper is not a standard layout!");

  struct AllocationInfo {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR AllocationInfo(uint32_t memoryType_ = {}, VkDeviceMemory deviceMemory_ = {},
                                  VkDeviceSize offset_ = {}, VkDeviceSize size_ = {},
                                  void *pMappedData_ = {}, void *pUserData_ = {},
                                  const char *pName_ = {}) VKMA_NOEXCEPT
      : memoryType(memoryType_),
        deviceMemory(deviceMemory_),
        offset(offset_),
        size(size_),
        pMappedData(pMappedData_),
        pUserData(pUserData_),
        pName(pName_) {}

    VKMA_CONSTEXPR AllocationInfo(AllocationInfo const &rhs) VKMA_NOEXCEPT = default;

    AllocationInfo(VkmaAllocationInfo const &rhs) VKMA_NOEXCEPT
      : AllocationInfo(*reinterpret_cast<AllocationInfo const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 AllocationInfo &operator=(AllocationInfo const &rhs) VKMA_NOEXCEPT = default;

    AllocationInfo &operator=(VkmaAllocationInfo const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::AllocationInfo const *>(&rhs);
      return *this;
    }

    AllocationInfo &setMemoryType(uint32_t memoryType_) VKMA_NOEXCEPT {
      memoryType = memoryType_;
      return *this;
    }

    AllocationInfo &setDeviceMemory(VkDeviceMemory deviceMemory_) VKMA_NOEXCEPT {
      deviceMemory = deviceMemory_;
      return *this;
    }

    AllocationInfo &setOffset(VkDeviceSize offset_) VKMA_NOEXCEPT {
      offset = offset_;
      return *this;
    }

    AllocationInfo &setSize(VkDeviceSize size_) VKMA_NOEXCEPT {
      size = size_;
      return *this;
    }

    AllocationInfo &setPMappedData(void *pMappedData_) VKMA_NOEXCEPT {
      pMappedData = pMappedData_;
      return *this;
    }

    AllocationInfo &setPUserData(void *pUserData_) VKMA_NOEXCEPT {
      pUserData = pUserData_;
      return *this;
    }

    AllocationInfo &setPName(const char *pName_) VKMA_NOEXCEPT {
      pName = pName_;
      return *this;
    }

    operator VkmaAllocationInfo const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaAllocationInfo *>(this);
    }

    operator VkmaAllocationInfo &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaAllocationInfo *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(AllocationInfo const &) const = default;
#else
    bool operator==(AllocationInfo const &rhs) const VKMA_NOEXCEPT {
      return (memoryType == rhs.memoryType) && (deviceMemory == rhs.deviceMemory)
          && (offset == rhs.offset) && (size == rhs.size) && (pMappedData == rhs.pMappedData)
          && (pUserData == rhs.pUserData) && (pName == rhs.pName);
    }

    bool operator!=(AllocationInfo const &rhs) const VKMA_NOEXCEPT { return !operator==(rhs); }
#endif

  public:
    uint32_t memoryType = {};
    VkDeviceMemory deviceMemory = {};
    VkDeviceSize offset = {};
    VkDeviceSize size = {};
    void *pMappedData = {};
    void *pUserData = {};
    const char *pName = {};
  };
  static_assert(sizeof(AllocationInfo) == sizeof(VkmaAllocationInfo),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<AllocationInfo>::value,
                "struct wrapper is not a standard layout!");

  struct DeviceMemoryCallbacks {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR DeviceMemoryCallbacks(PFN_vkmaAllocateDeviceMemoryFunction pfnAllocate_ = {},
                                         PFN_vkmaFreeDeviceMemoryFunction pfnFree_ = {},
                                         void *pUserData_ = {}) VKMA_NOEXCEPT
      : pfnAllocate(pfnAllocate_),
        pfnFree(pfnFree_),
        pUserData(pUserData_) {}

    VKMA_CONSTEXPR DeviceMemoryCallbacks(DeviceMemoryCallbacks const &rhs) VKMA_NOEXCEPT = default;

    DeviceMemoryCallbacks(VkmaDeviceMemoryCallbacks const &rhs) VKMA_NOEXCEPT
      : DeviceMemoryCallbacks(*reinterpret_cast<DeviceMemoryCallbacks const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 DeviceMemoryCallbacks &operator=(DeviceMemoryCallbacks const &rhs)
      VKMA_NOEXCEPT = default;

    DeviceMemoryCallbacks &operator=(VkmaDeviceMemoryCallbacks const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::DeviceMemoryCallbacks const *>(&rhs);
      return *this;
    }

    DeviceMemoryCallbacks &setPfnAllocate(PFN_vkmaAllocateDeviceMemoryFunction pfnAllocate_)
      VKMA_NOEXCEPT {
      pfnAllocate = pfnAllocate_;
      return *this;
    }

    DeviceMemoryCallbacks &setPfnFree(PFN_vkmaFreeDeviceMemoryFunction pfnFree_) VKMA_NOEXCEPT {
      pfnFree = pfnFree_;
      return *this;
    }

    DeviceMemoryCallbacks &setPUserData(void *pUserData_) VKMA_NOEXCEPT {
      pUserData = pUserData_;
      return *this;
    }

    operator VkmaDeviceMemoryCallbacks const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaDeviceMemoryCallbacks *>(this);
    }

    operator VkmaDeviceMemoryCallbacks &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaDeviceMemoryCallbacks *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(DeviceMemoryCallbacks const &) const = default;
#else
    bool operator==(DeviceMemoryCallbacks const &rhs) const VKMA_NOEXCEPT {
      return (pfnAllocate == rhs.pfnAllocate) && (pfnFree == rhs.pfnFree)
          && (pUserData == rhs.pUserData);
    }

    bool operator!=(DeviceMemoryCallbacks const &rhs) const VKMA_NOEXCEPT {
      return !operator==(rhs);
    }
#endif

  public:
    PFN_vkmaAllocateDeviceMemoryFunction pfnAllocate = {};
    PFN_vkmaFreeDeviceMemoryFunction pfnFree = {};
    void *pUserData = {};
  };
  static_assert(sizeof(DeviceMemoryCallbacks) == sizeof(VkmaDeviceMemoryCallbacks),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<DeviceMemoryCallbacks>::value,
                "struct wrapper is not a standard layout!");

  struct VulkanFunctions {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR VulkanFunctions(
      PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr_ = {},
      PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr_ = {},
      PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties_ = {},
      PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties_ = {},
      PFN_vkAllocateMemory vkAllocateMemory_ = {}, PFN_vkFreeMemory vkFreeMemory_ = {},
      PFN_vkMapMemory vkMapMemory_ = {}, PFN_vkUnmapMemory vkUnmapMemory_ = {},
      PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges_ = {},
      PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges_ = {},
      PFN_vkBindBufferMemory vkBindBufferMemory_ = {},
      PFN_vkBindImageMemory vkBindImageMemory_ = {},
      PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements_ = {},
      PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements_ = {},
      PFN_vkCreateBuffer vkCreateBuffer_ = {}, PFN_vkDestroyBuffer vkDestroyBuffer_ = {},
      PFN_vkCreateImage vkCreateImage_ = {}, PFN_vkDestroyImage vkDestroyImage_ = {},
      PFN_vkCmdCopyBuffer vkCmdCopyBuffer_ = {},
      PFN_vkGetBufferMemoryRequirements2KHR vkGetBufferMemoryRequirements2KHR_ = {},
      PFN_vkGetImageMemoryRequirements2KHR vkGetImageMemoryRequirements2KHR_ = {},
      PFN_vkBindBufferMemory2KHR vkBindBufferMemory2KHR_ = {},
      PFN_vkBindImageMemory2KHR vkBindImageMemory2KHR_ = {},
      PFN_vkGetPhysicalDeviceMemoryProperties2KHR vkGetPhysicalDeviceMemoryProperties2KHR_ = {})
      VKMA_NOEXCEPT
      : vkGetInstanceProcAddr(vkGetInstanceProcAddr_),
        vkGetDeviceProcAddr(vkGetDeviceProcAddr_),
        vkGetPhysicalDeviceProperties(vkGetPhysicalDeviceProperties_),
        vkGetPhysicalDeviceMemoryProperties(vkGetPhysicalDeviceMemoryProperties_),
        vkAllocateMemory(vkAllocateMemory_),
        vkFreeMemory(vkFreeMemory_),
        vkMapMemory(vkMapMemory_),
        vkUnmapMemory(vkUnmapMemory_),
        vkFlushMappedMemoryRanges(vkFlushMappedMemoryRanges_),
        vkInvalidateMappedMemoryRanges(vkInvalidateMappedMemoryRanges_),
        vkBindBufferMemory(vkBindBufferMemory_),
        vkBindImageMemory(vkBindImageMemory_),
        vkGetBufferMemoryRequirements(vkGetBufferMemoryRequirements_),
        vkGetImageMemoryRequirements(vkGetImageMemoryRequirements_),
        vkCreateBuffer(vkCreateBuffer_),
        vkDestroyBuffer(vkDestroyBuffer_),
        vkCreateImage(vkCreateImage_),
        vkDestroyImage(vkDestroyImage_),
        vkCmdCopyBuffer(vkCmdCopyBuffer_),
        vkGetBufferMemoryRequirements2KHR(vkGetBufferMemoryRequirements2KHR_),
        vkGetImageMemoryRequirements2KHR(vkGetImageMemoryRequirements2KHR_),
        vkBindBufferMemory2KHR(vkBindBufferMemory2KHR_),
        vkBindImageMemory2KHR(vkBindImageMemory2KHR_),
        vkGetPhysicalDeviceMemoryProperties2KHR(vkGetPhysicalDeviceMemoryProperties2KHR_) {}

    VKMA_CONSTEXPR VulkanFunctions(VulkanFunctions const &rhs) VKMA_NOEXCEPT = default;

    VulkanFunctions(VkmaVulkanFunctions const &rhs) VKMA_NOEXCEPT
      : VulkanFunctions(*reinterpret_cast<VulkanFunctions const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 VulkanFunctions &operator=(VulkanFunctions const &rhs)
      VKMA_NOEXCEPT = default;

    VulkanFunctions &operator=(VkmaVulkanFunctions const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::VulkanFunctions const *>(&rhs);
      return *this;
    }

    VulkanFunctions &setVkGetInstanceProcAddr(PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr_)
      VKMA_NOEXCEPT {
      vkGetInstanceProcAddr = vkGetInstanceProcAddr_;
      return *this;
    }

    VulkanFunctions &setVkGetDeviceProcAddr(PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr_)
      VKMA_NOEXCEPT {
      vkGetDeviceProcAddr = vkGetDeviceProcAddr_;
      return *this;
    }

    VulkanFunctions &setVkGetPhysicalDeviceProperties(
      PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties_) VKMA_NOEXCEPT {
      vkGetPhysicalDeviceProperties = vkGetPhysicalDeviceProperties_;
      return *this;
    }

    VulkanFunctions &setVkGetPhysicalDeviceMemoryProperties(
      PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties_) VKMA_NOEXCEPT {
      vkGetPhysicalDeviceMemoryProperties = vkGetPhysicalDeviceMemoryProperties_;
      return *this;
    }

    VulkanFunctions &setVkAllocateMemory(PFN_vkAllocateMemory vkAllocateMemory_) VKMA_NOEXCEPT {
      vkAllocateMemory = vkAllocateMemory_;
      return *this;
    }

    VulkanFunctions &setVkFreeMemory(PFN_vkFreeMemory vkFreeMemory_) VKMA_NOEXCEPT {
      vkFreeMemory = vkFreeMemory_;
      return *this;
    }

    VulkanFunctions &setVkMapMemory(PFN_vkMapMemory vkMapMemory_) VKMA_NOEXCEPT {
      vkMapMemory = vkMapMemory_;
      return *this;
    }

    VulkanFunctions &setVkUnmapMemory(PFN_vkUnmapMemory vkUnmapMemory_) VKMA_NOEXCEPT {
      vkUnmapMemory = vkUnmapMemory_;
      return *this;
    }

    VulkanFunctions &setVkFlushMappedMemoryRanges(
      PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges_) VKMA_NOEXCEPT {
      vkFlushMappedMemoryRanges = vkFlushMappedMemoryRanges_;
      return *this;
    }

    VulkanFunctions &setVkInvalidateMappedMemoryRanges(
      PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges_) VKMA_NOEXCEPT {
      vkInvalidateMappedMemoryRanges = vkInvalidateMappedMemoryRanges_;
      return *this;
    }

    VulkanFunctions &setVkBindBufferMemory(PFN_vkBindBufferMemory vkBindBufferMemory_)
      VKMA_NOEXCEPT {
      vkBindBufferMemory = vkBindBufferMemory_;
      return *this;
    }

    VulkanFunctions &setVkBindImageMemory(PFN_vkBindImageMemory vkBindImageMemory_) VKMA_NOEXCEPT {
      vkBindImageMemory = vkBindImageMemory_;
      return *this;
    }

    VulkanFunctions &setVkGetBufferMemoryRequirements(
      PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements_) VKMA_NOEXCEPT {
      vkGetBufferMemoryRequirements = vkGetBufferMemoryRequirements_;
      return *this;
    }

    VulkanFunctions &setVkGetImageMemoryRequirements(
      PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements_) VKMA_NOEXCEPT {
      vkGetImageMemoryRequirements = vkGetImageMemoryRequirements_;
      return *this;
    }

    VulkanFunctions &setVkCreateBuffer(PFN_vkCreateBuffer vkCreateBuffer_) VKMA_NOEXCEPT {
      vkCreateBuffer = vkCreateBuffer_;
      return *this;
    }

    VulkanFunctions &setVkDestroyBuffer(PFN_vkDestroyBuffer vkDestroyBuffer_) VKMA_NOEXCEPT {
      vkDestroyBuffer = vkDestroyBuffer_;
      return *this;
    }

    VulkanFunctions &setVkCreateImage(PFN_vkCreateImage vkCreateImage_) VKMA_NOEXCEPT {
      vkCreateImage = vkCreateImage_;
      return *this;
    }

    VulkanFunctions &setVkDestroyImage(PFN_vkDestroyImage vkDestroyImage_) VKMA_NOEXCEPT {
      vkDestroyImage = vkDestroyImage_;
      return *this;
    }

    VulkanFunctions &setVkCmdCopyBuffer(PFN_vkCmdCopyBuffer vkCmdCopyBuffer_) VKMA_NOEXCEPT {
      vkCmdCopyBuffer = vkCmdCopyBuffer_;
      return *this;
    }

    VulkanFunctions &setVkGetBufferMemoryRequirements2KHR(
      PFN_vkGetBufferMemoryRequirements2KHR vkGetBufferMemoryRequirements2KHR_) VKMA_NOEXCEPT {
      vkGetBufferMemoryRequirements2KHR = vkGetBufferMemoryRequirements2KHR_;
      return *this;
    }

    VulkanFunctions &setVkGetImageMemoryRequirements2KHR(
      PFN_vkGetImageMemoryRequirements2KHR vkGetImageMemoryRequirements2KHR_) VKMA_NOEXCEPT {
      vkGetImageMemoryRequirements2KHR = vkGetImageMemoryRequirements2KHR_;
      return *this;
    }

    VulkanFunctions &setVkBindBufferMemory2KHR(PFN_vkBindBufferMemory2KHR vkBindBufferMemory2KHR_)
      VKMA_NOEXCEPT {
      vkBindBufferMemory2KHR = vkBindBufferMemory2KHR_;
      return *this;
    }

    VulkanFunctions &setVkBindImageMemory2KHR(PFN_vkBindImageMemory2KHR vkBindImageMemory2KHR_)
      VKMA_NOEXCEPT {
      vkBindImageMemory2KHR = vkBindImageMemory2KHR_;
      return *this;
    }

    VulkanFunctions &setVkGetPhysicalDeviceMemoryProperties2KHR(
      PFN_vkGetPhysicalDeviceMemoryProperties2KHR vkGetPhysicalDeviceMemoryProperties2KHR_)
      VKMA_NOEXCEPT {
      vkGetPhysicalDeviceMemoryProperties2KHR = vkGetPhysicalDeviceMemoryProperties2KHR_;
      return *this;
    }

    operator VkmaVulkanFunctions const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaVulkanFunctions *>(this);
    }

    operator VkmaVulkanFunctions &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaVulkanFunctions *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(VulkanFunctions const &) const = default;
#else
    bool operator==(VulkanFunctions const &rhs) const VKMA_NOEXCEPT {
      return (vkGetInstanceProcAddr == rhs.vkGetInstanceProcAddr)
          && (vkGetDeviceProcAddr == rhs.vkGetDeviceProcAddr)
          && (vkGetPhysicalDeviceProperties == rhs.vkGetPhysicalDeviceProperties)
          && (vkGetPhysicalDeviceMemoryProperties == rhs.vkGetPhysicalDeviceMemoryProperties)
          && (vkAllocateMemory == rhs.vkAllocateMemory) && (vkFreeMemory == rhs.vkFreeMemory)
          && (vkMapMemory == rhs.vkMapMemory) && (vkUnmapMemory == rhs.vkUnmapMemory)
          && (vkFlushMappedMemoryRanges == rhs.vkFlushMappedMemoryRanges)
          && (vkInvalidateMappedMemoryRanges == rhs.vkInvalidateMappedMemoryRanges)
          && (vkBindBufferMemory == rhs.vkBindBufferMemory)
          && (vkBindImageMemory == rhs.vkBindImageMemory)
          && (vkGetBufferMemoryRequirements == rhs.vkGetBufferMemoryRequirements)
          && (vkGetImageMemoryRequirements == rhs.vkGetImageMemoryRequirements)
          && (vkCreateBuffer == rhs.vkCreateBuffer) && (vkDestroyBuffer == rhs.vkDestroyBuffer)
          && (vkCreateImage == rhs.vkCreateImage) && (vkDestroyImage == rhs.vkDestroyImage)
          && (vkCmdCopyBuffer == rhs.vkCmdCopyBuffer)
          && (vkGetBufferMemoryRequirements2KHR == rhs.vkGetBufferMemoryRequirements2KHR)
          && (vkGetImageMemoryRequirements2KHR == rhs.vkGetImageMemoryRequirements2KHR)
          && (vkBindBufferMemory2KHR == rhs.vkBindBufferMemory2KHR)
          && (vkBindImageMemory2KHR == rhs.vkBindImageMemory2KHR)
          && (vkGetPhysicalDeviceMemoryProperties2KHR
              == rhs.vkGetPhysicalDeviceMemoryProperties2KHR);
    }

    bool operator!=(VulkanFunctions const &rhs) const VKMA_NOEXCEPT { return !operator==(rhs); }
#endif

  public:
    PFN_vkGetInstanceProcAddr vkGetInstanceProcAddr = {};
    PFN_vkGetDeviceProcAddr vkGetDeviceProcAddr = {};
    PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties = {};
    PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties = {};
    PFN_vkAllocateMemory vkAllocateMemory = {};
    PFN_vkFreeMemory vkFreeMemory = {};
    PFN_vkMapMemory vkMapMemory = {};
    PFN_vkUnmapMemory vkUnmapMemory = {};
    PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges = {};
    PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges = {};
    PFN_vkBindBufferMemory vkBindBufferMemory = {};
    PFN_vkBindImageMemory vkBindImageMemory = {};
    PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements = {};
    PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements = {};
    PFN_vkCreateBuffer vkCreateBuffer = {};
    PFN_vkDestroyBuffer vkDestroyBuffer = {};
    PFN_vkCreateImage vkCreateImage = {};
    PFN_vkDestroyImage vkDestroyImage = {};
    PFN_vkCmdCopyBuffer vkCmdCopyBuffer = {};
    PFN_vkGetBufferMemoryRequirements2KHR vkGetBufferMemoryRequirements2KHR = {};
    PFN_vkGetImageMemoryRequirements2KHR vkGetImageMemoryRequirements2KHR = {};
    PFN_vkBindBufferMemory2KHR vkBindBufferMemory2KHR = {};
    PFN_vkBindImageMemory2KHR vkBindImageMemory2KHR = {};
    PFN_vkGetPhysicalDeviceMemoryProperties2KHR vkGetPhysicalDeviceMemoryProperties2KHR = {};
  };
  static_assert(sizeof(VulkanFunctions) == sizeof(VkmaVulkanFunctions),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<VulkanFunctions>::value,
                "struct wrapper is not a standard layout!");

  struct AllocatorCreateInfo {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR AllocatorCreateInfo(AllocatorCreateFlags flags_ = {},
                                       VkPhysicalDevice physicalDevice_ = {}, VkDevice device_ = {},
                                       VkDeviceSize preferredLargeHeapBlockSize_ = {},
                                       const VkAllocationCallbacks *pAllocationCallbacks_ = {},
                                       const DeviceMemoryCallbacks *pDeviceMemoryCallbacks_ = {},
                                       const VulkanFunctions *pVulkanFunctions_ = {},
                                       VkInstance instance_ = {},
                                       uint32_t vulkanApiVersion_ = {}) VKMA_NOEXCEPT
      : flags(flags_),
        physicalDevice(physicalDevice_),
        device(device_),
        preferredLargeHeapBlockSize(preferredLargeHeapBlockSize_),
        pAllocationCallbacks(pAllocationCallbacks_),
        pDeviceMemoryCallbacks(pDeviceMemoryCallbacks_),
        pVulkanFunctions(pVulkanFunctions_),
        instance(instance_),
        vulkanApiVersion(vulkanApiVersion_) {}

    VKMA_CONSTEXPR AllocatorCreateInfo(AllocatorCreateInfo const &rhs) VKMA_NOEXCEPT = default;

    AllocatorCreateInfo(VkmaAllocatorCreateInfo const &rhs) VKMA_NOEXCEPT
      : AllocatorCreateInfo(*reinterpret_cast<AllocatorCreateInfo const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 AllocatorCreateInfo &operator=(AllocatorCreateInfo const &rhs)
      VKMA_NOEXCEPT = default;

    AllocatorCreateInfo &operator=(VkmaAllocatorCreateInfo const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::AllocatorCreateInfo const *>(&rhs);
      return *this;
    }

    AllocatorCreateInfo &setFlags(AllocatorCreateFlags flags_) VKMA_NOEXCEPT {
      flags = flags_;
      return *this;
    }

    AllocatorCreateInfo &setPhysicalDevice(VkPhysicalDevice physicalDevice_) VKMA_NOEXCEPT {
      physicalDevice = physicalDevice_;
      return *this;
    }

    AllocatorCreateInfo &setDevice(VkDevice device_) VKMA_NOEXCEPT {
      device = device_;
      return *this;
    }

    AllocatorCreateInfo &setPreferredLargeHeapBlockSize(VkDeviceSize preferredLargeHeapBlockSize_)
      VKMA_NOEXCEPT {
      preferredLargeHeapBlockSize = preferredLargeHeapBlockSize_;
      return *this;
    }

    AllocatorCreateInfo &setPAllocationCallbacks(const VkAllocationCallbacks *pAllocationCallbacks_)
      VKMA_NOEXCEPT {
      pAllocationCallbacks = pAllocationCallbacks_;
      return *this;
    }

    AllocatorCreateInfo &
    setPDeviceMemoryCallbacks(const DeviceMemoryCallbacks *pDeviceMemoryCallbacks_) VKMA_NOEXCEPT {
      pDeviceMemoryCallbacks = pDeviceMemoryCallbacks_;
      return *this;
    }

    AllocatorCreateInfo &setPVulkanFunctions(const VulkanFunctions *pVulkanFunctions_)
      VKMA_NOEXCEPT {
      pVulkanFunctions = pVulkanFunctions_;
      return *this;
    }

    AllocatorCreateInfo &setInstance(VkInstance instance_) VKMA_NOEXCEPT {
      instance = instance_;
      return *this;
    }

    AllocatorCreateInfo &setVulkanApiVersion(uint32_t vulkanApiVersion_) VKMA_NOEXCEPT {
      vulkanApiVersion = vulkanApiVersion_;
      return *this;
    }

    operator VkmaAllocatorCreateInfo const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaAllocatorCreateInfo *>(this);
    }

    operator VkmaAllocatorCreateInfo &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaAllocatorCreateInfo *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(AllocatorCreateInfo const &) const = default;
#else
    bool operator==(AllocatorCreateInfo const &rhs) const VKMA_NOEXCEPT {
      return (flags == rhs.flags) && (physicalDevice == rhs.physicalDevice)
          && (device == rhs.device)
          && (preferredLargeHeapBlockSize == rhs.preferredLargeHeapBlockSize)
          && (pAllocationCallbacks == rhs.pAllocationCallbacks)
          && (pDeviceMemoryCallbacks == rhs.pDeviceMemoryCallbacks)
          && (pVulkanFunctions == rhs.pVulkanFunctions) && (instance == rhs.instance)
          && (vulkanApiVersion == rhs.vulkanApiVersion);
    }

    bool operator!=(AllocatorCreateInfo const &rhs) const VKMA_NOEXCEPT { return !operator==(rhs); }
#endif

  public:
    AllocatorCreateFlags flags = {};
    VkPhysicalDevice physicalDevice = {};
    VkDevice device = {};
    VkDeviceSize preferredLargeHeapBlockSize = {};
    const VkAllocationCallbacks *pAllocationCallbacks = {};
    const DeviceMemoryCallbacks *pDeviceMemoryCallbacks = {};
    const VulkanFunctions *pVulkanFunctions = {};
    VkInstance instance = {};
    uint32_t vulkanApiVersion = {};
  };
  static_assert(sizeof(AllocatorCreateInfo) == sizeof(VkmaAllocatorCreateInfo),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<AllocatorCreateInfo>::value,
                "struct wrapper is not a standard layout!");

  struct Statistics {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR Statistics(uint32_t blockCount_ = {}, uint32_t allocationCount_ = {},
                              VkDeviceSize blockBytes_ = {},
                              VkDeviceSize allocationBytes_ = {}) VKMA_NOEXCEPT
      : blockCount(blockCount_),
        allocationCount(allocationCount_),
        blockBytes(blockBytes_),
        allocationBytes(allocationBytes_) {}

    VKMA_CONSTEXPR Statistics(Statistics const &rhs) VKMA_NOEXCEPT = default;

    Statistics(VkmaStatistics const &rhs) VKMA_NOEXCEPT
      : Statistics(*reinterpret_cast<Statistics const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 Statistics &operator=(Statistics const &rhs) VKMA_NOEXCEPT = default;

    Statistics &operator=(VkmaStatistics const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::Statistics const *>(&rhs);
      return *this;
    }

    Statistics &setBlockCount(uint32_t blockCount_) VKMA_NOEXCEPT {
      blockCount = blockCount_;
      return *this;
    }

    Statistics &setAllocationCount(uint32_t allocationCount_) VKMA_NOEXCEPT {
      allocationCount = allocationCount_;
      return *this;
    }

    Statistics &setBlockBytes(VkDeviceSize blockBytes_) VKMA_NOEXCEPT {
      blockBytes = blockBytes_;
      return *this;
    }

    Statistics &setAllocationBytes(VkDeviceSize allocationBytes_) VKMA_NOEXCEPT {
      allocationBytes = allocationBytes_;
      return *this;
    }

    operator VkmaStatistics const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaStatistics *>(this);
    }

    operator VkmaStatistics &() VKMA_NOEXCEPT { return *reinterpret_cast<VkmaStatistics *>(this); }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(Statistics const &) const = default;
#else
    bool operator==(Statistics const &rhs) const VKMA_NOEXCEPT {
      return (blockCount == rhs.blockCount) && (allocationCount == rhs.allocationCount)
          && (blockBytes == rhs.blockBytes) && (allocationBytes == rhs.allocationBytes);
    }

    bool operator!=(Statistics const &rhs) const VKMA_NOEXCEPT { return !operator==(rhs); }
#endif

  public:
    uint32_t blockCount = {};
    uint32_t allocationCount = {};
    VkDeviceSize blockBytes = {};
    VkDeviceSize allocationBytes = {};
  };
  static_assert(sizeof(Statistics) == sizeof(VkmaStatistics),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<Statistics>::value,
                "struct wrapper is not a standard layout!");

  struct Budget {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR Budget(Statistics statistics_ = {}, VkDeviceSize usage_ = {},
                          VkDeviceSize budget_ = {}) VKMA_NOEXCEPT : statistics(statistics_),
                                                                     usage(usage_),
                                                                     budget(budget_) {}

    VKMA_CONSTEXPR Budget(Budget const &rhs) VKMA_NOEXCEPT = default;

    Budget(VkmaBudget const &rhs) VKMA_NOEXCEPT : Budget(*reinterpret_cast<Budget const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 Budget &operator=(Budget const &rhs) VKMA_NOEXCEPT = default;

    Budget &operator=(VkmaBudget const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::Budget const *>(&rhs);
      return *this;
    }

    Budget &setStatistics(Statistics const &statistics_) VKMA_NOEXCEPT {
      statistics = statistics_;
      return *this;
    }

    Budget &setUsage(VkDeviceSize usage_) VKMA_NOEXCEPT {
      usage = usage_;
      return *this;
    }

    Budget &setBudget(VkDeviceSize budget_) VKMA_NOEXCEPT {
      budget = budget_;
      return *this;
    }

    operator VkmaBudget const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaBudget *>(this);
    }

    operator VkmaBudget &() VKMA_NOEXCEPT { return *reinterpret_cast<VkmaBudget *>(this); }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(Budget const &) const = default;
#else
    bool operator==(Budget const &rhs) const VKMA_NOEXCEPT {
      return (statistics == rhs.statistics) && (usage == rhs.usage) && (budget == rhs.budget);
    }

    bool operator!=(Budget const &rhs) const VKMA_NOEXCEPT { return !operator==(rhs); }
#endif

  public:
    Statistics statistics = {};
    VkDeviceSize usage = {};
    VkDeviceSize budget = {};
  };
  static_assert(sizeof(Budget) == sizeof(VkmaBudget), "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<Budget>::value, "struct wrapper is not a standard layout!");

  struct DefragmentationInfo {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR DefragmentationInfo(DefragmentationFlags flags_ = {}, Pool pool_ = {},
                                       VkDeviceSize maxBytesPerPass_ = {},
                                       uint32_t maxAllocationsPerPass_ = {}) VKMA_NOEXCEPT
      : flags(flags_),
        pool(pool_),
        maxBytesPerPass(maxBytesPerPass_),
        maxAllocationsPerPass(maxAllocationsPerPass_) {}

    VKMA_CONSTEXPR DefragmentationInfo(DefragmentationInfo const &rhs) VKMA_NOEXCEPT = default;

    DefragmentationInfo(VkmaDefragmentationInfo const &rhs) VKMA_NOEXCEPT
      : DefragmentationInfo(*reinterpret_cast<DefragmentationInfo const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 DefragmentationInfo &operator=(DefragmentationInfo const &rhs)
      VKMA_NOEXCEPT = default;

    DefragmentationInfo &operator=(VkmaDefragmentationInfo const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::DefragmentationInfo const *>(&rhs);
      return *this;
    }

    DefragmentationInfo &setFlags(DefragmentationFlags flags_) VKMA_NOEXCEPT {
      flags = flags_;
      return *this;
    }

    DefragmentationInfo &setPool(Pool pool_) VKMA_NOEXCEPT {
      pool = pool_;
      return *this;
    }

    DefragmentationInfo &setMaxBytesPerPass(VkDeviceSize maxBytesPerPass_) VKMA_NOEXCEPT {
      maxBytesPerPass = maxBytesPerPass_;
      return *this;
    }

    DefragmentationInfo &setMaxAllocationsPerPass(uint32_t maxAllocationsPerPass_) VKMA_NOEXCEPT {
      maxAllocationsPerPass = maxAllocationsPerPass_;
      return *this;
    }

    operator VkmaDefragmentationInfo const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaDefragmentationInfo *>(this);
    }

    operator VkmaDefragmentationInfo &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaDefragmentationInfo *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(DefragmentationInfo const &) const = default;
#else
    bool operator==(DefragmentationInfo const &rhs) const VKMA_NOEXCEPT {
      return (flags == rhs.flags) && (pool == rhs.pool) && (maxBytesPerPass == rhs.maxBytesPerPass)
          && (maxAllocationsPerPass == rhs.maxAllocationsPerPass);
    }

    bool operator!=(DefragmentationInfo const &rhs) const VKMA_NOEXCEPT { return !operator==(rhs); }
#endif

  public:
    DefragmentationFlags flags = {};
    Pool pool = {};
    VkDeviceSize maxBytesPerPass = {};
    uint32_t maxAllocationsPerPass = {};
  };
  static_assert(sizeof(DefragmentationInfo) == sizeof(VkmaDefragmentationInfo),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<DefragmentationInfo>::value,
                "struct wrapper is not a standard layout!");

  struct DefragmentationInfo2 {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR DefragmentationInfo2(DefragmentationFlags flags_ = {}, Pool pool_ = {},
                                        VkDeviceSize maxBytesPerPass_ = {},
                                        uint32_t maxAllocationsPerPass_ = {}) VKMA_NOEXCEPT
      : flags(flags_),
        pool(pool_),
        maxBytesPerPass(maxBytesPerPass_),
        maxAllocationsPerPass(maxAllocationsPerPass_) {}

    VKMA_CONSTEXPR DefragmentationInfo2(DefragmentationInfo2 const &rhs) VKMA_NOEXCEPT = default;

    DefragmentationInfo2(VkmaDefragmentationInfo2 const &rhs) VKMA_NOEXCEPT
      : DefragmentationInfo2(*reinterpret_cast<DefragmentationInfo2 const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 DefragmentationInfo2 &operator=(DefragmentationInfo2 const &rhs)
      VKMA_NOEXCEPT = default;

    DefragmentationInfo2 &operator=(VkmaDefragmentationInfo2 const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::DefragmentationInfo2 const *>(&rhs);
      return *this;
    }

    DefragmentationInfo2 &setFlags(DefragmentationFlags flags_) VKMA_NOEXCEPT {
      flags = flags_;
      return *this;
    }

    DefragmentationInfo2 &setPool(Pool pool_) VKMA_NOEXCEPT {
      pool = pool_;
      return *this;
    }

    DefragmentationInfo2 &setMaxBytesPerPass(VkDeviceSize maxBytesPerPass_) VKMA_NOEXCEPT {
      maxBytesPerPass = maxBytesPerPass_;
      return *this;
    }

    DefragmentationInfo2 &setMaxAllocationsPerPass(uint32_t maxAllocationsPerPass_) VKMA_NOEXCEPT {
      maxAllocationsPerPass = maxAllocationsPerPass_;
      return *this;
    }

    operator VkmaDefragmentationInfo2 const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaDefragmentationInfo2 *>(this);
    }

    operator VkmaDefragmentationInfo2 &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaDefragmentationInfo2 *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(DefragmentationInfo2 const &) const = default;
#else
    bool operator==(DefragmentationInfo2 const &rhs) const VKMA_NOEXCEPT {
      return (flags == rhs.flags) && (pool == rhs.pool) && (maxBytesPerPass == rhs.maxBytesPerPass)
          && (maxAllocationsPerPass == rhs.maxAllocationsPerPass);
    }

    bool operator!=(DefragmentationInfo2 const &rhs) const VKMA_NOEXCEPT {
      return !operator==(rhs);
    }
#endif

  public:
    DefragmentationFlags flags = {};
    Pool pool = {};
    VkDeviceSize maxBytesPerPass = {};
    uint32_t maxAllocationsPerPass = {};
  };
  static_assert(sizeof(DefragmentationInfo2) == sizeof(VkmaDefragmentationInfo2),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<DefragmentationInfo2>::value,
                "struct wrapper is not a standard layout!");

  class Allocation {
  public:
    using CType = VkmaAllocation;

  public:
    VKMA_CONSTEXPR Allocation() VKMA_NOEXCEPT : m_allocation(VKMA_NULL_HANDLE) {}

    VKMA_CONSTEXPR Allocation(std::nullptr_t) VKMA_NOEXCEPT : m_allocation(VKMA_NULL_HANDLE) {}

    VKMA_TYPESAFE_EXPLICIT Allocation(VkmaAllocation allocation) VKMA_NOEXCEPT
      : m_allocation(allocation) {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    Allocation &operator=(VkmaAllocation allocation) VKMA_NOEXCEPT {
      m_allocation = allocation;
      return *this;
    }
#endif

    Allocation &operator=(std::nullptr_t) VKMA_NOEXCEPT {
      m_allocation = VKMA_NULL_HANDLE;
      return *this;
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(Allocation const &) const = default;
#else
    bool operator==(Allocation const &rhs) const VKMA_NOEXCEPT {
      return m_allocation == rhs.m_allocation;
    }

    bool operator!=(Allocation const &rhs) const VKMA_NOEXCEPT {
      return m_allocation != rhs.m_allocation;
    }

    bool operator<(Allocation const &rhs) const VKMA_NOEXCEPT {
      return m_allocation < rhs.m_allocation;
    }
#endif

    VKMA_TYPESAFE_EXPLICIT operator VkmaAllocation() const VKMA_NOEXCEPT { return m_allocation; }

    explicit operator bool() const VKMA_NOEXCEPT { return m_allocation != VKMA_NULL_HANDLE; }

    bool operator!() const VKMA_NOEXCEPT { return m_allocation == VKMA_NULL_HANDLE; }

  private:
    VkmaAllocation m_allocation;
  };
  static_assert(sizeof(VKMA_NAMESPACE::Allocation) == sizeof(VkmaAllocation),
                "handle and wrapper have different size!");

  template <> struct isVulkanHandleType<VKMA_NAMESPACE::Allocation> {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

  struct DefragmentationMove {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR DefragmentationMove(
      DefragmentationMoveOperation operation_ = VKMA_NAMESPACE::DefragmentationMoveOperation::eCopy,
      Allocation srcAllocation_ = {}, Allocation dstTmpAllocation_ = {}) VKMA_NOEXCEPT
      : operation(operation_),
        srcAllocation(srcAllocation_),
        dstTmpAllocation(dstTmpAllocation_) {}

    VKMA_CONSTEXPR DefragmentationMove(DefragmentationMove const &rhs) VKMA_NOEXCEPT = default;

    DefragmentationMove(VkmaDefragmentationMove const &rhs) VKMA_NOEXCEPT
      : DefragmentationMove(*reinterpret_cast<DefragmentationMove const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 DefragmentationMove &operator=(DefragmentationMove const &rhs)
      VKMA_NOEXCEPT = default;

    DefragmentationMove &operator=(VkmaDefragmentationMove const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::DefragmentationMove const *>(&rhs);
      return *this;
    }

    DefragmentationMove &setOperation(DefragmentationMoveOperation operation_) VKMA_NOEXCEPT {
      operation = operation_;
      return *this;
    }

    DefragmentationMove &setSrcAllocation(Allocation srcAllocation_) VKMA_NOEXCEPT {
      srcAllocation = srcAllocation_;
      return *this;
    }

    DefragmentationMove &setDstTmpAllocation(Allocation dstTmpAllocation_) VKMA_NOEXCEPT {
      dstTmpAllocation = dstTmpAllocation_;
      return *this;
    }

    operator VkmaDefragmentationMove const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaDefragmentationMove *>(this);
    }

    operator VkmaDefragmentationMove &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaDefragmentationMove *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(DefragmentationMove const &) const = default;
#else
    bool operator==(DefragmentationMove const &rhs) const VKMA_NOEXCEPT {
      return (operation == rhs.operation) && (srcAllocation == rhs.srcAllocation)
          && (dstTmpAllocation == rhs.dstTmpAllocation);
    }

    bool operator!=(DefragmentationMove const &rhs) const VKMA_NOEXCEPT { return !operator==(rhs); }
#endif

  public:
    DefragmentationMoveOperation operation = VKMA_NAMESPACE::DefragmentationMoveOperation::eCopy;
    Allocation srcAllocation = {};
    Allocation dstTmpAllocation = {};
  };
  static_assert(sizeof(DefragmentationMove) == sizeof(VkmaDefragmentationMove),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<DefragmentationMove>::value,
                "struct wrapper is not a standard layout!");

  struct DefragmentationPassMoveInfo {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR DefragmentationPassMoveInfo(uint32_t moveCount_ = {},
                                               DefragmentationMove *pMoves_ = {}) VKMA_NOEXCEPT
      : moveCount(moveCount_),
        pMoves(pMoves_) {}

    VKMA_CONSTEXPR DefragmentationPassMoveInfo(DefragmentationPassMoveInfo const &rhs)
      VKMA_NOEXCEPT = default;

    DefragmentationPassMoveInfo(VkmaDefragmentationPassMoveInfo const &rhs) VKMA_NOEXCEPT
      : DefragmentationPassMoveInfo(*reinterpret_cast<DefragmentationPassMoveInfo const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 DefragmentationPassMoveInfo &operator=(DefragmentationPassMoveInfo const &rhs)
      VKMA_NOEXCEPT = default;

    DefragmentationPassMoveInfo &operator=(VkmaDefragmentationPassMoveInfo const &rhs)
      VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::DefragmentationPassMoveInfo const *>(&rhs);
      return *this;
    }

    DefragmentationPassMoveInfo &setMoveCount(uint32_t moveCount_) VKMA_NOEXCEPT {
      moveCount = moveCount_;
      return *this;
    }

    DefragmentationPassMoveInfo &setPMoves(DefragmentationMove *pMoves_) VKMA_NOEXCEPT {
      pMoves = pMoves_;
      return *this;
    }

    operator VkmaDefragmentationPassMoveInfo const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaDefragmentationPassMoveInfo *>(this);
    }

    operator VkmaDefragmentationPassMoveInfo &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaDefragmentationPassMoveInfo *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(DefragmentationPassMoveInfo const &) const = default;
#else
    bool operator==(DefragmentationPassMoveInfo const &rhs) const VKMA_NOEXCEPT {
      return (moveCount == rhs.moveCount) && (pMoves == rhs.pMoves);
    }

    bool operator!=(DefragmentationPassMoveInfo const &rhs) const VKMA_NOEXCEPT {
      return !operator==(rhs);
    }
#endif

  public:
    uint32_t moveCount = {};
    DefragmentationMove *pMoves = {};
  };
  static_assert(sizeof(DefragmentationPassMoveInfo) == sizeof(VkmaDefragmentationPassMoveInfo),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<DefragmentationPassMoveInfo>::value,
                "struct wrapper is not a standard layout!");

  struct DefragmentationStats {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR DefragmentationStats(VkDeviceSize bytesMoved_ = {},
                                        VkDeviceSize bytesFreed_ = {},
                                        uint32_t allocationsMoved_ = {},
                                        uint32_t deviceMemoryBlocksFreed_ = {}) VKMA_NOEXCEPT
      : bytesMoved(bytesMoved_),
        bytesFreed(bytesFreed_),
        allocationsMoved(allocationsMoved_),
        deviceMemoryBlocksFreed(deviceMemoryBlocksFreed_) {}

    VKMA_CONSTEXPR DefragmentationStats(DefragmentationStats const &rhs) VKMA_NOEXCEPT = default;

    DefragmentationStats(VkmaDefragmentationStats const &rhs) VKMA_NOEXCEPT
      : DefragmentationStats(*reinterpret_cast<DefragmentationStats const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 DefragmentationStats &operator=(DefragmentationStats const &rhs)
      VKMA_NOEXCEPT = default;

    DefragmentationStats &operator=(VkmaDefragmentationStats const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::DefragmentationStats const *>(&rhs);
      return *this;
    }

    DefragmentationStats &setBytesMoved(VkDeviceSize bytesMoved_) VKMA_NOEXCEPT {
      bytesMoved = bytesMoved_;
      return *this;
    }

    DefragmentationStats &setBytesFreed(VkDeviceSize bytesFreed_) VKMA_NOEXCEPT {
      bytesFreed = bytesFreed_;
      return *this;
    }

    DefragmentationStats &setAllocationsMoved(uint32_t allocationsMoved_) VKMA_NOEXCEPT {
      allocationsMoved = allocationsMoved_;
      return *this;
    }

    DefragmentationStats &setDeviceMemoryBlocksFreed(uint32_t deviceMemoryBlocksFreed_)
      VKMA_NOEXCEPT {
      deviceMemoryBlocksFreed = deviceMemoryBlocksFreed_;
      return *this;
    }

    operator VkmaDefragmentationStats const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaDefragmentationStats *>(this);
    }

    operator VkmaDefragmentationStats &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaDefragmentationStats *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(DefragmentationStats const &) const = default;
#else
    bool operator==(DefragmentationStats const &rhs) const VKMA_NOEXCEPT {
      return (bytesMoved == rhs.bytesMoved) && (bytesFreed == rhs.bytesFreed)
          && (allocationsMoved == rhs.allocationsMoved)
          && (deviceMemoryBlocksFreed == rhs.deviceMemoryBlocksFreed);
    }

    bool operator!=(DefragmentationStats const &rhs) const VKMA_NOEXCEPT {
      return !operator==(rhs);
    }
#endif

  public:
    VkDeviceSize bytesMoved = {};
    VkDeviceSize bytesFreed = {};
    uint32_t allocationsMoved = {};
    uint32_t deviceMemoryBlocksFreed = {};
  };
  static_assert(sizeof(DefragmentationStats) == sizeof(VkmaDefragmentationStats),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<DefragmentationStats>::value,
                "struct wrapper is not a standard layout!");

  struct DetailedStatistics {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR DetailedStatistics(Statistics statistics_ = {}, uint32_t unusedRangeCount_ = {},
                                      VkDeviceSize allocationSizeMin_ = {},
                                      VkDeviceSize allocationSizeMax_ = {},
                                      VkDeviceSize unusedRangeSizeMin_ = {},
                                      VkDeviceSize unusedRangeSizeMax_ = {}) VKMA_NOEXCEPT
      : statistics(statistics_),
        unusedRangeCount(unusedRangeCount_),
        allocationSizeMin(allocationSizeMin_),
        allocationSizeMax(allocationSizeMax_),
        unusedRangeSizeMin(unusedRangeSizeMin_),
        unusedRangeSizeMax(unusedRangeSizeMax_) {}

    VKMA_CONSTEXPR DetailedStatistics(DetailedStatistics const &rhs) VKMA_NOEXCEPT = default;

    DetailedStatistics(VkmaDetailedStatistics const &rhs) VKMA_NOEXCEPT
      : DetailedStatistics(*reinterpret_cast<DetailedStatistics const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 DetailedStatistics &operator=(DetailedStatistics const &rhs)
      VKMA_NOEXCEPT = default;

    DetailedStatistics &operator=(VkmaDetailedStatistics const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::DetailedStatistics const *>(&rhs);
      return *this;
    }

    DetailedStatistics &setStatistics(Statistics const &statistics_) VKMA_NOEXCEPT {
      statistics = statistics_;
      return *this;
    }

    DetailedStatistics &setUnusedRangeCount(uint32_t unusedRangeCount_) VKMA_NOEXCEPT {
      unusedRangeCount = unusedRangeCount_;
      return *this;
    }

    DetailedStatistics &setAllocationSizeMin(VkDeviceSize allocationSizeMin_) VKMA_NOEXCEPT {
      allocationSizeMin = allocationSizeMin_;
      return *this;
    }

    DetailedStatistics &setAllocationSizeMax(VkDeviceSize allocationSizeMax_) VKMA_NOEXCEPT {
      allocationSizeMax = allocationSizeMax_;
      return *this;
    }

    DetailedStatistics &setUnusedRangeSizeMin(VkDeviceSize unusedRangeSizeMin_) VKMA_NOEXCEPT {
      unusedRangeSizeMin = unusedRangeSizeMin_;
      return *this;
    }

    DetailedStatistics &setUnusedRangeSizeMax(VkDeviceSize unusedRangeSizeMax_) VKMA_NOEXCEPT {
      unusedRangeSizeMax = unusedRangeSizeMax_;
      return *this;
    }

    operator VkmaDetailedStatistics const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaDetailedStatistics *>(this);
    }

    operator VkmaDetailedStatistics &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaDetailedStatistics *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(DetailedStatistics const &) const = default;
#else
    bool operator==(DetailedStatistics const &rhs) const VKMA_NOEXCEPT {
      return (statistics == rhs.statistics) && (unusedRangeCount == rhs.unusedRangeCount)
          && (allocationSizeMin == rhs.allocationSizeMin)
          && (allocationSizeMax == rhs.allocationSizeMax)
          && (unusedRangeSizeMin == rhs.unusedRangeSizeMin)
          && (unusedRangeSizeMax == rhs.unusedRangeSizeMax);
    }

    bool operator!=(DetailedStatistics const &rhs) const VKMA_NOEXCEPT { return !operator==(rhs); }
#endif

  public:
    Statistics statistics = {};
    uint32_t unusedRangeCount = {};
    VkDeviceSize allocationSizeMin = {};
    VkDeviceSize allocationSizeMax = {};
    VkDeviceSize unusedRangeSizeMin = {};
    VkDeviceSize unusedRangeSizeMax = {};
  };
  static_assert(sizeof(DetailedStatistics) == sizeof(VkmaDetailedStatistics),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<DetailedStatistics>::value,
                "struct wrapper is not a standard layout!");

  struct PoolCreateInfo {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR PoolCreateInfo(uint32_t memoryTypeIndex_ = {}, PoolCreateFlags flags_ = {},
                                  VkDeviceSize blockSize_ = {}, size_t minBlockCount_ = {},
                                  size_t maxBlockCount_ = {}, float priority_ = {},
                                  VkDeviceSize minAllocationAlignment_ = {},
                                  void *pMemoryAllocateNext_ = {}) VKMA_NOEXCEPT
      : memoryTypeIndex(memoryTypeIndex_),
        flags(flags_),
        blockSize(blockSize_),
        minBlockCount(minBlockCount_),
        maxBlockCount(maxBlockCount_),
        priority(priority_),
        minAllocationAlignment(minAllocationAlignment_),
        pMemoryAllocateNext(pMemoryAllocateNext_) {}

    VKMA_CONSTEXPR PoolCreateInfo(PoolCreateInfo const &rhs) VKMA_NOEXCEPT = default;

    PoolCreateInfo(VkmaPoolCreateInfo const &rhs) VKMA_NOEXCEPT
      : PoolCreateInfo(*reinterpret_cast<PoolCreateInfo const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 PoolCreateInfo &operator=(PoolCreateInfo const &rhs) VKMA_NOEXCEPT = default;

    PoolCreateInfo &operator=(VkmaPoolCreateInfo const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::PoolCreateInfo const *>(&rhs);
      return *this;
    }

    PoolCreateInfo &setMemoryTypeIndex(uint32_t memoryTypeIndex_) VKMA_NOEXCEPT {
      memoryTypeIndex = memoryTypeIndex_;
      return *this;
    }

    PoolCreateInfo &setFlags(PoolCreateFlags flags_) VKMA_NOEXCEPT {
      flags = flags_;
      return *this;
    }

    PoolCreateInfo &setBlockSize(VkDeviceSize blockSize_) VKMA_NOEXCEPT {
      blockSize = blockSize_;
      return *this;
    }

    PoolCreateInfo &setMinBlockCount(size_t minBlockCount_) VKMA_NOEXCEPT {
      minBlockCount = minBlockCount_;
      return *this;
    }

    PoolCreateInfo &setMaxBlockCount(size_t maxBlockCount_) VKMA_NOEXCEPT {
      maxBlockCount = maxBlockCount_;
      return *this;
    }

    PoolCreateInfo &setPriority(float priority_) VKMA_NOEXCEPT {
      priority = priority_;
      return *this;
    }

    PoolCreateInfo &setMinAllocationAlignment(VkDeviceSize minAllocationAlignment_) VKMA_NOEXCEPT {
      minAllocationAlignment = minAllocationAlignment_;
      return *this;
    }

    PoolCreateInfo &setPMemoryAllocateNext(void *pMemoryAllocateNext_) VKMA_NOEXCEPT {
      pMemoryAllocateNext = pMemoryAllocateNext_;
      return *this;
    }

    operator VkmaPoolCreateInfo const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaPoolCreateInfo *>(this);
    }

    operator VkmaPoolCreateInfo &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaPoolCreateInfo *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(PoolCreateInfo const &) const = default;
#else
    bool operator==(PoolCreateInfo const &rhs) const VKMA_NOEXCEPT {
      return (memoryTypeIndex == rhs.memoryTypeIndex) && (flags == rhs.flags)
          && (blockSize == rhs.blockSize) && (minBlockCount == rhs.minBlockCount)
          && (maxBlockCount == rhs.maxBlockCount) && (priority == rhs.priority)
          && (minAllocationAlignment == rhs.minAllocationAlignment)
          && (pMemoryAllocateNext == rhs.pMemoryAllocateNext);
    }

    bool operator!=(PoolCreateInfo const &rhs) const VKMA_NOEXCEPT { return !operator==(rhs); }
#endif

  public:
    uint32_t memoryTypeIndex = {};
    PoolCreateFlags flags = {};
    VkDeviceSize blockSize = {};
    size_t minBlockCount = {};
    size_t maxBlockCount = {};
    float priority = {};
    VkDeviceSize minAllocationAlignment = {};
    void *pMemoryAllocateNext = {};
  };
  static_assert(sizeof(PoolCreateInfo) == sizeof(VkmaPoolCreateInfo),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<PoolCreateInfo>::value,
                "struct wrapper is not a standard layout!");

  struct TotalStatistics {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR_14
    TotalStatistics(std::array<DetailedStatistics, VK_MAX_MEMORY_TYPES> const &memoryType_ = {},
                    std::array<DetailedStatistics, VK_MAX_MEMORY_TYPES> const &memoryHeap_ = {},
                    DetailedStatistics total_ = {}) VKMA_NOEXCEPT : memoryType(memoryType_),
                                                                    memoryHeap(memoryHeap_),
                                                                    total(total_) {}

    VKMA_CONSTEXPR_14 TotalStatistics(TotalStatistics const &rhs) VKMA_NOEXCEPT = default;

    TotalStatistics(VkmaTotalStatistics const &rhs) VKMA_NOEXCEPT
      : TotalStatistics(*reinterpret_cast<TotalStatistics const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 TotalStatistics &operator=(TotalStatistics const &rhs)
      VKMA_NOEXCEPT = default;

    TotalStatistics &operator=(VkmaTotalStatistics const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::TotalStatistics const *>(&rhs);
      return *this;
    }

    TotalStatistics &setMemoryType(
      std::array<DetailedStatistics, VK_MAX_MEMORY_TYPES> const &memoryType_) VKMA_NOEXCEPT {
      memoryType = memoryType_;
      return *this;
    }

    TotalStatistics &setMemoryHeap(
      std::array<DetailedStatistics, VK_MAX_MEMORY_TYPES> const &memoryHeap_) VKMA_NOEXCEPT {
      memoryHeap = memoryHeap_;
      return *this;
    }

    TotalStatistics &setTotal(DetailedStatistics const &total_) VKMA_NOEXCEPT {
      total = total_;
      return *this;
    }

    operator VkmaTotalStatistics const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaTotalStatistics *>(this);
    }

    operator VkmaTotalStatistics &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaTotalStatistics *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(TotalStatistics const &) const = default;
#else
    bool operator==(TotalStatistics const &rhs) const VKMA_NOEXCEPT {
      return (memoryType == rhs.memoryType) && (memoryHeap == rhs.memoryHeap)
          && (total == rhs.total);
    }

    bool operator!=(TotalStatistics const &rhs) const VKMA_NOEXCEPT { return !operator==(rhs); }
#endif

  public:
    VKMA_NAMESPACE::ArrayWrapper1D<DetailedStatistics, VK_MAX_MEMORY_TYPES> memoryType = {};
    VKMA_NAMESPACE::ArrayWrapper1D<DetailedStatistics, VK_MAX_MEMORY_TYPES> memoryHeap = {};
    DetailedStatistics total = {};
  };
  static_assert(sizeof(TotalStatistics) == sizeof(VkmaTotalStatistics),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<TotalStatistics>::value,
                "struct wrapper is not a standard layout!");

  struct VirtualAllocationCreateInfo {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR VirtualAllocationCreateInfo(VkDeviceSize size_ = {},
                                               VkDeviceSize alignment_ = {},
                                               VirtualAllocationCreateFlags flags_ = {},
                                               void *pUserData_ = {}) VKMA_NOEXCEPT
      : size(size_),
        alignment(alignment_),
        flags(flags_),
        pUserData(pUserData_) {}

    VKMA_CONSTEXPR VirtualAllocationCreateInfo(VirtualAllocationCreateInfo const &rhs)
      VKMA_NOEXCEPT = default;

    VirtualAllocationCreateInfo(VkmaVirtualAllocationCreateInfo const &rhs) VKMA_NOEXCEPT
      : VirtualAllocationCreateInfo(*reinterpret_cast<VirtualAllocationCreateInfo const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 VirtualAllocationCreateInfo &operator=(VirtualAllocationCreateInfo const &rhs)
      VKMA_NOEXCEPT = default;

    VirtualAllocationCreateInfo &operator=(VkmaVirtualAllocationCreateInfo const &rhs)
      VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::VirtualAllocationCreateInfo const *>(&rhs);
      return *this;
    }

    VirtualAllocationCreateInfo &setSize(VkDeviceSize size_) VKMA_NOEXCEPT {
      size = size_;
      return *this;
    }

    VirtualAllocationCreateInfo &setAlignment(VkDeviceSize alignment_) VKMA_NOEXCEPT {
      alignment = alignment_;
      return *this;
    }

    VirtualAllocationCreateInfo &setFlags(VirtualAllocationCreateFlags flags_) VKMA_NOEXCEPT {
      flags = flags_;
      return *this;
    }

    VirtualAllocationCreateInfo &setPUserData(void *pUserData_) VKMA_NOEXCEPT {
      pUserData = pUserData_;
      return *this;
    }

    operator VkmaVirtualAllocationCreateInfo const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaVirtualAllocationCreateInfo *>(this);
    }

    operator VkmaVirtualAllocationCreateInfo &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaVirtualAllocationCreateInfo *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(VirtualAllocationCreateInfo const &) const = default;
#else
    bool operator==(VirtualAllocationCreateInfo const &rhs) const VKMA_NOEXCEPT {
      return (size == rhs.size) && (alignment == rhs.alignment) && (flags == rhs.flags)
          && (pUserData == rhs.pUserData);
    }

    bool operator!=(VirtualAllocationCreateInfo const &rhs) const VKMA_NOEXCEPT {
      return !operator==(rhs);
    }
#endif

  public:
    VkDeviceSize size = {};
    VkDeviceSize alignment = {};
    VirtualAllocationCreateFlags flags = {};
    void *pUserData = {};
  };
  static_assert(sizeof(VirtualAllocationCreateInfo) == sizeof(VkmaVirtualAllocationCreateInfo),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<VirtualAllocationCreateInfo>::value,
                "struct wrapper is not a standard layout!");

  struct VirtualAllocationInfo {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR VirtualAllocationInfo(VkDeviceSize offset_ = {}, VkDeviceSize size_ = {},
                                         void *pUserData_ = {}) VKMA_NOEXCEPT
      : offset(offset_),
        size(size_),
        pUserData(pUserData_) {}

    VKMA_CONSTEXPR VirtualAllocationInfo(VirtualAllocationInfo const &rhs) VKMA_NOEXCEPT = default;

    VirtualAllocationInfo(VkmaVirtualAllocationInfo const &rhs) VKMA_NOEXCEPT
      : VirtualAllocationInfo(*reinterpret_cast<VirtualAllocationInfo const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 VirtualAllocationInfo &operator=(VirtualAllocationInfo const &rhs)
      VKMA_NOEXCEPT = default;

    VirtualAllocationInfo &operator=(VkmaVirtualAllocationInfo const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::VirtualAllocationInfo const *>(&rhs);
      return *this;
    }

    VirtualAllocationInfo &setOffset(VkDeviceSize offset_) VKMA_NOEXCEPT {
      offset = offset_;
      return *this;
    }

    VirtualAllocationInfo &setSize(VkDeviceSize size_) VKMA_NOEXCEPT {
      size = size_;
      return *this;
    }

    VirtualAllocationInfo &setPUserData(void *pUserData_) VKMA_NOEXCEPT {
      pUserData = pUserData_;
      return *this;
    }

    operator VkmaVirtualAllocationInfo const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaVirtualAllocationInfo *>(this);
    }

    operator VkmaVirtualAllocationInfo &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaVirtualAllocationInfo *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(VirtualAllocationInfo const &) const = default;
#else
    bool operator==(VirtualAllocationInfo const &rhs) const VKMA_NOEXCEPT {
      return (offset == rhs.offset) && (size == rhs.size) && (pUserData == rhs.pUserData);
    }

    bool operator!=(VirtualAllocationInfo const &rhs) const VKMA_NOEXCEPT {
      return !operator==(rhs);
    }
#endif

  public:
    VkDeviceSize offset = {};
    VkDeviceSize size = {};
    void *pUserData = {};
  };
  static_assert(sizeof(VirtualAllocationInfo) == sizeof(VkmaVirtualAllocationInfo),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<VirtualAllocationInfo>::value,
                "struct wrapper is not a standard layout!");

  struct VirtualBlockCreateInfo {
#if !defined(VKMA_NO_STRUCT_CONSTRUCTORS)
    VKMA_CONSTEXPR
    VirtualBlockCreateInfo(VkDeviceSize size_ = {}, VirtualBlockCreateFlags flags_ = {},
                           const VkAllocationCallbacks *pAllocationCallbacks_ = {}) VKMA_NOEXCEPT
      : size(size_),
        flags(flags_),
        pAllocationCallbacks(pAllocationCallbacks_) {}

    VKMA_CONSTEXPR VirtualBlockCreateInfo(VirtualBlockCreateInfo const &rhs)
      VKMA_NOEXCEPT = default;

    VirtualBlockCreateInfo(VkmaVirtualBlockCreateInfo const &rhs) VKMA_NOEXCEPT
      : VirtualBlockCreateInfo(*reinterpret_cast<VirtualBlockCreateInfo const *>(&rhs)) {}
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VKMA_CONSTEXPR_14 VirtualBlockCreateInfo &operator=(VirtualBlockCreateInfo const &rhs)
      VKMA_NOEXCEPT = default;

    VirtualBlockCreateInfo &operator=(VkmaVirtualBlockCreateInfo const &rhs) VKMA_NOEXCEPT {
      *this = *reinterpret_cast<VKMA_NAMESPACE::VirtualBlockCreateInfo const *>(&rhs);
      return *this;
    }

    VirtualBlockCreateInfo &setSize(VkDeviceSize size_) VKMA_NOEXCEPT {
      size = size_;
      return *this;
    }

    VirtualBlockCreateInfo &setFlags(VirtualBlockCreateFlags flags_) VKMA_NOEXCEPT {
      flags = flags_;
      return *this;
    }

    VirtualBlockCreateInfo &
    setPAllocationCallbacks(const VkAllocationCallbacks *pAllocationCallbacks_) VKMA_NOEXCEPT {
      pAllocationCallbacks = pAllocationCallbacks_;
      return *this;
    }

    operator VkmaVirtualBlockCreateInfo const &() const VKMA_NOEXCEPT {
      return *reinterpret_cast<const VkmaVirtualBlockCreateInfo *>(this);
    }

    operator VkmaVirtualBlockCreateInfo &() VKMA_NOEXCEPT {
      return *reinterpret_cast<VkmaVirtualBlockCreateInfo *>(this);
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(VirtualBlockCreateInfo const &) const = default;
#else
    bool operator==(VirtualBlockCreateInfo const &rhs) const VKMA_NOEXCEPT {
      return (size == rhs.size) && (flags == rhs.flags)
          && (pAllocationCallbacks == rhs.pAllocationCallbacks);
    }

    bool operator!=(VirtualBlockCreateInfo const &rhs) const VKMA_NOEXCEPT {
      return !operator==(rhs);
    }
#endif

  public:
    VkDeviceSize size = {};
    VirtualBlockCreateFlags flags = {};
    const VkAllocationCallbacks *pAllocationCallbacks = {};
  };
  static_assert(sizeof(VirtualBlockCreateInfo) == sizeof(VkmaVirtualBlockCreateInfo),
                "struct and wrapper have different size!");
  static_assert(std::is_standard_layout<VirtualBlockCreateInfo>::value,
                "struct wrapper is not a standard layout!");

  class DefragmentationContext {
  public:
    using CType = VkmaDefragmentationContext;

  public:
    VKMA_CONSTEXPR DefragmentationContext() VKMA_NOEXCEPT
      : m_defragmentationContext(VKMA_NULL_HANDLE) {}

    VKMA_CONSTEXPR DefragmentationContext(std::nullptr_t) VKMA_NOEXCEPT
      : m_defragmentationContext(VKMA_NULL_HANDLE) {}

    VKMA_TYPESAFE_EXPLICIT DefragmentationContext(VkmaDefragmentationContext defragmentationContext)
      VKMA_NOEXCEPT : m_defragmentationContext(defragmentationContext) {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    DefragmentationContext &operator=(VkmaDefragmentationContext defragmentationContext)
      VKMA_NOEXCEPT {
      m_defragmentationContext = defragmentationContext;
      return *this;
    }
#endif

    DefragmentationContext &operator=(std::nullptr_t) VKMA_NOEXCEPT {
      m_defragmentationContext = VKMA_NULL_HANDLE;
      return *this;
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(DefragmentationContext const &) const = default;
#else
    bool operator==(DefragmentationContext const &rhs) const VKMA_NOEXCEPT {
      return m_defragmentationContext == rhs.m_defragmentationContext;
    }

    bool operator!=(DefragmentationContext const &rhs) const VKMA_NOEXCEPT {
      return m_defragmentationContext != rhs.m_defragmentationContext;
    }

    bool operator<(DefragmentationContext const &rhs) const VKMA_NOEXCEPT {
      return m_defragmentationContext < rhs.m_defragmentationContext;
    }
#endif

    VKMA_TYPESAFE_EXPLICIT operator VkmaDefragmentationContext() const VKMA_NOEXCEPT {
      return m_defragmentationContext;
    }

    explicit operator bool() const VKMA_NOEXCEPT {
      return m_defragmentationContext != VKMA_NULL_HANDLE;
    }

    bool operator!() const VKMA_NOEXCEPT { return m_defragmentationContext == VKMA_NULL_HANDLE; }

  private:
    VkmaDefragmentationContext m_defragmentationContext;
  };
  static_assert(sizeof(VKMA_NAMESPACE::DefragmentationContext)
                  == sizeof(VkmaDefragmentationContext),
                "handle and wrapper have different size!");

  template <> struct isVulkanHandleType<VKMA_NAMESPACE::DefragmentationContext> {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

  class Buffer {
  public:
    using CType = VkmaBuffer;

  public:
    VKMA_CONSTEXPR Buffer() VKMA_NOEXCEPT : m_buffer(VKMA_NULL_HANDLE) {}

    VKMA_CONSTEXPR Buffer(std::nullptr_t) VKMA_NOEXCEPT : m_buffer(VKMA_NULL_HANDLE) {}

    VKMA_TYPESAFE_EXPLICIT Buffer(VkmaBuffer buffer) VKMA_NOEXCEPT : m_buffer(buffer) {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    Buffer &operator=(VkmaBuffer buffer) VKMA_NOEXCEPT {
      m_buffer = buffer;
      return *this;
    }
#endif

    Buffer &operator=(std::nullptr_t) VKMA_NOEXCEPT {
      m_buffer = VKMA_NULL_HANDLE;
      return *this;
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(Buffer const &) const = default;
#else
    bool operator==(Buffer const &rhs) const VKMA_NOEXCEPT { return m_buffer == rhs.m_buffer; }

    bool operator!=(Buffer const &rhs) const VKMA_NOEXCEPT { return m_buffer != rhs.m_buffer; }

    bool operator<(Buffer const &rhs) const VKMA_NOEXCEPT { return m_buffer < rhs.m_buffer; }
#endif

    void get(VkBuffer *pBuffer) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VkBuffer get() const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void getAllocation(Allocation *pAllocation) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VKMA_NAMESPACE::Allocation getAllocation() const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_TYPESAFE_EXPLICIT operator VkmaBuffer() const VKMA_NOEXCEPT { return m_buffer; }

    explicit operator bool() const VKMA_NOEXCEPT { return m_buffer != VKMA_NULL_HANDLE; }

    bool operator!() const VKMA_NOEXCEPT { return m_buffer == VKMA_NULL_HANDLE; }

  private:
    VkmaBuffer m_buffer;
  };
  static_assert(sizeof(VKMA_NAMESPACE::Buffer) == sizeof(VkmaBuffer),
                "handle and wrapper have different size!");

  template <> struct isVulkanHandleType<VKMA_NAMESPACE::Buffer> {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

  class Image {
  public:
    using CType = VkmaImage;

  public:
    VKMA_CONSTEXPR Image() VKMA_NOEXCEPT : m_image(VKMA_NULL_HANDLE) {}

    VKMA_CONSTEXPR Image(std::nullptr_t) VKMA_NOEXCEPT : m_image(VKMA_NULL_HANDLE) {}

    VKMA_TYPESAFE_EXPLICIT Image(VkmaImage image) VKMA_NOEXCEPT : m_image(image) {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    Image &operator=(VkmaImage image) VKMA_NOEXCEPT {
      m_image = image;
      return *this;
    }
#endif

    Image &operator=(std::nullptr_t) VKMA_NOEXCEPT {
      m_image = VKMA_NULL_HANDLE;
      return *this;
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(Image const &) const = default;
#else
    bool operator==(Image const &rhs) const VKMA_NOEXCEPT { return m_image == rhs.m_image; }

    bool operator!=(Image const &rhs) const VKMA_NOEXCEPT { return m_image != rhs.m_image; }

    bool operator<(Image const &rhs) const VKMA_NOEXCEPT { return m_image < rhs.m_image; }
#endif

    void get(VkImage *pImage) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VkImage get() const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void getAllocation(Allocation *pAllocation) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VKMA_NAMESPACE::Allocation getAllocation() const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_TYPESAFE_EXPLICIT operator VkmaImage() const VKMA_NOEXCEPT { return m_image; }

    explicit operator bool() const VKMA_NOEXCEPT { return m_image != VKMA_NULL_HANDLE; }

    bool operator!() const VKMA_NOEXCEPT { return m_image == VKMA_NULL_HANDLE; }

  private:
    VkmaImage m_image;
  };
  static_assert(sizeof(VKMA_NAMESPACE::Image) == sizeof(VkmaImage),
                "handle and wrapper have different size!");

  template <> struct isVulkanHandleType<VKMA_NAMESPACE::Image> {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

#ifndef VKMA_NO_SMART_HANDLE
  class Allocator;
  template <> class UniqueHandleTraits<Allocation> {
  public:
    using deleter = ObjectFree<Allocator>;
  };
  using UniqueAllocation = UniqueHandle<Allocation>;
  template <> class UniqueHandleTraits<Buffer> {
  public:
    using deleter = ObjectDestroy<Allocator>;
  };
  using UniqueBuffer = UniqueHandle<Buffer>;
  template <> class UniqueHandleTraits<Image> {
  public:
    using deleter = ObjectDestroy<Allocator>;
  };
  using UniqueImage = UniqueHandle<Image>;
  template <> class UniqueHandleTraits<Pool> {
  public:
    using deleter = ObjectDestroy<Allocator>;
  };
  using UniquePool = UniqueHandle<Pool>;
#endif /*VKMA_NO_SMART_HANDLE*/

  class Allocator {
  public:
    using CType = VkmaAllocator;

  public:
    VKMA_CONSTEXPR Allocator() VKMA_NOEXCEPT : m_allocator(VKMA_NULL_HANDLE) {}

    VKMA_CONSTEXPR Allocator(std::nullptr_t) VKMA_NOEXCEPT : m_allocator(VKMA_NULL_HANDLE) {}

    VKMA_TYPESAFE_EXPLICIT Allocator(VkmaAllocator allocator) VKMA_NOEXCEPT
      : m_allocator(allocator) {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    Allocator &operator=(VkmaAllocator allocator) VKMA_NOEXCEPT {
      m_allocator = allocator;
      return *this;
    }
#endif

    Allocator &operator=(std::nullptr_t) VKMA_NOEXCEPT {
      m_allocator = VKMA_NULL_HANDLE;
      return *this;
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(Allocator const &) const = default;
#else
    bool operator==(Allocator const &rhs) const VKMA_NOEXCEPT {
      return m_allocator == rhs.m_allocator;
    }

    bool operator!=(Allocator const &rhs) const VKMA_NOEXCEPT {
      return m_allocator != rhs.m_allocator;
    }

    bool operator<(Allocator const &rhs) const VKMA_NOEXCEPT {
      return m_allocator < rhs.m_allocator;
    }
#endif

    VKMA_NODISCARD Result allocateMemory(const VkMemoryRequirements *pVkMemoryRequirements,
                                         const AllocationCreateInfo *pCreateInfo,
                                         Allocation *pAllocation) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Allocation>::type
    allocateMemory(const VkMemoryRequirements &vkMemoryRequirements,
                   const AllocationCreateInfo &createInfo) const;
  #ifndef VKMA_NO_SMART_HANDLE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
      typename ResultValueType<UniqueHandle<Allocation>>::type
      allocateMemoryUnique(const VkMemoryRequirements &vkMemoryRequirements,
                           const AllocationCreateInfo &createInfo) const;
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result allocateMemoryForBuffer(VkBuffer buffer,
                                                  const AllocationCreateInfo *pCreateInfo,
                                                  Allocation *pAllocation) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Allocation>::type
    allocateMemoryForBuffer(VkBuffer buffer, const AllocationCreateInfo &createInfo) const;
  #ifndef VKMA_NO_SMART_HANDLE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
      typename ResultValueType<UniqueHandle<Allocation>>::type
      allocateMemoryForBufferUnique(VkBuffer buffer, const AllocationCreateInfo &createInfo) const;
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result allocateMemoryForImage(VkImage image,
                                                 const AllocationCreateInfo *pCreateInfo,
                                                 Allocation *pAllocation) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Allocation>::type
    allocateMemoryForImage(VkImage image, const AllocationCreateInfo &createInfo) const;
  #ifndef VKMA_NO_SMART_HANDLE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
      typename ResultValueType<UniqueHandle<Allocation>>::type
      allocateMemoryForImageUnique(VkImage image, const AllocationCreateInfo &createInfo) const;
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result allocateMemoryPages(const VkMemoryRequirements *pVkMemoryRequirements,
                                              const AllocationCreateInfo *pCreateInfo,
                                              size_t allocationCount,
                                              Allocation *pAllocations) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Allocation>::type
    allocateMemoryPages(const VkMemoryRequirements &vkMemoryRequirements,
                        const AllocationCreateInfo &createInfo, size_t allocationCount) const;
  #ifndef VKMA_NO_SMART_HANDLE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
      typename ResultValueType<UniqueHandle<Allocation>>::type
      allocateMemoryPagesUnique(const VkMemoryRequirements &vkMemoryRequirements,
                                const AllocationCreateInfo &createInfo,
                                size_t allocationCount) const;
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result beginDefragmentation(
      const DefragmentationInfo *pInfo, DefragmentationContext *pContext) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<DefragmentationContext>::type
    beginDefragmentation(const DefragmentationInfo &info) const;
  #ifndef VKMA_NO_SMART_HANDLE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
      typename ResultValueType<UniqueHandle<DefragmentationContext>>::type
      beginDefragmentationUnique(const DefragmentationInfo &info) const;
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result
    beginDefragmentationPass(DefragmentationContext pContext,
                             const DefragmentationPassMoveInfo *pPassInfo) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type beginDefragmentationPass(
      DefragmentationContext pContext, const DefragmentationPassMoveInfo &passInfo) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD Result bindBufferMemory(Allocation allocation,
                                           VkBuffer buffer) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type
    bindBufferMemory(Allocation allocation, VkBuffer buffer) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD Result bindBufferMemory2(Allocation allocation,
                                            VkDeviceSize allocationLocalOffset, VkBuffer buffer,
                                            const void *pNext) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type
    bindBufferMemory2(Allocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer,
                      const void *pNext) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD Result bindImageMemory(Allocation allocation, VkImage image) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type
    bindImageMemory(Allocation allocation, VkImage image) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD Result bindImageMemory2(Allocation allocation,
                                           VkDeviceSize allocationLocalOffset, VkImage image,
                                           const void *pNext) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type
    bindImageMemory2(Allocation allocation, VkDeviceSize allocationLocalOffset, VkImage image,
                     const void *pNext) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void buildStatsString(VkBool32 detailedMap, char **ppStatsString) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD char *buildStatsString(VkBool32 detailedMap) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void calculatePoolStatistics(Pool pool, DetailedStatistics *pPoolStats) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VKMA_NAMESPACE::DetailedStatistics
    calculatePoolStatistics(Pool pool) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void calculateStatistics(TotalStatistics *pStats) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VKMA_NAMESPACE::TotalStatistics calculateStatistics() const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD Result checkCorruption(uint32_t memoryTypeBits) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type
    checkCorruption(uint32_t memoryTypeBits) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD Result checkPoolCorruption(Pool pool) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type
    checkPoolCorruption(Pool pool) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result createBuffer(const VkBufferCreateInfo *pBufferCreateInfo,
                                       const AllocationCreateInfo *pAllocationCreateInfo,
                                       Buffer *pBuffer) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Buffer>::type
    createBuffer(const VkBufferCreateInfo &bufferCreateInfo,
                 const AllocationCreateInfo &allocationCreateInfo) const;
  #ifndef VKMA_NO_SMART_HANDLE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
      typename ResultValueType<UniqueHandle<Buffer>>::type
      createBufferUnique(const VkBufferCreateInfo &bufferCreateInfo,
                         const AllocationCreateInfo &allocationCreateInfo) const;
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result createImage(const VkImageCreateInfo *pImageCreateInfo,
                                      const AllocationCreateInfo *pAllocationCreateInfo,
                                      Image *pImage) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Image>::type
    createImage(const VkImageCreateInfo &imageCreateInfo,
                const AllocationCreateInfo &allocationCreateInfo) const;
  #ifndef VKMA_NO_SMART_HANDLE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
      typename ResultValueType<UniqueHandle<Image>>::type
      createImageUnique(const VkImageCreateInfo &imageCreateInfo,
                        const AllocationCreateInfo &allocationCreateInfo) const;
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result createPool(const PoolCreateInfo *pCreateInfo,
                                     Pool *pPool) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Pool>::type
    createPool(const PoolCreateInfo &createInfo) const;
  #ifndef VKMA_NO_SMART_HANDLE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Pool>>::type
    createPoolUnique(const PoolCreateInfo &createInfo) const;
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

    void destroy() const VKMA_NOEXCEPT;

    void destroyBuffer(Buffer buffer) const VKMA_NOEXCEPT;

    void destroy(Buffer buffer) const VKMA_NOEXCEPT;

    void destroyImage(Image image) const VKMA_NOEXCEPT;

    void destroy(Image image) const VKMA_NOEXCEPT;

    void destroyPool(Pool pool) const VKMA_NOEXCEPT;

    void destroy(Pool pool) const VKMA_NOEXCEPT;

    VKMA_NODISCARD Result endDefragmentation(DefragmentationContext context,
                                             DefragmentationStats *pStats) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<DefragmentationStats>::type
    endDefragmentation(DefragmentationContext context) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result end(DefragmentationContext context,
                              DefragmentationStats *pStats) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<DefragmentationStats>::type
    end(DefragmentationContext context) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result
    endDefragmentationPass(DefragmentationContext pContext,
                           const DefragmentationPassMoveInfo *pPassInfo) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type endDefragmentationPass(
      DefragmentationContext pContext, const DefragmentationPassMoveInfo &passInfo) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result end(DefragmentationContext pContext,
                              const DefragmentationPassMoveInfo *pPassInfo) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type
    end(DefragmentationContext pContext, const DefragmentationPassMoveInfo &passInfo) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result findMemoryTypeIndex(uint32_t memoryTypeBits,
                                              const AllocationCreateInfo *pAllocationCreateInfo,
                                              uint32_t *pMemoryTypeIndex) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<uint32_t>::type findMemoryTypeIndex(
      uint32_t memoryTypeBits, const AllocationCreateInfo &allocationCreateInfo) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result
    findMemoryTypeIndexForBufferInfo(const VkBufferCreateInfo *pBufferCreateInfo,
                                     const AllocationCreateInfo *pAllocationCreateInfo,
                                     uint32_t *pMemoryTypeIndex) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<uint32_t>::type
    findMemoryTypeIndexForBufferInfo(const VkBufferCreateInfo &bufferCreateInfo,
                                     const AllocationCreateInfo &allocationCreateInfo) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result findMemoryTypeIndexForImageInfo(
      const VkImageCreateInfo *pImageCreateInfo, const AllocationCreateInfo *pAllocationCreateInfo,
      uint32_t *pMemoryTypeIndex) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<uint32_t>::type
    findMemoryTypeIndexForImageInfo(const VkImageCreateInfo &imageCreateInfo,
                                    const AllocationCreateInfo &allocationCreateInfo) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD Result flushAllocation(Allocation allocation, VkDeviceSize offset,
                                          VkDeviceSize size) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type
    flushAllocation(Allocation allocation, VkDeviceSize offset, VkDeviceSize size) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result flushAllocations(uint32_t allocationCount, const Allocation *allocations,
                                           const VkDeviceSize *offsets,
                                           const VkDeviceSize *sizes) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type
    flushAllocations(uint32_t allocationCount, const Allocation &allocations,
                     const VkDeviceSize &offsets, const VkDeviceSize &sizes) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void freeMemory(const Allocation allocation) const VKMA_NOEXCEPT;

    void free(const Allocation allocation) const VKMA_NOEXCEPT;

    void freeMemoryPages(size_t allocationCount,
                         const Allocation *pAllocations) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    void freeMemoryPages(size_t allocationCount, const Allocation &allocations) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void free(size_t allocationCount, const Allocation *pAllocations) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    void free(size_t allocationCount, const Allocation &allocations) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void freeStatsString(const char *pStatsString) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    void freeStatsString(const char &statsString) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void free(const char *pStatsString) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    void free(const char &statsString) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void getAllocationInfo(Allocation allocation,
                           AllocationInfo *pAllocationInfo) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VKMA_NAMESPACE::AllocationInfo
    getAllocationInfo(Allocation allocation) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void getAllocationMemoryProperties(Allocation allocation,
                                       VkMemoryPropertyFlags *pFlags) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VkMemoryPropertyFlags
    getAllocationMemoryProperties(Allocation allocation) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void getHeapBudgets(Budget *pBudgets) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VKMA_NAMESPACE::Budget getHeapBudgets() const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void getMemoryProperties(
      VkPhysicalDeviceMemoryProperties *pPhysicalDeviceMemoryProperties) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VkPhysicalDeviceMemoryProperties getMemoryProperties() const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void getMemoryTypeProperties(uint32_t memoryTypeIndex,
                                 VkMemoryPropertyFlags *pFlags) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VkMemoryPropertyFlags
    getMemoryTypeProperties(uint32_t memoryTypeIndex) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void getPhysicalDeviceProperties(VkPhysicalDeviceProperties *pPhysicalDeviceProperties) const
      VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VkPhysicalDeviceProperties getPhysicalDeviceProperties() const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void getPoolName(Pool pool, const char **ppName) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD const char *getPoolName(Pool pool) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void getPoolStatistics(Pool pool, Statistics *pPoolStats) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VKMA_NAMESPACE::Statistics getPoolStatistics(Pool pool) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD Result invalidateAllocation(Allocation allocation, VkDeviceSize offset,
                                               VkDeviceSize size) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type
    invalidateAllocation(Allocation allocation, VkDeviceSize offset, VkDeviceSize size) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result invalidateAllocations(uint32_t allocationCount,
                                                const Allocation *allocations,
                                                const VkDeviceSize *offsets,
                                                const VkDeviceSize *sizes) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type
    invalidateAllocations(uint32_t allocationCount, const Allocation &allocations,
                          const VkDeviceSize &offsets, const VkDeviceSize &sizes) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result mapMemory(Allocation allocation, void **ppData) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void *>::type
    mapMemory(Allocation allocation) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void setAllocationName(Allocation allocation, const char *pName) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    void setAllocationName(Allocation allocation, const char &name) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void setAllocationUserData(Allocation allocation, const void *pUserData) const VKMA_NOEXCEPT;

    void setCurrentFrameIndex(uint32_t frameIndex) const VKMA_NOEXCEPT;

    void setPoolName(Pool pool, const char *pName) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    void setPoolName(Pool pool, const char &name) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void unmapMemory(Allocation allocation) const VKMA_NOEXCEPT;

    VKMA_TYPESAFE_EXPLICIT operator VkmaAllocator() const VKMA_NOEXCEPT { return m_allocator; }

    explicit operator bool() const VKMA_NOEXCEPT { return m_allocator != VKMA_NULL_HANDLE; }

    bool operator!() const VKMA_NOEXCEPT { return m_allocator == VKMA_NULL_HANDLE; }

  private:
    VkmaAllocator m_allocator;
  };
  static_assert(sizeof(VKMA_NAMESPACE::Allocator) == sizeof(VkmaAllocator),
                "handle and wrapper have different size!");

  template <> struct isVulkanHandleType<VKMA_NAMESPACE::Allocator> {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

  class VirtualAllocation {
  public:
    using CType = VkmaVirtualAllocation;

  public:
    VKMA_CONSTEXPR VirtualAllocation() VKMA_NOEXCEPT : m_virtualAllocation(VKMA_NULL_HANDLE) {}

    VKMA_CONSTEXPR VirtualAllocation(std::nullptr_t) VKMA_NOEXCEPT
      : m_virtualAllocation(VKMA_NULL_HANDLE) {}

    VKMA_TYPESAFE_EXPLICIT VirtualAllocation(VkmaVirtualAllocation virtualAllocation) VKMA_NOEXCEPT
      : m_virtualAllocation(virtualAllocation) {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    VirtualAllocation &operator=(VkmaVirtualAllocation virtualAllocation) VKMA_NOEXCEPT {
      m_virtualAllocation = virtualAllocation;
      return *this;
    }
#endif

    VirtualAllocation &operator=(std::nullptr_t) VKMA_NOEXCEPT {
      m_virtualAllocation = VKMA_NULL_HANDLE;
      return *this;
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(VirtualAllocation const &) const = default;
#else
    bool operator==(VirtualAllocation const &rhs) const VKMA_NOEXCEPT {
      return m_virtualAllocation == rhs.m_virtualAllocation;
    }

    bool operator!=(VirtualAllocation const &rhs) const VKMA_NOEXCEPT {
      return m_virtualAllocation != rhs.m_virtualAllocation;
    }

    bool operator<(VirtualAllocation const &rhs) const VKMA_NOEXCEPT {
      return m_virtualAllocation < rhs.m_virtualAllocation;
    }
#endif

    VKMA_TYPESAFE_EXPLICIT operator VkmaVirtualAllocation() const VKMA_NOEXCEPT {
      return m_virtualAllocation;
    }

    explicit operator bool() const VKMA_NOEXCEPT { return m_virtualAllocation != VKMA_NULL_HANDLE; }

    bool operator!() const VKMA_NOEXCEPT { return m_virtualAllocation == VKMA_NULL_HANDLE; }

  private:
    VkmaVirtualAllocation m_virtualAllocation;
  };
  static_assert(sizeof(VKMA_NAMESPACE::VirtualAllocation) == sizeof(VkmaVirtualAllocation),
                "handle and wrapper have different size!");

  template <> struct isVulkanHandleType<VKMA_NAMESPACE::VirtualAllocation> {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

  class VirtualBlock {
  public:
    using CType = VkmaVirtualBlock;

  public:
    VKMA_CONSTEXPR VirtualBlock() VKMA_NOEXCEPT : m_virtualBlock(VKMA_NULL_HANDLE) {}

    VKMA_CONSTEXPR VirtualBlock(std::nullptr_t) VKMA_NOEXCEPT : m_virtualBlock(VKMA_NULL_HANDLE) {}

    VKMA_TYPESAFE_EXPLICIT VirtualBlock(VkmaVirtualBlock virtualBlock) VKMA_NOEXCEPT
      : m_virtualBlock(virtualBlock) {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    VirtualBlock &operator=(VkmaVirtualBlock virtualBlock) VKMA_NOEXCEPT {
      m_virtualBlock = virtualBlock;
      return *this;
    }
#endif

    VirtualBlock &operator=(std::nullptr_t) VKMA_NOEXCEPT {
      m_virtualBlock = VKMA_NULL_HANDLE;
      return *this;
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(VirtualBlock const &) const = default;
#else
    bool operator==(VirtualBlock const &rhs) const VKMA_NOEXCEPT {
      return m_virtualBlock == rhs.m_virtualBlock;
    }

    bool operator!=(VirtualBlock const &rhs) const VKMA_NOEXCEPT {
      return m_virtualBlock != rhs.m_virtualBlock;
    }

    bool operator<(VirtualBlock const &rhs) const VKMA_NOEXCEPT {
      return m_virtualBlock < rhs.m_virtualBlock;
    }
#endif

    void buildStatsString(VkBool32 detailedMap, char **ppStatsString) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD char *buildStatsString(VkBool32 detailedMap) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void calculateStatistics(DetailedStatistics *pStats) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VKMA_NAMESPACE::DetailedStatistics calculateStatistics() const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void clear() const VKMA_NOEXCEPT;

    void destroy() const VKMA_NOEXCEPT;

    void freeStatsString(const char *pStatsString) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    void freeStatsString(const char &statsString) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void free(const char *pStatsString) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    void free(const char &statsString) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void getVirtualAllocationInfo(VirtualAllocation allocation,
                                  VirtualAllocationInfo *pVirtualAllocInfo) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VKMA_NAMESPACE::VirtualAllocationInfo
    getVirtualAllocationInfo(VirtualAllocation allocation) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    void getStatistics(Statistics *pStats) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD VKMA_NAMESPACE::Statistics getStatistics() const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VkBool32 isEmpty() const VKMA_NOEXCEPT;

    void setVirtualAllocationUserData(VirtualAllocation allocation,
                                      void *pUserData) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD void
    setVirtualAllocationUserData(VirtualAllocation allocation) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_NODISCARD Result virtualAllocate(const VirtualAllocationCreateInfo *pCreateInfo,
                                          VirtualAllocation *pAllocation) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<VirtualAllocation>::type
    virtualAllocate(const VirtualAllocationCreateInfo &createInfo) const;
  #ifndef VKMA_NO_SMART_HANDLE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
      typename ResultValueType<UniqueHandle<VirtualAllocation>>::type
      virtualAllocateUnique(const VirtualAllocationCreateInfo &createInfo) const;
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD Result virtualFree(VirtualAllocation allocation) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type
    virtualFree(VirtualAllocation allocation) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_TYPESAFE_EXPLICIT operator VkmaVirtualBlock() const VKMA_NOEXCEPT {
      return m_virtualBlock;
    }

    explicit operator bool() const VKMA_NOEXCEPT { return m_virtualBlock != VKMA_NULL_HANDLE; }

    bool operator!() const VKMA_NOEXCEPT { return m_virtualBlock == VKMA_NULL_HANDLE; }

  private:
    VkmaVirtualBlock m_virtualBlock;
  };
  static_assert(sizeof(VKMA_NAMESPACE::VirtualBlock) == sizeof(VkmaVirtualBlock),
                "handle and wrapper have different size!");

  template <> struct isVulkanHandleType<VKMA_NAMESPACE::VirtualBlock> {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

#ifndef VKMA_NO_SMART_HANDLE
  template <> class UniqueHandleTraits<Allocator> {
  public:
    using deleter = ObjectDestroy<NoParent>;
  };
  using UniqueAllocator = UniqueHandle<Allocator>;
#endif /*VKMA_NO_SMART_HANDLE*/

  VKMA_NODISCARD Result createAllocator(const AllocatorCreateInfo *pCreateInfo,
                                        Allocator *pAllocator) VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Allocator>::type
  createAllocator(const AllocatorCreateInfo &createInfo);
  #ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
    typename ResultValueType<UniqueHandle<Allocator>>::type
    createAllocatorUnique(const AllocatorCreateInfo &createInfo);
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD Result createVirtualBlock(const VirtualBlockCreateInfo *pCreateInfo,
                                           VirtualBlock *pVirtualBlock) VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<VirtualBlock>::type
  createVirtualBlock(const VirtualBlockCreateInfo &createInfo);
  #ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
    typename ResultValueType<UniqueHandle<VirtualBlock>>::type
    createVirtualBlockUnique(const VirtualBlockCreateInfo &createInfo);
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result createAllocator(const AllocatorCreateInfo *pCreateInfo,
                                                    Allocator *pAllocator) VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaCreateAllocator(reinterpret_cast<const VkmaAllocatorCreateInfo *>(pCreateInfo),
                          reinterpret_cast<VkmaAllocator *>(pAllocator)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Allocator>::type
  createAllocator(const AllocatorCreateInfo &createInfo) {
    Allocator allocator;
    Result result = static_cast<Result>(
      vkmaCreateAllocator(reinterpret_cast<const VkmaAllocatorCreateInfo *>(&createInfo),
                          reinterpret_cast<VkmaAllocator *>(&allocator)));
    return createResultValue(result, allocator, VKMA_NAMESPACE_STRING "::createAllocator");
  }

  #ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
    typename ResultValueType<UniqueHandle<Allocator>>::type
    createAllocatorUnique(const AllocatorCreateInfo &createInfo) {
    Allocator allocator;
    Result result = static_cast<Result>(
      vkmaCreateAllocator(reinterpret_cast<const VkmaAllocatorCreateInfo *>(&createInfo),
                          reinterpret_cast<VkmaAllocator *>(&allocator)));
    ObjectDestroy<NoParent> deleter;
    return createResultValue<Allocator>(result, allocator,
                                        VKMA_NAMESPACE_STRING "::createAllocatorUnique", deleter);
  }
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result createVirtualBlock(const VirtualBlockCreateInfo *pCreateInfo,
                                                       VirtualBlock *pVirtualBlock) VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaCreateVirtualBlock(reinterpret_cast<const VkmaVirtualBlockCreateInfo *>(pCreateInfo),
                             reinterpret_cast<VkmaVirtualBlock *>(pVirtualBlock)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<VirtualBlock>::type
  createVirtualBlock(const VirtualBlockCreateInfo &createInfo) {
    VirtualBlock virtualBlock;
    Result result = static_cast<Result>(
      vkmaCreateVirtualBlock(reinterpret_cast<const VkmaVirtualBlockCreateInfo *>(&createInfo),
                             reinterpret_cast<VkmaVirtualBlock *>(&virtualBlock)));
    return createResultValue(result, virtualBlock, VKMA_NAMESPACE_STRING "::createVirtualBlock");
  }

  #ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
    typename ResultValueType<UniqueHandle<VirtualBlock>>::type
    createVirtualBlockUnique(const VirtualBlockCreateInfo &createInfo) {
    VirtualBlock virtualBlock;
    Result result = static_cast<Result>(
      vkmaCreateVirtualBlock(reinterpret_cast<const VkmaVirtualBlockCreateInfo *>(&createInfo),
                             reinterpret_cast<VkmaVirtualBlock *>(&virtualBlock)));
    ObjectDestroy<NoParent> deleter;
    return createResultValue<VirtualBlock>(result, virtualBlock,
                                           VKMA_NAMESPACE_STRING "::createVirtualBlockUnique",
                                           deleter);
  }
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result Allocator::allocateMemory(
    const VkMemoryRequirements *pVkMemoryRequirements, const AllocationCreateInfo *pCreateInfo,
    Allocation *pAllocation) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaAllocateMemory(m_allocator, pVkMemoryRequirements,
                         reinterpret_cast<const VkmaAllocationCreateInfo *>(pCreateInfo),
                         reinterpret_cast<VkmaAllocation *>(pAllocation)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Allocation>::type
  Allocator::allocateMemory(const VkMemoryRequirements &vkMemoryRequirements,
                            const AllocationCreateInfo &createInfo) const {
    Allocation allocation;
    Result result = static_cast<Result>(
      vkmaAllocateMemory(m_allocator, &vkMemoryRequirements,
                         reinterpret_cast<const VkmaAllocationCreateInfo *>(&createInfo),
                         reinterpret_cast<VkmaAllocation *>(&allocation)));
    return createResultValue(result, allocation,
                             VKMA_NAMESPACE_STRING "::Allocator::allocateMemory");
  }

  #ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
    typename ResultValueType<UniqueHandle<Allocation>>::type
    Allocator::allocateMemoryUnique(const VkMemoryRequirements &vkMemoryRequirements,
                                    const AllocationCreateInfo &createInfo) const {
    Allocation allocation;
    Result result = static_cast<Result>(
      vkmaAllocateMemory(m_allocator, &vkMemoryRequirements,
                         reinterpret_cast<const VkmaAllocationCreateInfo *>(&createInfo),
                         reinterpret_cast<VkmaAllocation *>(&allocation)));
    ObjectFree<Allocator> deleter(*this);
    return createResultValue<Allocation>(result, allocation,
                                         VKMA_NAMESPACE_STRING "::Allocator::allocateMemoryUnique",
                                         deleter);
  }
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result
  Allocator::allocateMemoryForBuffer(VkBuffer buffer, const AllocationCreateInfo *pCreateInfo,
                                     Allocation *pAllocation) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaAllocateMemoryForBuffer(m_allocator, buffer,
                                  reinterpret_cast<const VkmaAllocationCreateInfo *>(pCreateInfo),
                                  reinterpret_cast<VkmaAllocation *>(pAllocation)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Allocation>::type
  Allocator::allocateMemoryForBuffer(VkBuffer buffer,
                                     const AllocationCreateInfo &createInfo) const {
    Allocation allocation;
    Result result = static_cast<Result>(
      vkmaAllocateMemoryForBuffer(m_allocator, buffer,
                                  reinterpret_cast<const VkmaAllocationCreateInfo *>(&createInfo),
                                  reinterpret_cast<VkmaAllocation *>(&allocation)));
    return createResultValue(result, allocation,
                             VKMA_NAMESPACE_STRING "::Allocator::allocateMemoryForBuffer");
  }

  #ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
    typename ResultValueType<UniqueHandle<Allocation>>::type
    Allocator::allocateMemoryForBufferUnique(VkBuffer buffer,
                                             const AllocationCreateInfo &createInfo) const {
    Allocation allocation;
    Result result = static_cast<Result>(
      vkmaAllocateMemoryForBuffer(m_allocator, buffer,
                                  reinterpret_cast<const VkmaAllocationCreateInfo *>(&createInfo),
                                  reinterpret_cast<VkmaAllocation *>(&allocation)));
    ObjectFree<Allocator> deleter(*this);
    return createResultValue<Allocation>(result, allocation,
                                         VKMA_NAMESPACE_STRING
                                         "::Allocator::allocateMemoryForBufferUnique",
                                         deleter);
  }
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result
  Allocator::allocateMemoryForImage(VkImage image, const AllocationCreateInfo *pCreateInfo,
                                    Allocation *pAllocation) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaAllocateMemoryForImage(m_allocator, image,
                                 reinterpret_cast<const VkmaAllocationCreateInfo *>(pCreateInfo),
                                 reinterpret_cast<VkmaAllocation *>(pAllocation)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Allocation>::type
  Allocator::allocateMemoryForImage(VkImage image, const AllocationCreateInfo &createInfo) const {
    Allocation allocation;
    Result result = static_cast<Result>(
      vkmaAllocateMemoryForImage(m_allocator, image,
                                 reinterpret_cast<const VkmaAllocationCreateInfo *>(&createInfo),
                                 reinterpret_cast<VkmaAllocation *>(&allocation)));
    return createResultValue(result, allocation,
                             VKMA_NAMESPACE_STRING "::Allocator::allocateMemoryForImage");
  }

  #ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
    typename ResultValueType<UniqueHandle<Allocation>>::type
    Allocator::allocateMemoryForImageUnique(VkImage image,
                                            const AllocationCreateInfo &createInfo) const {
    Allocation allocation;
    Result result = static_cast<Result>(
      vkmaAllocateMemoryForImage(m_allocator, image,
                                 reinterpret_cast<const VkmaAllocationCreateInfo *>(&createInfo),
                                 reinterpret_cast<VkmaAllocation *>(&allocation)));
    ObjectFree<Allocator> deleter(*this);
    return createResultValue<Allocation>(result, allocation,
                                         VKMA_NAMESPACE_STRING
                                         "::Allocator::allocateMemoryForImageUnique",
                                         deleter);
  }
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result Allocator::allocateMemoryPages(
    const VkMemoryRequirements *pVkMemoryRequirements, const AllocationCreateInfo *pCreateInfo,
    size_t allocationCount, Allocation *pAllocations) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaAllocateMemoryPages(m_allocator, pVkMemoryRequirements,
                              reinterpret_cast<const VkmaAllocationCreateInfo *>(pCreateInfo),
                              allocationCount, reinterpret_cast<VkmaAllocation *>(pAllocations)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Allocation>::type
  Allocator::allocateMemoryPages(const VkMemoryRequirements &vkMemoryRequirements,
                                 const AllocationCreateInfo &createInfo,
                                 size_t allocationCount) const {
    Allocation allocations;
    Result result = static_cast<Result>(
      vkmaAllocateMemoryPages(m_allocator, &vkMemoryRequirements,
                              reinterpret_cast<const VkmaAllocationCreateInfo *>(&createInfo),
                              allocationCount, reinterpret_cast<VkmaAllocation *>(&allocations)));
    return createResultValue(result, allocations,
                             VKMA_NAMESPACE_STRING "::Allocator::allocateMemoryPages");
  }

  #ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
    typename ResultValueType<UniqueHandle<Allocation>>::type
    Allocator::allocateMemoryPagesUnique(const VkMemoryRequirements &vkMemoryRequirements,
                                         const AllocationCreateInfo &createInfo,
                                         size_t allocationCount) const {
    Allocation allocations;
    Result result = static_cast<Result>(
      vkmaAllocateMemoryPages(m_allocator, &vkMemoryRequirements,
                              reinterpret_cast<const VkmaAllocationCreateInfo *>(&createInfo),
                              allocationCount, reinterpret_cast<VkmaAllocation *>(&allocations)));
    ObjectFree<Allocator> deleter(*this);
    return createResultValue<Allocation>(result, allocations,
                                         VKMA_NAMESPACE_STRING
                                         "::Allocator::allocateMemoryPagesUnique",
                                         deleter);
  }
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result Allocator::beginDefragmentation(
    const DefragmentationInfo *pInfo, DefragmentationContext *pContext) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaBeginDefragmentation(m_allocator,
                               reinterpret_cast<const VkmaDefragmentationInfo *>(pInfo),
                               reinterpret_cast<VkmaDefragmentationContext *>(pContext)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
    typename ResultValueType<DefragmentationContext>::type
    Allocator::beginDefragmentation(const DefragmentationInfo &info) const {
    DefragmentationContext context;
    Result result = static_cast<Result>(
      vkmaBeginDefragmentation(m_allocator,
                               reinterpret_cast<const VkmaDefragmentationInfo *>(&info),
                               reinterpret_cast<VkmaDefragmentationContext *>(&context)));
    return createResultValue(result, context,
                             VKMA_NAMESPACE_STRING "::Allocator::beginDefragmentation");
  }

  #ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
    typename ResultValueType<UniqueHandle<DefragmentationContext>>::type
    Allocator::beginDefragmentationUnique(const DefragmentationInfo &info) const {
    DefragmentationContext context;
    Result result = static_cast<Result>(
      vkmaBeginDefragmentation(m_allocator,
                               reinterpret_cast<const VkmaDefragmentationInfo *>(&info),
                               reinterpret_cast<VkmaDefragmentationContext *>(&context)));
    ObjectEnd<Allocator> deleter(*this);
    return createResultValue<DefragmentationContext>(result, context,
                                                     VKMA_NAMESPACE_STRING
                                                     "::Allocator::beginDefragmentationUnique",
                                                     deleter);
  }
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result Allocator::beginDefragmentationPass(
    DefragmentationContext pContext,
    const DefragmentationPassMoveInfo *pPassInfo) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaBeginDefragmentationPass(m_allocator, static_cast<VkmaDefragmentationContext>(pContext),
                                   reinterpret_cast<const VkmaDefragmentationPassMoveInfo *>(
                                     pPassInfo)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type
  Allocator::beginDefragmentationPass(DefragmentationContext pContext,
                                      const DefragmentationPassMoveInfo &passInfo) const {
    Result result = static_cast<Result>(
      vkmaBeginDefragmentationPass(m_allocator, static_cast<VkmaDefragmentationContext>(pContext),
                                   reinterpret_cast<const VkmaDefragmentationPassMoveInfo *>(
                                     &passInfo)));
    return createResultValue(result, VKMA_NAMESPACE_STRING "::Allocator::beginDefragmentationPass");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result
  Allocator::bindBufferMemory(Allocation allocation, VkBuffer buffer) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaBindBufferMemory(m_allocator, static_cast<VkmaAllocation>(allocation), buffer));
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type
  Allocator::bindBufferMemory(Allocation allocation, VkBuffer buffer) const {
    Result result = static_cast<Result>(
      vkmaBindBufferMemory(m_allocator, static_cast<VkmaAllocation>(allocation), buffer));
    return createResultValue(result, VKMA_NAMESPACE_STRING "::Allocator::bindBufferMemory");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result
  Allocator::bindBufferMemory2(Allocation allocation, VkDeviceSize allocationLocalOffset,
                               VkBuffer buffer, const void *pNext) const VKMA_NOEXCEPT {
    return static_cast<Result>(vkmaBindBufferMemory2(m_allocator,
                                                     static_cast<VkmaAllocation>(allocation),
                                                     allocationLocalOffset, buffer, pNext));
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type
  Allocator::bindBufferMemory2(Allocation allocation, VkDeviceSize allocationLocalOffset,
                               VkBuffer buffer, const void *pNext) const {
    Result result = static_cast<Result>(
      vkmaBindBufferMemory2(m_allocator, static_cast<VkmaAllocation>(allocation),
                            allocationLocalOffset, buffer, pNext));
    return createResultValue(result, VKMA_NAMESPACE_STRING "::Allocator::bindBufferMemory2");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result Allocator::bindImageMemory(Allocation allocation,
                                                               VkImage image) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaBindImageMemory(m_allocator, static_cast<VkmaAllocation>(allocation), image));
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type
  Allocator::bindImageMemory(Allocation allocation, VkImage image) const {
    Result result = static_cast<Result>(
      vkmaBindImageMemory(m_allocator, static_cast<VkmaAllocation>(allocation), image));
    return createResultValue(result, VKMA_NAMESPACE_STRING "::Allocator::bindImageMemory");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result
  Allocator::bindImageMemory2(Allocation allocation, VkDeviceSize allocationLocalOffset,
                              VkImage image, const void *pNext) const VKMA_NOEXCEPT {
    return static_cast<Result>(vkmaBindImageMemory2(m_allocator,
                                                    static_cast<VkmaAllocation>(allocation),
                                                    allocationLocalOffset, image, pNext));
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type
  Allocator::bindImageMemory2(Allocation allocation, VkDeviceSize allocationLocalOffset,
                              VkImage image, const void *pNext) const {
    Result result = static_cast<Result>(
      vkmaBindImageMemory2(m_allocator, static_cast<VkmaAllocation>(allocation),
                           allocationLocalOffset, image, pNext));
    return createResultValue(result, VKMA_NAMESPACE_STRING "::Allocator::bindImageMemory2");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::buildStatsString(VkBool32 detailedMap,
                                               char **ppStatsString) const VKMA_NOEXCEPT {
    vkmaBuildStatsString(m_allocator, detailedMap, ppStatsString);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE char *
  Allocator::buildStatsString(VkBool32 detailedMap) const VKMA_NOEXCEPT {
    char *pStatsString;
    vkmaBuildStatsString(m_allocator, detailedMap, &pStatsString);
    return pStatsString;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::calculatePoolStatistics(
    Pool pool, DetailedStatistics *pPoolStats) const VKMA_NOEXCEPT {
    vkmaCalculatePoolStatistics(m_allocator, static_cast<VkmaPool>(pool),
                                reinterpret_cast<VkmaDetailedStatistics *>(pPoolStats));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::DetailedStatistics
  Allocator::calculatePoolStatistics(Pool pool) const VKMA_NOEXCEPT {
    VKMA_NAMESPACE::DetailedStatistics poolStats;
    vkmaCalculatePoolStatistics(m_allocator, static_cast<VkmaPool>(pool),
                                reinterpret_cast<VkmaDetailedStatistics *>(&poolStats));
    return poolStats;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::calculateStatistics(TotalStatistics *pStats) const VKMA_NOEXCEPT {
    vkmaCalculateStatistics(m_allocator, reinterpret_cast<VkmaTotalStatistics *>(pStats));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::TotalStatistics
  Allocator::calculateStatistics() const VKMA_NOEXCEPT {
    VKMA_NAMESPACE::TotalStatistics stats;
    vkmaCalculateStatistics(m_allocator, reinterpret_cast<VkmaTotalStatistics *>(&stats));
    return stats;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result
  Allocator::checkCorruption(uint32_t memoryTypeBits) const VKMA_NOEXCEPT {
    return static_cast<Result>(vkmaCheckCorruption(m_allocator, memoryTypeBits));
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type
  Allocator::checkCorruption(uint32_t memoryTypeBits) const {
    Result result = static_cast<Result>(vkmaCheckCorruption(m_allocator, memoryTypeBits));
    return createResultValue(result, VKMA_NAMESPACE_STRING "::Allocator::checkCorruption");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result Allocator::checkPoolCorruption(Pool pool) const VKMA_NOEXCEPT {
    return static_cast<Result>(vkmaCheckPoolCorruption(m_allocator, static_cast<VkmaPool>(pool)));
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type
  Allocator::checkPoolCorruption(Pool pool) const {
    Result result = static_cast<Result>(
      vkmaCheckPoolCorruption(m_allocator, static_cast<VkmaPool>(pool)));
    return createResultValue(result, VKMA_NAMESPACE_STRING "::Allocator::checkPoolCorruption");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result Allocator::createBuffer(
    const VkBufferCreateInfo *pBufferCreateInfo, const AllocationCreateInfo *pAllocationCreateInfo,
    Buffer *pBuffer) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaCreateBuffer(m_allocator, pBufferCreateInfo,
                       reinterpret_cast<const VkmaAllocationCreateInfo *>(pAllocationCreateInfo),
                       reinterpret_cast<VkmaBuffer *>(pBuffer)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Buffer>::type
  Allocator::createBuffer(const VkBufferCreateInfo &bufferCreateInfo,
                          const AllocationCreateInfo &allocationCreateInfo) const {
    Buffer buffer;
    Result result = static_cast<Result>(
      vkmaCreateBuffer(m_allocator, &bufferCreateInfo,
                       reinterpret_cast<const VkmaAllocationCreateInfo *>(&allocationCreateInfo),
                       reinterpret_cast<VkmaBuffer *>(&buffer)));
    return createResultValue(result, buffer, VKMA_NAMESPACE_STRING "::Allocator::createBuffer");
  }

  #ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Buffer>>::type
  Allocator::createBufferUnique(const VkBufferCreateInfo &bufferCreateInfo,
                                const AllocationCreateInfo &allocationCreateInfo) const {
    Buffer buffer;
    Result result = static_cast<Result>(
      vkmaCreateBuffer(m_allocator, &bufferCreateInfo,
                       reinterpret_cast<const VkmaAllocationCreateInfo *>(&allocationCreateInfo),
                       reinterpret_cast<VkmaBuffer *>(&buffer)));
    ObjectDestroy<Allocator> deleter(*this);
    return createResultValue<Buffer>(result, buffer,
                                     VKMA_NAMESPACE_STRING "::Allocator::createBufferUnique",
                                     deleter);
  }
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result Allocator::createImage(
    const VkImageCreateInfo *pImageCreateInfo, const AllocationCreateInfo *pAllocationCreateInfo,
    Image *pImage) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaCreateImage(m_allocator, pImageCreateInfo,
                      reinterpret_cast<const VkmaAllocationCreateInfo *>(pAllocationCreateInfo),
                      reinterpret_cast<VkmaImage *>(pImage)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Image>::type
  Allocator::createImage(const VkImageCreateInfo &imageCreateInfo,
                         const AllocationCreateInfo &allocationCreateInfo) const {
    Image image;
    Result result = static_cast<Result>(
      vkmaCreateImage(m_allocator, &imageCreateInfo,
                      reinterpret_cast<const VkmaAllocationCreateInfo *>(&allocationCreateInfo),
                      reinterpret_cast<VkmaImage *>(&image)));
    return createResultValue(result, image, VKMA_NAMESPACE_STRING "::Allocator::createImage");
  }

  #ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Image>>::type
  Allocator::createImageUnique(const VkImageCreateInfo &imageCreateInfo,
                               const AllocationCreateInfo &allocationCreateInfo) const {
    Image image;
    Result result = static_cast<Result>(
      vkmaCreateImage(m_allocator, &imageCreateInfo,
                      reinterpret_cast<const VkmaAllocationCreateInfo *>(&allocationCreateInfo),
                      reinterpret_cast<VkmaImage *>(&image)));
    ObjectDestroy<Allocator> deleter(*this);
    return createResultValue<Image>(result, image,
                                    VKMA_NAMESPACE_STRING "::Allocator::createImageUnique",
                                    deleter);
  }
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result Allocator::createPool(const PoolCreateInfo *pCreateInfo,
                                                          Pool *pPool) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaCreatePool(m_allocator, reinterpret_cast<const VkmaPoolCreateInfo *>(pCreateInfo),
                     reinterpret_cast<VkmaPool *>(pPool)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Pool>::type
  Allocator::createPool(const PoolCreateInfo &createInfo) const {
    Pool pool;
    Result result = static_cast<Result>(
      vkmaCreatePool(m_allocator, reinterpret_cast<const VkmaPoolCreateInfo *>(&createInfo),
                     reinterpret_cast<VkmaPool *>(&pool)));
    return createResultValue(result, pool, VKMA_NAMESPACE_STRING "::Allocator::createPool");
  }

  #ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Pool>>::type
  Allocator::createPoolUnique(const PoolCreateInfo &createInfo) const {
    Pool pool;
    Result result = static_cast<Result>(
      vkmaCreatePool(m_allocator, reinterpret_cast<const VkmaPoolCreateInfo *>(&createInfo),
                     reinterpret_cast<VkmaPool *>(&pool)));
    ObjectDestroy<Allocator> deleter(*this);
    return createResultValue<Pool>(result, pool,
                                   VKMA_NAMESPACE_STRING "::Allocator::createPoolUnique", deleter);
  }
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::destroy() const VKMA_NOEXCEPT { vkmaDestroyAllocator(m_allocator); }

  VKMA_INLINE void Allocator::destroyBuffer(Buffer buffer) const VKMA_NOEXCEPT {
    vkmaDestroyBuffer(m_allocator, static_cast<VkmaBuffer>(buffer));
  }

  VKMA_INLINE void Allocator::destroy(Buffer buffer) const VKMA_NOEXCEPT {
    vkmaDestroyBuffer(m_allocator, static_cast<VkmaBuffer>(buffer));
  }

  VKMA_INLINE void Allocator::destroyImage(Image image) const VKMA_NOEXCEPT {
    vkmaDestroyImage(m_allocator, static_cast<VkmaImage>(image));
  }

  VKMA_INLINE void Allocator::destroy(Image image) const VKMA_NOEXCEPT {
    vkmaDestroyImage(m_allocator, static_cast<VkmaImage>(image));
  }

  VKMA_INLINE void Allocator::destroyPool(Pool pool) const VKMA_NOEXCEPT {
    vkmaDestroyPool(m_allocator, static_cast<VkmaPool>(pool));
  }

  VKMA_INLINE void Allocator::destroy(Pool pool) const VKMA_NOEXCEPT {
    vkmaDestroyPool(m_allocator, static_cast<VkmaPool>(pool));
  }

  VKMA_NODISCARD VKMA_INLINE Result Allocator::endDefragmentation(
    DefragmentationContext context, DefragmentationStats *pStats) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaEndDefragmentation(m_allocator, static_cast<VkmaDefragmentationContext>(context),
                             reinterpret_cast<VkmaDefragmentationStats *>(pStats)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<DefragmentationStats>::type
  Allocator::endDefragmentation(DefragmentationContext context) const {
    DefragmentationStats stats;
    Result result = static_cast<Result>(
      vkmaEndDefragmentation(m_allocator, static_cast<VkmaDefragmentationContext>(context),
                             reinterpret_cast<VkmaDefragmentationStats *>(&stats)));
    return createResultValue(result, stats,
                             VKMA_NAMESPACE_STRING "::Allocator::endDefragmentation");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result
  Allocator::end(DefragmentationContext context, DefragmentationStats *pStats) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaEndDefragmentation(m_allocator, static_cast<VkmaDefragmentationContext>(context),
                             reinterpret_cast<VkmaDefragmentationStats *>(pStats)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<DefragmentationStats>::type
  Allocator::end(DefragmentationContext context) const {
    DefragmentationStats stats;
    Result result = static_cast<Result>(
      vkmaEndDefragmentation(m_allocator, static_cast<VkmaDefragmentationContext>(context),
                             reinterpret_cast<VkmaDefragmentationStats *>(&stats)));
    return createResultValue(result, stats, VKMA_NAMESPACE_STRING "::Allocator::end");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result Allocator::endDefragmentationPass(
    DefragmentationContext pContext,
    const DefragmentationPassMoveInfo *pPassInfo) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaEndDefragmentationPass(m_allocator, static_cast<VkmaDefragmentationContext>(pContext),
                                 reinterpret_cast<const VkmaDefragmentationPassMoveInfo *>(
                                   pPassInfo)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type
  Allocator::endDefragmentationPass(DefragmentationContext pContext,
                                    const DefragmentationPassMoveInfo &passInfo) const {
    Result result = static_cast<Result>(
      vkmaEndDefragmentationPass(m_allocator, static_cast<VkmaDefragmentationContext>(pContext),
                                 reinterpret_cast<const VkmaDefragmentationPassMoveInfo *>(
                                   &passInfo)));
    return createResultValue(result, VKMA_NAMESPACE_STRING "::Allocator::endDefragmentationPass");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result
  Allocator::end(DefragmentationContext pContext,
                 const DefragmentationPassMoveInfo *pPassInfo) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaEndDefragmentationPass(m_allocator, static_cast<VkmaDefragmentationContext>(pContext),
                                 reinterpret_cast<const VkmaDefragmentationPassMoveInfo *>(
                                   pPassInfo)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::end(
    DefragmentationContext pContext, const DefragmentationPassMoveInfo &passInfo) const {
    Result result = static_cast<Result>(
      vkmaEndDefragmentationPass(m_allocator, static_cast<VkmaDefragmentationContext>(pContext),
                                 reinterpret_cast<const VkmaDefragmentationPassMoveInfo *>(
                                   &passInfo)));
    return createResultValue(result, VKMA_NAMESPACE_STRING "::Allocator::end");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result Allocator::findMemoryTypeIndex(
    uint32_t memoryTypeBits, const AllocationCreateInfo *pAllocationCreateInfo,
    uint32_t *pMemoryTypeIndex) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaFindMemoryTypeIndex(m_allocator, memoryTypeBits,
                              reinterpret_cast<const VkmaAllocationCreateInfo *>(
                                pAllocationCreateInfo),
                              pMemoryTypeIndex));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<uint32_t>::type
  Allocator::findMemoryTypeIndex(uint32_t memoryTypeBits,
                                 const AllocationCreateInfo &allocationCreateInfo) const {
    uint32_t memoryTypeIndex;
    Result result = static_cast<Result>(
      vkmaFindMemoryTypeIndex(m_allocator, memoryTypeBits,
                              reinterpret_cast<const VkmaAllocationCreateInfo *>(
                                &allocationCreateInfo),
                              &memoryTypeIndex));
    return createResultValue(result, memoryTypeIndex,
                             VKMA_NAMESPACE_STRING "::Allocator::findMemoryTypeIndex");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result Allocator::findMemoryTypeIndexForBufferInfo(
    const VkBufferCreateInfo *pBufferCreateInfo, const AllocationCreateInfo *pAllocationCreateInfo,
    uint32_t *pMemoryTypeIndex) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaFindMemoryTypeIndexForBufferInfo(m_allocator, pBufferCreateInfo,
                                           reinterpret_cast<const VkmaAllocationCreateInfo *>(
                                             pAllocationCreateInfo),
                                           pMemoryTypeIndex));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<uint32_t>::type
  Allocator::findMemoryTypeIndexForBufferInfo(
    const VkBufferCreateInfo &bufferCreateInfo,
    const AllocationCreateInfo &allocationCreateInfo) const {
    uint32_t memoryTypeIndex;
    Result result = static_cast<Result>(
      vkmaFindMemoryTypeIndexForBufferInfo(m_allocator, &bufferCreateInfo,
                                           reinterpret_cast<const VkmaAllocationCreateInfo *>(
                                             &allocationCreateInfo),
                                           &memoryTypeIndex));
    return createResultValue(result, memoryTypeIndex,
                             VKMA_NAMESPACE_STRING "::Allocator::findMemoryTypeIndexForBufferInfo");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result Allocator::findMemoryTypeIndexForImageInfo(
    const VkImageCreateInfo *pImageCreateInfo, const AllocationCreateInfo *pAllocationCreateInfo,
    uint32_t *pMemoryTypeIndex) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaFindMemoryTypeIndexForImageInfo(m_allocator, pImageCreateInfo,
                                          reinterpret_cast<const VkmaAllocationCreateInfo *>(
                                            pAllocationCreateInfo),
                                          pMemoryTypeIndex));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<uint32_t>::type
  Allocator::findMemoryTypeIndexForImageInfo(
    const VkImageCreateInfo &imageCreateInfo,
    const AllocationCreateInfo &allocationCreateInfo) const {
    uint32_t memoryTypeIndex;
    Result result = static_cast<Result>(
      vkmaFindMemoryTypeIndexForImageInfo(m_allocator, &imageCreateInfo,
                                          reinterpret_cast<const VkmaAllocationCreateInfo *>(
                                            &allocationCreateInfo),
                                          &memoryTypeIndex));
    return createResultValue(result, memoryTypeIndex,
                             VKMA_NAMESPACE_STRING "::Allocator::findMemoryTypeIndexForImageInfo");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result Allocator::flushAllocation(
    Allocation allocation, VkDeviceSize offset, VkDeviceSize size) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaFlushAllocation(m_allocator, static_cast<VkmaAllocation>(allocation), offset, size));
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type
  Allocator::flushAllocation(Allocation allocation, VkDeviceSize offset, VkDeviceSize size) const {
    Result result = static_cast<Result>(
      vkmaFlushAllocation(m_allocator, static_cast<VkmaAllocation>(allocation), offset, size));
    return createResultValue(result, VKMA_NAMESPACE_STRING "::Allocator::flushAllocation");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result Allocator::flushAllocations(
    uint32_t allocationCount, const Allocation *allocations, const VkDeviceSize *offsets,
    const VkDeviceSize *sizes) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaFlushAllocations(m_allocator, allocationCount,
                           reinterpret_cast<const VkmaAllocation *>(allocations), offsets, sizes));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type
  Allocator::flushAllocations(uint32_t allocationCount, const Allocation &allocations,
                              const VkDeviceSize &offsets, const VkDeviceSize &sizes) const {
    Result result = static_cast<Result>(
      vkmaFlushAllocations(m_allocator, allocationCount,
                           reinterpret_cast<const VkmaAllocation *>(&allocations), &offsets,
                           &sizes));
    return createResultValue(result, VKMA_NAMESPACE_STRING "::Allocator::flushAllocations");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::freeMemory(const Allocation allocation) const VKMA_NOEXCEPT {
    vkmaFreeMemory(m_allocator, static_cast<VkmaAllocation>(allocation));
  }

  VKMA_INLINE void Allocator::free(const Allocation allocation) const VKMA_NOEXCEPT {
    vkmaFreeMemory(m_allocator, static_cast<VkmaAllocation>(allocation));
  }

  VKMA_INLINE void Allocator::freeMemoryPages(size_t allocationCount,
                                              const Allocation *pAllocations) const VKMA_NOEXCEPT {
    vkmaFreeMemoryPages(m_allocator, allocationCount,
                        reinterpret_cast<const VkmaAllocation *>(pAllocations));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_INLINE void Allocator::freeMemoryPages(size_t allocationCount,
                                              const Allocation &allocations) const VKMA_NOEXCEPT {
    vkmaFreeMemoryPages(m_allocator, allocationCount,
                        reinterpret_cast<const VkmaAllocation *>(&allocations));
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::free(size_t allocationCount,
                                   const Allocation *pAllocations) const VKMA_NOEXCEPT {
    vkmaFreeMemoryPages(m_allocator, allocationCount,
                        reinterpret_cast<const VkmaAllocation *>(pAllocations));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_INLINE void Allocator::free(size_t allocationCount,
                                   const Allocation &allocations) const VKMA_NOEXCEPT {
    vkmaFreeMemoryPages(m_allocator, allocationCount,
                        reinterpret_cast<const VkmaAllocation *>(&allocations));
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::freeStatsString(const char *pStatsString) const VKMA_NOEXCEPT {
    vkmaFreeStatsString(m_allocator, pStatsString);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_INLINE void Allocator::freeStatsString(const char &statsString) const VKMA_NOEXCEPT {
    vkmaFreeStatsString(m_allocator, &statsString);
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::free(const char *pStatsString) const VKMA_NOEXCEPT {
    vkmaFreeStatsString(m_allocator, pStatsString);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_INLINE void Allocator::free(const char &statsString) const VKMA_NOEXCEPT {
    vkmaFreeStatsString(m_allocator, &statsString);
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::getAllocationInfo(
    Allocation allocation, AllocationInfo *pAllocationInfo) const VKMA_NOEXCEPT {
    vkmaGetAllocationInfo(m_allocator, static_cast<VkmaAllocation>(allocation),
                          reinterpret_cast<VkmaAllocationInfo *>(pAllocationInfo));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::AllocationInfo
  Allocator::getAllocationInfo(Allocation allocation) const VKMA_NOEXCEPT {
    VKMA_NAMESPACE::AllocationInfo allocationInfo;
    vkmaGetAllocationInfo(m_allocator, static_cast<VkmaAllocation>(allocation),
                          reinterpret_cast<VkmaAllocationInfo *>(&allocationInfo));
    return allocationInfo;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::getAllocationMemoryProperties(
    Allocation allocation, VkMemoryPropertyFlags *pFlags) const VKMA_NOEXCEPT {
    vkmaGetAllocationMemoryProperties(m_allocator, static_cast<VkmaAllocation>(allocation), pFlags);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VkMemoryPropertyFlags
  Allocator::getAllocationMemoryProperties(Allocation allocation) const VKMA_NOEXCEPT {
    VkMemoryPropertyFlags flags;
    vkmaGetAllocationMemoryProperties(m_allocator, static_cast<VkmaAllocation>(allocation), &flags);
    return flags;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::getHeapBudgets(Budget *pBudgets) const VKMA_NOEXCEPT {
    vkmaGetHeapBudgets(m_allocator, reinterpret_cast<VkmaBudget *>(pBudgets));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::Budget
  Allocator::getHeapBudgets() const VKMA_NOEXCEPT {
    VKMA_NAMESPACE::Budget budgets;
    vkmaGetHeapBudgets(m_allocator, reinterpret_cast<VkmaBudget *>(&budgets));
    return budgets;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::getMemoryProperties(
    VkPhysicalDeviceMemoryProperties *pPhysicalDeviceMemoryProperties) const VKMA_NOEXCEPT {
    vkmaGetMemoryProperties(m_allocator, pPhysicalDeviceMemoryProperties);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VkPhysicalDeviceMemoryProperties
  Allocator::getMemoryProperties() const VKMA_NOEXCEPT {
    VkPhysicalDeviceMemoryProperties physicalDeviceMemoryProperties;
    vkmaGetMemoryProperties(m_allocator, &physicalDeviceMemoryProperties);
    return physicalDeviceMemoryProperties;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::getMemoryTypeProperties(
    uint32_t memoryTypeIndex, VkMemoryPropertyFlags *pFlags) const VKMA_NOEXCEPT {
    vkmaGetMemoryTypeProperties(m_allocator, memoryTypeIndex, pFlags);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VkMemoryPropertyFlags
  Allocator::getMemoryTypeProperties(uint32_t memoryTypeIndex) const VKMA_NOEXCEPT {
    VkMemoryPropertyFlags flags;
    vkmaGetMemoryTypeProperties(m_allocator, memoryTypeIndex, &flags);
    return flags;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::getPhysicalDeviceProperties(
    VkPhysicalDeviceProperties *pPhysicalDeviceProperties) const VKMA_NOEXCEPT {
    vkmaGetPhysicalDeviceProperties(m_allocator, pPhysicalDeviceProperties);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VkPhysicalDeviceProperties
  Allocator::getPhysicalDeviceProperties() const VKMA_NOEXCEPT {
    VkPhysicalDeviceProperties physicalDeviceProperties;
    vkmaGetPhysicalDeviceProperties(m_allocator, &physicalDeviceProperties);
    return physicalDeviceProperties;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::getPoolName(Pool pool, const char **ppName) const VKMA_NOEXCEPT {
    vkmaGetPoolName(m_allocator, static_cast<VkmaPool>(pool), ppName);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE const char *Allocator::getPoolName(Pool pool) const VKMA_NOEXCEPT {
    const char *pName;
    vkmaGetPoolName(m_allocator, static_cast<VkmaPool>(pool), &pName);
    return pName;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::getPoolStatistics(Pool pool,
                                                Statistics *pPoolStats) const VKMA_NOEXCEPT {
    vkmaGetPoolStatistics(m_allocator, static_cast<VkmaPool>(pool),
                          reinterpret_cast<VkmaStatistics *>(pPoolStats));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::Statistics
  Allocator::getPoolStatistics(Pool pool) const VKMA_NOEXCEPT {
    VKMA_NAMESPACE::Statistics poolStats;
    vkmaGetPoolStatistics(m_allocator, static_cast<VkmaPool>(pool),
                          reinterpret_cast<VkmaStatistics *>(&poolStats));
    return poolStats;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result Allocator::invalidateAllocation(
    Allocation allocation, VkDeviceSize offset, VkDeviceSize size) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaInvalidateAllocation(m_allocator, static_cast<VkmaAllocation>(allocation), offset, size));
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type
  Allocator::invalidateAllocation(Allocation allocation, VkDeviceSize offset,
                                  VkDeviceSize size) const {
    Result result = static_cast<Result>(
      vkmaInvalidateAllocation(m_allocator, static_cast<VkmaAllocation>(allocation), offset, size));
    return createResultValue(result, VKMA_NAMESPACE_STRING "::Allocator::invalidateAllocation");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result Allocator::invalidateAllocations(
    uint32_t allocationCount, const Allocation *allocations, const VkDeviceSize *offsets,
    const VkDeviceSize *sizes) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaInvalidateAllocations(m_allocator, allocationCount,
                                reinterpret_cast<const VkmaAllocation *>(allocations), offsets,
                                sizes));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type
  Allocator::invalidateAllocations(uint32_t allocationCount, const Allocation &allocations,
                                   const VkDeviceSize &offsets, const VkDeviceSize &sizes) const {
    Result result = static_cast<Result>(
      vkmaInvalidateAllocations(m_allocator, allocationCount,
                                reinterpret_cast<const VkmaAllocation *>(&allocations), &offsets,
                                &sizes));
    return createResultValue(result, VKMA_NAMESPACE_STRING "::Allocator::invalidateAllocations");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result Allocator::mapMemory(Allocation allocation,
                                                         void **ppData) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaMapMemory(m_allocator, static_cast<VkmaAllocation>(allocation), ppData));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void *>::type
  Allocator::mapMemory(Allocation allocation) const {
    void *pData;
    Result result = static_cast<Result>(
      vkmaMapMemory(m_allocator, static_cast<VkmaAllocation>(allocation), &pData));
    return createResultValue(result, pData, VKMA_NAMESPACE_STRING "::Allocator::mapMemory");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::setAllocationName(Allocation allocation,
                                                const char *pName) const VKMA_NOEXCEPT {
    vkmaSetAllocationName(m_allocator, static_cast<VkmaAllocation>(allocation), pName);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_INLINE void Allocator::setAllocationName(Allocation allocation,
                                                const char &name) const VKMA_NOEXCEPT {
    vkmaSetAllocationName(m_allocator, static_cast<VkmaAllocation>(allocation), &name);
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::setAllocationUserData(Allocation allocation,
                                                    const void *pUserData) const VKMA_NOEXCEPT {
    vkmaSetAllocationUserData(m_allocator, static_cast<VkmaAllocation>(allocation), pUserData);
  }

  VKMA_INLINE void Allocator::setCurrentFrameIndex(uint32_t frameIndex) const VKMA_NOEXCEPT {
    vkmaSetCurrentFrameIndex(m_allocator, frameIndex);
  }

  VKMA_INLINE void Allocator::setPoolName(Pool pool, const char *pName) const VKMA_NOEXCEPT {
    vkmaSetPoolName(m_allocator, static_cast<VkmaPool>(pool), pName);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_INLINE void Allocator::setPoolName(Pool pool, const char &name) const VKMA_NOEXCEPT {
    vkmaSetPoolName(m_allocator, static_cast<VkmaPool>(pool), &name);
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Allocator::unmapMemory(Allocation allocation) const VKMA_NOEXCEPT {
    vkmaUnmapMemory(m_allocator, static_cast<VkmaAllocation>(allocation));
  }

  VKMA_INLINE void Buffer::get(VkBuffer *pBuffer) const VKMA_NOEXCEPT {
    vkmaGetBuffer(m_buffer, pBuffer);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VkBuffer Buffer::get() const VKMA_NOEXCEPT {
    VkBuffer buffer;
    vkmaGetBuffer(m_buffer, &buffer);
    return buffer;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Buffer::getAllocation(Allocation *pAllocation) const VKMA_NOEXCEPT {
    vkmaGetBufferAllocation(m_buffer, reinterpret_cast<VkmaAllocation *>(pAllocation));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::Allocation
  Buffer::getAllocation() const VKMA_NOEXCEPT {
    VKMA_NAMESPACE::Allocation allocation;
    vkmaGetBufferAllocation(m_buffer, reinterpret_cast<VkmaAllocation *>(&allocation));
    return allocation;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Image::get(VkImage *pImage) const VKMA_NOEXCEPT {
    vkmaGetImage(m_image, pImage);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VkImage Image::get() const VKMA_NOEXCEPT {
    VkImage image;
    vkmaGetImage(m_image, &image);
    return image;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void Image::getAllocation(Allocation *pAllocation) const VKMA_NOEXCEPT {
    vkmaGetImageAllocation(m_image, reinterpret_cast<VkmaAllocation *>(pAllocation));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::Allocation Image::getAllocation() const VKMA_NOEXCEPT {
    VKMA_NAMESPACE::Allocation allocation;
    vkmaGetImageAllocation(m_image, reinterpret_cast<VkmaAllocation *>(&allocation));
    return allocation;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void VirtualBlock::buildStatsString(VkBool32 detailedMap,
                                                  char **ppStatsString) const VKMA_NOEXCEPT {
    vkmaBuildVirtualBlockStatsString(m_virtualBlock, detailedMap, ppStatsString);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE char *
  VirtualBlock::buildStatsString(VkBool32 detailedMap) const VKMA_NOEXCEPT {
    char *pStatsString;
    vkmaBuildVirtualBlockStatsString(m_virtualBlock, detailedMap, &pStatsString);
    return pStatsString;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void
  VirtualBlock::calculateStatistics(DetailedStatistics *pStats) const VKMA_NOEXCEPT {
    vkmaCalculateVirtualBlockStatistics(m_virtualBlock,
                                        reinterpret_cast<VkmaDetailedStatistics *>(pStats));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::DetailedStatistics
  VirtualBlock::calculateStatistics() const VKMA_NOEXCEPT {
    VKMA_NAMESPACE::DetailedStatistics stats;
    vkmaCalculateVirtualBlockStatistics(m_virtualBlock,
                                        reinterpret_cast<VkmaDetailedStatistics *>(&stats));
    return stats;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void VirtualBlock::clear() const VKMA_NOEXCEPT {
    vkmaClearVirtualBlock(m_virtualBlock);
  }

  VKMA_INLINE void VirtualBlock::destroy() const VKMA_NOEXCEPT {
    vkmaDestroyVirtualBlock(m_virtualBlock);
  }

  VKMA_INLINE void VirtualBlock::freeStatsString(const char *pStatsString) const VKMA_NOEXCEPT {
    vkmaFreeVirtualBlockStatsString(m_virtualBlock, pStatsString);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_INLINE void VirtualBlock::freeStatsString(const char &statsString) const VKMA_NOEXCEPT {
    vkmaFreeVirtualBlockStatsString(m_virtualBlock, &statsString);
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void VirtualBlock::free(const char *pStatsString) const VKMA_NOEXCEPT {
    vkmaFreeVirtualBlockStatsString(m_virtualBlock, pStatsString);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_INLINE void VirtualBlock::free(const char &statsString) const VKMA_NOEXCEPT {
    vkmaFreeVirtualBlockStatsString(m_virtualBlock, &statsString);
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void VirtualBlock::getVirtualAllocationInfo(
    VirtualAllocation allocation, VirtualAllocationInfo *pVirtualAllocInfo) const VKMA_NOEXCEPT {
    vkmaGetVirtualAllocationInfo(m_virtualBlock, static_cast<VkmaVirtualAllocation>(allocation),
                                 reinterpret_cast<VkmaVirtualAllocationInfo *>(pVirtualAllocInfo));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::VirtualAllocationInfo
  VirtualBlock::getVirtualAllocationInfo(VirtualAllocation allocation) const VKMA_NOEXCEPT {
    VKMA_NAMESPACE::VirtualAllocationInfo virtualAllocInfo;
    vkmaGetVirtualAllocationInfo(m_virtualBlock, static_cast<VkmaVirtualAllocation>(allocation),
                                 reinterpret_cast<VkmaVirtualAllocationInfo *>(&virtualAllocInfo));
    return virtualAllocInfo;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE void VirtualBlock::getStatistics(Statistics *pStats) const VKMA_NOEXCEPT {
    vkmaGetVirtualBlockStatistics(m_virtualBlock, reinterpret_cast<VkmaStatistics *>(pStats));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::Statistics
  VirtualBlock::getStatistics() const VKMA_NOEXCEPT {
    VKMA_NAMESPACE::Statistics stats;
    vkmaGetVirtualBlockStatistics(m_virtualBlock, reinterpret_cast<VkmaStatistics *>(&stats));
    return stats;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_INLINE VkBool32 VirtualBlock::isEmpty() const VKMA_NOEXCEPT {
    return vkmaIsVirtualBlockEmpty(m_virtualBlock);
  }

  VKMA_INLINE void VirtualBlock::setVirtualAllocationUserData(VirtualAllocation allocation,
                                                              void *pUserData) const VKMA_NOEXCEPT {
    vkmaSetVirtualAllocationUserData(m_virtualBlock, static_cast<VkmaVirtualAllocation>(allocation),
                                     pUserData);
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE void
  VirtualBlock::setVirtualAllocationUserData(VirtualAllocation allocation) const VKMA_NOEXCEPT {
    void userData;
    vkmaSetVirtualAllocationUserData(m_virtualBlock, static_cast<VkmaVirtualAllocation>(allocation),
                                     &userData);
    return userData;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

  VKMA_NODISCARD VKMA_INLINE Result
  VirtualBlock::virtualAllocate(const VirtualAllocationCreateInfo *pCreateInfo,
                                VirtualAllocation *pAllocation) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaVirtualAllocate(m_virtualBlock,
                          reinterpret_cast<const VkmaVirtualAllocationCreateInfo *>(pCreateInfo),
                          reinterpret_cast<VkmaVirtualAllocation *>(pAllocation)));
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<VirtualAllocation>::type
  VirtualBlock::virtualAllocate(const VirtualAllocationCreateInfo &createInfo) const {
    VirtualAllocation allocation;
    Result result = static_cast<Result>(
      vkmaVirtualAllocate(m_virtualBlock,
                          reinterpret_cast<const VkmaVirtualAllocationCreateInfo *>(&createInfo),
                          reinterpret_cast<VkmaVirtualAllocation *>(&allocation)));
    return createResultValue(result, allocation,
                             VKMA_NAMESPACE_STRING "::VirtualBlock::virtualAllocate");
  }

  #ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE
    typename ResultValueType<UniqueHandle<VirtualAllocation>>::type
    VirtualBlock::virtualAllocateUnique(const VirtualAllocationCreateInfo &createInfo) const {
    VirtualAllocation allocation;
    Result result = static_cast<Result>(
      vkmaVirtualAllocate(m_virtualBlock,
                          reinterpret_cast<const VkmaVirtualAllocationCreateInfo *>(&createInfo),
                          reinterpret_cast<VkmaVirtualAllocation *>(&allocation)));
    ObjectFree<VirtualBlock> deleter(*this);
    return createResultValue<VirtualAllocation>(result, allocation,
                                                VKMA_NAMESPACE_STRING
                                                "::VirtualBlock::virtualAllocateUnique",
                                                deleter);
  }
  #endif /*VKMA_NO_SMART_HANDLE*/
#endif   /*VKMA_DISABLE_ENHANCED_MODE*/

#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result
  VirtualBlock::virtualFree(VirtualAllocation allocation) const VKMA_NOEXCEPT {
    return static_cast<Result>(
      vkmaVirtualFree(m_virtualBlock, static_cast<VkmaVirtualAllocation>(allocation)));
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type
  VirtualBlock::virtualFree(VirtualAllocation allocation) const {
    Result result = static_cast<Result>(
      vkmaVirtualFree(m_virtualBlock, static_cast<VkmaVirtualAllocation>(allocation)));
    return createResultValue(result, VKMA_NAMESPACE_STRING "::VirtualBlock::virtualFree");
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

} // namespace VKMA_NAMESPACE

namespace std {

  template <> struct hash<VKMA_NAMESPACE::Allocation> {
    std::size_t operator()(VKMA_NAMESPACE::Allocation const &allocation) const VKMA_NOEXCEPT {
      return std::hash<VkmaAllocation>{}(static_cast<VkmaAllocation>(allocation));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::Allocator> {
    std::size_t operator()(VKMA_NAMESPACE::Allocator const &allocator) const VKMA_NOEXCEPT {
      return std::hash<VkmaAllocator>{}(static_cast<VkmaAllocator>(allocator));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::Buffer> {
    std::size_t operator()(VKMA_NAMESPACE::Buffer const &buffer) const VKMA_NOEXCEPT {
      return std::hash<VkmaBuffer>{}(static_cast<VkmaBuffer>(buffer));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::DefragmentationContext> {
    std::size_t operator()(
      VKMA_NAMESPACE::DefragmentationContext const &defragmentationContext) const VKMA_NOEXCEPT {
      return std::hash<VkmaDefragmentationContext>{}(
        static_cast<VkmaDefragmentationContext>(defragmentationContext));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::Image> {
    std::size_t operator()(VKMA_NAMESPACE::Image const &image) const VKMA_NOEXCEPT {
      return std::hash<VkmaImage>{}(static_cast<VkmaImage>(image));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::Pool> {
    std::size_t operator()(VKMA_NAMESPACE::Pool const &pool) const VKMA_NOEXCEPT {
      return std::hash<VkmaPool>{}(static_cast<VkmaPool>(pool));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::VirtualAllocation> {
    std::size_t
    operator()(VKMA_NAMESPACE::VirtualAllocation const &virtualAllocation) const VKMA_NOEXCEPT {
      return std::hash<VkmaVirtualAllocation>{}(
        static_cast<VkmaVirtualAllocation>(virtualAllocation));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::VirtualBlock> {
    std::size_t operator()(VKMA_NAMESPACE::VirtualBlock const &virtualBlock) const VKMA_NOEXCEPT {
      return std::hash<VkmaVirtualBlock>{}(static_cast<VkmaVirtualBlock>(virtualBlock));
    }
  };
} // namespace std
#endif
