// Copyright (c) 2021 Cvelth (cvelth.mail@gmail.com)
// SPDX-License-Identifier: Unlicense.
// 
// DO NOT MODIFY MANUALLY!
// This file was generated using [generator](https://github.com/Cvelth/vkma_xml_generator).
// Generated files are licensed under [The Unlicense](https://unlicense.org).
// The generator itself is licensed under [MIT License](https://www.mit.edu/~amini/LICENSE.md).

// This header is generated from the Khronos Vulkan XML API Registry.

#ifndef VKMA
#define VKMA

#if defined( _MSVC_LANG )
#  define VKMA_CPLUSPLUS _MSVC_LANG
#else
#  define VKMA_CPLUSPLUS __cplusplus
#endif

#if 201703L < VKMA_CPLUSPLUS
#  define VKMA_CPP_VERSION 20
#elif 201402L < VKMA_CPLUSPLUS
#  define VKMA_CPP_VERSION 17
#elif 201103L < VKMA_CPLUSPLUS
#  define VKMA_CPP_VERSION 14
#elif 199711L < VKMA_CPLUSPLUS
#  define VKMA_CPP_VERSION 11
#else
#  error "vkma.hpp needs at least c++ standard version 11"
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
#include <vk_mem_alloc.h>

#if 17 <= VKMA_CPP_VERSION
#include <string_view>
#endif

#if defined(VKMA_DISABLE_ENHANCED_MODE)
# if !defined(VKMA_NO_SMART_HANDLE)
#  define VKMA_NO_SMART_HANDLE
# endif
#else
# include <memory>
# include <vector>
#endif

#if !defined(VKMA_ASSERT)
# include <cassert>
# define VKMA_ASSERT   assert
#endif

#if !defined(VKMA_ASSERT_ON_RESULT)
# define VKMA_ASSERT_ON_RESULT VKMA_ASSERT
#endif

#if !defined(VKMA_ENABLE_DYNAMIC_LOADER_TOOL)
# define VKMA_ENABLE_DYNAMIC_LOADER_TOOL 1
#endif

#if VKMA_ENABLE_DYNAMIC_LOADER_TOOL == 1
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

#if ( 201711 <= __cpp_impl_three_way_comparison ) && __has_include( <compare> ) && !defined( VKMA_NO_SPACESHIP_OPERATOR )
# define VKMA_HAS_SPACESHIP_OPERATOR
#endif
#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
# include <compare>
#endif


// 32-bit vulkan is not typesafe for handles, so don't allow copy constructors on this platform by default.
// To enable this feature on 32-bit platforms please define VKMA_TYPESAFE_CONVERSION

# if !defined( VKMA_TYPESAFE_CONVERSION )
#  define VKMA_TYPESAFE_CONVERSION
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
// with the VKMA_NAMESPACE::MemoryBarrier struct.
#if defined(MemoryBarrier)
  #undef MemoryBarrier
#endif

#if !defined(VKMA_HAS_UNRESTRICTED_UNIONS)
# if defined(__clang__)
#  if __has_feature(cxx_unrestricted_unions)
#   define VKMA_HAS_UNRESTRICTED_UNIONS
#  endif
# elif defined(__GNUC__)
#  define GCC_VERSION (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#  if 40600 <= GCC_VERSION
#   define VKMA_HAS_UNRESTRICTED_UNIONS
#  endif
# elif defined(_MSC_VER)
#  if 1900 <= _MSC_VER
#   define VKMA_HAS_UNRESTRICTED_UNIONS
#  endif
# endif
#endif

#if !defined(VKMA_INLINE)
# if defined(__clang__)
#  if __has_attribute(always_inline)
#   define VKMA_INLINE __attribute__((always_inline)) __inline__
#  else
#   define VKMA_INLINE inline
#  endif
# elif defined(__GNUC__)
#  define VKMA_INLINE __attribute__((always_inline)) __inline__
# elif defined(_MSC_VER)
#  define VKMA_INLINE inline
# else
#  define VKMA_INLINE inline
# endif
#endif

#if defined(VKMA_TYPESAFE_CONVERSION)
# define VKMA_TYPESAFE_EXPLICIT
#else
# define VKMA_TYPESAFE_EXPLICIT explicit
#endif

#if defined(__cpp_constexpr)
# define VKMA_CONSTEXPR constexpr
# if __cpp_constexpr >= 201304
#  define VKMA_CONSTEXPR_14  constexpr
# else
#  define VKMA_CONSTEXPR_14
# endif
# define VKMA_CONST_OR_CONSTEXPR  constexpr
#else
# define VKMA_CONSTEXPR
# define VKMA_CONSTEXPR_14
# define VKMA_CONST_OR_CONSTEXPR  const
#endif

#if !defined(VKMA_NOEXCEPT)
# if defined(_MSC_VER) && (_MSC_VER <= 1800)
#  define VKMA_NOEXCEPT
# else
#  define VKMA_NOEXCEPT noexcept
#  define VKMA_HAS_NOEXCEPT 1
#  if defined(VKMA_NO_EXCEPTIONS)
#    define VKMA_NOEXCEPT_WHEN_NO_EXCEPTIONS noexcept
#  else
#    define VKMA_NOEXCEPT_WHEN_NO_EXCEPTIONS
#  endif
# endif
#endif

#if 14 <= VKMA_CPP_VERSION
#  define VKMA_DEPRECATED( msg ) [[deprecated( msg )]]
#else
#  define VKMA_DEPRECATED( msg )
#endif

#if ( 17 <= VKMA_CPP_VERSION ) && !defined( VKMA_NO_NODISCARD_WARNINGS )
#  define VKMA_NODISCARD [[nodiscard]]
#  if defined(VKMA_NO_EXCEPTIONS)
#    define VKMA_NODISCARD_WHEN_NO_EXCEPTIONS [[nodiscard]]
#  else
#    define VKMA_NODISCARD_WHEN_NO_EXCEPTIONS
#  endif
#else
#  define VKMA_NODISCARD
#  define VKMA_NODISCARD_WHEN_NO_EXCEPTIONS
#endif

#if !defined(VKMA_NAMESPACE)
#define VKMA_NAMESPACE vkma
#endif

#define VKMA_STRINGIFY2(text) #text
#define VKMA_STRINGIFY(text) VKMA_STRINGIFY2(text)
#define VKMA_NAMESPACE_STRING VKMA_STRINGIFY(VKMA_NAMESPACE)

namespace VKMA_NAMESPACE
{

#if !defined(VKMA_DISABLE_ENHANCED_MODE)
  template <typename T>
  class ArrayProxy
  {
  public:
    VKMA_CONSTEXPR ArrayProxy() VKMA_NOEXCEPT
      : m_count( 0 )
      , m_ptr( nullptr )
    {}

    VKMA_CONSTEXPR ArrayProxy( std::nullptr_t ) VKMA_NOEXCEPT
      : m_count( 0 )
      , m_ptr( nullptr )
    {}

    ArrayProxy( T & value ) VKMA_NOEXCEPT
      : m_count( 1 )
      , m_ptr( &value )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( typename std::remove_const<T>::type & value ) VKMA_NOEXCEPT
      : m_count( 1 )
      , m_ptr( &value )
    {}

    ArrayProxy( uint32_t count, T * ptr ) VKMA_NOEXCEPT
      : m_count( count )
      , m_ptr( ptr )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( uint32_t count, typename std::remove_const<T>::type * ptr ) VKMA_NOEXCEPT
      : m_count( count )
      , m_ptr( ptr )
    {}

