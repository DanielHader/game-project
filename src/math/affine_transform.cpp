#include "math/affine_transform.hpp"

AffineTransform::AffineTransform() : translation(), orientation() {}
AffineTransform::~AffineTransform() {}

AffineTransform AffineTransform::identity() {
    return AffineTransform();
}

AffineTransform AffineTransform::from_matrix(const glm::mat4 &matrix) {
    // todo finish this
    return AffineTransform();
}

glm::mat4 to_matrix() {
    // todo finish this
    return glm::mat4();
}

