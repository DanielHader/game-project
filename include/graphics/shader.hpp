#ifndef GRAPHICS_SHADER_HPP
#define GRAPHICS_SHADER_HPP

#include <GL/glew.h>
#include <string>
#include <array>

class ShaderType {
public:
    enum Value { Vertex, Fragment };

    ShaderType() = default;
    constexpr ShaderType(Value value) : value(value) {}

    constexpr operator Value() const { return this->value; }

    constexpr operator GLuint() const {
        switch (this->value) {
        case Vertex: return GL_VERTEX_SHADER;
        case Fragment: return GL_FRAGMENT_SHADER;
        default: return 0;
        }
    }

    constexpr const char *str() const {
        switch (this->value) {
        case Vertex: return "Vertex";
        case Fragment: return "Fragment";
        default: return "Unknown";
        }
    }
    
    // prevent if(shader_type)
    explicit operator bool() const = delete;
private:
    Value value;
};

class Shader {

    GLuint handle;
    
public:
    Shader(const std::string &src, ShaderType type);
    virtual ~Shader();
};

#endif
