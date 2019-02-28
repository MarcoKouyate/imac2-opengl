#version 330 core

in vec3 vFragColor;
in vec2 vFragPosition;

out vec3 fFragColor;

float blur (const float a, const float b){
	float dist = distance(vec2(0.0f,0.0f), vFragPosition);
	float att = a*exp(-b * pow(dist,2));
	return att;

}

/*Il est possible de générer des patterns en combinant des fonctions simples comme fract, abs, smoothstep, mod, floor, ... Renseignez vous sur chacune de ces fonctions.

Voici quelques formules permettant de créer quelques patterns (PP est la position du fragment dans l'espace local au triangle):

length(fract(5.0 * P))
length(abs(fract(5.0 * P) * 2.0 - 1.0))
mod(floor(10.0 * P.x) + floor(10.0 * P.y), 2.0)
smoothstep(0.3, 0.32, length(fract(5.0 * P) - 0.5))
smoothstep(0.4, 0.5, max(abs(fract(8.0 * P.x - 0.5 * mod(floor(8.0 * P.y), 2.0)) - 0.5), abs(fract(8.0 * P.y) - 0.5)))
Chaque formule produit un coefficient que vous pouvez appliquer à la couleur du fragment (multiplication)*/

float fractional1(const float coeff){
	return length(fract(coeff *vFragPosition));
}

float fractional2(const float coeff){
	return length(abs(fract(coeff * vFragPosition) * 2.0f * 1.0f ));
}

float chess(const float coeff){
	return mod(floor(coeff * vFragPosition.x) + floor(coeff * vFragPosition.y), 2.0);
}

float smoothstep1(){
	return smoothstep(0.3, 0.32, length(fract(5.0 * vFragPosition) - 0.5));
}

float smoothstep2(){
	return smoothstep(0.4, 0.5, max(abs(fract(8.0 * vFragPosition.x - 0.5 * mod(floor(8.0 * vFragPosition.y), 2.0)) - 0.5), abs(fract(8.0 * vFragPosition.y) - 0.5)));
}


void main() {

  fFragColor = vFragColor * smoothstep2();
};