#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/Image.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Geometry.hpp>
#include <cstddef>
#include <glm/gtc/random.hpp>
#include <glimac/TrackballCamera.hpp>

using namespace glimac;


struct EarthProgram {
	Program m_Program;

	GLint uMVPMatrix;
	GLint uMVMatrix; //Model View Matrix
	GLint uNormalMatrix; //matrice de transformation des normales
	GLint uEarthTexture; //textureobject pour la Terre
	GLint uCloudTexture; //textureobject pour les nuages
	GLint uTime;

	EarthProgram(const FilePath& applicationPath):
		m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl", applicationPath.dirPath() + "shaders/multiTex3D.fs.glsl")){
			uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
			uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
			uNormalMatrix = glGetUniformLocation(m_Program.getGLId(),"uNormalMatrix");
			uEarthTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture1");
			uCloudTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture2");
			uTime = glGetUniformLocation(m_Program.getGLId(), "uTime");

		}
	
};

struct MoonProgram {
	Program m_Program;

	GLint uMVPMatrix;
	GLint uMVMatrix; //Model View Matrix
	GLint uNormalMatrix; //matrice de transformation des normales
	GLint uTexture; //textureobject pour la  lune

	MoonProgram(const FilePath& applicationPath):
		m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl", applicationPath.dirPath() + "shaders/tex3D.fs.glsl")){
			uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
			uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
			uNormalMatrix = glGetUniformLocation(m_Program.getGLId(),"uNormalMatrix");
			uTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
			
		}
};

// struct ShapeVertex {
//     glm::vec3 position;
//     glm::vec3 normal;
//     glm::vec2 texCoords;

