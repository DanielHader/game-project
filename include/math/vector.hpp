#ifndef MATH_VECTOR_HPP
#define MATH_VECTOR_HPP

#include <initializer_list>
#include <array>

template <typename T, std::size_t N>
class Vector {
private:
    std::array<T, N> data;

public:
    Vector() : data{0, 0, 0} {}
    
    template <typename... Ts>
    Vector(Ts... ts) : data{ts...} {}
    
    T& operator[](std::size_t i) { return data[i]; }
    const T& operator[](std::size_t i) const { return data[i]; }
};


typedef Vector<float, 3> vec3;
typedef Vector<int, 3> ivec3;

#endif
