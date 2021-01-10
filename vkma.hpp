// Copyright (c) 2021 Cvelth (cvelth.mail@gmail.com)
// SPDX-License-Identifier: Unlicense.
// 
// DO NOT MODIFY MANUALLY!
// This file was generated using [generator](https://github.com/Cvelth/vma_xml_generator).
// Generated files are licensed under [The Unlicense](https://unlicense.org).
// The generator itself is licensed under [MIT License](https://www.mit.edu/~amini/LICENSE.md).

// This header is generated from the Khronos Vulkan XML API Registry.

#ifndef VULKAN_HPP
#define VULKAN_HPP

#if defined( _MSVC_LANG )
#  define VULKAN_HPP_CPLUSPLUS _MSVC_LANG
#else
#  define VULKAN_HPP_CPLUSPLUS __cplusplus
#endif

#if 201703L < VULKAN_HPP_CPLUSPLUS
#  define VULKAN_HPP_CPP_VERSION 20
#elif 201402L < VULKAN_HPP_CPLUSPLUS
#  define VULKAN_HPP_CPP_VERSION 17
#elif 201103L < VULKAN_HPP_CPLUSPLUS
#  define VULKAN_HPP_CPP_VERSION 14
#elif 199711L < VULKAN_HPP_CPLUSPLUS
#  define VULKAN_HPP_CPP_VERSION 11
#else
#  error "vulkan.hpp needs at least c++ standard version 11"
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
#include <vulkan/vulkan.h>

#if 17 <= VULKAN_HPP_CPP_VERSION
#include <string_view>
#endif

#if defined(VULKAN_HPP_DISABLE_ENHANCED_MODE)
# if !defined(VULKAN_HPP_NO_SMART_HANDLE)
#  define VULKAN_HPP_NO_SMART_HANDLE
# endif
#else
# include <memory>
# include <vector>
#endif

#if !defined(VULKAN_HPP_ASSERT)
# include <cassert>
# define VULKAN_HPP_ASSERT   assert
#endif

#if !defined(VULKAN_HPP_ASSERT_ON_RESULT)
# define VULKAN_HPP_ASSERT_ON_RESULT VULKAN_HPP_ASSERT
#endif

#if !defined(VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL)
# define VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL 1
#endif

#if VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL == 1
#  if defined( __linux__ ) || defined( __APPLE__ )
#    include <dlfcn.h>
#  elif defined( _WIN32 )
typedef struct HINSTANCE__ * HINSTANCE;
#    if defined( _WIN64 )
typedef int64_t( __stdcall * FARPROC )();
#    else
typedef int( __stdcall * FARPROC )();
#    endif
extern "C" __declspec( dllimport ) HINSTANCE __stdcall LoadLibraryA( char const * lpLibFileName );
extern "C" __declspec( dllimport ) int __stdcall FreeLibrary( HINSTANCE hLibModule );
extern "C" __declspec( dllimport ) FARPROC __stdcall GetProcAddress( HINSTANCE hModule, const char * lpProcName );
#  endif
#endif

#if !defined(__has_include)
# define __has_include(x) false
#endif

#if ( 201711 <= __cpp_impl_three_way_comparison ) && __has_include( <compare> ) && !defined( VULKAN_HPP_NO_SPACESHIP_OPERATOR )
# define VULKAN_HPP_HAS_SPACESHIP_OPERATOR
#endif
#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
# include <compare>
#endif


static_assert( VK_HEADER_VERSION ==  , "Wrong VK_HEADER_VERSION!" );

// 32-bit vulkan is not typesafe for handles, so don't allow copy constructors on this platform by default.
// To enable this feature on 32-bit platforms please define VULKAN_HPP_TYPESAFE_CONVERSION

# if !defined( VULKAN_HPP_TYPESAFE_CONVERSION )
#  define VULKAN_HPP_TYPESAFE_CONVERSION
# endif
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
// with the VULKAN_HPP_NAMESPACE::MemoryBarrier struct.
#if defined(MemoryBarrier)
  #undef MemoryBarrier
#endif

#if !defined(VULKAN_HPP_HAS_UNRESTRICTED_UNIONS)
# if defined(__clang__)
#  if __has_feature(cxx_unrestricted_unions)
#   define VULKAN_HPP_HAS_UNRESTRICTED_UNIONS
#  endif
# elif defined(__GNUC__)
#  define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#  if 40600 <= GCC_VERSION
#   define VULKAN_HPP_HAS_UNRESTRICTED_UNIONS
#  endif
# elif defined(_MSC_VER)
#  if 1900 <= _MSC_VER
#   define VULKAN_HPP_HAS_UNRESTRICTED_UNIONS
#  endif
# endif
#endif

#if !defined(VULKAN_HPP_INLINE)
# if defined(__clang__)
#  if __has_attribute(always_inline)
#   define VULKAN_HPP_INLINE __attribute__((always_inline)) __inline__
#  else
#   define VULKAN_HPP_INLINE inline
#  endif
# elif defined(__GNUC__)
#  define VULKAN_HPP_INLINE __attribute__((always_inline)) __inline__
# elif defined(_MSC_VER)
#  define VULKAN_HPP_INLINE inline
# else
#  define VULKAN_HPP_INLINE inline
# endif
#endif

#if defined(VULKAN_HPP_TYPESAFE_CONVERSION)
# define VULKAN_HPP_TYPESAFE_EXPLICIT
#else
# define VULKAN_HPP_TYPESAFE_EXPLICIT explicit
#endif

#if defined(__cpp_constexpr)
# define VULKAN_HPP_CONSTEXPR constexpr
# if __cpp_constexpr >= 201304
#  define VULKAN_HPP_CONSTEXPR_14  constexpr
# else
#  define VULKAN_HPP_CONSTEXPR_14
# endif
# define VULKAN_HPP_CONST_OR_CONSTEXPR  constexpr
#else
# define VULKAN_HPP_CONSTEXPR
# define VULKAN_HPP_CONSTEXPR_14
# define VULKAN_HPP_CONST_OR_CONSTEXPR  const
#endif

#if !defined(VULKAN_HPP_NOEXCEPT)
# if defined(_MSC_VER) && (_MSC_VER <= 1800)
#  define VULKAN_HPP_NOEXCEPT
# else
#  define VULKAN_HPP_NOEXCEPT noexcept
#  define VULKAN_HPP_HAS_NOEXCEPT 1
#  if defined(VULKAN_HPP_NO_EXCEPTIONS)
#    define VULKAN_HPP_NOEXCEPT_WHEN_NO_EXCEPTIONS noexcept
#  else
#    define VULKAN_HPP_NOEXCEPT_WHEN_NO_EXCEPTIONS
#  endif
# endif
#endif

#if 14 <= VULKAN_HPP_CPP_VERSION
#  define VULKAN_HPP_DEPRECATED( msg ) [[deprecated( msg )]]
#else
#  define VULKAN_HPP_DEPRECATED( msg )
#endif

#if ( 17 <= VULKAN_HPP_CPP_VERSION ) && !defined( VULKAN_HPP_NO_NODISCARD_WARNINGS )
#  define VULKAN_HPP_NODISCARD [[nodiscard]]
#  if defined(VULKAN_HPP_NO_EXCEPTIONS)
#    define VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS [[nodiscard]]
#  else
#    define VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS
#  endif
#else
#  define VULKAN_HPP_NODISCARD
#  define VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS
#endif

#if !defined(VULKAN_HPP_NAMESPACE)
#define VULKAN_HPP_NAMESPACE vk
#endif

#define VULKAN_HPP_STRINGIFY2(text) #text
#define VULKAN_HPP_STRINGIFY(text) VULKAN_HPP_STRINGIFY2(text)
#define VULKAN_HPP_NAMESPACE_STRING VULKAN_HPP_STRINGIFY(VULKAN_HPP_NAMESPACE)

namespace VULKAN_HPP_NAMESPACE
{

#if !defined(VULKAN_HPP_DISABLE_ENHANCED_MODE)
  template <typename T>
  class ArrayProxy
  {
  public:
    VULKAN_HPP_CONSTEXPR ArrayProxy() VULKAN_HPP_NOEXCEPT
      : m_count( 0 )
      , m_ptr( nullptr )
    {}

    VULKAN_HPP_CONSTEXPR ArrayProxy( std::nullptr_t ) VULKAN_HPP_NOEXCEPT
      : m_count( 0 )
      , m_ptr( nullptr )
    {}

    ArrayProxy( T & value ) VULKAN_HPP_NOEXCEPT
      : m_count( 1 )
      , m_ptr( &value )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( typename std::remove_const<T>::type & value ) VULKAN_HPP_NOEXCEPT
      : m_count( 1 )
      , m_ptr( &value )
    {}

    ArrayProxy( uint32_t count, T * ptr ) VULKAN_HPP_NOEXCEPT
      : m_count( count )
      , m_ptr( ptr )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( uint32_t count, typename std::remove_const<T>::type * ptr ) VULKAN_HPP_NOEXCEPT
      : m_count( count )
      , m_ptr( ptr )
    {}

    ArrayProxy( std::initializer_list<T> const & list ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( std::initializer_list<typename std::remove_const<T>::type> const & list ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    ArrayProxy( std::initializer_list<T> & list ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( std::initializer_list<typename std::remove_const<T>::type> & list ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    template <size_t N>
    ArrayProxy( std::array<T, N> const & data ) VULKAN_HPP_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <size_t N, typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( std::array<typename std::remove_const<T>::type, N> const & data ) VULKAN_HPP_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <size_t N>
    ArrayProxy( std::array<T, N> & data ) VULKAN_HPP_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <size_t N, typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( std::array<typename std::remove_const<T>::type, N> & data ) VULKAN_HPP_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxy( std::vector<T, Allocator> const & data ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>,
              typename B      = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( std::vector<typename std::remove_const<T>::type, Allocator> const & data ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxy( std::vector<T, Allocator> & data ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>,
              typename B      = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( std::vector<typename std::remove_const<T>::type, Allocator> & data ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    const T * begin() const VULKAN_HPP_NOEXCEPT
    {
      return m_ptr;
    }

    const T * end() const VULKAN_HPP_NOEXCEPT
    {
      return m_ptr + m_count;
    }

    const T & front() const VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( m_count && m_ptr );
      return *m_ptr;
    }

    const T & back() const VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( m_count && m_ptr );
      return *( m_ptr + m_count - 1 );
    }

    bool empty() const VULKAN_HPP_NOEXCEPT
    {
      return ( m_count == 0 );
    }

    uint32_t size() const VULKAN_HPP_NOEXCEPT
    {
      return m_count;
    }

    T * data() const VULKAN_HPP_NOEXCEPT
    {
      return m_ptr;
    }

  private:
    uint32_t m_count;
    T *      m_ptr;
  };

  template <typename T>
  class ArrayProxyNoTemporaries
  {
  public:
    VULKAN_HPP_CONSTEXPR ArrayProxyNoTemporaries() VULKAN_HPP_NOEXCEPT
      : m_count( 0 )
      , m_ptr( nullptr )
    {}

    VULKAN_HPP_CONSTEXPR ArrayProxyNoTemporaries( std::nullptr_t ) VULKAN_HPP_NOEXCEPT
      : m_count( 0 )
      , m_ptr( nullptr )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( typename std::remove_const<T>::type & value ) VULKAN_HPP_NOEXCEPT
      : m_count( 1 )
      , m_ptr( &value )
    {}

    ArrayProxyNoTemporaries( uint32_t count, T * ptr ) VULKAN_HPP_NOEXCEPT
      : m_count( count )
      , m_ptr( ptr )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( uint32_t count, typename std::remove_const<T>::type * ptr ) VULKAN_HPP_NOEXCEPT
      : m_count( count )
      , m_ptr( ptr )
    {}

    ArrayProxyNoTemporaries( std::initializer_list<T> const & list ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::initializer_list<typename std::remove_const<T>::type> const & list ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    ArrayProxyNoTemporaries( std::initializer_list<T> & list ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::initializer_list<typename std::remove_const<T>::type> & list ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    ArrayProxyNoTemporaries( std::initializer_list<T> const && list ) VULKAN_HPP_NOEXCEPT = delete;
    ArrayProxyNoTemporaries( std::initializer_list<T> && list ) VULKAN_HPP_NOEXCEPT       = delete;

    template <size_t N>
    ArrayProxyNoTemporaries( std::array<T, N> const & data ) VULKAN_HPP_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <size_t N, typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::array<typename std::remove_const<T>::type, N> const & data ) VULKAN_HPP_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <size_t N>
    ArrayProxyNoTemporaries( std::array<T, N> & data ) VULKAN_HPP_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <size_t N, typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::array<typename std::remove_const<T>::type, N> & data ) VULKAN_HPP_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <size_t N>
    ArrayProxyNoTemporaries( std::array<T, N> const && data ) VULKAN_HPP_NOEXCEPT = delete;
    template <size_t N>
    ArrayProxyNoTemporaries( std::array<T, N> && data ) VULKAN_HPP_NOEXCEPT       = delete;

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxyNoTemporaries( std::vector<T, Allocator> const & data ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>,
              typename B      = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::vector<typename std::remove_const<T>::type, Allocator> const & data ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxyNoTemporaries( std::vector<T, Allocator> & data ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>,
              typename B      = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::vector<typename std::remove_const<T>::type, Allocator> & data ) VULKAN_HPP_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    ArrayProxyNoTemporaries( std::vector<T> const && data ) VULKAN_HPP_NOEXCEPT = delete;
    ArrayProxyNoTemporaries( std::vector<T> && data ) VULKAN_HPP_NOEXCEPT       = delete;

    const T * begin() const VULKAN_HPP_NOEXCEPT
    {
      return m_ptr;
    }

    const T * end() const VULKAN_HPP_NOEXCEPT
    {
      return m_ptr + m_count;
    }

    const T & front() const VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( m_count && m_ptr );
      return *m_ptr;
    }

    const T & back() const VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( m_count && m_ptr );
      return *( m_ptr + m_count - 1 );
    }

    bool empty() const VULKAN_HPP_NOEXCEPT
    {
      return ( m_count == 0 );
    }

    uint32_t size() const VULKAN_HPP_NOEXCEPT
    {
      return m_count;
    }

    T * data() const VULKAN_HPP_NOEXCEPT
    {
      return m_ptr;
    }

  private:
    uint32_t m_count;
    T *      m_ptr;
  };
#endif

  template <typename T, size_t N>
  class ArrayWrapper1D : public std::array<T,N>
  {
  public:
    VULKAN_HPP_CONSTEXPR ArrayWrapper1D() VULKAN_HPP_NOEXCEPT
      : std::array<T, N>()
    {}

    VULKAN_HPP_CONSTEXPR ArrayWrapper1D(std::array<T,N> const& data) VULKAN_HPP_NOEXCEPT
      : std::array<T, N>(data)
    {}

#if defined(_WIN32) && !defined(_WIN64)
    VULKAN_HPP_CONSTEXPR T const& operator[](int index) const VULKAN_HPP_NOEXCEPT
    {
      return std::array<T, N>::operator[](index);
    }

    T & operator[](int index) VULKAN_HPP_NOEXCEPT
    {
      return std::array<T, N>::operator[](index);
    }
#endif

    operator T const* () const VULKAN_HPP_NOEXCEPT
    {
      return this->data();
    }

    operator T * () VULKAN_HPP_NOEXCEPT
    {
      return this->data();
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    operator std::string() const
    {
      return std::string( this->data() );
    }

#if 17 <= VULKAN_HPP_CPP_VERSION
    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    operator std::string_view() const
    {
      return std::string_view( this->data() );
    }
#endif

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator<( ArrayWrapper1D<char, N> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) < *static_cast<std::array<char, N> const *>( &rhs );
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator<=( ArrayWrapper1D<char, N> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) <= *static_cast<std::array<char, N> const *>( &rhs );
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator>( ArrayWrapper1D<char, N> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) > *static_cast<std::array<char, N> const *>( &rhs );
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator>=( ArrayWrapper1D<char, N> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) >= *static_cast<std::array<char, N> const *>( &rhs );
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator==( ArrayWrapper1D<char, N> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) == *static_cast<std::array<char, N> const *>( &rhs );
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator!=( ArrayWrapper1D<char, N> const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) != *static_cast<std::array<char, N> const *>( &rhs );
    }
  };

  // specialization of relational operators between std::string and arrays of chars
  template <size_t N>
  bool operator<(std::string const& lhs, ArrayWrapper1D<char, N> const& rhs) VULKAN_HPP_NOEXCEPT
  {
    return lhs < rhs.data();
  }

  template <size_t N>
  bool operator<=(std::string const& lhs, ArrayWrapper1D<char, N> const& rhs) VULKAN_HPP_NOEXCEPT
  {
    return lhs <= rhs.data();
  }

  template <size_t N>
  bool operator>(std::string const& lhs, ArrayWrapper1D<char, N> const& rhs) VULKAN_HPP_NOEXCEPT
  {
    return lhs > rhs.data();
  }

  template <size_t N>
  bool operator>=(std::string const& lhs, ArrayWrapper1D<char, N> const& rhs) VULKAN_HPP_NOEXCEPT
  {
    return lhs >= rhs.data();
  }

  template <size_t N>
  bool operator==(std::string const& lhs, ArrayWrapper1D<char, N> const& rhs) VULKAN_HPP_NOEXCEPT
  {
    return lhs == rhs.data();
  }

  template <size_t N>
  bool operator!=(std::string const& lhs, ArrayWrapper1D<char, N> const& rhs) VULKAN_HPP_NOEXCEPT
  {
    return lhs != rhs.data();
  }

  template <typename T, size_t N, size_t M>
  class ArrayWrapper2D : public std::array<ArrayWrapper1D<T,M>,N>
  {
  public:
    VULKAN_HPP_CONSTEXPR ArrayWrapper2D() VULKAN_HPP_NOEXCEPT
      : std::array<ArrayWrapper1D<T,M>, N>()
    {}

    VULKAN_HPP_CONSTEXPR ArrayWrapper2D(std::array<std::array<T,M>,N> const& data) VULKAN_HPP_NOEXCEPT
      : std::array<ArrayWrapper1D<T,M>, N>(*reinterpret_cast<std::array<ArrayWrapper1D<T,M>,N> const*>(&data))
    {}
  };

  template <typename FlagBitsType> struct FlagTraits
  {
    enum { allFlags = 0 };
  };

  template <typename BitType>
  class Flags
  {
  public:
    using MaskType = typename std::underlying_type<BitType>::type;

    // constructors
    VULKAN_HPP_CONSTEXPR Flags() VULKAN_HPP_NOEXCEPT
      : m_mask(0)
    {}

    VULKAN_HPP_CONSTEXPR Flags(BitType bit) VULKAN_HPP_NOEXCEPT
      : m_mask(static_cast<MaskType>(bit))
    {}

    VULKAN_HPP_CONSTEXPR Flags(Flags<BitType> const& rhs) VULKAN_HPP_NOEXCEPT = default;

    VULKAN_HPP_CONSTEXPR explicit Flags(MaskType flags) VULKAN_HPP_NOEXCEPT
      : m_mask(flags)
    {}

    // relational operators
#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(Flags<BitType> const&) const = default;
#else
    VULKAN_HPP_CONSTEXPR bool operator<(Flags<BitType> const& rhs) const VULKAN_HPP_NOEXCEPT
    {
      return m_mask < rhs.m_mask;
    }

    VULKAN_HPP_CONSTEXPR bool operator<=(Flags<BitType> const& rhs) const VULKAN_HPP_NOEXCEPT
    {
      return m_mask <= rhs.m_mask;
    }

    VULKAN_HPP_CONSTEXPR bool operator>(Flags<BitType> const& rhs) const VULKAN_HPP_NOEXCEPT
    {
      return m_mask > rhs.m_mask;
    }

    VULKAN_HPP_CONSTEXPR bool operator>=(Flags<BitType> const& rhs) const VULKAN_HPP_NOEXCEPT
    {
      return m_mask >= rhs.m_mask;
    }

    VULKAN_HPP_CONSTEXPR bool operator==(Flags<BitType> const& rhs) const VULKAN_HPP_NOEXCEPT
    {
      return m_mask == rhs.m_mask;
    }

    VULKAN_HPP_CONSTEXPR bool operator!=(Flags<BitType> const& rhs) const VULKAN_HPP_NOEXCEPT
    {
      return m_mask != rhs.m_mask;
    }
#endif

    // logical operator
    VULKAN_HPP_CONSTEXPR bool operator!() const VULKAN_HPP_NOEXCEPT
    {
      return !m_mask;
    }

    // bitwise operators
    VULKAN_HPP_CONSTEXPR Flags<BitType> operator&(Flags<BitType> const& rhs) const VULKAN_HPP_NOEXCEPT
    {
      return Flags<BitType>(m_mask & rhs.m_mask);
    }

    VULKAN_HPP_CONSTEXPR Flags<BitType> operator|(Flags<BitType> const& rhs) const VULKAN_HPP_NOEXCEPT
    {
      return Flags<BitType>(m_mask | rhs.m_mask);
    }

    VULKAN_HPP_CONSTEXPR Flags<BitType> operator^(Flags<BitType> const& rhs) const VULKAN_HPP_NOEXCEPT
    {
      return Flags<BitType>(m_mask ^ rhs.m_mask);
    }

    VULKAN_HPP_CONSTEXPR Flags<BitType> operator~() const VULKAN_HPP_NOEXCEPT
    {
      return Flags<BitType>(m_mask ^ FlagTraits<BitType>::allFlags);
    }

    // assignment operators
    VULKAN_HPP_CONSTEXPR_14 Flags<BitType> & operator=(Flags<BitType> const& rhs) VULKAN_HPP_NOEXCEPT = default;

    VULKAN_HPP_CONSTEXPR_14 Flags<BitType> & operator|=(Flags<BitType> const& rhs) VULKAN_HPP_NOEXCEPT
    {
      m_mask |= rhs.m_mask;
      return *this;
    }

    VULKAN_HPP_CONSTEXPR_14 Flags<BitType> & operator&=(Flags<BitType> const& rhs) VULKAN_HPP_NOEXCEPT
    {
      m_mask &= rhs.m_mask;
      return *this;
    }

    VULKAN_HPP_CONSTEXPR_14 Flags<BitType> & operator^=(Flags<BitType> const& rhs) VULKAN_HPP_NOEXCEPT
    {
      m_mask ^= rhs.m_mask;
      return *this;
    }

    // cast operators
    explicit VULKAN_HPP_CONSTEXPR operator bool() const VULKAN_HPP_NOEXCEPT
    {
      return !!m_mask;
    }

    explicit VULKAN_HPP_CONSTEXPR operator MaskType() const VULKAN_HPP_NOEXCEPT
    {
        return m_mask;
    }

  private:
    MaskType  m_mask;
  };

#if !defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
  // relational operators only needed for pre C++20
  template <typename BitType>
  VULKAN_HPP_CONSTEXPR bool operator<(BitType bit, Flags<BitType> const& flags) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator>( bit );
  }

  template <typename BitType>
  VULKAN_HPP_CONSTEXPR bool operator<=(BitType bit, Flags<BitType> const& flags) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator>=( bit );
  }

  template <typename BitType>
  VULKAN_HPP_CONSTEXPR bool operator>(BitType bit, Flags<BitType> const& flags) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator<( bit );
  }

  template <typename BitType>
  VULKAN_HPP_CONSTEXPR bool operator>=(BitType bit, Flags<BitType> const& flags) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator<=(bit);
  }

  template <typename BitType>
  VULKAN_HPP_CONSTEXPR bool operator==(BitType bit, Flags<BitType> const& flags) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator==( bit );
  }

  template <typename BitType>
  VULKAN_HPP_CONSTEXPR bool operator!=(BitType bit, Flags<BitType> const& flags) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator!=( bit );
  }
