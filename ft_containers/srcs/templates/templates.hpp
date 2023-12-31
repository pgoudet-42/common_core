 #pragma once

#include <exception>
#include <iostream>

namespace ft {
template <typename T1, typename T2>
class pair
{
  public:
		T1 first;
    T2 second;
    pair() : first(), second() {};
    pair(const T1& a, const T2& b) : first(a), second(b) {};
    pair(const pair<T1, T2>& copy) : first(copy.first), second(copy.second) {};
    template <typename U, typename V>
    pair(const pair<U, V>& copy) : first(copy.first), second(copy.second) {};
    ~pair() {};
    pair& operator=(const pair& assign)
    {
        if (this != &assign)
        {
            first = assign.first;
            second = assign.second;
        }
        return (*this);
    }
        
};

   
template <class T>
struct less
{
    typedef T       first_argument_type;
    typedef T       second_argument_type;
    typedef bool    result_type;
    bool operator() (const T& x, const T& y) const {return x<y;}
};

template <bool B>
struct enable_if {};

template <>
struct enable_if<true> { typedef int type; };

template <typename T>
struct is_integral { static const bool value = false; };

template <>
struct is_integral<bool> { static const bool value = true; };
        
template <>
struct is_integral<char> { static const bool value = true; };

template <>
struct is_integral<short> { static const bool value = true; };

template <>
struct is_integral<int> { static const bool value = true; };

template <>
struct is_integral<long> { static const bool value = true; };

template <>
struct is_integral<long long> { static const bool value = true; };

template <>
struct is_integral<unsigned char> { static const bool value = true; };

template <>
struct is_integral<unsigned short> { static const bool value = true; };

template <>
struct is_integral<unsigned int> { static const bool value = true; };

template <>
struct is_integral<unsigned long> { static const bool value = true; };

template <>
struct is_integral<unsigned long long> { static const bool value = true; };

}
