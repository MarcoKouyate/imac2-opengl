#version 330 core

in vec3 vFragColor;

out vec3 fFragColor;

uniform vec3 uColor;

void main() {

  fFragColor = uColor;
};