#endif

  // bitwise operators
  template <typename BitType>
  VULKAN_HPP_CONSTEXPR Flags<BitType> operator&(BitType bit, Flags<BitType> const& flags) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator&( bit );
  }

  template <typename BitType>
  VULKAN_HPP_CONSTEXPR Flags<BitType> operator|(BitType bit, Flags<BitType> const& flags) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator|( bit );
  }

  template <typename BitType>
  VULKAN_HPP_CONSTEXPR Flags<BitType> operator^(BitType bit, Flags<BitType> const& flags) VULKAN_HPP_NOEXCEPT
  {
    return flags.operator^( bit );
  }

  template <typename RefType>
  class Optional
  {
  public:
    Optional(RefType & reference) VULKAN_HPP_NOEXCEPT { m_ptr = &reference; }
    Optional(RefType * ptr) VULKAN_HPP_NOEXCEPT { m_ptr = ptr; }
    Optional(std::nullptr_t) VULKAN_HPP_NOEXCEPT { m_ptr = nullptr; }

    operator RefType*() const VULKAN_HPP_NOEXCEPT { return m_ptr; }
    RefType const* operator->() const VULKAN_HPP_NOEXCEPT { return m_ptr; }
    explicit operator bool() const VULKAN_HPP_NOEXCEPT { return !!m_ptr; }

  private:
    RefType *m_ptr;
  };

  template <typename X, typename Y> struct StructExtends { enum { value = false }; };

  template<typename Type, class...>
  struct IsPartOfStructureChain
  {
    static const bool valid = false;
  };

  template<typename Type, typename Head, typename... Tail>
  struct IsPartOfStructureChain<Type, Head, Tail...>
  {
    static const bool valid = std::is_same<Type, Head>::value || IsPartOfStructureChain<Type, Tail...>::valid;
  };

  template <size_t Index, typename T, typename... ChainElements>
  struct StructureChainContains
  {
    static const bool value = std::is_same<T, typename std::tuple_element<Index, std::tuple<ChainElements...>>::type>::value ||
                              StructureChainContains<Index - 1, T, ChainElements...>::value;
  };

  template <typename T, typename... ChainElements>
  struct StructureChainContains<0, T, ChainElements...>
  {
    static const bool value = std::is_same<T, typename std::tuple_element<0, std::tuple<ChainElements...>>::type>::value;
  };

  template <size_t Index, typename... ChainElements>
  struct StructureChainValidation
  {
    using TestType = typename std::tuple_element<Index, std::tuple<ChainElements...>>::type;
    static const bool valid =
      StructExtends<TestType, typename std::tuple_element<0, std::tuple<ChainElements...>>::type>::value &&
      ( TestType::allowDuplicate || !StructureChainContains<Index - 1, TestType, ChainElements...>::value ) &&
      StructureChainValidation<Index - 1, ChainElements...>::valid;
  };

  template <typename... ChainElements>
  struct StructureChainValidation<0, ChainElements...>
  {
    static const bool valid = true;
  };

  template <typename... ChainElements>
  class StructureChain : public std::tuple<ChainElements...>
  {
  public:
    StructureChain() VULKAN_HPP_NOEXCEPT
    {
      static_assert( StructureChainValidation<sizeof...( ChainElements ) - 1, ChainElements...>::valid,
                     "The structure chain is not valid!" );
      link<sizeof...( ChainElements ) - 1>();
    }

    StructureChain( StructureChain const & rhs ) VULKAN_HPP_NOEXCEPT : std::tuple<ChainElements...>( rhs )
    {
      static_assert( StructureChainValidation<sizeof...( ChainElements ) - 1, ChainElements...>::valid,
                     "The structure chain is not valid!" );
      link<sizeof...( ChainElements ) - 1>();
    }

    StructureChain( StructureChain && rhs ) VULKAN_HPP_NOEXCEPT
      : std::tuple<ChainElements...>( std::forward<std::tuple<ChainElements...>>( rhs ) )
    {
      static_assert( StructureChainValidation<sizeof...( ChainElements ) - 1, ChainElements...>::valid,
                     "The structure chain is not valid!" );
      link<sizeof...( ChainElements ) - 1>();
    }

    StructureChain( ChainElements const &... elems ) VULKAN_HPP_NOEXCEPT : std::tuple<ChainElements...>( elems... )
    {
      static_assert( StructureChainValidation<sizeof...( ChainElements ) - 1, ChainElements...>::valid,
                     "The structure chain is not valid!" );
      link<sizeof...( ChainElements ) - 1>();
    }

    StructureChain & operator=( StructureChain const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      std::tuple<ChainElements...>::operator=( rhs );
      link<sizeof...( ChainElements ) - 1>();
      return *this;
    }

    StructureChain & operator=( StructureChain && rhs ) = delete;

    template <typename T = typename std::tuple_element<0, std::tuple<ChainElements...>>::type, size_t Which = 0>
    T & get() VULKAN_HPP_NOEXCEPT
    {
      return std::get<ChainElementIndex<0, T, Which, void, ChainElements...>::value>( static_cast<std::tuple<ChainElements...>&>( *this ) );
    }

    template <typename T = typename std::tuple_element<0, std::tuple<ChainElements...>>::type, size_t Which = 0>
    T const & get() const VULKAN_HPP_NOEXCEPT
    {
      return std::get<ChainElementIndex<0, T, Which, void, ChainElements...>::value>( static_cast<std::tuple<ChainElements...> const &>( *this ) );
    }

    template <typename T0, typename T1, typename... Ts>
    std::tuple<T0 &, T1 &, Ts &...> get() VULKAN_HPP_NOEXCEPT
    {
      return std::tie( get<T0>(), get<T1>(), get<Ts>()... );
    }

    template <typename T0, typename T1, typename... Ts>
    std::tuple<T0 const &, T1 const &, Ts const &...> get() const VULKAN_HPP_NOEXCEPT
    {
      return std::tie( get<T0>(), get<T1>(), get<Ts>()... );
    }

    template <typename ClassType, size_t Which = 0>
    void relink() VULKAN_HPP_NOEXCEPT
    {
      static_assert( IsPartOfStructureChain<ClassType, ChainElements...>::valid,
                     "Can't relink Structure that's not part of this StructureChain!" );
      static_assert(
        !std::is_same<ClassType, typename std::tuple_element<0, std::tuple<ChainElements...>>::type>::value || (Which != 0),
        "It's not allowed to have the first element unlinked!" );

      auto pNext = reinterpret_cast<VkBaseInStructure *>( &get<ClassType, Which>() );
      VULKAN_HPP_ASSERT( !isLinked( pNext ) );
      auto & headElement = std::get<0>( static_cast<std::tuple<ChainElements...>&>( *this ) );
      pNext->pNext       = reinterpret_cast<VkBaseInStructure const*>(headElement.pNext);
      headElement.pNext  = pNext;
    }

    template <typename ClassType, size_t Which = 0>
    void unlink() VULKAN_HPP_NOEXCEPT
    {
      static_assert( IsPartOfStructureChain<ClassType, ChainElements...>::valid,
                     "Can't unlink Structure that's not part of this StructureChain!" );
      static_assert(
        !std::is_same<ClassType, typename std::tuple_element<0, std::tuple<ChainElements...>>::type>::value || (Which != 0),
        "It's not allowed to unlink the first element!" );

      unlink<sizeof...( ChainElements ) - 1>( reinterpret_cast<VkBaseOutStructure const *>( &get<ClassType, Which>() ) );
    }

  private:
    template <int Index, typename T, int Which, typename, class First, class... Types>
    struct ChainElementIndex : ChainElementIndex<Index + 1, T, Which, void, Types...>
    {};

    template <int Index, typename T, int Which, class First, class... Types>
    struct ChainElementIndex<Index,
                             T,
                             Which,
                             typename std::enable_if<!std::is_same<T, First>::value, void>::type,
                             First,
                             Types...> : ChainElementIndex<Index + 1, T, Which, void, Types...>
    {};

    template <int Index, typename T, int Which, class First, class... Types>
    struct ChainElementIndex<Index,
                             T,
                             Which,
                             typename std::enable_if<std::is_same<T, First>::value, void>::type,
                             First,
                             Types...> : ChainElementIndex<Index + 1, T, Which - 1, void, Types...>
    {};

    template <int Index, typename T, class First, class... Types>
    struct ChainElementIndex<Index,
                             T,
                             0,
                             typename std::enable_if<std::is_same<T, First>::value, void>::type,
                             First,
                             Types...> : std::integral_constant<int, Index>
    {};

    bool isLinked( VkBaseInStructure const * pNext )
    {
      VkBaseInStructure const * elementPtr = reinterpret_cast<VkBaseInStructure const*>(&std::get<0>( static_cast<std::tuple<ChainElements...>&>( *this ) ) );
      while ( elementPtr )
      {
        if ( elementPtr->pNext == pNext )
        {
          return true;
        }
        elementPtr = elementPtr->pNext;
      }
      return false;
    }

    template <size_t Index>
    typename std::enable_if<Index != 0, void>::type link() VULKAN_HPP_NOEXCEPT
    {
      auto & x = std::get<Index - 1>( static_cast<std::tuple<ChainElements...>&>( *this ) );
      x.pNext  = &std::get<Index>( static_cast<std::tuple<ChainElements...>&>( *this ) );
      link<Index - 1>();
    }

    template <size_t Index>
    typename std::enable_if<Index == 0, void>::type link() VULKAN_HPP_NOEXCEPT
    {}

    template <size_t Index>
    typename std::enable_if<Index != 0, void>::type unlink( VkBaseOutStructure const * pNext ) VULKAN_HPP_NOEXCEPT
    {
      auto & element = std::get<Index>( static_cast<std::tuple<ChainElements...>&>( *this ) );
      if ( element.pNext == pNext )
      {
        element.pNext = pNext->pNext;
      }
      else
      {
        unlink<Index - 1>( pNext );
      }
    }

    template <size_t Index>
    typename std::enable_if<Index == 0, void>::type unlink( VkBaseOutStructure const * pNext ) VULKAN_HPP_NOEXCEPT
    {
      auto & element = std::get<0>( static_cast<std::tuple<ChainElements...>&>( *this ) );
      if ( element.pNext == pNext )
      {
        element.pNext = pNext->pNext;
      }
      else
      {
        VULKAN_HPP_ASSERT( false );  // fires, if the ClassType member has already been unlinked !
      }
    }
  };

#if !defined(VULKAN_HPP_NO_SMART_HANDLE)
  template <typename Type, typename Dispatch> class UniqueHandleTraits;

  template <typename Type, typename Dispatch>
  class UniqueHandle : public UniqueHandleTraits<Type,Dispatch>::deleter
  {
  private:
    using Deleter = typename UniqueHandleTraits<Type,Dispatch>::deleter;

  public:
    using element_type = Type;

    UniqueHandle()
      : Deleter()
      , m_value()
    {}

    explicit UniqueHandle( Type const& value, Deleter const& deleter = Deleter() ) VULKAN_HPP_NOEXCEPT
      : Deleter( deleter)
      , m_value( value )
    {}

    UniqueHandle( UniqueHandle const& ) = delete;

    UniqueHandle( UniqueHandle && other ) VULKAN_HPP_NOEXCEPT
      : Deleter( std::move( static_cast<Deleter&>( other ) ) )
      , m_value( other.release() )
    {}

    ~UniqueHandle() VULKAN_HPP_NOEXCEPT
    {
      if ( m_value ) this->destroy( m_value );
    }

    UniqueHandle & operator=( UniqueHandle const& ) = delete;

    UniqueHandle & operator=( UniqueHandle && other ) VULKAN_HPP_NOEXCEPT
    {
      reset( other.release() );
      *static_cast<Deleter*>(this) = std::move( static_cast<Deleter&>(other) );
      return *this;
    }

    explicit operator bool() const VULKAN_HPP_NOEXCEPT
    {
      return m_value.operator bool();
    }

    Type const* operator->() const VULKAN_HPP_NOEXCEPT
    {
      return &m_value;
    }

    Type * operator->() VULKAN_HPP_NOEXCEPT
    {
      return &m_value;
    }

    Type const& operator*() const VULKAN_HPP_NOEXCEPT
    {
      return m_value;
    }

    Type & operator*() VULKAN_HPP_NOEXCEPT
    {
      return m_value;
    }

    const Type & get() const VULKAN_HPP_NOEXCEPT
    {
      return m_value;
    }

    Type & get() VULKAN_HPP_NOEXCEPT
    {
      return m_value;
    }

    void reset( Type const& value = Type() ) VULKAN_HPP_NOEXCEPT
    {
      if ( m_value != value )
      {
        if ( m_value ) this->destroy( m_value );
        m_value = value;
      }
    }

    Type release() VULKAN_HPP_NOEXCEPT
    {
      Type value = m_value;
      m_value = nullptr;
      return value;
    }

    void swap( UniqueHandle<Type,Dispatch> & rhs ) VULKAN_HPP_NOEXCEPT
    {
      std::swap(m_value, rhs.m_value);
      std::swap(static_cast<Deleter&>(*this), static_cast<Deleter&>(rhs));
    }

  private:
    Type    m_value;
  };

  template <typename UniqueType>
  VULKAN_HPP_INLINE std::vector<typename UniqueType::element_type> uniqueToRaw(std::vector<UniqueType> const& handles)
  {
    std::vector<typename UniqueType::element_type> newBuffer(handles.size());
    std::transform(handles.begin(), handles.end(), newBuffer.begin(), [](UniqueType const& handle) { return handle.get(); });
    return newBuffer;
  }

  template <typename Type, typename Dispatch>
  VULKAN_HPP_INLINE void swap( UniqueHandle<Type,Dispatch> & lhs, UniqueHandle<Type,Dispatch> & rhs ) VULKAN_HPP_NOEXCEPT
  {
    lhs.swap( rhs );
  }
#endif

#if !defined(VK_NO_PROTOTYPES)
  class DispatchLoaderStatic
  {
  public:
    VkResult vkAllocateMemory( VmaAllocator allocator, const VkMemoryRequirements* pVkMemoryRequirements, const VmaAllocationCreateInfo* pCreateInfo, VmaAllocation* pAllocation, VmaAllocationInfo* pAllocationInfo ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkAllocateMemory( allocator, pVkMemoryRequirements, pCreateInfo, pAllocation, pAllocationInfo );
    }

    VkResult vkAllocateMemoryForBuffer( VmaAllocator allocator, VkBuffer buffer, const VmaAllocationCreateInfo* pCreateInfo, VmaAllocation* pAllocation, VmaAllocationInfo* pAllocationInfo ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkAllocateMemoryForBuffer( allocator, buffer, pCreateInfo, pAllocation, pAllocationInfo );
    }

    VkResult vkAllocateMemoryForImage( VmaAllocator allocator, VkImage image, const VmaAllocationCreateInfo* pCreateInfo, VmaAllocation* pAllocation, VmaAllocationInfo* pAllocationInfo ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkAllocateMemoryForImage( allocator, image, pCreateInfo, pAllocation, pAllocationInfo );
    }

    VkResult vkAllocateMemoryPages( VmaAllocator allocator, const VkMemoryRequirements* pVkMemoryRequirements, const VmaAllocationCreateInfo* pCreateInfo, size_t allocationCount, VmaAllocation* pAllocations, VmaAllocationInfo* pAllocationInfo ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkAllocateMemoryPages( allocator, pVkMemoryRequirements, pCreateInfo, allocationCount, pAllocations, pAllocationInfo );
    }

    VkResult vkBindBufferMemory( VmaAllocator allocator, VmaAllocation allocation, VkBuffer buffer ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkBindBufferMemory( allocator, allocation, buffer );
    }

    VkResult vkBindBufferMemory2( VmaAllocator allocator, VmaAllocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer, const void* pNext ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkBindBufferMemory2( allocator, allocation, allocationLocalOffset, buffer, pNext );
    }

    VkResult vkBindImageMemory( VmaAllocator allocator, VmaAllocation allocation, VkImage image ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkBindImageMemory( allocator, allocation, image );
    }

    VkResult vkBindImageMemory2( VmaAllocator allocator, VmaAllocation allocation, VkDeviceSize allocationLocalOffset, VkImage image, const void* pNext ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkBindImageMemory2( allocator, allocation, allocationLocalOffset, image, pNext );
    }

    void vkBuildStatsString( VmaAllocator allocator, char** ppStatsString, VkBool32 detailedMap ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkBuildStatsString( allocator, ppStatsString, detailedMap );
    }

    void vkCalculateStats( VmaAllocator allocator, VmaStats* pStats ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkCalculateStats( allocator, pStats );
    }

    VkResult vkCheckCorruption( VmaAllocator allocator, uint32_t memoryTypeBits ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkCheckCorruption( allocator, memoryTypeBits );
    }

    VkResult vkCheckPoolCorruption( VmaAllocator allocator, VmaPool pool ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkCheckPoolCorruption( allocator, pool );
    }

    VkResult vkCreateAllocator( const VmaAllocatorCreateInfo* pCreateInfo, VmaAllocator* pAllocator ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkCreateAllocator( pCreateInfo, pAllocator );
    }

    VkResult vkCreateBuffer( VmaAllocator allocator, const VkBufferCreateInfo* pBufferCreateInfo, const VmaAllocationCreateInfo* pAllocationCreateInfo, VkBuffer* pBuffer, VmaAllocation* pAllocation, VmaAllocationInfo* pAllocationInfo ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkCreateBuffer( allocator, pBufferCreateInfo, pAllocationCreateInfo, pBuffer, pAllocation, pAllocationInfo );
    }

    VkResult vkCreateImage( VmaAllocator allocator, const VkImageCreateInfo* pImageCreateInfo, const VmaAllocationCreateInfo* pAllocationCreateInfo, VkImage* pImage, VmaAllocation* pAllocation, VmaAllocationInfo* pAllocationInfo ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkCreateImage( allocator, pImageCreateInfo, pAllocationCreateInfo, pImage, pAllocation, pAllocationInfo );
    }

    void vkCreateLostAllocation( VmaAllocator allocator, VmaAllocation* pAllocation ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkCreateLostAllocation( allocator, pAllocation );
    }

    VkResult vkCreatePool( VmaAllocator allocator, const VmaPoolCreateInfo* pCreateInfo, VmaPool* pPool ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkCreatePool( allocator, pCreateInfo, pPool );
    }

    VkResult vkDefragment( VmaAllocator allocator, VmaAllocation* pAllocations, size_t allocationCount, VkBool32* pAllocationsChanged, const VmaDefragmentationInfo* pDefragmentationInfo, VmaDefragmentationStats* pDefragmentationStats ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkDefragment( allocator, pAllocations, allocationCount, pAllocationsChanged, pDefragmentationInfo, pDefragmentationStats );
    }

    VkResult vkDefragmentationBegin( VmaAllocator allocator, const VmaDefragmentationInfo2* pInfo, VmaDefragmentationStats* pStats, VmaDefragmentationContext* pContext ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkDefragmentationBegin( allocator, pInfo, pStats, pContext );
    }

    VkResult vkDefragmentationEnd( VmaAllocator allocator, VmaDefragmentationContext context ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkDefragmentationEnd( allocator, context );
    }

    void vkDestroyAllocator( VmaAllocator allocator ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkDestroyAllocator( allocator );
    }

    void vkDestroyBuffer( VmaAllocator allocator, VkBuffer buffer, VmaAllocation allocation ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkDestroyBuffer( allocator, buffer, allocation );
    }

    void vkDestroyImage( VmaAllocator allocator, VkImage image, VmaAllocation allocation ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkDestroyImage( allocator, image, allocation );
    }

    void vkDestroyPool( VmaAllocator allocator, VmaPool pool ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkDestroyPool( allocator, pool );
    }

    VkResult vkFindMemoryTypeIndex( VmaAllocator allocator, uint32_t memoryTypeBits, const VmaAllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkFindMemoryTypeIndex( allocator, memoryTypeBits, pAllocationCreateInfo, pMemoryTypeIndex );
    }

    VkResult vkFindMemoryTypeIndexForBufferInfo( VmaAllocator allocator, const VkBufferCreateInfo* pBufferCreateInfo, const VmaAllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkFindMemoryTypeIndexForBufferInfo( allocator, pBufferCreateInfo, pAllocationCreateInfo, pMemoryTypeIndex );
    }

    VkResult vkFindMemoryTypeIndexForImageInfo( VmaAllocator allocator, const VkImageCreateInfo* pImageCreateInfo, const VmaAllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkFindMemoryTypeIndexForImageInfo( allocator, pImageCreateInfo, pAllocationCreateInfo, pMemoryTypeIndex );
    }

    void vkFlushAllocation( VmaAllocator allocator, VmaAllocation allocation, VkDeviceSize offset, VkDeviceSize size ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkFlushAllocation( allocator, allocation, offset, size );
    }

    void vkFreeMemory( VmaAllocator allocator, VmaAllocation allocation ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkFreeMemory( allocator, allocation );
    }

    void vkFreeMemoryPages( VmaAllocator allocator, size_t allocationCount, VmaAllocation* pAllocations ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkFreeMemoryPages( allocator, allocationCount, pAllocations );
    }

    void vkFreeStatsString( VmaAllocator allocator, char* pStatsString ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkFreeStatsString( allocator, pStatsString );
    }

    void vkGetAllocationInfo( VmaAllocator allocator, VmaAllocation allocation, VmaAllocationInfo* pAllocationInfo ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkGetAllocationInfo( allocator, allocation, pAllocationInfo );
    }

    void vkGetBudget( VmaAllocator allocator, VmaBudget* pBudget ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkGetBudget( allocator, pBudget );
    }

    void vkGetMemoryProperties( VmaAllocator allocator, const VkPhysicalDeviceMemoryProperties** ppPhysicalDeviceMemoryProperties ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkGetMemoryProperties( allocator, ppPhysicalDeviceMemoryProperties );
    }

    void vkGetMemoryTypeProperties( VmaAllocator allocator, uint32_t memoryTypeIndex, VkMemoryPropertyFlags* pFlags ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkGetMemoryTypeProperties( allocator, memoryTypeIndex, pFlags );
    }

    void vkGetPhysicalDeviceProperties( VmaAllocator allocator, const VkPhysicalDeviceProperties** ppPhysicalDeviceProperties ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkGetPhysicalDeviceProperties( allocator, ppPhysicalDeviceProperties );
    }

    void vkGetPoolName( VmaAllocator allocator, VmaPool pool, const char** ppName ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkGetPoolName( allocator, pool, ppName );
    }

    void vkGetPoolStats( VmaAllocator allocator, VmaPool pool, VmaPoolStats* pPoolStats ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkGetPoolStats( allocator, pool, pPoolStats );
    }

    void vkInvalidateAllocation( VmaAllocator allocator, VmaAllocation allocation, VkDeviceSize offset, VkDeviceSize size ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkInvalidateAllocation( allocator, allocation, offset, size );
    }

    void vkMakePoolAllocationsLost( VmaAllocator allocator, VmaPool pool, size_t* pLostAllocationCount ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkMakePoolAllocationsLost( allocator, pool, pLostAllocationCount );
    }

    VkResult vkMapMemory( VmaAllocator allocator, VmaAllocation allocation, void** ppData ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkMapMemory( allocator, allocation, ppData );
    }

    VkResult vkResizeAllocation( VmaAllocator allocator, VmaAllocation allocation, VkDeviceSize newSize ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkResizeAllocation( allocator, allocation, newSize );
    }

    void vkSetAllocationUserData( VmaAllocator allocator, VmaAllocation allocation, void* pUserData ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkSetAllocationUserData( allocator, allocation, pUserData );
    }

    void vkSetCurrentFrameIndex( VmaAllocator allocator, uint32_t frameIndex ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkSetCurrentFrameIndex( allocator, frameIndex );
    }

    void vkSetPoolName( VmaAllocator allocator, VmaPool pool, const char* pName ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkSetPoolName( allocator, pool, pName );
    }

    VkBool32 vkTouchAllocation( VmaAllocator allocator, VmaAllocation allocation ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkTouchAllocation( allocator, allocation );
    }

    void vkUnmapMemory( VmaAllocator allocator, VmaAllocation allocation ) const VULKAN_HPP_NOEXCEPT
    {
      return ::vkUnmapMemory( allocator, allocation );
    }
  };
#endif

  class DispatchLoaderDynamic;
#if !defined(VULKAN_HPP_DISPATCH_LOADER_DYNAMIC)
# if defined(VK_NO_PROTOTYPES)
#  define VULKAN_HPP_DISPATCH_LOADER_DYNAMIC 1
# else
#  define VULKAN_HPP_DISPATCH_LOADER_DYNAMIC 0
# endif
#endif

#if defined(_WIN32) && defined(VULKAN_HPP_STORAGE_SHARED)
#  ifdef VULKAN_HPP_STORAGE_SHARED_EXPORT
#    define VULKAN_HPP_STORAGE_API __declspec( dllexport )
#  else
#    define VULKAN_HPP_STORAGE_API __declspec( dllimport )
#  endif
#else
#  define VULKAN_HPP_STORAGE_API
#endif

#if !defined(VULKAN_HPP_DEFAULT_DISPATCHER)
# if VULKAN_HPP_DISPATCH_LOADER_DYNAMIC == 1
#  define VULKAN_HPP_DEFAULT_DISPATCHER ::VULKAN_HPP_NAMESPACE::defaultDispatchLoaderDynamic
#  define VULKAN_HPP_DEFAULT_DISPATCH_LOADER_DYNAMIC_STORAGE namespace VULKAN_HPP_NAMESPACE { VULKAN_HPP_STORAGE_API DispatchLoaderDynamic defaultDispatchLoaderDynamic; }
  extern VULKAN_HPP_STORAGE_API DispatchLoaderDynamic defaultDispatchLoaderDynamic;
# else
#  define VULKAN_HPP_DEFAULT_DISPATCHER ::VULKAN_HPP_NAMESPACE::DispatchLoaderStatic()
#  define VULKAN_HPP_DEFAULT_DISPATCH_LOADER_DYNAMIC_STORAGE
# endif
#endif

#if !defined(VULKAN_HPP_DEFAULT_DISPATCHER_TYPE)
# if VULKAN_HPP_DISPATCH_LOADER_DYNAMIC == 1
  #define VULKAN_HPP_DEFAULT_DISPATCHER_TYPE ::VULKAN_HPP_NAMESPACE::DispatchLoaderDynamic
# else
#  define VULKAN_HPP_DEFAULT_DISPATCHER_TYPE ::VULKAN_HPP_NAMESPACE::DispatchLoaderStatic
# endif
#endif

