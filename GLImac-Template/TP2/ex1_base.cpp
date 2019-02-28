//HEADER
#include <glimac/SDLWindowManager.hpp>  
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/glm.hpp> 


//NAMESPACES
using namespace glimac;



//================= CLASSE SOMMET COULEUR + SOMMET) ================

class Vertex2DColor 
{

public: 
	const glm::vec2 _position; 
	const glm::vec3 _color; 

	Vertex2DColor(const glm::vec2 position,glm::vec3 color); 
	Vertex2DColor();
	~Vertex2DColor(); 
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
	Program program = loadProgram(applicationPath.dirPath() + "shaders/color2D.vs.glsl",
	                              applicationPath.dirPath() + "shaders/color2D.fs.glsl");
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


			glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Vertex2DColor), vertices, GL_STATIC_DRAW); 

			
			//================ DEBINDER LE VBO ====================
			glBindBuffer(GL_ARRAY_BUFFER, 0);


			//============ VERTEX ARRAY OBJECT (VAO) ==========

			GLuint vao; 
		    glGenBuffers(1, &vao);
		    glBindVertexArray(vao); 


		    //=========== ACTIVATION DES ATTRIBUTS DE VERTEX ========

		    const GLuint VERTEX_ATTR_POSITION = 0;
			glEnableVertexAttribArray(VERTEX_ATTR_POSITION);

			const GLuint VERTEX_ATTR_COLOR = 1;
			glEnableVertexAttribArray(VERTEX_ATTR_COLOR);


			//========== SPECIFICATION DES ATTRIBUTS DE VERTEX ==========
			
			glBindBuffer(GL_ARRAY_BUFFER, vbo); 

			glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), offsetof(Vertex2DColor, _position)); 
			glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (const GLvoid*)offsetof(Vertex2DColor, _color)); 

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
