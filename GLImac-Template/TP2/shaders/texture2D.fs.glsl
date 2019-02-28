#version 330 core

in vec3 vFragColor;
in vec2 vFragTexture;

out vec3 fFragColor;

uniform vec3 uColor;
uniform sampler2D uTexture;

void main() {
  vec4 textureColor =  texture(uTexture, vFragTexture);

  //fFragColor = vFragColor;

  fFragColor = textureColor.xyz;
  


};