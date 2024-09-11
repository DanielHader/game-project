#ifndef MATH_AFFINE_TRANSFORM_HPP
#define MATH_AFFINE_TRANSFORM_HPP

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/quaternion.hpp>

class AffineTransform {
private:
    glm::vec3 translation;
    glm::quat rotation;

public:
    AffineTransform();
    AffineTransform(glm::vec3, glm::quat);
    virtual ~AffineTransform();
    
    static AffineTransform identity();
    static AffineTransform from_matrix(const glm::mat4 &matrix);
    static AffineTransform from_angle_axis_offset(float angle, glm::vec3 axis, glm::vec3 offset);
    
    glm::mat4 to_matrix() const;

    glm::vec3 operator()(const glm::vec3 &vec) const;
};

#endif
