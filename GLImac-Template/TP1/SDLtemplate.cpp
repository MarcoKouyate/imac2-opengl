#include <glimac/SDLWindowManager.hpp>  //La classe SDLWindowManager se charge de gérer ce qui concerne la SDL: ouverture de fenêtre, récupération d'évenements clavier-souris
#include <GL/glew.h>
#include <iostream>

using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window - va ouvrir une fenêtre de résolution 800x600 dont le titre est "GLImac". La variable windowManager sera utilisée par la suite pour gérer les évenements.
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support - initialise la bibliothèque GLEW. Cette bibliothèque charge l'ensemble des fonctions OpenGL3. Sans elle on peut considerer que l'on a accès qu'aux fonctions OpenGL2.
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    //On affiche ensuite des informations sur OpenGL afin de vérifier que l'on a la bonne version:
    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

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


        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        // Update the display
        windowManager.swapBuffers(); //met à jour l'affichage de la fenêtre en pratiquant le double buffering.
    }

    return EXIT_SUCCESS;
}