#if defined( VULKAN_HPP_NO_DEFAULT_DISPATCHER )
#  define VULKAN_HPP_DEFAULT_ARGUMENT_ASSIGNMENT
#  define VULKAN_HPP_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT
#  define VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT
#else
#  define VULKAN_HPP_DEFAULT_ARGUMENT_ASSIGNMENT = {}
#  define VULKAN_HPP_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT = nullptr
#  define VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT = VULKAN_HPP_DEFAULT_DISPATCHER
#endif

  struct AllocationCallbacks;

  template <typename OwnerType, typename Dispatch>
  class ObjectDestroy
  {
    public:
    ObjectDestroy() = default;

    ObjectDestroy( OwnerType owner,
                   Optional<const AllocationCallbacks> allocationCallbacks
                                    VULKAN_HPP_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT,
                   Dispatch const & dispatch = VULKAN_HPP_DEFAULT_DISPATCHER ) VULKAN_HPP_NOEXCEPT
      : m_owner( owner )
      , m_allocationCallbacks( allocationCallbacks )
      , m_dispatch( &dispatch )
    {}

      OwnerType getOwner() const VULKAN_HPP_NOEXCEPT { return m_owner; }
      Optional<const AllocationCallbacks> getAllocator() const VULKAN_HPP_NOEXCEPT { return m_allocationCallbacks; }

    protected:
      template <typename T>
      void destroy(T t) VULKAN_HPP_NOEXCEPT
      {
        VULKAN_HPP_ASSERT( m_owner && m_dispatch );
        m_owner.destroy( t, m_allocationCallbacks, *m_dispatch );
      }

    private:
    OwnerType                           m_owner               = {};
    Optional<const AllocationCallbacks> m_allocationCallbacks = nullptr;
    Dispatch const *                    m_dispatch            = nullptr;
  };

  class NoParent;

  template <typename Dispatch>
  class ObjectDestroy<NoParent,Dispatch>
  {
    public:
    ObjectDestroy() = default;

    ObjectDestroy( Optional<const AllocationCallbacks> allocationCallbacks,
                   Dispatch const &                    dispatch = VULKAN_HPP_DEFAULT_DISPATCHER ) VULKAN_HPP_NOEXCEPT
      : m_allocationCallbacks( allocationCallbacks )
      , m_dispatch( &dispatch )
    {}

      Optional<const AllocationCallbacks> getAllocator() const VULKAN_HPP_NOEXCEPT { return m_allocationCallbacks; }

    protected:
      template <typename T>
      void destroy(T t) VULKAN_HPP_NOEXCEPT
      {
        VULKAN_HPP_ASSERT( m_dispatch );
        t.destroy( m_allocationCallbacks, *m_dispatch );
      }

    private:
    Optional<const AllocationCallbacks> m_allocationCallbacks = nullptr;
    Dispatch const *                    m_dispatch            = nullptr;
  };

  template <typename OwnerType, typename Dispatch>
  class ObjectFree
  {
  public:
    ObjectFree() = default;

    ObjectFree( OwnerType                                               owner,
                Optional<const AllocationCallbacks> allocationCallbacks VULKAN_HPP_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT,
                Dispatch const & dispatch = VULKAN_HPP_DEFAULT_DISPATCHER ) VULKAN_HPP_NOEXCEPT
      : m_owner( owner )
      , m_allocationCallbacks( allocationCallbacks )
      , m_dispatch( &dispatch )
    {}

    OwnerType getOwner() const VULKAN_HPP_NOEXCEPT
    {
      return m_owner;
    }

    Optional<const AllocationCallbacks> getAllocator() const VULKAN_HPP_NOEXCEPT
    {
      return m_allocationCallbacks;
    }

  protected:
    template <typename T>
    void destroy( T t ) VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( m_owner && m_dispatch );
      m_owner.free( t, m_allocationCallbacks, *m_dispatch );
    }

  private:
    OwnerType                           m_owner               = {};
    Optional<const AllocationCallbacks> m_allocationCallbacks = nullptr;
    Dispatch const *                    m_dispatch            = nullptr;
  };

  template <typename OwnerType, typename Dispatch>
  class ObjectRelease
  {
  public:
    ObjectRelease() = default;

    ObjectRelease( OwnerType owner, Dispatch const & dispatch = VULKAN_HPP_DEFAULT_DISPATCHER ) VULKAN_HPP_NOEXCEPT
      : m_owner( owner )
      , m_dispatch( &dispatch )
    {}

    OwnerType getOwner() const VULKAN_HPP_NOEXCEPT
    {
      return m_owner;
    }

  protected:
    template <typename T>
    void destroy( T t ) VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT( m_owner && m_dispatch );
      m_owner.release( t, *m_dispatch );
    }

  private:
    OwnerType        m_owner    = {};
    Dispatch const * m_dispatch = nullptr;
  };

  template <typename OwnerType, typename PoolType, typename Dispatch>
  class PoolFree
  {
    public:
      PoolFree() = default;

      PoolFree( OwnerType        owner,
                PoolType         pool,
                Dispatch const & dispatch = VULKAN_HPP_DEFAULT_DISPATCHER ) VULKAN_HPP_NOEXCEPT
        : m_owner( owner )
        , m_pool( pool )
        , m_dispatch( &dispatch )
      {}

      OwnerType getOwner() const VULKAN_HPP_NOEXCEPT { return m_owner; }
      PoolType getPool() const VULKAN_HPP_NOEXCEPT { return m_pool; }

    protected:
      template <typename T>
      void destroy(T t) VULKAN_HPP_NOEXCEPT
      {
        m_owner.free( m_pool, t, *m_dispatch );
      }

    private:
      OwnerType        m_owner    = OwnerType();
      PoolType         m_pool     = PoolType();
      Dispatch const * m_dispatch = nullptr;
  };


  template <typename EnumType, EnumType value>
  struct CppType
  {};

  template <typename Type>
  struct isVulkanHandleType
  {
    static VULKAN_HPP_CONST_OR_CONSTEXPR bool value = false;
  };

  VULKAN_HPP_INLINE std::string toHexString( uint32_t value )
  {
    std::stringstream stream;
    stream << std::hex << value;
    return stream.str();
  }

  enum class VkDebugReportObjectTypeEXT
  {};

  VULKAN_HPP_INLINE std::string to_string( VkDebugReportObjectTypeEXT )
  {
    return "(void)";
  }

  enum class VkIndexType
  {
    eUint16 = VK_INDEX_TYPE_UINT16,
    eUint32 = VK_INDEX_TYPE_UINT32
  };

  VULKAN_HPP_INLINE std::string to_string( VkIndexType value )
  {
    switch ( value )
    {
      case VkIndexType::eUint16 : return "Uint16";
      case VkIndexType::eUint32 : return "Uint32";
      default: return "invalid ( " + VULKAN_HPP_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class VkObjectType
  {
    eVmaAllocation = VK_OBJECT_TYPE_VMA_ALLOCATION,
    eVmaAllocator = VK_OBJECT_TYPE_VMA_ALLOCATOR,
    eVmaDefragmentationContext = VK_OBJECT_TYPE_VMA_DEFRAGMENTATION_CONTEXT,
    eVmaPool = VK_OBJECT_TYPE_VMA_POOL
  };

  VULKAN_HPP_INLINE std::string to_string( VkObjectType value )
  {
    switch ( value )
    {
      case VkObjectType::eVmaAllocation : return "VmaAllocation";
      case VkObjectType::eVmaAllocator : return "VmaAllocator";
      case VkObjectType::eVmaDefragmentationContext : return "VmaDefragmentationContext";
      case VkObjectType::eVmaPool : return "VmaPool";
      default: return "invalid ( " + VULKAN_HPP_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  template<ObjectType value>
  struct cpp_type
  {};

  enum class VkResult
  {
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
    eErrorSurfaceLostKhr = VK_ERROR_SURFACE_LOST_KHR,
    eErrorNativeWindowInUseKhr = VK_ERROR_NATIVE_WINDOW_IN_USE_KHR,
    eSuboptimalKhr = VK_SUBOPTIMAL_KHR,
    eErrorOutOfDateKhr = VK_ERROR_OUT_OF_DATE_KHR,
    eErrorIncompatibleDisplayKhr = VK_ERROR_INCOMPATIBLE_DISPLAY_KHR,
    eErrorValidationFailedExt = VK_ERROR_VALIDATION_FAILED_EXT,
    eErrorInvalidShaderNv = VK_ERROR_INVALID_SHADER_NV
  };

  VULKAN_HPP_INLINE std::string to_string( VkResult value )
  {
    switch ( value )
    {
      case VkResult::eSuccess : return "Success";
      case VkResult::eNotReady : return "NotReady";
      case VkResult::eTimeout : return "Timeout";
      case VkResult::eEventSet : return "EventSet";
      case VkResult::eEventReset : return "EventReset";
      case VkResult::eIncomplete : return "Incomplete";
      case VkResult::eErrorOutOfHostMemory : return "ErrorOutOfHostMemory";
      case VkResult::eErrorOutOfDeviceMemory : return "ErrorOutOfDeviceMemory";
      case VkResult::eErrorInitializationFailed : return "ErrorInitializationFailed";
      case VkResult::eErrorDeviceLost : return "ErrorDeviceLost";
      case VkResult::eErrorMemoryMapFailed : return "ErrorMemoryMapFailed";
      case VkResult::eErrorLayerNotPresent : return "ErrorLayerNotPresent";
      case VkResult::eErrorExtensionNotPresent : return "ErrorExtensionNotPresent";
      case VkResult::eErrorFeatureNotPresent : return "ErrorFeatureNotPresent";
      case VkResult::eErrorIncompatibleDriver : return "ErrorIncompatibleDriver";
      case VkResult::eErrorTooManyObjects : return "ErrorTooManyObjects";
      case VkResult::eErrorFormatNotSupported : return "ErrorFormatNotSupported";
      case VkResult::eErrorFragmentedPool : return "ErrorFragmentedPool";
      case VkResult::eErrorSurfaceLostKhr : return "ErrorSurfaceLostKhr";
      case VkResult::eErrorNativeWindowInUseKhr : return "ErrorNativeWindowInUseKhr";
      case VkResult::eSuboptimalKhr : return "SuboptimalKhr";
      case VkResult::eErrorOutOfDateKhr : return "ErrorOutOfDateKhr";
      case VkResult::eErrorIncompatibleDisplayKhr : return "ErrorIncompatibleDisplayKhr";
      case VkResult::eErrorValidationFailedExt : return "ErrorValidationFailedExt";
      case VkResult::eErrorInvalidShaderNv : return "ErrorInvalidShaderNv";
      default: return "invalid ( " + VULKAN_HPP_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class VkStructureType
  {};

  VULKAN_HPP_INLINE std::string to_string( VkStructureType )
  {
    return "(void)";
  }

  enum class AllocationCreateFlagBits : VmaAllocationCreateFlags
  {
    eDedicatedMemory = VMA_ALLOCATION_CREATE_DEDICATED_MEMORY_BIT,
    eNeverAllocate = VMA_ALLOCATION_CREATE_NEVER_ALLOCATE_BIT,
    eMapped = VMA_ALLOCATION_CREATE_MAPPED_BIT,
    eCanBecomeLost = VMA_ALLOCATION_CREATE_CAN_BECOME_LOST_BIT,
    eCanMakeOtherLost = VMA_ALLOCATION_CREATE_CAN_MAKE_OTHER_LOST_BIT,
    eUserDataCopyString = VMA_ALLOCATION_CREATE_USER_DATA_COPY_STRING_BIT,
    eUpperAddress = VMA_ALLOCATION_CREATE_UPPER_ADDRESS_BIT,
    eDontBind = VMA_ALLOCATION_CREATE_DONT_BIND_BIT,
    eWithinBudget = VMA_ALLOCATION_CREATE_WITHIN_BUDGET_BIT,
    eStrategyBestFit = VMA_ALLOCATION_CREATE_STRATEGY_BEST_FIT_BIT,
    eStrategyWorstFit = VMA_ALLOCATION_CREATE_STRATEGY_WORST_FIT_BIT,
    eStrategyFirstFit = VMA_ALLOCATION_CREATE_STRATEGY_FIRST_FIT_BIT,
    eStrategyMinMemory = VMA_ALLOCATION_CREATE_STRATEGY_MIN_MEMORY_BIT,
    eStrategyMinTime = VMA_ALLOCATION_CREATE_STRATEGY_MIN_TIME_BIT,
    eStrategyMinFragmentation = VMA_ALLOCATION_CREATE_STRATEGY_MIN_FRAGMENTATION_BIT,
    eStrategyMask = VMA_ALLOCATION_CREATE_STRATEGY_MASK,
    eFlagsMaxEnum = VMA_ALLOCATION_CREATE_FLAG_BITS_MAX_ENUM
  };

  VULKAN_HPP_INLINE std::string to_string( AllocationCreateFlagBits value )
  {
    switch ( value )
    {
      case AllocationCreateFlagBits::eDedicatedMemory : return "DedicatedMemory";
      case AllocationCreateFlagBits::eNeverAllocate : return "NeverAllocate";
      case AllocationCreateFlagBits::eMapped : return "Mapped";
      case AllocationCreateFlagBits::eCanBecomeLost : return "CanBecomeLost";
      case AllocationCreateFlagBits::eCanMakeOtherLost : return "CanMakeOtherLost";
      case AllocationCreateFlagBits::eUserDataCopyString : return "UserDataCopyString";
      case AllocationCreateFlagBits::eUpperAddress : return "UpperAddress";
      case AllocationCreateFlagBits::eDontBind : return "DontBind";
      case AllocationCreateFlagBits::eWithinBudget : return "WithinBudget";
      case AllocationCreateFlagBits::eStrategyBestFit : return "StrategyBestFit";
      case AllocationCreateFlagBits::eStrategyWorstFit : return "StrategyWorstFit";
      case AllocationCreateFlagBits::eStrategyFirstFit : return "StrategyFirstFit";
      case AllocationCreateFlagBits::eStrategyMinMemory : return "StrategyMinMemory";
      case AllocationCreateFlagBits::eStrategyMinTime : return "StrategyMinTime";
      case AllocationCreateFlagBits::eStrategyMinFragmentation : return "StrategyMinFragmentation";
      case AllocationCreateFlagBits::eStrategyMask : return "StrategyMask";
      case AllocationCreateFlagBits::eFlagsMaxEnum : return "FlagsMaxEnum";
      default: return "invalid ( " + VULKAN_HPP_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class AllocatorCreateFlagBits : VmaAllocatorCreateFlags
  {
    eExternallySynchronized = VMA_ALLOCATOR_CREATE_EXTERNALLY_SYNCHRONIZED_BIT,
    eKhrDedicatedAllocation = VMA_ALLOCATOR_CREATE_KHR_DEDICATED_ALLOCATION_BIT,
    eKhrBindMemory2 = VMA_ALLOCATOR_CREATE_KHR_BIND_MEMORY2_BIT,
    eExtMemoryBudget = VMA_ALLOCATOR_CREATE_EXT_MEMORY_BUDGET_BIT,
    eFlagsMaxEnum = VMA_ALLOCATOR_CREATE_FLAG_BITS_MAX_ENUM
  };

  VULKAN_HPP_INLINE std::string to_string( AllocatorCreateFlagBits value )
  {
    switch ( value )
    {
      case AllocatorCreateFlagBits::eExternallySynchronized : return "ExternallySynchronized";
      case AllocatorCreateFlagBits::eKhrDedicatedAllocation : return "KhrDedicatedAllocation";
      case AllocatorCreateFlagBits::eKhrBindMemory2 : return "KhrBindMemory2";
      case AllocatorCreateFlagBits::eExtMemoryBudget : return "ExtMemoryBudget";
      case AllocatorCreateFlagBits::eFlagsMaxEnum : return "FlagsMaxEnum";
      default: return "invalid ( " + VULKAN_HPP_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class DefragmentationFlagBits : VmaDefragmentationFlags
  {
    eFlagsMaxEnum = VMA_DEFRAGMENTATION_FLAG_BITS_MAX_ENUM
  };

  VULKAN_HPP_INLINE std::string to_string( DefragmentationFlagBits value )
  {
    switch ( value )
    {
      case DefragmentationFlagBits::eFlagsMaxEnum : return "FlagsMaxEnum";
      default: return "invalid ( " + VULKAN_HPP_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class MemoryUsage
  {
    eUnknown = VMA_MEMORY_USAGE_UNKNOWN,
    eGpuOnly = VMA_MEMORY_USAGE_GPU_ONLY,
    eCpuOnly = VMA_MEMORY_USAGE_CPU_ONLY,
    eCpuToGpu = VMA_MEMORY_USAGE_CPU_TO_GPU,
    eGpuToCpu = VMA_MEMORY_USAGE_GPU_TO_CPU,
    eCpuCopy = VMA_MEMORY_USAGE_CPU_COPY,
    eGpuLazilyAllocated = VMA_MEMORY_USAGE_GPU_LAZILY_ALLOCATED,
    eMaxEnum = VMA_MEMORY_USAGE_MAX_ENUM
  };

  VULKAN_HPP_INLINE std::string to_string( MemoryUsage value )
  {
    switch ( value )
    {
      case MemoryUsage::eUnknown : return "Unknown";
      case MemoryUsage::eGpuOnly : return "GpuOnly";
      case MemoryUsage::eCpuOnly : return "CpuOnly";
      case MemoryUsage::eCpuToGpu : return "CpuToGpu";
      case MemoryUsage::eGpuToCpu : return "GpuToCpu";
      case MemoryUsage::eCpuCopy : return "CpuCopy";
      case MemoryUsage::eGpuLazilyAllocated : return "GpuLazilyAllocated";
      case MemoryUsage::eMaxEnum : return "MaxEnum";
      default: return "invalid ( " + VULKAN_HPP_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class PoolCreateFlagBits : VmaPoolCreateFlags
  {
    eIgnoreBufferImageGranularity = VMA_POOL_CREATE_IGNORE_BUFFER_IMAGE_GRANULARITY_BIT,
    eLinearAlgorithm = VMA_POOL_CREATE_LINEAR_ALGORITHM_BIT,
    eBuddyAlgorithm = VMA_POOL_CREATE_BUDDY_ALGORITHM_BIT,
    eAlgorithmMask = VMA_POOL_CREATE_ALGORITHM_MASK,
    eFlagsMaxEnum = VMA_POOL_CREATE_FLAG_BITS_MAX_ENUM
  };

  VULKAN_HPP_INLINE std::string to_string( PoolCreateFlagBits value )
  {
    switch ( value )
    {
      case PoolCreateFlagBits::eIgnoreBufferImageGranularity : return "IgnoreBufferImageGranularity";
      case PoolCreateFlagBits::eLinearAlgorithm : return "LinearAlgorithm";
      case PoolCreateFlagBits::eBuddyAlgorithm : return "BuddyAlgorithm";
      case PoolCreateFlagBits::eAlgorithmMask : return "AlgorithmMask";
      case PoolCreateFlagBits::eFlagsMaxEnum : return "FlagsMaxEnum";
      default: return "invalid ( " + VULKAN_HPP_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class RecordFlagBits : VmaRecordFlags
  {
    eFlushAfterCall = VMA_RECORD_FLUSH_AFTER_CALL_BIT,
    eFlagsMaxEnum = VMA_RECORD_FLAG_BITS_MAX_ENUM
  };

  VULKAN_HPP_INLINE std::string to_string( RecordFlagBits value )
  {
    switch ( value )
    {
      case RecordFlagBits::eFlushAfterCall : return "FlushAfterCall";
      case RecordFlagBits::eFlagsMaxEnum : return "FlagsMaxEnum";
      default: return "invalid ( " + VULKAN_HPP_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  template<typename T>
  struct IndexTypeValue
  {};

  template <>
  struct IndexTypeValue<uint16_t>
  {
    static VULKAN_HPP_CONST_OR_CONSTEXPR IndexType value = IndexType::eUint16;
  };

  template <>
  struct CppType<IndexType, IndexType::eUint16>
  {
    using Type = uint16_t;
  };

  template <>
  struct IndexTypeValue<uint32_t>
  {
    static VULKAN_HPP_CONST_OR_CONSTEXPR IndexType value = IndexType::eUint32;
  };

  template <>
  struct CppType<IndexType, IndexType::eUint32>
  {
    using Type = uint32_t;
  };


  using AllocationCreateFlags = Flags<AllocationCreateFlagBits>;

  template <> struct FlagTraits<AllocationCreateFlagBits>
  {
    enum : VkFlags
    {
      allFlags = VkFlags(AllocationCreateFlagBits::eDedicatedMemory) | VkFlags(AllocationCreateFlagBits::eNeverAllocate) | VkFlags(AllocationCreateFlagBits::eMapped) | VkFlags(AllocationCreateFlagBits::eCanBecomeLost) | VkFlags(AllocationCreateFlagBits::eCanMakeOtherLost) | VkFlags(AllocationCreateFlagBits::eUserDataCopyString) | VkFlags(AllocationCreateFlagBits::eUpperAddress) | VkFlags(AllocationCreateFlagBits::eDontBind) | VkFlags(AllocationCreateFlagBits::eWithinBudget) | VkFlags(AllocationCreateFlagBits::eStrategyBestFit) | VkFlags(AllocationCreateFlagBits::eStrategyWorstFit) | VkFlags(AllocationCreateFlagBits::eStrategyFirstFit) | VkFlags(AllocationCreateFlagBits::eStrategyMinMemory) | VkFlags(AllocationCreateFlagBits::eStrategyMinTime) | VkFlags(AllocationCreateFlagBits::eStrategyMinFragmentation) | VkFlags(AllocationCreateFlagBits::eStrategyMask) | VkFlags(AllocationCreateFlagBits::eFlagsMaxEnum)
    };
  };

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR AllocationCreateFlags operator|( AllocationCreateFlagBits bit0, AllocationCreateFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return AllocationCreateFlags( bit0 ) | bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR AllocationCreateFlags operator&( AllocationCreateFlagBits bit0, AllocationCreateFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return AllocationCreateFlags( bit0 ) & bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR AllocationCreateFlags operator^( AllocationCreateFlagBits bit0, AllocationCreateFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return AllocationCreateFlags( bit0 ) ^ bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR AllocationCreateFlags operator~( AllocationCreateFlagBits bits ) VULKAN_HPP_NOEXCEPT
  {
    return ~( AllocationCreateFlags( bits ) );
  }

  VULKAN_HPP_INLINE std::string to_string( AllocationCreateFlags value  )
  {

    if ( !value ) return "{}";
    std::string result;

    return "{ " + result.substr(0, result.size() - 3) + " }";
  }


  using AllocatorCreateFlags = Flags<AllocatorCreateFlagBits>;

  template <> struct FlagTraits<AllocatorCreateFlagBits>
  {
    enum : VkFlags
    {
      allFlags = VkFlags(AllocatorCreateFlagBits::eExternallySynchronized) | VkFlags(AllocatorCreateFlagBits::eKhrDedicatedAllocation) | VkFlags(AllocatorCreateFlagBits::eKhrBindMemory2) | VkFlags(AllocatorCreateFlagBits::eExtMemoryBudget) | VkFlags(AllocatorCreateFlagBits::eFlagsMaxEnum)
    };
  };

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR AllocatorCreateFlags operator|( AllocatorCreateFlagBits bit0, AllocatorCreateFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return AllocatorCreateFlags( bit0 ) | bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR AllocatorCreateFlags operator&( AllocatorCreateFlagBits bit0, AllocatorCreateFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return AllocatorCreateFlags( bit0 ) & bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR AllocatorCreateFlags operator^( AllocatorCreateFlagBits bit0, AllocatorCreateFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return AllocatorCreateFlags( bit0 ) ^ bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR AllocatorCreateFlags operator~( AllocatorCreateFlagBits bits ) VULKAN_HPP_NOEXCEPT
  {
    return ~( AllocatorCreateFlags( bits ) );
  }

  VULKAN_HPP_INLINE std::string to_string( AllocatorCreateFlags value  )
  {

    if ( !value ) return "{}";
    std::string result;

    return "{ " + result.substr(0, result.size() - 3) + " }";
  }


  using DefragmentationFlags = Flags<DefragmentationFlagBits>;

  template <> struct FlagTraits<DefragmentationFlagBits>
  {
    enum : VkFlags
    {
      allFlags = VkFlags(DefragmentationFlagBits::eFlagsMaxEnum)
    };
  };

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR DefragmentationFlags operator|( DefragmentationFlagBits bit0, DefragmentationFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return DefragmentationFlags( bit0 ) | bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR DefragmentationFlags operator&( DefragmentationFlagBits bit0, DefragmentationFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return DefragmentationFlags( bit0 ) & bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR DefragmentationFlags operator^( DefragmentationFlagBits bit0, DefragmentationFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return DefragmentationFlags( bit0 ) ^ bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR DefragmentationFlags operator~( DefragmentationFlagBits bits ) VULKAN_HPP_NOEXCEPT
  {
    return ~( DefragmentationFlags( bits ) );
  }

  VULKAN_HPP_INLINE std::string to_string( DefragmentationFlags value  )
  {

    if ( !value ) return "{}";
    std::string result;

    return "{ " + result.substr(0, result.size() - 3) + " }";
  }


  using PoolCreateFlags = Flags<PoolCreateFlagBits>;

  template <> struct FlagTraits<PoolCreateFlagBits>
  {
    enum : VkFlags
    {
      allFlags = VkFlags(PoolCreateFlagBits::eIgnoreBufferImageGranularity) | VkFlags(PoolCreateFlagBits::eLinearAlgorithm) | VkFlags(PoolCreateFlagBits::eBuddyAlgorithm) | VkFlags(PoolCreateFlagBits::eAlgorithmMask) | VkFlags(PoolCreateFlagBits::eFlagsMaxEnum)
    };
  };

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR PoolCreateFlags operator|( PoolCreateFlagBits bit0, PoolCreateFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return PoolCreateFlags( bit0 ) | bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR PoolCreateFlags operator&( PoolCreateFlagBits bit0, PoolCreateFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return PoolCreateFlags( bit0 ) & bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR PoolCreateFlags operator^( PoolCreateFlagBits bit0, PoolCreateFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return PoolCreateFlags( bit0 ) ^ bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR PoolCreateFlags operator~( PoolCreateFlagBits bits ) VULKAN_HPP_NOEXCEPT
  {
    return ~( PoolCreateFlags( bits ) );
  }

  VULKAN_HPP_INLINE std::string to_string( PoolCreateFlags value  )
  {

    if ( !value ) return "{}";
    std::string result;

    return "{ " + result.substr(0, result.size() - 3) + " }";
  }


  using RecordFlags = Flags<RecordFlagBits>;

  template <> struct FlagTraits<RecordFlagBits>
  {
    enum : VkFlags
    {
      allFlags = VkFlags(RecordFlagBits::eFlushAfterCall) | VkFlags(RecordFlagBits::eFlagsMaxEnum)
    };
  };

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR RecordFlags operator|( RecordFlagBits bit0, RecordFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return RecordFlags( bit0 ) | bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR RecordFlags operator&( RecordFlagBits bit0, RecordFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return RecordFlags( bit0 ) & bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR RecordFlags operator^( RecordFlagBits bit0, RecordFlagBits bit1 ) VULKAN_HPP_NOEXCEPT
  {
    return RecordFlags( bit0 ) ^ bit1;
  }

  VULKAN_HPP_INLINE VULKAN_HPP_CONSTEXPR RecordFlags operator~( RecordFlagBits bits ) VULKAN_HPP_NOEXCEPT
  {
    return ~( RecordFlags( bits ) );
  }

  VULKAN_HPP_INLINE std::string to_string( RecordFlags value  )
  {

    if ( !value ) return "{}";
    std::string result;

    return "{ " + result.substr(0, result.size() - 3) + " }";
  }
} // namespace VULKAN_HPP_NAMESPACE

#ifndef VULKAN_HPP_NO_EXCEPTIONS
namespace std
{
  template <>
  struct is_error_code_enum<VULKAN_HPP_NAMESPACE::Result> : public true_type
  {};
}
#endif

namespace VULKAN_HPP_NAMESPACE
{
#ifndef VULKAN_HPP_NO_EXCEPTIONS
  class ErrorCategoryImpl : public std::error_category
  {
    public:
    virtual const char* name() const VULKAN_HPP_NOEXCEPT override { return VULKAN_HPP_NAMESPACE_STRING"::Result"; }
    virtual std::string message(int ev) const override { return to_string(static_cast<Result>(ev)); }
  };

  class Error
  {
    public:
    Error() VULKAN_HPP_NOEXCEPT = default;
    Error(const Error&) VULKAN_HPP_NOEXCEPT = default;
    virtual ~Error() VULKAN_HPP_NOEXCEPT = default;

    virtual const char* what() const VULKAN_HPP_NOEXCEPT = 0;
  };

  class LogicError : public Error, public std::logic_error
  {
    public:
    explicit LogicError( const std::string& what )
      : Error(), std::logic_error(what) {}
    explicit LogicError( char const * what )
      : Error(), std::logic_error(what) {}

    virtual const char* what() const VULKAN_HPP_NOEXCEPT { return std::logic_error::what(); }
  };

  class SystemError : public Error, public std::system_error
  {
    public:
    SystemError( std::error_code ec )
      : Error(), std::system_error(ec) {}
    SystemError( std::error_code ec, std::string const& what )
      : Error(), std::system_error(ec, what) {}
    SystemError( std::error_code ec, char const * what )
      : Error(), std::system_error(ec, what) {}
    SystemError( int ev, std::error_category const& ecat )
      : Error(), std::system_error(ev, ecat) {}
    SystemError( int ev, std::error_category const& ecat, std::string const& what)
      : Error(), std::system_error(ev, ecat, what) {}
    SystemError( int ev, std::error_category const& ecat, char const * what)
      : Error(), std::system_error(ev, ecat, what) {}

    virtual const char* what() const VULKAN_HPP_NOEXCEPT { return std::system_error::what(); }
  };

  VULKAN_HPP_INLINE const std::error_category& errorCategory() VULKAN_HPP_NOEXCEPT
  {
    static ErrorCategoryImpl instance;
    return instance;
  }

  VULKAN_HPP_INLINE std::error_code make_error_code(Result e) VULKAN_HPP_NOEXCEPT
  {
    return std::error_code(static_cast<int>(e), errorCategory());
  }

  VULKAN_HPP_INLINE std::error_condition make_error_condition(Result e) VULKAN_HPP_NOEXCEPT
  {
    return std::error_condition(static_cast<int>(e), errorCategory());
  }

  class OutOfHostMemoryError : public SystemError
  {
  public:
    OutOfHostMemoryError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorOutOfHostMemory ), message ) {}
    OutOfHostMemoryError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorOutOfHostMemory ), message ) {}
  };

  class OutOfDeviceMemoryError : public SystemError
  {
  public:
    OutOfDeviceMemoryError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorOutOfDeviceMemory ), message ) {}
    OutOfDeviceMemoryError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorOutOfDeviceMemory ), message ) {}
  };

  class InitializationFailedError : public SystemError
  {
  public:
    InitializationFailedError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorInitializationFailed ), message ) {}
    InitializationFailedError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorInitializationFailed ), message ) {}
  };

  class DeviceLostError : public SystemError
  {
  public:
    DeviceLostError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorDeviceLost ), message ) {}
    DeviceLostError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorDeviceLost ), message ) {}
  };

  class MemoryMapFailedError : public SystemError
  {
  public:
    MemoryMapFailedError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorMemoryMapFailed ), message ) {}
    MemoryMapFailedError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorMemoryMapFailed ), message ) {}
  };

  class LayerNotPresentError : public SystemError
  {
  public:
    LayerNotPresentError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorLayerNotPresent ), message ) {}
    LayerNotPresentError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorLayerNotPresent ), message ) {}
  };

  class ExtensionNotPresentError : public SystemError
  {
  public:
    ExtensionNotPresentError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorExtensionNotPresent ), message ) {}
    ExtensionNotPresentError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorExtensionNotPresent ), message ) {}
  };

  class FeatureNotPresentError : public SystemError
  {
  public:
    FeatureNotPresentError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorFeatureNotPresent ), message ) {}
    FeatureNotPresentError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorFeatureNotPresent ), message ) {}
  };

  class IncompatibleDriverError : public SystemError
  {
  public:
    IncompatibleDriverError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorIncompatibleDriver ), message ) {}
    IncompatibleDriverError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorIncompatibleDriver ), message ) {}
  };

  class TooManyObjectsError : public SystemError
  {
  public:
    TooManyObjectsError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorTooManyObjects ), message ) {}
    TooManyObjectsError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorTooManyObjects ), message ) {}
  };

  class FormatNotSupportedError : public SystemError
  {
  public:
    FormatNotSupportedError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorFormatNotSupported ), message ) {}
    FormatNotSupportedError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorFormatNotSupported ), message ) {}
  };

  class FragmentedPoolError : public SystemError
  {
  public:
    FragmentedPoolError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorFragmentedPool ), message ) {}
    FragmentedPoolError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorFragmentedPool ), message ) {}
  };

  class SurfaceLostKhrError : public SystemError
  {
  public:
    SurfaceLostKhrError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorSurfaceLostKhr ), message ) {}
    SurfaceLostKhrError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorSurfaceLostKhr ), message ) {}
  };

  class NativeWindowInUseKhrError : public SystemError
  {
  public:
    NativeWindowInUseKhrError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorNativeWindowInUseKhr ), message ) {}
    NativeWindowInUseKhrError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorNativeWindowInUseKhr ), message ) {}
  };

  class OutOfDateKhrError : public SystemError
  {
  public:
    OutOfDateKhrError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorOutOfDateKhr ), message ) {}
    OutOfDateKhrError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorOutOfDateKhr ), message ) {}
  };

  class IncompatibleDisplayKhrError : public SystemError
  {
  public:
    IncompatibleDisplayKhrError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorIncompatibleDisplayKhr ), message ) {}
    IncompatibleDisplayKhrError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorIncompatibleDisplayKhr ), message ) {}
  };

  class ValidationFailedExtError : public SystemError
  {
  public:
    ValidationFailedExtError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorValidationFailedExt ), message ) {}
    ValidationFailedExtError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorValidationFailedExt ), message ) {}
  };

  class InvalidShaderNvError : public SystemError
  {
  public:
    InvalidShaderNvError( std::string const& message )
      : SystemError( make_error_code( VkResult::eErrorInvalidShaderNv ), message ) {}
    InvalidShaderNvError( char const * message )
      : SystemError( make_error_code( VkResult::eErrorInvalidShaderNv ), message ) {}
  };


  [[noreturn]] static void throwResultException( Result result, char const * message )
  {
    switch ( result )
    {
      case Result::eErrorOutOfHostMemory: throw OutOfHostMemoryError( message );
      case Result::eErrorOutOfDeviceMemory: throw OutOfDeviceMemoryError( message );
      case Result::eErrorInitializationFailed: throw InitializationFailedError( message );
      case Result::eErrorDeviceLost: throw DeviceLostError( message );
      case Result::eErrorMemoryMapFailed: throw MemoryMapFailedError( message );
      case Result::eErrorLayerNotPresent: throw LayerNotPresentError( message );
      case Result::eErrorExtensionNotPresent: throw ExtensionNotPresentError( message );
      case Result::eErrorFeatureNotPresent: throw FeatureNotPresentError( message );
      case Result::eErrorIncompatibleDriver: throw IncompatibleDriverError( message );
      case Result::eErrorTooManyObjects: throw TooManyObjectsError( message );
      case Result::eErrorFormatNotSupported: throw FormatNotSupportedError( message );
      case Result::eErrorFragmentedPool: throw FragmentedPoolError( message );
      case Result::eErrorSurfaceLostKhr: throw SurfaceLostKhrError( message );
      case Result::eErrorNativeWindowInUseKhr: throw NativeWindowInUseKhrError( message );
      case Result::eErrorOutOfDateKhr: throw OutOfDateKhrError( message );
      case Result::eErrorIncompatibleDisplayKhr: throw IncompatibleDisplayKhrError( message );
      case Result::eErrorValidationFailedExt: throw ValidationFailedExtError( message );
      case Result::eErrorInvalidShaderNv: throw InvalidShaderNvError( message );
      default: throw SystemError( make_error_code( result ) );
    }
  }
