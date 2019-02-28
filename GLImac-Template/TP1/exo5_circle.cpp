//HEADER
#include <glimac/SDLWindowManager.hpp>  
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/glm.hpp> 
#include <vector>

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


Vertex2DColor::Vertex2DColor(const glm::vec2 position, const glm::vec3 color):
_position(position), _color(color)
{
	
}

Vertex2DColor::Vertex2DColor():
_position(glm::vec2(0.0,0.0)), _color(glm::vec3(0.0,0.0,0.0)) 
{

}

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

			float N = 50.0f; //On indique le nombre de triangles
			std::vector<Vertex2DColor> vertices; //tableau de vextex à taille variable


			     for(int i=0;i<N;++i){ 
			        vertices.push_back( //on détermine le premier sommet du triangle, qui est toujours au centre
			            Vertex2DColor(glm::vec2(0, 0), glm::vec3(0, 0, 0.5))
			        );
			        vertices.push_back( //on détermine le second sommet du triangle, à l'aide du cosinus et du sinus de 2 * pi, cela divisé par N puis multiplié par i. C'est un peu comme si on cherchait le point du cercle pour une portion puis qu'on le multiplie par le triangle.
			            Vertex2DColor(glm::vec2(0.5*glm::cos(((2*glm::pi<float>())/N)*i), 0.5*glm::sin(((2*glm::pi<float>())/N)*i)) , glm::vec3(1, 1, 1)
			        ));
			        vertices.push_back( //m^me chose que plus haut, mais cette fois on ajoute 1 à i pour que le sommet aille se ranger sur le premier sommet du traingle suivant. 
			            Vertex2DColor(glm::vec2(0.5*glm::cos(((2*glm::pi<float>())/N)*(i+1)), 0.5*glm::sin(((2*glm::pi<float>())/N)*(i+1))), glm::vec3(1, 1, 1)
			        ));
			    }


			    //Puis on envois les données à la CG //3*N pour le nombre de sommets pour un triangle, puis multiplie par N pour le nombre de triangles
			    glBufferData(GL_ARRAY_BUFFER, 3*N*sizeof(Vertex2DColor), vertices.data(), GL_STATIC_DRAW);

			    //Débindind du vbo de la cible pour éviter de le remodifier
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


		std::cout << N << std::endl;
		glDrawArrays(GL_TRIANGLES, 0, N*3);
		std::cout << "Test" << std::endl;



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