    ArrayProxy( std::initializer_list<T> const & list ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( std::initializer_list<typename std::remove_const<T>::type> const & list ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    ArrayProxy( std::initializer_list<T> & list ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( std::initializer_list<typename std::remove_const<T>::type> & list ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    template <size_t N>
    ArrayProxy( std::array<T, N> const & data ) VKMA_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <size_t N, typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( std::array<typename std::remove_const<T>::type, N> const & data ) VKMA_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <size_t N>
    ArrayProxy( std::array<T, N> & data ) VKMA_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <size_t N, typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( std::array<typename std::remove_const<T>::type, N> & data ) VKMA_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxy( std::vector<T, Allocator> const & data ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>,
              typename B      = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( std::vector<typename std::remove_const<T>::type, Allocator> const & data ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxy( std::vector<T, Allocator> & data ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>,
              typename B      = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxy( std::vector<typename std::remove_const<T>::type, Allocator> & data ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    const T * begin() const VKMA_NOEXCEPT
    {
      return m_ptr;
    }

    const T * end() const VKMA_NOEXCEPT
    {
      return m_ptr + m_count;
    }

    const T & front() const VKMA_NOEXCEPT
    {
      VKMA_ASSERT( m_count && m_ptr );
      return *m_ptr;
    }

    const T & back() const VKMA_NOEXCEPT
    {
      VKMA_ASSERT( m_count && m_ptr );
      return *( m_ptr + m_count - 1 );
    }

    bool empty() const VKMA_NOEXCEPT
    {
      return ( m_count == 0 );
    }

    uint32_t size() const VKMA_NOEXCEPT
    {
      return m_count;
    }

    T * data() const VKMA_NOEXCEPT
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
    VKMA_CONSTEXPR ArrayProxyNoTemporaries() VKMA_NOEXCEPT
      : m_count( 0 )
      , m_ptr( nullptr )
    {}

    VKMA_CONSTEXPR ArrayProxyNoTemporaries( std::nullptr_t ) VKMA_NOEXCEPT
      : m_count( 0 )
      , m_ptr( nullptr )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( typename std::remove_const<T>::type & value ) VKMA_NOEXCEPT
      : m_count( 1 )
      , m_ptr( &value )
    {}

    ArrayProxyNoTemporaries( uint32_t count, T * ptr ) VKMA_NOEXCEPT
      : m_count( count )
      , m_ptr( ptr )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( uint32_t count, typename std::remove_const<T>::type * ptr ) VKMA_NOEXCEPT
      : m_count( count )
      , m_ptr( ptr )
    {}

    ArrayProxyNoTemporaries( std::initializer_list<T> const & list ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::initializer_list<typename std::remove_const<T>::type> const & list ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    ArrayProxyNoTemporaries( std::initializer_list<T> & list ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    template <typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::initializer_list<typename std::remove_const<T>::type> & list ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( list.size() ) )
      , m_ptr( list.begin() )
    {}

    ArrayProxyNoTemporaries( std::initializer_list<T> const && list ) VKMA_NOEXCEPT = delete;
    ArrayProxyNoTemporaries( std::initializer_list<T> && list ) VKMA_NOEXCEPT       = delete;

    template <size_t N>
    ArrayProxyNoTemporaries( std::array<T, N> const & data ) VKMA_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <size_t N, typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::array<typename std::remove_const<T>::type, N> const & data ) VKMA_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <size_t N>
    ArrayProxyNoTemporaries( std::array<T, N> & data ) VKMA_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <size_t N, typename B = T, typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::array<typename std::remove_const<T>::type, N> & data ) VKMA_NOEXCEPT
      : m_count( N )
      , m_ptr( data.data() )
    {}

    template <size_t N>
    ArrayProxyNoTemporaries( std::array<T, N> const && data ) VKMA_NOEXCEPT = delete;
    template <size_t N>
    ArrayProxyNoTemporaries( std::array<T, N> && data ) VKMA_NOEXCEPT       = delete;

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxyNoTemporaries( std::vector<T, Allocator> const & data ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>,
              typename B      = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::vector<typename std::remove_const<T>::type, Allocator> const & data ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>>
    ArrayProxyNoTemporaries( std::vector<T, Allocator> & data ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    template <class Allocator = std::allocator<typename std::remove_const<T>::type>,
              typename B      = T,
              typename std::enable_if<std::is_const<B>::value, int>::type = 0>
    ArrayProxyNoTemporaries( std::vector<typename std::remove_const<T>::type, Allocator> & data ) VKMA_NOEXCEPT
      : m_count( static_cast<uint32_t>( data.size() ) )
      , m_ptr( data.data() )
    {}

    ArrayProxyNoTemporaries( std::vector<T> const && data ) VKMA_NOEXCEPT = delete;
    ArrayProxyNoTemporaries( std::vector<T> && data ) VKMA_NOEXCEPT       = delete;

    const T * begin() const VKMA_NOEXCEPT
    {
      return m_ptr;
    }

    const T * end() const VKMA_NOEXCEPT
    {
      return m_ptr + m_count;
    }

    const T & front() const VKMA_NOEXCEPT
    {
      VKMA_ASSERT( m_count && m_ptr );
      return *m_ptr;
    }

    const T & back() const VKMA_NOEXCEPT
    {
      VKMA_ASSERT( m_count && m_ptr );
      return *( m_ptr + m_count - 1 );
    }

    bool empty() const VKMA_NOEXCEPT
    {
      return ( m_count == 0 );
    }

    uint32_t size() const VKMA_NOEXCEPT
    {
      return m_count;
    }

    T * data() const VKMA_NOEXCEPT
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
    VKMA_CONSTEXPR ArrayWrapper1D() VKMA_NOEXCEPT
      : std::array<T, N>()
    {}

    VKMA_CONSTEXPR ArrayWrapper1D(std::array<T,N> const& data) VKMA_NOEXCEPT
      : std::array<T, N>(data)
    {}

#if defined(_WIN32) && !defined(_WIN64)
    VKMA_CONSTEXPR T const& operator[](int index) const VKMA_NOEXCEPT
    {
      return std::array<T, N>::operator[](index);
    }

    T & operator[](int index) VKMA_NOEXCEPT
    {
      return std::array<T, N>::operator[](index);
    }
#endif

    operator T const* () const VKMA_NOEXCEPT
    {
      return this->data();
    }

    operator T * () VKMA_NOEXCEPT
    {
      return this->data();
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    operator std::string() const
    {
      return std::string( this->data() );
    }

#if 17 <= VKMA_CPP_VERSION
    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    operator std::string_view() const
    {
      return std::string_view( this->data() );
    }
#endif

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator<( ArrayWrapper1D<char, N> const & rhs ) const VKMA_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) < *static_cast<std::array<char, N> const *>( &rhs );
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator<=( ArrayWrapper1D<char, N> const & rhs ) const VKMA_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) <= *static_cast<std::array<char, N> const *>( &rhs );
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator>( ArrayWrapper1D<char, N> const & rhs ) const VKMA_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) > *static_cast<std::array<char, N> const *>( &rhs );
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator>=( ArrayWrapper1D<char, N> const & rhs ) const VKMA_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) >= *static_cast<std::array<char, N> const *>( &rhs );
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator==( ArrayWrapper1D<char, N> const & rhs ) const VKMA_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) == *static_cast<std::array<char, N> const *>( &rhs );
    }

    template <typename B = T, typename std::enable_if<std::is_same<B, char>::value, int>::type = 0>
    bool operator!=( ArrayWrapper1D<char, N> const & rhs ) const VKMA_NOEXCEPT
    {
      return *static_cast<std::array<char, N> const *>( this ) != *static_cast<std::array<char, N> const *>( &rhs );
    }
  };

  // specialization of relational operators between std::string and arrays of chars
  template <size_t N>
  bool operator<(std::string const& lhs, ArrayWrapper1D<char, N> const& rhs) VKMA_NOEXCEPT
  {
    return lhs < rhs.data();
  }

  template <size_t N>
  bool operator<=(std::string const& lhs, ArrayWrapper1D<char, N> const& rhs) VKMA_NOEXCEPT
  {
    return lhs <= rhs.data();
  }

  template <size_t N>
  bool operator>(std::string const& lhs, ArrayWrapper1D<char, N> const& rhs) VKMA_NOEXCEPT
  {
    return lhs > rhs.data();
  }

  template <size_t N>
  bool operator>=(std::string const& lhs, ArrayWrapper1D<char, N> const& rhs) VKMA_NOEXCEPT
  {
    return lhs >= rhs.data();
  }

  template <size_t N>
  bool operator==(std::string const& lhs, ArrayWrapper1D<char, N> const& rhs) VKMA_NOEXCEPT
  {
    return lhs == rhs.data();
  }

  template <size_t N>
  bool operator!=(std::string const& lhs, ArrayWrapper1D<char, N> const& rhs) VKMA_NOEXCEPT
  {
    return lhs != rhs.data();
  }

  template <typename T, size_t N, size_t M>
  class ArrayWrapper2D : public std::array<ArrayWrapper1D<T,M>,N>
  {
  public:
    VKMA_CONSTEXPR ArrayWrapper2D() VKMA_NOEXCEPT
      : std::array<ArrayWrapper1D<T,M>, N>()
    {}

    VKMA_CONSTEXPR ArrayWrapper2D(std::array<std::array<T,M>,N> const& data) VKMA_NOEXCEPT
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
    VKMA_CONSTEXPR Flags() VKMA_NOEXCEPT
      : m_mask(0)
    {}

    VKMA_CONSTEXPR Flags(BitType bit) VKMA_NOEXCEPT
      : m_mask(static_cast<MaskType>(bit))
    {}

    VKMA_CONSTEXPR Flags(Flags<BitType> const& rhs) VKMA_NOEXCEPT = default;

    VKMA_CONSTEXPR explicit Flags(MaskType flags) VKMA_NOEXCEPT
      : m_mask(flags)
    {}

    // relational operators
#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>(Flags<BitType> const&) const = default;
#else
    VKMA_CONSTEXPR bool operator<(Flags<BitType> const& rhs) const VKMA_NOEXCEPT
    {
      return m_mask < rhs.m_mask;
    }

    VKMA_CONSTEXPR bool operator<=(Flags<BitType> const& rhs) const VKMA_NOEXCEPT
    {
      return m_mask <= rhs.m_mask;
    }

    VKMA_CONSTEXPR bool operator>(Flags<BitType> const& rhs) const VKMA_NOEXCEPT
    {
      return m_mask > rhs.m_mask;
    }

    VKMA_CONSTEXPR bool operator>=(Flags<BitType> const& rhs) const VKMA_NOEXCEPT
    {
      return m_mask >= rhs.m_mask;
    }

    VKMA_CONSTEXPR bool operator==(Flags<BitType> const& rhs) const VKMA_NOEXCEPT
    {
      return m_mask == rhs.m_mask;
    }

    VKMA_CONSTEXPR bool operator!=(Flags<BitType> const& rhs) const VKMA_NOEXCEPT
    {
      return m_mask != rhs.m_mask;
    }
#endif

    // logical operator
    VKMA_CONSTEXPR bool operator!() const VKMA_NOEXCEPT
    {
      return !m_mask;
    }

    // bitwise operators
    VKMA_CONSTEXPR Flags<BitType> operator&(Flags<BitType> const& rhs) const VKMA_NOEXCEPT
    {
      return Flags<BitType>(m_mask & rhs.m_mask);
    }

    VKMA_CONSTEXPR Flags<BitType> operator|(Flags<BitType> const& rhs) const VKMA_NOEXCEPT
    {
      return Flags<BitType>(m_mask | rhs.m_mask);
    }

    VKMA_CONSTEXPR Flags<BitType> operator^(Flags<BitType> const& rhs) const VKMA_NOEXCEPT
    {
      return Flags<BitType>(m_mask ^ rhs.m_mask);
    }

    VKMA_CONSTEXPR Flags<BitType> operator~() const VKMA_NOEXCEPT
    {
      return Flags<BitType>(m_mask ^ FlagTraits<BitType>::allFlags);
    }

    // assignment operators
    VKMA_CONSTEXPR_14 Flags<BitType> & operator=(Flags<BitType> const& rhs) VKMA_NOEXCEPT = default;

    VKMA_CONSTEXPR_14 Flags<BitType> & operator|=(Flags<BitType> const& rhs) VKMA_NOEXCEPT
    {
      m_mask |= rhs.m_mask;
      return *this;
    }

    VKMA_CONSTEXPR_14 Flags<BitType> & operator&=(Flags<BitType> const& rhs) VKMA_NOEXCEPT
    {
      m_mask &= rhs.m_mask;
      return *this;
    }

    VKMA_CONSTEXPR_14 Flags<BitType> & operator^=(Flags<BitType> const& rhs) VKMA_NOEXCEPT
    {
      m_mask ^= rhs.m_mask;
      return *this;
    }

    // cast operators
    explicit VKMA_CONSTEXPR operator bool() const VKMA_NOEXCEPT
    {
      return !!m_mask;
    }

    explicit VKMA_CONSTEXPR operator MaskType() const VKMA_NOEXCEPT
    {
        return m_mask;
    }

  private:
    MaskType  m_mask;
  };

#if !defined(VKMA_HAS_SPACESHIP_OPERATOR)
  // relational operators only needed for pre C++20
  template <typename BitType>
  VKMA_CONSTEXPR bool operator<(BitType bit, Flags<BitType> const& flags) VKMA_NOEXCEPT
  {
    return flags.operator>( bit );
  }

  template <typename BitType>
  VKMA_CONSTEXPR bool operator<=(BitType bit, Flags<BitType> const& flags) VKMA_NOEXCEPT
  {
    return flags.operator>=( bit );
  }

  template <typename BitType>
  VKMA_CONSTEXPR bool operator>(BitType bit, Flags<BitType> const& flags) VKMA_NOEXCEPT
  {
    return flags.operator<( bit );
  }

  template <typename BitType>
  VKMA_CONSTEXPR bool operator>=(BitType bit, Flags<BitType> const& flags) VKMA_NOEXCEPT
  {
    return flags.operator<=(bit);
  }

  template <typename BitType>
  VKMA_CONSTEXPR bool operator==(BitType bit, Flags<BitType> const& flags) VKMA_NOEXCEPT
  {
    return flags.operator==( bit );
  }

  template <typename BitType>
  VKMA_CONSTEXPR bool operator!=(BitType bit, Flags<BitType> const& flags) VKMA_NOEXCEPT
  {
    return flags.operator!=( bit );
  }
#endif

  // bitwise operators
  template <typename BitType>
  VKMA_CONSTEXPR Flags<BitType> operator&(BitType bit, Flags<BitType> const& flags) VKMA_NOEXCEPT
  {
    return flags.operator&( bit );
  }

  template <typename BitType>
  VKMA_CONSTEXPR Flags<BitType> operator|(BitType bit, Flags<BitType> const& flags) VKMA_NOEXCEPT
  {
    return flags.operator|( bit );
  }

  template <typename BitType>
  VKMA_CONSTEXPR Flags<BitType> operator^(BitType bit, Flags<BitType> const& flags) VKMA_NOEXCEPT
  {
    return flags.operator^( bit );
  }

  template <typename RefType>
  class Optional
  {
  public:
    Optional(RefType & reference) VKMA_NOEXCEPT { m_ptr = &reference; }
    Optional(RefType * ptr) VKMA_NOEXCEPT { m_ptr = ptr; }
    Optional(std::nullptr_t) VKMA_NOEXCEPT { m_ptr = nullptr; }

    operator RefType*() const VKMA_NOEXCEPT { return m_ptr; }
    RefType const* operator->() const VKMA_NOEXCEPT { return m_ptr; }
    explicit operator bool() const VKMA_NOEXCEPT { return !!m_ptr; }

  private:
    RefType *m_ptr;
  };

#if !defined(VKMA_NO_SMART_HANDLE)
  template <typename Type> class UniqueHandleTraits;

  template <typename Type>
  class UniqueHandle : public UniqueHandleTraits<Type>::deleter
  {
  private:
    using Deleter = typename UniqueHandleTraits<Type>::deleter;

  public:
    using element_type = Type;

    UniqueHandle()
      : Deleter()
      , m_value()
    {}

    explicit UniqueHandle( Type const& value, Deleter const& deleter = Deleter() ) VKMA_NOEXCEPT
      : Deleter( deleter)
      , m_value( value )
    {}

    UniqueHandle( UniqueHandle const& ) = delete;

    UniqueHandle( UniqueHandle && other ) VKMA_NOEXCEPT
      : Deleter( std::move( static_cast<Deleter&>( other ) ) )
      , m_value( other.release() )
    {}

    ~UniqueHandle() VKMA_NOEXCEPT
    {
      if ( m_value ) this->destroy( m_value );
    }

    UniqueHandle & operator=( UniqueHandle const& ) = delete;

    UniqueHandle & operator=( UniqueHandle && other ) VKMA_NOEXCEPT
    {
      reset( other.release() );
      *static_cast<Deleter*>(this) = std::move( static_cast<Deleter&>(other) );
      return *this;
    }

    explicit operator bool() const VKMA_NOEXCEPT
    {
      return m_value.operator bool();
    }

    Type const* operator->() const VKMA_NOEXCEPT
    {
      return &m_value;
    }

    Type * operator->() VKMA_NOEXCEPT
    {
      return &m_value;
    }

    Type const& operator*() const VKMA_NOEXCEPT
    {
      return m_value;
    }

    Type & operator*() VKMA_NOEXCEPT
    {
      return m_value;
    }

    const Type & get() const VKMA_NOEXCEPT
    {
      return m_value;
    }

    Type & get() VKMA_NOEXCEPT
    {
      return m_value;
    }

    void reset( Type const& value = Type() ) VKMA_NOEXCEPT
    {
      if ( m_value != value )
      {
        if ( m_value ) this->destroy( m_value );
        m_value = value;
      }
    }

    Type release() VKMA_NOEXCEPT
    {
      Type value = m_value;
      m_value = nullptr;
      return value;
    }

    void swap( UniqueHandle<Type> & rhs ) VKMA_NOEXCEPT
    {
      std::swap(m_value, rhs.m_value);
      std::swap(static_cast<Deleter&>(*this), static_cast<Deleter&>(rhs));
    }

  private:
    Type    m_value;
  };

  template <typename UniqueType>
  VKMA_INLINE std::vector<typename UniqueType::element_type> uniqueToRaw(std::vector<UniqueType> const& handles)
  {
    std::vector<typename UniqueType::element_type> newBuffer(handles.size());
    std::transform(handles.begin(), handles.end(), newBuffer.begin(), [](UniqueType const& handle) { return handle.get(); });
    return newBuffer;
  }

  template <typename Type>
  VKMA_INLINE void swap( UniqueHandle<Type> & lhs, UniqueHandle<Type> & rhs ) VKMA_NOEXCEPT
  {
    lhs.swap( rhs );
  }
#endif
#define VKMA_DEFAULT_ARGUMENT_ASSIGNMENT = {}
# define VKMA_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT = nullptr

  struct AllocationCallbacks;

  template <typename OwnerType>
  class ObjectDestroy
  {
    public:
    ObjectDestroy() = default;

    ObjectDestroy( OwnerType owner,
                   Optional<const AllocationCallbacks> allocationCallbacks
                                    VKMA_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT ) VKMA_NOEXCEPT
      : m_owner( owner )
      , m_allocationCallbacks( allocationCallbacks )
    {}

      OwnerType getOwner() const VKMA_NOEXCEPT { return m_owner; }
      Optional<const AllocationCallbacks> getAllocator() const VKMA_NOEXCEPT { return m_allocationCallbacks; }

    protected:
      template <typename T>
      void destroy(T t) VKMA_NOEXCEPT
      {
        VKMA_ASSERT( m_owner );
        m_owner.destroy( t, m_allocationCallbacks );
      }

    private:
    OwnerType                           m_owner               = {};
    Optional<const AllocationCallbacks> m_allocationCallbacks = nullptr;
  };

  class NoParent;

  template <>
  class ObjectDestroy<NoParent>
  {
    public:
    ObjectDestroy() = default;

    ObjectDestroy( Optional<const AllocationCallbacks> allocationCallbacks ) VKMA_NOEXCEPT
      : m_allocationCallbacks( allocationCallbacks )
    {}

      Optional<const AllocationCallbacks> getAllocator() const VKMA_NOEXCEPT { return m_allocationCallbacks; }

    protected:
      template <typename T>
      void destroy(T t) VKMA_NOEXCEPT
      {
        t.destroy( m_allocationCallbacks );
      }

    private:
    Optional<const AllocationCallbacks> m_allocationCallbacks = nullptr;
  };

  template <typename OwnerType>
  class ObjectFree
  {
  public:
    ObjectFree() = default;

    ObjectFree( OwnerType owner,
                Optional<const AllocationCallbacks> allocationCallbacks VKMA_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT ) VKMA_NOEXCEPT
      : m_owner( owner )
      , m_allocationCallbacks( allocationCallbacks )
    {}

    OwnerType getOwner() const VKMA_NOEXCEPT
    {
      return m_owner;
    }

    Optional<const AllocationCallbacks> getAllocator() const VKMA_NOEXCEPT
    {
      return m_allocationCallbacks;
    }

  protected:
    template <typename T>
    void destroy( T t ) VKMA_NOEXCEPT
    {
      VKMA_ASSERT( m_owner );
      m_owner.free( t, m_allocationCallbacks );
    }

  private:
    OwnerType                           m_owner               = {};
    Optional<const AllocationCallbacks> m_allocationCallbacks = nullptr;
  };

  template <typename OwnerType>
  class ObjectRelease
  {
  public:
    ObjectRelease() = default;

    ObjectRelease( OwnerType owner ) VKMA_NOEXCEPT
      : m_owner( owner )
    {}

    OwnerType getOwner() const VKMA_NOEXCEPT
    {
      return m_owner;
    }

  protected:
    template <typename T>
    void destroy( T t ) VKMA_NOEXCEPT
    {
      VKMA_ASSERT( m_owner );
      m_owner.release( t );
    }

  private:
    OwnerType        m_owner    = {};
  };

  template <typename OwnerType, typename PoolType>
  class PoolFree
  {
    public:
      PoolFree() = default;

    PoolFree( OwnerType        owner,
              PoolType         pool ) VKMA_NOEXCEPT
      : m_owner( owner )
      , m_pool( pool )
    {}

      OwnerType getOwner() const VKMA_NOEXCEPT { return m_owner; }
      PoolType getPool() const VKMA_NOEXCEPT { return m_pool; }

    protected:
      template <typename T>
      void destroy(T t) VKMA_NOEXCEPT
      {
        m_owner.free( m_pool, t );
      }

    private:
      OwnerType        m_owner    = OwnerType();
      PoolType         m_pool     = PoolType();
  };

  using VkBool32 = uint32_t;
  using VkDeviceSize = uint64_t;
  using VkMemoryPropertyFlags = VkFlags;

  template <typename EnumType, EnumType value>
  struct CppType
  {};

  template <typename Type>
  struct isVulkanHandleType
  {
    static VKMA_CONST_OR_CONSTEXPR bool value = false;
  };

  VKMA_INLINE std::string toHexString( uint32_t value )
  {
    std::stringstream stream;
    stream << std::hex << value;
    return stream.str();
  }

  enum class AllocationCreateFlagBits : VkmaAllocationCreateFlags
  {
    eVmaAllocationCreateDedicatedMemory = VMA_ALLOCATION_CREATE_DEDICATED_MEMORY_BIT,
    eVmaAllocationCreateNeverAllocate = VMA_ALLOCATION_CREATE_NEVER_ALLOCATE_BIT,
    eVmaAllocationCreateMapped = VMA_ALLOCATION_CREATE_MAPPED_BIT,
    eVmaAllocationCreateCanBecomeLost = VMA_ALLOCATION_CREATE_CAN_BECOME_LOST_BIT,
    eVmaAllocationCreateCanMakeOtherLost = VMA_ALLOCATION_CREATE_CAN_MAKE_OTHER_LOST_BIT,
    eVmaAllocationCreateUserDataCopyString = VMA_ALLOCATION_CREATE_USER_DATA_COPY_STRING_BIT,
    eVmaAllocationCreateUpperAddress = VMA_ALLOCATION_CREATE_UPPER_ADDRESS_BIT,
    eVmaAllocationCreateDontBind = VMA_ALLOCATION_CREATE_DONT_BIND_BIT,
    eVmaAllocationCreateWithinBudget = VMA_ALLOCATION_CREATE_WITHIN_BUDGET_BIT,
    eVmaAllocationCreateStrategyBestFit = VMA_ALLOCATION_CREATE_STRATEGY_BEST_FIT_BIT,
    eVmaAllocationCreateStrategyWorstFit = VMA_ALLOCATION_CREATE_STRATEGY_WORST_FIT_BIT,
    eVmaAllocationCreateStrategyFirstFit = VMA_ALLOCATION_CREATE_STRATEGY_FIRST_FIT_BIT,
    eVmaAllocationCreateStrategyMinMemory = VMA_ALLOCATION_CREATE_STRATEGY_MIN_MEMORY_BIT,
    eVmaAllocationCreateStrategyMinTime = VMA_ALLOCATION_CREATE_STRATEGY_MIN_TIME_BIT,
    eVmaAllocationCreateStrategyMinFragmentation = VMA_ALLOCATION_CREATE_STRATEGY_MIN_FRAGMENTATION_BIT,
    eVmaAllocationCreateStrategyMask = VMA_ALLOCATION_CREATE_STRATEGY_MASK
  };

  VKMA_INLINE std::string to_string( AllocationCreateFlagBits value )
  {
    switch ( value )
    {
      case AllocationCreateFlagBits::eVmaAllocationCreateDedicatedMemory : return "VmaAllocationCreateDedicatedMemory";
      case AllocationCreateFlagBits::eVmaAllocationCreateNeverAllocate : return "VmaAllocationCreateNeverAllocate";
      case AllocationCreateFlagBits::eVmaAllocationCreateMapped : return "VmaAllocationCreateMapped";
      case AllocationCreateFlagBits::eVmaAllocationCreateCanBecomeLost : return "VmaAllocationCreateCanBecomeLost";
      case AllocationCreateFlagBits::eVmaAllocationCreateCanMakeOtherLost : return "VmaAllocationCreateCanMakeOtherLost";
      case AllocationCreateFlagBits::eVmaAllocationCreateUserDataCopyString : return "VmaAllocationCreateUserDataCopyString";
      case AllocationCreateFlagBits::eVmaAllocationCreateUpperAddress : return "VmaAllocationCreateUpperAddress";
      case AllocationCreateFlagBits::eVmaAllocationCreateDontBind : return "VmaAllocationCreateDontBind";
      case AllocationCreateFlagBits::eVmaAllocationCreateWithinBudget : return "VmaAllocationCreateWithinBudget";
      case AllocationCreateFlagBits::eVmaAllocationCreateStrategyBestFit : return "VmaAllocationCreateStrategyBestFit";
      case AllocationCreateFlagBits::eVmaAllocationCreateStrategyWorstFit : return "VmaAllocationCreateStrategyWorstFit";
      case AllocationCreateFlagBits::eVmaAllocationCreateStrategyFirstFit : return "VmaAllocationCreateStrategyFirstFit";
      case AllocationCreateFlagBits::eVmaAllocationCreateStrategyMinMemory : return "VmaAllocationCreateStrategyMinMemory";
      case AllocationCreateFlagBits::eVmaAllocationCreateStrategyMinTime : return "VmaAllocationCreateStrategyMinTime";
      case AllocationCreateFlagBits::eVmaAllocationCreateStrategyMinFragmentation : return "VmaAllocationCreateStrategyMinFragmentation";
      case AllocationCreateFlagBits::eVmaAllocationCreateStrategyMask : return "VmaAllocationCreateStrategyMask";
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class AllocatorCreateFlagBits : VkmaAllocatorCreateFlags
  {
    eVmaAllocatorCreateExternallySynchronized = VMA_ALLOCATOR_CREATE_EXTERNALLY_SYNCHRONIZED_BIT,
    eVmaAllocatorCreateKhrDedicatedAllocation = VMA_ALLOCATOR_CREATE_KHR_DEDICATED_ALLOCATION_BIT,
    eVmaAllocatorCreateKhrBindMemory2 = VMA_ALLOCATOR_CREATE_KHR_BIND_MEMORY2_BIT,
    eVmaAllocatorCreateExtMemoryBudget = VMA_ALLOCATOR_CREATE_EXT_MEMORY_BUDGET_BIT
  };

  VKMA_INLINE std::string to_string( AllocatorCreateFlagBits value )
  {
    switch ( value )
    {
      case AllocatorCreateFlagBits::eVmaAllocatorCreateExternallySynchronized : return "VmaAllocatorCreateExternallySynchronized";
      case AllocatorCreateFlagBits::eVmaAllocatorCreateKhrDedicatedAllocation : return "VmaAllocatorCreateKhrDedicatedAllocation";
      case AllocatorCreateFlagBits::eVmaAllocatorCreateKhrBindMemory2 : return "VmaAllocatorCreateKhrBindMemory2";
      case AllocatorCreateFlagBits::eVmaAllocatorCreateExtMemoryBudget : return "VmaAllocatorCreateExtMemoryBudget";
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class DefragmentationFlagBits : VkmaDefragmentationFlags
  {};

  VKMA_INLINE std::string to_string( DefragmentationFlagBits )
  {
    return "(void)";
  }

  enum class MemoryUsage
  {
    eVmaMemoryUsageUnknown = VMA_MEMORY_USAGE_UNKNOWN,
    eVmaMemoryUsageGpuOnly = VMA_MEMORY_USAGE_GPU_ONLY,
    eVmaMemoryUsageCpuOnly = VMA_MEMORY_USAGE_CPU_ONLY,
    eVmaMemoryUsageCpuToGpu = VMA_MEMORY_USAGE_CPU_TO_GPU,
    eVmaMemoryUsageGpuToCpu = VMA_MEMORY_USAGE_GPU_TO_CPU,
    eVmaMemoryUsageCpuCopy = VMA_MEMORY_USAGE_CPU_COPY,
    eVmaMemoryUsageGpuLazilyAllocated = VMA_MEMORY_USAGE_GPU_LAZILY_ALLOCATED
  };

  VKMA_INLINE std::string to_string( MemoryUsage value )
  {
    switch ( value )
    {
      case MemoryUsage::eVmaMemoryUsageUnknown : return "VmaMemoryUsageUnknown";
      case MemoryUsage::eVmaMemoryUsageGpuOnly : return "VmaMemoryUsageGpuOnly";
      case MemoryUsage::eVmaMemoryUsageCpuOnly : return "VmaMemoryUsageCpuOnly";
      case MemoryUsage::eVmaMemoryUsageCpuToGpu : return "VmaMemoryUsageCpuToGpu";
      case MemoryUsage::eVmaMemoryUsageGpuToCpu : return "VmaMemoryUsageGpuToCpu";
      case MemoryUsage::eVmaMemoryUsageCpuCopy : return "VmaMemoryUsageCpuCopy";
      case MemoryUsage::eVmaMemoryUsageGpuLazilyAllocated : return "VmaMemoryUsageGpuLazilyAllocated";
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class PoolCreateFlagBits : VkmaPoolCreateFlags
  {
    eVmaPoolCreateIgnoreBufferImageGranularity = VMA_POOL_CREATE_IGNORE_BUFFER_IMAGE_GRANULARITY_BIT,
    eVmaPoolCreateLinearAlgorithm = VMA_POOL_CREATE_LINEAR_ALGORITHM_BIT,
    eVmaPoolCreateBuddyAlgorithm = VMA_POOL_CREATE_BUDDY_ALGORITHM_BIT,
    eVmaPoolCreateAlgorithmMask = VMA_POOL_CREATE_ALGORITHM_MASK
  };

  VKMA_INLINE std::string to_string( PoolCreateFlagBits value )
  {
    switch ( value )
    {
      case PoolCreateFlagBits::eVmaPoolCreateIgnoreBufferImageGranularity : return "VmaPoolCreateIgnoreBufferImageGranularity";
      case PoolCreateFlagBits::eVmaPoolCreateLinearAlgorithm : return "VmaPoolCreateLinearAlgorithm";
      case PoolCreateFlagBits::eVmaPoolCreateBuddyAlgorithm : return "VmaPoolCreateBuddyAlgorithm";
      case PoolCreateFlagBits::eVmaPoolCreateAlgorithmMask : return "VmaPoolCreateAlgorithmMask";
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class RecordFlagBits : VkmaRecordFlags
  {
    eVmaRecordFlushAfterCall = VMA_RECORD_FLUSH_AFTER_CALL_BIT
  };

  VKMA_INLINE std::string to_string( RecordFlagBits value )
  {
    switch ( value )
    {
      case RecordFlagBits::eVmaRecordFlushAfterCall : return "VmaRecordFlushAfterCall";
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class Result
  {
    eVkSuccess = VK_SUCCESS,
    eVkNotReady = VK_NOT_READY,
    eVkTimeout = VK_TIMEOUT,
    eVkEventSet = VK_EVENT_SET,
    eVkEventReset = VK_EVENT_RESET,
    eVkIncomplete = VK_INCOMPLETE,
    eVkErrorOutOfHostMemory = VK_ERROR_OUT_OF_HOST_MEMORY,
    eVkErrorOutOfDeviceMemory = VK_ERROR_OUT_OF_DEVICE_MEMORY,
    eVkErrorInitializationFailed = VK_ERROR_INITIALIZATION_FAILED,
    eVkErrorDeviceLost = VK_ERROR_DEVICE_LOST,
    eVkErrorMemoryMapFailed = VK_ERROR_MEMORY_MAP_FAILED,
    eVkErrorLayerNotPresent = VK_ERROR_LAYER_NOT_PRESENT,
    eVkErrorExtensionNotPresent = VK_ERROR_EXTENSION_NOT_PRESENT,
    eVkErrorFeatureNotPresent = VK_ERROR_FEATURE_NOT_PRESENT,
    eVkErrorIncompatibleDriver = VK_ERROR_INCOMPATIBLE_DRIVER,
    eVkErrorTooManyObjects = VK_ERROR_TOO_MANY_OBJECTS,
    eVkErrorFormatNotSupported = VK_ERROR_FORMAT_NOT_SUPPORTED,
    eVkErrorFragmentedPool = VK_ERROR_FRAGMENTED_POOL,
    eVkErrorUnknown = VK_ERROR_UNKNOWN,
    eVkErrorOutOfPoolMemory = VK_ERROR_OUT_OF_POOL_MEMORY,
    eVkErrorInvalidExternalHandle = VK_ERROR_INVALID_EXTERNAL_HANDLE,
    eVkErrorFragmentation = VK_ERROR_FRAGMENTATION,
    eVkErrorInvalidOpaqueCaptureAddress = VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS,
    eVkErrorSurfaceLostKhr = VK_ERROR_SURFACE_LOST_KHR,
    eVkErrorNativeWindowInUseKhr = VK_ERROR_NATIVE_WINDOW_IN_USE_KHR,
    eVkSuboptimalKhr = VK_SUBOPTIMAL_KHR,
    eVkErrorOutOfDateKhr = VK_ERROR_OUT_OF_DATE_KHR,
    eVkErrorIncompatibleDisplayKhr = VK_ERROR_INCOMPATIBLE_DISPLAY_KHR,
    eVkErrorValidationFailedExt = VK_ERROR_VALIDATION_FAILED_EXT,
    eVkErrorInvalidShaderNv = VK_ERROR_INVALID_SHADER_NV,
    eVkErrorInvalidDrmFormatModifierPlaneLayoutExt = VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT,
    eVkErrorNotPermittedExt = VK_ERROR_NOT_PERMITTED_EXT,
    eVkErrorFullScreenExclusiveModeLostExt = VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT,
    eVkThreadIdleKhr = VK_THREAD_IDLE_KHR,
    eVkThreadDoneKhr = VK_THREAD_DONE_KHR,
    eVkOperationDeferredKhr = VK_OPERATION_DEFERRED_KHR,
    eVkOperationNotDeferredKhr = VK_OPERATION_NOT_DEFERRED_KHR,
    eVkPipelineCompileRequiredExt = VK_PIPELINE_COMPILE_REQUIRED_EXT,
    eVkErrorOutOfPoolMemoryKhr = VK_ERROR_OUT_OF_POOL_MEMORY_KHR,
    eVkErrorInvalidExternalHandleKhr = VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR,
    eVkErrorFragmentationExt = VK_ERROR_FRAGMENTATION_EXT,
    eVkErrorInvalidDeviceAddressExt = VK_ERROR_INVALID_DEVICE_ADDRESS_EXT,
    eVkErrorInvalidOpaqueCaptureAddressKhr = VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR,
    eVkErrorPipelineCompileRequiredExt = VK_ERROR_PIPELINE_COMPILE_REQUIRED_EXT
  };

  VKMA_INLINE std::string to_string( Result value )
  {
    switch ( value )
    {
      case Result::eVkSuccess : return "VkSuccess";
      case Result::eVkNotReady : return "VkNotReady";
      case Result::eVkTimeout : return "VkTimeout";
      case Result::eVkEventSet : return "VkEventSet";
      case Result::eVkEventReset : return "VkEventReset";
      case Result::eVkIncomplete : return "VkIncomplete";
      case Result::eVkErrorOutOfHostMemory : return "VkErrorOutOfHostMemory";
      case Result::eVkErrorOutOfDeviceMemory : return "VkErrorOutOfDeviceMemory";
      case Result::eVkErrorInitializationFailed : return "VkErrorInitializationFailed";
      case Result::eVkErrorDeviceLost : return "VkErrorDeviceLost";
      case Result::eVkErrorMemoryMapFailed : return "VkErrorMemoryMapFailed";
      case Result::eVkErrorLayerNotPresent : return "VkErrorLayerNotPresent";
      case Result::eVkErrorExtensionNotPresent : return "VkErrorExtensionNotPresent";
      case Result::eVkErrorFeatureNotPresent : return "VkErrorFeatureNotPresent";
      case Result::eVkErrorIncompatibleDriver : return "VkErrorIncompatibleDriver";
      case Result::eVkErrorTooManyObjects : return "VkErrorTooManyObjects";
      case Result::eVkErrorFormatNotSupported : return "VkErrorFormatNotSupported";
      case Result::eVkErrorFragmentedPool : return "VkErrorFragmentedPool";
      case Result::eVkErrorUnknown : return "VkErrorUnknown";
      case Result::eVkErrorOutOfPoolMemory : return "VkErrorOutOfPoolMemory";
      case Result::eVkErrorInvalidExternalHandle : return "VkErrorInvalidExternalHandle";
      case Result::eVkErrorFragmentation : return "VkErrorFragmentation";
      case Result::eVkErrorInvalidOpaqueCaptureAddress : return "VkErrorInvalidOpaqueCaptureAddress";
      case Result::eVkErrorSurfaceLostKhr : return "VkErrorSurfaceLostKhr";
      case Result::eVkErrorNativeWindowInUseKhr : return "VkErrorNativeWindowInUseKhr";
      case Result::eVkSuboptimalKhr : return "VkSuboptimalKhr";
      case Result::eVkErrorOutOfDateKhr : return "VkErrorOutOfDateKhr";
      case Result::eVkErrorIncompatibleDisplayKhr : return "VkErrorIncompatibleDisplayKhr";
      case Result::eVkErrorValidationFailedExt : return "VkErrorValidationFailedExt";
      case Result::eVkErrorInvalidShaderNv : return "VkErrorInvalidShaderNv";
      case Result::eVkErrorInvalidDrmFormatModifierPlaneLayoutExt : return "VkErrorInvalidDrmFormatModifierPlaneLayoutExt";
      case Result::eVkErrorNotPermittedExt : return "VkErrorNotPermittedExt";
      case Result::eVkErrorFullScreenExclusiveModeLostExt : return "VkErrorFullScreenExclusiveModeLostExt";
      case Result::eVkThreadIdleKhr : return "VkThreadIdleKhr";
      case Result::eVkThreadDoneKhr : return "VkThreadDoneKhr";
      case Result::eVkOperationDeferredKhr : return "VkOperationDeferredKhr";
      case Result::eVkOperationNotDeferredKhr : return "VkOperationNotDeferredKhr";
      case Result::eVkPipelineCompileRequiredExt : return "VkPipelineCompileRequiredExt";
      case Result::eVkErrorOutOfPoolMemoryKhr : return "VkErrorOutOfPoolMemoryKhr";
      case Result::eVkErrorInvalidExternalHandleKhr : return "VkErrorInvalidExternalHandleKhr";
      case Result::eVkErrorFragmentationExt : return "VkErrorFragmentationExt";
      case Result::eVkErrorInvalidDeviceAddressExt : return "VkErrorInvalidDeviceAddressExt";
      case Result::eVkErrorInvalidOpaqueCaptureAddressKhr : return "VkErrorInvalidOpaqueCaptureAddressKhr";
      case Result::eVkErrorPipelineCompileRequiredExt : return "VkErrorPipelineCompileRequiredExt";
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }


  using AllocationCreateFlags = Flags<AllocationCreateFlagBits>;

  template <> struct FlagTraits<AllocationCreateFlagBits>
  {
    enum : VkFlags
    {
      allFlags = VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateDedicatedMemory) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateNeverAllocate) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateMapped) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateCanBecomeLost) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateCanMakeOtherLost) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateUserDataCopyString) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateUpperAddress) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateDontBind) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateWithinBudget) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateStrategyBestFit) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateStrategyWorstFit) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateStrategyFirstFit) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateStrategyMinMemory) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateStrategyMinTime) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateStrategyMinFragmentation) | VkFlags(AllocationCreateFlagBits::eVmaAllocationCreateStrategyMask)
    };
  };

