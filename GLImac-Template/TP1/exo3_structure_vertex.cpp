//HEADER
#include <glimac/SDLWindowManager.hpp>  
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/glm.hpp> //permet d'utiliser la bibliothèque de maths GLM qui nous permettra d'avoir des types vecteur, matrices et toutes les opérations associées


//NAMESPACES
using namespace glimac;



//================= CLASSE SOMMET COULEUR + SOMMET) ================

class Vertex2DColor // on déclare la classe en lui attribuant et méthodes nécessaires
{

public: // ce n'est pas bon de laisser les attributs en public mais on laisse pour cette fois car OpenGL en aura besoin
	const glm::vec2 _position; // Vecteur à deux coordonnées pour la position
	const glm::vec3 _color; // Vecteur à trois coordonnées pour la couleur

	Vertex2DColor(const glm::vec2 position,glm::vec3 color); //on déclaire le constructeur avec attributs
	Vertex2DColor(); //on déclare le constructeur sans attributs
	~Vertex2DColor(); //on déclare le destructeur	
};

//ON DEFINIT LES CONSTRUCTEURS
Vertex2DColor::Vertex2DColor(const glm::vec2 position, const glm::vec3 color):
_position(position), _color(color)
{
	std::cout << "Construction de l'objet" << std::endl;
}

Vertex2DColor::Vertex2DColor():
_position(glm::vec2(0.0,0.0)), _color(glm::vec3(0.0,0.0,0.0)) 
{

}

//ON DEFINIT LE DESTRUCTEUR
Vertex2DColor::~Vertex2DColor()
{

}



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

			Vertex2DColor vertices[] = { 
			    Vertex2DColor(glm::vec2(-0.5, -0.5), glm::vec3(1, 0, 0)),
			    Vertex2DColor(glm::vec2(0.5, -0.5), glm::vec3(0, 1, 0)),
			    Vertex2DColor(glm::vec2(0, 0.5), glm::vec3(0, 0, 1))
			};


			glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Vertex2DColor), vertices, GL_STATIC_DRAW); //on a change la taille du tableau de 15 GLfloat à 3 Veertex2DColor

			
			//================ DEBINDER LE VBO ====================
			glBindBuffer(GL_ARRAY_BUFFER, 0);


			//============ VERTEX ARRAY OBJECT (VAO) ==========

			GLuint vao; 
		    glGenBuffers(1, &vao);
		    glBindVertexArray(vao); 


		    //=========== ACTIVATION DES ATTRIBUTS DE VERTEX ========

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

			glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), offsetof(Vertex2DColor, _position)); //specification du format des attributs de sommet de position
			glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (const GLvoid*)offsetof(Vertex2DColor, _color)); //specification du format des attributs de sommet de position

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