#endif

  template <typename T> void ignore(T const&) VULKAN_HPP_NOEXCEPT {}

  template <typename T>
  struct ResultValue
  {
#ifdef VULKAN_HPP_HAS_NOEXCEPT
    ResultValue( Result r, T & v ) VULKAN_HPP_NOEXCEPT(VULKAN_HPP_NOEXCEPT(T(v)))
#else
    ResultValue( Result r, T & v )
#endif
      : result( r )
      , value( v )
    {}

#ifdef VULKAN_HPP_HAS_NOEXCEPT
    ResultValue( Result r, T && v ) VULKAN_HPP_NOEXCEPT(VULKAN_HPP_NOEXCEPT(T(std::move(v))))
#else
    ResultValue( Result r, T && v )
#endif
      : result( r )
      , value( std::move( v ) )
    {}

    Result  result;
    T       value;

    operator std::tuple<Result&, T&>() VULKAN_HPP_NOEXCEPT { return std::tuple<Result&, T&>(result, value); }

#if !defined(VULKAN_HPP_DISABLE_IMPLICIT_RESULT_VALUE_CAST)
    VULKAN_HPP_DEPRECATED("Implicit-cast operators on vk::ResultValue are deprecated. Explicitly access the value as member of ResultValue.")
    operator T const& () const & VULKAN_HPP_NOEXCEPT
    {
      return value;
    }

    VULKAN_HPP_DEPRECATED("Implicit-cast operators on vk::ResultValue are deprecated. Explicitly access the value as member of ResultValue.")
    operator T& () & VULKAN_HPP_NOEXCEPT
    {
      return value;
    }

    VULKAN_HPP_DEPRECATED("Implicit-cast operators on vk::ResultValue are deprecated. Explicitly access the value as member of ResultValue.")
    operator T const&& () const && VULKAN_HPP_NOEXCEPT
    {
      return std::move( value );
    }

    VULKAN_HPP_DEPRECATED("Implicit-cast operators on vk::ResultValue are deprecated. Explicitly access the value as member of ResultValue.")
    operator T&& () && VULKAN_HPP_NOEXCEPT
    {
      return std::move( value );
    }
#endif
  };

#if !defined(VULKAN_HPP_NO_SMART_HANDLE)
  template <typename Type, typename Dispatch>
  struct ResultValue<UniqueHandle<Type,Dispatch>>
  {
#ifdef VULKAN_HPP_HAS_NOEXCEPT
    ResultValue(Result r, UniqueHandle<Type, Dispatch> && v) VULKAN_HPP_NOEXCEPT
#else
    ResultValue(Result r, UniqueHandle<Type, Dispatch> && v)
#endif
      : result(r)
      , value(std::move(v))
    {}

    std::tuple<Result, UniqueHandle<Type, Dispatch>> asTuple()
    {
      return std::make_tuple( result, std::move( value ) );
    }

#  if !defined(VULKAN_HPP_DISABLE_IMPLICIT_RESULT_VALUE_CAST)
    VULKAN_HPP_DEPRECATED("Implicit-cast operators on vk::ResultValue are deprecated. Explicitly access the value as member of ResultValue.")
    operator UniqueHandle<Type, Dispatch>& () & VULKAN_HPP_NOEXCEPT
    {
      return value;
    }

    VULKAN_HPP_DEPRECATED("Implicit-cast operators on vk::ResultValue are deprecated. Explicitly access the value as member of ResultValue.")
    operator UniqueHandle<Type, Dispatch>() VULKAN_HPP_NOEXCEPT
    {
      return std::move(value);
    }
#  endif

    Result                        result;
    UniqueHandle<Type, Dispatch>  value;
  };

  template <typename Type, typename Dispatch>
  struct ResultValue<std::vector<UniqueHandle<Type, Dispatch>>>
  {
#  ifdef VULKAN_HPP_HAS_NOEXCEPT
    ResultValue( Result r, std::vector<UniqueHandle<Type, Dispatch>> && v ) VULKAN_HPP_NOEXCEPT
#  else
    ResultValue( Result r, std::vector<UniqueHandle<Type, Dispatch>> && v )
#  endif
      : result( r )
      , value( std::move( v ) )
    {}

    Result                                    result;
    std::vector<UniqueHandle<Type, Dispatch>> value;

    operator std::tuple<Result &, std::vector<UniqueHandle<Type, Dispatch>> &>() VULKAN_HPP_NOEXCEPT
    {
      return std::tuple<Result &, std::vector<UniqueHandle<Type, Dispatch>> &>( result, value );
    }
  };
#endif

  template <typename T>
  struct ResultValueType
  {
#ifdef VULKAN_HPP_NO_EXCEPTIONS
    typedef ResultValue<T>  type;
#else
    typedef T               type;
#endif
  };

  template <>
  struct ResultValueType<void>
  {
#ifdef VULKAN_HPP_NO_EXCEPTIONS
    typedef Result type;
#else
    typedef void   type;
#endif
  };

  VULKAN_HPP_INLINE ResultValueType<void>::type createResultValue( Result result, char const * message )
  {
#ifdef VULKAN_HPP_NO_EXCEPTIONS
    ignore(message);
    VULKAN_HPP_ASSERT_ON_RESULT( result == Result::eSuccess );
    return result;
#else
    if ( result != Result::eSuccess )
    {
      throwResultException( result, message );
    }
#endif
  }

  template <typename T>
  VULKAN_HPP_INLINE typename ResultValueType<T>::type createResultValue( Result result, T & data, char const * message )
  {
#ifdef VULKAN_HPP_NO_EXCEPTIONS
    ignore(message);
    VULKAN_HPP_ASSERT_ON_RESULT( result == Result::eSuccess );
    return ResultValue<T>( result, std::move( data ) );
#else
    if ( result != Result::eSuccess )
    {
      throwResultException( result, message );
    }
    return std::move( data );
#endif
  }

  VULKAN_HPP_INLINE Result createResultValue( Result result, char const * message, std::initializer_list<Result> successCodes )
  {
#ifdef VULKAN_HPP_NO_EXCEPTIONS
    ignore(message);
    ignore(successCodes);   // just in case VULKAN_HPP_ASSERT_ON_RESULT is empty
    VULKAN_HPP_ASSERT_ON_RESULT( std::find( successCodes.begin(), successCodes.end(), result ) != successCodes.end() );
#else
    if ( std::find( successCodes.begin(), successCodes.end(), result ) == successCodes.end() )
    {
      throwResultException( result, message );
    }
#endif
    return result;
  }

  template <typename T>
  VULKAN_HPP_INLINE ResultValue<T> createResultValue( Result result, T & data, char const * message, std::initializer_list<Result> successCodes )
  {
#ifdef VULKAN_HPP_NO_EXCEPTIONS
    ignore(message);
    ignore(successCodes);   // just in case VULKAN_HPP_ASSERT_ON_RESULT is empty
    VULKAN_HPP_ASSERT_ON_RESULT( std::find( successCodes.begin(), successCodes.end(), result ) != successCodes.end() );
#else
    if ( std::find( successCodes.begin(), successCodes.end(), result ) == successCodes.end() )
    {
      throwResultException( result, message );
    }
#endif
    return ResultValue<T>( result, data );
  }

#ifndef VULKAN_HPP_NO_SMART_HANDLE
  template <typename T, typename D>
  VULKAN_HPP_INLINE typename ResultValueType<UniqueHandle<T,D>>::type createResultValue( Result result, T & data, char const * message, typename UniqueHandleTraits<T,D>::deleter const& deleter )
  {
#ifdef VULKAN_HPP_NO_EXCEPTIONS
    ignore(message);
    VULKAN_HPP_ASSERT_ON_RESULT( result == Result::eSuccess );
    return ResultValue<UniqueHandle<T,D>>( result, UniqueHandle<T,D>(data, deleter) );
#else
    if ( result != Result::eSuccess )
    {
      throwResultException( result, message );
    }
    return UniqueHandle<T,D>(data, deleter);
#endif
  }

  template <typename T, typename D>
  VULKAN_HPP_INLINE ResultValue<UniqueHandle<T, D>>
                    createResultValue( Result                                             result,
                                       T &                                                data,
                                       char const *                                       message,
                                       std::initializer_list<Result>                      successCodes,
                                       typename UniqueHandleTraits<T, D>::deleter const & deleter )
  {
#  ifdef VULKAN_HPP_NO_EXCEPTIONS
    ignore( message );
    ignore(successCodes);   // just in case VULKAN_HPP_ASSERT_ON_RESULT is empty
    VULKAN_HPP_ASSERT_ON_RESULT( std::find( successCodes.begin(), successCodes.end(), result ) != successCodes.end() );
#  else
    if ( std::find( successCodes.begin(), successCodes.end(), result ) == successCodes.end() )
    {
      throwResultException( result, message );
    }
#  endif
    return ResultValue<UniqueHandle<T, D>>( result, UniqueHandle<T, D>( data, deleter ) );
  }

  template <typename T, typename D>
  VULKAN_HPP_INLINE typename ResultValueType<std::vector<UniqueHandle<T, D>>>::type
    createResultValue( Result result, std::vector<UniqueHandle<T, D>> && data, char const * message )
  {
#  ifdef VULKAN_HPP_NO_EXCEPTIONS
    ignore( message );
    VULKAN_HPP_ASSERT_ON_RESULT( result == Result::eSuccess );
    return ResultValue<std::vector<UniqueHandle<T, D>>>( result, std::move( data ) );
#  else
    if ( result != Result::eSuccess )
    {
      throwResultException( result, message );
    }
    return std::move( data );
#  endif
  }

  template <typename T, typename D>
  VULKAN_HPP_INLINE ResultValue<std::vector<UniqueHandle<T, D>>>
                    createResultValue( Result                             result,
                                       std::vector<UniqueHandle<T, D>> && data,
                                       char const *                       message,
                                       std::initializer_list<Result>      successCodes )
  {
#  ifdef VULKAN_HPP_NO_EXCEPTIONS
    ignore( message );
    ignore(successCodes);   // just in case VULKAN_HPP_ASSERT_ON_RESULT is empty
    VULKAN_HPP_ASSERT_ON_RESULT( std::find( successCodes.begin(), successCodes.end(), result ) != successCodes.end() );
#  else
    if ( std::find( successCodes.begin(), successCodes.end(), result ) == successCodes.end() )
    {
      throwResultException( result, message );
    }
#  endif
    return ResultValue<std::vector<UniqueHandle<T, D>>>( result, std::move( data ) );
  }
#endif

  class Pool
  {
  public:
    using CType = VkPool;

    static VULKAN_HPP_CONST_OR_CONSTEXPR VULKAN_HPP_NAMESPACE::ObjectType objectType = VULKAN_HPP_NAMESPACE::ObjectType::eVmaPool;
    static VULKAN_HPP_CONST_OR_CONSTEXPR VULKAN_HPP_NAMESPACE::DebugReportObjectTypeEXT debugReportObjectType = VULKAN_HPP_NAMESPACE::DebugReportObjectTypeEXT::eUnknown;

  public:
    VULKAN_HPP_CONSTEXPR Pool() VULKAN_HPP_NOEXCEPT
      : m_pool(VK_NULL_HANDLE)
    {}

    VULKAN_HPP_CONSTEXPR Pool( std::nullptr_t ) VULKAN_HPP_NOEXCEPT
      : m_pool(VK_NULL_HANDLE)
    {}

    VULKAN_HPP_TYPESAFE_EXPLICIT Pool( VkPool pool ) VULKAN_HPP_NOEXCEPT
      : m_pool( pool )
    {}

#if defined(VULKAN_HPP_TYPESAFE_CONVERSION)
    Pool & operator=(VkPool pool) VULKAN_HPP_NOEXCEPT
    {
      m_pool = pool;
      return *this;
    }
#endif

    Pool & operator=( std::nullptr_t ) VULKAN_HPP_NOEXCEPT
    {
      m_pool = VK_NULL_HANDLE;
      return *this;
    }

#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( Pool const& ) const = default;
#else
    bool operator==( Pool const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_pool == rhs.m_pool;
    }

    bool operator!=(Pool const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_pool != rhs.m_pool;
    }

    bool operator<(Pool const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_pool < rhs.m_pool;
    }
#endif

    VULKAN_HPP_TYPESAFE_EXPLICIT operator VkPool() const VULKAN_HPP_NOEXCEPT
    {
      return m_pool;
    }

    explicit operator bool() const VULKAN_HPP_NOEXCEPT
    {
      return m_pool != VK_NULL_HANDLE;
    }

    bool operator!() const VULKAN_HPP_NOEXCEPT
    {
      return m_pool == VK_NULL_HANDLE;
    }

  private:
    VkPool m_pool;
  };
  static_assert( sizeof( VULKAN_HPP_NAMESPACE::Pool ) == sizeof( VkPool ), "handle and wrapper have different size!" );

  template <>
  struct VULKAN_HPP_DEPRECATED("vk::cpp_type is deprecated. Use vk::CppType instead.") cpp_type<ObjectType::eVmaPool>
  {
    using type = VULKAN_HPP_NAMESPACE::Pool;
  };

  template <>
  struct CppType<VULKAN_HPP_NAMESPACE::ObjectType, VULKAN_HPP_NAMESPACE::ObjectType::eVmaPool>
  {
    using Type = VULKAN_HPP_NAMESPACE::Pool;
  };



  template <>
  struct isVulkanHandleType<VULKAN_HPP_NAMESPACE::Pool>
  {
    static VULKAN_HPP_CONST_OR_CONSTEXPR bool value = true;
  };

  struct AllocationCreateInfo
  {


#if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
    VULKAN_HPP_CONSTEXPR AllocationCreateInfo(AllocationCreateFlags flags_ = {}, MemoryUsage usage_ = VULKAN_HPP_NAMESPACE::MemoryUsage::eUnknown, VkMemoryPropertyFlags requiredFlags_ = {}, VkMemoryPropertyFlags preferredFlags_ = {}, uint32_t memoryTypeBits_ = {}, Pool pool_ = {}, void* pUserData_ = {}) VULKAN_HPP_NOEXCEPT
    : flags( flags_ ), usage( usage_ ), requiredFlags( requiredFlags_ ), preferredFlags( preferredFlags_ ), memoryTypeBits( memoryTypeBits_ ), pool( pool_ ), pUserData( pUserData_ )
    {}

    VULKAN_HPP_CONSTEXPR AllocationCreateInfo( AllocationCreateInfo const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    AllocationCreateInfo( VkAllocationCreateInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )

    AllocationCreateInfo & operator=( VkAllocationCreateInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = *reinterpret_cast<VULKAN_HPP_NAMESPACE::AllocationCreateInfo const *>( &rhs );
      return *this;
    }

    AllocationCreateInfo & operator=( AllocationCreateInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( AllocationCreateInfo ) );
      return *this;
    }

    AllocationCreateInfo & setFlags( AllocationCreateFlags flags_ ) VULKAN_HPP_NOEXCEPT
    {
      flags = flags_;
      return *this;
    }

    AllocationCreateInfo & setUsage( MemoryUsage usage_ ) VULKAN_HPP_NOEXCEPT
    {
      usage = usage_;
      return *this;
    }

    AllocationCreateInfo & setRequiredFlags( VkMemoryPropertyFlags requiredFlags_ ) VULKAN_HPP_NOEXCEPT
    {
      requiredFlags = requiredFlags_;
      return *this;
    }

    AllocationCreateInfo & setPreferredFlags( VkMemoryPropertyFlags preferredFlags_ ) VULKAN_HPP_NOEXCEPT
    {
      preferredFlags = preferredFlags_;
      return *this;
    }

    AllocationCreateInfo & setMemoryTypeBits( uint32_t memoryTypeBits_ ) VULKAN_HPP_NOEXCEPT
    {
      memoryTypeBits = memoryTypeBits_;
      return *this;
    }

    AllocationCreateInfo & setPool( Pool pool_ ) VULKAN_HPP_NOEXCEPT
    {
      pool = pool_;
      return *this;
    }

    AllocationCreateInfo & setPUserData( void* pUserData_ ) VULKAN_HPP_NOEXCEPT
    {
      pUserData = pUserData_;
      return *this;
    }


    operator VmaAllocationCreateInfo const&() const VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<const VmaAllocationCreateInfo*>( this );
    }

    operator VmaAllocationCreateInfo &() VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<VmaAllocationCreateInfo*>( this );
    }


#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( AllocationCreateInfo const& ) const = default;
#else
    bool operator==( AllocationCreateInfo const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return ( flags == rhs.flags )
          && ( usage == rhs.usage )
          && ( memcmp( &requiredFlags, &rhs.requiredFlags, sizeof( VkMemoryPropertyFlags ) ) == 0 )
          && ( memcmp( &preferredFlags, &rhs.preferredFlags, sizeof( VkMemoryPropertyFlags ) ) == 0 )
          && ( memoryTypeBits == rhs.memoryTypeBits )
          && ( pool == rhs.pool )
          && ( pUserData == rhs.pUserData );
    }

    bool operator!=( AllocationCreateInfo const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    AllocationCreateFlags flags = {};
    MemoryUsage usage = VULKAN_HPP_NAMESPACE::MemoryUsage::eUnknown;
    VkMemoryPropertyFlags requiredFlags = {};
    VkMemoryPropertyFlags preferredFlags = {};
    uint32_t memoryTypeBits = {};
    Pool pool = {};
    void* pUserData = {};

  };
  static_assert( sizeof( AllocationCreateInfo ) == sizeof( VmaAllocationCreateInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<AllocationCreateInfo>::value, "struct wrapper is not a standard layout!" );

  struct AllocationInfo
  {


#if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
    VULKAN_HPP_CONSTEXPR AllocationInfo(uint32_t memoryType_ = {}, VkDeviceMemory deviceMemory_ = {}, VkDeviceSize offset_ = {}, VkDeviceSize size_ = {}, void* pMappedData_ = {}, void* pUserData_ = {}) VULKAN_HPP_NOEXCEPT
    : memoryType( memoryType_ ), deviceMemory( deviceMemory_ ), offset( offset_ ), size( size_ ), pMappedData( pMappedData_ ), pUserData( pUserData_ )
    {}

    VULKAN_HPP_CONSTEXPR AllocationInfo( AllocationInfo const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    AllocationInfo( VkAllocationInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )

    AllocationInfo & operator=( VkAllocationInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = *reinterpret_cast<VULKAN_HPP_NAMESPACE::AllocationInfo const *>( &rhs );
      return *this;
    }

    AllocationInfo & operator=( AllocationInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( AllocationInfo ) );
      return *this;
    }

    AllocationInfo & setMemoryType( uint32_t memoryType_ ) VULKAN_HPP_NOEXCEPT
    {
      memoryType = memoryType_;
      return *this;
    }

    AllocationInfo & setDeviceMemory( VkDeviceMemory deviceMemory_ ) VULKAN_HPP_NOEXCEPT
    {
      deviceMemory = deviceMemory_;
      return *this;
    }

    AllocationInfo & setOffset( VkDeviceSize offset_ ) VULKAN_HPP_NOEXCEPT
    {
      offset = offset_;
      return *this;
    }

    AllocationInfo & setSize( VkDeviceSize size_ ) VULKAN_HPP_NOEXCEPT
    {
      size = size_;
      return *this;
    }

    AllocationInfo & setPMappedData( void* pMappedData_ ) VULKAN_HPP_NOEXCEPT
    {
      pMappedData = pMappedData_;
      return *this;
    }

    AllocationInfo & setPUserData( void* pUserData_ ) VULKAN_HPP_NOEXCEPT
    {
      pUserData = pUserData_;
      return *this;
    }


    operator VmaAllocationInfo const&() const VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<const VmaAllocationInfo*>( this );
    }

    operator VmaAllocationInfo &() VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<VmaAllocationInfo*>( this );
    }


#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( AllocationInfo const& ) const = default;
#else
    bool operator==( AllocationInfo const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return ( memoryType == rhs.memoryType )
          && ( memcmp( &deviceMemory, &rhs.deviceMemory, sizeof( VkDeviceMemory ) ) == 0 )
          && ( memcmp( &offset, &rhs.offset, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &size, &rhs.size, sizeof( VkDeviceSize ) ) == 0 )
          && ( pMappedData == rhs.pMappedData )
          && ( pUserData == rhs.pUserData );
    }

    bool operator!=( AllocationInfo const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    uint32_t memoryType = {};
    VkDeviceMemory deviceMemory = {};
    VkDeviceSize offset = {};
    VkDeviceSize size = {};
    void* pMappedData = {};
    void* pUserData = {};

  };
  static_assert( sizeof( AllocationInfo ) == sizeof( VmaAllocationInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<AllocationInfo>::value, "struct wrapper is not a standard layout!" );

  struct DeviceMemoryCallbacks
  {


#if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
    VULKAN_HPP_CONSTEXPR DeviceMemoryCallbacks(PFN_vmaAllocateDeviceMemoryFunction pfnAllocate_ = {}, PFN_vmaFreeDeviceMemoryFunction pfnFree_ = {}) VULKAN_HPP_NOEXCEPT
    : pfnAllocate( pfnAllocate_ ), pfnFree( pfnFree_ )
    {}

    VULKAN_HPP_CONSTEXPR DeviceMemoryCallbacks( DeviceMemoryCallbacks const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    DeviceMemoryCallbacks( VkDeviceMemoryCallbacks const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )

    DeviceMemoryCallbacks & operator=( VkDeviceMemoryCallbacks const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = *reinterpret_cast<VULKAN_HPP_NAMESPACE::DeviceMemoryCallbacks const *>( &rhs );
      return *this;
    }

    DeviceMemoryCallbacks & operator=( DeviceMemoryCallbacks const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( DeviceMemoryCallbacks ) );
      return *this;
    }

    DeviceMemoryCallbacks & setPfnAllocate( PFN_vmaAllocateDeviceMemoryFunction pfnAllocate_ ) VULKAN_HPP_NOEXCEPT
    {
      pfnAllocate = pfnAllocate_;
      return *this;
    }

    DeviceMemoryCallbacks & setPfnFree( PFN_vmaFreeDeviceMemoryFunction pfnFree_ ) VULKAN_HPP_NOEXCEPT
    {
      pfnFree = pfnFree_;
      return *this;
    }


    operator VmaDeviceMemoryCallbacks const&() const VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<const VmaDeviceMemoryCallbacks*>( this );
    }

    operator VmaDeviceMemoryCallbacks &() VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<VmaDeviceMemoryCallbacks*>( this );
    }


