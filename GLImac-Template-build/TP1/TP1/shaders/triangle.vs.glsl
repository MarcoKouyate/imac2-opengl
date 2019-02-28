/*La première ligne indique à OpenGL la version de GLSL à utiliser.*/ 
#version 330 


layout(location = 3) in vec2 aVertexPosition;
layout(location = 8) in vec3 aVertexColor;

//La location permet de faire le lien avec l'application C++

out vec3 vColor; //déclare une variable de sortie du shader

void main() {
    vColor = aVertexColor; //affecte la couleur d'entrée à la variable de sortie.
    gl_Position = vec4(aVertexPosition, 0, 1); //Pour l'instant, en 2D, gardez à l'esprit qu'on ajoutera toujours 0 et 1 à la fin de nos positions.
    
    /*Cette variable représente les coordonnées projetées à l'écran du sommet. Dans le cas de la 2D il n'y a pas de projection, aucune transformation n'est donc appliquée ici. On ajoute néammoins deux coordonnées. Une profondeur z = 0 car on considère qu'on regarde le plan 2D z = 0 (on pourrait mettre n'importe quelle valeur entre -1 et 1, cela ne changerait rien). On ajoute également une coordonnée homogène (OpenGL travaille avec des coordonnées homogènes) w = 1. Quand nous ferons de la 3D, cette coordonnée sera calculée par la transformation projective. */
}
