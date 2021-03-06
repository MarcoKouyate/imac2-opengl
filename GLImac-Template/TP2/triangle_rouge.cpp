#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/Program.hpp>
#include <glimac/glm.hpp> 

using namespace glimac;

// ====== CLASSE DE SOMMET ======
class Vertex2DUV {
    public :
        glm::vec2 _position;
        glm::vec2 _coordTex;


        Vertex2DUV(const glm::vec2 position,const glm::vec2 coordTex);
        Vertex2DUV(const glm::vec2 position);
        Vertex2DUV();
        ~Vertex2DUV();
};

Vertex2DUV::Vertex2DUV(const glm::vec2 position, const glm::vec2 coordTex)  : 
_position(position), _coordTex(coordTex) {

}

Vertex2DUV::Vertex2DUV(const glm::vec2 position)  : 
_position(position), _coordTex(0.0f,0.0f) {

}

Vertex2DUV::Vertex2DUV() : 
_position(glm::vec2(0.0f,0.0f)), _coordTex(0.0f,0.0f) {

}

Vertex2DUV::~Vertex2DUV(){

}





int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    //==== CHARGEMENT DES SHADERS =====
    FilePath applicationPath(argv[0]);
    Program program = loadProgram (applicationPath.dirPath()+"shaders/"+argv[1], applicationPath.dirPath()+"shaders/"+argv[2]);
    program.use();



        //========== VBO ==========
        GLuint vbo;
        glGenBuffers(1,&vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        //====== REMPLIR LE VBO ====
        Vertex2DUV vertices[] = { Vertex2DUV(glm::vec2(0.0f,1.0f)), Vertex2DUV(glm::vec2(-1.0f,-1.0f)), Vertex2DUV(glm::vec2(1.0f,-1.0f)) };

        glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Vertex2DUV), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER,0);

        //===== INDEX BUFFER OBJECT ======
        GLuint ibo;
        glGenBuffers(1, &ibo);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

        uint32_t indices[] = {
            0, 1, 2
        };

        glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(uint32_t), indices,GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);


        //===== VAO =====
        GLuint vao;
        glGenBuffers(1,&vao);
        glBindVertexArray(vao);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

        const GLuint VERTEX_ATTR_POSITION = 0;
        glEnableVertexAttribArray(VERTEX_ATTR_POSITION);

        //===== SPECIFICATION DES ATTRIBUTS =====
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV), (const GLvoid *)offsetof(Vertex2DUV,_position));

        glBindBuffer(GL_ARRAY_BUFFER,0);
        glBindVertexArray(0);




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

         glClear(GL_COLOR_BUFFER_BIT);

         glBindVertexArray(vao);

         glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

         glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteBuffers(1,&vbo);
    glDeleteVertexArrays(1,&vao); 

    return EXIT_SUCCESS;
}
