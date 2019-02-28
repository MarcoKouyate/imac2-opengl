//HEADER
#include <glimac/SDLWindowManager.hpp>  //La classe SDLWindowManager se charge de gérer ce qui concerne la SDL: ouverture de fenêtre, récupération d'évenements clavier-souris
#include <GL/glew.h>
#include <iostream>

//NAMESPACES
using namespace glimac;

/*  =================== ETAPES POUR DESSINER UN TRIANGLE ========================
Initialisation:
	Création du VBO
	Binding du VBO
	Envoie des données de vertex
	Débinding du VBO
	Création du VAO
	Binding du VAO
	Activation de l'attribut de sommet 0 (la position)
	Spécification de l'attribut de sommet 0
	Débinding du VAO
Dessin:
	Binding du VAO
	Appel à la fonction de dessin
	Débinding du VAO
Libération des resources
*/



int main(int argc, char** argv) {
	// ============= FENETRE ET BIBLIOTHEQUES =================

    // Va ouvrir une fenêtre de résolution 800x600 dont le titre est "GLImac". La variable windowManager sera utilisée par la suite pour gérer les évenements.
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialise la bibliothèque GLEW. Cette bibliothèque charge l'ensemble des fonctions OpenGL3. Sans elle on peut considerer que l'on a accès qu'aux fonctions OpenGL2.
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    //On affiche ensuite des informations sur OpenGL afin de vérifier que l'on a la bonne version:
    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;


		    /*********************************
		     * HERE SHOULD COME THE INITIALIZATION CODE */

		    //=============== VERTEX BUFFER OBJECT (VBO) =====================

    		/*Un Vertex Buffer Object (VBO) est un tableau (buffer) stocké sur GPU (la carte graphique) destiné a contenir des sommets de triangle (sommmet = Vertex en anglais)
    		Un Vertex est décrit par des attributs de sommet qui peuvent être par exemple sa position, sa normale, ses coordonnées de texture, sa couleur, etc. 
    		En pratique un attribut est juste un ensemble de nombres flottants. 
    		Tout d'abord il faut créer le VBO en utilisant la fonction glGenBuffers. Chaque VBO sera identifié par un entier strictement superieur à 0 qui nous sera renvoyé par OpenGL. La fonction a pour prototype:
		     - glGenBuffers(GLsizei n, GLuint* buffers);
		    		- GLsizei n: le nombre de VBOs à créer.
		    		- GLuint* buffers: un pointeur vers un tableau d'entiers. OpenGL le remplit avec les identifiants des VBOs créés. Si on créé un seul VBO (cas n = 1), on peut juste passer l'addresse d'une variable.*/


		    GLuint vbo; // definition du Vertex Buffer Object (VBO stockant les attributs)
		    glGenBuffers(1, &vbo); //remplit le tableau d'entier par les identifiants des VBOs (ici il n'y en a qu'un seul)
		    

		    //================== BINDING DU VBO =======================
		    /*Pour modifier le VBO créé (le remplir avec des données) il faut le binder sur une cible. 
		    On applique ensuite les opérations de modification en spécifiant la cible sur laquelle est bindé le VBO.*/
		    glBindBuffer(GL_ARRAY_BUFFER, vbo);  // on utilise la cible GL_ARRAY_BUFFER pour les VBOs
		    // On peut à présent modifier le VBO en passant par la cible GL_ARRAY_BUFFER

			
		    //================= REMPLIR LE VBO ========================
		    /*Il faut envoyer les données de nos sommets à la carte graphique pour qu'elles soient placées dans le VBO.
		    On veut dessiner un triangle au centre de l'écran. Par défaut l'écran représente l'espace 2D allant de -1 à 1 sur chacun des axes.*/


			//Il faut commencer par creer un tableau de GLfloat contenant toutes ces coordonnées à la suite:
			GLfloat vertices[] = { -0.5f, -0.5f, 0.5f, -0.5f, 0.0f, 0.5f };

			/*L'envoi des données se fait ensuite avec la fonction:
				glBufferData(GLenum target, GLsizeiptr size, const GLvoid* data, GLenum usage)
					- GLenum target: la cible sur laquelle le buffer est bindé (GL_ARRAY_BUFFER dans notre cas)
					- GLsizeiptr size: la taille du tableau en octets. C'est le nombre de flottants multiplié par la taille d'un float (sizeof(float)).
					- const GLvoid* data: le pointeur vers les données, notre tableau de flottants.
					- GLenum usage: un flag indiquant à OpenGL quel usage on va faire du buffer. On utilise GL_STATIC_DRAW pour un buffer dont les données ne changeront jamais.*/
			glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

			
			//================ DEBINDER LE VBO ====================
			/*Après avoir modifié le VBO, on le débind de la cible pour éviter de le remodifier par erreur*/
			glBindBuffer(GL_ARRAY_BUFFER, 0);


			//============ VERTEX ARRAY OBJECT (VAO) ==========
			/*Votre GPU est très fort, mais il ne sait pas interpreter tout seul les données contenu dans le tableau. 
			C'est ce qu'on appelle la spécification de sommet (vertex specification).
			Un VAO décrit pour chaque attribut de sommet (position, couleur, normale, etc.) la manière dont ils sont rangés dans un ou plusieurs VBOs. */ 

			GLuint vao; //on cree le vao de la meme facon que le VBO
		    glGenBuffers(1, &vao);
		    glBindVertexArray(vao); //On bind aussi le vao, mais contrairement au VBO, il est inutile de specifier la cible (il n'y en a qu'une seule)


		    //=========== ACTIVATION DES ATTRIBUTS DE VERTEX ========
		    /* Par défaut, l'attribut position est identifié par 0. Cela peut changer lorsque l'on commence à utiliser des shaders.
		    Afin d'indiquer à OpenGL qu'on utilise un attribut donné, on utilise la fonction :
		    	glEnableVertexAttribArray(GLuint index)
		    		- GLuint index: l'index de l'attribut à activer 
		    L'appel à cette fonction modifie le VAO actuellement bindé, elle enregistre l'information "attribut [index] activé" dans le VAO. 
		    Cela signifie que si vous n'avez pas bindé de VAO, une erreur sera générée par OpenGL. 
		    Si vous avez bindé un mauvais VAO (par la suite on utilisera plusieurs VAOs), alors vous vous exposez à un bug très difficile à trouver et à corriger.*/

		    const GLuint VERTEX_ATTR_POSITION = 0;
			glEnableVertexAttribArray(VERTEX_ATTR_POSITION); // De cette manière on comprend immédiatement que le 0 correspond à l'attribut de sommet identifiant la position.
			//On pourrait faire la meme chose si nous avions d'autre attributs, comme la couleur.


			//========== SPECIFICATION DES ATTRIBUTS DE VERTEX ==========
			/*On doit ensuite indiquer à OpenGL où il va trouver les sommets à dessiner, et comment lire les informations associé à chaque sommet. 
			Pour cela on va utiliser la fonction glVertexAttribPointer. Pour cela on utilise la fonction : 

				glVertexAttribPointer(GLuint index, 
				    GLint size, GLenum type, GLboolean normalized, 
				    GLsizei stride, const GLvoid* pointer); 
				    		- GLuint index: l'index de l'attribut à spécifier
				    		- GLint size: le nombre de composantes de l'attribut. Dans notre cas c'est 2 car chaque position est décrite par deux nombres flottants.
				    		- GLenum type: une constante OpenGL indiquant le type de chaque composante. Dans notre cas on passe GL_FLOAT pour indiquer que chaque composante est un nombre flottant.
				    		- GLboolean normalized: pas besoin de s'occuper de ce paramètre pour le moment, on passe GL_FALSE
				    		- GLsizei stride: indique à OpenGL le nombre d'octets séparant l'attribut pour deux sommets consécutifs. La position suivante peut être situé plus loin dans le tableau lorsqu'on rajoute des attributs de sommet.
				    		- const GLvoid* pointer: un pointeur, ou pas. Ce paramètre est un piège. Il faut en fait passer l'offset (décalage) en octets de la premiere instance de l'attribut dans le tableau. OK, ça ne veut encore rien dire. 
				    		  Dans notre cas, la première position est située au début du tableau, l'offset est donc 0.

			Il faut qu'OpenGL puisse stocker dans le VAO une référence vers le VBO contenant les données. 
			Le VBO contient les données et le VAO décrit les données.*/

			glBindBuffer(GL_ARRAY_BUFFER, vbo); // Il faut rebrancher le VBO pour que le VAO puisse l'utiliser
			glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(GLfloat), 0); //specification du format des attributs de sommet
			glBindBuffer(GL_ARRAY_BUFFER, 0); //pour debrancher le VBO
			glBindVertexArray(0);//pour debrancher le VAO

		     /**********************************/

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        /*Lorsqu'on évenement survient (clic souris, touche clavier, déplacement souris, etc.), la SDL l'enregistre dans une pile appelée pile d'évenement. 
        La methode windowManager.pollEvent(e) permet de dépiler le dernier évenement reçu afin de le traiter dans la boucle. 
        Tant qu'il reste des évenements, la méthode renvoit true et la boucle se relance.*/
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) { //SDL_QUIT, evenement qui est déclenché lorsque l'utilisateur ferme la fenêtre.
                done = true; // Leave the loop after this iteration
            }
        }


        /**********************************/

        //======== NETTOYAGE DE FENETRE ========== 
        /* Le code de dessin est répété à chaque tour de la boucle d'application. Il faut donc d'abord nettoyer la fenêtre afin de ne pas avoir de résidu du tour précédent. Pour cela on utilise la fonction */
        glClear(GL_COLOR_BUFFER_BIT);

		
        //======== DESSIN EN UTILISANT LE VAO =========
		glBindVertexArray(vao); //on rebind le VAO pour pouvoir l'utiliser

		/*On utilise la fonction :
			glDrawArrays(GLenum mode, GLint first, GLsizei count);

		Avec comme parametres :
			- GLenum mode: le type de primitive à dessiner, dans notre cas GL_TRIANGLES
			- GLint first: l'indice du premier sommet dans le VBO. On passe 0.
			- GLsizei count: le nombre de sommets à dessiner, on passe 3 car on veut dessiner un triangle qui est composé de 3 sommets. Si on voulait dessiner plus de triangles il faudrait changer ce paramètre. */
		glDrawArrays(GL_TRIANGLES, 0, 3);


		glBindVertexArray(0);

         
        /**********************************/

        // Update the display
        windowManager.swapBuffers(); //met à jour l'affichage de la fenêtre en pratiquant le double buffering.
    }


    //==============LIBERER LES RESSOURCES ==========
    glDeleteBuffers(1, &vbo); //pour supprimmer le VBO
    glBindVertexArray(vao); // pour supprimer le VAO

    return EXIT_SUCCESS;
}
