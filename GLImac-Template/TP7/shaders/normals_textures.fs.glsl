#version 330 core

in vec3 vPosition_vs;
in vec3 vNormal_vs;
in vec2 vTexCoords;

out vec3 fFragColor;

uniform sampler2D uTexture;

void main()
{
	vec4 textureColor =  texture(uTexture, vTexCoords);
	fFragColor = textureColor.xyz;
	//fFragColor = vec3(normalize(vNormal_vs));
}