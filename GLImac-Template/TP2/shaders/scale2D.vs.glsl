#version 330 core//version de GLSL utilisé


layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vFragColor;


void main() {
	int scale = 2;
  
  gl_Position = vec4(aVertexPosition * scale, 0, 1);
  vFragColor = aVertexColor;
};