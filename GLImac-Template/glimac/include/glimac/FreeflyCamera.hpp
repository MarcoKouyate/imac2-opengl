#pragma once

#include <cstdint>
#include <SDL/SDL.h>
#include "glm.hpp"

namespace glimac {

	class FreeflyCamera {

		public:
			FreeflyCamera(); //constructeur
			~FreeflyCamera(); //destructeur

			void computeDirectionVectors(); //calcule Front, Left et Up

			void moveLeft(float t); 
			void moveFront(float t); 
			void rotateLeft(float degrees);
			void rotateUp(float degrees);

			glm::mat4 getViewMatrix() const; 


		private:
			//position de la caméra
			glm::vec3 m_Position; //Position de la camera
			
			//coordonnées sphériques du vecteur avant
			float m_fPhi;  
			float m_fTheta;

			//vecteurs;
			glm::vec3 m_FrontVector; 
			glm::vec3 m_LeftVector;
			glm::vec3 m_UpVector;
			

	};
}