
#version 330 core

in vec3 vFragColor;
in vec2 vFragPosition;

out vec3 fFragColor;

float blur (const float a, const float b){
	float dist = distance(vec2(0.0f,0.0f), vFragPosition);
	float att = a*exp(-b * pow(dist,2));
	return att;

}

void main() {

  fFragColor = vFragColor * blur(4, 50);
};