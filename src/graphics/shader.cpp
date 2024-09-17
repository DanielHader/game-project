#include "graphics/shader.hpp"

#include <string>
#include <stdexcept>

#include <iostream>

Shader::Shader(const std::string &src, ShaderType type) {

    this->handle = glCreateShader(type);
    if (this->handle == 0) {
        std::string msg("Failed to create shader of type: ");
        msg += type.str();
        throw std::runtime_error(msg);
    }

    const GLchar *src_buffer;
    glShaderSource(this->handle, 1, &(src_buffer = src.data()), NULL);
    glCompileShader(this->handle);

    GLint success = 0;
    glGetShaderiv(this->handle, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {

        GLint log_size = 0;
        glGetShaderiv(this->handle, GL_INFO_LOG_LENGTH, &log_size);

        GLchar log_buffer[log_size];
        glGetShaderInfoLog(this->handle, log_size, NULL, log_buffer);

        glDeleteShader(this->handle);
        std::string msg("Failed to compile shader of type: ");
        msg += type.str();
        msg += "\n";
        msg += log_buffer;
        throw std::runtime_error(msg);
    }
}

Shader::~Shader() {
    glDeleteShader(this->handle);
}