#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( DeviceMemoryCallbacks const& ) const = default;
#else
    bool operator==( DeviceMemoryCallbacks const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return ( pfnAllocate == rhs.pfnAllocate )
          && ( pfnFree == rhs.pfnFree );
    }

    bool operator!=( DeviceMemoryCallbacks const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    PFN_vmaAllocateDeviceMemoryFunction pfnAllocate = {};
    PFN_vmaFreeDeviceMemoryFunction pfnFree = {};

  };
  static_assert( sizeof( DeviceMemoryCallbacks ) == sizeof( VmaDeviceMemoryCallbacks ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<DeviceMemoryCallbacks>::value, "struct wrapper is not a standard layout!" );

  struct VulkanFunctions
  {


#if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
    VULKAN_HPP_CONSTEXPR VulkanFunctions(PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties_ = {}, PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties_ = {}, PFN_vkAllocateMemory vkAllocateMemory_ = {}, PFN_vkFreeMemory vkFreeMemory_ = {}, PFN_vkMapMemory vkMapMemory_ = {}, PFN_vkUnmapMemory vkUnmapMemory_ = {}, PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges_ = {}, PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges_ = {}, PFN_vkBindBufferMemory vkBindBufferMemory_ = {}, PFN_vkBindImageMemory vkBindImageMemory_ = {}, PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements_ = {}, PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements_ = {}, PFN_vkCreateBuffer vkCreateBuffer_ = {}, PFN_vkDestroyBuffer vkDestroyBuffer_ = {}, PFN_vkCreateImage vkCreateImage_ = {}, PFN_vkDestroyImage vkDestroyImage_ = {}, PFN_vkCmdCopyBuffer vkCmdCopyBuffer_ = {}) VULKAN_HPP_NOEXCEPT
    : vkGetPhysicalDeviceProperties( vkGetPhysicalDeviceProperties_ ), vkGetPhysicalDeviceMemoryProperties( vkGetPhysicalDeviceMemoryProperties_ ), vkAllocateMemory( vkAllocateMemory_ ), vkFreeMemory( vkFreeMemory_ ), vkMapMemory( vkMapMemory_ ), vkUnmapMemory( vkUnmapMemory_ ), vkFlushMappedMemoryRanges( vkFlushMappedMemoryRanges_ ), vkInvalidateMappedMemoryRanges( vkInvalidateMappedMemoryRanges_ ), vkBindBufferMemory( vkBindBufferMemory_ ), vkBindImageMemory( vkBindImageMemory_ ), vkGetBufferMemoryRequirements( vkGetBufferMemoryRequirements_ ), vkGetImageMemoryRequirements( vkGetImageMemoryRequirements_ ), vkCreateBuffer( vkCreateBuffer_ ), vkDestroyBuffer( vkDestroyBuffer_ ), vkCreateImage( vkCreateImage_ ), vkDestroyImage( vkDestroyImage_ ), vkCmdCopyBuffer( vkCmdCopyBuffer_ )
    {}

    VULKAN_HPP_CONSTEXPR VulkanFunctions( VulkanFunctions const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    VulkanFunctions( VkVulkanFunctions const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )

    VulkanFunctions & operator=( VkVulkanFunctions const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = *reinterpret_cast<VULKAN_HPP_NAMESPACE::VulkanFunctions const *>( &rhs );
      return *this;
    }

    VulkanFunctions & operator=( VulkanFunctions const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( VulkanFunctions ) );
      return *this;
    }

    VulkanFunctions & setVkGetPhysicalDeviceProperties( PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties_ ) VULKAN_HPP_NOEXCEPT
    {
      vkGetPhysicalDeviceProperties = vkGetPhysicalDeviceProperties_;
      return *this;
    }

    VulkanFunctions & setVkGetPhysicalDeviceMemoryProperties( PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties_ ) VULKAN_HPP_NOEXCEPT
    {
      vkGetPhysicalDeviceMemoryProperties = vkGetPhysicalDeviceMemoryProperties_;
      return *this;
    }

    VulkanFunctions & setVkAllocateMemory( PFN_vkAllocateMemory vkAllocateMemory_ ) VULKAN_HPP_NOEXCEPT
    {
      vkAllocateMemory = vkAllocateMemory_;
      return *this;
    }

    VulkanFunctions & setVkFreeMemory( PFN_vkFreeMemory vkFreeMemory_ ) VULKAN_HPP_NOEXCEPT
    {
      vkFreeMemory = vkFreeMemory_;
      return *this;
    }

    VulkanFunctions & setVkMapMemory( PFN_vkMapMemory vkMapMemory_ ) VULKAN_HPP_NOEXCEPT
    {
      vkMapMemory = vkMapMemory_;
      return *this;
    }

    VulkanFunctions & setVkUnmapMemory( PFN_vkUnmapMemory vkUnmapMemory_ ) VULKAN_HPP_NOEXCEPT
    {
      vkUnmapMemory = vkUnmapMemory_;
      return *this;
    }

    VulkanFunctions & setVkFlushMappedMemoryRanges( PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges_ ) VULKAN_HPP_NOEXCEPT
    {
      vkFlushMappedMemoryRanges = vkFlushMappedMemoryRanges_;
      return *this;
    }

    VulkanFunctions & setVkInvalidateMappedMemoryRanges( PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges_ ) VULKAN_HPP_NOEXCEPT
    {
      vkInvalidateMappedMemoryRanges = vkInvalidateMappedMemoryRanges_;
      return *this;
    }

    VulkanFunctions & setVkBindBufferMemory( PFN_vkBindBufferMemory vkBindBufferMemory_ ) VULKAN_HPP_NOEXCEPT
    {
      vkBindBufferMemory = vkBindBufferMemory_;
      return *this;
    }

    VulkanFunctions & setVkBindImageMemory( PFN_vkBindImageMemory vkBindImageMemory_ ) VULKAN_HPP_NOEXCEPT
    {
      vkBindImageMemory = vkBindImageMemory_;
      return *this;
    }

    VulkanFunctions & setVkGetBufferMemoryRequirements( PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements_ ) VULKAN_HPP_NOEXCEPT
    {
      vkGetBufferMemoryRequirements = vkGetBufferMemoryRequirements_;
      return *this;
    }

    VulkanFunctions & setVkGetImageMemoryRequirements( PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements_ ) VULKAN_HPP_NOEXCEPT
    {
      vkGetImageMemoryRequirements = vkGetImageMemoryRequirements_;
      return *this;
    }

    VulkanFunctions & setVkCreateBuffer( PFN_vkCreateBuffer vkCreateBuffer_ ) VULKAN_HPP_NOEXCEPT
    {
      vkCreateBuffer = vkCreateBuffer_;
      return *this;
    }

    VulkanFunctions & setVkDestroyBuffer( PFN_vkDestroyBuffer vkDestroyBuffer_ ) VULKAN_HPP_NOEXCEPT
    {
      vkDestroyBuffer = vkDestroyBuffer_;
      return *this;
    }

    VulkanFunctions & setVkCreateImage( PFN_vkCreateImage vkCreateImage_ ) VULKAN_HPP_NOEXCEPT
    {
      vkCreateImage = vkCreateImage_;
      return *this;
    }

    VulkanFunctions & setVkDestroyImage( PFN_vkDestroyImage vkDestroyImage_ ) VULKAN_HPP_NOEXCEPT
    {
      vkDestroyImage = vkDestroyImage_;
      return *this;
    }

    VulkanFunctions & setVkCmdCopyBuffer( PFN_vkCmdCopyBuffer vkCmdCopyBuffer_ ) VULKAN_HPP_NOEXCEPT
    {
      vkCmdCopyBuffer = vkCmdCopyBuffer_;
      return *this;
    }


    operator VmaVulkanFunctions const&() const VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<const VmaVulkanFunctions*>( this );
    }

    operator VmaVulkanFunctions &() VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<VmaVulkanFunctions*>( this );
    }


#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( VulkanFunctions const& ) const = default;
#else
    bool operator==( VulkanFunctions const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return ( memcmp( &vkGetPhysicalDeviceProperties, &rhs.vkGetPhysicalDeviceProperties, sizeof( PFN_vkGetPhysicalDeviceProperties ) ) == 0 )
          && ( memcmp( &vkGetPhysicalDeviceMemoryProperties, &rhs.vkGetPhysicalDeviceMemoryProperties, sizeof( PFN_vkGetPhysicalDeviceMemoryProperties ) ) == 0 )
          && ( memcmp( &vkAllocateMemory, &rhs.vkAllocateMemory, sizeof( PFN_vkAllocateMemory ) ) == 0 )
          && ( memcmp( &vkFreeMemory, &rhs.vkFreeMemory, sizeof( PFN_vkFreeMemory ) ) == 0 )
          && ( memcmp( &vkMapMemory, &rhs.vkMapMemory, sizeof( PFN_vkMapMemory ) ) == 0 )
          && ( memcmp( &vkUnmapMemory, &rhs.vkUnmapMemory, sizeof( PFN_vkUnmapMemory ) ) == 0 )
          && ( memcmp( &vkFlushMappedMemoryRanges, &rhs.vkFlushMappedMemoryRanges, sizeof( PFN_vkFlushMappedMemoryRanges ) ) == 0 )
          && ( memcmp( &vkInvalidateMappedMemoryRanges, &rhs.vkInvalidateMappedMemoryRanges, sizeof( PFN_vkInvalidateMappedMemoryRanges ) ) == 0 )
          && ( memcmp( &vkBindBufferMemory, &rhs.vkBindBufferMemory, sizeof( PFN_vkBindBufferMemory ) ) == 0 )
          && ( memcmp( &vkBindImageMemory, &rhs.vkBindImageMemory, sizeof( PFN_vkBindImageMemory ) ) == 0 )
          && ( memcmp( &vkGetBufferMemoryRequirements, &rhs.vkGetBufferMemoryRequirements, sizeof( PFN_vkGetBufferMemoryRequirements ) ) == 0 )
          && ( memcmp( &vkGetImageMemoryRequirements, &rhs.vkGetImageMemoryRequirements, sizeof( PFN_vkGetImageMemoryRequirements ) ) == 0 )
          && ( memcmp( &vkCreateBuffer, &rhs.vkCreateBuffer, sizeof( PFN_vkCreateBuffer ) ) == 0 )
          && ( memcmp( &vkDestroyBuffer, &rhs.vkDestroyBuffer, sizeof( PFN_vkDestroyBuffer ) ) == 0 )
          && ( memcmp( &vkCreateImage, &rhs.vkCreateImage, sizeof( PFN_vkCreateImage ) ) == 0 )
          && ( memcmp( &vkDestroyImage, &rhs.vkDestroyImage, sizeof( PFN_vkDestroyImage ) ) == 0 )
          && ( memcmp( &vkCmdCopyBuffer, &rhs.vkCmdCopyBuffer, sizeof( PFN_vkCmdCopyBuffer ) ) == 0 );
    }

    bool operator!=( VulkanFunctions const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
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

  };
  static_assert( sizeof( VulkanFunctions ) == sizeof( VmaVulkanFunctions ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<VulkanFunctions>::value, "struct wrapper is not a standard layout!" );

  struct RecordSettings
  {


#if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
    VULKAN_HPP_CONSTEXPR RecordSettings(RecordFlags flags_ = {}, const char* pFilePath_ = {}) VULKAN_HPP_NOEXCEPT
    : flags( flags_ ), pFilePath( pFilePath_ )
    {}

    VULKAN_HPP_CONSTEXPR RecordSettings( RecordSettings const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    RecordSettings( VkRecordSettings const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )

    RecordSettings & operator=( VkRecordSettings const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = *reinterpret_cast<VULKAN_HPP_NAMESPACE::RecordSettings const *>( &rhs );
      return *this;
    }

    RecordSettings & operator=( RecordSettings const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( RecordSettings ) );
      return *this;
    }

    RecordSettings & setFlags( RecordFlags flags_ ) VULKAN_HPP_NOEXCEPT
    {
      flags = flags_;
      return *this;
    }

    RecordSettings & setPFilePath( const char* pFilePath_ ) VULKAN_HPP_NOEXCEPT
    {
      pFilePath = pFilePath_;
      return *this;
    }


    operator VmaRecordSettings const&() const VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<const VmaRecordSettings*>( this );
    }

    operator VmaRecordSettings &() VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<VmaRecordSettings*>( this );
    }


#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( RecordSettings const& ) const = default;
#else
    bool operator==( RecordSettings const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return ( flags == rhs.flags )
          && ( pFilePath == rhs.pFilePath );
    }

    bool operator!=( RecordSettings const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    RecordFlags flags = {};
    const char* pFilePath = {};

  };
  static_assert( sizeof( RecordSettings ) == sizeof( VmaRecordSettings ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<RecordSettings>::value, "struct wrapper is not a standard layout!" );

  struct AllocatorCreateInfo
  {


#if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
    VULKAN_HPP_CONSTEXPR AllocatorCreateInfo(AllocatorCreateFlags flags_ = {}, VkPhysicalDevice physicalDevice_ = {}, VkDevice device_ = {}, VkDeviceSize preferredLargeHeapBlockSize_ = {}, const VkAllocationCallbacks* pAllocationCallbacks_ = {}, const DeviceMemoryCallbacks* pDeviceMemoryCallbacks_ = {}, uint32_t frameInUseCount_ = {}, const VkDeviceSize* pHeapSizeLimit_ = {}, const VulkanFunctions* pVulkanFunctions_ = {}, const RecordSettings* pRecordSettings_ = {}, VkInstance instance_ = {}, uint32_t vulkanApiVersion_ = {}) VULKAN_HPP_NOEXCEPT
    : flags( flags_ ), physicalDevice( physicalDevice_ ), device( device_ ), preferredLargeHeapBlockSize( preferredLargeHeapBlockSize_ ), pAllocationCallbacks( pAllocationCallbacks_ ), pDeviceMemoryCallbacks( pDeviceMemoryCallbacks_ ), frameInUseCount( frameInUseCount_ ), pHeapSizeLimit( pHeapSizeLimit_ ), pVulkanFunctions( pVulkanFunctions_ ), pRecordSettings( pRecordSettings_ ), instance( instance_ ), vulkanApiVersion( vulkanApiVersion_ )
    {}

    VULKAN_HPP_CONSTEXPR AllocatorCreateInfo( AllocatorCreateInfo const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    AllocatorCreateInfo( VkAllocatorCreateInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )

    AllocatorCreateInfo & operator=( VkAllocatorCreateInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = *reinterpret_cast<VULKAN_HPP_NAMESPACE::AllocatorCreateInfo const *>( &rhs );
      return *this;
    }

    AllocatorCreateInfo & operator=( AllocatorCreateInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( AllocatorCreateInfo ) );
      return *this;
    }

    AllocatorCreateInfo & setFlags( AllocatorCreateFlags flags_ ) VULKAN_HPP_NOEXCEPT
    {
      flags = flags_;
      return *this;
    }

    AllocatorCreateInfo & setPhysicalDevice( VkPhysicalDevice physicalDevice_ ) VULKAN_HPP_NOEXCEPT
    {
      physicalDevice = physicalDevice_;
      return *this;
    }

    AllocatorCreateInfo & setDevice( VkDevice device_ ) VULKAN_HPP_NOEXCEPT
    {
      device = device_;
      return *this;
    }

    AllocatorCreateInfo & setPreferredLargeHeapBlockSize( VkDeviceSize preferredLargeHeapBlockSize_ ) VULKAN_HPP_NOEXCEPT
    {
      preferredLargeHeapBlockSize = preferredLargeHeapBlockSize_;
      return *this;
    }

    AllocatorCreateInfo & setPAllocationCallbacks( const VkAllocationCallbacks* pAllocationCallbacks_ ) VULKAN_HPP_NOEXCEPT
    {
      pAllocationCallbacks = pAllocationCallbacks_;
      return *this;
    }

    AllocatorCreateInfo & setPDeviceMemoryCallbacks( const DeviceMemoryCallbacks* pDeviceMemoryCallbacks_ ) VULKAN_HPP_NOEXCEPT
    {
      pDeviceMemoryCallbacks = pDeviceMemoryCallbacks_;
      return *this;
    }

    AllocatorCreateInfo & setFrameInUseCount( uint32_t frameInUseCount_ ) VULKAN_HPP_NOEXCEPT
    {
      frameInUseCount = frameInUseCount_;
      return *this;
    }

    AllocatorCreateInfo & setPHeapSizeLimit( const VkDeviceSize* pHeapSizeLimit_ ) VULKAN_HPP_NOEXCEPT
    {
      pHeapSizeLimit = pHeapSizeLimit_;
      return *this;
    }

    AllocatorCreateInfo & setPVulkanFunctions( const VulkanFunctions* pVulkanFunctions_ ) VULKAN_HPP_NOEXCEPT
    {
      pVulkanFunctions = pVulkanFunctions_;
      return *this;
    }

    AllocatorCreateInfo & setPRecordSettings( const RecordSettings* pRecordSettings_ ) VULKAN_HPP_NOEXCEPT
    {
      pRecordSettings = pRecordSettings_;
      return *this;
    }

    AllocatorCreateInfo & setInstance( VkInstance instance_ ) VULKAN_HPP_NOEXCEPT
    {
      instance = instance_;
      return *this;
    }

    AllocatorCreateInfo & setVulkanApiVersion( uint32_t vulkanApiVersion_ ) VULKAN_HPP_NOEXCEPT
    {
      vulkanApiVersion = vulkanApiVersion_;
      return *this;
    }


    operator VmaAllocatorCreateInfo const&() const VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<const VmaAllocatorCreateInfo*>( this );
    }

    operator VmaAllocatorCreateInfo &() VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<VmaAllocatorCreateInfo*>( this );
    }


#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( AllocatorCreateInfo const& ) const = default;
#else
    bool operator==( AllocatorCreateInfo const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return ( flags == rhs.flags )
          && ( memcmp( &physicalDevice, &rhs.physicalDevice, sizeof( VkPhysicalDevice ) ) == 0 )
          && ( memcmp( &device, &rhs.device, sizeof( VkDevice ) ) == 0 )
          && ( memcmp( &preferredLargeHeapBlockSize, &rhs.preferredLargeHeapBlockSize, sizeof( VkDeviceSize ) ) == 0 )
          && ( pAllocationCallbacks == rhs.pAllocationCallbacks )
          && ( pDeviceMemoryCallbacks == rhs.pDeviceMemoryCallbacks )
          && ( frameInUseCount == rhs.frameInUseCount )
          && ( pHeapSizeLimit == rhs.pHeapSizeLimit )
          && ( pVulkanFunctions == rhs.pVulkanFunctions )
          && ( pRecordSettings == rhs.pRecordSettings )
          && ( memcmp( &instance, &rhs.instance, sizeof( VkInstance ) ) == 0 )
          && ( vulkanApiVersion == rhs.vulkanApiVersion );
    }

    bool operator!=( AllocatorCreateInfo const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    AllocatorCreateFlags flags = {};
    VkPhysicalDevice physicalDevice = {};
    VkDevice device = {};
    VkDeviceSize preferredLargeHeapBlockSize = {};
    const VkAllocationCallbacks* pAllocationCallbacks = {};
    const DeviceMemoryCallbacks* pDeviceMemoryCallbacks = {};
    uint32_t frameInUseCount = {};
    const VkDeviceSize* pHeapSizeLimit = {};
    const VulkanFunctions* pVulkanFunctions = {};
    const RecordSettings* pRecordSettings = {};
    VkInstance instance = {};
    uint32_t vulkanApiVersion = {};

  };
  static_assert( sizeof( AllocatorCreateInfo ) == sizeof( VmaAllocatorCreateInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<AllocatorCreateInfo>::value, "struct wrapper is not a standard layout!" );

  struct Budget
  {


#if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
    VULKAN_HPP_CONSTEXPR Budget(VkDeviceSize blockBytes_ = {}, VkDeviceSize allocationBytes_ = {}, VkDeviceSize usage_ = {}, VkDeviceSize budget_ = {}) VULKAN_HPP_NOEXCEPT
    : blockBytes( blockBytes_ ), allocationBytes( allocationBytes_ ), usage( usage_ ), budget( budget_ )
    {}

    VULKAN_HPP_CONSTEXPR Budget( Budget const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    Budget( VkBudget const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )

    Budget & operator=( VkBudget const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = *reinterpret_cast<VULKAN_HPP_NAMESPACE::Budget const *>( &rhs );
      return *this;
    }

    Budget & operator=( Budget const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( Budget ) );
      return *this;
    }

    Budget & setBlockBytes( VkDeviceSize blockBytes_ ) VULKAN_HPP_NOEXCEPT
    {
      blockBytes = blockBytes_;
      return *this;
    }

    Budget & setAllocationBytes( VkDeviceSize allocationBytes_ ) VULKAN_HPP_NOEXCEPT
    {
      allocationBytes = allocationBytes_;
      return *this;
    }

    Budget & setUsage( VkDeviceSize usage_ ) VULKAN_HPP_NOEXCEPT
    {
      usage = usage_;
      return *this;
    }

    Budget & setBudget( VkDeviceSize budget_ ) VULKAN_HPP_NOEXCEPT
    {
      budget = budget_;
      return *this;
    }


    operator VmaBudget const&() const VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<const VmaBudget*>( this );
    }

    operator VmaBudget &() VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<VmaBudget*>( this );
    }


#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( Budget const& ) const = default;
#else
    bool operator==( Budget const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return ( memcmp( &blockBytes, &rhs.blockBytes, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &allocationBytes, &rhs.allocationBytes, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &usage, &rhs.usage, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &budget, &rhs.budget, sizeof( VkDeviceSize ) ) == 0 );
    }

    bool operator!=( Budget const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    VkDeviceSize blockBytes = {};
    VkDeviceSize allocationBytes = {};
    VkDeviceSize usage = {};
    VkDeviceSize budget = {};

  };
  static_assert( sizeof( Budget ) == sizeof( VmaBudget ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<Budget>::value, "struct wrapper is not a standard layout!" );

  struct DefragmentationInfo
  {


#if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
    VULKAN_HPP_CONSTEXPR DefragmentationInfo(VkDeviceSize maxBytesToMove_ = {}, uint32_t maxAllocationsToMove_ = {}) VULKAN_HPP_NOEXCEPT
    : maxBytesToMove( maxBytesToMove_ ), maxAllocationsToMove( maxAllocationsToMove_ )
    {}

    VULKAN_HPP_CONSTEXPR DefragmentationInfo( DefragmentationInfo const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    DefragmentationInfo( VkDefragmentationInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )

    DefragmentationInfo & operator=( VkDefragmentationInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = *reinterpret_cast<VULKAN_HPP_NAMESPACE::DefragmentationInfo const *>( &rhs );
      return *this;
    }

    DefragmentationInfo & operator=( DefragmentationInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( DefragmentationInfo ) );
      return *this;
    }

    DefragmentationInfo & setMaxBytesToMove( VkDeviceSize maxBytesToMove_ ) VULKAN_HPP_NOEXCEPT
    {
      maxBytesToMove = maxBytesToMove_;
      return *this;
    }

    DefragmentationInfo & setMaxAllocationsToMove( uint32_t maxAllocationsToMove_ ) VULKAN_HPP_NOEXCEPT
    {
      maxAllocationsToMove = maxAllocationsToMove_;
      return *this;
    }


    operator VmaDefragmentationInfo const&() const VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<const VmaDefragmentationInfo*>( this );
    }

    operator VmaDefragmentationInfo &() VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<VmaDefragmentationInfo*>( this );
    }


