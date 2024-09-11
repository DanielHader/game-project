#ifndef MATH_AFFINE_TRANSFORM_HPP
#define MATH_AFFINE_TRANSFORM_HPP

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/quaternion.hpp>

class AffineTransform {
private:
    glm::vec3 translation;
    glm::quat orientation;

public:
    AffineTransform();
    virtual ~AffineTransform();
    
    static AffineTransform identity();
    static AffineTransform from_matrix(const glm::mat4 &matrix);
    
    glm::mat4 to_matrix() const;
};

#endif
