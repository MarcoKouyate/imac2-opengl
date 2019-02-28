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

using namespace glimac;

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
    Program program = loadProgram(
        applicationPath.dirPath() + "shaders/3D.vs.glsl",
        applicationPath.dirPath() + "shaders/multiTex3D.fs.glsl"
    );
    program.use();

    //Obtention de l'id de la variable uniforme
    GLint uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");
    GLint uTextureLoc1 = glGetUniformLocation(program.getGLId(), "uTexture1");
    GLint uTextureLoc2 = glGetUniformLocation(program.getGLId(), "uTexture2");
    GLint uTime = glGetUniformLocation(program.getGLId(), "uTime");

    glEnable(GL_DEPTH_TEST);

    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 800.f/600.f, 0.1f, 100.f);
    glm::mat4 MVMatrix = glm::translate(glm::mat4(1), glm::vec3(0, 0, -5));
    //MVMatrix = glm::rotate(MVMatrix, windowManager.getTime(), glm::vec3(0,1,0));
    glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));


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

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glBindVertexArray(vao);

        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix));
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix));

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,earthTexture);
        glUniform1i(uTextureLoc1,0);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D,cloudTexture);
        glUniform1i(uTextureLoc2,1);
        glUniform1f(uTime,windowManager.getTime()/50.0);
        
        glDrawArrays(GL_TRIANGLES, 0, sphere.getVertexCount()); //Dessin de la terre

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D,moonTexture);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D,0);


        for (unsigned int i = 0; i < nbrMoons; i++){
            glm::mat4 MVMatrix2 = MVMatrix;
            glm::mat4 NormalMatrix2 = NormalMatrix;
			MVMatrix2 = glm::rotate(MVMatrix2, windowManager.getTime(), moonAxes.at(i)); // Translation * Rotation
			MVMatrix2 = glm::translate(MVMatrix2, moonTranslations.at(i)); // Translation * Rotation * Translation
			MVMatrix2 = glm::scale(MVMatrix2, glm::vec3(0.2, 0.2, 0.2)); // Translation * Rotation * Translation * Scale
            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * MVMatrix2));
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(MVMatrix2));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(NormalMatrix2));
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