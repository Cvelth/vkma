// Copyright (c) 2021 Cvelth (cvelth.mail@gmail.com)
// SPDX-License-Identifier: Unlicense.
// 
// DO NOT MODIFY MANUALLY!
// This file was generated using [generator](https://github.com/Cvelth/vma_xml_generator).
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
#include <vulkan/vulkan.h>

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


static_assert( VMA_HEADER_VERSION ==  , "Wrong VMA_HEADER_VERSION!" );

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
    StructureChain() VKMA_NOEXCEPT
    {
      static_assert( StructureChainValidation<sizeof...( ChainElements ) - 1, ChainElements...>::valid,
                     "The structure chain is not valid!" );
      link<sizeof...( ChainElements ) - 1>();
    }

    StructureChain( StructureChain const & rhs ) VKMA_NOEXCEPT : std::tuple<ChainElements...>( rhs )
    {
      static_assert( StructureChainValidation<sizeof...( ChainElements ) - 1, ChainElements...>::valid,
                     "The structure chain is not valid!" );
      link<sizeof...( ChainElements ) - 1>();
    }

    StructureChain( StructureChain && rhs ) VKMA_NOEXCEPT
      : std::tuple<ChainElements...>( std::forward<std::tuple<ChainElements...>>( rhs ) )
    {
      static_assert( StructureChainValidation<sizeof...( ChainElements ) - 1, ChainElements...>::valid,
                     "The structure chain is not valid!" );
      link<sizeof...( ChainElements ) - 1>();
    }

    StructureChain( ChainElements const &... elems ) VKMA_NOEXCEPT : std::tuple<ChainElements...>( elems... )
    {
      static_assert( StructureChainValidation<sizeof...( ChainElements ) - 1, ChainElements...>::valid,
                     "The structure chain is not valid!" );
      link<sizeof...( ChainElements ) - 1>();
    }

    StructureChain & operator=( StructureChain const & rhs ) VKMA_NOEXCEPT
    {
      std::tuple<ChainElements...>::operator=( rhs );
      link<sizeof...( ChainElements ) - 1>();
      return *this;
    }

    StructureChain & operator=( StructureChain && rhs ) = delete;

    template <typename T = typename std::tuple_element<0, std::tuple<ChainElements...>>::type, size_t Which = 0>
    T & get() VKMA_NOEXCEPT
    {
      return std::get<ChainElementIndex<0, T, Which, void, ChainElements...>::value>( static_cast<std::tuple<ChainElements...>&>( *this ) );
    }

    template <typename T = typename std::tuple_element<0, std::tuple<ChainElements...>>::type, size_t Which = 0>
    T const & get() const VKMA_NOEXCEPT
    {
      return std::get<ChainElementIndex<0, T, Which, void, ChainElements...>::value>( static_cast<std::tuple<ChainElements...> const &>( *this ) );
    }

    template <typename T0, typename T1, typename... Ts>
    std::tuple<T0 &, T1 &, Ts &...> get() VKMA_NOEXCEPT
    {
      return std::tie( get<T0>(), get<T1>(), get<Ts>()... );
    }

    template <typename T0, typename T1, typename... Ts>
    std::tuple<T0 const &, T1 const &, Ts const &...> get() const VKMA_NOEXCEPT
    {
      return std::tie( get<T0>(), get<T1>(), get<Ts>()... );
    }

    template <typename ClassType, size_t Which = 0>
    void relink() VKMA_NOEXCEPT
    {
      static_assert( IsPartOfStructureChain<ClassType, ChainElements...>::valid,
                     "Can't relink Structure that's not part of this StructureChain!" );
      static_assert(
        !std::is_same<ClassType, typename std::tuple_element<0, std::tuple<ChainElements...>>::type>::value || (Which != 0),
        "It's not allowed to have the first element unlinked!" );

      auto pNext = reinterpret_cast<VmaBaseInStructure *>( &get<ClassType, Which>() );
      VKMA_ASSERT( !isLinked( pNext ) );
      auto & headElement = std::get<0>( static_cast<std::tuple<ChainElements...>&>( *this ) );
      pNext->pNext       = reinterpret_cast<VmaBaseInStructure const*>(headElement.pNext);
      headElement.pNext  = pNext;
    }

    template <typename ClassType, size_t Which = 0>
    void unlink() VKMA_NOEXCEPT
    {
      static_assert( IsPartOfStructureChain<ClassType, ChainElements...>::valid,
                     "Can't unlink Structure that's not part of this StructureChain!" );
      static_assert(
        !std::is_same<ClassType, typename std::tuple_element<0, std::tuple<ChainElements...>>::type>::value || (Which != 0),
        "It's not allowed to unlink the first element!" );

      unlink<sizeof...( ChainElements ) - 1>( reinterpret_cast<VmaBaseOutStructure const *>( &get<ClassType, Which>() ) );
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

    bool isLinked( VmaBaseInStructure const * pNext )
    {
      VmaBaseInStructure const * elementPtr = reinterpret_cast<VmaBaseInStructure const*>(&std::get<0>( static_cast<std::tuple<ChainElements...>&>( *this ) ) );
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
    typename std::enable_if<Index != 0, void>::type link() VKMA_NOEXCEPT
    {
      auto & x = std::get<Index - 1>( static_cast<std::tuple<ChainElements...>&>( *this ) );
      x.pNext  = &std::get<Index>( static_cast<std::tuple<ChainElements...>&>( *this ) );
      link<Index - 1>();
    }

    template <size_t Index>
    typename std::enable_if<Index == 0, void>::type link() VKMA_NOEXCEPT
    {}

    template <size_t Index>
    typename std::enable_if<Index != 0, void>::type unlink( VmaBaseOutStructure const * pNext ) VKMA_NOEXCEPT
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
    typename std::enable_if<Index == 0, void>::type unlink( VmaBaseOutStructure const * pNext ) VKMA_NOEXCEPT
    {
      auto & element = std::get<0>( static_cast<std::tuple<ChainElements...>&>( *this ) );
      if ( element.pNext == pNext )
      {
        element.pNext = pNext->pNext;
      }
      else
      {
        VKMA_ASSERT( false );  // fires, if the ClassType member has already been unlinked !
      }
    }
  };

#if !defined(VKMA_NO_SMART_HANDLE)
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

    void swap( UniqueHandle<Type,Dispatch> & rhs ) VKMA_NOEXCEPT
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

  template <typename Type, typename Dispatch>
  VKMA_INLINE void swap( UniqueHandle<Type,Dispatch> & lhs, UniqueHandle<Type,Dispatch> & rhs ) VKMA_NOEXCEPT
  {
    lhs.swap( rhs );
  }
#endif

#if !defined(VMA_NO_PROTOTYPES)
  class DispatchLoaderStatic
  {
  public:
    VkResult vmaAllocateMemory( VmaAllocator allocator, const VkMemoryRequirements* pVkMemoryRequirements, const VmaAllocationCreateInfo* pCreateInfo, VmaAllocation* pAllocation, VmaAllocationInfo* pAllocationInfo ) const VKMA_NOEXCEPT
    {
      return ::vmaAllocateMemory( allocator, pVkMemoryRequirements, pCreateInfo, pAllocation, pAllocationInfo );
    }

    VkResult vmaAllocateMemoryForBuffer( VmaAllocator allocator, VkBuffer buffer, const VmaAllocationCreateInfo* pCreateInfo, VmaAllocation* pAllocation, VmaAllocationInfo* pAllocationInfo ) const VKMA_NOEXCEPT
    {
      return ::vmaAllocateMemoryForBuffer( allocator, buffer, pCreateInfo, pAllocation, pAllocationInfo );
    }

    VkResult vmaAllocateMemoryForImage( VmaAllocator allocator, VkImage image, const VmaAllocationCreateInfo* pCreateInfo, VmaAllocation* pAllocation, VmaAllocationInfo* pAllocationInfo ) const VKMA_NOEXCEPT
    {
      return ::vmaAllocateMemoryForImage( allocator, image, pCreateInfo, pAllocation, pAllocationInfo );
    }

    VkResult vmaAllocateMemoryPages( VmaAllocator allocator, const VkMemoryRequirements* pVkMemoryRequirements, const VmaAllocationCreateInfo* pCreateInfo, size_t allocationCount, VmaAllocation* pAllocations, VmaAllocationInfo* pAllocationInfo ) const VKMA_NOEXCEPT
    {
      return ::vmaAllocateMemoryPages( allocator, pVkMemoryRequirements, pCreateInfo, allocationCount, pAllocations, pAllocationInfo );
    }

    VkResult vmaBindBufferMemory( VmaAllocator allocator, VmaAllocation allocation, VkBuffer buffer ) const VKMA_NOEXCEPT
    {
      return ::vmaBindBufferMemory( allocator, allocation, buffer );
    }

    VkResult vmaBindBufferMemory2( VmaAllocator allocator, VmaAllocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer, const void* pNext ) const VKMA_NOEXCEPT
    {
      return ::vmaBindBufferMemory2( allocator, allocation, allocationLocalOffset, buffer, pNext );
    }

    VkResult vmaBindImageMemory( VmaAllocator allocator, VmaAllocation allocation, VkImage image ) const VKMA_NOEXCEPT
    {
      return ::vmaBindImageMemory( allocator, allocation, image );
    }

    VkResult vmaBindImageMemory2( VmaAllocator allocator, VmaAllocation allocation, VkDeviceSize allocationLocalOffset, VkImage image, const void* pNext ) const VKMA_NOEXCEPT
    {
      return ::vmaBindImageMemory2( allocator, allocation, allocationLocalOffset, image, pNext );
    }

    void vmaBuildStatsString( VmaAllocator allocator, char** ppStatsString, VkBool32 detailedMap ) const VKMA_NOEXCEPT
    {
      return ::vmaBuildStatsString( allocator, ppStatsString, detailedMap );
    }

    void vmaCalculateStats( VmaAllocator allocator, VmaStats* pStats ) const VKMA_NOEXCEPT
    {
      return ::vmaCalculateStats( allocator, pStats );
    }

    VkResult vmaCheckCorruption( VmaAllocator allocator, uint32_t memoryTypeBits ) const VKMA_NOEXCEPT
    {
      return ::vmaCheckCorruption( allocator, memoryTypeBits );
    }

    VkResult vmaCheckPoolCorruption( VmaAllocator allocator, VmaPool pool ) const VKMA_NOEXCEPT
    {
      return ::vmaCheckPoolCorruption( allocator, pool );
    }

    VkResult vmaCreateAllocator( const VmaAllocatorCreateInfo* pCreateInfo, VmaAllocator* pAllocator ) const VKMA_NOEXCEPT
    {
      return ::vmaCreateAllocator( pCreateInfo, pAllocator );
    }

    VkResult vmaCreateBuffer( VmaAllocator allocator, const VkBufferCreateInfo* pBufferCreateInfo, const VmaAllocationCreateInfo* pAllocationCreateInfo, VkBuffer* pBuffer, VmaAllocation* pAllocation, VmaAllocationInfo* pAllocationInfo ) const VKMA_NOEXCEPT
    {
      return ::vmaCreateBuffer( allocator, pBufferCreateInfo, pAllocationCreateInfo, pBuffer, pAllocation, pAllocationInfo );
    }

    VkResult vmaCreateImage( VmaAllocator allocator, const VkImageCreateInfo* pImageCreateInfo, const VmaAllocationCreateInfo* pAllocationCreateInfo, VkImage* pImage, VmaAllocation* pAllocation, VmaAllocationInfo* pAllocationInfo ) const VKMA_NOEXCEPT
    {
      return ::vmaCreateImage( allocator, pImageCreateInfo, pAllocationCreateInfo, pImage, pAllocation, pAllocationInfo );
    }

    void vmaCreateLostAllocation( VmaAllocator allocator, VmaAllocation* pAllocation ) const VKMA_NOEXCEPT
    {
      return ::vmaCreateLostAllocation( allocator, pAllocation );
    }

    VkResult vmaCreatePool( VmaAllocator allocator, const VmaPoolCreateInfo* pCreateInfo, VmaPool* pPool ) const VKMA_NOEXCEPT
    {
      return ::vmaCreatePool( allocator, pCreateInfo, pPool );
    }

    VkResult vmaDefragment( VmaAllocator allocator, VmaAllocation* pAllocations, size_t allocationCount, VkBool32* pAllocationsChanged, const VmaDefragmentationInfo* pDefragmentationInfo, VmaDefragmentationStats* pDefragmentationStats ) const VKMA_NOEXCEPT
    {
      return ::vmaDefragment( allocator, pAllocations, allocationCount, pAllocationsChanged, pDefragmentationInfo, pDefragmentationStats );
    }

    VkResult vmaDefragmentationBegin( VmaAllocator allocator, const VmaDefragmentationInfo2* pInfo, VmaDefragmentationStats* pStats, VmaDefragmentationContext* pContext ) const VKMA_NOEXCEPT
    {
      return ::vmaDefragmentationBegin( allocator, pInfo, pStats, pContext );
    }

    VkResult vmaDefragmentationEnd( VmaAllocator allocator, VmaDefragmentationContext context ) const VKMA_NOEXCEPT
    {
      return ::vmaDefragmentationEnd( allocator, context );
    }

    void vmaDestroyAllocator( VmaAllocator allocator ) const VKMA_NOEXCEPT
    {
      return ::vmaDestroyAllocator( allocator );
    }

    void vmaDestroyBuffer( VmaAllocator allocator, VkBuffer buffer, VmaAllocation allocation ) const VKMA_NOEXCEPT
    {
      return ::vmaDestroyBuffer( allocator, buffer, allocation );
    }

    void vmaDestroyImage( VmaAllocator allocator, VkImage image, VmaAllocation allocation ) const VKMA_NOEXCEPT
    {
      return ::vmaDestroyImage( allocator, image, allocation );
    }

    void vmaDestroyPool( VmaAllocator allocator, VmaPool pool ) const VKMA_NOEXCEPT
    {
      return ::vmaDestroyPool( allocator, pool );
    }

    VkResult vmaFindMemoryTypeIndex( VmaAllocator allocator, uint32_t memoryTypeBits, const VmaAllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex ) const VKMA_NOEXCEPT
    {
      return ::vmaFindMemoryTypeIndex( allocator, memoryTypeBits, pAllocationCreateInfo, pMemoryTypeIndex );
    }

    VkResult vmaFindMemoryTypeIndexForBufferInfo( VmaAllocator allocator, const VkBufferCreateInfo* pBufferCreateInfo, const VmaAllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex ) const VKMA_NOEXCEPT
    {
      return ::vmaFindMemoryTypeIndexForBufferInfo( allocator, pBufferCreateInfo, pAllocationCreateInfo, pMemoryTypeIndex );
    }

    VkResult vmaFindMemoryTypeIndexForImageInfo( VmaAllocator allocator, const VkImageCreateInfo* pImageCreateInfo, const VmaAllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex ) const VKMA_NOEXCEPT
    {
      return ::vmaFindMemoryTypeIndexForImageInfo( allocator, pImageCreateInfo, pAllocationCreateInfo, pMemoryTypeIndex );
    }

    void vmaFlushAllocation( VmaAllocator allocator, VmaAllocation allocation, VkDeviceSize offset, VkDeviceSize size ) const VKMA_NOEXCEPT
    {
      return ::vmaFlushAllocation( allocator, allocation, offset, size );
    }

    void vmaFreeMemory( VmaAllocator allocator, VmaAllocation allocation ) const VKMA_NOEXCEPT
    {
      return ::vmaFreeMemory( allocator, allocation );
    }

    void vmaFreeMemoryPages( VmaAllocator allocator, size_t allocationCount, VmaAllocation* pAllocations ) const VKMA_NOEXCEPT
    {
      return ::vmaFreeMemoryPages( allocator, allocationCount, pAllocations );
    }

    void vmaFreeStatsString( VmaAllocator allocator, char* pStatsString ) const VKMA_NOEXCEPT
    {
      return ::vmaFreeStatsString( allocator, pStatsString );
    }

    void vmaGetAllocationInfo( VmaAllocator allocator, VmaAllocation allocation, VmaAllocationInfo* pAllocationInfo ) const VKMA_NOEXCEPT
    {
      return ::vmaGetAllocationInfo( allocator, allocation, pAllocationInfo );
    }

    void vmaGetBudget( VmaAllocator allocator, VmaBudget* pBudget ) const VKMA_NOEXCEPT
    {
      return ::vmaGetBudget( allocator, pBudget );
    }

    void vmaGetMemoryProperties( VmaAllocator allocator, const VkPhysicalDeviceMemoryProperties** ppPhysicalDeviceMemoryProperties ) const VKMA_NOEXCEPT
    {
      return ::vmaGetMemoryProperties( allocator, ppPhysicalDeviceMemoryProperties );
    }

    void vmaGetMemoryTypeProperties( VmaAllocator allocator, uint32_t memoryTypeIndex, VkMemoryPropertyFlags* pFlags ) const VKMA_NOEXCEPT
    {
      return ::vmaGetMemoryTypeProperties( allocator, memoryTypeIndex, pFlags );
    }

    void vmaGetPhysicalDeviceProperties( VmaAllocator allocator, const VkPhysicalDeviceProperties** ppPhysicalDeviceProperties ) const VKMA_NOEXCEPT
    {
      return ::vmaGetPhysicalDeviceProperties( allocator, ppPhysicalDeviceProperties );
    }

    void vmaGetPoolName( VmaAllocator allocator, VmaPool pool, const char** ppName ) const VKMA_NOEXCEPT
    {
      return ::vmaGetPoolName( allocator, pool, ppName );
    }

    void vmaGetPoolStats( VmaAllocator allocator, VmaPool pool, VmaPoolStats* pPoolStats ) const VKMA_NOEXCEPT
    {
      return ::vmaGetPoolStats( allocator, pool, pPoolStats );
    }

    void vmaInvalidateAllocation( VmaAllocator allocator, VmaAllocation allocation, VkDeviceSize offset, VkDeviceSize size ) const VKMA_NOEXCEPT
    {
      return ::vmaInvalidateAllocation( allocator, allocation, offset, size );
    }

    void vmaMakePoolAllocationsLost( VmaAllocator allocator, VmaPool pool, size_t* pLostAllocationCount ) const VKMA_NOEXCEPT
    {
      return ::vmaMakePoolAllocationsLost( allocator, pool, pLostAllocationCount );
    }

    VkResult vmaMapMemory( VmaAllocator allocator, VmaAllocation allocation, void** ppData ) const VKMA_NOEXCEPT
    {
      return ::vmaMapMemory( allocator, allocation, ppData );
    }

    VkResult vmaResizeAllocation( VmaAllocator allocator, VmaAllocation allocation, VkDeviceSize newSize ) const VKMA_NOEXCEPT
    {
      return ::vmaResizeAllocation( allocator, allocation, newSize );
    }

    void vmaSetAllocationUserData( VmaAllocator allocator, VmaAllocation allocation, void* pUserData ) const VKMA_NOEXCEPT
    {
      return ::vmaSetAllocationUserData( allocator, allocation, pUserData );
    }

    void vmaSetCurrentFrameIndex( VmaAllocator allocator, uint32_t frameIndex ) const VKMA_NOEXCEPT
    {
      return ::vmaSetCurrentFrameIndex( allocator, frameIndex );
    }

    void vmaSetPoolName( VmaAllocator allocator, VmaPool pool, const char* pName ) const VKMA_NOEXCEPT
    {
      return ::vmaSetPoolName( allocator, pool, pName );
    }

    VkBool32 vmaTouchAllocation( VmaAllocator allocator, VmaAllocation allocation ) const VKMA_NOEXCEPT
    {
      return ::vmaTouchAllocation( allocator, allocation );
    }

    void vmaUnmapMemory( VmaAllocator allocator, VmaAllocation allocation ) const VKMA_NOEXCEPT
    {
      return ::vmaUnmapMemory( allocator, allocation );
    }
  };
#endif

  class DispatchLoaderDynamic;
#if !defined(VKMA_DISPATCH_LOADER_DYNAMIC)
# if defined(VMA_NO_PROTOTYPES)
#  define VKMA_DISPATCH_LOADER_DYNAMIC 1
# else
#  define VKMA_DISPATCH_LOADER_DYNAMIC 0
# endif
#endif

#if defined(_WIN32) && defined(VKMA_STORAGE_SHARED)
#  ifdef VKMA_STORAGE_SHARED_EXPORT
#    define VKMA_STORAGE_API __declspec( dllexport )
#  else
#    define VKMA_STORAGE_API __declspec( dllimport )
#  endif
#else
#  define VKMA_STORAGE_API
#endif

#if !defined(VKMA_DEFAULT_DISPATCHER)
# if VKMA_DISPATCH_LOADER_DYNAMIC == 1
#  define VKMA_DEFAULT_DISPATCHER ::VKMA_NAMESPACE::defaultDispatchLoaderDynamic
#  define VKMA_DEFAULT_DISPATCH_LOADER_DYNAMIC_STORAGE namespace VKMA_NAMESPACE { VKMA_STORAGE_API DispatchLoaderDynamic defaultDispatchLoaderDynamic; }
  extern VKMA_STORAGE_API DispatchLoaderDynamic defaultDispatchLoaderDynamic;
# else
#  define VKMA_DEFAULT_DISPATCHER ::VKMA_NAMESPACE::DispatchLoaderStatic()
#  define VKMA_DEFAULT_DISPATCH_LOADER_DYNAMIC_STORAGE
# endif
#endif

#if !defined(VKMA_DEFAULT_DISPATCHER_TYPE)
# if VKMA_DISPATCH_LOADER_DYNAMIC == 1
  #define VKMA_DEFAULT_DISPATCHER_TYPE ::VKMA_NAMESPACE::DispatchLoaderDynamic
# else
#  define VKMA_DEFAULT_DISPATCHER_TYPE ::VKMA_NAMESPACE::DispatchLoaderStatic
# endif
#endif

#if defined( VKMA_NO_DEFAULT_DISPATCHER )
#  define VKMA_DEFAULT_ARGUMENT_ASSIGNMENT
#  define VKMA_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT
#  define VKMA_DEFAULT_DISPATCHER_ASSIGNMENT
#else
#  define VKMA_DEFAULT_ARGUMENT_ASSIGNMENT = {}
#  define VKMA_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT = nullptr
#  define VKMA_DEFAULT_DISPATCHER_ASSIGNMENT = VKMA_DEFAULT_DISPATCHER
#endif

  struct AllocationCallbacks;

  template <typename OwnerType, typename Dispatch>
  class ObjectDestroy
  {
    public:
    ObjectDestroy() = default;

    ObjectDestroy( OwnerType owner,
                   Optional<const AllocationCallbacks> allocationCallbacks
                                    VKMA_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT,
                   Dispatch const & dispatch = VKMA_DEFAULT_DISPATCHER ) VKMA_NOEXCEPT
      : m_owner( owner )
      , m_allocationCallbacks( allocationCallbacks )
      , m_dispatch( &dispatch )
    {}

      OwnerType getOwner() const VKMA_NOEXCEPT { return m_owner; }
      Optional<const AllocationCallbacks> getAllocator() const VKMA_NOEXCEPT { return m_allocationCallbacks; }

    protected:
      template <typename T>
      void destroy(T t) VKMA_NOEXCEPT
      {
        VKMA_ASSERT( m_owner && m_dispatch );
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
                   Dispatch const &                    dispatch = VKMA_DEFAULT_DISPATCHER ) VKMA_NOEXCEPT
      : m_allocationCallbacks( allocationCallbacks )
      , m_dispatch( &dispatch )
    {}

      Optional<const AllocationCallbacks> getAllocator() const VKMA_NOEXCEPT { return m_allocationCallbacks; }

    protected:
      template <typename T>
      void destroy(T t) VKMA_NOEXCEPT
      {
        VKMA_ASSERT( m_dispatch );
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
                Optional<const AllocationCallbacks> allocationCallbacks VKMA_DEFAULT_ARGUMENT_NULLPTR_ASSIGNMENT,
                Dispatch const & dispatch = VKMA_DEFAULT_DISPATCHER ) VKMA_NOEXCEPT
      : m_owner( owner )
      , m_allocationCallbacks( allocationCallbacks )
      , m_dispatch( &dispatch )
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
      VKMA_ASSERT( m_owner && m_dispatch );
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

    ObjectRelease( OwnerType owner, Dispatch const & dispatch = VKMA_DEFAULT_DISPATCHER ) VKMA_NOEXCEPT
      : m_owner( owner )
      , m_dispatch( &dispatch )
    {}

    OwnerType getOwner() const VKMA_NOEXCEPT
    {
      return m_owner;
    }

  protected:
    template <typename T>
    void destroy( T t ) VKMA_NOEXCEPT
    {
      VKMA_ASSERT( m_owner && m_dispatch );
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
                Dispatch const & dispatch = VKMA_DEFAULT_DISPATCHER ) VKMA_NOEXCEPT
        : m_owner( owner )
        , m_pool( pool )
        , m_dispatch( &dispatch )
      {}

      OwnerType getOwner() const VKMA_NOEXCEPT { return m_owner; }
      PoolType getPool() const VKMA_NOEXCEPT { return m_pool; }

    protected:
      template <typename T>
      void destroy(T t) VKMA_NOEXCEPT
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
    static VKMA_CONST_OR_CONSTEXPR bool value = false;
  };

  VKMA_INLINE std::string toHexString( uint32_t value )
  {
    std::stringstream stream;
    stream << std::hex << value;
    return stream.str();
  }

  enum class VkDebugReportObjectTypeEXT
  {};

  VKMA_INLINE std::string to_string( VkDebugReportObjectTypeEXT )
  {
    return "(void)";
  }

  enum class VkIndexType
  {
    eUint16 = VK_INDEX_TYPE_UINT16,
    eUint32 = VK_INDEX_TYPE_UINT32
  };

  VKMA_INLINE std::string to_string( VkIndexType value )
  {
    switch ( value )
    {
      case VkIndexType::eUint16 : return "Uint16";
      case VkIndexType::eUint32 : return "Uint32";
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class VkObjectType
  {
    eVmaAllocation = VK_OBJECT_TYPE_VMA_ALLOCATION,
    eVmaAllocator = VK_OBJECT_TYPE_VMA_ALLOCATOR,
    eVmaDefragmentationContext = VK_OBJECT_TYPE_VMA_DEFRAGMENTATION_CONTEXT,
    eVmaPool = VK_OBJECT_TYPE_VMA_POOL
  };

  VKMA_INLINE std::string to_string( VkObjectType value )
  {
    switch ( value )
    {
      case VkObjectType::eVmaAllocation : return "VmaAllocation";
      case VkObjectType::eVmaAllocator : return "VmaAllocator";
      case VkObjectType::eVmaDefragmentationContext : return "VmaDefragmentationContext";
      case VkObjectType::eVmaPool : return "VmaPool";
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  template<ObjectType value>
  struct cpp_type
  {};

  enum class VkResult
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
    eVkErrorSurfaceLostKhr = VK_ERROR_SURFACE_LOST_KHR,
    eVkErrorNativeWindowInUseKhr = VK_ERROR_NATIVE_WINDOW_IN_USE_KHR,
    eVkSuboptimalKhr = VK_SUBOPTIMAL_KHR,
    eVkErrorOutOfDateKhr = VK_ERROR_OUT_OF_DATE_KHR,
    eVkErrorIncompatibleDisplayKhr = VK_ERROR_INCOMPATIBLE_DISPLAY_KHR,
    eVkErrorValidationFailedExt = VK_ERROR_VALIDATION_FAILED_EXT,
    eVkErrorInvalidShaderNv = VK_ERROR_INVALID_SHADER_NV
  };

  VKMA_INLINE std::string to_string( VkResult value )
  {
    switch ( value )
    {
      case VkResult::eVkSuccess : return "VkSuccess";
      case VkResult::eVkNotReady : return "VkNotReady";
      case VkResult::eVkTimeout : return "VkTimeout";
      case VkResult::eVkEventSet : return "VkEventSet";
      case VkResult::eVkEventReset : return "VkEventReset";
      case VkResult::eVkIncomplete : return "VkIncomplete";
      case VkResult::eVkErrorOutOfHostMemory : return "VkErrorOutOfHostMemory";
      case VkResult::eVkErrorOutOfDeviceMemory : return "VkErrorOutOfDeviceMemory";
      case VkResult::eVkErrorInitializationFailed : return "VkErrorInitializationFailed";
      case VkResult::eVkErrorDeviceLost : return "VkErrorDeviceLost";
      case VkResult::eVkErrorMemoryMapFailed : return "VkErrorMemoryMapFailed";
      case VkResult::eVkErrorLayerNotPresent : return "VkErrorLayerNotPresent";
      case VkResult::eVkErrorExtensionNotPresent : return "VkErrorExtensionNotPresent";
      case VkResult::eVkErrorFeatureNotPresent : return "VkErrorFeatureNotPresent";
      case VkResult::eVkErrorIncompatibleDriver : return "VkErrorIncompatibleDriver";
      case VkResult::eVkErrorTooManyObjects : return "VkErrorTooManyObjects";
      case VkResult::eVkErrorFormatNotSupported : return "VkErrorFormatNotSupported";
      case VkResult::eVkErrorFragmentedPool : return "VkErrorFragmentedPool";
      case VkResult::eVkErrorSurfaceLostKhr : return "VkErrorSurfaceLostKhr";
      case VkResult::eVkErrorNativeWindowInUseKhr : return "VkErrorNativeWindowInUseKhr";
      case VkResult::eVkSuboptimalKhr : return "VkSuboptimalKhr";
      case VkResult::eVkErrorOutOfDateKhr : return "VkErrorOutOfDateKhr";
      case VkResult::eVkErrorIncompatibleDisplayKhr : return "VkErrorIncompatibleDisplayKhr";
      case VkResult::eVkErrorValidationFailedExt : return "VkErrorValidationFailedExt";
      case VkResult::eVkErrorInvalidShaderNv : return "VkErrorInvalidShaderNv";
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class VkStructureType
  {};

  VKMA_INLINE std::string to_string( VkStructureType )
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

  VKMA_INLINE std::string to_string( AllocationCreateFlagBits value )
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
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
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

  VKMA_INLINE std::string to_string( AllocatorCreateFlagBits value )
  {
    switch ( value )
    {
      case AllocatorCreateFlagBits::eExternallySynchronized : return "ExternallySynchronized";
      case AllocatorCreateFlagBits::eKhrDedicatedAllocation : return "KhrDedicatedAllocation";
      case AllocatorCreateFlagBits::eKhrBindMemory2 : return "KhrBindMemory2";
      case AllocatorCreateFlagBits::eExtMemoryBudget : return "ExtMemoryBudget";
      case AllocatorCreateFlagBits::eFlagsMaxEnum : return "FlagsMaxEnum";
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class DefragmentationFlagBits : VmaDefragmentationFlags
  {
    eFlagsMaxEnum = VMA_DEFRAGMENTATION_FLAG_BITS_MAX_ENUM
  };

  VKMA_INLINE std::string to_string( DefragmentationFlagBits value )
  {
    switch ( value )
    {
      case DefragmentationFlagBits::eFlagsMaxEnum : return "FlagsMaxEnum";
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
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

  VKMA_INLINE std::string to_string( MemoryUsage value )
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
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
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

  VKMA_INLINE std::string to_string( PoolCreateFlagBits value )
  {
    switch ( value )
    {
      case PoolCreateFlagBits::eIgnoreBufferImageGranularity : return "IgnoreBufferImageGranularity";
      case PoolCreateFlagBits::eLinearAlgorithm : return "LinearAlgorithm";
      case PoolCreateFlagBits::eBuddyAlgorithm : return "BuddyAlgorithm";
      case PoolCreateFlagBits::eAlgorithmMask : return "AlgorithmMask";
      case PoolCreateFlagBits::eFlagsMaxEnum : return "FlagsMaxEnum";
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  enum class RecordFlagBits : VmaRecordFlags
  {
    eFlushAfterCall = VMA_RECORD_FLUSH_AFTER_CALL_BIT,
    eFlagsMaxEnum = VMA_RECORD_FLAG_BITS_MAX_ENUM
  };

  VKMA_INLINE std::string to_string( RecordFlagBits value )
  {
    switch ( value )
    {
      case RecordFlagBits::eFlushAfterCall : return "FlushAfterCall";
      case RecordFlagBits::eFlagsMaxEnum : return "FlagsMaxEnum";
      default: return "invalid ( " + VKMA_NAMESPACE::toHexString( static_cast<uint32_t>( value ) ) + " )";
    }
  }

  template<typename T>
  struct IndexTypeValue
  {};

  template <>
  struct IndexTypeValue<uint16_t>
  {
    static VKMA_CONST_OR_CONSTEXPR IndexType value = IndexType::eUint16;
  };

  template <>
  struct CppType<IndexType, IndexType::eUint16>
  {
    using Type = uint16_t;
  };

  template <>
  struct IndexTypeValue<uint32_t>
  {
    static VKMA_CONST_OR_CONSTEXPR IndexType value = IndexType::eUint32;
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
      allFlags = VkFlags(AllocatorCreateFlagBits::eExternallySynchronized) | VkFlags(AllocatorCreateFlagBits::eKhrDedicatedAllocation) | VkFlags(AllocatorCreateFlagBits::eKhrBindMemory2) | VkFlags(AllocatorCreateFlagBits::eExtMemoryBudget) | VkFlags(AllocatorCreateFlagBits::eFlagsMaxEnum)
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

  template <> struct FlagTraits<DefragmentationFlagBits>
  {
    enum : VkFlags
    {
      allFlags = VkFlags(DefragmentationFlagBits::eFlagsMaxEnum)
    };
  };

  VKMA_INLINE VKMA_CONSTEXPR DefragmentationFlags operator|( DefragmentationFlagBits bit0, DefragmentationFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return DefragmentationFlags( bit0 ) | bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR DefragmentationFlags operator&( DefragmentationFlagBits bit0, DefragmentationFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return DefragmentationFlags( bit0 ) & bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR DefragmentationFlags operator^( DefragmentationFlagBits bit0, DefragmentationFlagBits bit1 ) VKMA_NOEXCEPT
  {
    return DefragmentationFlags( bit0 ) ^ bit1;
  }

  VKMA_INLINE VKMA_CONSTEXPR DefragmentationFlags operator~( DefragmentationFlagBits bits ) VKMA_NOEXCEPT
  {
    return ~( DefragmentationFlags( bits ) );
  }

  VKMA_INLINE std::string to_string( DefragmentationFlags value  )
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
      allFlags = VkFlags(RecordFlagBits::eFlushAfterCall) | VkFlags(RecordFlagBits::eFlagsMaxEnum)
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
  template <typename Type, typename Dispatch>
  struct ResultValue<UniqueHandle<Type,Dispatch>>
  {
#ifdef VKMA_HAS_NOEXCEPT
    ResultValue(Result r, UniqueHandle<Type, Dispatch> && v) VKMA_NOEXCEPT
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

#  if !defined(VKMA_DISABLE_IMPLICIT_RESULT_VALUE_CAST)
    VKMA_DEPRECATED("Implicit-cast operators on vkma::ResultValue are deprecated. Explicitly access the value as member of ResultValue.")
    operator UniqueHandle<Type, Dispatch>& () & VKMA_NOEXCEPT
    {
      return value;
    }

    VKMA_DEPRECATED("Implicit-cast operators on vkma::ResultValue are deprecated. Explicitly access the value as member of ResultValue.")
    operator UniqueHandle<Type, Dispatch>() VKMA_NOEXCEPT
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
#  ifdef VKMA_HAS_NOEXCEPT
    ResultValue( Result r, std::vector<UniqueHandle<Type, Dispatch>> && v ) VKMA_NOEXCEPT
#  else
    ResultValue( Result r, std::vector<UniqueHandle<Type, Dispatch>> && v )
#  endif
      : result( r )
      , value( std::move( v ) )
    {}

    Result                                    result;
    std::vector<UniqueHandle<Type, Dispatch>> value;

    operator std::tuple<Result &, std::vector<UniqueHandle<Type, Dispatch>> &>() VKMA_NOEXCEPT
    {
      return std::tuple<Result &, std::vector<UniqueHandle<Type, Dispatch>> &>( result, value );
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
    using CType = VmaPool;

    static VKMA_CONST_OR_CONSTEXPR VKMA_NAMESPACE::ObjectType objectType = VKMA_NAMESPACE::ObjectType::eVmaPool;
    static VKMA_CONST_OR_CONSTEXPR VKMA_NAMESPACE::DebugReportObjectTypeEXT debugReportObjectType = VKMA_NAMESPACE::DebugReportObjectTypeEXT::eUnknown;

  public:
    VKMA_CONSTEXPR Pool() VKMA_NOEXCEPT
      : m_pool(VMA_NULL_HANDLE)
    {}

    VKMA_CONSTEXPR Pool( std::nullptr_t ) VKMA_NOEXCEPT
      : m_pool(VMA_NULL_HANDLE)
    {}

    VKMA_TYPESAFE_EXPLICIT Pool( VmaPool pool ) VKMA_NOEXCEPT
      : m_pool( pool )
    {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    Pool & operator=(VmaPool pool) VKMA_NOEXCEPT
    {
      m_pool = pool;
      return *this;
    }
#endif

    Pool & operator=( std::nullptr_t ) VKMA_NOEXCEPT
    {
      m_pool = VMA_NULL_HANDLE;
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

    VKMA_TYPESAFE_EXPLICIT operator VmaPool() const VKMA_NOEXCEPT
    {
      return m_pool;
    }

    explicit operator bool() const VKMA_NOEXCEPT
    {
      return m_pool != VMA_NULL_HANDLE;
    }

    bool operator!() const VKMA_NOEXCEPT
    {
      return m_pool == VMA_NULL_HANDLE;
    }

  private:
    VmaPool m_pool;
  };
  static_assert( sizeof( VKMA_NAMESPACE::Pool ) == sizeof( VmaPool ), "handle and wrapper have different size!" );

  template <>
  struct VKMA_DEPRECATED("vma::cpp_type is deprecated. Use vma::CppType instead.") cpp_type<ObjectType::eVmaPool>
  {
    using type = VKMA_NAMESPACE::Pool;
  };

  template <>
  struct CppType<VKMA_NAMESPACE::ObjectType, VKMA_NAMESPACE::ObjectType::eVmaPool>
  {
    using Type = VKMA_NAMESPACE::Pool;
  };



  template <>
  struct isVulkanHandleType<VKMA_NAMESPACE::Pool>
  {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

  struct AllocationCreateInfo
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR AllocationCreateInfo(AllocationCreateFlags flags_ = {}, MemoryUsage usage_ = VKMA_NAMESPACE::MemoryUsage::eUnknown, VkMemoryPropertyFlags requiredFlags_ = {}, VkMemoryPropertyFlags preferredFlags_ = {}, uint32_t memoryTypeBits_ = {}, Pool pool_ = {}, void* pUserData_ = {}) VKMA_NOEXCEPT
    : flags( flags_ ), usage( usage_ ), requiredFlags( requiredFlags_ ), preferredFlags( preferredFlags_ ), memoryTypeBits( memoryTypeBits_ ), pool( pool_ ), pUserData( pUserData_ )
    {}

    VKMA_CONSTEXPR AllocationCreateInfo( AllocationCreateInfo const & rhs ) VKMA_NOEXCEPT = default;

    AllocationCreateInfo( VmaAllocationCreateInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    AllocationCreateInfo & operator=( VmaAllocationCreateInfo const & rhs ) VKMA_NOEXCEPT
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


    operator VmaAllocationCreateInfo const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VmaAllocationCreateInfo*>( this );
    }

    operator VmaAllocationCreateInfo &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VmaAllocationCreateInfo*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( AllocationCreateInfo const& ) const = default;
#else
    bool operator==( AllocationCreateInfo const& rhs ) const VKMA_NOEXCEPT
    {
      return ( flags == rhs.flags )
          && ( usage == rhs.usage )
          && ( memcmp( &requiredFlags, &rhs.requiredFlags, sizeof( VkMemoryPropertyFlags ) ) == 0 )
          && ( memcmp( &preferredFlags, &rhs.preferredFlags, sizeof( VkMemoryPropertyFlags ) ) == 0 )
          && ( memoryTypeBits == rhs.memoryTypeBits )
          && ( pool == rhs.pool )
          && ( pUserData == rhs.pUserData );
    }

    bool operator!=( AllocationCreateInfo const& rhs ) const VKMA_NOEXCEPT
    {
      return !operator==( rhs );
    }
#endif



  public:
    AllocationCreateFlags flags = {};
    MemoryUsage usage = VKMA_NAMESPACE::MemoryUsage::eUnknown;
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


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR AllocationInfo(uint32_t memoryType_ = {}, VkDeviceMemory deviceMemory_ = {}, VkDeviceSize offset_ = {}, VkDeviceSize size_ = {}, void* pMappedData_ = {}, void* pUserData_ = {}) VKMA_NOEXCEPT
    : memoryType( memoryType_ ), deviceMemory( deviceMemory_ ), offset( offset_ ), size( size_ ), pMappedData( pMappedData_ ), pUserData( pUserData_ )
    {}

    VKMA_CONSTEXPR AllocationInfo( AllocationInfo const & rhs ) VKMA_NOEXCEPT = default;

    AllocationInfo( VmaAllocationInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    AllocationInfo & operator=( VmaAllocationInfo const & rhs ) VKMA_NOEXCEPT
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


    operator VmaAllocationInfo const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VmaAllocationInfo*>( this );
    }

    operator VmaAllocationInfo &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VmaAllocationInfo*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( AllocationInfo const& ) const = default;
#else
    bool operator==( AllocationInfo const& rhs ) const VKMA_NOEXCEPT
    {
      return ( memoryType == rhs.memoryType )
          && ( memcmp( &deviceMemory, &rhs.deviceMemory, sizeof( VkDeviceMemory ) ) == 0 )
          && ( memcmp( &offset, &rhs.offset, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &size, &rhs.size, sizeof( VkDeviceSize ) ) == 0 )
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
  static_assert( sizeof( AllocationInfo ) == sizeof( VmaAllocationInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<AllocationInfo>::value, "struct wrapper is not a standard layout!" );

  struct DeviceMemoryCallbacks
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR DeviceMemoryCallbacks(PFN_vmaAllocateDeviceMemoryFunction pfnAllocate_ = {}, PFN_vmaFreeDeviceMemoryFunction pfnFree_ = {}) VKMA_NOEXCEPT
    : pfnAllocate( pfnAllocate_ ), pfnFree( pfnFree_ )
    {}

    VKMA_CONSTEXPR DeviceMemoryCallbacks( DeviceMemoryCallbacks const & rhs ) VKMA_NOEXCEPT = default;

    DeviceMemoryCallbacks( VmaDeviceMemoryCallbacks const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    DeviceMemoryCallbacks & operator=( VmaDeviceMemoryCallbacks const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::DeviceMemoryCallbacks const *>( &rhs );
      return *this;
    }

    DeviceMemoryCallbacks & operator=( DeviceMemoryCallbacks const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( DeviceMemoryCallbacks ) );
      return *this;
    }

    DeviceMemoryCallbacks & setPfnAllocate( PFN_vmaAllocateDeviceMemoryFunction pfnAllocate_ ) VKMA_NOEXCEPT
    {
      pfnAllocate = pfnAllocate_;
      return *this;
    }

    DeviceMemoryCallbacks & setPfnFree( PFN_vmaFreeDeviceMemoryFunction pfnFree_ ) VKMA_NOEXCEPT
    {
      pfnFree = pfnFree_;
      return *this;
    }


    operator VmaDeviceMemoryCallbacks const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VmaDeviceMemoryCallbacks*>( this );
    }

    operator VmaDeviceMemoryCallbacks &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VmaDeviceMemoryCallbacks*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( DeviceMemoryCallbacks const& ) const = default;
#else
    bool operator==( DeviceMemoryCallbacks const& rhs ) const VKMA_NOEXCEPT
    {
      return ( pfnAllocate == rhs.pfnAllocate )
          && ( pfnFree == rhs.pfnFree );
    }

    bool operator!=( DeviceMemoryCallbacks const& rhs ) const VKMA_NOEXCEPT
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


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR VulkanFunctions(PFN_vkGetPhysicalDeviceProperties vkGetPhysicalDeviceProperties_ = {}, PFN_vkGetPhysicalDeviceMemoryProperties vkGetPhysicalDeviceMemoryProperties_ = {}, PFN_vkAllocateMemory vkAllocateMemory_ = {}, PFN_vkFreeMemory vkFreeMemory_ = {}, PFN_vkMapMemory vkMapMemory_ = {}, PFN_vkUnmapMemory vkUnmapMemory_ = {}, PFN_vkFlushMappedMemoryRanges vkFlushMappedMemoryRanges_ = {}, PFN_vkInvalidateMappedMemoryRanges vkInvalidateMappedMemoryRanges_ = {}, PFN_vkBindBufferMemory vkBindBufferMemory_ = {}, PFN_vkBindImageMemory vkBindImageMemory_ = {}, PFN_vkGetBufferMemoryRequirements vkGetBufferMemoryRequirements_ = {}, PFN_vkGetImageMemoryRequirements vkGetImageMemoryRequirements_ = {}, PFN_vkCreateBuffer vkCreateBuffer_ = {}, PFN_vkDestroyBuffer vkDestroyBuffer_ = {}, PFN_vkCreateImage vkCreateImage_ = {}, PFN_vkDestroyImage vkDestroyImage_ = {}, PFN_vkCmdCopyBuffer vkCmdCopyBuffer_ = {}) VKMA_NOEXCEPT
    : vkGetPhysicalDeviceProperties( vkGetPhysicalDeviceProperties_ ), vkGetPhysicalDeviceMemoryProperties( vkGetPhysicalDeviceMemoryProperties_ ), vkAllocateMemory( vkAllocateMemory_ ), vkFreeMemory( vkFreeMemory_ ), vkMapMemory( vkMapMemory_ ), vkUnmapMemory( vkUnmapMemory_ ), vkFlushMappedMemoryRanges( vkFlushMappedMemoryRanges_ ), vkInvalidateMappedMemoryRanges( vkInvalidateMappedMemoryRanges_ ), vkBindBufferMemory( vkBindBufferMemory_ ), vkBindImageMemory( vkBindImageMemory_ ), vkGetBufferMemoryRequirements( vkGetBufferMemoryRequirements_ ), vkGetImageMemoryRequirements( vkGetImageMemoryRequirements_ ), vkCreateBuffer( vkCreateBuffer_ ), vkDestroyBuffer( vkDestroyBuffer_ ), vkCreateImage( vkCreateImage_ ), vkDestroyImage( vkDestroyImage_ ), vkCmdCopyBuffer( vkCmdCopyBuffer_ )
    {}

    VKMA_CONSTEXPR VulkanFunctions( VulkanFunctions const & rhs ) VKMA_NOEXCEPT = default;

    VulkanFunctions( VmaVulkanFunctions const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    VulkanFunctions & operator=( VmaVulkanFunctions const & rhs ) VKMA_NOEXCEPT
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


    operator VmaVulkanFunctions const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VmaVulkanFunctions*>( this );
    }

    operator VmaVulkanFunctions &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VmaVulkanFunctions*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( VulkanFunctions const& ) const = default;
#else
    bool operator==( VulkanFunctions const& rhs ) const VKMA_NOEXCEPT
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
  static_assert( sizeof( VulkanFunctions ) == sizeof( VmaVulkanFunctions ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<VulkanFunctions>::value, "struct wrapper is not a standard layout!" );

  struct RecordSettings
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR RecordSettings(RecordFlags flags_ = {}, const char* pFilePath_ = {}) VKMA_NOEXCEPT
    : flags( flags_ ), pFilePath( pFilePath_ )
    {}

    VKMA_CONSTEXPR RecordSettings( RecordSettings const & rhs ) VKMA_NOEXCEPT = default;

    RecordSettings( VmaRecordSettings const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    RecordSettings & operator=( VmaRecordSettings const & rhs ) VKMA_NOEXCEPT
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


    operator VmaRecordSettings const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VmaRecordSettings*>( this );
    }

    operator VmaRecordSettings &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VmaRecordSettings*>( this );
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
  static_assert( sizeof( RecordSettings ) == sizeof( VmaRecordSettings ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<RecordSettings>::value, "struct wrapper is not a standard layout!" );

  struct AllocatorCreateInfo
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR AllocatorCreateInfo(AllocatorCreateFlags flags_ = {}, VkPhysicalDevice physicalDevice_ = {}, VkDevice device_ = {}, VkDeviceSize preferredLargeHeapBlockSize_ = {}, const VkAllocationCallbacks* pAllocationCallbacks_ = {}, const DeviceMemoryCallbacks* pDeviceMemoryCallbacks_ = {}, uint32_t frameInUseCount_ = {}, const VkDeviceSize* pHeapSizeLimit_ = {}, const VulkanFunctions* pVulkanFunctions_ = {}, const RecordSettings* pRecordSettings_ = {}, VkInstance instance_ = {}, uint32_t vulkanApiVersion_ = {}) VKMA_NOEXCEPT
    : flags( flags_ ), physicalDevice( physicalDevice_ ), device( device_ ), preferredLargeHeapBlockSize( preferredLargeHeapBlockSize_ ), pAllocationCallbacks( pAllocationCallbacks_ ), pDeviceMemoryCallbacks( pDeviceMemoryCallbacks_ ), frameInUseCount( frameInUseCount_ ), pHeapSizeLimit( pHeapSizeLimit_ ), pVulkanFunctions( pVulkanFunctions_ ), pRecordSettings( pRecordSettings_ ), instance( instance_ ), vulkanApiVersion( vulkanApiVersion_ )
    {}

    VKMA_CONSTEXPR AllocatorCreateInfo( AllocatorCreateInfo const & rhs ) VKMA_NOEXCEPT = default;

    AllocatorCreateInfo( VmaAllocatorCreateInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    AllocatorCreateInfo & operator=( VmaAllocatorCreateInfo const & rhs ) VKMA_NOEXCEPT
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


    operator VmaAllocatorCreateInfo const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VmaAllocatorCreateInfo*>( this );
    }

    operator VmaAllocatorCreateInfo &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VmaAllocatorCreateInfo*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( AllocatorCreateInfo const& ) const = default;
#else
    bool operator==( AllocatorCreateInfo const& rhs ) const VKMA_NOEXCEPT
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
  static_assert( sizeof( AllocatorCreateInfo ) == sizeof( VmaAllocatorCreateInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<AllocatorCreateInfo>::value, "struct wrapper is not a standard layout!" );

  struct Budget
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR Budget(VkDeviceSize blockBytes_ = {}, VkDeviceSize allocationBytes_ = {}, VkDeviceSize usage_ = {}, VkDeviceSize budget_ = {}) VKMA_NOEXCEPT
    : blockBytes( blockBytes_ ), allocationBytes( allocationBytes_ ), usage( usage_ ), budget( budget_ )
    {}

    VKMA_CONSTEXPR Budget( Budget const & rhs ) VKMA_NOEXCEPT = default;

    Budget( VmaBudget const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    Budget & operator=( VmaBudget const & rhs ) VKMA_NOEXCEPT
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


    operator VmaBudget const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VmaBudget*>( this );
    }

    operator VmaBudget &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VmaBudget*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( Budget const& ) const = default;
#else
    bool operator==( Budget const& rhs ) const VKMA_NOEXCEPT
    {
      return ( memcmp( &blockBytes, &rhs.blockBytes, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &allocationBytes, &rhs.allocationBytes, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &usage, &rhs.usage, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &budget, &rhs.budget, sizeof( VkDeviceSize ) ) == 0 );
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
  static_assert( sizeof( Budget ) == sizeof( VmaBudget ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<Budget>::value, "struct wrapper is not a standard layout!" );

  struct DefragmentationInfo
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR DefragmentationInfo(VkDeviceSize maxBytesToMove_ = {}, uint32_t maxAllocationsToMove_ = {}) VKMA_NOEXCEPT
    : maxBytesToMove( maxBytesToMove_ ), maxAllocationsToMove( maxAllocationsToMove_ )
    {}

    VKMA_CONSTEXPR DefragmentationInfo( DefragmentationInfo const & rhs ) VKMA_NOEXCEPT = default;

    DefragmentationInfo( VmaDefragmentationInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    DefragmentationInfo & operator=( VmaDefragmentationInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = *reinterpret_cast<VKMA_NAMESPACE::DefragmentationInfo const *>( &rhs );
      return *this;
    }

    DefragmentationInfo & operator=( DefragmentationInfo const & rhs ) VKMA_NOEXCEPT
    {
      memcpy( static_cast<void *>( this ), &rhs, sizeof( DefragmentationInfo ) );
      return *this;
    }

    DefragmentationInfo & setMaxBytesToMove( VkDeviceSize maxBytesToMove_ ) VKMA_NOEXCEPT
    {
      maxBytesToMove = maxBytesToMove_;
      return *this;
    }

    DefragmentationInfo & setMaxAllocationsToMove( uint32_t maxAllocationsToMove_ ) VKMA_NOEXCEPT
    {
      maxAllocationsToMove = maxAllocationsToMove_;
      return *this;
    }


    operator VmaDefragmentationInfo const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VmaDefragmentationInfo*>( this );
    }

    operator VmaDefragmentationInfo &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VmaDefragmentationInfo*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( DefragmentationInfo const& ) const = default;
#else
    bool operator==( DefragmentationInfo const& rhs ) const VKMA_NOEXCEPT
    {
      return ( memcmp( &maxBytesToMove, &rhs.maxBytesToMove, sizeof( VkDeviceSize ) ) == 0 )
          && ( maxAllocationsToMove == rhs.maxAllocationsToMove );
    }

    bool operator!=( DefragmentationInfo const& rhs ) const VKMA_NOEXCEPT
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
    using CType = VmaAllocation;

    static VKMA_CONST_OR_CONSTEXPR VKMA_NAMESPACE::ObjectType objectType = VKMA_NAMESPACE::ObjectType::eVmaAllocation;
    static VKMA_CONST_OR_CONSTEXPR VKMA_NAMESPACE::DebugReportObjectTypeEXT debugReportObjectType = VKMA_NAMESPACE::DebugReportObjectTypeEXT::eUnknown;

  public:
    VKMA_CONSTEXPR Allocation() VKMA_NOEXCEPT
      : m_allocation(VMA_NULL_HANDLE)
    {}

    VKMA_CONSTEXPR Allocation( std::nullptr_t ) VKMA_NOEXCEPT
      : m_allocation(VMA_NULL_HANDLE)
    {}

    VKMA_TYPESAFE_EXPLICIT Allocation( VmaAllocation allocation ) VKMA_NOEXCEPT
      : m_allocation( allocation )
    {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    Allocation & operator=(VmaAllocation allocation) VKMA_NOEXCEPT
    {
      m_allocation = allocation;
      return *this;
    }
#endif

    Allocation & operator=( std::nullptr_t ) VKMA_NOEXCEPT
    {
      m_allocation = VMA_NULL_HANDLE;
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

    VKMA_TYPESAFE_EXPLICIT operator VmaAllocation() const VKMA_NOEXCEPT
    {
      return m_allocation;
    }

    explicit operator bool() const VKMA_NOEXCEPT
    {
      return m_allocation != VMA_NULL_HANDLE;
    }

    bool operator!() const VKMA_NOEXCEPT
    {
      return m_allocation == VMA_NULL_HANDLE;
    }

  private:
    VmaAllocation m_allocation;
  };
  static_assert( sizeof( VKMA_NAMESPACE::Allocation ) == sizeof( VmaAllocation ), "handle and wrapper have different size!" );

  template <>
  struct VKMA_DEPRECATED("vma::cpp_type is deprecated. Use vma::CppType instead.") cpp_type<ObjectType::eVmaAllocation>
  {
    using type = VKMA_NAMESPACE::Allocation;
  };

  template <>
  struct CppType<VKMA_NAMESPACE::ObjectType, VKMA_NAMESPACE::ObjectType::eVmaAllocation>
  {
    using Type = VKMA_NAMESPACE::Allocation;
  };



  template <>
  struct isVulkanHandleType<VKMA_NAMESPACE::Allocation>
  {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

  struct DefragmentationInfo2
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR DefragmentationInfo2(DefragmentationFlags flags_ = {}, uint32_t allocationCount_ = {}, Allocation* pAllocations_ = {}, VkBool32* pAllocationsChanged_ = {}, uint32_t poolCount_ = {}, Pool* pPools_ = {}, VkDeviceSize maxCpuBytesToMove_ = {}, uint32_t maxCpuAllocationsToMove_ = {}, VkDeviceSize maxGpuBytesToMove_ = {}, uint32_t maxGpuAllocationsToMove_ = {}, VkCommandBuffer commandBuffer_ = {}) VKMA_NOEXCEPT
    : flags( flags_ ), allocationCount( allocationCount_ ), pAllocations( pAllocations_ ), pAllocationsChanged( pAllocationsChanged_ ), poolCount( poolCount_ ), pPools( pPools_ ), maxCpuBytesToMove( maxCpuBytesToMove_ ), maxCpuAllocationsToMove( maxCpuAllocationsToMove_ ), maxGpuBytesToMove( maxGpuBytesToMove_ ), maxGpuAllocationsToMove( maxGpuAllocationsToMove_ ), commandBuffer( commandBuffer_ )
    {}

    VKMA_CONSTEXPR DefragmentationInfo2( DefragmentationInfo2 const & rhs ) VKMA_NOEXCEPT = default;

    DefragmentationInfo2( VmaDefragmentationInfo2 const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    DefragmentationInfo2 & operator=( VmaDefragmentationInfo2 const & rhs ) VKMA_NOEXCEPT
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

    DefragmentationInfo2 & setPAllocations( Allocation* pAllocations_ ) VKMA_NOEXCEPT
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

    DefragmentationInfo2 & setPPools( Pool* pPools_ ) VKMA_NOEXCEPT
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


    operator VmaDefragmentationInfo2 const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VmaDefragmentationInfo2*>( this );
    }

    operator VmaDefragmentationInfo2 &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VmaDefragmentationInfo2*>( this );
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
          && ( memcmp( &maxCpuBytesToMove, &rhs.maxCpuBytesToMove, sizeof( VkDeviceSize ) ) == 0 )
          && ( maxCpuAllocationsToMove == rhs.maxCpuAllocationsToMove )
          && ( memcmp( &maxGpuBytesToMove, &rhs.maxGpuBytesToMove, sizeof( VkDeviceSize ) ) == 0 )
          && ( maxGpuAllocationsToMove == rhs.maxGpuAllocationsToMove )
          && ( memcmp( &commandBuffer, &rhs.commandBuffer, sizeof( VkCommandBuffer ) ) == 0 );
    }

    bool operator!=( DefragmentationInfo2 const& rhs ) const VKMA_NOEXCEPT
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


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR DefragmentationStats(VkDeviceSize bytesMoved_ = {}, VkDeviceSize bytesFreed_ = {}, uint32_t allocationsMoved_ = {}, uint32_t deviceMemoryBlocksFreed_ = {}) VKMA_NOEXCEPT
    : bytesMoved( bytesMoved_ ), bytesFreed( bytesFreed_ ), allocationsMoved( allocationsMoved_ ), deviceMemoryBlocksFreed( deviceMemoryBlocksFreed_ )
    {}

    VKMA_CONSTEXPR DefragmentationStats( DefragmentationStats const & rhs ) VKMA_NOEXCEPT = default;

    DefragmentationStats( VmaDefragmentationStats const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    DefragmentationStats & operator=( VmaDefragmentationStats const & rhs ) VKMA_NOEXCEPT
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


    operator VmaDefragmentationStats const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VmaDefragmentationStats*>( this );
    }

    operator VmaDefragmentationStats &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VmaDefragmentationStats*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( DefragmentationStats const& ) const = default;
#else
    bool operator==( DefragmentationStats const& rhs ) const VKMA_NOEXCEPT
    {
      return ( memcmp( &bytesMoved, &rhs.bytesMoved, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &bytesFreed, &rhs.bytesFreed, sizeof( VkDeviceSize ) ) == 0 )
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
  static_assert( sizeof( DefragmentationStats ) == sizeof( VmaDefragmentationStats ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<DefragmentationStats>::value, "struct wrapper is not a standard layout!" );

  struct PoolCreateInfo
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR PoolCreateInfo(uint32_t memoryTypeIndex_ = {}, PoolCreateFlags flags_ = {}, VkDeviceSize blockSize_ = {}, size_t minBlockCount_ = {}, size_t maxBlockCount_ = {}, uint32_t frameInUseCount_ = {}) VKMA_NOEXCEPT
    : memoryTypeIndex( memoryTypeIndex_ ), flags( flags_ ), blockSize( blockSize_ ), minBlockCount( minBlockCount_ ), maxBlockCount( maxBlockCount_ ), frameInUseCount( frameInUseCount_ )
    {}

    VKMA_CONSTEXPR PoolCreateInfo( PoolCreateInfo const & rhs ) VKMA_NOEXCEPT = default;

    PoolCreateInfo( VmaPoolCreateInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    PoolCreateInfo & operator=( VmaPoolCreateInfo const & rhs ) VKMA_NOEXCEPT
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


    operator VmaPoolCreateInfo const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VmaPoolCreateInfo*>( this );
    }

    operator VmaPoolCreateInfo &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VmaPoolCreateInfo*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( PoolCreateInfo const& ) const = default;
#else
    bool operator==( PoolCreateInfo const& rhs ) const VKMA_NOEXCEPT
    {
      return ( memoryTypeIndex == rhs.memoryTypeIndex )
          && ( flags == rhs.flags )
          && ( memcmp( &blockSize, &rhs.blockSize, sizeof( VkDeviceSize ) ) == 0 )
          && ( minBlockCount == rhs.minBlockCount )
          && ( maxBlockCount == rhs.maxBlockCount )
          && ( frameInUseCount == rhs.frameInUseCount );
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

  };
  static_assert( sizeof( PoolCreateInfo ) == sizeof( VmaPoolCreateInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<PoolCreateInfo>::value, "struct wrapper is not a standard layout!" );

  struct PoolStats
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR PoolStats(VkDeviceSize size_ = {}, VkDeviceSize unusedSize_ = {}, size_t allocationCount_ = {}, size_t unusedRangeCount_ = {}, VkDeviceSize unusedRangeSizeMax_ = {}, size_t blockCount_ = {}) VKMA_NOEXCEPT
    : size( size_ ), unusedSize( unusedSize_ ), allocationCount( allocationCount_ ), unusedRangeCount( unusedRangeCount_ ), unusedRangeSizeMax( unusedRangeSizeMax_ ), blockCount( blockCount_ )
    {}

    VKMA_CONSTEXPR PoolStats( PoolStats const & rhs ) VKMA_NOEXCEPT = default;

    PoolStats( VmaPoolStats const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    PoolStats & operator=( VmaPoolStats const & rhs ) VKMA_NOEXCEPT
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


    operator VmaPoolStats const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VmaPoolStats*>( this );
    }

    operator VmaPoolStats &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VmaPoolStats*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( PoolStats const& ) const = default;
#else
    bool operator==( PoolStats const& rhs ) const VKMA_NOEXCEPT
    {
      return ( memcmp( &size, &rhs.size, sizeof( VkDeviceSize ) ) == 0 )
          && ( memcmp( &unusedSize, &rhs.unusedSize, sizeof( VkDeviceSize ) ) == 0 )
          && ( allocationCount == rhs.allocationCount )
          && ( unusedRangeCount == rhs.unusedRangeCount )
          && ( memcmp( &unusedRangeSizeMax, &rhs.unusedRangeSizeMax, sizeof( VkDeviceSize ) ) == 0 )
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
  static_assert( sizeof( PoolStats ) == sizeof( VmaPoolStats ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<PoolStats>::value, "struct wrapper is not a standard layout!" );

  struct StatInfo
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR StatInfo(uint32_t blockCount_ = {}, uint32_t allocationCount_ = {}, uint32_t unusedRangeCount_ = {}, VkDeviceSize usedBytes_ = {}, VkDeviceSize unusedBytes_ = {}, VkDeviceSize allocationSizeMin_ = {}, VkDeviceSize allocationSizeAvg_ = {}, VkDeviceSize allocationSizeMax_ = {}, VkDeviceSize unusedRangeSizeMin_ = {}, VkDeviceSize unusedRangeSizeAvg_ = {}, VkDeviceSize unusedRangeSizeMax_ = {}) VKMA_NOEXCEPT
    : blockCount( blockCount_ ), allocationCount( allocationCount_ ), unusedRangeCount( unusedRangeCount_ ), usedBytes( usedBytes_ ), unusedBytes( unusedBytes_ ), allocationSizeMin( allocationSizeMin_ ), allocationSizeAvg( allocationSizeAvg_ ), allocationSizeMax( allocationSizeMax_ ), unusedRangeSizeMin( unusedRangeSizeMin_ ), unusedRangeSizeAvg( unusedRangeSizeAvg_ ), unusedRangeSizeMax( unusedRangeSizeMax_ )
    {}

    VKMA_CONSTEXPR StatInfo( StatInfo const & rhs ) VKMA_NOEXCEPT = default;

    StatInfo( VmaStatInfo const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    StatInfo & operator=( VmaStatInfo const & rhs ) VKMA_NOEXCEPT
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


    operator VmaStatInfo const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VmaStatInfo*>( this );
    }

    operator VmaStatInfo &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VmaStatInfo*>( this );
    }


#if defined(VKMA_HAS_SPACESHIP_OPERATOR)
    auto operator<=>( StatInfo const& ) const = default;
#else
    bool operator==( StatInfo const& rhs ) const VKMA_NOEXCEPT
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
  static_assert( sizeof( StatInfo ) == sizeof( VmaStatInfo ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<StatInfo>::value, "struct wrapper is not a standard layout!" );

  struct Stats
  {


#if !defined( VKMA_NO_STRUCT_CONSTRUCTORS )
    VKMA_CONSTEXPR Stats(StatInfo memoryType_ = {}, StatInfo memoryHeap_ = {}, StatInfo total_ = {}) VKMA_NOEXCEPT
    : memoryType( memoryType_ ), memoryHeap( memoryHeap_ ), total( total_ )
    {}

    VKMA_CONSTEXPR Stats( Stats const & rhs ) VKMA_NOEXCEPT = default;

    Stats( VmaStats const & rhs ) VKMA_NOEXCEPT
    {
      *this = rhs;
    }
#endif // !defined( VKMA_NO_STRUCT_CONSTRUCTORS )

    Stats & operator=( VmaStats const & rhs ) VKMA_NOEXCEPT
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


    operator VmaStats const&() const VKMA_NOEXCEPT
    {
      return *reinterpret_cast<const VmaStats*>( this );
    }

    operator VmaStats &() VKMA_NOEXCEPT
    {
      return *reinterpret_cast<VmaStats*>( this );
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
  static_assert( sizeof( Stats ) == sizeof( VmaStats ), "struct and wrapper have different size!" );
  static_assert( std::is_standard_layout<Stats>::value, "struct wrapper is not a standard layout!" );

  class DefragmentationContext
  {
  public:
    using CType = VmaDefragmentationContext;

    static VKMA_CONST_OR_CONSTEXPR VKMA_NAMESPACE::ObjectType objectType = VKMA_NAMESPACE::ObjectType::eVmaDefragmentationContext;
    static VKMA_CONST_OR_CONSTEXPR VKMA_NAMESPACE::DebugReportObjectTypeEXT debugReportObjectType = VKMA_NAMESPACE::DebugReportObjectTypeEXT::eUnknown;

  public:
    VKMA_CONSTEXPR DefragmentationContext() VKMA_NOEXCEPT
      : m_defragmentationContext(VMA_NULL_HANDLE)
    {}

    VKMA_CONSTEXPR DefragmentationContext( std::nullptr_t ) VKMA_NOEXCEPT
      : m_defragmentationContext(VMA_NULL_HANDLE)
    {}

    VKMA_TYPESAFE_EXPLICIT DefragmentationContext( VmaDefragmentationContext defragmentationContext ) VKMA_NOEXCEPT
      : m_defragmentationContext( defragmentationContext )
    {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    DefragmentationContext & operator=(VmaDefragmentationContext defragmentationContext) VKMA_NOEXCEPT
    {
      m_defragmentationContext = defragmentationContext;
      return *this;
    }
#endif

    DefragmentationContext & operator=( std::nullptr_t ) VKMA_NOEXCEPT
    {
      m_defragmentationContext = VMA_NULL_HANDLE;
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

    VKMA_TYPESAFE_EXPLICIT operator VmaDefragmentationContext() const VKMA_NOEXCEPT
    {
      return m_defragmentationContext;
    }

    explicit operator bool() const VKMA_NOEXCEPT
    {
      return m_defragmentationContext != VMA_NULL_HANDLE;
    }

    bool operator!() const VKMA_NOEXCEPT
    {
      return m_defragmentationContext == VMA_NULL_HANDLE;
    }

  private:
    VmaDefragmentationContext m_defragmentationContext;
  };
  static_assert( sizeof( VKMA_NAMESPACE::DefragmentationContext ) == sizeof( VmaDefragmentationContext ), "handle and wrapper have different size!" );

  template <>
  struct VKMA_DEPRECATED("vma::cpp_type is deprecated. Use vma::CppType instead.") cpp_type<ObjectType::eVmaDefragmentationContext>
  {
    using type = VKMA_NAMESPACE::DefragmentationContext;
  };

  template <>
  struct CppType<VKMA_NAMESPACE::ObjectType, VKMA_NAMESPACE::ObjectType::eVmaDefragmentationContext>
  {
    using Type = VKMA_NAMESPACE::DefragmentationContext;
  };



  template <>
  struct isVulkanHandleType<VKMA_NAMESPACE::DefragmentationContext>
  {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };

  class Allocator
  {
  public:
    using CType = VmaAllocator;

    static VKMA_CONST_OR_CONSTEXPR VKMA_NAMESPACE::ObjectType objectType = VKMA_NAMESPACE::ObjectType::eVmaAllocator;
    static VKMA_CONST_OR_CONSTEXPR VKMA_NAMESPACE::DebugReportObjectTypeEXT debugReportObjectType = VKMA_NAMESPACE::DebugReportObjectTypeEXT::eUnknown;

  public:
    VKMA_CONSTEXPR Allocator() VKMA_NOEXCEPT
      : m_allocator(VMA_NULL_HANDLE)
    {}

    VKMA_CONSTEXPR Allocator( std::nullptr_t ) VKMA_NOEXCEPT
      : m_allocator(VMA_NULL_HANDLE)
    {}

    VKMA_TYPESAFE_EXPLICIT Allocator( VmaAllocator allocator ) VKMA_NOEXCEPT
      : m_allocator( allocator )
    {}

#if defined(VKMA_TYPESAFE_CONVERSION)
    Allocator & operator=(VmaAllocator allocator) VKMA_NOEXCEPT
    {
      m_allocator = allocator;
      return *this;
    }
#endif

    Allocator & operator=( std::nullptr_t ) VKMA_NOEXCEPT
    {
      m_allocator = VMA_NULL_HANDLE;
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






#ifdef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkResult bindBufferMemory( Allocation allocation, VkBuffer buffer, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#else
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type bindBufferMemory( Allocation allocation, VkBuffer buffer, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkResult bindBufferMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer, const void* pNext, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#else
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type bindBufferMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer, const void* pNext, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkResult bindImageMemory( Allocation allocation, VkImage image, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#else
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type bindImageMemory( Allocation allocation, VkImage image, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkResult bindImageMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkImage image, const void* pNext, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#else
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type bindImageMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkImage image, const void* pNext, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void buildStatsString( char** ppStatsString, VkBool32 detailedMap, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD char buildStatsString( VkBool32 detailedMap, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void calculateStats( Stats* pStats, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VKMA_NAMESPACE::Stats calculateStats( Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


#ifdef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkResult checkCorruption( uint32_t memoryTypeBits, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#else
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type checkCorruption( uint32_t memoryTypeBits, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkResult checkPoolCorruption( Pool pool, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#else
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type checkPoolCorruption( Pool pool, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/






    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkResult createPool( const PoolCreateInfo* pCreateInfo, Pool* pPool, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Pool>::type createPool( const PoolCreateInfo & createInfo, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#  ifndef VKMA_NO_SMART_HANDLE
  template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Pool, Dispatch>>::type createPoolUnique( const PoolCreateInfo & createInfo, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/




#ifdef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkResult defragmentationEnd( DefragmentationContext context, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#else
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type defragmentationEnd( DefragmentationContext context, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void destroy( Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void destroyBuffer( VkBuffer buffer, Allocation allocation, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void destroyImage( VkImage image, Allocation allocation, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void destroyPool( Pool pool, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkResult findMemoryTypeIndex( uint32_t memoryTypeBits, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<uint32_t>::type findMemoryTypeIndex( uint32_t memoryTypeBits, const AllocationCreateInfo & allocationCreateInfo, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkResult findMemoryTypeIndexForBufferInfo( const VkBufferCreateInfo* pBufferCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<uint32_t>::type findMemoryTypeIndexForBufferInfo( const VkBufferCreateInfo & bufferCreateInfo, const AllocationCreateInfo & allocationCreateInfo, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkResult findMemoryTypeIndexForImageInfo( const VkImageCreateInfo* pImageCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<uint32_t>::type findMemoryTypeIndexForImageInfo( const VkImageCreateInfo & imageCreateInfo, const AllocationCreateInfo & allocationCreateInfo, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void flushAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void freeMemory( Allocation allocation, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;



    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void freeStatsString( char* pStatsString, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD char freeStatsString( Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void getAllocationInfo( Allocation allocation, AllocationInfo* pAllocationInfo, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VKMA_NAMESPACE::AllocationInfo getAllocationInfo( Allocation allocation, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void getBudget( Budget* pBudget, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VKMA_NAMESPACE::Budget getBudget( Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void getMemoryProperties( const VkPhysicalDeviceMemoryProperties** ppPhysicalDeviceMemoryProperties, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void getMemoryProperties( const VkPhysicalDeviceMemoryProperties & pPhysicalDeviceMemoryProperties, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void getMemoryTypeProperties( uint32_t memoryTypeIndex, VkMemoryPropertyFlags* pFlags, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkMemoryPropertyFlags getMemoryTypeProperties( uint32_t memoryTypeIndex, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void getPhysicalDeviceProperties( const VkPhysicalDeviceProperties** ppPhysicalDeviceProperties, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void getPhysicalDeviceProperties( const VkPhysicalDeviceProperties & pPhysicalDeviceProperties, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void getPoolName( Pool pool, const char** ppName, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void getPoolName( Pool pool, const char & pName, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void getPoolStats( Pool pool, PoolStats* pPoolStats, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VKMA_NAMESPACE::PoolStats getPoolStats( Pool pool, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void invalidateAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void makePoolAllocationsLost( Pool pool, size_t* pLostAllocationCount, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD size_t makePoolAllocationsLost( Pool pool, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkResult mapMemory( Allocation allocation, void** ppData, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void*>::type mapMemory( Allocation allocation, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


#ifdef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkResult resizeAllocation( Allocation allocation, VkDeviceSize newSize, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#else
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<void>::type resizeAllocation( Allocation allocation, VkDeviceSize newSize, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void setAllocationUserData( Allocation allocation, void* pUserData, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD void setAllocationUserData( Allocation allocation, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void setCurrentFrameIndex( uint32_t frameIndex, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void setPoolName( Pool pool, const char* pName, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void setPoolName( Pool pool, const char & name, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VkBool32 touchAllocation( Allocation allocation, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    void unmapMemory( Allocation allocation, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) const VKMA_NOEXCEPT;

    VKMA_TYPESAFE_EXPLICIT operator VmaAllocator() const VKMA_NOEXCEPT
    {
      return m_allocator;
    }

    explicit operator bool() const VKMA_NOEXCEPT
    {
      return m_allocator != VMA_NULL_HANDLE;
    }

    bool operator!() const VKMA_NOEXCEPT
    {
      return m_allocator == VMA_NULL_HANDLE;
    }

  private:
    VmaAllocator m_allocator;
  };
  static_assert( sizeof( VKMA_NAMESPACE::Allocator ) == sizeof( VmaAllocator ), "handle and wrapper have different size!" );

  template <>
  struct VKMA_DEPRECATED("vma::cpp_type is deprecated. Use vma::CppType instead.") cpp_type<ObjectType::eVmaAllocator>
  {
    using type = VKMA_NAMESPACE::Allocator;
  };

  template <>
  struct CppType<VKMA_NAMESPACE::ObjectType, VKMA_NAMESPACE::ObjectType::eVmaAllocator>
  {
    using Type = VKMA_NAMESPACE::Allocator;
  };



  template <>
  struct isVulkanHandleType<VKMA_NAMESPACE::Allocator>
  {
    static VKMA_CONST_OR_CONSTEXPR bool value = true;
  };


    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD VkResult createAllocator( const AllocatorCreateInfo* pCreateInfo, Allocator* pAllocator, Dispatch const & d  VKMA_DEFAULT_DISPATCHER_ASSIGNMENT ) VKMA_NOEXCEPT;
#ifndef VKMA_DISABLE_ENHANCED_MODE
    template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
    VKMA_NODISCARD_WHEN_NO_EXCEPTIONS typename ResultValueType<Allocator>::type createAllocator( const AllocatorCreateInfo & createInfo, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT );
#  ifndef VKMA_NO_SMART_HANDLE
  template <typename Dispatch = VKMA_DEFAULT_DISPATCHER_TYPE>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Allocator, Dispatch>>::type createAllocatorUnique( const AllocatorCreateInfo & createInfo, Dispatch const & d VKMA_DEFAULT_DISPATCHER_ASSIGNMENT );
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkResult createAllocator( const AllocatorCreateInfo* pCreateInfo, Allocator* pAllocator, Dispatch const & d  ) VKMA_NOEXCEPT
  {
    return d.vmaCreateAllocator( reinterpret_cast<const VmaAllocatorCreateInfo *>( pCreateInfo ), reinterpret_cast< VmaAllocator *>( pAllocator ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Allocator>::type createAllocator( const AllocatorCreateInfo & createInfo, Dispatch const & d )
  {
    Allocator allocator;
    Result result = static_cast<Result>( d.vmaCreateAllocator( reinterpret_cast<const VmaAllocatorCreateInfo *>( &createInfo ), reinterpret_cast<VmaAllocator *>( &allocator ) ) );
    return createResultValue( result, allocator, VKMA_NAMESPACE_STRING "::createAllocator" );
  }

#  ifndef VKMA_NO_SMART_HANDLE
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Allocator, Dispatch>>::type createAllocatorUnique( const AllocatorCreateInfo & createInfo, Dispatch const & d )
  {
    Allocator allocator;
    Result result = static_cast<Result>( d.vmaCreateAllocator( reinterpret_cast<const VmaAllocatorCreateInfo *>( &createInfo ), reinterpret_cast<VmaAllocator *>( &allocator ) ) );
    ObjectDestroy<NoParent, Dispatch> deleter( allocator, d );
    return createResultValue<Allocator, Dispatch>( result, allocator, VKMA_NAMESPACE_STRING "::createAllocatorUnique", deleter );
  }
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/






#ifdef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkResult Allocator::bindBufferMemory( Allocation allocation, VkBuffer buffer, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    return d.vmaBindBufferMemory( m_allocator, static_cast<VmaAllocation>( allocation ), buffer );
  }
#else
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::bindBufferMemory( Allocation allocation, VkBuffer buffer, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaBindBufferMemory( m_allocator, static_cast<VmaAllocation>( allocation ), buffer ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::bindBufferMemory" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkResult Allocator::bindBufferMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer, const void* pNext, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    return d.vmaBindBufferMemory2( m_allocator, static_cast<VmaAllocation>( allocation ), allocationLocalOffset, buffer, pNext );
  }
#else
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::bindBufferMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkBuffer buffer, const void* pNext, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaBindBufferMemory2( m_allocator, static_cast<VmaAllocation>( allocation ), allocationLocalOffset, buffer, pNext ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::bindBufferMemory2" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkResult Allocator::bindImageMemory( Allocation allocation, VkImage image, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    return d.vmaBindImageMemory( m_allocator, static_cast<VmaAllocation>( allocation ), image );
  }
#else
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::bindImageMemory( Allocation allocation, VkImage image, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaBindImageMemory( m_allocator, static_cast<VmaAllocation>( allocation ), image ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::bindImageMemory" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkResult Allocator::bindImageMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkImage image, const void* pNext, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    return d.vmaBindImageMemory2( m_allocator, static_cast<VmaAllocation>( allocation ), allocationLocalOffset, image, pNext );
  }
#else
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::bindImageMemory2( Allocation allocation, VkDeviceSize allocationLocalOffset, VkImage image, const void* pNext, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaBindImageMemory2( m_allocator, static_cast<VmaAllocation>( allocation ), allocationLocalOffset, image, pNext ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::bindImageMemory2" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  template <typename Dispatch>
  VKMA_INLINE void Allocator::buildStatsString( char** ppStatsString, VkBool32 detailedMap, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaBuildStatsString( m_allocator, ppStatsString, detailedMap );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE char Allocator::buildStatsString( VkBool32 detailedMap, Dispatch const & d ) const VKMA_NOEXCEPT
  {
    char pStatsString;
    d.vmaBuildStatsString( m_allocator, &pStatsString, detailedMap );
    return pStatsString;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_INLINE void Allocator::calculateStats( Stats* pStats, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaCalculateStats( m_allocator, reinterpret_cast< VmaStats *>( pStats ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::Stats Allocator::calculateStats( Dispatch const & d ) const VKMA_NOEXCEPT
  {
    VKMA_NAMESPACE::Stats stats;
    d.vmaCalculateStats( m_allocator, reinterpret_cast<VmaStats *>( &stats ) );
    return stats;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


#ifdef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkResult Allocator::checkCorruption( uint32_t memoryTypeBits, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    return d.vmaCheckCorruption( m_allocator, memoryTypeBits );
  }
#else
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::checkCorruption( uint32_t memoryTypeBits, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaCheckCorruption( m_allocator, memoryTypeBits ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::checkCorruption" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



#ifdef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkResult Allocator::checkPoolCorruption( Pool pool, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    return d.vmaCheckPoolCorruption( m_allocator, static_cast<VmaPool>( pool ) );
  }
#else
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::checkPoolCorruption( Pool pool, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaCheckPoolCorruption( m_allocator, static_cast<VmaPool>( pool ) ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::checkPoolCorruption" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/






  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkResult Allocator::createPool( const PoolCreateInfo* pCreateInfo, Pool* pPool, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    return d.vmaCreatePool( m_allocator, reinterpret_cast<const VmaPoolCreateInfo *>( pCreateInfo ), reinterpret_cast< VmaPool *>( pPool ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<Pool>::type Allocator::createPool( const PoolCreateInfo & createInfo, Dispatch const & d ) const
  {
    Pool pool;
    Result result = static_cast<Result>( d.vmaCreatePool( m_allocator, reinterpret_cast<const VmaPoolCreateInfo *>( &createInfo ), reinterpret_cast<VmaPool *>( &pool ) ) );
    return createResultValue( result, pool, VKMA_NAMESPACE_STRING "::Allocator::createPool" );
  }

#  ifndef VKMA_NO_SMART_HANDLE
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<UniqueHandle<Pool, Dispatch>>::type Allocator::createPoolUnique( const PoolCreateInfo & createInfo, Dispatch const & d ) const
  {
    Pool pool;
    Result result = static_cast<Result>( d.vmaCreatePool( m_allocator, reinterpret_cast<const VmaPoolCreateInfo *>( &createInfo ), reinterpret_cast<VmaPool *>( &pool ) ) );
    ObjectDestroy<Allocator, Dispatch> deleter( *this, allocator, d );
    return createResultValue<Pool, Dispatch>( result, pool, VKMA_NAMESPACE_STRING "::Allocator::createPoolUnique", deleter );
  }
#  endif /*VKMA_NO_SMART_HANDLE*/
#endif /*VKMA_DISABLE_ENHANCED_MODE*/




#ifdef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkResult Allocator::defragmentationEnd( DefragmentationContext context, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    return d.vmaDefragmentationEnd( m_allocator, static_cast<VmaDefragmentationContext>( context ) );
  }
#else
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::defragmentationEnd( DefragmentationContext context, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaDefragmentationEnd( m_allocator, static_cast<VmaDefragmentationContext>( context ) ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::defragmentationEnd" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  template <typename Dispatch>
  VKMA_INLINE void Allocator::destroy( Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaDestroyAllocator( m_allocator );
  }


  template <typename Dispatch>
  VKMA_INLINE void Allocator::destroyBuffer( VkBuffer buffer, Allocation allocation, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaDestroyBuffer( m_allocator, buffer, static_cast<VmaAllocation>( allocation ) );
  }


  template <typename Dispatch>
  VKMA_INLINE void Allocator::destroyImage( VkImage image, Allocation allocation, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaDestroyImage( m_allocator, image, static_cast<VmaAllocation>( allocation ) );
  }


  template <typename Dispatch>
  VKMA_INLINE void Allocator::destroyPool( Pool pool, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaDestroyPool( m_allocator, static_cast<VmaPool>( pool ) );
  }


  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkResult Allocator::findMemoryTypeIndex( uint32_t memoryTypeBits, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    return d.vmaFindMemoryTypeIndex( m_allocator, memoryTypeBits, reinterpret_cast<const VmaAllocationCreateInfo *>( pAllocationCreateInfo ), pMemoryTypeIndex );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<uint32_t>::type Allocator::findMemoryTypeIndex( uint32_t memoryTypeBits, const AllocationCreateInfo & allocationCreateInfo, Dispatch const & d ) const
  {
    uint32_t memoryTypeIndex;
    Result result = static_cast<Result>( d.vmaFindMemoryTypeIndex( m_allocator, memoryTypeBits, reinterpret_cast<const VmaAllocationCreateInfo *>( &allocationCreateInfo ), &memoryTypeIndex ) );
    return createResultValue( result, memoryTypeIndex, VKMA_NAMESPACE_STRING "::Allocator::findMemoryTypeIndex" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkResult Allocator::findMemoryTypeIndexForBufferInfo( const VkBufferCreateInfo* pBufferCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    return d.vmaFindMemoryTypeIndexForBufferInfo( m_allocator, pBufferCreateInfo, reinterpret_cast<const VmaAllocationCreateInfo *>( pAllocationCreateInfo ), pMemoryTypeIndex );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<uint32_t>::type Allocator::findMemoryTypeIndexForBufferInfo( const VkBufferCreateInfo & bufferCreateInfo, const AllocationCreateInfo & allocationCreateInfo, Dispatch const & d ) const
  {
    uint32_t memoryTypeIndex;
    Result result = static_cast<Result>( d.vmaFindMemoryTypeIndexForBufferInfo( m_allocator, &bufferCreateInfo, reinterpret_cast<const VmaAllocationCreateInfo *>( &allocationCreateInfo ), &memoryTypeIndex ) );
    return createResultValue( result, memoryTypeIndex, VKMA_NAMESPACE_STRING "::Allocator::findMemoryTypeIndexForBufferInfo" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkResult Allocator::findMemoryTypeIndexForImageInfo( const VkImageCreateInfo* pImageCreateInfo, const AllocationCreateInfo* pAllocationCreateInfo, uint32_t* pMemoryTypeIndex, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    return d.vmaFindMemoryTypeIndexForImageInfo( m_allocator, pImageCreateInfo, reinterpret_cast<const VmaAllocationCreateInfo *>( pAllocationCreateInfo ), pMemoryTypeIndex );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<uint32_t>::type Allocator::findMemoryTypeIndexForImageInfo( const VkImageCreateInfo & imageCreateInfo, const AllocationCreateInfo & allocationCreateInfo, Dispatch const & d ) const
  {
    uint32_t memoryTypeIndex;
    Result result = static_cast<Result>( d.vmaFindMemoryTypeIndexForImageInfo( m_allocator, &imageCreateInfo, reinterpret_cast<const VmaAllocationCreateInfo *>( &allocationCreateInfo ), &memoryTypeIndex ) );
    return createResultValue( result, memoryTypeIndex, VKMA_NAMESPACE_STRING "::Allocator::findMemoryTypeIndexForImageInfo" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_INLINE void Allocator::flushAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaFlushAllocation( m_allocator, static_cast<VmaAllocation>( allocation ), offset, size );
  }


  template <typename Dispatch>
  VKMA_INLINE void Allocator::freeMemory( Allocation allocation, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaFreeMemory( m_allocator, static_cast<VmaAllocation>( allocation ) );
  }



  template <typename Dispatch>
  VKMA_INLINE void Allocator::freeStatsString( char* pStatsString, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaFreeStatsString( m_allocator, pStatsString );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE char Allocator::freeStatsString( Dispatch const & d ) const VKMA_NOEXCEPT
  {
    char statsString;
    d.vmaFreeStatsString( m_allocator, &statsString );
    return statsString;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_INLINE void Allocator::getAllocationInfo( Allocation allocation, AllocationInfo* pAllocationInfo, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaGetAllocationInfo( m_allocator, static_cast<VmaAllocation>( allocation ), reinterpret_cast< VmaAllocationInfo *>( pAllocationInfo ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::AllocationInfo Allocator::getAllocationInfo( Allocation allocation, Dispatch const & d ) const VKMA_NOEXCEPT
  {
    VKMA_NAMESPACE::AllocationInfo allocationInfo;
    d.vmaGetAllocationInfo( m_allocator, static_cast<VmaAllocation>( allocation ), reinterpret_cast<VmaAllocationInfo *>( &allocationInfo ) );
    return allocationInfo;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_INLINE void Allocator::getBudget( Budget* pBudget, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaGetBudget( m_allocator, reinterpret_cast< VmaBudget *>( pBudget ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::Budget Allocator::getBudget( Dispatch const & d ) const VKMA_NOEXCEPT
  {
    VKMA_NAMESPACE::Budget budget;
    d.vmaGetBudget( m_allocator, reinterpret_cast<VmaBudget *>( &budget ) );
    return budget;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_INLINE void Allocator::getMemoryProperties( const VkPhysicalDeviceMemoryProperties** ppPhysicalDeviceMemoryProperties, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaGetMemoryProperties( m_allocator, ppPhysicalDeviceMemoryProperties );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_INLINE void Allocator::getMemoryProperties( const VkPhysicalDeviceMemoryProperties & pPhysicalDeviceMemoryProperties, Dispatch const & d ) const VKMA_NOEXCEPT
  {
    d.vmaGetMemoryProperties( m_allocator, &pPhysicalDeviceMemoryProperties );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_INLINE void Allocator::getMemoryTypeProperties( uint32_t memoryTypeIndex, VkMemoryPropertyFlags* pFlags, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaGetMemoryTypeProperties( m_allocator, memoryTypeIndex, pFlags );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkMemoryPropertyFlags Allocator::getMemoryTypeProperties( uint32_t memoryTypeIndex, Dispatch const & d ) const VKMA_NOEXCEPT
  {
    VkMemoryPropertyFlags flags;
    d.vmaGetMemoryTypeProperties( m_allocator, memoryTypeIndex, &flags );
    return flags;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_INLINE void Allocator::getPhysicalDeviceProperties( const VkPhysicalDeviceProperties** ppPhysicalDeviceProperties, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaGetPhysicalDeviceProperties( m_allocator, ppPhysicalDeviceProperties );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_INLINE void Allocator::getPhysicalDeviceProperties( const VkPhysicalDeviceProperties & pPhysicalDeviceProperties, Dispatch const & d ) const VKMA_NOEXCEPT
  {
    d.vmaGetPhysicalDeviceProperties( m_allocator, &pPhysicalDeviceProperties );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_INLINE void Allocator::getPoolName( Pool pool, const char** ppName, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaGetPoolName( m_allocator, static_cast<VmaPool>( pool ), ppName );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_INLINE void Allocator::getPoolName( Pool pool, const char & pName, Dispatch const & d ) const VKMA_NOEXCEPT
  {
    d.vmaGetPoolName( m_allocator, static_cast<VmaPool>( pool ), &pName );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_INLINE void Allocator::getPoolStats( Pool pool, PoolStats* pPoolStats, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaGetPoolStats( m_allocator, static_cast<VmaPool>( pool ), reinterpret_cast< VmaPoolStats *>( pPoolStats ) );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VKMA_NAMESPACE::PoolStats Allocator::getPoolStats( Pool pool, Dispatch const & d ) const VKMA_NOEXCEPT
  {
    VKMA_NAMESPACE::PoolStats poolStats;
    d.vmaGetPoolStats( m_allocator, static_cast<VmaPool>( pool ), reinterpret_cast<VmaPoolStats *>( &poolStats ) );
    return poolStats;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_INLINE void Allocator::invalidateAllocation( Allocation allocation, VkDeviceSize offset, VkDeviceSize size, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaInvalidateAllocation( m_allocator, static_cast<VmaAllocation>( allocation ), offset, size );
  }


  template <typename Dispatch>
  VKMA_INLINE void Allocator::makePoolAllocationsLost( Pool pool, size_t* pLostAllocationCount, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaMakePoolAllocationsLost( m_allocator, static_cast<VmaPool>( pool ), pLostAllocationCount );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE size_t Allocator::makePoolAllocationsLost( Pool pool, Dispatch const & d ) const VKMA_NOEXCEPT
  {
    size_t lostAllocationCount;
    d.vmaMakePoolAllocationsLost( m_allocator, static_cast<VmaPool>( pool ), &lostAllocationCount );
    return lostAllocationCount;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkResult Allocator::mapMemory( Allocation allocation, void** ppData, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    return d.vmaMapMemory( m_allocator, static_cast<VmaAllocation>( allocation ), ppData );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void*>::type Allocator::mapMemory( Allocation allocation, Dispatch const & d ) const
  {
    void* pData;
    Result result = static_cast<Result>( d.vmaMapMemory( m_allocator, static_cast<VmaAllocation>( allocation ), &pData ) );
    return createResultValue( result, pData, VKMA_NAMESPACE_STRING "::Allocator::mapMemory" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


#ifdef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE VkResult Allocator::resizeAllocation( Allocation allocation, VkDeviceSize newSize, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    return d.vmaResizeAllocation( m_allocator, static_cast<VmaAllocation>( allocation ), newSize );
  }
#else
  template <typename Dispatch>
  VKMA_NODISCARD_WHEN_NO_EXCEPTIONS VKMA_INLINE typename ResultValueType<void>::type Allocator::resizeAllocation( Allocation allocation, VkDeviceSize newSize, Dispatch const & d ) const
  {
    Result result = static_cast<Result>( d.vmaResizeAllocation( m_allocator, static_cast<VmaAllocation>( allocation ), newSize ) );
    return createResultValue( result, VKMA_NAMESPACE_STRING "::Allocator::resizeAllocation" );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/



  template <typename Dispatch>
  VKMA_INLINE void Allocator::setAllocationUserData( Allocation allocation, void* pUserData, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaSetAllocationUserData( m_allocator, static_cast<VmaAllocation>( allocation ), pUserData );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_NODISCARD VKMA_INLINE void Allocator::setAllocationUserData( Allocation allocation, Dispatch const & d ) const VKMA_NOEXCEPT
  {
    void userData;
    d.vmaSetAllocationUserData( m_allocator, static_cast<VmaAllocation>( allocation ), &userData );
    return userData;
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_INLINE void Allocator::setCurrentFrameIndex( uint32_t frameIndex, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaSetCurrentFrameIndex( m_allocator, frameIndex );
  }


  template <typename Dispatch>
  VKMA_INLINE void Allocator::setPoolName( Pool pool, const char* pName, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaSetPoolName( m_allocator, static_cast<VmaPool>( pool ), pName );
  }

#ifndef VKMA_DISABLE_ENHANCED_MODE
  template <typename Dispatch>
  VKMA_INLINE void Allocator::setPoolName( Pool pool, const char & name, Dispatch const & d ) const VKMA_NOEXCEPT
  {
    d.vmaSetPoolName( m_allocator, static_cast<VmaPool>( pool ), &name );
  }
#endif /*VKMA_DISABLE_ENHANCED_MODE*/


  template <typename Dispatch>
  VKMA_INLINE VkBool32 Allocator::touchAllocation( Allocation allocation, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    return d.vmaTouchAllocation( m_allocator, static_cast<VmaAllocation>( allocation ) );
  }


  template <typename Dispatch>
  VKMA_INLINE void Allocator::unmapMemory( Allocation allocation, Dispatch const & d  ) const VKMA_NOEXCEPT
  {
    d.vmaUnmapMemory( m_allocator, static_cast<VmaAllocation>( allocation ) );
  }

#if VKMA_ENABLE_DYNAMIC_LOADER_TOOL
  class DynamicLoader
  {
  public:
#  ifdef VKMA_NO_EXCEPTIONS
    DynamicLoader( std::string const & vulkanLibraryName = {} ) VKMA_NOEXCEPT
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

#ifndef VKMA_NO_EXCEPTIONS
      if ( m_library == nullptr )
      {
        // NOTE there should be an InitializationFailedError, but msvc insists on the symbol does not exist within the scope of this function.
        throw std::runtime_error( "Failed to load vulkan library!" );
      }
#endif
    }

    DynamicLoader( DynamicLoader const& ) = delete;

    DynamicLoader( DynamicLoader && other ) VKMA_NOEXCEPT : m_library(other.m_library)
    {
      other.m_library = nullptr;
    }

    DynamicLoader &operator=( DynamicLoader const& ) = delete;

    DynamicLoader &operator=( DynamicLoader && other ) VKMA_NOEXCEPT
    {
      std::swap(m_library, other.m_library);
      return *this;
    }

    ~DynamicLoader() VKMA_NOEXCEPT
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
    T getProcAddress( const char* function ) const VKMA_NOEXCEPT
    {
#  if defined( __linux__ ) || defined( __APPLE__ )
      return (T)dlsym( m_library, function );
#  elif defined( _WIN32 )
      return (T)::GetProcAddress( m_library, function );
#  else
#    error unsupported platform
#  endif
    }

    bool success() const VKMA_NOEXCEPT { return m_library != nullptr; }

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
    DispatchLoaderDynamic() VKMA_NOEXCEPT = default;

#if !defined(VMA_NO_PROTOTYPES)
    // This interface is designed to be used for per-device function pointers in combination with a linked vulkan library.
    template <typename DynamicLoader>
    void init(VKMA_NAMESPACE::Instance const& instance, VKMA_NAMESPACE::Device const& device, DynamicLoader const& dl) VKMA_NOEXCEPT
    {
      PFN_vmaGetInstanceProcAddr getInstanceProcAddr = dl.template getProcAddress<PFN_vmaGetInstanceProcAddr>("vmaGetInstanceProcAddr");
      PFN_vmaGetDeviceProcAddr getDeviceProcAddr = dl.template getProcAddress<PFN_vmaGetDeviceProcAddr>("vmaGetDeviceProcAddr");
      init(static_cast<VmaInstance>(instance), getInstanceProcAddr, static_cast<VmaDevice>(device), device ? getDeviceProcAddr : nullptr);
    }

    // This interface is designed to be used for per-device function pointers in combination with a linked vulkan library.
    template <typename DynamicLoader
#if VKMA_ENABLE_DYNAMIC_LOADER_TOOL
      = VKMA_NAMESPACE::DynamicLoader
#endif
    >
    void init(VKMA_NAMESPACE::Instance const& instance, VKMA_NAMESPACE::Device const& device) VKMA_NOEXCEPT
    {
      static DynamicLoader dl;
      init(instance, device, dl);
    }
#endif // !defined(VMA_NO_PROTOTYPES)

    DispatchLoaderDynamic(PFN_vmaGetInstanceProcAddr getInstanceProcAddr) VKMA_NOEXCEPT
    {
      init(getInstanceProcAddr);
    }

    void init( PFN_vmaGetInstanceProcAddr getInstanceProcAddr ) VKMA_NOEXCEPT
    {
      VKMA_ASSERT(getInstanceProcAddr);

      vmaGetInstanceProcAddr = getInstanceProcAddr;
      vmaCreateAllocator = PFN_vmaCreateAllocator( vmaGetInstanceProcAddr( NULL, "vmaCreateAllocator" ) );
    }

    // This interface does not require a linked vulkan library.
    DispatchLoaderDynamic( VmaInstance instance, PFN_vmaGetInstanceProcAddr getInstanceProcAddr, VmaDevice device = VMA_NULL_HANDLE, PFN_vmaGetDeviceProcAddr getDeviceProcAddr = nullptr ) VKMA_NOEXCEPT
    {
      init( instance, getInstanceProcAddr, device, getDeviceProcAddr );
    }

    // This interface does not require a linked vulkan library.
    void init( VmaInstance instance, PFN_vmaGetInstanceProcAddr getInstanceProcAddr, VmaDevice device = VMA_NULL_HANDLE, PFN_vmaGetDeviceProcAddr /*getDeviceProcAddr*/ = nullptr ) VKMA_NOEXCEPT
    {
      VKMA_ASSERT(instance && getInstanceProcAddr);
      vmaGetInstanceProcAddr = getInstanceProcAddr;
      init( VKMA_NAMESPACE::Instance(instance) );
      if (device) {
        init( VKMA_NAMESPACE::Device(device) );
      }
    }

    void init( VKMA_NAMESPACE::Instance instanceCpp ) VKMA_NOEXCEPT
    {
      VmaInstance instance = static_cast<VmaInstance>(instanceCpp);
      vmaAllocateMemory = PFN_vmaAllocateMemory( vmaGetInstanceProcAddr( instance, "vmaAllocateMemory" ) );
      vmaAllocateMemoryForBuffer = PFN_vmaAllocateMemoryForBuffer( vmaGetInstanceProcAddr( instance, "vmaAllocateMemoryForBuffer" ) );
      vmaAllocateMemoryForImage = PFN_vmaAllocateMemoryForImage( vmaGetInstanceProcAddr( instance, "vmaAllocateMemoryForImage" ) );
      vmaAllocateMemoryPages = PFN_vmaAllocateMemoryPages( vmaGetInstanceProcAddr( instance, "vmaAllocateMemoryPages" ) );
      vmaBindBufferMemory = PFN_vmaBindBufferMemory( vmaGetInstanceProcAddr( instance, "vmaBindBufferMemory" ) );
      vmaBindBufferMemory2 = PFN_vmaBindBufferMemory2( vmaGetInstanceProcAddr( instance, "vmaBindBufferMemory2" ) );
      vmaBindImageMemory = PFN_vmaBindImageMemory( vmaGetInstanceProcAddr( instance, "vmaBindImageMemory" ) );
      vmaBindImageMemory2 = PFN_vmaBindImageMemory2( vmaGetInstanceProcAddr( instance, "vmaBindImageMemory2" ) );
      vmaBuildStatsString = PFN_vmaBuildStatsString( vmaGetInstanceProcAddr( instance, "vmaBuildStatsString" ) );
      vmaCalculateStats = PFN_vmaCalculateStats( vmaGetInstanceProcAddr( instance, "vmaCalculateStats" ) );
      vmaCheckCorruption = PFN_vmaCheckCorruption( vmaGetInstanceProcAddr( instance, "vmaCheckCorruption" ) );
      vmaCheckPoolCorruption = PFN_vmaCheckPoolCorruption( vmaGetInstanceProcAddr( instance, "vmaCheckPoolCorruption" ) );
      vmaCreateBuffer = PFN_vmaCreateBuffer( vmaGetInstanceProcAddr( instance, "vmaCreateBuffer" ) );
      vmaCreateImage = PFN_vmaCreateImage( vmaGetInstanceProcAddr( instance, "vmaCreateImage" ) );
      vmaCreateLostAllocation = PFN_vmaCreateLostAllocation( vmaGetInstanceProcAddr( instance, "vmaCreateLostAllocation" ) );
      vmaCreatePool = PFN_vmaCreatePool( vmaGetInstanceProcAddr( instance, "vmaCreatePool" ) );
      vmaDefragment = PFN_vmaDefragment( vmaGetInstanceProcAddr( instance, "vmaDefragment" ) );
      vmaDefragmentationBegin = PFN_vmaDefragmentationBegin( vmaGetInstanceProcAddr( instance, "vmaDefragmentationBegin" ) );
      vmaDefragmentationEnd = PFN_vmaDefragmentationEnd( vmaGetInstanceProcAddr( instance, "vmaDefragmentationEnd" ) );
      vmaDestroyAllocator = PFN_vmaDestroyAllocator( vmaGetInstanceProcAddr( instance, "vmaDestroyAllocator" ) );
      vmaDestroyBuffer = PFN_vmaDestroyBuffer( vmaGetInstanceProcAddr( instance, "vmaDestroyBuffer" ) );
      vmaDestroyImage = PFN_vmaDestroyImage( vmaGetInstanceProcAddr( instance, "vmaDestroyImage" ) );
      vmaDestroyPool = PFN_vmaDestroyPool( vmaGetInstanceProcAddr( instance, "vmaDestroyPool" ) );
      vmaFindMemoryTypeIndex = PFN_vmaFindMemoryTypeIndex( vmaGetInstanceProcAddr( instance, "vmaFindMemoryTypeIndex" ) );
      vmaFindMemoryTypeIndexForBufferInfo = PFN_vmaFindMemoryTypeIndexForBufferInfo( vmaGetInstanceProcAddr( instance, "vmaFindMemoryTypeIndexForBufferInfo" ) );
      vmaFindMemoryTypeIndexForImageInfo = PFN_vmaFindMemoryTypeIndexForImageInfo( vmaGetInstanceProcAddr( instance, "vmaFindMemoryTypeIndexForImageInfo" ) );
      vmaFlushAllocation = PFN_vmaFlushAllocation( vmaGetInstanceProcAddr( instance, "vmaFlushAllocation" ) );
      vmaFreeMemory = PFN_vmaFreeMemory( vmaGetInstanceProcAddr( instance, "vmaFreeMemory" ) );
      vmaFreeMemoryPages = PFN_vmaFreeMemoryPages( vmaGetInstanceProcAddr( instance, "vmaFreeMemoryPages" ) );
      vmaFreeStatsString = PFN_vmaFreeStatsString( vmaGetInstanceProcAddr( instance, "vmaFreeStatsString" ) );
      vmaGetAllocationInfo = PFN_vmaGetAllocationInfo( vmaGetInstanceProcAddr( instance, "vmaGetAllocationInfo" ) );
      vmaGetBudget = PFN_vmaGetBudget( vmaGetInstanceProcAddr( instance, "vmaGetBudget" ) );
      vmaGetMemoryProperties = PFN_vmaGetMemoryProperties( vmaGetInstanceProcAddr( instance, "vmaGetMemoryProperties" ) );
      vmaGetMemoryTypeProperties = PFN_vmaGetMemoryTypeProperties( vmaGetInstanceProcAddr( instance, "vmaGetMemoryTypeProperties" ) );
      vmaGetPhysicalDeviceProperties = PFN_vmaGetPhysicalDeviceProperties( vmaGetInstanceProcAddr( instance, "vmaGetPhysicalDeviceProperties" ) );
      vmaGetPoolName = PFN_vmaGetPoolName( vmaGetInstanceProcAddr( instance, "vmaGetPoolName" ) );
      vmaGetPoolStats = PFN_vmaGetPoolStats( vmaGetInstanceProcAddr( instance, "vmaGetPoolStats" ) );
      vmaInvalidateAllocation = PFN_vmaInvalidateAllocation( vmaGetInstanceProcAddr( instance, "vmaInvalidateAllocation" ) );
      vmaMakePoolAllocationsLost = PFN_vmaMakePoolAllocationsLost( vmaGetInstanceProcAddr( instance, "vmaMakePoolAllocationsLost" ) );
      vmaMapMemory = PFN_vmaMapMemory( vmaGetInstanceProcAddr( instance, "vmaMapMemory" ) );
      vmaResizeAllocation = PFN_vmaResizeAllocation( vmaGetInstanceProcAddr( instance, "vmaResizeAllocation" ) );
      vmaSetAllocationUserData = PFN_vmaSetAllocationUserData( vmaGetInstanceProcAddr( instance, "vmaSetAllocationUserData" ) );
      vmaSetCurrentFrameIndex = PFN_vmaSetCurrentFrameIndex( vmaGetInstanceProcAddr( instance, "vmaSetCurrentFrameIndex" ) );
      vmaSetPoolName = PFN_vmaSetPoolName( vmaGetInstanceProcAddr( instance, "vmaSetPoolName" ) );
      vmaTouchAllocation = PFN_vmaTouchAllocation( vmaGetInstanceProcAddr( instance, "vmaTouchAllocation" ) );
      vmaUnmapMemory = PFN_vmaUnmapMemory( vmaGetInstanceProcAddr( instance, "vmaUnmapMemory" ) );
    }

    void init( VKMA_NAMESPACE::Device deviceCpp ) VKMA_NOEXCEPT
    {
      VmaDevice device = static_cast<VmaDevice>(deviceCpp);
      vmaAllocateMemory = PFN_vmaAllocateMemory( vmaGetDeviceProcAddr( device, "vmaAllocateMemory" ) );
      vmaAllocateMemoryForBuffer = PFN_vmaAllocateMemoryForBuffer( vmaGetDeviceProcAddr( device, "vmaAllocateMemoryForBuffer" ) );
      vmaAllocateMemoryForImage = PFN_vmaAllocateMemoryForImage( vmaGetDeviceProcAddr( device, "vmaAllocateMemoryForImage" ) );
      vmaAllocateMemoryPages = PFN_vmaAllocateMemoryPages( vmaGetDeviceProcAddr( device, "vmaAllocateMemoryPages" ) );
      vmaBindBufferMemory = PFN_vmaBindBufferMemory( vmaGetDeviceProcAddr( device, "vmaBindBufferMemory" ) );
      vmaBindBufferMemory2 = PFN_vmaBindBufferMemory2( vmaGetDeviceProcAddr( device, "vmaBindBufferMemory2" ) );
      vmaBindImageMemory = PFN_vmaBindImageMemory( vmaGetDeviceProcAddr( device, "vmaBindImageMemory" ) );
      vmaBindImageMemory2 = PFN_vmaBindImageMemory2( vmaGetDeviceProcAddr( device, "vmaBindImageMemory2" ) );
      vmaBuildStatsString = PFN_vmaBuildStatsString( vmaGetDeviceProcAddr( device, "vmaBuildStatsString" ) );
      vmaCalculateStats = PFN_vmaCalculateStats( vmaGetDeviceProcAddr( device, "vmaCalculateStats" ) );
      vmaCheckCorruption = PFN_vmaCheckCorruption( vmaGetDeviceProcAddr( device, "vmaCheckCorruption" ) );
      vmaCheckPoolCorruption = PFN_vmaCheckPoolCorruption( vmaGetDeviceProcAddr( device, "vmaCheckPoolCorruption" ) );
      vmaCreateBuffer = PFN_vmaCreateBuffer( vmaGetDeviceProcAddr( device, "vmaCreateBuffer" ) );
      vmaCreateImage = PFN_vmaCreateImage( vmaGetDeviceProcAddr( device, "vmaCreateImage" ) );
      vmaCreateLostAllocation = PFN_vmaCreateLostAllocation( vmaGetDeviceProcAddr( device, "vmaCreateLostAllocation" ) );
      vmaCreatePool = PFN_vmaCreatePool( vmaGetDeviceProcAddr( device, "vmaCreatePool" ) );
      vmaDefragment = PFN_vmaDefragment( vmaGetDeviceProcAddr( device, "vmaDefragment" ) );
      vmaDefragmentationBegin = PFN_vmaDefragmentationBegin( vmaGetDeviceProcAddr( device, "vmaDefragmentationBegin" ) );
      vmaDefragmentationEnd = PFN_vmaDefragmentationEnd( vmaGetDeviceProcAddr( device, "vmaDefragmentationEnd" ) );
      vmaDestroyAllocator = PFN_vmaDestroyAllocator( vmaGetDeviceProcAddr( device, "vmaDestroyAllocator" ) );
      vmaDestroyBuffer = PFN_vmaDestroyBuffer( vmaGetDeviceProcAddr( device, "vmaDestroyBuffer" ) );
      vmaDestroyImage = PFN_vmaDestroyImage( vmaGetDeviceProcAddr( device, "vmaDestroyImage" ) );
      vmaDestroyPool = PFN_vmaDestroyPool( vmaGetDeviceProcAddr( device, "vmaDestroyPool" ) );
      vmaFindMemoryTypeIndex = PFN_vmaFindMemoryTypeIndex( vmaGetDeviceProcAddr( device, "vmaFindMemoryTypeIndex" ) );
      vmaFindMemoryTypeIndexForBufferInfo = PFN_vmaFindMemoryTypeIndexForBufferInfo( vmaGetDeviceProcAddr( device, "vmaFindMemoryTypeIndexForBufferInfo" ) );
      vmaFindMemoryTypeIndexForImageInfo = PFN_vmaFindMemoryTypeIndexForImageInfo( vmaGetDeviceProcAddr( device, "vmaFindMemoryTypeIndexForImageInfo" ) );
      vmaFlushAllocation = PFN_vmaFlushAllocation( vmaGetDeviceProcAddr( device, "vmaFlushAllocation" ) );
      vmaFreeMemory = PFN_vmaFreeMemory( vmaGetDeviceProcAddr( device, "vmaFreeMemory" ) );
      vmaFreeMemoryPages = PFN_vmaFreeMemoryPages( vmaGetDeviceProcAddr( device, "vmaFreeMemoryPages" ) );
      vmaFreeStatsString = PFN_vmaFreeStatsString( vmaGetDeviceProcAddr( device, "vmaFreeStatsString" ) );
      vmaGetAllocationInfo = PFN_vmaGetAllocationInfo( vmaGetDeviceProcAddr( device, "vmaGetAllocationInfo" ) );
      vmaGetBudget = PFN_vmaGetBudget( vmaGetDeviceProcAddr( device, "vmaGetBudget" ) );
      vmaGetMemoryProperties = PFN_vmaGetMemoryProperties( vmaGetDeviceProcAddr( device, "vmaGetMemoryProperties" ) );
      vmaGetMemoryTypeProperties = PFN_vmaGetMemoryTypeProperties( vmaGetDeviceProcAddr( device, "vmaGetMemoryTypeProperties" ) );
      vmaGetPhysicalDeviceProperties = PFN_vmaGetPhysicalDeviceProperties( vmaGetDeviceProcAddr( device, "vmaGetPhysicalDeviceProperties" ) );
      vmaGetPoolName = PFN_vmaGetPoolName( vmaGetDeviceProcAddr( device, "vmaGetPoolName" ) );
      vmaGetPoolStats = PFN_vmaGetPoolStats( vmaGetDeviceProcAddr( device, "vmaGetPoolStats" ) );
      vmaInvalidateAllocation = PFN_vmaInvalidateAllocation( vmaGetDeviceProcAddr( device, "vmaInvalidateAllocation" ) );
      vmaMakePoolAllocationsLost = PFN_vmaMakePoolAllocationsLost( vmaGetDeviceProcAddr( device, "vmaMakePoolAllocationsLost" ) );
      vmaMapMemory = PFN_vmaMapMemory( vmaGetDeviceProcAddr( device, "vmaMapMemory" ) );
      vmaResizeAllocation = PFN_vmaResizeAllocation( vmaGetDeviceProcAddr( device, "vmaResizeAllocation" ) );
      vmaSetAllocationUserData = PFN_vmaSetAllocationUserData( vmaGetDeviceProcAddr( device, "vmaSetAllocationUserData" ) );
      vmaSetCurrentFrameIndex = PFN_vmaSetCurrentFrameIndex( vmaGetDeviceProcAddr( device, "vmaSetCurrentFrameIndex" ) );
      vmaSetPoolName = PFN_vmaSetPoolName( vmaGetDeviceProcAddr( device, "vmaSetPoolName" ) );
      vmaTouchAllocation = PFN_vmaTouchAllocation( vmaGetDeviceProcAddr( device, "vmaTouchAllocation" ) );
      vmaUnmapMemory = PFN_vmaUnmapMemory( vmaGetDeviceProcAddr( device, "vmaUnmapMemory" ) );
    }
  };

} // namespace VKMA_NAMESPACE

namespace std
{

  template <> struct hash<VKMA_NAMESPACE::Allocation>
  {
    std::size_t operator()(VKMA_NAMESPACE::Allocation const& allocation) const VKMA_NOEXCEPT
    {
      return std::hash<VmaAllocation>{}(static_cast<VmaAllocation>(allocation));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::Allocator>
  {
    std::size_t operator()(VKMA_NAMESPACE::Allocator const& allocator) const VKMA_NOEXCEPT
    {
      return std::hash<VmaAllocator>{}(static_cast<VmaAllocator>(allocator));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::DefragmentationContext>
  {
    std::size_t operator()(VKMA_NAMESPACE::DefragmentationContext const& defragmentationContext) const VKMA_NOEXCEPT
    {
      return std::hash<VmaDefragmentationContext>{}(static_cast<VmaDefragmentationContext>(defragmentationContext));
    }
  };

  template <> struct hash<VKMA_NAMESPACE::Pool>
  {
    std::size_t operator()(VKMA_NAMESPACE::Pool const& pool) const VKMA_NOEXCEPT
    {
      return std::hash<VmaPool>{}(static_cast<VmaPool>(pool));
    }
  };
}
#endif
