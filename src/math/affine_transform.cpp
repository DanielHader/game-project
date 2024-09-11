#include "math/affine_transform.hpp"

#include <cmath>

AffineTransform::AffineTransform() : translation(), rotation() {}
AffineTransform::AffineTransform(glm::vec3 trans, glm::quat rot) : translation(trans), rotation(rot) {}
AffineTransform::~AffineTransform() {}

AffineTransform AffineTransform::identity() {
    return AffineTransform();
}

AffineTransform AffineTransform::from_matrix(const glm::mat4 &matrix) {
    // todo finish this
    return AffineTransform();
}

AffineTransform AffineTransform::from_angle_axis_offset(float angle, glm::vec3 axis, glm::vec3 offset) {
    float s = sin(angle / 2);
    float c = cos(angle / 2);
    glm::quat rot(c, s * axis.x, s * axis.y, s * axis.z);
    return AffineTransform(offset, rot);
}

glm::mat4 AffineTransform::to_matrix() const {
    // todo finish this
    return glm::mat4();
}

glm::vec3 AffineTransform::operator()(const glm::vec3 &vec) const {
    return this->rotation * vec + this->translation;
}