  VKMA_INLINE VKMA_CONSTEXPR AllocationCreateFlags operator|( AllocationCreateFlagBits bit0, AllocationCreateFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return AllocationCreateFlags( bit0 ) | bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR AllocationCreateFlags operator&( AllocationCreateFlagBits bit0, AllocationCreateFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return AllocationCreateFlags( bit0 ) & bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR AllocationCreateFlags operator^( AllocationCreateFlagBits bit0, AllocationCreateFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return AllocationCreateFlags( bit0 ) ^ bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR AllocationCreateFlags operator~( AllocationCreateFlagBits bits ) VKMA_NOEXCEPT
  {
    return ~( AllocationCreateFlags( bits ) );
  }

  VKMA_INLINE std::string to_string( AllocationCreateFlags value  )
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
      allFlags = VkFlags(AllocatorCreateFlagBits::eVmaAllocatorCreateExternallySynchronized) | VkFlags(AllocatorCreateFlagBits::eVmaAllocatorCreateKhrDedicatedAllocation) | VkFlags(AllocatorCreateFlagBits::eVmaAllocatorCreateKhrBindMemory2) | VkFlags(AllocatorCreateFlagBits::eVmaAllocatorCreateExtMemoryBudget)
    };
  };

  VKMA_INLINE VKMA_CONSTEXPR AllocatorCreateFlags operator|( AllocatorCreateFlagBits bit0, AllocatorCreateFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return AllocatorCreateFlags( bit0 ) | bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR AllocatorCreateFlags operator&( AllocatorCreateFlagBits bit0, AllocatorCreateFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return AllocatorCreateFlags( bit0 ) & bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR AllocatorCreateFlags operator^( AllocatorCreateFlagBits bit0, AllocatorCreateFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return AllocatorCreateFlags( bit0 ) ^ bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR AllocatorCreateFlags operator~( AllocatorCreateFlagBits bits ) VKMA_NOEXCEPT
  {
    return ~( AllocatorCreateFlags( bits ) );
  }

  VKMA_INLINE std::string to_string( AllocatorCreateFlags value  )
  {

    if ( !value ) return "{}";
    std::string result;

    return "{ " + result.substr(0, result.size() - 3) + " }";
  }


  using DefragmentationFlags = Flags<DefragmentationFlagBits>;

  VKMA_INLINE std::string to_string( DefragmentationFlags  )
  {

    return "{}";
  }


  using PoolCreateFlags = Flags<PoolCreateFlagBits>;

  template <> struct FlagTraits<PoolCreateFlagBits>
  {
    enum : VkFlags
    {
      allFlags = VkFlags(PoolCreateFlagBits::eVmaPoolCreateIgnoreBufferImageGranularity) | VkFlags(PoolCreateFlagBits::eVmaPoolCreateLinearAlgorithm) | VkFlags(PoolCreateFlagBits::eVmaPoolCreateBuddyAlgorithm) | VkFlags(PoolCreateFlagBits::eVmaPoolCreateAlgorithmMask)
    };
  };

  VKMA_INLINE VKMA_CONSTEXPR PoolCreateFlags operator|( PoolCreateFlagBits bit0, PoolCreateFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return PoolCreateFlags( bit0 ) | bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR PoolCreateFlags operator&( PoolCreateFlagBits bit0, PoolCreateFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return PoolCreateFlags( bit0 ) & bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR PoolCreateFlags operator^( PoolCreateFlagBits bit0, PoolCreateFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return PoolCreateFlags( bit0 ) ^ bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR PoolCreateFlags operator~( PoolCreateFlagBits bits ) VKMA_NOEXCEPT
  {
    return ~( PoolCreateFlags( bits ) );
  }

  VKMA_INLINE std::string to_string( PoolCreateFlags value  )
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
      allFlags = VkFlags(RecordFlagBits::eVmaRecordFlushAfterCall)
    };
  };

  VKMA_INLINE VKMA_CONSTEXPR RecordFlags operator|( RecordFlagBits bit0, RecordFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return RecordFlags( bit0 ) | bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR RecordFlags operator&( RecordFlagBits bit0, RecordFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return RecordFlags( bit0 ) & bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR RecordFlags operator^( RecordFlagBits bit0, RecordFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return RecordFlags( bit0 ) ^ bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR RecordFlags operator~( RecordFlagBits bits ) VKMA_NOEXCEPT
  {
    return ~( RecordFlags( bits ) );
  }

  VKMA_INLINE std::string to_string( RecordFlags value  )
  {

    if ( !value ) return "{}";
    std::string result;

    return "{ " + result.substr(0, result.size() - 3) + " }";
  }
} // namespace VKMA_NAMESPACE

#ifndef VKMA_NO_EXCEPTIONS
namespace std
{
  template <>
  struct is_error_code_enum<VKMA_NAMESPACE::Result> : public true_type
  {};
}
#endif

namespace VKMA_NAMESPACE
{
#ifndef VKMA_NO_EXCEPTIONS
  class ErrorCategoryImpl : public std::error_category
  {
    public:
    virtual const char* name() const VKMA_NOEXCEPT override { return VKMA_NAMESPACE_STRING"::Result"; }
    virtual std::string message(int ev) const override { return to_string(static_cast<Result>(ev)); }
  };

  class Error
  {
    public:
    Error() VKMA_NOEXCEPT = default;
    Error(const Error&) VKMA_NOEXCEPT = default;
    virtual ~Error() VKMA_NOEXCEPT = default;

    virtual const char* what() const VKMA_NOEXCEPT = 0;
  };

  class LogicError : public Error, public std::logic_error
  {
    public:
    explicit LogicError( const std::string& what )
      : Error(), std::logic_error(what) {}
    explicit LogicError( char const * what )
      : Error(), std::logic_error(what) {}

    virtual const char* what() const VKMA_NOEXCEPT { return std::logic_error::what(); }
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

    virtual const char* what() const VKMA_NOEXCEPT { return std::system_error::what(); }
  };

  VKMA_INLINE const std::error_category& errorCategory() VKMA_NOEXCEPT
  {
    static ErrorCategoryImpl instance;
    return instance;
  }

  VKMA_INLINE std::error_code make_error_code(Result e) VKMA_NOEXCEPT
  {
    return std::error_code(static_cast<int>(e), errorCategory());
  }

  VKMA_INLINE std::error_condition make_error_condition(Result e) VKMA_NOEXCEPT
  {
    return std::error_condition(static_cast<int>(e), errorCategory());
  }


  [[noreturn]] static void throwResultException( Result result, char const * message )
  {
    switch ( result )
    {
      default: throw SystemError( make_error_code( result ) );
    }
  }
#endif

  template <typename T> void ignore(T const&) VKMA_NOEXCEPT {}

  template <typename T>
  struct ResultValue
  {
#ifdef VKMA_HAS_NOEXCEPT
    ResultValue( Result r, T & v ) VKMA_NOEXCEPT(VKMA_NOEXCEPT(T(v)))
#else
    ResultValue( Result r, T & v )
#endif
      : result( r )
      , value( v )
    {}

#ifdef VKMA_HAS_NOEXCEPT
    ResultValue( Result r, T && v ) VKMA_NOEXCEPT(VKMA_NOEXCEPT(T(std::move(v))))
#else
    ResultValue( Result r, T && v )
#endif
      : result( r )
      , value( std::move( v ) )
    {}

    Result  result;
    T       value;

    operator std::tuple<Result&, T&>() VKMA_NOEXCEPT { return std::tuple<Result&, T&>(result, value); }

#if !defined(VKMA_DISABLE_IMPLICIT_RESULT_VALUE_CAST)
    VKMA_DEPRECATED("Implicit-cast operators on vkma::ResultValue are deprecated. Explicitly access the value as member of ResultValue.")
    operator T const& () const & VKMA_NOEXCEPT
    {
      return value;
    }

    VKMA_DEPRECATED("Implicit-cast operators on vkma::ResultValue are deprecated. Explicitly access the value as member of ResultValue.")
    operator T& () & VKMA_NOEXCEPT
    {
      return value;
    }

    VKMA_DEPRECATED("Implicit-cast operators on vkma::ResultValue are deprecated. Explicitly access the value as member of ResultValue.")
    operator T const&& () const && VKMA_NOEXCEPT
    {
      return std::move( value );
    }

    VKMA_DEPRECATED("Implicit-cast operators on vkma::ResultValue are deprecated. Explicitly access the value as member of ResultValue.")
    operator T&& () && VKMA_NOEXCEPT
    {
      return std::move( value );
    }
#endif
  };

#if !defined(VKMA_NO_SMART_HANDLE)
  template <typename Type>
  struct ResultValue<UniqueHandle<Type>>
  {
#ifdef VKMA_HAS_NOEXCEPT
    ResultValue(Result r, UniqueHandle<Type> && v) VKMA_NOEXCEPT
#else
    ResultValue(Result r, UniqueHandle<Type> && v)
#endif
      : result(r)
      , value(std::move(v))
    {}

    std::tuple<Result, UniqueHandle<Type>> asTuple()
    {
      return std::make_tuple( result, std::move( value ) );
    }

#  if !defined(VKMA_DISABLE_IMPLICIT_RESULT_VALUE_CAST)
    VKMA_DEPRECATED("Implicit-cast operators on vkma::ResultValue are deprecated. Explicitly access the value as member of ResultValue.")
    operator UniqueHandle<Type>& () & VKMA_NOEXCEPT
    {
      return value;
    }

    VKMA_DEPRECATED("Implicit-cast operators on vkma::ResultValue are deprecated. Explicitly access the value as member of ResultValue.")
    operator UniqueHandle<Type>() VKMA_NOEXCEPT
    {
      return std::move(value);
    }
#  endif

    Result                        result;
    UniqueHandle<Type>  value;
  };

  template <typename Type>
  struct ResultValue<std::vector<UniqueHandle<Type>>>
  {
#  ifdef VKMA_HAS_NOEXCEPT
    ResultValue( Result r, std::vector<UniqueHandle<Type>> && v ) VKMA_NOEXCEPT
#  else
    ResultValue( Result r, std::vector<UniqueHandle<Type>> && v )
#  endif
      : result( r )
      , value( std::move( v ) )
    {}

    Result                                    result;
    std::vector<UniqueHandle<Type>> value;

    operator std::tuple<Result &, std::vector<UniqueHandle<Type>> &>() VKMA_NOEXCEPT
    {
      return std::tuple<Result &, std::vector<UniqueHandle<Type>> &>( result, value );
    }
  };
#endif

  template <typename T>
  struct ResultValueType
  {
#ifdef VKMA_NO_EXCEPTIONS
    typedef ResultValue<T>  type;
#else
    typedef T               type;
#endif
  };

  template <>
  struct ResultValueType<void>
  {
#ifdef VKMA_NO_EXCEPTIONS
    typedef Result type;
#else
    typedef void   type;
#endif
  };

  VKMA_INLINE ResultValueType<void>::type createResultValue( Result result, char const * message )
  {
#ifdef VKMA_NO_EXCEPTIONS
    ignore(message);
    VKMA_ASSERT_ON_RESULT( result == Result::eSuccess );
    return result;
#else
    if ( result != Result::eSuccess )
    {
      throwResultException( result, message );
    }
#endif
  }

  template <typename T>
  VKMA_INLINE typename ResultValueType<T>::type createResultValue( Result result, T & data, char const * message )
  {
#ifdef VKMA_NO_EXCEPTIONS
    ignore(message);
    VKMA_ASSERT_ON_RESULT( result == Result::eSuccess );
    return ResultValue<T>( result, std::move( data ) );
#else
    if ( result != Result::eSuccess )
    {
      throwResultException( result, message );
    }
    return std::move( data );
#endif
  }

  VKMA_INLINE Result createResultValue( Result result, char const * message, std::initializer_list<Result> successCodes )
  {
#ifdef VKMA_NO_EXCEPTIONS
    ignore(message);
    ignore(successCodes);   // just in case VKMA_ASSERT_ON_RESULT is empty
    VKMA_ASSERT_ON_RESULT( std::find( successCodes.begin(), successCodes.end(), result ) != successCodes.end() );
#else
    if ( std::find( successCodes.begin(), successCodes.end(), result ) == successCodes.end() )
    {
      throwResultException( result, message );
    }
#endif
    return result;
  }

  template <typename T>
  VKMA_INLINE ResultValue<T> createResultValue( Result result, T & data, char const * message, std::initializer_list<Result> successCodes )
  {
#ifdef VKMA_NO_EXCEPTIONS
    ignore(message);
    ignore(successCodes);   // just in case VKMA_ASSERT_ON_RESULT is empty
    VKMA_ASSERT_ON_RESULT( std::find( successCodes.begin(), successCodes.end(), result ) != successCodes.end() );
#else
    if ( std::find( successCodes.begin(), successCodes.end(), result ) == successCodes.end() )
    {
      throwResultException( result, message );
    }
#endif
    return ResultValue<T>( result, data );
  }

#ifndef VKMA_NO_SMART_HANDLE
  template <typename T, typename D>
  VKMA_INLINE typename ResultValueType<UniqueHandle<T,D>>::type createResultValue( Result result, T & data, char const * message, typename UniqueHandleTraits<T,D>::deleter const& deleter )
  {
#ifdef VKMA_NO_EXCEPTIONS
    ignore(message);
    VKMA_ASSERT_ON_RESULT( result == Result::eSuccess );
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
  VKMA_INLINE ResultValue<UniqueHandle<T, D>>
                    createResultValue( Result                                             result,
                                       T &                                                data,
                                       char const *                                       message,
                                       std::initializer_list<Result>                      successCodes,
                                       typename UniqueHandleTraits<T, D>::deleter const & deleter )
  {
#  ifdef VKMA_NO_EXCEPTIONS
    ignore( message );
    ignore(successCodes);   // just in case VKMA_ASSERT_ON_RESULT is empty
    VKMA_ASSERT_ON_RESULT( std::find( successCodes.begin(), successCodes.end(), result ) != successCodes.end() );
#  else
    if ( std::find( successCodes.begin(), successCodes.end(), result ) == successCodes.end() )
    {
      throwResultException( result, message );
    }
#  endif
    return ResultValue<UniqueHandle<T, D>>( result, UniqueHandle<T, D>( data, deleter ) );
  }

  template <typename T, typename D>
  VKMA_INLINE typename ResultValueType<std::vector<UniqueHandle<T, D>>>::type
    createResultValue( Result result, std::vector<UniqueHandle<T, D>> && data, char const * message )
  {
#  ifdef VKMA_NO_EXCEPTIONS
    ignore( message );
    VKMA_ASSERT_ON_RESULT( result == Result::eSuccess );
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
  VKMA_INLINE ResultValue<std::vector<UniqueHandle<T, D>>>
                    createResultValue( Result                             result,
                                       std::vector<UniqueHandle<T, D>> && data,
                                       char const *                       message,
                                       std::initializer_list<Result>      successCodes )
  {
#  ifdef VKMA_NO_EXCEPTIONS
    ignore( message );
    ignore(successCodes);   // just in case VKMA_ASSERT_ON_RESULT is empty
    VKMA_ASSERT_ON_RESULT( std::find( successCodes.begin(), successCodes.end(), result ) != successCodes.end() );
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
    using CType = VkmaPool;


  public:
    VKMA_CONSTEXPR Pool() VKMA_NOEXCEPT
      : m_pool(VKMA_NULL_HANDLE)
    {}

    VKMA_CONSTEXPR Pool( std::nullptr_t ) VKMA_NOEXCEPT
      : m_pool(VKMA_NULL_HANDLE)
    {}

    VKMA_TYPESAFE_EXPLICIT Pool( VkmaPool pool ) VKMA_NOEXCEPT
      : m_pool( pool )
    {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    Pool & operator=(VkmaPool pool) VKMA_NOEXCEPT
    {
      m_pool = pool;
      return *this;
    }
#endif

    Pool & operator=( std::nullptr_t ) VKMA_NOEXCEPT
    {
      m_pool = VKMA_NULL_HANDLE;
      return *this;
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( Pool const& ) const = default;
#else
    bool operator==( Pool const & rhs ) const VKMA_NOEXCEPT
    {
      return m_pool == rhs.m_pool;
    }

    bool operator!=(Pool const & rhs ) const VKMA_NOEXCEPT
    {
      return m_pool != rhs.m_pool;
    }

    bool operator<(Pool const & rhs ) const VKMA_NOEXCEPT
    {
      return m_pool < rhs.m_pool;
    }
#endif

    VKMA_TYPESAFE_EXPLICIT operator VkmaPool() const VKMA_NOEXCEPT
    {
      return m_pool;
    }

    explicit operator bool() const VKMA_NOEXCEPT
    {
      return m_pool != VKMA_NULL_HANDLE;
    }

    bool operator!() const VKMA_NOEXCEPT
    {
      return m_pool == VKMA_NULL_HANDLE;
    }

  private:
    VkmaPool m_pool;
  };
  static_assert( sizeof( VKMA_NAMESPACE::Pool ) == sizeof( VkmaPool ), "handle and wrapper have different size!" );


  template <>
  struct isVulkanHandleType<VKMA_NAMESPACE::Pool>
  {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

  struct AllocationCreateInfo
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR AllocationCreateInfo(AllocationCreateFlags flags_ = {}, MemoryUsage usage_ = VKMA_NAMESPACE::MemoryUsage::eVmaMemoryUsageUnknown, VkMemoryPropertyFlags requiredFlags_ = {}, VkMemoryPropertyFlags preferredFlags_ = {}, uint32_t memoryTypeBits_ = {}, Pool pool_ = {}, void* pUserData_ = {}, float priority_ = {}) VKMA_NOEXCEPT
    : flags( flags_ ), usage( usage_ ), requiredFlags( requiredFlags_ ), preferredFlags( preferredFlags_ ), memoryTypeBits( memoryTypeBits_ ), pool( pool_ ), pUserData( pUserData_ ), priority( priority_ )
    {}

    VKMA_CONSTEXPR AllocationCreateInfo( AllocationCreateInfo const & rhs ) VKMA_NOEXCEPT = default;

    AllocationCreateInfo( VkmaAllocationCreateInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    AllocationCreateInfo & operator=( VkmaAllocationCreateInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::AllocationCreateInfo const *>( &rhs );
      return *this;
    }

    AllocationCreateInfo & operator=( AllocationCreateInfo const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( AllocationCreateInfo ) );
      return *this;
    }

    AllocationCreateInfo & setFlags( AllocationCreateFlags flags_ ) VKMA_NOEXCEPT
    {
      flags = flags_;
      return *this;
    }

    AllocationCreateInfo & setUsage( MemoryUsage usage_ ) VKMA_NOEXCEPT
    {
      usage = usage_;
      return *this;
    }

    AllocationCreateInfo & setRequiredFlags( VkMemoryPropertyFlags requiredFlags_ ) VKMA_NOEXCEPT
    {
      requiredFlags = requiredFlags_;
      return *this;
    }

    AllocationCreateInfo & setPreferredFlags( VkMemoryPropertyFlags preferredFlags_ ) VKMA_NOEXCEPT
    {
      preferredFlags = preferredFlags_;
      return *this;
    }

    AllocationCreateInfo & setMemoryTypeBits( uint32_t memoryTypeBits_ ) VKMA_NOEXCEPT
    {
      memoryTypeBits = memoryTypeBits_;
      return *this;
    }

    AllocationCreateInfo & setPool( Pool pool_ ) VKMA_NOEXCEPT
    {
      pool = pool_;
      return *this;
    }

    AllocationCreateInfo & setPUserData( void* pUserData_ ) VKMA_NOEXCEPT
    {
      pUserData = pUserData_;
      return *this;
    }

    AllocationCreateInfo & setPriority( float priority_ ) VKMA_NOEXCEPT
    {
      priority = priority_;
      return *this;
    }


    operator VkmaAllocationCreateInfo const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VkmaAllocationCreateInfo*>( this );
    }

    operator VkmaAllocationCreateInfo &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VkmaAllocationCreateInfo*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( AllocationCreateInfo const& ) const = default;
#else
    bool operator==( AllocationCreateInfo const& rhs ) const VKMA_NOEXCEPT
    {
      return ( flags == rhs.flags )
          && ( usage == rhs.usage )
          && ( requiredFlags == rhs.requiredFlags )
          && ( preferredFlags == rhs.preferredFlags )
          && ( memoryTypeBits == rhs.memoryTypeBits )
          && ( pool == rhs.pool )
          && ( pUserData == rhs.pUserData )
          && ( priority == rhs.priority );
    }

    bool operator!=( AllocationCreateInfo const& rhs ) const VKMA_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    AllocationCreateFlags flags = {};
    MemoryUsage usage = VKMA_NAMESPACE::MemoryUsage::eVmaMemoryUsageUnknown;
    VkMemoryPropertyFlags requiredFlags = {};
    VkMemoryPropertyFlags preferredFlags = {};
    uint32_t memoryTypeBits = {};
    Pool pool = {};
    void* pUserData = {};
    float priority = {};

  };
  static_assert( sizeof( AllocationCreateInfo ) == sizeof( VkmaAllocationCreateInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<AllocationCreateInfo>::value, "struct wrapper is not a standard layout!" );

  struct AllocationInfo
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR AllocationInfo(uint32_t memoryType_ = {}, VkDeviceMemory deviceMemory_ = {}, VkDeviceSize offset_ = {}, VkDeviceSize size_ = {}, void* pMappedData_ = {}, void* pUserData_ = {}) VKMA_NOEXCEPT
    : memoryType( memoryType_ ), deviceMemory( deviceMemory_ ), offset( offset_ ), size( size_ ), pMappedData( pMappedData_ ), pUserData( pUserData_ )
    {}

    VKMA_CONSTEXPR AllocationInfo( AllocationInfo const & rhs ) VKMA_NOEXCEPT = default;

    AllocationInfo( VkmaAllocationInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    AllocationInfo & operator=( VkmaAllocationInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::AllocationInfo const *>( &rhs );
      return *this;
    }

    AllocationInfo & operator=( AllocationInfo const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( AllocationInfo ) );
      return *this;
    }

    AllocationInfo & setMemoryType( uint32_t memoryType_ ) VKMA_NOEXCEPT
    {
      memoryType = memoryType_;
      return *this;
    }

    AllocationInfo & setDeviceMemory( VkDeviceMemory deviceMemory_ ) VKMA_NOEXCEPT
    {
      deviceMemory = deviceMemory_;
      return *this;
    }

    AllocationInfo & setOffset( VkDeviceSize offset_ ) VKMA_NOEXCEPT
    {
      offset = offset_;
      return *this;
    }

    AllocationInfo & setSize( VkDeviceSize size_ ) VKMA_NOEXCEPT
    {
      size = size_;
      return *this;
    }

    AllocationInfo & setPMappedData( void* pMappedData_ ) VKMA_NOEXCEPT
    {
      pMappedData = pMappedData_;
      return *this;
    }

    AllocationInfo & setPUserData( void* pUserData_ ) VKMA_NOEXCEPT
    {
      pUserData = pUserData_;
      return *this;
    }


    operator VkmaAllocationInfo const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VkmaAllocationInfo*>( this );
    }

    operator VkmaAllocationInfo &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VkmaAllocationInfo*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( AllocationInfo const& ) const = default;
#else
    bool operator==( AllocationInfo const& rhs ) const VKMA_NOEXCEPT
    {
      return ( memoryType == rhs.memoryType )
          && ( deviceMemory == rhs.deviceMemory )
          && ( offset == rhs.offset )
          && ( size == rhs.size )
          && ( pMappedData == rhs.pMappedData )
          && ( pUserData == rhs.pUserData );
    }

    bool operator!=( AllocationInfo const& rhs ) const VKMA_NOEXCEPT
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
  static_assert( sizeof( AllocationInfo ) == sizeof( VkmaAllocationInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<AllocationInfo>::value, "struct wrapper is not a standard layout!" );

  struct DeviceMemoryCallbacks
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR DeviceMemoryCallbacks(PFN_vkmaAllocateDeviceMemoryFunction pfnAllocate_ = {}, PFN_vkmaFreeDeviceMemoryFunction pfnFree_ = {}, void* pUserData_ = {}) VKMA_NOEXCEPT
    : pfnAllocate( pfnAllocate_ ), pfnFree( pfnFree_ ), pUserData( pUserData_ )
    {}

    VKMA_CONSTEXPR DeviceMemoryCallbacks( DeviceMemoryCallbacks const & rhs ) VKMA_NOEXCEPT = default;

    DeviceMemoryCallbacks( VkmaDeviceMemoryCallbacks const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    DeviceMemoryCallbacks & operator=( VkmaDeviceMemoryCallbacks const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::DeviceMemoryCallbacks const *>( &rhs );
      return *this;
    }

    DeviceMemoryCallbacks & operator=( DeviceMemoryCallbacks const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( DeviceMemoryCallbacks ) );
      return *this;
    }

    DeviceMemoryCallbacks & setPfnAllocate( PFN_vkmaAllocateDeviceMemoryFunction pfnAllocate_ ) VKMA_NOEXCEPT
    {
      pfnAllocate = pfnAllocate_;
      return *this;
    }

    DeviceMemoryCallbacks & setPfnFree( PFN_vkmaFreeDeviceMemoryFunction pfnFree_ ) VKMA_NOEXCEPT
    {
      pfnFree = pfnFree_;
      return *this;
    }

    DeviceMemoryCallbacks & setPUserData( void* pUserData_ ) VKMA_NOEXCEPT
    {
      pUserData = pUserData_;
      return *this;
    }


    operator VkmaDeviceMemoryCallbacks const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VkmaDeviceMemoryCallbacks*>( this );
    }

    operator VkmaDeviceMemoryCallbacks &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VkmaDeviceMemoryCallbacks*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( DeviceMemoryCallbacks const& ) const = default;
#else
    bool operator==( DeviceMemoryCallbacks const& rhs ) const VKMA_NOEXCEPT
    {
      return ( pfnAllocate == rhs.pfnAllocate )
          && ( pfnFree == rhs.pfnFree )
          && ( pUserData == rhs.pUserData );
    }

    bool operator!=( DeviceMemoryCallbacks const& rhs ) const VKMA_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    PFN_vkmaAllocateDeviceMemoryFunction pfnAllocate = {};
    PFN_vkmaFreeDeviceMemoryFunction pfnFree = {};
    void* pUserData = {};

  };
  static_assert( sizeof( DeviceMemoryCallbacks ) == sizeof( VkmaDeviceMemoryCallbacks ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<DeviceMemoryCallbacks>::value, "struct wrapper is not a standard layout!" );

  struct VulkanFunctions
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR VulkanFunctions(PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties_ = {}, PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties_ = {}, PFN_vkAllocateMemory vkAllocateMemory_ = {}, PFN_vkFreeMemory vkFreeMemory_ = {}, PFN_vkMapMemory vkMapMemory_ = {}, PFN_vkUnmapMemory vkUnmapMemory_ = {}, PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges_ = {}, PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges_ = {}, PFN_vkBindBufferMemory vkBindBufferMemory_ = {}, PFN_vkBindImageMemory vkBindImageMemory_ = {}, PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements_ = {}, PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements_ = {}, PFN_vkCreateBuffer vkCreateBuffer_ = {}, PFN_vkDestroyBuffer vkDestroyBuffer_ = {}, PFN_vkCreateImage vkCreateImage_ = {}, PFN_vkDestroyImage vkDestroyImage_ = {}, PFN_vkCmdCopyBuffer vkCmdCopyBuffer_ = {}) VKMA_NOEXCEPT
    : vkGetPhysicalDeviceProperties( vkGetPhysicalDeviceProperties_ ), vkGetPhysicalDeviceMemoryProperties( vkGetPhysicalDeviceMemoryProperties_ ), vkAllocateMemory( vkAllocateMemory_ ), vkFreeMemory( vkFreeMemory_ ), vkMapMemory( vkMapMemory_ ), vkUnmapMemory( vkUnmapMemory_ ), vkFlushMappedMemoryRanges( vkFlushMappedMemoryRanges_ ), vkInvalidateMappedMemoryRanges( vkInvalidateMappedMemoryRanges_ ), vkBindBufferMemory( vkBindBufferMemory_ ), vkBindImageMemory( vkBindImageMemory_ ), vkGetBufferMemoryRequirements( vkGetBufferMemoryRequirements_ ), vkGetImageMemoryRequirements( vkGetImageMemoryRequirements_ ), vkCreateBuffer( vkCreateBuffer_ ), vkDestroyBuffer( vkDestroyBuffer_ ), vkCreateImage( vkCreateImage_ ), vkDestroyImage( vkDestroyImage_ ), vkCmdCopyBuffer( vkCmdCopyBuffer_ )
    {}

    VKMA_CONSTEXPR VulkanFunctions( VulkanFunctions const & rhs ) VKMA_NOEXCEPT = default;

    VulkanFunctions( VkmaVulkanFunctions const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VulkanFunctions & operator=( VkmaVulkanFunctions const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::VulkanFunctions const *>( &rhs );
      return *this;
    }

    VulkanFunctions & operator=( VulkanFunctions const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( VulkanFunctions ) );
      return *this;
    }

    VulkanFunctions & setVkGetPhysicalDeviceProperties( PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties_ ) VKMA_NOEXCEPT
    {
      vkGetPhysicalDeviceProperties = vkGetPhysicalDeviceProperties_;
      return *this;
    }

    VulkanFunctions & setVkGetPhysicalDeviceMemoryProperties( PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties_ ) VKMA_NOEXCEPT
    {
      vkGetPhysicalDeviceMemoryProperties = vkGetPhysicalDeviceMemoryProperties_;
      return *this;
    }

    VulkanFunctions & setVkAllocateMemory( PFN_vkAllocateMemory vkAllocateMemory_ ) VKMA_NOEXCEPT
    {
      vkAllocateMemory = vkAllocateMemory_;
      return *this;
    }

    VulkanFunctions & setVkFreeMemory( PFN_vkFreeMemory vkFreeMemory_ ) VKMA_NOEXCEPT
    {
      vkFreeMemory = vkFreeMemory_;
      return *this;
    }

    VulkanFunctions & setVkMapMemory( PFN_vkMapMemory vkMapMemory_ ) VKMA_NOEXCEPT
    {
      vkMapMemory = vkMapMemory_;
      return *this;
    }

    VulkanFunctions & setVkUnmapMemory( PFN_vkUnmapMemory vkUnmapMemory_ ) VKMA_NOEXCEPT
    {
      vkUnmapMemory = vkUnmapMemory_;
      return *this;
    }

    VulkanFunctions & setVkFlushMappedMemoryRanges( PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges_ ) VKMA_NOEXCEPT
    {
      vkFlushMappedMemoryRanges = vkFlushMappedMemoryRanges_;
      return *this;
    }

    VulkanFunctions & setVkInvalidateMappedMemoryRanges( PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges_ ) VKMA_NOEXCEPT
    {
      vkInvalidateMappedMemoryRanges = vkInvalidateMappedMemoryRanges_;
      return *this;
    }

    VulkanFunctions & setVkBindBufferMemory( PFN_vkBindBufferMemory vkBindBufferMemory_ ) VKMA_NOEXCEPT
    {
      vkBindBufferMemory = vkBindBufferMemory_;
      return *this;
    }

    VulkanFunctions & setVkBindImageMemory( PFN_vkBindImageMemory vkBindImageMemory_ ) VKMA_NOEXCEPT
    {
      vkBindImageMemory = vkBindImageMemory_;
      return *this;
    }

    VulkanFunctions & setVkGetBufferMemoryRequirements( PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements_ ) VKMA_NOEXCEPT
    {
      vkGetBufferMemoryRequirements = vkGetBufferMemoryRequirements_;
      return *this;
    }

    VulkanFunctions & setVkGetImageMemoryRequirements( PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements_ ) VKMA_NOEXCEPT
    {
      vkGetImageMemoryRequirements = vkGetImageMemoryRequirements_;
      return *this;
    }

    VulkanFunctions & setVkCreateBuffer( PFN_vkCreateBuffer vkCreateBuffer_ ) VKMA_NOEXCEPT
    {
      vkCreateBuffer = vkCreateBuffer_;
      return *this;
    }

    VulkanFunctions & setVkDestroyBuffer( PFN_vkDestroyBuffer vkDestroyBuffer_ ) VKMA_NOEXCEPT
    {
      vkDestroyBuffer = vkDestroyBuffer_;
      return *this;
    }

    VulkanFunctions & setVkCreateImage( PFN_vkCreateImage vkCreateImage_ ) VKMA_NOEXCEPT
    {
      vkCreateImage = vkCreateImage_;
      return *this;
    }

    VulkanFunctions & setVkDestroyImage( PFN_vkDestroyImage vkDestroyImage_ ) VKMA_NOEXCEPT
    {
      vkDestroyImage = vkDestroyImage_;
      return *this;
    }

    VulkanFunctions & setVkCmdCopyBuffer( PFN_vkCmdCopyBuffer vkCmdCopyBuffer_ ) VKMA_NOEXCEPT
    {
      vkCmdCopyBuffer = vkCmdCopyBuffer_;
      return *this;
    }


    operator VkmaVulkanFunctions const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VkmaVulkanFunctions*>( this );
    }

    operator VkmaVulkanFunctions &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VkmaVulkanFunctions*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( VulkanFunctions const& ) const = default;
#else
    bool operator==( VulkanFunctions const& rhs ) const VKMA_NOEXCEPT
    {
      return ( vkGetPhysicalDeviceProperties == rhs.vkGetPhysicalDeviceProperties )
          && ( vkGetPhysicalDeviceMemoryProperties == rhs.vkGetPhysicalDeviceMemoryProperties )
          && ( vkAllocateMemory == rhs.vkAllocateMemory )
          && ( vkFreeMemory == rhs.vkFreeMemory )
          && ( vkMapMemory == rhs.vkMapMemory )
          && ( vkUnmapMemory == rhs.vkUnmapMemory )
          && ( vkFlushMappedMemoryRanges == rhs.vkFlushMappedMemoryRanges )
          && ( vkInvalidateMappedMemoryRanges == rhs.vkInvalidateMappedMemoryRanges )
          && ( vkBindBufferMemory == rhs.vkBindBufferMemory )
          && ( vkBindImageMemory == rhs.vkBindImageMemory )
          && ( vkGetBufferMemoryRequirements == rhs.vkGetBufferMemoryRequirements )
          && ( vkGetImageMemoryRequirements == rhs.vkGetImageMemoryRequirements )
          && ( vkCreateBuffer == rhs.vkCreateBuffer )
          && ( vkDestroyBuffer == rhs.vkDestroyBuffer )
          && ( vkCreateImage == rhs.vkCreateImage )
          && ( vkDestroyImage == rhs.vkDestroyImage )
          && ( vkCmdCopyBuffer == rhs.vkCmdCopyBuffer );
    }

    bool operator!=( VulkanFunctions const& rhs ) const VKMA_NOEXCEPT
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
  static_assert( sizeof( VulkanFunctions ) == sizeof( VkmaVulkanFunctions ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<VulkanFunctions>::value, "struct wrapper is not a standard layout!" );

  struct RecordSettings
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR RecordSettings(RecordFlags flags_ = {}, const char* pFilePath_ = {}) VKMA_NOEXCEPT
    : flags( flags_ ), pFilePath( pFilePath_ )
    {}

    VKMA_CONSTEXPR RecordSettings( RecordSettings const & rhs ) VKMA_NOEXCEPT = default;

    RecordSettings( VkmaRecordSettings const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    RecordSettings & operator=( VkmaRecordSettings const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::RecordSettings const *>( &rhs );
      return *this;
    }

    RecordSettings & operator=( RecordSettings const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( RecordSettings ) );
      return *this;
    }

    RecordSettings & setFlags( RecordFlags flags_ ) VKMA_NOEXCEPT
    {
      flags = flags_;
      return *this;
    }

    RecordSettings & setPFilePath( const char* pFilePath_ ) VKMA_NOEXCEPT
    {
      pFilePath = pFilePath_;
      return *this;
    }


    operator VkmaRecordSettings const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VkmaRecordSettings*>( this );
    }

    operator VkmaRecordSettings &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VkmaRecordSettings*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( RecordSettings const& ) const = default;
#else
    bool operator==( RecordSettings const& rhs ) const VKMA_NOEXCEPT
    {
      return ( flags == rhs.flags )
          && ( pFilePath == rhs.pFilePath );
    }

    bool operator!=( RecordSettings const& rhs ) const VKMA_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    RecordFlags flags = {};
    const char* pFilePath = {};

  };
  static_assert( sizeof( RecordSettings ) == sizeof( VkmaRecordSettings ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<RecordSettings>::value, "struct wrapper is not a standard layout!" );

  struct AllocatorCreateInfo
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR AllocatorCreateInfo(AllocatorCreateFlags flags_ = {}, VkPhysicalDevice physicalDevice_ = {}, VkDevice device_ = {}, VkDeviceSize preferredLargeHeapBlockSize_ = {}, const VkAllocationCallbacks* pAllocationCallbacks_ = {}, const DeviceMemoryCallbacks* pDeviceMemoryCallbacks_ = {}, uint32_t frameInUseCount_ = {}, const VkDeviceSize* pHeapSizeLimit_ = {}, const VulkanFunctions* pVulkanFunctions_ = {}, const RecordSettings* pRecordSettings_ = {}, VkInstance instance_ = {}, uint32_t vulkanApiVersion_ = {}) VKMA_NOEXCEPT
    : flags( flags_ ), physicalDevice( physicalDevice_ ), device( device_ ), preferredLargeHeapBlockSize( preferredLargeHeapBlockSize_ ), pAllocationCallbacks( pAllocationCallbacks_ ), pDeviceMemoryCallbacks( pDeviceMemoryCallbacks_ ), frameInUseCount( frameInUseCount_ ), pHeapSizeLimit( pHeapSizeLimit_ ), pVulkanFunctions( pVulkanFunctions_ ), pRecordSettings( pRecordSettings_ ), instance( instance_ ), vulkanApiVersion( vulkanApiVersion_ )
    {}

    VKMA_CONSTEXPR AllocatorCreateInfo( AllocatorCreateInfo const & rhs ) VKMA_NOEXCEPT = default;

    AllocatorCreateInfo( VkmaAllocatorCreateInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    AllocatorCreateInfo & operator=( VkmaAllocatorCreateInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::AllocatorCreateInfo const *>( &rhs );
      return *this;
    }

    AllocatorCreateInfo & operator=( AllocatorCreateInfo const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( AllocatorCreateInfo ) );
      return *this;
    }

    AllocatorCreateInfo & setFlags( AllocatorCreateFlags flags_ ) VKMA_NOEXCEPT
    {
      flags = flags_;
      return *this;
    }

    AllocatorCreateInfo & setPhysicalDevice( VkPhysicalDevice physicalDevice_ ) VKMA_NOEXCEPT
    {
      physicalDevice = physicalDevice_;
      return *this;
    }

    AllocatorCreateInfo & setDevice( VkDevice device_ ) VKMA_NOEXCEPT
    {
      device = device_;
      return *this;
    }

    AllocatorCreateInfo & setPreferredLargeHeapBlockSize( VkDeviceSize preferredLargeHeapBlockSize_ ) VKMA_NOEXCEPT
    {
      preferredLargeHeapBlockSize = preferredLargeHeapBlockSize_;
      return *this;
    }

    AllocatorCreateInfo & setPAllocationCallbacks( const VkAllocationCallbacks* pAllocationCallbacks_ ) VKMA_NOEXCEPT
    {
      pAllocationCallbacks = pAllocationCallbacks_;
      return *this;
    }

    AllocatorCreateInfo & setPDeviceMemoryCallbacks( const DeviceMemoryCallbacks* pDeviceMemoryCallbacks_ ) VKMA_NOEXCEPT
    {
      pDeviceMemoryCallbacks = pDeviceMemoryCallbacks_;
      return *this;
    }

    AllocatorCreateInfo & setFrameInUseCount( uint32_t frameInUseCount_ ) VKMA_NOEXCEPT
    {
      frameInUseCount = frameInUseCount_;
      return *this;
    }

    AllocatorCreateInfo & setPHeapSizeLimit( const VkDeviceSize* pHeapSizeLimit_ ) VKMA_NOEXCEPT
    {
      pHeapSizeLimit = pHeapSizeLimit_;
      return *this;
    }

    AllocatorCreateInfo & setPVulkanFunctions( const VulkanFunctions* pVulkanFunctions_ ) VKMA_NOEXCEPT
    {
      pVulkanFunctions = pVulkanFunctions_;
      return *this;
    }

    AllocatorCreateInfo & setPRecordSettings( const RecordSettings* pRecordSettings_ ) VKMA_NOEXCEPT
    {
      pRecordSettings = pRecordSettings_;
      return *this;
    }

    AllocatorCreateInfo & setInstance( VkInstance instance_ ) VKMA_NOEXCEPT
    {
      instance = instance_;
      return *this;
    }

    AllocatorCreateInfo & setVulkanApiVersion( uint32_t vulkanApiVersion_ ) VKMA_NOEXCEPT
    {
      vulkanApiVersion = vulkanApiVersion_;
      return *this;
    }


    operator VkmaAllocatorCreateInfo const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VkmaAllocatorCreateInfo*>( this );
    }

    operator VkmaAllocatorCreateInfo &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VkmaAllocatorCreateInfo*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( AllocatorCreateInfo const& ) const = default;
#else
    bool operator==( AllocatorCreateInfo const& rhs ) const VKMA_NOEXCEPT
    {
      return ( flags == rhs.flags )
          && ( physicalDevice == rhs.physicalDevice )
          && ( device == rhs.device )
          && ( preferredLargeHeapBlockSize == rhs.preferredLargeHeapBlockSize )
          && ( pAllocationCallbacks == rhs.pAllocationCallbacks )
          && ( pDeviceMemoryCallbacks == rhs.pDeviceMemoryCallbacks )
          && ( frameInUseCount == rhs.frameInUseCount )
          && ( pHeapSizeLimit == rhs.pHeapSizeLimit )
          && ( pVulkanFunctions == rhs.pVulkanFunctions )
          && ( pRecordSettings == rhs.pRecordSettings )
          && ( instance == rhs.instance )
          && ( vulkanApiVersion == rhs.vulkanApiVersion );
    }

    bool operator!=( AllocatorCreateInfo const& rhs ) const VKMA_NOEXCEPT
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
  static_assert( sizeof( AllocatorCreateInfo ) == sizeof( VkmaAllocatorCreateInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<AllocatorCreateInfo>::value, "struct wrapper is not a standard layout!" );

  struct Budget
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR Budget(VkDeviceSize blockBytes_ = {}, VkDeviceSize allocationBytes_ = {}, VkDeviceSize usage_ = {}, VkDeviceSize budget_ = {}) VKMA_NOEXCEPT
    : blockBytes( blockBytes_ ), allocationBytes( allocationBytes_ ), usage( usage_ ), budget( budget_ )
    {}

    VKMA_CONSTEXPR Budget( Budget const & rhs ) VKMA_NOEXCEPT = default;

    Budget( VkmaBudget const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    Budget & operator=( VkmaBudget const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::Budget const *>( &rhs );
      return *this;
    }

    Budget & operator=( Budget const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( Budget ) );
      return *this;
    }

    Budget & setBlockBytes( VkDeviceSize blockBytes_ ) VKMA_NOEXCEPT
    {
      blockBytes = blockBytes_;
      return *this;
    }

    Budget & setAllocationBytes( VkDeviceSize allocationBytes_ ) VKMA_NOEXCEPT
    {
      allocationBytes = allocationBytes_;
      return *this;
    }

    Budget & setUsage( VkDeviceSize usage_ ) VKMA_NOEXCEPT
    {
      usage = usage_;
      return *this;
    }

    Budget & setBudget( VkDeviceSize budget_ ) VKMA_NOEXCEPT
    {
      budget = budget_;
      return *this;
    }


    operator VkmaBudget const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VkmaBudget*>( this );
    }

    operator VkmaBudget &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VkmaBudget*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( Budget const& ) const = default;
#else
    bool operator==( Budget const& rhs ) const VKMA_NOEXCEPT
    {
      return ( blockBytes == rhs.blockBytes )
          && ( allocationBytes == rhs.allocationBytes )
          && ( usage == rhs.usage )
          && ( budget == rhs.budget );
    }

    bool operator!=( Budget const& rhs ) const VKMA_NOEXCEPT
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
  static_assert( sizeof( Budget ) == sizeof( VkmaBudget ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<Budget>::value, "struct wrapper is not a standard layout!" );

  class Allocation
  {
  public:
    using CType = VkmaAllocation;


  public:
    VKMA_CONSTEXPR Allocation() VKMA_NOEXCEPT
      : m_allocation(VKMA_NULL_HANDLE)
    {}

    VKMA_CONSTEXPR Allocation( std::nullptr_t ) VKMA_NOEXCEPT
      : m_allocation(VKMA_NULL_HANDLE)
    {}

    VKMA_TYPESAFE_EXPLICIT Allocation( VkmaAllocation allocation ) VKMA_NOEXCEPT
      : m_allocation( allocation )
    {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    Allocation & operator=(VkmaAllocation allocation) VKMA_NOEXCEPT
    {
      m_allocation = allocation;
      return *this;
    }
#endif

    Allocation & operator=( std::nullptr_t ) VKMA_NOEXCEPT
    {
      m_allocation = VKMA_NULL_HANDLE;
      return *this;
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( Allocation const& ) const = default;
#else
    bool operator==( Allocation const & rhs ) const VKMA_NOEXCEPT
    {
      return m_allocation == rhs.m_allocation;
    }

    bool operator!=(Allocation const & rhs ) const VKMA_NOEXCEPT
    {
      return m_allocation != rhs.m_allocation;
    }

    bool operator<(Allocation const & rhs ) const VKMA_NOEXCEPT
    {
      return m_allocation < rhs.m_allocation;
    }
#endif

    VKMA_TYPESAFE_EXPLICIT operator VkmaAllocation() const VKMA_NOEXCEPT
    {
      return m_allocation;
    }

    explicit operator bool() const VKMA_NOEXCEPT
    {
      return m_allocation != VKMA_NULL_HANDLE;
    }

    bool operator!() const VKMA_NOEXCEPT
    {
      return m_allocation == VKMA_NULL_HANDLE;
    }

  private:
    VkmaAllocation m_allocation;
  };
  static_assert( sizeof( VKMA_NAMESPACE::Allocation ) == sizeof( VkmaAllocation ), "handle and wrapper have different size!" );


  template <>
  struct isVulkanHandleType<VKMA_NAMESPACE::Allocation>
  {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

  struct DefragmentationInfo2
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR DefragmentationInfo2(DefragmentationFlags flags_ = {}, uint32_t allocationCount_ = {}, const Allocation* pAllocations_ = {}, VkBool32* pAllocationsChanged_ = {}, uint32_t poolCount_ = {}, const Pool* pPools_ = {}, VkDeviceSize maxCpuBytesToMove_ = {}, uint32_t maxCpuAllocationsToMove_ = {}, VkDeviceSize maxGpuBytesToMove_ = {}, uint32_t maxGpuAllocationsToMove_ = {}, VkCommandBuffer commandBuffer_ = {}) VKMA_NOEXCEPT
    : flags( flags_ ), allocationCount( allocationCount_ ), pAllocations( pAllocations_ ), pAllocationsChanged( pAllocationsChanged_ ), poolCount( poolCount_ ), pPools( pPools_ ), maxCpuBytesToMove( maxCpuBytesToMove_ ), maxCpuAllocationsToMove( maxCpuAllocationsToMove_ ), maxGpuBytesToMove( maxGpuBytesToMove_ ), maxGpuAllocationsToMove( maxGpuAllocationsToMove_ ), commandBuffer( commandBuffer_ )
    {}

    VKMA_CONSTEXPR DefragmentationInfo2( DefragmentationInfo2 const & rhs ) VKMA_NOEXCEPT = default;

    DefragmentationInfo2( VkmaDefragmentationInfo2 const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    DefragmentationInfo2 & operator=( VkmaDefragmentationInfo2 const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::DefragmentationInfo2 const *>( &rhs );
      return *this;
    }

    DefragmentationInfo2 & operator=( DefragmentationInfo2 const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( DefragmentationInfo2 ) );
      return *this;
    }

    DefragmentationInfo2 & setFlags( DefragmentationFlags flags_ ) VKMA_NOEXCEPT
    {
      flags = flags_;
      return *this;
    }

    DefragmentationInfo2 & setAllocationCount( uint32_t allocationCount_ ) VKMA_NOEXCEPT
    {
      allocationCount = allocationCount_;
      return *this;
    }

    DefragmentationInfo2 & setPAllocations( const Allocation* pAllocations_ ) VKMA_NOEXCEPT
    {
      pAllocations = pAllocations_;
      return *this;
    }

    DefragmentationInfo2 & setPAllocationsChanged( VkBool32* pAllocationsChanged_ ) VKMA_NOEXCEPT
    {
      pAllocationsChanged = pAllocationsChanged_;
      return *this;
    }

    DefragmentationInfo2 & setPoolCount( uint32_t poolCount_ ) VKMA_NOEXCEPT
    {
      poolCount = poolCount_;
      return *this;
    }

    DefragmentationInfo2 & setPPools( const Pool* pPools_ ) VKMA_NOEXCEPT
    {
      pPools = pPools_;
      return *this;
    }

    DefragmentationInfo2 & setMaxCpuBytesToMove( VkDeviceSize maxCpuBytesToMove_ ) VKMA_NOEXCEPT
    {
      maxCpuBytesToMove = maxCpuBytesToMove_;
      return *this;
    }

    DefragmentationInfo2 & setMaxCpuAllocationsToMove( uint32_t maxCpuAllocationsToMove_ ) VKMA_NOEXCEPT
    {
      maxCpuAllocationsToMove = maxCpuAllocationsToMove_;
      return *this;
    }

    DefragmentationInfo2 & setMaxGpuBytesToMove( VkDeviceSize maxGpuBytesToMove_ ) VKMA_NOEXCEPT
    {
      maxGpuBytesToMove = maxGpuBytesToMove_;
      return *this;
    }

    DefragmentationInfo2 & setMaxGpuAllocationsToMove( uint32_t maxGpuAllocationsToMove_ ) VKMA_NOEXCEPT
    {
      maxGpuAllocationsToMove = maxGpuAllocationsToMove_;
      return *this;
    }

    DefragmentationInfo2 & setCommandBuffer( VkCommandBuffer commandBuffer_ ) VKMA_NOEXCEPT
    {
      commandBuffer = commandBuffer_;
      return *this;
    }


    operator VkmaDefragmentationInfo2 const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VkmaDefragmentationInfo2*>( this );
    }

    operator VkmaDefragmentationInfo2 &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VkmaDefragmentationInfo2*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( DefragmentationInfo2 const& ) const = default;
#else
    bool operator==( DefragmentationInfo2 const& rhs ) const VKMA_NOEXCEPT
    {
      return ( flags == rhs.flags )
          && ( allocationCount == rhs.allocationCount )
          && ( pAllocations == rhs.pAllocations )
          && ( pAllocationsChanged == rhs.pAllocationsChanged )
          && ( poolCount == rhs.poolCount )
          && ( pPools == rhs.pPools )
          && ( maxCpuBytesToMove == rhs.maxCpuBytesToMove )
          && ( maxCpuAllocationsToMove == rhs.maxCpuAllocationsToMove )
          && ( maxGpuBytesToMove == rhs.maxGpuBytesToMove )
          && ( maxGpuAllocationsToMove == rhs.maxGpuAllocationsToMove )
          && ( commandBuffer == rhs.commandBuffer );
    }

    bool operator!=( DefragmentationInfo2 const& rhs ) const VKMA_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    DefragmentationFlags flags = {};
    uint32_t allocationCount = {};
    const Allocation* pAllocations = {};
    VkBool32* pAllocationsChanged = {};
    uint32_t poolCount = {};
    const Pool* pPools = {};
    VkDeviceSize maxCpuBytesToMove = {};
    uint32_t maxCpuAllocationsToMove = {};
    VkDeviceSize maxGpuBytesToMove = {};
    uint32_t maxGpuAllocationsToMove = {};
    VkCommandBuffer commandBuffer = {};

  };
  static_assert( sizeof( DefragmentationInfo2 ) == sizeof( VkmaDefragmentationInfo2 ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<DefragmentationInfo2>::value, "struct wrapper is not a standard layout!" );

  struct DefragmentationStats
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR DefragmentationStats(VkDeviceSize bytesMoved_ = {}, VkDeviceSize bytesFreed_ = {}, uint32_t allocationsMoved_ = {}, uint32_t deviceMemoryBlocksFreed_ = {}) VKMA_NOEXCEPT
    : bytesMoved( bytesMoved_ ), bytesFreed( bytesFreed_ ), allocationsMoved( allocationsMoved_ ), deviceMemoryBlocksFreed( deviceMemoryBlocksFreed_ )
    {}

    VKMA_CONSTEXPR DefragmentationStats( DefragmentationStats const & rhs ) VKMA_NOEXCEPT = default;

    DefragmentationStats( VkmaDefragmentationStats const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    DefragmentationStats & operator=( VkmaDefragmentationStats const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::DefragmentationStats const *>( &rhs );
      return *this;
    }

    DefragmentationStats & operator=( DefragmentationStats const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( DefragmentationStats ) );
      return *this;
    }

    DefragmentationStats & setBytesMoved( VkDeviceSize bytesMoved_ ) VKMA_NOEXCEPT
    {
      bytesMoved = bytesMoved_;
      return *this;
    }

    DefragmentationStats & setBytesFreed( VkDeviceSize bytesFreed_ ) VKMA_NOEXCEPT
    {
      bytesFreed = bytesFreed_;
      return *this;
    }

    DefragmentationStats & setAllocationsMoved( uint32_t allocationsMoved_ ) VKMA_NOEXCEPT
    {
      allocationsMoved = allocationsMoved_;
      return *this;
    }

    DefragmentationStats & setDeviceMemoryBlocksFreed( uint32_t deviceMemoryBlocksFreed_ ) VKMA_NOEXCEPT
    {
      deviceMemoryBlocksFreed = deviceMemoryBlocksFreed_;
      return *this;
    }


    operator VkmaDefragmentationStats const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VkmaDefragmentationStats*>( this );
    }

    operator VkmaDefragmentationStats &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VkmaDefragmentationStats*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( DefragmentationStats const& ) const = default;
#else
    bool operator==( DefragmentationStats const& rhs ) const VKMA_NOEXCEPT
    {
      return ( bytesMoved == rhs.bytesMoved )
          && ( bytesFreed == rhs.bytesFreed )
          && ( allocationsMoved == rhs.allocationsMoved )
          && ( deviceMemoryBlocksFreed == rhs.deviceMemoryBlocksFreed );
    }

    bool operator!=( DefragmentationStats const& rhs ) const VKMA_NOEXCEPT
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
  static_assert( sizeof( DefragmentationStats ) == sizeof( VkmaDefragmentationStats ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<DefragmentationStats>::value, "struct wrapper is not a standard layout!" );

  struct PoolCreateInfo
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR PoolCreateInfo(uint32_t memoryTypeIndex_ = {}, PoolCreateFlags flags_ = {}, VkDeviceSize blockSize_ = {}, size_t minBlockCount_ = {}, size_t maxBlockCount_ = {}, uint32_t frameInUseCount_ = {}, float priority_ = {}) VKMA_NOEXCEPT
    : memoryTypeIndex( memoryTypeIndex_ ), flags( flags_ ), blockSize( blockSize_ ), minBlockCount( minBlockCount_ ), maxBlockCount( maxBlockCount_ ), frameInUseCount( frameInUseCount_ ), priority( priority_ )
    {}

    VKMA_CONSTEXPR PoolCreateInfo( PoolCreateInfo const & rhs ) VKMA_NOEXCEPT = default;

    PoolCreateInfo( VkmaPoolCreateInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    PoolCreateInfo & operator=( VkmaPoolCreateInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::PoolCreateInfo const *>( &rhs );
      return *this;
    }

    PoolCreateInfo & operator=( PoolCreateInfo const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( PoolCreateInfo ) );
      return *this;
    }

    PoolCreateInfo & setMemoryTypeIndex( uint32_t memoryTypeIndex_ ) VKMA_NOEXCEPT
    {
      memoryTypeIndex = memoryTypeIndex_;
      return *this;
    }

    PoolCreateInfo & setFlags( PoolCreateFlags flags_ ) VKMA_NOEXCEPT
    {
      flags = flags_;
      return *this;
    }

    PoolCreateInfo & setBlockSize( VkDeviceSize blockSize_ ) VKMA_NOEXCEPT
    {
      blockSize = blockSize_;
      return *this;
    }

    PoolCreateInfo & setMinBlockCount( size_t minBlockCount_ ) VKMA_NOEXCEPT
    {
      minBlockCount = minBlockCount_;
      return *this;
    }

    PoolCreateInfo & setMaxBlockCount( size_t maxBlockCount_ ) VKMA_NOEXCEPT
    {
      maxBlockCount = maxBlockCount_;
      return *this;
    }

    PoolCreateInfo & setFrameInUseCount( uint32_t frameInUseCount_ ) VKMA_NOEXCEPT
    {
      frameInUseCount = frameInUseCount_;
      return *this;
    }

    PoolCreateInfo & setPriority( float priority_ ) VKMA_NOEXCEPT
    {
      priority = priority_;
      return *this;
    }


    operator VkmaPoolCreateInfo const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VkmaPoolCreateInfo*>( this );
    }

    operator VkmaPoolCreateInfo &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VkmaPoolCreateInfo*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( PoolCreateInfo const& ) const = default;
#else
    bool operator==( PoolCreateInfo const& rhs ) const VKMA_NOEXCEPT
    {
      return ( memoryTypeIndex == rhs.memoryTypeIndex )
          && ( flags == rhs.flags )
          && ( blockSize == rhs.blockSize )
          && ( minBlockCount == rhs.minBlockCount )
          && ( maxBlockCount == rhs.maxBlockCount )
          && ( frameInUseCount == rhs.frameInUseCount )
          && ( priority == rhs.priority );
    }

    bool operator!=( PoolCreateInfo const& rhs ) const VKMA_NOEXCEPT
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
    float priority = {};

  };
  static_assert( sizeof( PoolCreateInfo ) == sizeof( VkmaPoolCreateInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<PoolCreateInfo>::value, "struct wrapper is not a standard layout!" );

  struct PoolStats
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR PoolStats(VkDeviceSize size_ = {}, VkDeviceSize unusedSize_ = {}, size_t allocationCount_ = {}, size_t unusedRangeCount_ = {}, VkDeviceSize unusedRangeSizeMax_ = {}, size_t blockCount_ = {}) VKMA_NOEXCEPT
    : size( size_ ), unusedSize( unusedSize_ ), allocationCount( allocationCount_ ), unusedRangeCount( unusedRangeCount_ ), unusedRangeSizeMax( unusedRangeSizeMax_ ), blockCount( blockCount_ )
    {}

    VKMA_CONSTEXPR PoolStats( PoolStats const & rhs ) VKMA_NOEXCEPT = default;

    PoolStats( VkmaPoolStats const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    PoolStats & operator=( VkmaPoolStats const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::PoolStats const *>( &rhs );
      return *this;
    }

    PoolStats & operator=( PoolStats const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( PoolStats ) );
      return *this;
    }

    PoolStats & setSize( VkDeviceSize size_ ) VKMA_NOEXCEPT
    {
      size = size_;
      return *this;
    }

    PoolStats & setUnusedSize( VkDeviceSize unusedSize_ ) VKMA_NOEXCEPT
    {
      unusedSize = unusedSize_;
      return *this;
    }

    PoolStats & setAllocationCount( size_t allocationCount_ ) VKMA_NOEXCEPT
    {
      allocationCount = allocationCount_;
      return *this;
    }

    PoolStats & setUnusedRangeCount( size_t unusedRangeCount_ ) VKMA_NOEXCEPT
    {
      unusedRangeCount = unusedRangeCount_;
      return *this;
    }

    PoolStats & setUnusedRangeSizeMax( VkDeviceSize unusedRangeSizeMax_ ) VKMA_NOEXCEPT
    {
      unusedRangeSizeMax = unusedRangeSizeMax_;
      return *this;
    }

    PoolStats & setBlockCount( size_t blockCount_ ) VKMA_NOEXCEPT
    {
      blockCount = blockCount_;
      return *this;
    }


    operator VkmaPoolStats const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VkmaPoolStats*>( this );
    }

    operator VkmaPoolStats &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VkmaPoolStats*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( PoolStats const& ) const = default;
#else
    bool operator==( PoolStats const& rhs ) const VKMA_NOEXCEPT
    {
      return ( size == rhs.size )
          && ( unusedSize == rhs.unusedSize )
          && ( allocationCount == rhs.allocationCount )
          && ( unusedRangeCount == rhs.unusedRangeCount )
          && ( unusedRangeSizeMax == rhs.unusedRangeSizeMax )
          && ( blockCount == rhs.blockCount );
    }

    bool operator!=( PoolStats const& rhs ) const VKMA_NOEXCEPT
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
  static_assert( sizeof( PoolStats ) == sizeof( VkmaPoolStats ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<PoolStats>::value, "struct wrapper is not a standard layout!" );

  struct StatInfo
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR StatInfo(uint32_t blockCount_ = {}, uint32_t allocationCount_ = {}, uint32_t unusedRangeCount_ = {}, VkDeviceSize usedBytes_ = {}, VkDeviceSize unusedBytes_ = {}, VkDeviceSize allocationSizeMin_ = {}, VkDeviceSize allocationSizeAvg_ = {}, VkDeviceSize allocationSizeMax_ = {}, VkDeviceSize unusedRangeSizeMin_ = {}, VkDeviceSize unusedRangeSizeAvg_ = {}, VkDeviceSize unusedRangeSizeMax_ = {}) VKMA_NOEXCEPT
    : blockCount( blockCount_ ), allocationCount( allocationCount_ ), unusedRangeCount( unusedRangeCount_ ), usedBytes( usedBytes_ ), unusedBytes( unusedBytes_ ), allocationSizeMin( allocationSizeMin_ ), allocationSizeAvg( allocationSizeAvg_ ), allocationSizeMax( allocationSizeMax_ ), unusedRangeSizeMin( unusedRangeSizeMin_ ), unusedRangeSizeAvg( unusedRangeSizeAvg_ ), unusedRangeSizeMax( unusedRangeSizeMax_ )
    {}

    VKMA_CONSTEXPR StatInfo( StatInfo const & rhs ) VKMA_NOEXCEPT = default;

    StatInfo( VkmaStatInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    StatInfo & operator=( VkmaStatInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::StatInfo const *>( &rhs );
      return *this;
    }

    StatInfo & operator=( StatInfo const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( StatInfo ) );
      return *this;
    }

    StatInfo & setBlockCount( uint32_t blockCount_ ) VKMA_NOEXCEPT
    {
      blockCount = blockCount_;
      return *this;
    }

    StatInfo & setAllocationCount( uint32_t allocationCount_ ) VKMA_NOEXCEPT
    {
      allocationCount = allocationCount_;
      return *this;
    }

    StatInfo & setUnusedRangeCount( uint32_t unusedRangeCount_ ) VKMA_NOEXCEPT
    {
      unusedRangeCount = unusedRangeCount_;
      return *this;
    }

    StatInfo & setUsedBytes( VkDeviceSize usedBytes_ ) VKMA_NOEXCEPT
    {
      usedBytes = usedBytes_;
      return *this;
    }

    StatInfo & setUnusedBytes( VkDeviceSize unusedBytes_ ) VKMA_NOEXCEPT
    {
      unusedBytes = unusedBytes_;
      return *this;
    }

    StatInfo & setAllocationSizeMin( VkDeviceSize allocationSizeMin_ ) VKMA_NOEXCEPT
    {
      allocationSizeMin = allocationSizeMin_;
      return *this;
    }

    StatInfo & setAllocationSizeAvg( VkDeviceSize allocationSizeAvg_ ) VKMA_NOEXCEPT
    {
      allocationSizeAvg = allocationSizeAvg_;
      return *this;
    }

    StatInfo & setAllocationSizeMax( VkDeviceSize allocationSizeMax_ ) VKMA_NOEXCEPT
    {
      allocationSizeMax = allocationSizeMax_;
      return *this;
    }

    StatInfo & setUnusedRangeSizeMin( VkDeviceSize unusedRangeSizeMin_ ) VKMA_NOEXCEPT
    {
      unusedRangeSizeMin = unusedRangeSizeMin_;
      return *this;
    }

    StatInfo & setUnusedRangeSizeAvg( VkDeviceSize unusedRangeSizeAvg_ ) VKMA_NOEXCEPT
    {
      unusedRangeSizeAvg = unusedRangeSizeAvg_;
      return *this;
    }

    StatInfo & setUnusedRangeSizeMax( VkDeviceSize unusedRangeSizeMax_ ) VKMA_NOEXCEPT
    {
      unusedRangeSizeMax = unusedRangeSizeMax_;
      return *this;
    }


    operator VkmaStatInfo const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VkmaStatInfo*>( this );
    }

    operator VkmaStatInfo &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VkmaStatInfo*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( StatInfo const& ) const = default;
#else
    bool operator==( StatInfo const& rhs ) const VKMA_NOEXCEPT
    {
      return ( blockCount == rhs.blockCount )
          && ( allocationCount == rhs.allocationCount )
          && ( unusedRangeCount == rhs.unusedRangeCount )
          && ( usedBytes == rhs.usedBytes )
          && ( unusedBytes == rhs.unusedBytes )
          && ( allocationSizeMin == rhs.allocationSizeMin )
          && ( allocationSizeAvg == rhs.allocationSizeAvg )
          && ( allocationSizeMax == rhs.allocationSizeMax )
          && ( unusedRangeSizeMin == rhs.unusedRangeSizeMin )
          && ( unusedRangeSizeAvg == rhs.unusedRangeSizeAvg )
          && ( unusedRangeSizeMax == rhs.unusedRangeSizeMax );
    }

    bool operator!=( StatInfo const& rhs ) const VKMA_NOEXCEPT
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
  static_assert( sizeof( StatInfo ) == sizeof( VkmaStatInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<StatInfo>::value, "struct wrapper is not a standard layout!" );

  struct Stats
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR Stats(StatInfo memoryType_ = {}, StatInfo memoryHeap_ = {}, StatInfo total_ = {}) VKMA_NOEXCEPT
    : memoryType( memoryType_ ), memoryHeap( memoryHeap_ ), total( total_ )
    {}

    VKMA_CONSTEXPR Stats( Stats const & rhs ) VKMA_NOEXCEPT = default;

    Stats( VkmaStats const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    Stats & operator=( VkmaStats const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::Stats const *>( &rhs );
      return *this;
    }

    Stats & operator=( Stats const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( Stats ) );
      return *this;
    }

    Stats & setMemoryType( StatInfo const & memoryType_ ) VKMA_NOEXCEPT
    {
      memoryType = memoryType_;
      return *this;
    }

    Stats & setMemoryHeap( StatInfo const & memoryHeap_ ) VKMA_NOEXCEPT
    {
      memoryHeap = memoryHeap_;
      return *this;
    }

    Stats & setTotal( StatInfo const & total_ ) VKMA_NOEXCEPT
    {
      total = total_;
      return *this;
    }


    operator VkmaStats const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VkmaStats*>( this );
    }

    operator VkmaStats &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VkmaStats*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( Stats const& ) const = default;
#else
    bool operator==( Stats const& rhs ) const VKMA_NOEXCEPT
    {
      return ( memoryType == rhs.memoryType )
          && ( memoryHeap == rhs.memoryHeap )
          && ( total == rhs.total );
    }

    bool operator!=( Stats const& rhs ) const VKMA_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    StatInfo memoryType = {};
    StatInfo memoryHeap = {};
    StatInfo total = {};

  };
  static_assert( sizeof( Stats ) == sizeof( VkmaStats ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<Stats>::value, "struct wrapper is not a standard layout!" );

  class Buffer
  {
  public:
    using CType = VkmaBuffer;


  public:
    VKMA_CONSTEXPR Buffer() VKMA_NOEXCEPT
      : m_buffer(VKMA_NULL_HANDLE)
    {}

    VKMA_CONSTEXPR Buffer( std::nullptr_t ) VKMA_NOEXCEPT
      : m_buffer(VKMA_NULL_HANDLE)
    {}

    VKMA_TYPESAFE_EXPLICIT Buffer( VkmaBuffer buffer ) VKMA_NOEXCEPT
      : m_buffer( buffer )
    {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    Buffer & operator=(VkmaBuffer buffer) VKMA_NOEXCEPT
    {
      m_buffer = buffer;
      return *this;
    }
#endif

    Buffer & operator=( std::nullptr_t ) VKMA_NOEXCEPT
    {
      m_buffer = VKMA_NULL_HANDLE;
      return *this;
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( Buffer const& ) const = default;
#else
    bool operator==( Buffer const & rhs ) const VKMA_NOEXCEPT
    {
      return m_buffer == rhs.m_buffer;
    }

    bool operator!=(Buffer const & rhs ) const VKMA_NOEXCEPT
    {
      return m_buffer != rhs.m_buffer;
    }

    bool operator<(Buffer const & rhs ) const VKMA_NOEXCEPT
    {
      return m_buffer < rhs.m_buffer;
    }
#endif


  void get( VkBuffer* pBuffer ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VkBuffer get(  ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  void getAllocation( Allocation* pAllocation ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_NAMESPACE::Allocation getAllocation(  ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_TYPESAFE_EXPLICIT operator VkmaBuffer() const VKMA_NOEXCEPT
    {
      return m_buffer;
    }

    explicit operator bool() const VKMA_NOEXCEPT
    {
      return m_buffer != VKMA_NULL_HANDLE;
    }

    bool operator!() const VKMA_NOEXCEPT
    {
      return m_buffer == VKMA_NULL_HANDLE;
    }

  private:
    VkmaBuffer m_buffer;
  };
  static_assert( sizeof( VKMA_NAMESPACE::Buffer ) == sizeof( VkmaBuffer ), "handle and wrapper have different size!" );


  template <>
  struct isVulkanHandleType<VKMA_NAMESPACE::Buffer>
  {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

  class DefragmentationContext
  {
  public:
    using CType = VkmaDefragmentationContext;


  public:
    VKMA_CONSTEXPR DefragmentationContext() VKMA_NOEXCEPT
      : m_defragmentationContext(VKMA_NULL_HANDLE)
    {}

    VKMA_CONSTEXPR DefragmentationContext( std::nullptr_t ) VKMA_NOEXCEPT
      : m_defragmentationContext(VKMA_NULL_HANDLE)
    {}

    VKMA_TYPESAFE_EXPLICIT DefragmentationContext( VkmaDefragmentationContext defragmentationContext ) VKMA_NOEXCEPT
      : m_defragmentationContext( defragmentationContext )
    {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    DefragmentationContext & operator=(VkmaDefragmentationContext defragmentationContext) VKMA_NOEXCEPT
    {
      m_defragmentationContext = defragmentationContext;
      return *this;
    }
#endif

    DefragmentationContext & operator=( std::nullptr_t ) VKMA_NOEXCEPT
    {
      m_defragmentationContext = VKMA_NULL_HANDLE;
      return *this;
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( DefragmentationContext const& ) const = default;
#else
    bool operator==( DefragmentationContext const & rhs ) const VKMA_NOEXCEPT
    {
      return m_defragmentationContext == rhs.m_defragmentationContext;
    }

    bool operator!=(DefragmentationContext const & rhs ) const VKMA_NOEXCEPT
    {
      return m_defragmentationContext != rhs.m_defragmentationContext;
    }

    bool operator<(DefragmentationContext const & rhs ) const VKMA_NOEXCEPT
    {
      return m_defragmentationContext < rhs.m_defragmentationContext;
    }
#endif

    VKMA_TYPESAFE_EXPLICIT operator VkmaDefragmentationContext() const VKMA_NOEXCEPT
    {
      return m_defragmentationContext;
    }

    explicit operator bool() const VKMA_NOEXCEPT
    {
      return m_defragmentationContext != VKMA_NULL_HANDLE;
    }

    bool operator!() const VKMA_NOEXCEPT
    {
      return m_defragmentationContext == VKMA_NULL_HANDLE;
    }

  private:
    VkmaDefragmentationContext m_defragmentationContext;
  };
  static_assert( sizeof( VKMA_NAMESPACE::DefragmentationContext ) == sizeof( VkmaDefragmentationContext ), "handle and wrapper have different size!" );


  template <>
  struct isVulkanHandleType<VKMA_NAMESPACE::DefragmentationContext>
  {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

  class Image
  {
  public:
    using CType = VkmaImage;


  public:
    VKMA_CONSTEXPR Image() VKMA_NOEXCEPT
      : m_image(VKMA_NULL_HANDLE)
    {}

    VKMA_CONSTEXPR Image( std::nullptr_t ) VKMA_NOEXCEPT
      : m_image(VKMA_NULL_HANDLE)
    {}

    VKMA_TYPESAFE_EXPLICIT Image( VkmaImage image ) VKMA_NOEXCEPT
      : m_image( image )
    {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    Image & operator=(VkmaImage image) VKMA_NOEXCEPT
    {
      m_image = image;
      return *this;
    }
#endif

    Image & operator=( std::nullptr_t ) VKMA_NOEXCEPT
    {
      m_image = VKMA_NULL_HANDLE;
      return *this;
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( Image const& ) const = default;
#else
    bool operator==( Image const & rhs ) const VKMA_NOEXCEPT
    {
      return m_image == rhs.m_image;
    }

    bool operator!=(Image const & rhs ) const VKMA_NOEXCEPT
    {
      return m_image != rhs.m_image;
    }

    bool operator<(Image const & rhs ) const VKMA_NOEXCEPT
    {
      return m_image < rhs.m_image;
    }
#endif


  void get( VkImage* pImage ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VkImage get(  ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  void getAllocation( Allocation* pAllocation ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_NAMESPACE::Allocation getAllocation(  ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/

    VKMA_TYPESAFE_EXPLICIT operator VkmaImage() const VKMA_NOEXCEPT
    {
      return m_image;
    }

    explicit operator bool() const VKMA_NOEXCEPT
    {
      return m_image != VKMA_NULL_HANDLE;
    }

    bool operator!() const VKMA_NOEXCEPT
    {
      return m_image == VKMA_NULL_HANDLE;
    }

  private:
    VkmaImage m_image;
  };
  static_assert( sizeof( VKMA_NAMESPACE::Image ) == sizeof( VkmaImage ), "handle and wrapper have different size!" );


  template <>
  struct isVulkanHandleType<VKMA_NAMESPACE::Image>
  {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

  class Allocator
  {
  public:
    using CType = VkmaAllocator;


  public:
    VKMA_CONSTEXPR Allocator() VKMA_NOEXCEPT
      : m_allocator(VKMA_NULL_HANDLE)
    {}

    VKMA_CONSTEXPR Allocator( std::nullptr_t ) VKMA_NOEXCEPT
      : m_allocator(VKMA_NULL_HANDLE)
    {}

    VKMA_TYPESAFE_EXPLICIT Allocator( VkmaAllocator allocator ) VKMA_NOEXCEPT
      : m_allocator( allocator )
    {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    Allocator & operator=(VkmaAllocator allocator) VKMA_NOEXCEPT
    {
      m_allocator = allocator;
      return *this;
    }
#endif

    Allocator & operator=( std::nullptr_t ) VKMA_NOEXCEPT
    {
      m_allocator = VKMA_NULL_HANDLE;
      return *this;
    }

#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( Allocator const& ) const = default;
#else
    bool operator==( Allocator const & rhs ) const VKMA_NOEXCEPT
    {
      return m_allocator == rhs.m_allocator;
    }

    bool operator!=(Allocator const & rhs ) const VKMA_NOEXCEPT
    {
      return m_allocator != rhs.m_allocator;
    }

    bool operator<(Allocator const & rhs ) const VKMA_NOEXCEPT
    {
      return m_allocator < rhs.m_allocator;
    }
#endif


  VKMA_NODISCARD Result allocateMemory( const VkMemoryRequirements* pVkMemoryRequirements, const AllocationCreateInfo* pCreateInfo, Allocation* pAllocation ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Allocation>::type allocateMemory( const VkMemoryRequirements & vkMemoryRequirements, const AllocationCreateInfo & createInfo ) const;
#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Allocation, Dispatch>>::type allocateMemoryUnique( const VkMemoryRequirements & vkMemoryRequirements, const AllocationCreateInfo & createInfo ) const;
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD Result allocateMemoryForBuffer( VkBuffer buffer, const AllocationCreateInfo* pCreateInfo, Allocation* pAllocation ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Allocation>::type allocateMemoryForBuffer( VkBuffer buffer, const AllocationCreateInfo & createInfo ) const;
#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Allocation, Dispatch>>::type allocateMemoryForBufferUnique( VkBuffer buffer, const AllocationCreateInfo & createInfo ) const;
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD Result allocateMemoryForImage( VkImage image, const AllocationCreateInfo* pCreateInfo, Allocation* pAllocation ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Allocation>::type allocateMemoryForImage( VkImage image, const AllocationCreateInfo & createInfo ) const;
#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Allocation, Dispatch>>::type allocateMemoryForImageUnique( VkImage image, const AllocationCreateInfo & createInfo ) const;
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD Result allocateMemoryPages( const VkMemoryRequirements* pVkMemoryRequirements, const AllocationCreateInfo* pCreateInfo, size_t allocationCount, Allocation* pAllocations ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Allocation>::type allocateMemoryPages( const VkMemoryRequirements & vkMemoryRequirements, const AllocationCreateInfo & createInfo, size_t allocationCount ) const;
#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Allocation, Dispatch>>::type allocateMemoryPagesUnique( const VkMemoryRequirements & vkMemoryRequirements, const AllocationCreateInfo & createInfo, size_t allocationCount ) const;
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD Result bindBufferMemory( Allocation allocation, VkBuffer buffer ) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type bindBufferMemory( Allocation allocation, VkBuffer buffer ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD Result bindBufferMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer, const void* pNext ) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type bindBufferMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer, const void* pNext ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD Result bindImageMemory( Allocation allocation, VkImage image ) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type bindImageMemory( Allocation allocation, VkImage image ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD Result bindImageMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkImage image, const void* pNext ) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type bindImageMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkImage image, const void* pNext ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  void buildStatsString( VkBool32 detailedMap, char** ppStatsString ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD char buildStatsString( VkBool32 detailedMap ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  void calculateStats( Stats* pStats ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_NAMESPACE::Stats calculateStats(  ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD Result checkCorruption( uint32_t memoryTypeBits ) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type checkCorruption( uint32_t memoryTypeBits ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD Result checkPoolCorruption( Pool pool ) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type checkPoolCorruption( Pool pool ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  VKMA_NODISCARD Result createBuffer( const VkBufferCreateInfo* pBufferCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, Buffer* pBuffer ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Buffer>::type createBuffer( const VkBufferCreateInfo & bufferCreateInfo, const AllocationCreateInfo & allocationCreateInfo ) const;
#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Buffer, Dispatch>>::type createBufferUnique( const VkBufferCreateInfo & bufferCreateInfo, const AllocationCreateInfo & allocationCreateInfo ) const;
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD Result createDefragmentationContext( const DefragmentationInfo2* pInfo, DefragmentationContext* pContext ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<DefragmentationContext>::type createDefragmentationContext( const DefragmentationInfo2 & info ) const;
#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<DefragmentationContext, Dispatch>>::type createDefragmentationContextUnique( const DefragmentationInfo2 & info ) const;
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD Result createImage( const VkImageCreateInfo* pImageCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, Image* pImage ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Image>::type createImage( const VkImageCreateInfo & imageCreateInfo, const AllocationCreateInfo & allocationCreateInfo ) const;
#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Image, Dispatch>>::type createImageUnique( const VkImageCreateInfo & imageCreateInfo, const AllocationCreateInfo & allocationCreateInfo ) const;
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  VKMA_NODISCARD Result createPool( const PoolCreateInfo* pCreateInfo, Pool* pPool ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Pool>::type createPool( const PoolCreateInfo & createInfo ) const;
#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Pool, Dispatch>>::type createPoolUnique( const PoolCreateInfo & createInfo ) const;
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  void destroy(  ) const VKMA_NOEXCEPT;


  void destroyBuffer( Buffer buffer ) const VKMA_NOEXCEPT;


#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD Result destroyDefragmentationContext( DefragmentationContext context ) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type destroyDefragmentationContext( DefragmentationContext context ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  void destroyImage( Image image ) const VKMA_NOEXCEPT;


  void destroyPool( Pool pool ) const VKMA_NOEXCEPT;


  VKMA_NODISCARD Result findMemoryTypeIndex( uint32_t memoryTypeBits, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<uint32_t>::type findMemoryTypeIndex( uint32_t memoryTypeBits, const AllocationCreateInfo & allocationCreateInfo ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD Result findMemoryTypeIndexForBufferInfo( const VkBufferCreateInfo* pBufferCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<uint32_t>::type findMemoryTypeIndexForBufferInfo( const VkBufferCreateInfo & bufferCreateInfo, const AllocationCreateInfo & allocationCreateInfo ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD Result findMemoryTypeIndexForImageInfo( const VkImageCreateInfo* pImageCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<uint32_t>::type findMemoryTypeIndexForImageInfo( const VkImageCreateInfo & imageCreateInfo, const AllocationCreateInfo & allocationCreateInfo ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD Result flushAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size ) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type flushAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  void freeMemory( const Allocation allocation ) const VKMA_NOEXCEPT;


  void freeMemoryPages( size_t allocationCount, const Allocation* pAllocations ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <>
void freeMemoryPages( size_t allocationCount, const Allocation & allocations ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  void freeStatsString( char* pStatsString ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD char freeStatsString(  ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  void getAllocationInfo( Allocation allocation, AllocationInfo* pAllocationInfo ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_NAMESPACE::AllocationInfo getAllocationInfo( Allocation allocation ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  void getBudget( Budget* pBudget ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_NAMESPACE::Budget getBudget(  ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  void getMemoryProperties( VkPhysicalDeviceMemoryProperties* pPhysicalDeviceMemoryProperties ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VkPhysicalDeviceMemoryProperties getMemoryProperties(  ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  void getMemoryTypeProperties( uint32_t memoryTypeIndex, VkMemoryPropertyFlags* pFlags ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VkMemoryPropertyFlags getMemoryTypeProperties( uint32_t memoryTypeIndex ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  void getPhysicalDeviceProperties( VkPhysicalDeviceProperties* pPhysicalDeviceProperties ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VkPhysicalDeviceProperties getPhysicalDeviceProperties(  ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  void getPoolName( Pool pool, const char** ppName ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <>
void getPoolName( Pool pool, const char & pName ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  void getPoolStats( Pool pool, PoolStats* pPoolStats ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_NAMESPACE::PoolStats getPoolStats( Pool pool ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD Result invalidateAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size ) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type invalidateAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  void makePoolAllocationsLost( Pool pool, size_t* pLostAllocationCount ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD size_t makePoolAllocationsLost( Pool pool ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD Result mapMemory( Allocation allocation, void** ppData ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void*>::type mapMemory( Allocation allocation ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD Result resizeAllocation( Allocation allocation, VkDeviceSize newSize ) const VKMA_NOEXCEPT;
#else
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type resizeAllocation( Allocation allocation, VkDeviceSize newSize ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  void setAllocationUserData( Allocation allocation, const void* pUserData ) const VKMA_NOEXCEPT;


  void setCurrentFrameIndex( uint32_t frameIndex ) const VKMA_NOEXCEPT;


  void setPoolName( Pool pool, const char* pName ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <>
void setPoolName( Pool pool, const char & name ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VkBool32 touchAllocation( Allocation allocation ) const VKMA_NOEXCEPT;


  void unmapMemory( Allocation allocation ) const VKMA_NOEXCEPT;

    VKMA_TYPESAFE_EXPLICIT operator VkmaAllocator() const VKMA_NOEXCEPT
    {
      return m_allocator;
    }

    explicit operator bool() const VKMA_NOEXCEPT
    {
      return m_allocator != VKMA_NULL_HANDLE;
    }

    bool operator!() const VKMA_NOEXCEPT
    {
      return m_allocator == VKMA_NULL_HANDLE;
    }

  private:
    VkmaAllocator m_allocator;
  };
  static_assert( sizeof( VKMA_NAMESPACE::Allocator ) == sizeof( VkmaAllocator ), "handle and wrapper have different size!" );


  template <>
  struct isVulkanHandleType<VKMA_NAMESPACE::Allocator>
  {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };


  VKMA_NODISCARD Result createAllocator( const AllocatorCreateInfo* pCreateInfo, Allocator* pAllocator ) VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Allocator>::type createAllocator( const AllocatorCreateInfo & createInfo );
#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Allocator, Dispatch>>::type createAllocatorUnique( const AllocatorCreateInfo & createInfo );
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD VKMA_INLINE Result createAllocator( const AllocatorCreateInfo* pCreateInfo, Allocator* pAllocator ) VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaCreateAllocator( reinterpret_cast<const VkmaAllocatorCreateInfo *>( pCreateInfo ), reinterpret_cast< VkmaAllocator *>( pAllocator ) ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Allocator>::type createAllocator( const AllocatorCreateInfo & createInfo )
  {
    Allocator allocator;
    Result result = static_cast<Result>( d.vkmaCreateAllocator( reinterpret_cast<const VkmaAllocatorCreateInfo *>( &createInfo ), reinterpret_cast<VkmaAllocator *>( &allocator ) ) );
    return createResultValue( result, allocator, VKMA_NAMESPACE_STRING "::createAllocator" );
  }

#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Allocator>>::type createAllocatorUnique( const AllocatorCreateInfo & createInfo )
  {
    Allocator allocator;
    Result result = static_cast<Result>( d.vkmaCreateAllocator( reinterpret_cast<const VkmaAllocatorCreateInfo *>( &createInfo ), reinterpret_cast<VkmaAllocator *>( &allocator ) ) );
    ObjectDestroy<NoParent> deleter( allocator, d );
    return createResultValue<Allocator>( result, allocator, VKMA_NAMESPACE_STRING "::createAllocatorUnique", deleter );
  }
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD VKMA_INLINE Result Allocator::allocateMemory( const VkMemoryRequirements* pVkMemoryRequirements, const AllocationCreateInfo* pCreateInfo, Allocation* pAllocation ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaAllocateMemory( m_allocator, pVkMemoryRequirements, reinterpret_cast<const VkmaAllocationCreateInfo *>( pCreateInfo ), reinterpret_cast< VkmaAllocation *>( pAllocation ) ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Allocation>::type Allocator::allocateMemory( const VkMemoryRequirements & vkMemoryRequirements, const AllocationCreateInfo & createInfo ) const
  {
    Allocation allocation;
    Result result = static_cast<Result>( d.vkmaAllocateMemory( m_allocator, &vkMemoryRequirements, reinterpret_cast<const VkmaAllocationCreateInfo *>( &createInfo ), reinterpret_cast<VkmaAllocation *>( &allocation ) ) );
    return createResultValue( result, allocation, VKMA_NAMESPACE_STRING "::Allocator::allocateMemory" );
  }

#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Allocation>>::type Allocator::allocateMemoryUnique( const VkMemoryRequirements & vkMemoryRequirements, const AllocationCreateInfo & createInfo ) const
  {
    Allocation allocation;
    Result result = static_cast<Result>( d.vkmaAllocateMemory( m_allocator, &vkMemoryRequirements, reinterpret_cast<const VkmaAllocationCreateInfo *>( &createInfo ), reinterpret_cast<VkmaAllocation *>( &allocation ) ) );
    ObjectFree<Allocator> deleter( *this, allocator, d );
    return createResultValue<Allocation>( result, allocation, VKMA_NAMESPACE_STRING "::Allocator::allocateMemoryUnique", deleter );
  }
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD VKMA_INLINE Result Allocator::allocateMemoryForBuffer( VkBuffer buffer, const AllocationCreateInfo* pCreateInfo, Allocation* pAllocation ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaAllocateMemoryForBuffer( m_allocator, buffer, reinterpret_cast<const VkmaAllocationCreateInfo *>( pCreateInfo ), reinterpret_cast< VkmaAllocation *>( pAllocation ) ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Allocation>::type Allocator::allocateMemoryForBuffer( VkBuffer buffer, const AllocationCreateInfo & createInfo ) const
  {
    Allocation allocation;
    Result result = static_cast<Result>( d.vkmaAllocateMemoryForBuffer( m_allocator, buffer, reinterpret_cast<const VkmaAllocationCreateInfo *>( &createInfo ), reinterpret_cast<VkmaAllocation *>( &allocation ) ) );
    return createResultValue( result, allocation, VKMA_NAMESPACE_STRING "::Allocator::allocateMemoryForBuffer" );
  }

#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Allocation>>::type Allocator::allocateMemoryForBufferUnique( VkBuffer buffer, const AllocationCreateInfo & createInfo ) const
  {
    Allocation allocation;
    Result result = static_cast<Result>( d.vkmaAllocateMemoryForBuffer( m_allocator, buffer, reinterpret_cast<const VkmaAllocationCreateInfo *>( &createInfo ), reinterpret_cast<VkmaAllocation *>( &allocation ) ) );
    ObjectFree<Allocator> deleter( *this, allocator, d );
    return createResultValue<Allocation>( result, allocation, VKMA_NAMESPACE_STRING "::Allocator::allocateMemoryForBufferUnique", deleter );
  }
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD VKMA_INLINE Result Allocator::allocateMemoryForImage( VkImage image, const AllocationCreateInfo* pCreateInfo, Allocation* pAllocation ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaAllocateMemoryForImage( m_allocator, image, reinterpret_cast<const VkmaAllocationCreateInfo *>( pCreateInfo ), reinterpret_cast< VkmaAllocation *>( pAllocation ) ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Allocation>::type Allocator::allocateMemoryForImage( VkImage image, const AllocationCreateInfo & createInfo ) const
  {
    Allocation allocation;
    Result result = static_cast<Result>( d.vkmaAllocateMemoryForImage( m_allocator, image, reinterpret_cast<const VkmaAllocationCreateInfo *>( &createInfo ), reinterpret_cast<VkmaAllocation *>( &allocation ) ) );
    return createResultValue( result, allocation, VKMA_NAMESPACE_STRING "::Allocator::allocateMemoryForImage" );
  }

#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Allocation>>::type Allocator::allocateMemoryForImageUnique( VkImage image, const AllocationCreateInfo & createInfo ) const
  {
    Allocation allocation;
    Result result = static_cast<Result>( d.vkmaAllocateMemoryForImage( m_allocator, image, reinterpret_cast<const VkmaAllocationCreateInfo *>( &createInfo ), reinterpret_cast<VkmaAllocation *>( &allocation ) ) );
    ObjectFree<Allocator> deleter( *this, allocator, d );
    return createResultValue<Allocation>( result, allocation, VKMA_NAMESPACE_STRING "::Allocator::allocateMemoryForImageUnique", deleter );
  }
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD VKMA_INLINE Result Allocator::allocateMemoryPages( const VkMemoryRequirements* pVkMemoryRequirements, const AllocationCreateInfo* pCreateInfo, size_t allocationCount, Allocation* pAllocations ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaAllocateMemoryPages( m_allocator, pVkMemoryRequirements, reinterpret_cast<const VkmaAllocationCreateInfo *>( pCreateInfo ), allocationCount, reinterpret_cast< VkmaAllocation *>( pAllocations ) ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Allocation>::type Allocator::allocateMemoryPages( const VkMemoryRequirements & vkMemoryRequirements, const AllocationCreateInfo & createInfo, size_t allocationCount ) const
  {
    Allocation allocations;
    Result result = static_cast<Result>( d.vkmaAllocateMemoryPages( m_allocator, &vkMemoryRequirements, reinterpret_cast<const VkmaAllocationCreateInfo *>( &createInfo ), allocationCount, reinterpret_cast<VkmaAllocation *>( &allocations ) ) );
    return createResultValue( result, allocations, VKMA_NAMESPACE_STRING "::Allocator::allocateMemoryPages" );
  }

#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Allocation>>::type Allocator::allocateMemoryPagesUnique( const VkMemoryRequirements & vkMemoryRequirements, const AllocationCreateInfo & createInfo, size_t allocationCount ) const
  {
    Allocation allocations;
    Result result = static_cast<Result>( d.vkmaAllocateMemoryPages( m_allocator, &vkMemoryRequirements, reinterpret_cast<const VkmaAllocationCreateInfo *>( &createInfo ), allocationCount, reinterpret_cast<VkmaAllocation *>( &allocations ) ) );
    ObjectFree<Allocator> deleter( *this, allocator, d );
    return createResultValue<Allocation>( result, allocations, VKMA_NAMESPACE_STRING "::Allocator::allocateMemoryPagesUnique", deleter );
  }
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result Allocator::bindBufferMemory( Allocation allocation, VkBuffer buffer ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaBindBufferMemory( m_allocator, static_cast<VkmaAllocation>( allocation ), buffer ) );
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::bindBufferMemory( Allocation allocation, VkBuffer buffer ) const
  {
    Result result = static_cast<Result>( d.vkmaBindBufferMemory( m_allocator, static_cast<VkmaAllocation>( allocation ), buffer ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::bindBufferMemory" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result Allocator::bindBufferMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer, const void* pNext ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaBindBufferMemory2( m_allocator, static_cast<VkmaAllocation>( allocation ), allocationLocalOffset, buffer, pNext ) );
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::bindBufferMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer, const void* pNext ) const
  {
    Result result = static_cast<Result>( d.vkmaBindBufferMemory2( m_allocator, static_cast<VkmaAllocation>( allocation ), allocationLocalOffset, buffer, pNext ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::bindBufferMemory2" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result Allocator::bindImageMemory( Allocation allocation, VkImage image ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaBindImageMemory( m_allocator, static_cast<VkmaAllocation>( allocation ), image ) );
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::bindImageMemory( Allocation allocation, VkImage image ) const
  {
    Result result = static_cast<Result>( d.vkmaBindImageMemory( m_allocator, static_cast<VkmaAllocation>( allocation ), image ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::bindImageMemory" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result Allocator::bindImageMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkImage image, const void* pNext ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaBindImageMemory2( m_allocator, static_cast<VkmaAllocation>( allocation ), allocationLocalOffset, image, pNext ) );
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::bindImageMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkImage image, const void* pNext ) const
  {
    Result result = static_cast<Result>( d.vkmaBindImageMemory2( m_allocator, static_cast<VkmaAllocation>( allocation ), allocationLocalOffset, image, pNext ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::bindImageMemory2" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  VKMA_INLINE void Allocator::buildStatsString( VkBool32 detailedMap, char** ppStatsString ) const VKMA_NOEXCEPT
  {
    d.vkmaBuildStatsString( m_allocator, detailedMap, ppStatsString );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE char Allocator::buildStatsString( VkBool32 detailedMap ) const VKMA_NOEXCEPT
  {
    char pStatsString;
    d.vkmaBuildStatsString( m_allocator, detailedMap, &pStatsString );
    return pStatsString;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_INLINE void Allocator::calculateStats( Stats* pStats ) const VKMA_NOEXCEPT
  {
    d.vkmaCalculateStats( m_allocator, reinterpret_cast< VkmaStats *>( pStats ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::Stats Allocator::calculateStats(  ) const VKMA_NOEXCEPT
  {
    VKMA_NAMESPACE::Stats stats;
    d.vkmaCalculateStats( m_allocator, reinterpret_cast<VkmaStats *>( &stats ) );
    return stats;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result Allocator::checkCorruption( uint32_t memoryTypeBits ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaCheckCorruption( m_allocator, memoryTypeBits ) );
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::checkCorruption( uint32_t memoryTypeBits ) const
  {
    Result result = static_cast<Result>( d.vkmaCheckCorruption( m_allocator, memoryTypeBits ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::checkCorruption" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result Allocator::checkPoolCorruption( Pool pool ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaCheckPoolCorruption( m_allocator, static_cast<VkmaPool>( pool ) ) );
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::checkPoolCorruption( Pool pool ) const
  {
    Result result = static_cast<Result>( d.vkmaCheckPoolCorruption( m_allocator, static_cast<VkmaPool>( pool ) ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::checkPoolCorruption" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  VKMA_NODISCARD VKMA_INLINE Result Allocator::createBuffer( const VkBufferCreateInfo* pBufferCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, Buffer* pBuffer ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaCreateBuffer( m_allocator, pBufferCreateInfo, reinterpret_cast<const VkmaAllocationCreateInfo *>( pAllocationCreateInfo ), reinterpret_cast< VkmaBuffer *>( pBuffer ) ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Buffer>::type Allocator::createBuffer( const VkBufferCreateInfo & bufferCreateInfo, const AllocationCreateInfo & allocationCreateInfo ) const
  {
    Buffer buffer;
    Result result = static_cast<Result>( d.vkmaCreateBuffer( m_allocator, &bufferCreateInfo, reinterpret_cast<const VkmaAllocationCreateInfo *>( &allocationCreateInfo ), reinterpret_cast<VkmaBuffer *>( &buffer ) ) );
    return createResultValue( result, buffer, VKMA_NAMESPACE_STRING "::Allocator::createBuffer" );
  }

#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Buffer>>::type Allocator::createBufferUnique( const VkBufferCreateInfo & bufferCreateInfo, const AllocationCreateInfo & allocationCreateInfo ) const
  {
    Buffer buffer;
    Result result = static_cast<Result>( d.vkmaCreateBuffer( m_allocator, &bufferCreateInfo, reinterpret_cast<const VkmaAllocationCreateInfo *>( &allocationCreateInfo ), reinterpret_cast<VkmaBuffer *>( &buffer ) ) );
    ObjectDestroy<Allocator> deleter( *this, allocator, d );
    return createResultValue<Buffer>( result, buffer, VKMA_NAMESPACE_STRING "::Allocator::createBufferUnique", deleter );
  }
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD VKMA_INLINE Result Allocator::createDefragmentationContext( const DefragmentationInfo2* pInfo, DefragmentationContext* pContext ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaCreateDefragmentationContext( m_allocator, reinterpret_cast<const VkmaDefragmentationInfo2 *>( pInfo ), reinterpret_cast< VkmaDefragmentationContext *>( pContext ) ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<DefragmentationContext>::type Allocator::createDefragmentationContext( const DefragmentationInfo2 & info ) const
  {
    DefragmentationContext context;
    Result result = static_cast<Result>( d.vkmaCreateDefragmentationContext( m_allocator, reinterpret_cast<const VkmaDefragmentationInfo2 *>( &info ), reinterpret_cast<VkmaDefragmentationContext *>( &context ) ) );
    return createResultValue( result, context, VKMA_NAMESPACE_STRING "::Allocator::createDefragmentationContext" );
  }

#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<DefragmentationContext>>::type Allocator::createDefragmentationContextUnique( const DefragmentationInfo2 & info ) const
  {
    DefragmentationContext context;
    Result result = static_cast<Result>( d.vkmaCreateDefragmentationContext( m_allocator, reinterpret_cast<const VkmaDefragmentationInfo2 *>( &info ), reinterpret_cast<VkmaDefragmentationContext *>( &context ) ) );
    ObjectDestroy<Allocator> deleter( *this, allocator, d );
    return createResultValue<DefragmentationContext>( result, context, VKMA_NAMESPACE_STRING "::Allocator::createDefragmentationContextUnique", deleter );
  }
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD VKMA_INLINE Result Allocator::createImage( const VkImageCreateInfo* pImageCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, Image* pImage ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaCreateImage( m_allocator, pImageCreateInfo, reinterpret_cast<const VkmaAllocationCreateInfo *>( pAllocationCreateInfo ), reinterpret_cast< VkmaImage *>( pImage ) ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Image>::type Allocator::createImage( const VkImageCreateInfo & imageCreateInfo, const AllocationCreateInfo & allocationCreateInfo ) const
  {
    Image image;
    Result result = static_cast<Result>( d.vkmaCreateImage( m_allocator, &imageCreateInfo, reinterpret_cast<const VkmaAllocationCreateInfo *>( &allocationCreateInfo ), reinterpret_cast<VkmaImage *>( &image ) ) );
    return createResultValue( result, image, VKMA_NAMESPACE_STRING "::Allocator::createImage" );
  }

#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Image>>::type Allocator::createImageUnique( const VkImageCreateInfo & imageCreateInfo, const AllocationCreateInfo & allocationCreateInfo ) const
  {
    Image image;
    Result result = static_cast<Result>( d.vkmaCreateImage( m_allocator, &imageCreateInfo, reinterpret_cast<const VkmaAllocationCreateInfo *>( &allocationCreateInfo ), reinterpret_cast<VkmaImage *>( &image ) ) );
    ObjectDestroy<Allocator> deleter( *this, allocator, d );
    return createResultValue<Image>( result, image, VKMA_NAMESPACE_STRING "::Allocator::createImageUnique", deleter );
  }
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  VKMA_NODISCARD VKMA_INLINE Result Allocator::createPool( const PoolCreateInfo* pCreateInfo, Pool* pPool ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaCreatePool( m_allocator, reinterpret_cast<const VkmaPoolCreateInfo *>( pCreateInfo ), reinterpret_cast< VkmaPool *>( pPool ) ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Pool>::type Allocator::createPool( const PoolCreateInfo & createInfo ) const
  {
    Pool pool;
    Result result = static_cast<Result>( d.vkmaCreatePool( m_allocator, reinterpret_cast<const VkmaPoolCreateInfo *>( &createInfo ), reinterpret_cast<VkmaPool *>( &pool ) ) );
    return createResultValue( result, pool, VKMA_NAMESPACE_STRING "::Allocator::createPool" );
  }

#  ifndef VKMA_NO_SMART_HANDLE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Pool>>::type Allocator::createPoolUnique( const PoolCreateInfo & createInfo ) const
  {
    Pool pool;
    Result result = static_cast<Result>( d.vkmaCreatePool( m_allocator, reinterpret_cast<const VkmaPoolCreateInfo *>( &createInfo ), reinterpret_cast<VkmaPool *>( &pool ) ) );
    ObjectDestroy<Allocator> deleter( *this, allocator, d );
    return createResultValue<Pool>( result, pool, VKMA_NAMESPACE_STRING "::Allocator::createPoolUnique", deleter );
  }
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_INLINE void Allocator::destroy(  ) const VKMA_NOEXCEPT
  {
    d.vkmaDestroyAllocator( m_allocator );
  }


  VKMA_INLINE void Allocator::destroyBuffer( Buffer buffer ) const VKMA_NOEXCEPT
  {
    d.vkmaDestroyBuffer( m_allocator, static_cast<VkmaBuffer>( buffer ) );
  }


#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result Allocator::destroyDefragmentationContext( DefragmentationContext context ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaDestroyDefragmentationContext( m_allocator, static_cast<VkmaDefragmentationContext>( context ) ) );
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::destroyDefragmentationContext( DefragmentationContext context ) const
  {
    Result result = static_cast<Result>( d.vkmaDestroyDefragmentationContext( m_allocator, static_cast<VkmaDefragmentationContext>( context ) ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::destroyDefragmentationContext" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  VKMA_INLINE void Allocator::destroyImage( Image image ) const VKMA_NOEXCEPT
  {
    d.vkmaDestroyImage( m_allocator, static_cast<VkmaImage>( image ) );
  }


  VKMA_INLINE void Allocator::destroyPool( Pool pool ) const VKMA_NOEXCEPT
  {
    d.vkmaDestroyPool( m_allocator, static_cast<VkmaPool>( pool ) );
  }


  VKMA_NODISCARD VKMA_INLINE Result Allocator::findMemoryTypeIndex( uint32_t memoryTypeBits, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaFindMemoryTypeIndex( m_allocator, memoryTypeBits, reinterpret_cast<const VkmaAllocationCreateInfo *>( pAllocationCreateInfo ), pMemoryTypeIndex ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<uint32_t>::type Allocator::findMemoryTypeIndex( uint32_t memoryTypeBits, const AllocationCreateInfo & allocationCreateInfo ) const
  {
    uint32_t memoryTypeIndex;
    Result result = static_cast<Result>( d.vkmaFindMemoryTypeIndex( m_allocator, memoryTypeBits, reinterpret_cast<const VkmaAllocationCreateInfo *>( &allocationCreateInfo ), &memoryTypeIndex ) );
    return createResultValue( result, memoryTypeIndex, VKMA_NAMESPACE_STRING "::Allocator::findMemoryTypeIndex" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD VKMA_INLINE Result Allocator::findMemoryTypeIndexForBufferInfo( const VkBufferCreateInfo* pBufferCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaFindMemoryTypeIndexForBufferInfo( m_allocator, pBufferCreateInfo, reinterpret_cast<const VkmaAllocationCreateInfo *>( pAllocationCreateInfo ), pMemoryTypeIndex ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<uint32_t>::type Allocator::findMemoryTypeIndexForBufferInfo( const VkBufferCreateInfo & bufferCreateInfo, const AllocationCreateInfo & allocationCreateInfo ) const
  {
    uint32_t memoryTypeIndex;
    Result result = static_cast<Result>( d.vkmaFindMemoryTypeIndexForBufferInfo( m_allocator, &bufferCreateInfo, reinterpret_cast<const VkmaAllocationCreateInfo *>( &allocationCreateInfo ), &memoryTypeIndex ) );
    return createResultValue( result, memoryTypeIndex, VKMA_NAMESPACE_STRING "::Allocator::findMemoryTypeIndexForBufferInfo" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD VKMA_INLINE Result Allocator::findMemoryTypeIndexForImageInfo( const VkImageCreateInfo* pImageCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaFindMemoryTypeIndexForImageInfo( m_allocator, pImageCreateInfo, reinterpret_cast<const VkmaAllocationCreateInfo *>( pAllocationCreateInfo ), pMemoryTypeIndex ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<uint32_t>::type Allocator::findMemoryTypeIndexForImageInfo( const VkImageCreateInfo & imageCreateInfo, const AllocationCreateInfo & allocationCreateInfo ) const
  {
    uint32_t memoryTypeIndex;
    Result result = static_cast<Result>( d.vkmaFindMemoryTypeIndexForImageInfo( m_allocator, &imageCreateInfo, reinterpret_cast<const VkmaAllocationCreateInfo *>( &allocationCreateInfo ), &memoryTypeIndex ) );
    return createResultValue( result, memoryTypeIndex, VKMA_NAMESPACE_STRING "::Allocator::findMemoryTypeIndexForImageInfo" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result Allocator::flushAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaFlushAllocation( m_allocator, static_cast<VkmaAllocation>( allocation ), offset, size ) );
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::flushAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size ) const
  {
    Result result = static_cast<Result>( d.vkmaFlushAllocation( m_allocator, static_cast<VkmaAllocation>( allocation ), offset, size ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::flushAllocation" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  VKMA_INLINE void Allocator::freeMemory( const Allocation allocation ) const VKMA_NOEXCEPT
  {
    d.vkmaFreeMemory( m_allocator, static_cast<VkmaAllocation>( allocation ) );
  }


  VKMA_INLINE void Allocator::freeMemoryPages( size_t allocationCount, const Allocation* pAllocations ) const VKMA_NOEXCEPT
  {
    d.vkmaFreeMemoryPages( m_allocator, allocationCount, reinterpret_cast<const VkmaAllocation *>( pAllocations ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <>
  VKMA_INLINE void Allocator::freeMemoryPages( size_t allocationCount, const Allocation & allocations ) const VKMA_NOEXCEPT
  {
    d.vkmaFreeMemoryPages( m_allocator, allocationCount, reinterpret_cast<const VkmaAllocation *>( &allocations ) );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_INLINE void Allocator::freeStatsString( char* pStatsString ) const VKMA_NOEXCEPT
  {
    d.vkmaFreeStatsString( m_allocator, pStatsString );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE char Allocator::freeStatsString(  ) const VKMA_NOEXCEPT
  {
    char statsString;
    d.vkmaFreeStatsString( m_allocator, &statsString );
    return statsString;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_INLINE void Allocator::getAllocationInfo( Allocation allocation, AllocationInfo* pAllocationInfo ) const VKMA_NOEXCEPT
  {
    d.vkmaGetAllocationInfo( m_allocator, static_cast<VkmaAllocation>( allocation ), reinterpret_cast< VkmaAllocationInfo *>( pAllocationInfo ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::AllocationInfo Allocator::getAllocationInfo( Allocation allocation ) const VKMA_NOEXCEPT
  {
    VKMA_NAMESPACE::AllocationInfo allocationInfo;
    d.vkmaGetAllocationInfo( m_allocator, static_cast<VkmaAllocation>( allocation ), reinterpret_cast<VkmaAllocationInfo *>( &allocationInfo ) );
    return allocationInfo;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_INLINE void Allocator::getBudget( Budget* pBudget ) const VKMA_NOEXCEPT
  {
    d.vkmaGetBudget( m_allocator, reinterpret_cast< VkmaBudget *>( pBudget ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::Budget Allocator::getBudget(  ) const VKMA_NOEXCEPT
  {
    VKMA_NAMESPACE::Budget budget;
    d.vkmaGetBudget( m_allocator, reinterpret_cast<VkmaBudget *>( &budget ) );
    return budget;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_INLINE void Allocator::getMemoryProperties( VkPhysicalDeviceMemoryProperties* pPhysicalDeviceMemoryProperties ) const VKMA_NOEXCEPT
  {
    d.vkmaGetMemoryProperties( m_allocator, pPhysicalDeviceMemoryProperties );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VkPhysicalDeviceMemoryProperties Allocator::getMemoryProperties(  ) const VKMA_NOEXCEPT
  {
    VkPhysicalDeviceMemoryProperties physicalDeviceMemoryProperties;
    d.vkmaGetMemoryProperties( m_allocator, &physicalDeviceMemoryProperties );
    return physicalDeviceMemoryProperties;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_INLINE void Allocator::getMemoryTypeProperties( uint32_t memoryTypeIndex, VkMemoryPropertyFlags* pFlags ) const VKMA_NOEXCEPT
  {
    d.vkmaGetMemoryTypeProperties( m_allocator, memoryTypeIndex, pFlags );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VkMemoryPropertyFlags Allocator::getMemoryTypeProperties( uint32_t memoryTypeIndex ) const VKMA_NOEXCEPT
  {
    VkMemoryPropertyFlags flags;
    d.vkmaGetMemoryTypeProperties( m_allocator, memoryTypeIndex, &flags );
    return flags;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_INLINE void Allocator::getPhysicalDeviceProperties( VkPhysicalDeviceProperties* pPhysicalDeviceProperties ) const VKMA_NOEXCEPT
  {
    d.vkmaGetPhysicalDeviceProperties( m_allocator, pPhysicalDeviceProperties );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VkPhysicalDeviceProperties Allocator::getPhysicalDeviceProperties(  ) const VKMA_NOEXCEPT
  {
    VkPhysicalDeviceProperties physicalDeviceProperties;
    d.vkmaGetPhysicalDeviceProperties( m_allocator, &physicalDeviceProperties );
    return physicalDeviceProperties;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_INLINE void Allocator::getPoolName( Pool pool, const char** ppName ) const VKMA_NOEXCEPT
  {
    d.vkmaGetPoolName( m_allocator, static_cast<VkmaPool>( pool ), ppName );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <>
  VKMA_INLINE void Allocator::getPoolName( Pool pool, const char & pName ) const VKMA_NOEXCEPT
  {
    d.vkmaGetPoolName( m_allocator, static_cast<VkmaPool>( pool ), &pName );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_INLINE void Allocator::getPoolStats( Pool pool, PoolStats* pPoolStats ) const VKMA_NOEXCEPT
  {
    d.vkmaGetPoolStats( m_allocator, static_cast<VkmaPool>( pool ), reinterpret_cast< VkmaPoolStats *>( pPoolStats ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::PoolStats Allocator::getPoolStats( Pool pool ) const VKMA_NOEXCEPT
  {
    VKMA_NAMESPACE::PoolStats poolStats;
    d.vkmaGetPoolStats( m_allocator, static_cast<VkmaPool>( pool ), reinterpret_cast<VkmaPoolStats *>( &poolStats ) );
    return poolStats;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result Allocator::invalidateAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaInvalidateAllocation( m_allocator, static_cast<VkmaAllocation>( allocation ), offset, size ) );
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::invalidateAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size ) const
  {
    Result result = static_cast<Result>( d.vkmaInvalidateAllocation( m_allocator, static_cast<VkmaAllocation>( allocation ), offset, size ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::invalidateAllocation" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  VKMA_INLINE void Allocator::makePoolAllocationsLost( Pool pool, size_t* pLostAllocationCount ) const VKMA_NOEXCEPT
  {
    d.vkmaMakePoolAllocationsLost( m_allocator, static_cast<VkmaPool>( pool ), pLostAllocationCount );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE size_t Allocator::makePoolAllocationsLost( Pool pool ) const VKMA_NOEXCEPT
  {
    size_t lostAllocationCount;
    d.vkmaMakePoolAllocationsLost( m_allocator, static_cast<VkmaPool>( pool ), &lostAllocationCount );
    return lostAllocationCount;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_NODISCARD VKMA_INLINE Result Allocator::mapMemory( Allocation allocation, void** ppData ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaMapMemory( m_allocator, static_cast<VkmaAllocation>( allocation ), ppData ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void*>::type Allocator::mapMemory( Allocation allocation ) const
  {
    void* pData;
    Result result = static_cast<Result>( d.vkmaMapMemory( m_allocator, static_cast<VkmaAllocation>( allocation ), &pData ) );
    return createResultValue( result, pData, VKMA_NAMESPACE_STRING "::Allocator::mapMemory" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


#ifdef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE Result Allocator::resizeAllocation( Allocation allocation, VkDeviceSize newSize ) const VKMA_NOEXCEPT
  {
    return static_cast<Result>( d.vkmaResizeAllocation( m_allocator, static_cast<VkmaAllocation>( allocation ), newSize ) );
  }
#else
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::resizeAllocation( Allocation allocation, VkDeviceSize newSize ) const
  {
    Result result = static_cast<Result>( d.vkmaResizeAllocation( m_allocator, static_cast<VkmaAllocation>( allocation ), newSize ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::resizeAllocation" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  VKMA_INLINE void Allocator::setAllocationUserData( Allocation allocation, const void* pUserData ) const VKMA_NOEXCEPT
  {
    d.vkmaSetAllocationUserData( m_allocator, static_cast<VkmaAllocation>( allocation ), pUserData );
  }


  VKMA_INLINE void Allocator::setCurrentFrameIndex( uint32_t frameIndex ) const VKMA_NOEXCEPT
  {
    d.vkmaSetCurrentFrameIndex( m_allocator, frameIndex );
  }


  VKMA_INLINE void Allocator::setPoolName( Pool pool, const char* pName ) const VKMA_NOEXCEPT
  {
    d.vkmaSetPoolName( m_allocator, static_cast<VkmaPool>( pool ), pName );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <>
  VKMA_INLINE void Allocator::setPoolName( Pool pool, const char & name ) const VKMA_NOEXCEPT
  {
    d.vkmaSetPoolName( m_allocator, static_cast<VkmaPool>( pool ), &name );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_INLINE VkBool32 Allocator::touchAllocation( Allocation allocation ) const VKMA_NOEXCEPT
  {
    return d.vkmaTouchAllocation( m_allocator, static_cast<VkmaAllocation>( allocation ) );
  }


  VKMA_INLINE void Allocator::unmapMemory( Allocation allocation ) const VKMA_NOEXCEPT
  {
    d.vkmaUnmapMemory( m_allocator, static_cast<VkmaAllocation>( allocation ) );
  }


  VKMA_INLINE void Buffer::get( VkBuffer* pBuffer ) const VKMA_NOEXCEPT
  {
    d.vkmaGetBuffer( m_buffer, pBuffer );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VkBuffer Buffer::get(  ) const VKMA_NOEXCEPT
  {
    VkBuffer buffer;
    d.vkmaGetBuffer( m_buffer, &buffer );
    return buffer;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_INLINE void Buffer::getAllocation( Allocation* pAllocation ) const VKMA_NOEXCEPT
  {
    d.vkmaGetBufferAllocation( m_buffer, reinterpret_cast< VkmaAllocation *>( pAllocation ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::Allocation Buffer::getAllocation(  ) const VKMA_NOEXCEPT
  {
    VKMA_NAMESPACE::Allocation allocation;
    d.vkmaGetBufferAllocation( m_buffer, reinterpret_cast<VkmaAllocation *>( &allocation ) );
    return allocation;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_INLINE void Image::get( VkImage* pImage ) const VKMA_NOEXCEPT
  {
    d.vkmaGetImage( m_image, pImage );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VkImage Image::get(  ) const VKMA_NOEXCEPT
  {
    VkImage image;
    d.vkmaGetImage( m_image, &image );
    return image;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  VKMA_INLINE void Image::getAllocation( Allocation* pAllocation ) const VKMA_NOEXCEPT
  {
    d.vkmaGetImageAllocation( m_image, reinterpret_cast< VkmaAllocation *>( pAllocation ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::Allocation Image::getAllocation(  ) const VKMA_NOEXCEPT
  {
    VKMA_NAMESPACE::Allocation allocation;
    d.vkmaGetImageAllocation( m_image, reinterpret_cast<VkmaAllocation *>( &allocation ) );
    return allocation;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/
} // namespace VKMA_NAMESPACE

namespace std
{

  template <> struct hash<VKMA_NAMESPACE::Allocation>
  {
    std::size_t operator()(VKMA_NAMESPACE::Allocation const& allocation) const VKMA_NOEXCEPT
    {
      return std::hash<VkmaAllocation>{}(static_cast<VkmaAllocation>(allocation));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::Allocator>
  {
    std::size_t operator()(VKMA_NAMESPACE::Allocator const& allocator) const VKMA_NOEXCEPT
    {
      return std::hash<VkmaAllocator>{}(static_cast<VkmaAllocator>(allocator));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::Buffer>
  {
    std::size_t operator()(VKMA_NAMESPACE::Buffer const& buffer) const VKMA_NOEXCEPT
    {
      return std::hash<VkmaBuffer>{}(static_cast<VkmaBuffer>(buffer));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::DefragmentationContext>
  {
    std::size_t operator()(VKMA_NAMESPACE::DefragmentationContext const& defragmentationContext) const VKMA_NOEXCEPT
    {
      return std::hash<VkmaDefragmentationContext>{}(static_cast<VkmaDefragmentationContext>(defragmentationContext));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::Image>
  {
    std::size_t operator()(VKMA_NAMESPACE::Image const& image) const VKMA_NOEXCEPT
    {
      return std::hash<VkmaImage>{}(static_cast<VkmaImage>(image));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::Pool>
  {
    std::size_t operator()(VKMA_NAMESPACE::Pool const& pool) const VKMA_NOEXCEPT
    {
      return std::hash<VkmaPool>{}(static_cast<VkmaPool>(pool));
    }
  };
}
#endif
