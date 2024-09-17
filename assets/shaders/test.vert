#version 330

uniform mat4 u_model_view_matrix;
uniform mat4 u_projection_matrix;

in vec3 a_position;

void main() {

    gl_Position = u_projection_matrix * u_model_view_matrix * vec4(a_position, 1.0f);
}
