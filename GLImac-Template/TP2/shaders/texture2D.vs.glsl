#version 330 core//version de GLSL utilisé


layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;
layout(location = 2) in vec2 aVertexTexture;

out vec3 vFragColor;
out vec2 vFragPosition;
out vec2 vFragTexture;

uniform float uTime;
uniform mat3 uModelMatrix;


void main() {
  vFragColor = aVertexColor;
  vFragPosition = aVertexPosition;
  vFragTexture = aVertexTexture;

  vec2 transformed = (uModelMatrix * vec3(aVertexPosition, 1)).xy;

  gl_Position = vec4(transformed, 0, 1);
};