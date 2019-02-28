#version 330 core

in vec3 vPosition_vs;
in vec3 vNormal_vs;
in vec2 vTexCoords;

out vec3 fFragColor;

uniform sampler2D uTexture1;
uniform sampler2D uTexture2;
uniform float uTime;

void main()
{
	vec4 textureColor1 =  texture(uTexture1, vTexCoords);
	vec4 textureColor2 =  texture(uTexture2, vTexCoords + vec2(uTime,0.0));
	fFragColor = textureColor1.xyz + textureColor2.xyz;
	//fFragColor = vec3(normalize(vNormal_vs));
}