//HEADER
#include <glimac/SDLWindowManager.hpp>  //La classe SDLWindowManager se charge de gérer ce qui concerne la SDL: ouverture de fenêtre, récupération d'évenements clavier-souris
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>


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

    SDLWindowManager windowManager(800, 600, "GLImac");

    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

	
    //============= CHARGEMENT DES SHADERS ===================
    /*Ce code à pour effet de charger les shaders, les compiler (à l'execution de l'application) et d'indiquer à OpenGL de les utiliser.*/
	FilePath applicationPath(argv[0]);
	Program program = loadProgram(applicationPath.dirPath() + "shaders/triangle.vs.glsl",
	                              applicationPath.dirPath() + "shaders/triangle.fs.glsl");
	program.use();    




		    //=============== VERTEX BUFFER OBJECT (VBO) =====================

		    GLuint vbo; 
		    glGenBuffers(1, &vbo); 
		    

		    //================== BINDING DU VBO =======================
		    glBindBuffer(GL_ARRAY_BUFFER, vbo);  

			
		    //================= REMPLIR LE VBO ========================
			//Il faut commencer par creer un tableau de GLfloat contenant toutes ces coordonnées à la suite. Les couleurs sont gérés en OpenGL par des nombres flottants entre 0 et 1

			GLfloat vertices[] = { 
				-0.5f, -0.5f, 1.f,0.f,0.f, //premier sommet (rouge)
				 0.5f, -0.5f, 0.f,1.f,0.f, //deuxieme sommet (vert)
				 0.0f,  0.5f, 0.f,0.f,1.f  //troisieme sommet (bleu)
				};


			glBufferData(GL_ARRAY_BUFFER, 15 * sizeof(GLfloat), vertices, GL_STATIC_DRAW); //on a change la taille du tableau de 6 à 15

			
			//================ DEBINDER LE VBO ====================
			glBindBuffer(GL_ARRAY_BUFFER, 0);


			//============ VERTEX ARRAY OBJECT (VAO) ==========

			GLuint vao; 
		    glGenBuffers(1, &vao);
		    glBindVertexArray(vao); 


		    //=========== ACTIVATION DES ATTRIBUTS DE VERTEX ========
		    /* chaque attribut est identifié par un index. Sans shader il est 0 par défaut, mais puisque nous utilisons des shaders il a change. 
		    Pour connaitre l'index associé à chaque attribut, ouvrez le fichier triangle.vs.glsl*/

		    const GLuint VERTEX_ATTR_POSITION = 3;
			glEnableVertexAttribArray(VERTEX_ATTR_POSITION);

			const GLuint VERTEX_ATTR_COLOR = 8;
			glEnableVertexAttribArray(VERTEX_ATTR_COLOR);


			//========== SPECIFICATION DES ATTRIBUTS DE VERTEX ==========
			/*
				glVertexAttribPointer(GLuint index, 
				    GLint size, GLenum type, GLboolean normalized, 
				    GLsizei stride, const GLvoid* pointer); 

						- GLuint index: l'index de l'attribut à spécifier
						- GLint size: le nombre de composantes de l'attribut.
						- GLenum type: une constante OpenGL indiquant le type de chaque composante. Dans notre cas on passe GL_FLOAT pour indiquer que chaque composante est un nombre flottant.
						- GLboolean normalized: pas besoin de s'occuper de ce paramètre pour le moment, on passe GL_FALSE
						- GLsizei stride: indique à OpenGL le nombre d'octets séparant l'attribut pour deux sommets consécutifs.
						- const GLvoid* pointer: un pointeur, ou pas. Ce paramètre est un piège. Il faut en fait passer l'offset (décalage) en octets de la premiere instance de l'attribut dans le tableau.*/

			glBindBuffer(GL_ARRAY_BUFFER, vbo); 

			glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), 0); //specification du format des attributs de sommet de position
			glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (const GLvoid*)(2*sizeof(GL_FLOAT))); //specification du format des attributs de sommet de position

			glBindBuffer(GL_ARRAY_BUFFER, 0); 
			glBindVertexArray(0);

		     /**********************************/

    // Application loop:
    bool done = false;
    while(!done) {

        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) { 
                done = true; 
            }
        }


        /**********************************/

        //======== NETTOYAGE DE FENETRE ========== 
 
        glClear(GL_COLOR_BUFFER_BIT);

		
        //======== DESSIN EN UTILISANT LE VAO =========
		glBindVertexArray(vao); 

		glDrawArrays(GL_TRIANGLES, 0, 3);


		glBindVertexArray(0);

         
        /**********************************/

        // Update the display
        windowManager.swapBuffers(); 

    }
    //==============LIBERER LES RESSOURCES ==========
    glDeleteBuffers(1, &vbo); 
    glBindVertexArray(vao); 

    return EXIT_SUCCESS;
}