#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( DefragmentationInfo const& ) const = default;
#else
    bool operator==( DefragmentationInfo const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return ( memcmp( &maxBytesToMove, &rhs.maxBytesToMove, sizeof( VkDeviceSize ) ) == 0 )
          && ( maxAllocationsToMove == rhs.maxAllocationsToMove );
    }

    bool operator!=( DefragmentationInfo const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    VkDeviceSize maxBytesToMove = {};
    uint32_t maxAllocationsToMove = {};

  };
  static_assert( sizeof( DefragmentationInfo ) == sizeof( VmaDefragmentationInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<DefragmentationInfo>::value, "struct wrapper is not a standard layout!" );

  class Allocation
  {
  public:
    using CType = VkAllocation;

    static VULKAN_HPP_CONST_OR_CONSTEXPR VULKAN_HPP_NAMESPACE::ObjectType objectType = VULKAN_HPP_NAMESPACE::ObjectType::eVmaAllocation;
    static VULKAN_HPP_CONST_OR_CONSTEXPR VULKAN_HPP_NAMESPACE::DebugReportObjectTypeEXT debugReportObjectType = VULKAN_HPP_NAMESPACE::DebugReportObjectTypeEXT::eUnknown;

  public:
    VULKAN_HPP_CONSTEXPR Allocation() VULKAN_HPP_NOEXCEPT
      : m_allocation(VK_NULL_HANDLE)
    {}

    VULKAN_HPP_CONSTEXPR Allocation( std::nullptr_t ) VULKAN_HPP_NOEXCEPT
      : m_allocation(VK_NULL_HANDLE)
    {}

    VULKAN_HPP_TYPESAFE_EXPLICIT Allocation( VkAllocation allocation ) VULKAN_HPP_NOEXCEPT
      : m_allocation( allocation )
    {}

#if defined(VULKAN_HPP_TYPESAFE_CONVERSION)
    Allocation & operator=(VkAllocation allocation) VULKAN_HPP_NOEXCEPT
    {
      m_allocation = allocation;
      return *this;
    }
#endif

    Allocation & operator=( std::nullptr_t ) VULKAN_HPP_NOEXCEPT
    {
      m_allocation = VK_NULL_HANDLE;
      return *this;
    }

#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( Allocation const& ) const = default;
#else
    bool operator==( Allocation const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_allocation == rhs.m_allocation;
    }

    bool operator!=(Allocation const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_allocation != rhs.m_allocation;
    }

    bool operator<(Allocation const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_allocation < rhs.m_allocation;
    }
#endif

    VULKAN_HPP_TYPESAFE_EXPLICIT operator VkAllocation() const VULKAN_HPP_NOEXCEPT
    {
      return m_allocation;
    }

    explicit operator bool() const VULKAN_HPP_NOEXCEPT
    {
      return m_allocation != VK_NULL_HANDLE;
    }

    bool operator!() const VULKAN_HPP_NOEXCEPT
    {
      return m_allocation == VK_NULL_HANDLE;
    }

  private:
    VkAllocation m_allocation;
  };
  static_assert( sizeof( VULKAN_HPP_NAMESPACE::Allocation ) == sizeof( VkAllocation ), "handle and wrapper have different size!" );

  template <>
  struct VULKAN_HPP_DEPRECATED("vk::cpp_type is deprecated. Use vk::CppType instead.") cpp_type<ObjectType::eVmaAllocation>
  {
    using type = VULKAN_HPP_NAMESPACE::Allocation;
  };

  template <>
  struct CppType<VULKAN_HPP_NAMESPACE::ObjectType, VULKAN_HPP_NAMESPACE::ObjectType::eVmaAllocation>
  {
    using Type = VULKAN_HPP_NAMESPACE::Allocation;
  };



  template <>
  struct isVulkanHandleType<VULKAN_HPP_NAMESPACE::Allocation>
  {
    static VULKAN_HPP_CONST_OR_CONSTEXPR bool value = true;
  };

  struct DefragmentationInfo2
  {


#if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
    VULKAN_HPP_CONSTEXPR DefragmentationInfo2(DefragmentationFlags flags_ = {}, uint32_t allocationCount_ = {}, Allocation* pAllocations_ = {}, VkBool32* pAllocationsChanged_ = {}, uint32_t poolCount_ = {}, Pool* pPools_ = {}, VkDeviceSize maxCpuBytesToMove_ = {}, uint32_t maxCpuAllocationsToMove_ = {}, VkDeviceSize maxGpuBytesToMove_ = {}, uint32_t maxGpuAllocationsToMove_ = {}, VkCommandBuffer commandBuffer_ = {}) VULKAN_HPP_NOEXCEPT
    : flags( flags_ ), allocationCount( allocationCount_ ), pAllocations( pAllocations_ ), pAllocationsChanged( pAllocationsChanged_ ), poolCount( poolCount_ ), pPools( pPools_ ), maxCpuBytesToMove( maxCpuBytesToMove_ ), maxCpuAllocationsToMove( maxCpuAllocationsToMove_ ), maxGpuBytesToMove( maxGpuBytesToMove_ ), maxGpuAllocationsToMove( maxGpuAllocationsToMove_ ), commandBuffer( commandBuffer_ )
    {}

    VULKAN_HPP_CONSTEXPR DefragmentationInfo2( DefragmentationInfo2 const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    DefragmentationInfo2( VkDefragmentationInfo2 const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )

    DefragmentationInfo2 & operator=( VkDefragmentationInfo2 const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = *reinterpret_cast<VULKAN_HPP_NAMESPACE::DefragmentationInfo2 const *>( &rhs );
      return *this;
    }

    DefragmentationInfo2 & operator=( DefragmentationInfo2 const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( DefragmentationInfo2 ) );
      return *this;
    }

    DefragmentationInfo2 & setFlags( DefragmentationFlags flags_ ) VULKAN_HPP_NOEXCEPT
    {
      flags = flags_;
      return *this;
    }

    DefragmentationInfo2 & setAllocationCount( uint32_t allocationCount_ ) VULKAN_HPP_NOEXCEPT
    {
      allocationCount = allocationCount_;
      return *this;
    }

    DefragmentationInfo2 & setPAllocations( Allocation* pAllocations_ ) VULKAN_HPP_NOEXCEPT
    {
      pAllocations = pAllocations_;
      return *this;
    }

    DefragmentationInfo2 & setPAllocationsChanged( VkBool32* pAllocationsChanged_ ) VULKAN_HPP_NOEXCEPT
    {
      pAllocationsChanged = pAllocationsChanged_;
      return *this;
    }

    DefragmentationInfo2 & setPoolCount( uint32_t poolCount_ ) VULKAN_HPP_NOEXCEPT
    {
      poolCount = poolCount_;
      return *this;
    }

    DefragmentationInfo2 & setPPools( Pool* pPools_ ) VULKAN_HPP_NOEXCEPT
    {
      pPools = pPools_;
      return *this;
    }

    DefragmentationInfo2 & setMaxCpuBytesToMove( VkDeviceSize maxCpuBytesToMove_ ) VULKAN_HPP_NOEXCEPT
    {
      maxCpuBytesToMove = maxCpuBytesToMove_;
      return *this;
    }

    DefragmentationInfo2 & setMaxCpuAllocationsToMove( uint32_t maxCpuAllocationsToMove_ ) VULKAN_HPP_NOEXCEPT
    {
      maxCpuAllocationsToMove = maxCpuAllocationsToMove_;
      return *this;
    }

    DefragmentationInfo2 & setMaxGpuBytesToMove( VkDeviceSize maxGpuBytesToMove_ ) VULKAN_HPP_NOEXCEPT
    {
      maxGpuBytesToMove = maxGpuBytesToMove_;
      return *this;
    }

    DefragmentationInfo2 & setMaxGpuAllocationsToMove( uint32_t maxGpuAllocationsToMove_ ) VULKAN_HPP_NOEXCEPT
    {
      maxGpuAllocationsToMove = maxGpuAllocationsToMove_;
      return *this;
    }

    DefragmentationInfo2 & setCommandBuffer( VkCommandBuffer commandBuffer_ ) VULKAN_HPP_NOEXCEPT
    {
      commandBuffer = commandBuffer_;
      return *this;
    }


    operator VmaDefragmentationInfo2 const&() const VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<const VmaDefragmentationInfo2*>( this );
    }

    operator VmaDefragmentationInfo2 &() VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<VmaDefragmentationInfo2*>( this );
    }


#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( DefragmentationInfo2 const& ) const = default;
#else
    bool operator==( DefragmentationInfo2 const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return ( flags == rhs.flags )
          && ( allocationCount == rhs.allocationCount )
          && ( pAllocations == rhs.pAllocations )
          && ( pAllocationsChanged == rhs.pAllocationsChanged )
          && ( poolCount == rhs.poolCount )
          && ( pPools == rhs.pPools )
          && ( memcmp( &maxCpuBytesToMove, &rhs.maxCpuBytesToMove, sizeof( VkDeviceSize ) ) == 0 )
          && ( maxCpuAllocationsToMove == rhs.maxCpuAllocationsToMove )
          && ( memcmp( &maxGpuBytesToMove, &rhs.maxGpuBytesToMove, sizeof( VkDeviceSize ) ) == 0 )
          && ( maxGpuAllocationsToMove == rhs.maxGpuAllocationsToMove )
          && ( memcmp( &commandBuffer, &rhs.commandBuffer, sizeof( VkCommandBuffer ) ) == 0 );
    }

    bool operator!=( DefragmentationInfo2 const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    DefragmentationFlags flags = {};
    uint32_t allocationCount = {};
    Allocation* pAllocations = {};
    VkBool32* pAllocationsChanged = {};
    uint32_t poolCount = {};
    Pool* pPools = {};
    VkDeviceSize maxCpuBytesToMove = {};
    uint32_t maxCpuAllocationsToMove = {};
    VkDeviceSize maxGpuBytesToMove = {};
    uint32_t maxGpuAllocationsToMove = {};
    VkCommandBuffer commandBuffer = {};

  };
  static_assert( sizeof( DefragmentationInfo2 ) == sizeof( VmaDefragmentationInfo2 ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<DefragmentationInfo2>::value, "struct wrapper is not a standard layout!" );

  struct DefragmentationStats
  {


#if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
    VULKAN_HPP_CONSTEXPR DefragmentationStats(VkDeviceSize bytesMoved_ = {}, VkDeviceSize bytesFreed_ = {}, uint32_t allocationsMoved_ = {}, uint32_t deviceMemoryBlocksFreed_ = {}) VULKAN_HPP_NOEXCEPT
    : bytesMoved( bytesMoved_ ), bytesFreed( bytesFreed_ ), allocationsMoved( allocationsMoved_ ), deviceMemoryBlocksFreed( deviceMemoryBlocksFreed_ )
    {}

    VULKAN_HPP_CONSTEXPR DefragmentationStats( DefragmentationStats const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    DefragmentationStats( VkDefragmentationStats const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )

    DefragmentationStats & operator=( VkDefragmentationStats const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = *reinterpret_cast<VULKAN_HPP_NAMESPACE::DefragmentationStats const *>( &rhs );
      return *this;
    }

    DefragmentationStats & operator=( DefragmentationStats const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( DefragmentationStats ) );
      return *this;
    }

    DefragmentationStats & setBytesMoved( VkDeviceSize bytesMoved_ ) VULKAN_HPP_NOEXCEPT
    {
      bytesMoved = bytesMoved_;
      return *this;
    }

    DefragmentationStats & setBytesFreed( VkDeviceSize bytesFreed_ ) VULKAN_HPP_NOEXCEPT
    {
      bytesFreed = bytesFreed_;
      return *this;
    }

    DefragmentationStats & setAllocationsMoved( uint32_t allocationsMoved_ ) VULKAN_HPP_NOEXCEPT
    {
      allocationsMoved = allocationsMoved_;
      return *this;
    }

    DefragmentationStats & setDeviceMemoryBlocksFreed( uint32_t deviceMemoryBlocksFreed_ ) VULKAN_HPP_NOEXCEPT
    {
      deviceMemoryBlocksFreed = deviceMemoryBlocksFreed_;
      return *this;
    }


    operator VmaDefragmentationStats const&() const VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<const VmaDefragmentationStats*>( this );
    }

    operator VmaDefragmentationStats &() VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<VmaDefragmentationStats*>( this );
    }


#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( DefragmentationStats const& ) const = default;
#else
    bool operator==( DefragmentationStats const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return ( memcmp( &bytesMoved, &rhs.bytesMoved, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &bytesFreed, &rhs.bytesFreed, sizeof( VkDeviceSize ) ) == 0 )
          && ( allocationsMoved == rhs.allocationsMoved )
          && ( deviceMemoryBlocksFreed == rhs.deviceMemoryBlocksFreed );
    }

    bool operator!=( DefragmentationStats const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    VkDeviceSize bytesMoved = {};
    VkDeviceSize bytesFreed = {};
    uint32_t allocationsMoved = {};
    uint32_t deviceMemoryBlocksFreed = {};

  };
  static_assert( sizeof( DefragmentationStats ) == sizeof( VmaDefragmentationStats ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<DefragmentationStats>::value, "struct wrapper is not a standard layout!" );

  struct PoolCreateInfo
  {


#if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
    VULKAN_HPP_CONSTEXPR PoolCreateInfo(uint32_t memoryTypeIndex_ = {}, PoolCreateFlags flags_ = {}, VkDeviceSize blockSize_ = {}, size_t minBlockCount_ = {}, size_t maxBlockCount_ = {}, uint32_t frameInUseCount_ = {}) VULKAN_HPP_NOEXCEPT
    : memoryTypeIndex( memoryTypeIndex_ ), flags( flags_ ), blockSize( blockSize_ ), minBlockCount( minBlockCount_ ), maxBlockCount( maxBlockCount_ ), frameInUseCount( frameInUseCount_ )
    {}

    VULKAN_HPP_CONSTEXPR PoolCreateInfo( PoolCreateInfo const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    PoolCreateInfo( VkPoolCreateInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )

    PoolCreateInfo & operator=( VkPoolCreateInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = *reinterpret_cast<VULKAN_HPP_NAMESPACE::PoolCreateInfo const *>( &rhs );
      return *this;
    }

    PoolCreateInfo & operator=( PoolCreateInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( PoolCreateInfo ) );
      return *this;
    }

    PoolCreateInfo & setMemoryTypeIndex( uint32_t memoryTypeIndex_ ) VULKAN_HPP_NOEXCEPT
    {
      memoryTypeIndex = memoryTypeIndex_;
      return *this;
    }

    PoolCreateInfo & setFlags( PoolCreateFlags flags_ ) VULKAN_HPP_NOEXCEPT
    {
      flags = flags_;
      return *this;
    }

    PoolCreateInfo & setBlockSize( VkDeviceSize blockSize_ ) VULKAN_HPP_NOEXCEPT
    {
      blockSize = blockSize_;
      return *this;
    }

    PoolCreateInfo & setMinBlockCount( size_t minBlockCount_ ) VULKAN_HPP_NOEXCEPT
    {
      minBlockCount = minBlockCount_;
      return *this;
    }

    PoolCreateInfo & setMaxBlockCount( size_t maxBlockCount_ ) VULKAN_HPP_NOEXCEPT
    {
      maxBlockCount = maxBlockCount_;
      return *this;
    }

    PoolCreateInfo & setFrameInUseCount( uint32_t frameInUseCount_ ) VULKAN_HPP_NOEXCEPT
    {
      frameInUseCount = frameInUseCount_;
      return *this;
    }


    operator VmaPoolCreateInfo const&() const VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<const VmaPoolCreateInfo*>( this );
    }

    operator VmaPoolCreateInfo &() VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<VmaPoolCreateInfo*>( this );
    }


#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( PoolCreateInfo const& ) const = default;
#else
    bool operator==( PoolCreateInfo const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return ( memoryTypeIndex == rhs.memoryTypeIndex )
          && ( flags == rhs.flags )
          && ( memcmp( &blockSize, &rhs.blockSize, sizeof( VkDeviceSize ) ) == 0 )
          && ( minBlockCount == rhs.minBlockCount )
          && ( maxBlockCount == rhs.maxBlockCount )
          && ( frameInUseCount == rhs.frameInUseCount );
    }

    bool operator!=( PoolCreateInfo const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    uint32_t memoryTypeIndex = {};
    PoolCreateFlags flags = {};
    VkDeviceSize blockSize = {};
    size_t minBlockCount = {};
    size_t maxBlockCount = {};
    uint32_t frameInUseCount = {};

  };
  static_assert( sizeof( PoolCreateInfo ) == sizeof( VmaPoolCreateInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<PoolCreateInfo>::value, "struct wrapper is not a standard layout!" );

  struct PoolStats
  {


#if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
    VULKAN_HPP_CONSTEXPR PoolStats(VkDeviceSize size_ = {}, VkDeviceSize unusedSize_ = {}, size_t allocationCount_ = {}, size_t unusedRangeCount_ = {}, VkDeviceSize unusedRangeSizeMax_ = {}, size_t blockCount_ = {}) VULKAN_HPP_NOEXCEPT
    : size( size_ ), unusedSize( unusedSize_ ), allocationCount( allocationCount_ ), unusedRangeCount( unusedRangeCount_ ), unusedRangeSizeMax( unusedRangeSizeMax_ ), blockCount( blockCount_ )
    {}

    VULKAN_HPP_CONSTEXPR PoolStats( PoolStats const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    PoolStats( VkPoolStats const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )

    PoolStats & operator=( VkPoolStats const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = *reinterpret_cast<VULKAN_HPP_NAMESPACE::PoolStats const *>( &rhs );
      return *this;
    }

    PoolStats & operator=( PoolStats const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( PoolStats ) );
      return *this;
    }

    PoolStats & setSize( VkDeviceSize size_ ) VULKAN_HPP_NOEXCEPT
    {
      size = size_;
      return *this;
    }

    PoolStats & setUnusedSize( VkDeviceSize unusedSize_ ) VULKAN_HPP_NOEXCEPT
    {
      unusedSize = unusedSize_;
      return *this;
    }

    PoolStats & setAllocationCount( size_t allocationCount_ ) VULKAN_HPP_NOEXCEPT
    {
      allocationCount = allocationCount_;
      return *this;
    }

    PoolStats & setUnusedRangeCount( size_t unusedRangeCount_ ) VULKAN_HPP_NOEXCEPT
    {
      unusedRangeCount = unusedRangeCount_;
      return *this;
    }

    PoolStats & setUnusedRangeSizeMax( VkDeviceSize unusedRangeSizeMax_ ) VULKAN_HPP_NOEXCEPT
    {
      unusedRangeSizeMax = unusedRangeSizeMax_;
      return *this;
    }

    PoolStats & setBlockCount( size_t blockCount_ ) VULKAN_HPP_NOEXCEPT
    {
      blockCount = blockCount_;
      return *this;
    }


    operator VmaPoolStats const&() const VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<const VmaPoolStats*>( this );
    }

    operator VmaPoolStats &() VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<VmaPoolStats*>( this );
    }


#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( PoolStats const& ) const = default;
#else
    bool operator==( PoolStats const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return ( memcmp( &size, &rhs.size, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &unusedSize, &rhs.unusedSize, sizeof( VkDeviceSize ) ) == 0 )
          && ( allocationCount == rhs.allocationCount )
          && ( unusedRangeCount == rhs.unusedRangeCount )
          && ( memcmp( &unusedRangeSizeMax, &rhs.unusedRangeSizeMax, sizeof( VkDeviceSize ) ) == 0 )
          && ( blockCount == rhs.blockCount );
    }

    bool operator!=( PoolStats const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    VkDeviceSize size = {};
    VkDeviceSize unusedSize = {};
    size_t allocationCount = {};
    size_t unusedRangeCount = {};
    VkDeviceSize unusedRangeSizeMax = {};
    size_t blockCount = {};

  };
  static_assert( sizeof( PoolStats ) == sizeof( VmaPoolStats ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<PoolStats>::value, "struct wrapper is not a standard layout!" );

  struct StatInfo
  {


#if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
    VULKAN_HPP_CONSTEXPR StatInfo(uint32_t blockCount_ = {}, uint32_t allocationCount_ = {}, uint32_t unusedRangeCount_ = {}, VkDeviceSize usedBytes_ = {}, VkDeviceSize unusedBytes_ = {}, VkDeviceSize allocationSizeMin_ = {}, VkDeviceSize allocationSizeAvg_ = {}, VkDeviceSize allocationSizeMax_ = {}, VkDeviceSize unusedRangeSizeMin_ = {}, VkDeviceSize unusedRangeSizeAvg_ = {}, VkDeviceSize unusedRangeSizeMax_ = {}) VULKAN_HPP_NOEXCEPT
    : blockCount( blockCount_ ), allocationCount( allocationCount_ ), unusedRangeCount( unusedRangeCount_ ), usedBytes( usedBytes_ ), unusedBytes( unusedBytes_ ), allocationSizeMin( allocationSizeMin_ ), allocationSizeAvg( allocationSizeAvg_ ), allocationSizeMax( allocationSizeMax_ ), unusedRangeSizeMin( unusedRangeSizeMin_ ), unusedRangeSizeAvg( unusedRangeSizeAvg_ ), unusedRangeSizeMax( unusedRangeSizeMax_ )
    {}

    VULKAN_HPP_CONSTEXPR StatInfo( StatInfo const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    StatInfo( VkStatInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )

    StatInfo & operator=( VkStatInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = *reinterpret_cast<VULKAN_HPP_NAMESPACE::StatInfo const *>( &rhs );
      return *this;
    }

    StatInfo & operator=( StatInfo const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( StatInfo ) );
      return *this;
    }

    StatInfo & setBlockCount( uint32_t blockCount_ ) VULKAN_HPP_NOEXCEPT
    {
      blockCount = blockCount_;
      return *this;
    }

    StatInfo & setAllocationCount( uint32_t allocationCount_ ) VULKAN_HPP_NOEXCEPT
    {
      allocationCount = allocationCount_;
      return *this;
    }

    StatInfo & setUnusedRangeCount( uint32_t unusedRangeCount_ ) VULKAN_HPP_NOEXCEPT
    {
      unusedRangeCount = unusedRangeCount_;
      return *this;
    }

    StatInfo & setUsedBytes( VkDeviceSize usedBytes_ ) VULKAN_HPP_NOEXCEPT
    {
      usedBytes = usedBytes_;
      return *this;
    }

    StatInfo & setUnusedBytes( VkDeviceSize unusedBytes_ ) VULKAN_HPP_NOEXCEPT
    {
      unusedBytes = unusedBytes_;
      return *this;
    }

    StatInfo & setAllocationSizeMin( VkDeviceSize allocationSizeMin_ ) VULKAN_HPP_NOEXCEPT
    {
      allocationSizeMin = allocationSizeMin_;
      return *this;
    }

    StatInfo & setAllocationSizeAvg( VkDeviceSize allocationSizeAvg_ ) VULKAN_HPP_NOEXCEPT
    {
      allocationSizeAvg = allocationSizeAvg_;
      return *this;
    }

    StatInfo & setAllocationSizeMax( VkDeviceSize allocationSizeMax_ ) VULKAN_HPP_NOEXCEPT
    {
      allocationSizeMax = allocationSizeMax_;
      return *this;
    }

    StatInfo & setUnusedRangeSizeMin( VkDeviceSize unusedRangeSizeMin_ ) VULKAN_HPP_NOEXCEPT
    {
      unusedRangeSizeMin = unusedRangeSizeMin_;
      return *this;
    }

    StatInfo & setUnusedRangeSizeAvg( VkDeviceSize unusedRangeSizeAvg_ ) VULKAN_HPP_NOEXCEPT
    {
      unusedRangeSizeAvg = unusedRangeSizeAvg_;
      return *this;
    }

    StatInfo & setUnusedRangeSizeMax( VkDeviceSize unusedRangeSizeMax_ ) VULKAN_HPP_NOEXCEPT
    {
      unusedRangeSizeMax = unusedRangeSizeMax_;
      return *this;
    }


    operator VmaStatInfo const&() const VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<const VmaStatInfo*>( this );
    }

    operator VmaStatInfo &() VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<VmaStatInfo*>( this );
    }


#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( StatInfo const& ) const = default;
#else
    bool operator==( StatInfo const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return ( blockCount == rhs.blockCount )
          && ( allocationCount == rhs.allocationCount )
          && ( unusedRangeCount == rhs.unusedRangeCount )
          && ( memcmp( &usedBytes, &rhs.usedBytes, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &unusedBytes, &rhs.unusedBytes, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &allocationSizeMin, &rhs.allocationSizeMin, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &allocationSizeAvg, &rhs.allocationSizeAvg, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &allocationSizeMax, &rhs.allocationSizeMax, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &unusedRangeSizeMin, &rhs.unusedRangeSizeMin, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &unusedRangeSizeAvg, &rhs.unusedRangeSizeAvg, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &unusedRangeSizeMax, &rhs.unusedRangeSizeMax, sizeof( VkDeviceSize ) ) == 0 );
    }

    bool operator!=( StatInfo const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    uint32_t blockCount = {};
    uint32_t allocationCount = {};
    uint32_t unusedRangeCount = {};
    VkDeviceSize usedBytes = {};
    VkDeviceSize unusedBytes = {};
    VkDeviceSize allocationSizeMin = {};
    VkDeviceSize allocationSizeAvg = {};
    VkDeviceSize allocationSizeMax = {};
    VkDeviceSize unusedRangeSizeMin = {};
    VkDeviceSize unusedRangeSizeAvg = {};
    VkDeviceSize unusedRangeSizeMax = {};

  };
  static_assert( sizeof( StatInfo ) == sizeof( VmaStatInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<StatInfo>::value, "struct wrapper is not a standard layout!" );

  struct Stats
  {


#if !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )
    VULKAN_HPP_CONSTEXPR Stats(StatInfo memoryType_ = {}, StatInfo memoryHeap_ = {}, StatInfo total_ = {}) VULKAN_HPP_NOEXCEPT
    : memoryType( memoryType_ ), memoryHeap( memoryHeap_ ), total( total_ )
    {}

    VULKAN_HPP_CONSTEXPR Stats( Stats const & rhs ) VULKAN_HPP_NOEXCEPT = default;

    Stats( VkStats const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VULKAN_HPP_NO_STRUCT_CONSTRUCTORS )

    Stats & operator=( VkStats const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      *this = *reinterpret_cast<VULKAN_HPP_NAMESPACE::Stats const *>( &rhs );
      return *this;
    }

    Stats & operator=( Stats const & rhs ) VULKAN_HPP_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( Stats ) );
      return *this;
    }

    Stats & setMemoryType( StatInfo const & memoryType_ ) VULKAN_HPP_NOEXCEPT
    {
      memoryType = memoryType_;
      return *this;
    }

    Stats & setMemoryHeap( StatInfo const & memoryHeap_ ) VULKAN_HPP_NOEXCEPT
    {
      memoryHeap = memoryHeap_;
      return *this;
    }

    Stats & setTotal( StatInfo const & total_ ) VULKAN_HPP_NOEXCEPT
    {
      total = total_;
      return *this;
    }


    operator VmaStats const&() const VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<const VmaStats*>( this );
    }

    operator VmaStats &() VULKAN_HPP_NOEXCEPT
    {
      return *reinterpret_cast<VmaStats*>( this );
    }


