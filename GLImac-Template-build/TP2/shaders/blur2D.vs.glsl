#version 330 core//version de GLSL utilisé


layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vFragColor;
out vec2 vFragPosition;

mat3 translate(float tx, float ty) {
	mat3 M = mat3(vec3(1, 0, 0), vec3(0, 1, 0), vec3(tx, ty, 1));
	return M;
}

mat3 scale(float sx, float sy){
	mat3 M = mat3(vec3(sx, 0, 0), vec3(0, sy, 0), vec3(0, 0, 1));
	return M;
}

mat3 rotate(float alpha){
	mat3 M = mat3(vec3(cos(radians(alpha)), sin(radians(alpha)), 0), vec3(cos(radians(alpha)), -sin(radians(alpha)), 0), vec3(0, 0, 1));
	return M;
}


void main() {
	 vFragColor = aVertexColor;
	 vFragPosition = aVertexPosition;

	mat3 transformation = translate(0,0) * scale(1,1)*rotate(45);

	vec2 transformed = (vec3(aVertexPosition, 1) * transformation).xy;
	gl_Position = vec4(transformed, 0, 1);
};