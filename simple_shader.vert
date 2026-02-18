#version 450

layout(location = 0) in vec2 position; // First vertex attribute

void main() {
	gl_Position = vec4(position, 0.0, 1.0);
}