#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( Stats const& ) const = default;
#else
    bool operator==( Stats const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return ( memoryType == rhs.memoryType )
          && ( memoryHeap == rhs.memoryHeap )
          && ( total == rhs.total );
    }

    bool operator!=( Stats const& rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    StatInfo memoryType = {};
    StatInfo memoryHeap = {};
    StatInfo total = {};

  };
  static_assert( sizeof( Stats ) == sizeof( VmaStats ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<Stats>::value, "struct wrapper is not a standard layout!" );

  class DefragmentationContext
  {
  public:
    using CType = VkDefragmentationContext;

    static VULKAN_HPP_CONST_OR_CONSTEXPR VULKAN_HPP_NAMESPACE::ObjectType objectType = VULKAN_HPP_NAMESPACE::ObjectType::eVmaDefragmentationContext;
    static VULKAN_HPP_CONST_OR_CONSTEXPR VULKAN_HPP_NAMESPACE::DebugReportObjectTypeEXT debugReportObjectType = VULKAN_HPP_NAMESPACE::DebugReportObjectTypeEXT::eUnknown;

  public:
    VULKAN_HPP_CONSTEXPR DefragmentationContext() VULKAN_HPP_NOEXCEPT
      : m_defragmentationContext(VK_NULL_HANDLE)
    {}

    VULKAN_HPP_CONSTEXPR DefragmentationContext( std::nullptr_t ) VULKAN_HPP_NOEXCEPT
      : m_defragmentationContext(VK_NULL_HANDLE)
    {}

    VULKAN_HPP_TYPESAFE_EXPLICIT DefragmentationContext( VkDefragmentationContext defragmentationContext ) VULKAN_HPP_NOEXCEPT
      : m_defragmentationContext( defragmentationContext )
    {}

#if defined(VULKAN_HPP_TYPESAFE_CONVERSION)
    DefragmentationContext & operator=(VkDefragmentationContext defragmentationContext) VULKAN_HPP_NOEXCEPT
    {
      m_defragmentationContext = defragmentationContext;
      return *this;
    }
#endif

    DefragmentationContext & operator=( std::nullptr_t ) VULKAN_HPP_NOEXCEPT
    {
      m_defragmentationContext = VK_NULL_HANDLE;
      return *this;
    }

#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( DefragmentationContext const& ) const = default;
#else
    bool operator==( DefragmentationContext const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_defragmentationContext == rhs.m_defragmentationContext;
    }

    bool operator!=(DefragmentationContext const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_defragmentationContext != rhs.m_defragmentationContext;
    }

    bool operator<(DefragmentationContext const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_defragmentationContext < rhs.m_defragmentationContext;
    }
#endif

    VULKAN_HPP_TYPESAFE_EXPLICIT operator VkDefragmentationContext() const VULKAN_HPP_NOEXCEPT
    {
      return m_defragmentationContext;
    }

    explicit operator bool() const VULKAN_HPP_NOEXCEPT
    {
      return m_defragmentationContext != VK_NULL_HANDLE;
    }

    bool operator!() const VULKAN_HPP_NOEXCEPT
    {
      return m_defragmentationContext == VK_NULL_HANDLE;
    }

  private:
    VkDefragmentationContext m_defragmentationContext;
  };
  static_assert( sizeof( VULKAN_HPP_NAMESPACE::DefragmentationContext ) == sizeof( VkDefragmentationContext ), "handle and wrapper have different size!" );

  template <>
  struct VULKAN_HPP_DEPRECATED("vk::cpp_type is deprecated. Use vk::CppType instead.") cpp_type<ObjectType::eVmaDefragmentationContext>
  {
    using type = VULKAN_HPP_NAMESPACE::DefragmentationContext;
  };

  template <>
  struct CppType<VULKAN_HPP_NAMESPACE::ObjectType, VULKAN_HPP_NAMESPACE::ObjectType::eVmaDefragmentationContext>
  {
    using Type = VULKAN_HPP_NAMESPACE::DefragmentationContext;
  };



  template <>
  struct isVulkanHandleType<VULKAN_HPP_NAMESPACE::DefragmentationContext>
  {
    static VULKAN_HPP_CONST_OR_CONSTEXPR bool value = true;
  };

  class Allocator
  {
  public:
    using CType = VkAllocator;

    static VULKAN_HPP_CONST_OR_CONSTEXPR VULKAN_HPP_NAMESPACE::ObjectType objectType = VULKAN_HPP_NAMESPACE::ObjectType::eVmaAllocator;
    static VULKAN_HPP_CONST_OR_CONSTEXPR VULKAN_HPP_NAMESPACE::DebugReportObjectTypeEXT debugReportObjectType = VULKAN_HPP_NAMESPACE::DebugReportObjectTypeEXT::eUnknown;

  public:
    VULKAN_HPP_CONSTEXPR Allocator() VULKAN_HPP_NOEXCEPT
      : m_allocator(VK_NULL_HANDLE)
    {}

    VULKAN_HPP_CONSTEXPR Allocator( std::nullptr_t ) VULKAN_HPP_NOEXCEPT
      : m_allocator(VK_NULL_HANDLE)
    {}

    VULKAN_HPP_TYPESAFE_EXPLICIT Allocator( VkAllocator allocator ) VULKAN_HPP_NOEXCEPT
      : m_allocator( allocator )
    {}

#if defined(VULKAN_HPP_TYPESAFE_CONVERSION)
    Allocator & operator=(VkAllocator allocator) VULKAN_HPP_NOEXCEPT
    {
      m_allocator = allocator;
      return *this;
    }
#endif

    Allocator & operator=( std::nullptr_t ) VULKAN_HPP_NOEXCEPT
    {
      m_allocator = VK_NULL_HANDLE;
      return *this;
    }

#if defined(VULKAN_HPP_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( Allocator const& ) const = default;
#else
    bool operator==( Allocator const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_allocator == rhs.m_allocator;
    }

    bool operator!=(Allocator const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_allocator != rhs.m_allocator;
    }

    bool operator<(Allocator const & rhs ) const VULKAN_HPP_NOEXCEPT
    {
      return m_allocator < rhs.m_allocator;
    }
#endif






#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkResult bindBufferMemory( Allocation allocation, VkBuffer buffer, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#else
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type bindBufferMemory( Allocation allocation, VkBuffer buffer, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/



#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkResult bindBufferMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer, const void* pNext, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#else
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type bindBufferMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer, const void* pNext, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/



#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkResult bindImageMemory( Allocation allocation, VkImage image, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#else
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type bindImageMemory( Allocation allocation, VkImage image, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/



#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkResult bindImageMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkImage image, const void* pNext, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#else
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type bindImageMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkImage image, const void* pNext, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/



    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void buildStatsString( char** ppStatsString, VkBool32 detailedMap, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD char buildStatsString( VkBool32 detailedMap, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void calculateStats( Stats* pStats, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VULKAN_HPP_NAMESPACE::Stats calculateStats( Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkResult checkCorruption( uint32_t memoryTypeBits, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#else
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type checkCorruption( uint32_t memoryTypeBits, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/



#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkResult checkPoolCorruption( Pool pool, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#else
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type checkPoolCorruption( Pool pool, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/






    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkResult createPool( const PoolCreateInfo* pCreateInfo, Pool* pPool, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Pool>::type createPool( const PoolCreateInfo & createInfo, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#  ifndef VULKAN_HPP_NO_SMART_HANDLE
  template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<UniqueHandle<Pool, Dispatch>>::type createPoolUnique( const PoolCreateInfo & createInfo, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#  endif /*VULKAN_HPP_NO_SMART_HANDLE*/
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/




#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkResult defragmentationEnd( DefragmentationContext context, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#else
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type defragmentationEnd( DefragmentationContext context, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/



    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void destroy( Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void destroyBuffer( VkBuffer buffer, Allocation allocation, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void destroyImage( VkImage image, Allocation allocation, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void destroyPool( Pool pool, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkResult findMemoryTypeIndex( uint32_t memoryTypeBits, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<uint32_t>::type findMemoryTypeIndex( uint32_t memoryTypeBits, const AllocationCreateInfo & allocationCreateInfo, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkResult findMemoryTypeIndexForBufferInfo( const VkBufferCreateInfo* pBufferCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<uint32_t>::type findMemoryTypeIndexForBufferInfo( const VkBufferCreateInfo & bufferCreateInfo, const AllocationCreateInfo & allocationCreateInfo, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkResult findMemoryTypeIndexForImageInfo( const VkImageCreateInfo* pImageCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<uint32_t>::type findMemoryTypeIndexForImageInfo( const VkImageCreateInfo & imageCreateInfo, const AllocationCreateInfo & allocationCreateInfo, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void flushAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void freeMemory( Allocation allocation, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;



    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void freeStatsString( char* pStatsString, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD char freeStatsString( Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void getAllocationInfo( Allocation allocation, AllocationInfo* pAllocationInfo, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VULKAN_HPP_NAMESPACE::AllocationInfo getAllocationInfo( Allocation allocation, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void getBudget( Budget* pBudget, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VULKAN_HPP_NAMESPACE::Budget getBudget( Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void getMemoryProperties( const VkPhysicalDeviceMemoryProperties** ppPhysicalDeviceMemoryProperties, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void getMemoryProperties( const VkPhysicalDeviceMemoryProperties & pPhysicalDeviceMemoryProperties, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void getMemoryTypeProperties( uint32_t memoryTypeIndex, VkMemoryPropertyFlags* pFlags, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkMemoryPropertyFlags getMemoryTypeProperties( uint32_t memoryTypeIndex, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void getPhysicalDeviceProperties( const VkPhysicalDeviceProperties** ppPhysicalDeviceProperties, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void getPhysicalDeviceProperties( const VkPhysicalDeviceProperties & pPhysicalDeviceProperties, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void getPoolName( Pool pool, const char** ppName, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void getPoolName( Pool pool, const char & pName, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void getPoolStats( Pool pool, PoolStats* pPoolStats, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VULKAN_HPP_NAMESPACE::PoolStats getPoolStats( Pool pool, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void invalidateAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void makePoolAllocationsLost( Pool pool, size_t* pLostAllocationCount, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD size_t makePoolAllocationsLost( Pool pool, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkResult mapMemory( Allocation allocation, void** ppData, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void*>::type mapMemory( Allocation allocation, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkResult resizeAllocation( Allocation allocation, VkDeviceSize newSize, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#else
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type resizeAllocation( Allocation allocation, VkDeviceSize newSize, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/



    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void setAllocationUserData( Allocation allocation, void* pUserData, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD void setAllocationUserData( Allocation allocation, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void setCurrentFrameIndex( uint32_t frameIndex, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void setPoolName( Pool pool, const char* pName, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void setPoolName( Pool pool, const char & name, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VkBool32 touchAllocation( Allocation allocation, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    void unmapMemory( Allocation allocation, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) const VULKAN_HPP_NOEXCEPT;

    VULKAN_HPP_TYPESAFE_EXPLICIT operator VkAllocator() const VULKAN_HPP_NOEXCEPT
    {
      return m_allocator;
    }

    explicit operator bool() const VULKAN_HPP_NOEXCEPT
    {
      return m_allocator != VK_NULL_HANDLE;
    }

    bool operator!() const VULKAN_HPP_NOEXCEPT
    {
      return m_allocator == VK_NULL_HANDLE;
    }

  private:
    VkAllocator m_allocator;
  };
  static_assert( sizeof( VULKAN_HPP_NAMESPACE::Allocator ) == sizeof( VkAllocator ), "handle and wrapper have different size!" );

  template <>
  struct VULKAN_HPP_DEPRECATED("vk::cpp_type is deprecated. Use vk::CppType instead.") cpp_type<ObjectType::eVmaAllocator>
  {
    using type = VULKAN_HPP_NAMESPACE::Allocator;
  };

  template <>
  struct CppType<VULKAN_HPP_NAMESPACE::ObjectType, VULKAN_HPP_NAMESPACE::ObjectType::eVmaAllocator>
  {
    using Type = VULKAN_HPP_NAMESPACE::Allocator;
  };



  template <>
  struct isVulkanHandleType<VULKAN_HPP_NAMESPACE::Allocator>
  {
    static VULKAN_HPP_CONST_OR_CONSTEXPR bool value = true;
  };


    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD VkResult createAllocator( const AllocatorCreateInfo* pCreateInfo, Allocator* pAllocator, Dispatch const & d  VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT ) VULKAN_HPP_NOEXCEPT;
#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
    VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Allocator>::type createAllocator( const AllocatorCreateInfo & createInfo, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT );
#  ifndef VULKAN_HPP_NO_SMART_HANDLE
  template <typename Dispatch = VULKAN_HPP_DEFAULT_DISPATCHER_TYPE>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<UniqueHandle<Allocator, Dispatch>>::type createAllocatorUnique( const AllocatorCreateInfo & createInfo, Dispatch const & d VULKAN_HPP_DEFAULT_DISPATCHER_ASSIGNMENT );
#  endif /*VULKAN_HPP_NO_SMART_HANDLE*/
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkResult createAllocator( const AllocatorCreateInfo* pCreateInfo, Allocator* pAllocator, Dispatch const & d  ) VULKAN_HPP_NOEXCEPT
  {
    return d.vmaCreateAllocator( reinterpret_cast<const VmaAllocatorCreateInfo *>( pCreateInfo ), reinterpret_cast< VmaAllocator *>( pAllocator ) );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<Allocator>::type createAllocator( const AllocatorCreateInfo & createInfo, Dispatch const & d )
  {
    Allocator allocator;
    Result result = static_cast<Result>( d.vmaCreateAllocator( reinterpret_cast<const VmaAllocatorCreateInfo *>( &createInfo ), reinterpret_cast<VmaAllocator *>( &allocator ) ) );
    return createResultValue( result, allocator, VULKAN_HPP_NAMESPACE_STRING "::createAllocator" );
  }

#  ifndef VULKAN_HPP_NO_SMART_HANDLE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<UniqueHandle<Allocator, Dispatch>>::type createAllocatorUnique( const AllocatorCreateInfo & createInfo, Dispatch const & d )
  {
    Allocator allocator;
    Result result = static_cast<Result>( d.vmaCreateAllocator( reinterpret_cast<const VmaAllocatorCreateInfo *>( &createInfo ), reinterpret_cast<VmaAllocator *>( &allocator ) ) );
    ObjectDestroy<NoParent, Dispatch> deleter( allocator, d );
    return createResultValue<Allocator, Dispatch>( result, allocator, VULKAN_HPP_NAMESPACE_STRING "::createAllocatorUnique", deleter );
  }
#  endif /*VULKAN_HPP_NO_SMART_HANDLE*/
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/






#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkResult Allocator::bindBufferMemory( Allocation allocation, VkBuffer buffer, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    return d.vmaBindBufferMemory( m_allocator, static_cast<VmaAllocation>( allocation ), buffer );
  }
#else
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<void>::type Allocator::bindBufferMemory( Allocation allocation, VkBuffer buffer, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaBindBufferMemory( m_allocator, static_cast<VmaAllocation>( allocation ), buffer ) );
    return createResultValue( result, VULKAN_HPP_NAMESPACE_STRING "::Allocator::bindBufferMemory" );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/



#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkResult Allocator::bindBufferMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer, const void* pNext, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    return d.vmaBindBufferMemory2( m_allocator, static_cast<VmaAllocation>( allocation ), allocationLocalOffset, buffer, pNext );
  }
#else
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<void>::type Allocator::bindBufferMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer, const void* pNext, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaBindBufferMemory2( m_allocator, static_cast<VmaAllocation>( allocation ), allocationLocalOffset, buffer, pNext ) );
    return createResultValue( result, VULKAN_HPP_NAMESPACE_STRING "::Allocator::bindBufferMemory2" );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/



#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkResult Allocator::bindImageMemory( Allocation allocation, VkImage image, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    return d.vmaBindImageMemory( m_allocator, static_cast<VmaAllocation>( allocation ), image );
  }
#else
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<void>::type Allocator::bindImageMemory( Allocation allocation, VkImage image, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaBindImageMemory( m_allocator, static_cast<VmaAllocation>( allocation ), image ) );
    return createResultValue( result, VULKAN_HPP_NAMESPACE_STRING "::Allocator::bindImageMemory" );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/



#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkResult Allocator::bindImageMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkImage image, const void* pNext, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    return d.vmaBindImageMemory2( m_allocator, static_cast<VmaAllocation>( allocation ), allocationLocalOffset, image, pNext );
  }
#else
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<void>::type Allocator::bindImageMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkImage image, const void* pNext, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaBindImageMemory2( m_allocator, static_cast<VmaAllocation>( allocation ), allocationLocalOffset, image, pNext ) );
    return createResultValue( result, VULKAN_HPP_NAMESPACE_STRING "::Allocator::bindImageMemory2" );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/



  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::buildStatsString( char** ppStatsString, VkBool32 detailedMap, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaBuildStatsString( m_allocator, ppStatsString, detailedMap );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE char Allocator::buildStatsString( VkBool32 detailedMap, Dispatch const & d ) const VULKAN_HPP_NOEXCEPT
  {
    char pStatsString;
    d.vmaBuildStatsString( m_allocator, &pStatsString, detailedMap );
    return pStatsString;
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::calculateStats( Stats* pStats, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaCalculateStats( m_allocator, reinterpret_cast< VmaStats *>( pStats ) );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VULKAN_HPP_NAMESPACE::Stats Allocator::calculateStats( Dispatch const & d ) const VULKAN_HPP_NOEXCEPT
  {
    VULKAN_HPP_NAMESPACE::Stats stats;
    d.vmaCalculateStats( m_allocator, reinterpret_cast<VmaStats *>( &stats ) );
    return stats;
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkResult Allocator::checkCorruption( uint32_t memoryTypeBits, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    return d.vmaCheckCorruption( m_allocator, memoryTypeBits );
  }
#else
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<void>::type Allocator::checkCorruption( uint32_t memoryTypeBits, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaCheckCorruption( m_allocator, memoryTypeBits ) );
    return createResultValue( result, VULKAN_HPP_NAMESPACE_STRING "::Allocator::checkCorruption" );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/



#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkResult Allocator::checkPoolCorruption( Pool pool, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    return d.vmaCheckPoolCorruption( m_allocator, static_cast<VmaPool>( pool ) );
  }
#else
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<void>::type Allocator::checkPoolCorruption( Pool pool, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaCheckPoolCorruption( m_allocator, static_cast<VmaPool>( pool ) ) );
    return createResultValue( result, VULKAN_HPP_NAMESPACE_STRING "::Allocator::checkPoolCorruption" );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/






  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkResult Allocator::createPool( const PoolCreateInfo* pCreateInfo, Pool* pPool, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    return d.vmaCreatePool( m_allocator, reinterpret_cast<const VmaPoolCreateInfo *>( pCreateInfo ), reinterpret_cast< VmaPool *>( pPool ) );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<Pool>::type Allocator::createPool( const PoolCreateInfo & createInfo, Dispatch const & d ) const
  {
    Pool pool;
    Result result = static_cast<Result>( d.vmaCreatePool( m_allocator, reinterpret_cast<const VmaPoolCreateInfo *>( &createInfo ), reinterpret_cast<VmaPool *>( &pool ) ) );
    return createResultValue( result, pool, VULKAN_HPP_NAMESPACE_STRING "::Allocator::createPool" );
  }

#  ifndef VULKAN_HPP_NO_SMART_HANDLE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<UniqueHandle<Pool, Dispatch>>::type Allocator::createPoolUnique( const PoolCreateInfo & createInfo, Dispatch const & d ) const
  {
    Pool pool;
    Result result = static_cast<Result>( d.vmaCreatePool( m_allocator, reinterpret_cast<const VmaPoolCreateInfo *>( &createInfo ), reinterpret_cast<VmaPool *>( &pool ) ) );
    ObjectDestroy<Allocator, Dispatch> deleter( *this, allocator, d );
    return createResultValue<Pool, Dispatch>( result, pool, VULKAN_HPP_NAMESPACE_STRING "::Allocator::createPoolUnique", deleter );
  }
#  endif /*VULKAN_HPP_NO_SMART_HANDLE*/
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/




#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkResult Allocator::defragmentationEnd( DefragmentationContext context, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    return d.vmaDefragmentationEnd( m_allocator, static_cast<VmaDefragmentationContext>( context ) );
  }
#else
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<void>::type Allocator::defragmentationEnd( DefragmentationContext context, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaDefragmentationEnd( m_allocator, static_cast<VmaDefragmentationContext>( context ) ) );
    return createResultValue( result, VULKAN_HPP_NAMESPACE_STRING "::Allocator::defragmentationEnd" );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/



  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::destroy( Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaDestroyAllocator( m_allocator );
  }


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::destroyBuffer( VkBuffer buffer, Allocation allocation, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaDestroyBuffer( m_allocator, buffer, static_cast<VmaAllocation>( allocation ) );
  }


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::destroyImage( VkImage image, Allocation allocation, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaDestroyImage( m_allocator, image, static_cast<VmaAllocation>( allocation ) );
  }


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::destroyPool( Pool pool, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaDestroyPool( m_allocator, static_cast<VmaPool>( pool ) );
  }


  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkResult Allocator::findMemoryTypeIndex( uint32_t memoryTypeBits, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    return d.vmaFindMemoryTypeIndex( m_allocator, memoryTypeBits, reinterpret_cast<const VmaAllocationCreateInfo *>( pAllocationCreateInfo ), pMemoryTypeIndex );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<uint32_t>::type Allocator::findMemoryTypeIndex( uint32_t memoryTypeBits, const AllocationCreateInfo & allocationCreateInfo, Dispatch const & d ) const
  {
    uint32_t memoryTypeIndex;
    Result result = static_cast<Result>( d.vmaFindMemoryTypeIndex( m_allocator, memoryTypeBits, reinterpret_cast<const VmaAllocationCreateInfo *>( &allocationCreateInfo ), &memoryTypeIndex ) );
    return createResultValue( result, memoryTypeIndex, VULKAN_HPP_NAMESPACE_STRING "::Allocator::findMemoryTypeIndex" );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkResult Allocator::findMemoryTypeIndexForBufferInfo( const VkBufferCreateInfo* pBufferCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    return d.vmaFindMemoryTypeIndexForBufferInfo( m_allocator, pBufferCreateInfo, reinterpret_cast<const VmaAllocationCreateInfo *>( pAllocationCreateInfo ), pMemoryTypeIndex );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<uint32_t>::type Allocator::findMemoryTypeIndexForBufferInfo( const VkBufferCreateInfo & bufferCreateInfo, const AllocationCreateInfo & allocationCreateInfo, Dispatch const & d ) const
  {
    uint32_t memoryTypeIndex;
    Result result = static_cast<Result>( d.vmaFindMemoryTypeIndexForBufferInfo( m_allocator, &bufferCreateInfo, reinterpret_cast<const VmaAllocationCreateInfo *>( &allocationCreateInfo ), &memoryTypeIndex ) );
    return createResultValue( result, memoryTypeIndex, VULKAN_HPP_NAMESPACE_STRING "::Allocator::findMemoryTypeIndexForBufferInfo" );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkResult Allocator::findMemoryTypeIndexForImageInfo( const VkImageCreateInfo* pImageCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    return d.vmaFindMemoryTypeIndexForImageInfo( m_allocator, pImageCreateInfo, reinterpret_cast<const VmaAllocationCreateInfo *>( pAllocationCreateInfo ), pMemoryTypeIndex );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<uint32_t>::type Allocator::findMemoryTypeIndexForImageInfo( const VkImageCreateInfo & imageCreateInfo, const AllocationCreateInfo & allocationCreateInfo, Dispatch const & d ) const
  {
    uint32_t memoryTypeIndex;
    Result result = static_cast<Result>( d.vmaFindMemoryTypeIndexForImageInfo( m_allocator, &imageCreateInfo, reinterpret_cast<const VmaAllocationCreateInfo *>( &allocationCreateInfo ), &memoryTypeIndex ) );
    return createResultValue( result, memoryTypeIndex, VULKAN_HPP_NAMESPACE_STRING "::Allocator::findMemoryTypeIndexForImageInfo" );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::flushAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaFlushAllocation( m_allocator, static_cast<VmaAllocation>( allocation ), offset, size );
  }


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::freeMemory( Allocation allocation, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaFreeMemory( m_allocator, static_cast<VmaAllocation>( allocation ) );
  }



  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::freeStatsString( char* pStatsString, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaFreeStatsString( m_allocator, pStatsString );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE char Allocator::freeStatsString( Dispatch const & d ) const VULKAN_HPP_NOEXCEPT
  {
    char statsString;
    d.vmaFreeStatsString( m_allocator, &statsString );
    return statsString;
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::getAllocationInfo( Allocation allocation, AllocationInfo* pAllocationInfo, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaGetAllocationInfo( m_allocator, static_cast<VmaAllocation>( allocation ), reinterpret_cast< VmaAllocationInfo *>( pAllocationInfo ) );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VULKAN_HPP_NAMESPACE::AllocationInfo Allocator::getAllocationInfo( Allocation allocation, Dispatch const & d ) const VULKAN_HPP_NOEXCEPT
  {
    VULKAN_HPP_NAMESPACE::AllocationInfo allocationInfo;
    d.vmaGetAllocationInfo( m_allocator, static_cast<VmaAllocation>( allocation ), reinterpret_cast<VmaAllocationInfo *>( &allocationInfo ) );
    return allocationInfo;
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::getBudget( Budget* pBudget, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaGetBudget( m_allocator, reinterpret_cast< VmaBudget *>( pBudget ) );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VULKAN_HPP_NAMESPACE::Budget Allocator::getBudget( Dispatch const & d ) const VULKAN_HPP_NOEXCEPT
  {
    VULKAN_HPP_NAMESPACE::Budget budget;
    d.vmaGetBudget( m_allocator, reinterpret_cast<VmaBudget *>( &budget ) );
    return budget;
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::getMemoryProperties( const VkPhysicalDeviceMemoryProperties** ppPhysicalDeviceMemoryProperties, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaGetMemoryProperties( m_allocator, ppPhysicalDeviceMemoryProperties );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::getMemoryProperties( const VkPhysicalDeviceMemoryProperties & pPhysicalDeviceMemoryProperties, Dispatch const & d ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaGetMemoryProperties( m_allocator, &pPhysicalDeviceMemoryProperties );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::getMemoryTypeProperties( uint32_t memoryTypeIndex, VkMemoryPropertyFlags* pFlags, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaGetMemoryTypeProperties( m_allocator, memoryTypeIndex, pFlags );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkMemoryPropertyFlags Allocator::getMemoryTypeProperties( uint32_t memoryTypeIndex, Dispatch const & d ) const VULKAN_HPP_NOEXCEPT
  {
    VkMemoryPropertyFlags flags;
    d.vmaGetMemoryTypeProperties( m_allocator, memoryTypeIndex, &flags );
    return flags;
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::getPhysicalDeviceProperties( const VkPhysicalDeviceProperties** ppPhysicalDeviceProperties, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaGetPhysicalDeviceProperties( m_allocator, ppPhysicalDeviceProperties );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::getPhysicalDeviceProperties( const VkPhysicalDeviceProperties & pPhysicalDeviceProperties, Dispatch const & d ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaGetPhysicalDeviceProperties( m_allocator, &pPhysicalDeviceProperties );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::getPoolName( Pool pool, const char** ppName, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaGetPoolName( m_allocator, static_cast<VmaPool>( pool ), ppName );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::getPoolName( Pool pool, const char & pName, Dispatch const & d ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaGetPoolName( m_allocator, static_cast<VmaPool>( pool ), &pName );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::getPoolStats( Pool pool, PoolStats* pPoolStats, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaGetPoolStats( m_allocator, static_cast<VmaPool>( pool ), reinterpret_cast< VmaPoolStats *>( pPoolStats ) );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VULKAN_HPP_NAMESPACE::PoolStats Allocator::getPoolStats( Pool pool, Dispatch const & d ) const VULKAN_HPP_NOEXCEPT
  {
    VULKAN_HPP_NAMESPACE::PoolStats poolStats;
    d.vmaGetPoolStats( m_allocator, static_cast<VmaPool>( pool ), reinterpret_cast<VmaPoolStats *>( &poolStats ) );
    return poolStats;
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::invalidateAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaInvalidateAllocation( m_allocator, static_cast<VmaAllocation>( allocation ), offset, size );
  }


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::makePoolAllocationsLost( Pool pool, size_t* pLostAllocationCount, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaMakePoolAllocationsLost( m_allocator, static_cast<VmaPool>( pool ), pLostAllocationCount );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE size_t Allocator::makePoolAllocationsLost( Pool pool, Dispatch const & d ) const VULKAN_HPP_NOEXCEPT
  {
    size_t lostAllocationCount;
    d.vmaMakePoolAllocationsLost( m_allocator, static_cast<VmaPool>( pool ), &lostAllocationCount );
    return lostAllocationCount;
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkResult Allocator::mapMemory( Allocation allocation, void** ppData, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    return d.vmaMapMemory( m_allocator, static_cast<VmaAllocation>( allocation ), ppData );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<void*>::type Allocator::mapMemory( Allocation allocation, Dispatch const & d ) const
  {
    void* pData;
    Result result = static_cast<Result>( d.vmaMapMemory( m_allocator, static_cast<VmaAllocation>( allocation ), &pData ) );
    return createResultValue( result, pData, VULKAN_HPP_NAMESPACE_STRING "::Allocator::mapMemory" );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


#ifdef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE VkResult Allocator::resizeAllocation( Allocation allocation, VkDeviceSize newSize, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    return d.vmaResizeAllocation( m_allocator, static_cast<VmaAllocation>( allocation ), newSize );
  }
#else
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD_WHEN_NO_EXCEPTIONS VULKAN_HPP_INLINE typename ResultValueType<void>::type Allocator::resizeAllocation( Allocation allocation, VkDeviceSize newSize, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaResizeAllocation( m_allocator, static_cast<VmaAllocation>( allocation ), newSize ) );
    return createResultValue( result, VULKAN_HPP_NAMESPACE_STRING "::Allocator::resizeAllocation" );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/



  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::setAllocationUserData( Allocation allocation, void* pUserData, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaSetAllocationUserData( m_allocator, static_cast<VmaAllocation>( allocation ), pUserData );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_NODISCARD VULKAN_HPP_INLINE void Allocator::setAllocationUserData( Allocation allocation, Dispatch const & d ) const VULKAN_HPP_NOEXCEPT
  {
    void userData;
    d.vmaSetAllocationUserData( m_allocator, static_cast<VmaAllocation>( allocation ), &userData );
    return userData;
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::setCurrentFrameIndex( uint32_t frameIndex, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaSetCurrentFrameIndex( m_allocator, frameIndex );
  }


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::setPoolName( Pool pool, const char* pName, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaSetPoolName( m_allocator, static_cast<VmaPool>( pool ), pName );
  }

#ifndef VULKAN_HPP_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::setPoolName( Pool pool, const char & name, Dispatch const & d ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaSetPoolName( m_allocator, static_cast<VmaPool>( pool ), &name );
  }
#endif /*VULKAN_HPP_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VULKAN_HPP_INLINE VkBool32 Allocator::touchAllocation( Allocation allocation, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    return d.vmaTouchAllocation( m_allocator, static_cast<VmaAllocation>( allocation ) );
  }


  template <typename Dispatch>
  VULKAN_HPP_INLINE void Allocator::unmapMemory( Allocation allocation, Dispatch const & d  ) const VULKAN_HPP_NOEXCEPT
  {
    d.vmaUnmapMemory( m_allocator, static_cast<VmaAllocation>( allocation ) );
  }

#if VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL
  class DynamicLoader
  {
  public:
#  ifdef VULKAN_HPP_NO_EXCEPTIONS
    DynamicLoader( std::string const & vulkanLibraryName = {} ) VULKAN_HPP_NOEXCEPT
#  else
    DynamicLoader( std::string const & vulkanLibraryName = {} )
#  endif
    {
      if ( !vulkanLibraryName.empty() )
      {
#  if defined( __linux__ ) || defined( __APPLE__ )
        m_library = dlopen( vulkanLibraryName.c_str(), RTLD_NOW | RTLD_LOCAL );
#  elif defined( _WIN32 )
        m_library = ::LoadLibraryA( vulkanLibraryName.c_str() );
#  else
#    error unsupported platform
#  endif
      }
      else
      {
#  if defined( __linux__ )
        m_library = dlopen( "libvulkan.so", RTLD_NOW | RTLD_LOCAL );
        if ( m_library == nullptr )
        {
          m_library = dlopen( "libvulkan.so.1", RTLD_NOW | RTLD_LOCAL );
        }
#  elif defined( __APPLE__ )
        m_library = dlopen( "libvulkan.dylib", RTLD_NOW | RTLD_LOCAL );
#  elif defined( _WIN32 )
        m_library = ::LoadLibraryA( "vulkan-1.dll" );
#  else
#    error unsupported platform
#  endif
      }

#ifndef VULKAN_HPP_NO_EXCEPTIONS
      if ( m_library == nullptr )
      {
        // NOTE there should be an InitializationFailedError, but msvc insists on the symbol does not exist within the scope of this function.
        throw std::runtime_error( "Failed to load vulkan library!" );
      }
#endif
    }

    DynamicLoader( DynamicLoader const& ) = delete;

    DynamicLoader( DynamicLoader && other ) VULKAN_HPP_NOEXCEPT : m_library(other.m_library)
    {
      other.m_library = nullptr;
    }

    DynamicLoader &operator=( DynamicLoader const& ) = delete;

    DynamicLoader &operator=( DynamicLoader && other ) VULKAN_HPP_NOEXCEPT
    {
      std::swap(m_library, other.m_library);
      return *this;
    }

    ~DynamicLoader() VULKAN_HPP_NOEXCEPT
    {
      if ( m_library )
      {
#  if defined( __linux__ ) || defined( __APPLE__ )
        dlclose( m_library );
#  elif defined( _WIN32 )
        ::FreeLibrary( m_library );
#  else
#    error unsupported platform
#  endif
      }
    }

    template <typename T>
    T getProcAddress( const char* function ) const VULKAN_HPP_NOEXCEPT
    {
#  if defined( __linux__ ) || defined( __APPLE__ )
      return (T)dlsym( m_library, function );
#  elif defined( _WIN32 )
      return (T)::GetProcAddress( m_library, function );
#  else
#    error unsupported platform
#  endif
    }

    bool success() const VULKAN_HPP_NOEXCEPT { return m_library != nullptr; }

  private:
#  if defined( __linux__ ) || defined( __APPLE__ )
    void * m_library;
#  elif defined( _WIN32 )
    ::HINSTANCE m_library;
#  else
#    error unsupported platform
#  endif
  };
#endif


  class DispatchLoaderDynamic
  {
  public:
    PFN_vmaAllocateMemory vmaAllocateMemory = 0;
    PFN_vmaAllocateMemoryForBuffer vmaAllocateMemoryForBuffer = 0;
    PFN_vmaAllocateMemoryForImage vmaAllocateMemoryForImage = 0;
    PFN_vmaAllocateMemoryPages vmaAllocateMemoryPages = 0;
    PFN_vmaBindBufferMemory vmaBindBufferMemory = 0;
    PFN_vmaBindBufferMemory2 vmaBindBufferMemory2 = 0;
    PFN_vmaBindImageMemory vmaBindImageMemory = 0;
    PFN_vmaBindImageMemory2 vmaBindImageMemory2 = 0;
    PFN_vmaBuildStatsString vmaBuildStatsString = 0;
    PFN_vmaCalculateStats vmaCalculateStats = 0;
    PFN_vmaCheckCorruption vmaCheckCorruption = 0;
    PFN_vmaCheckPoolCorruption vmaCheckPoolCorruption = 0;
    PFN_vmaCreateAllocator vmaCreateAllocator = 0;
    PFN_vmaCreateBuffer vmaCreateBuffer = 0;
    PFN_vmaCreateImage vmaCreateImage = 0;
    PFN_vmaCreateLostAllocation vmaCreateLostAllocation = 0;
    PFN_vmaCreatePool vmaCreatePool = 0;
    PFN_vmaDefragment vmaDefragment = 0;
    PFN_vmaDefragmentationBegin vmaDefragmentationBegin = 0;
    PFN_vmaDefragmentationEnd vmaDefragmentationEnd = 0;
    PFN_vmaDestroyAllocator vmaDestroyAllocator = 0;
    PFN_vmaDestroyBuffer vmaDestroyBuffer = 0;
    PFN_vmaDestroyImage vmaDestroyImage = 0;
    PFN_vmaDestroyPool vmaDestroyPool = 0;
    PFN_vmaFindMemoryTypeIndex vmaFindMemoryTypeIndex = 0;
    PFN_vmaFindMemoryTypeIndexForBufferInfo vmaFindMemoryTypeIndexForBufferInfo = 0;
    PFN_vmaFindMemoryTypeIndexForImageInfo vmaFindMemoryTypeIndexForImageInfo = 0;
    PFN_vmaFlushAllocation vmaFlushAllocation = 0;
    PFN_vmaFreeMemory vmaFreeMemory = 0;
    PFN_vmaFreeMemoryPages vmaFreeMemoryPages = 0;
    PFN_vmaFreeStatsString vmaFreeStatsString = 0;
    PFN_vmaGetAllocationInfo vmaGetAllocationInfo = 0;
    PFN_vmaGetBudget vmaGetBudget = 0;
    PFN_vmaGetMemoryProperties vmaGetMemoryProperties = 0;
    PFN_vmaGetMemoryTypeProperties vmaGetMemoryTypeProperties = 0;
    PFN_vmaGetPhysicalDeviceProperties vmaGetPhysicalDeviceProperties = 0;
    PFN_vmaGetPoolName vmaGetPoolName = 0;
    PFN_vmaGetPoolStats vmaGetPoolStats = 0;
    PFN_vmaInvalidateAllocation vmaInvalidateAllocation = 0;
    PFN_vmaMakePoolAllocationsLost vmaMakePoolAllocationsLost = 0;
    PFN_vmaMapMemory vmaMapMemory = 0;
    PFN_vmaResizeAllocation vmaResizeAllocation = 0;
    PFN_vmaSetAllocationUserData vmaSetAllocationUserData = 0;
    PFN_vmaSetCurrentFrameIndex vmaSetCurrentFrameIndex = 0;
    PFN_vmaSetPoolName vmaSetPoolName = 0;
    PFN_vmaTouchAllocation vmaTouchAllocation = 0;
    PFN_vmaUnmapMemory vmaUnmapMemory = 0;

  public:
    DispatchLoaderDynamic() VULKAN_HPP_NOEXCEPT = default;

#if !defined(VK_NO_PROTOTYPES)
    // This interface is designed to be used for per-device function pointers in combination with a linked vulkan library.
    template <typename DynamicLoader>
    void init(VULKAN_HPP_NAMESPACE::Instance const& instance, VULKAN_HPP_NAMESPACE::Device const& device, DynamicLoader const& dl) VULKAN_HPP_NOEXCEPT
    {
      PFN_vkGetInstanceProcAddr getInstanceProcAddr = dl.template getProcAddress<PFN_vkGetInstanceProcAddr>("vkGetInstanceProcAddr");
      PFN_vkGetDeviceProcAddr getDeviceProcAddr = dl.template getProcAddress<PFN_vkGetDeviceProcAddr>("vkGetDeviceProcAddr");
      init(static_cast<VkInstance>(instance), getInstanceProcAddr, static_cast<VkDevice>(device), device ? getDeviceProcAddr : nullptr);
    }

    // This interface is designed to be used for per-device function pointers in combination with a linked vulkan library.
    template <typename DynamicLoader
#if VULKAN_HPP_ENABLE_DYNAMIC_LOADER_TOOL
      = VULKAN_HPP_NAMESPACE::DynamicLoader
#endif
    >
    void init(VULKAN_HPP_NAMESPACE::Instance const& instance, VULKAN_HPP_NAMESPACE::Device const& device) VULKAN_HPP_NOEXCEPT
    {
      static DynamicLoader dl;
      init(instance, device, dl);
    }
#endif // !defined(VK_NO_PROTOTYPES)

    DispatchLoaderDynamic(PFN_vkGetInstanceProcAddr getInstanceProcAddr) VULKAN_HPP_NOEXCEPT
    {
      init(getInstanceProcAddr);
    }

    void init( PFN_vkGetInstanceProcAddr getInstanceProcAddr ) VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT(getInstanceProcAddr);

      vkGetInstanceProcAddr = getInstanceProcAddr;
      vmaCreateAllocator = PFN_vmaCreateAllocator( vkGetInstanceProcAddr( NULL, "vmaCreateAllocator" ) );
    }

    // This interface does not require a linked vulkan library.
    DispatchLoaderDynamic( VkInstance instance, PFN_vkGetInstanceProcAddr getInstanceProcAddr, VkDevice device = VK_NULL_HANDLE, PFN_vkGetDeviceProcAddr getDeviceProcAddr = nullptr ) VULKAN_HPP_NOEXCEPT
    {
      init( instance, getInstanceProcAddr, device, getDeviceProcAddr );
    }

    // This interface does not require a linked vulkan library.
    void init( VkInstance instance, PFN_vkGetInstanceProcAddr getInstanceProcAddr, VkDevice device = VK_NULL_HANDLE, PFN_vkGetDeviceProcAddr /*getDeviceProcAddr*/ = nullptr ) VULKAN_HPP_NOEXCEPT
    {
      VULKAN_HPP_ASSERT(instance && getInstanceProcAddr);
      vkGetInstanceProcAddr = getInstanceProcAddr;
      init( VULKAN_HPP_NAMESPACE::Instance(instance) );
      if (device) {
        init( VULKAN_HPP_NAMESPACE::Device(device) );
      }
    }

    void init( VULKAN_HPP_NAMESPACE::Instance instanceCpp ) VULKAN_HPP_NOEXCEPT
    {
      VkInstance instance = static_cast<VkInstance>(instanceCpp);
      vmaAllocateMemory = PFN_vmaAllocateMemory( vkGetInstanceProcAddr( instance, "vmaAllocateMemory" ) );
      vmaAllocateMemoryForBuffer = PFN_vmaAllocateMemoryForBuffer( vkGetInstanceProcAddr( instance, "vmaAllocateMemoryForBuffer" ) );
      vmaAllocateMemoryForImage = PFN_vmaAllocateMemoryForImage( vkGetInstanceProcAddr( instance, "vmaAllocateMemoryForImage" ) );
      vmaAllocateMemoryPages = PFN_vmaAllocateMemoryPages( vkGetInstanceProcAddr( instance, "vmaAllocateMemoryPages" ) );
      vmaBindBufferMemory = PFN_vmaBindBufferMemory( vkGetInstanceProcAddr( instance, "vmaBindBufferMemory" ) );
      vmaBindBufferMemory2 = PFN_vmaBindBufferMemory2( vkGetInstanceProcAddr( instance, "vmaBindBufferMemory2" ) );
      vmaBindImageMemory = PFN_vmaBindImageMemory( vkGetInstanceProcAddr( instance, "vmaBindImageMemory" ) );
      vmaBindImageMemory2 = PFN_vmaBindImageMemory2( vkGetInstanceProcAddr( instance, "vmaBindImageMemory2" ) );
      vmaBuildStatsString = PFN_vmaBuildStatsString( vkGetInstanceProcAddr( instance, "vmaBuildStatsString" ) );
      vmaCalculateStats = PFN_vmaCalculateStats( vkGetInstanceProcAddr( instance, "vmaCalculateStats" ) );
      vmaCheckCorruption = PFN_vmaCheckCorruption( vkGetInstanceProcAddr( instance, "vmaCheckCorruption" ) );
      vmaCheckPoolCorruption = PFN_vmaCheckPoolCorruption( vkGetInstanceProcAddr( instance, "vmaCheckPoolCorruption" ) );
      vmaCreateBuffer = PFN_vmaCreateBuffer( vkGetInstanceProcAddr( instance, "vmaCreateBuffer" ) );
      vmaCreateImage = PFN_vmaCreateImage( vkGetInstanceProcAddr( instance, "vmaCreateImage" ) );
      vmaCreateLostAllocation = PFN_vmaCreateLostAllocation( vkGetInstanceProcAddr( instance, "vmaCreateLostAllocation" ) );
      vmaCreatePool = PFN_vmaCreatePool( vkGetInstanceProcAddr( instance, "vmaCreatePool" ) );
      vmaDefragment = PFN_vmaDefragment( vkGetInstanceProcAddr( instance, "vmaDefragment" ) );
      vmaDefragmentationBegin = PFN_vmaDefragmentationBegin( vkGetInstanceProcAddr( instance, "vmaDefragmentationBegin" ) );
      vmaDefragmentationEnd = PFN_vmaDefragmentationEnd( vkGetInstanceProcAddr( instance, "vmaDefragmentationEnd" ) );
      vmaDestroyAllocator = PFN_vmaDestroyAllocator( vkGetInstanceProcAddr( instance, "vmaDestroyAllocator" ) );
      vmaDestroyBuffer = PFN_vmaDestroyBuffer( vkGetInstanceProcAddr( instance, "vmaDestroyBuffer" ) );
      vmaDestroyImage = PFN_vmaDestroyImage( vkGetInstanceProcAddr( instance, "vmaDestroyImage" ) );
      vmaDestroyPool = PFN_vmaDestroyPool( vkGetInstanceProcAddr( instance, "vmaDestroyPool" ) );
      vmaFindMemoryTypeIndex = PFN_vmaFindMemoryTypeIndex( vkGetInstanceProcAddr( instance, "vmaFindMemoryTypeIndex" ) );
      vmaFindMemoryTypeIndexForBufferInfo = PFN_vmaFindMemoryTypeIndexForBufferInfo( vkGetInstanceProcAddr( instance, "vmaFindMemoryTypeIndexForBufferInfo" ) );
      vmaFindMemoryTypeIndexForImageInfo = PFN_vmaFindMemoryTypeIndexForImageInfo( vkGetInstanceProcAddr( instance, "vmaFindMemoryTypeIndexForImageInfo" ) );
      vmaFlushAllocation = PFN_vmaFlushAllocation( vkGetInstanceProcAddr( instance, "vmaFlushAllocation" ) );
      vmaFreeMemory = PFN_vmaFreeMemory( vkGetInstanceProcAddr( instance, "vmaFreeMemory" ) );
      vmaFreeMemoryPages = PFN_vmaFreeMemoryPages( vkGetInstanceProcAddr( instance, "vmaFreeMemoryPages" ) );
      vmaFreeStatsString = PFN_vmaFreeStatsString( vkGetInstanceProcAddr( instance, "vmaFreeStatsString" ) );
      vmaGetAllocationInfo = PFN_vmaGetAllocationInfo( vkGetInstanceProcAddr( instance, "vmaGetAllocationInfo" ) );
      vmaGetBudget = PFN_vmaGetBudget( vkGetInstanceProcAddr( instance, "vmaGetBudget" ) );
      vmaGetMemoryProperties = PFN_vmaGetMemoryProperties( vkGetInstanceProcAddr( instance, "vmaGetMemoryProperties" ) );
      vmaGetMemoryTypeProperties = PFN_vmaGetMemoryTypeProperties( vkGetInstanceProcAddr( instance, "vmaGetMemoryTypeProperties" ) );
      vmaGetPhysicalDeviceProperties = PFN_vmaGetPhysicalDeviceProperties( vkGetInstanceProcAddr( instance, "vmaGetPhysicalDeviceProperties" ) );
      vmaGetPoolName = PFN_vmaGetPoolName( vkGetInstanceProcAddr( instance, "vmaGetPoolName" ) );
      vmaGetPoolStats = PFN_vmaGetPoolStats( vkGetInstanceProcAddr( instance, "vmaGetPoolStats" ) );
      vmaInvalidateAllocation = PFN_vmaInvalidateAllocation( vkGetInstanceProcAddr( instance, "vmaInvalidateAllocation" ) );
      vmaMakePoolAllocationsLost = PFN_vmaMakePoolAllocationsLost( vkGetInstanceProcAddr( instance, "vmaMakePoolAllocationsLost" ) );
      vmaMapMemory = PFN_vmaMapMemory( vkGetInstanceProcAddr( instance, "vmaMapMemory" ) );
      vmaResizeAllocation = PFN_vmaResizeAllocation( vkGetInstanceProcAddr( instance, "vmaResizeAllocation" ) );
      vmaSetAllocationUserData = PFN_vmaSetAllocationUserData( vkGetInstanceProcAddr( instance, "vmaSetAllocationUserData" ) );
      vmaSetCurrentFrameIndex = PFN_vmaSetCurrentFrameIndex( vkGetInstanceProcAddr( instance, "vmaSetCurrentFrameIndex" ) );
      vmaSetPoolName = PFN_vmaSetPoolName( vkGetInstanceProcAddr( instance, "vmaSetPoolName" ) );
      vmaTouchAllocation = PFN_vmaTouchAllocation( vkGetInstanceProcAddr( instance, "vmaTouchAllocation" ) );
      vmaUnmapMemory = PFN_vmaUnmapMemory( vkGetInstanceProcAddr( instance, "vmaUnmapMemory" ) );
    }

    void init( VULKAN_HPP_NAMESPACE::Device deviceCpp ) VULKAN_HPP_NOEXCEPT
    {
      VkDevice device = static_cast<VkDevice>(deviceCpp);
      vmaAllocateMemory = PFN_vmaAllocateMemory( vkGetDeviceProcAddr( device, "vmaAllocateMemory" ) );
      vmaAllocateMemoryForBuffer = PFN_vmaAllocateMemoryForBuffer( vkGetDeviceProcAddr( device, "vmaAllocateMemoryForBuffer" ) );
      vmaAllocateMemoryForImage = PFN_vmaAllocateMemoryForImage( vkGetDeviceProcAddr( device, "vmaAllocateMemoryForImage" ) );
      vmaAllocateMemoryPages = PFN_vmaAllocateMemoryPages( vkGetDeviceProcAddr( device, "vmaAllocateMemoryPages" ) );
      vmaBindBufferMemory = PFN_vmaBindBufferMemory( vkGetDeviceProcAddr( device, "vmaBindBufferMemory" ) );
      vmaBindBufferMemory2 = PFN_vmaBindBufferMemory2( vkGetDeviceProcAddr( device, "vmaBindBufferMemory2" ) );
      vmaBindImageMemory = PFN_vmaBindImageMemory( vkGetDeviceProcAddr( device, "vmaBindImageMemory" ) );
      vmaBindImageMemory2 = PFN_vmaBindImageMemory2( vkGetDeviceProcAddr( device, "vmaBindImageMemory2" ) );
      vmaBuildStatsString = PFN_vmaBuildStatsString( vkGetDeviceProcAddr( device, "vmaBuildStatsString" ) );
      vmaCalculateStats = PFN_vmaCalculateStats( vkGetDeviceProcAddr( device, "vmaCalculateStats" ) );
      vmaCheckCorruption = PFN_vmaCheckCorruption( vkGetDeviceProcAddr( device, "vmaCheckCorruption" ) );
      vmaCheckPoolCorruption = PFN_vmaCheckPoolCorruption( vkGetDeviceProcAddr( device, "vmaCheckPoolCorruption" ) );
      vmaCreateBuffer = PFN_vmaCreateBuffer( vkGetDeviceProcAddr( device, "vmaCreateBuffer" ) );
      vmaCreateImage = PFN_vmaCreateImage( vkGetDeviceProcAddr( device, "vmaCreateImage" ) );
      vmaCreateLostAllocation = PFN_vmaCreateLostAllocation( vkGetDeviceProcAddr( device, "vmaCreateLostAllocation" ) );
      vmaCreatePool = PFN_vmaCreatePool( vkGetDeviceProcAddr( device, "vmaCreatePool" ) );
      vmaDefragment = PFN_vmaDefragment( vkGetDeviceProcAddr( device, "vmaDefragment" ) );
      vmaDefragmentationBegin = PFN_vmaDefragmentationBegin( vkGetDeviceProcAddr( device, "vmaDefragmentationBegin" ) );
      vmaDefragmentationEnd = PFN_vmaDefragmentationEnd( vkGetDeviceProcAddr( device, "vmaDefragmentationEnd" ) );
      vmaDestroyAllocator = PFN_vmaDestroyAllocator( vkGetDeviceProcAddr( device, "vmaDestroyAllocator" ) );
      vmaDestroyBuffer = PFN_vmaDestroyBuffer( vkGetDeviceProcAddr( device, "vmaDestroyBuffer" ) );
      vmaDestroyImage = PFN_vmaDestroyImage( vkGetDeviceProcAddr( device, "vmaDestroyImage" ) );
      vmaDestroyPool = PFN_vmaDestroyPool( vkGetDeviceProcAddr( device, "vmaDestroyPool" ) );
      vmaFindMemoryTypeIndex = PFN_vmaFindMemoryTypeIndex( vkGetDeviceProcAddr( device, "vmaFindMemoryTypeIndex" ) );
      vmaFindMemoryTypeIndexForBufferInfo = PFN_vmaFindMemoryTypeIndexForBufferInfo( vkGetDeviceProcAddr( device, "vmaFindMemoryTypeIndexForBufferInfo" ) );
      vmaFindMemoryTypeIndexForImageInfo = PFN_vmaFindMemoryTypeIndexForImageInfo( vkGetDeviceProcAddr( device, "vmaFindMemoryTypeIndexForImageInfo" ) );
      vmaFlushAllocation = PFN_vmaFlushAllocation( vkGetDeviceProcAddr( device, "vmaFlushAllocation" ) );
      vmaFreeMemory = PFN_vmaFreeMemory( vkGetDeviceProcAddr( device, "vmaFreeMemory" ) );
      vmaFreeMemoryPages = PFN_vmaFreeMemoryPages( vkGetDeviceProcAddr( device, "vmaFreeMemoryPages" ) );
      vmaFreeStatsString = PFN_vmaFreeStatsString( vkGetDeviceProcAddr( device, "vmaFreeStatsString" ) );
      vmaGetAllocationInfo = PFN_vmaGetAllocationInfo( vkGetDeviceProcAddr( device, "vmaGetAllocationInfo" ) );
      vmaGetBudget = PFN_vmaGetBudget( vkGetDeviceProcAddr( device, "vmaGetBudget" ) );
      vmaGetMemoryProperties = PFN_vmaGetMemoryProperties( vkGetDeviceProcAddr( device, "vmaGetMemoryProperties" ) );
      vmaGetMemoryTypeProperties = PFN_vmaGetMemoryTypeProperties( vkGetDeviceProcAddr( device, "vmaGetMemoryTypeProperties" ) );
      vmaGetPhysicalDeviceProperties = PFN_vmaGetPhysicalDeviceProperties( vkGetDeviceProcAddr( device, "vmaGetPhysicalDeviceProperties" ) );
      vmaGetPoolName = PFN_vmaGetPoolName( vkGetDeviceProcAddr( device, "vmaGetPoolName" ) );
      vmaGetPoolStats = PFN_vmaGetPoolStats( vkGetDeviceProcAddr( device, "vmaGetPoolStats" ) );
      vmaInvalidateAllocation = PFN_vmaInvalidateAllocation( vkGetDeviceProcAddr( device, "vmaInvalidateAllocation" ) );
      vmaMakePoolAllocationsLost = PFN_vmaMakePoolAllocationsLost( vkGetDeviceProcAddr( device, "vmaMakePoolAllocationsLost" ) );
      vmaMapMemory = PFN_vmaMapMemory( vkGetDeviceProcAddr( device, "vmaMapMemory" ) );
      vmaResizeAllocation = PFN_vmaResizeAllocation( vkGetDeviceProcAddr( device, "vmaResizeAllocation" ) );
      vmaSetAllocationUserData = PFN_vmaSetAllocationUserData( vkGetDeviceProcAddr( device, "vmaSetAllocationUserData" ) );
      vmaSetCurrentFrameIndex = PFN_vmaSetCurrentFrameIndex( vkGetDeviceProcAddr( device, "vmaSetCurrentFrameIndex" ) );
      vmaSetPoolName = PFN_vmaSetPoolName( vkGetDeviceProcAddr( device, "vmaSetPoolName" ) );
      vmaTouchAllocation = PFN_vmaTouchAllocation( vkGetDeviceProcAddr( device, "vmaTouchAllocation" ) );
      vmaUnmapMemory = PFN_vmaUnmapMemory( vkGetDeviceProcAddr( device, "vmaUnmapMemory" ) );
    }
  };

} // namespace VULKAN_HPP_NAMESPACE

namespace std
{

  template <> struct hash<VULKAN_HPP_NAMESPACE::Allocation>
  {
    std::size_t operator()(VULKAN_HPP_NAMESPACE::Allocation const& allocation) const VULKAN_HPP_NOEXCEPT
    {
      return std::hash<VkAllocation>{}(static_cast<VkAllocation>(allocation));
    }
  };

  template <> struct hash<VULKAN_HPP_NAMESPACE::Allocator>
  {
    std::size_t operator()(VULKAN_HPP_NAMESPACE::Allocator const& allocator) const VULKAN_HPP_NOEXCEPT
    {
      return std::hash<VkAllocator>{}(static_cast<VkAllocator>(allocator));
    }
  };

  template <> struct hash<VULKAN_HPP_NAMESPACE::DefragmentationContext>
  {
    std::size_t operator()(VULKAN_HPP_NAMESPACE::DefragmentationContext const& defragmentationContext) const VULKAN_HPP_NOEXCEPT
    {
      return std::hash<VkDefragmentationContext>{}(static_cast<VkDefragmentationContext>(defragmentationContext));
    }
  };

  template <> struct hash<VULKAN_HPP_NAMESPACE::Pool>
  {
    std::size_t operator()(VULKAN_HPP_NAMESPACE::Pool const& pool) const VULKAN_HPP_NOEXCEPT
    {
      return std::hash<VkPool>{}(static_cast<VkPool>(pool));
    }
  };
}
#endif