//     ShapeVertex(){}
//     ShapeVertex(glm::vec3 position, glm::vec3 normal, glm::vec2 texCoords):position(position), normal(normal), texCoords(texCoords){}
// };

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");
    glewExperimental = GL_TRUE;

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    Sphere sphere(1, 64, 32);
    unsigned int nbrMoons = 8;

    //Chargement des shaders
    FilePath applicationPath(argv[0]);
    EarthProgram earthProgram(applicationPath);
    MoonProgram moonProgram(applicationPath);

    //Obtention de l'id de la variable uniforme

    

    glEnable(GL_DEPTH_TEST);

    

    //Texture
    std::unique_ptr<Image> EarthMap = loadImage("/home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/assets/textures/EarthMap.jpg");
	std::unique_ptr<Image> MoonMap = loadImage("/home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/assets/textures/MoonMap.jpg");
	std::unique_ptr<Image> CloudMap = loadImage("/home/6im2/mkouyate/Documents/Marco/TP-OpenGL/GLImac-Template/assets/textures/CloudMap.jpg");
        
        if(EarthMap == NULL || MoonMap == NULL || CloudMap == NULL){
            std::cerr << "Une des textures n'a pas pu etre chargée. \n" << std::endl;
            exit(0);
        }

    GLuint earthTexture;
    glGenTextures(1, &earthTexture);

     //Création d'un VBO
    GLuint vbo;
    glGenBuffers(1, &vbo);

    glBindTexture(GL_TEXTURE_2D,earthTexture);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, EarthMap->getWidth() , EarthMap->getHeight(), 0, GL_RGBA, GL_FLOAT, EarthMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D,0);

    GLuint moonTexture;
    glGenTextures(1, &moonTexture);
    glBindTexture(GL_TEXTURE_2D,moonTexture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, MoonMap->getWidth() , MoonMap->getHeight(), 0, GL_RGBA, GL_FLOAT, MoonMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D,0);

    GLuint cloudTexture;
    glGenTextures(1, &cloudTexture);
    glBindTexture(GL_TEXTURE_2D,cloudTexture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, CloudMap->getWidth() , CloudMap->getHeight(), 0, GL_RGBA, GL_FLOAT, CloudMap->getPixels());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D,0);







    //Bindind du vbo sur la cible
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    //Puis on envois les données à la CG
    glBufferData(GL_ARRAY_BUFFER, sphere.getVertexCount()*sizeof(ShapeVertex), sphere.getDataPointer(), GL_STATIC_DRAW);

    //Débindind du vbo de la cible pour éviter de le remodifier
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //Création du VAO
    GLuint vao;
    glGenVertexArrays(1, &vao);

    //Binding du vao (un seul à la fois)
    glBindVertexArray(vao);

    //Dire à OpenGL qu'on utilise le VAO
    const GLuint VERTEX_ATTR_POSITION = 0;
    const GLuint VERTEX_ATTR_NORMAL = 1;
    const GLuint VERTEX_ATTR_TEXCOORDS = 2;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORDS);

    //Indiquer à OpenGL où trouver les sommets
    //Bindind du vbo sur la cible
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    //Spécification du format de l'attribut de sommet position
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, position));
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, normal));
    glVertexAttribPointer(VERTEX_ATTR_TEXCOORDS, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)offsetof(ShapeVertex, texCoords));
    //Débindind du vbo de la cible pour éviter de le remodifier
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    //Débindind du vao de la cible pour éviter de le remodifier
    glBindVertexArray(0);



    //Aléatoire pour les lunes
    std::vector <glm::vec3> moonAxes;
    std::vector <glm::vec3> moonTranslations;

    for (unsigned int i = 0; i < nbrMoons; i++){
     moonAxes.push_back(glm::sphericalRand(1.0f));
     moonTranslations.push_back(glm::sphericalRand(2.0f));
    }


    TrackballCamera Camera;

    //Matrice de projection
    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/600.f, 0.1f, 100.f);



        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }


        glm::mat4 ViewMatrix = Camera.getViewMatrix();

        //Ici on récupère les positions de la souris
        glm::ivec2 mousePos = windowManager.getMousePosition();
	        if(windowManager.isMouseButtonPressed(SDL_BUTTON_RIGHT)) Camera.moveFront(0.01);
	        else if(windowManager.isMouseButtonPressed(SDL_BUTTON_LEFT)) Camera.moveFront(-0.01);

        Camera.rotateLeft( mousePos.y );
        Camera.rotateUp( mousePos.x );

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(vao);

        earthProgram.m_Program.use();
        glUniform1i(earthProgram.uEarthTexture,0);
        glUniform1i(earthProgram.uCloudTexture,1);


	    
	    glm::mat4 earthMVMatrix = glm::rotate(ViewMatrix, windowManager.getTime(), glm::vec3(0,1,0));
	    


        glUniformMatrix4fv(earthProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(earthMVMatrix));
        glUniformMatrix4fv(earthProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(earthMVMatrix))));
        glUniformMatrix4fv(earthProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * ViewMatrix));
        

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,earthTexture);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D,cloudTexture);

        glUniform1f(earthProgram.uTime,windowManager.getTime()/50.0);
        
        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount()); //Dessin de la terre

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,moonTexture);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D,0);


        moonProgram.m_Program.use();

        for (unsigned int i = 0; i < nbrMoons; i++){
			glm::mat4 moonMVMatrix = glm::rotate(ViewMatrix, windowManager.getTime(), moonAxes.at(i)); // Translation * Rotation
			moonMVMatrix = glm::translate(moonMVMatrix, moonTranslations.at(i)); // Translation * Rotation * Translation
			moonMVMatrix = glm::scale(moonMVMatrix, glm::vec3(0.2, 0.2, 0.2)); // Translation * Rotation * Translation * Scale

            glUniformMatrix4fv(moonProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(moonMVMatrix));
            glUniformMatrix4fv(moonProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(moonMVMatrix))));
            glUniformMatrix4fv(moonProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * moonMVMatrix));
            glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount());
        }
       
       

        // Update the display
        windowManager.swapBuffers();
    }
    glDeleteBuffers(1,&vbo);
    glDeleteVertexArrays(1,&vao); 
    glDeleteTextures(1,&earthTexture);

    return EXIT_SUCCESS;
}