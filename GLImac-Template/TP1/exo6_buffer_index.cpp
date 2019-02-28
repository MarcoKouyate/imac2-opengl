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

			int N = 50; //On indique le nombre de triangles
			std::vector<Vertex2DColor> vertices; // => Tableau de sommets : un seul exemplaire de chaque sommet



			     for(int i=0;i<N+1;++i){ 
			        vertices.push_back( //Voilà une fonction qui détermine tous les autres points autour du cercle
			            Vertex2DColor(glm::vec2(0.5*glm::cos(((2*glm::pi<float>())/N)*i), 0.5*glm::sin(((2*glm::pi<float>())/N)*i)) , glm::vec3(1, 1, 0)) 
			            );
			    }


			     // => Penser à bien changer le nombre de sommet (pour correspondre au nombre de points utilisés, soit tous les points du triangle plus l'origine)
			    glBufferData(GL_ARRAY_BUFFER, (N+1)*sizeof(Vertex2DColor), vertices.data(), GL_STATIC_DRAW);

			    //Débindind du vbo de la cible pour éviter de le remodifier
			    glBindBuffer(GL_ARRAY_BUFFER, 0);

			        // => Creation du IBO
		    
			

			//============ INDEX BUFFER OBJECT (IB0)==========
			  /*Ce tableau va nous servir à stocker les index des sommets que nous voulons dessiner dans l'ordre que nous voulons dessiner*/
		    GLuint ibo;
		    glGenBuffers(1, &ibo); 

		    
		    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo); // => On bind sur GL_ELEMENT_ARRAY_BUFFER, cible reservée pour les IBOs

		        // => Tableau d'indices: ce sont les indices des sommets à dessiner
			    // Chaque indice correspond au sommet correspondant dans le VBO
			    uint32_t indices[N*3];

			   



			   
			    // C'EST ICI QUE CA SE REPARE
			    size_t a = 0;

			    for(int i=0;i<N;i++){ 
			    	indices[a]= 0;
			    	std::cout << indices[a] << std::endl;
			    	a++;
			    	indices[a]= i+1;
			    	std::cout << indices[a] << std::endl;
			    	a++;
			    	indices[a]= i+2;
			    	std::cout << indices[a] << std::endl;
			    	a++;
			    }

			    // => On remplit l'IBO avec les indices:
			    glBufferData(GL_ELEMENT_ARRAY_BUFFER, N*3* sizeof(uint32_t), indices, GL_STATIC_DRAW);

			    // => Comme d'habitude on debind avant de passer à autre chose
			    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);




			//============ VERTEX ARRAY OBJECT (VAO) ==========

			GLuint vao; 
		    glGenBuffers(1, &vao);
		    glBindVertexArray(vao); 

		    // => On bind l'IBO sur GL_ELEMENT_ARRAY_BUFFER; puisqu'un VAO est actuellement bindé,
		    // cela a pour effet d'enregistrer l'IBO dans le VAO
		    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);


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


		// => On utilise glDrawElements à la place de glDrawArrays
        // Cela indique à OpenGL qu'il doit utiliser l'IBO enregistré dans le VAO
        glDrawElements(GL_TRIANGLES, 3 * N, GL_UNSIGNED_INT, 0);
			/*GLenum mode: le type de primitives à dessiner (GL_TRIANGLES)
			GLsizei count: le nombre d'indice à dessiner (nombre de triangles * 3)
			GLenum type: une constante OpenGL correspondant au type des indices (GL_UNSIGNED_INT). 
				Lorsqu'on utilise peu d'indices, il peut être plus efficace d'utiliser des indices de type unsigned short ou unsigned char afin de consommer encore moins de mémoire.
			const GLvoid * indices: encore un pointeur "piège". C'est en fait l'offset dans le tableau d'indices à partir duquel commencer. On passe 0 car on veut utiliser tous les indices.*/





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
