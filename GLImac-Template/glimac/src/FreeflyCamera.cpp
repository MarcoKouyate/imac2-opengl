#include "glimac/FreeflyCamera.hpp"
#include <iostream>
#include <math.h>

namespace glimac {

    //Constructeurs
    FreeflyCamera::FreeflyCamera() : m_Position(glm::vec3(0.0f)), m_fPhi(M_PI), m_fTheta(0.0) {
        computeDirectionVectors();
    }

    //Destructeur
    FreeflyCamera::~FreeflyCamera() {
    }

    void FreeflyCamera::computeDirectionVectors(){
    
        //F⃗ =(cos(θ)sin(ϕ), sin(θ), cos(θ)cos(ϕ))
        m_FrontVector = glm::vec3(cos(m_fTheta)*sin(m_fPhi), sin(m_fTheta),cos(m_fTheta)*cos(m_fPhi));
        
        //L⃗ =(sin(ϕ+π2), 0, cos(ϕ+π2))
        m_LeftVector = glm::vec3(sin(m_fPhi+(M_PI/2.0)), 0, cos(m_fPhi+(M_PI/2.0))); 

        //U⃗ =F⃗ ×L⃗ 
        m_UpVector = glm::cross(m_FrontVector, m_LeftVector);

    }

    void FreeflyCamera::moveLeft(float t){
        //P += t*V
        m_Position += t* m_LeftVector;
        computeDirectionVectors();
    }

    void FreeflyCamera::moveFront(float t){
        //P += t*V
        m_Position += t* m_FrontVector;
        computeDirectionVectors();
    }

    void FreeflyCamera::rotateLeft(float degrees){
        m_fPhi += glm::radians(degrees);
        computeDirectionVectors();
        std::cout << "Wild" <<std::endl;
    }

    void FreeflyCamera::rotateUp(float degrees){
        m_fTheta += glm::radians(degrees);
        computeDirectionVectors();
    }



    glm::mat4 FreeflyCamera::getViewMatrix() const{

        glm::mat4 ViewMatrix = glm::lookAt(m_Position,m_Position+m_FrontVector,m_UpVector);

        return ViewMatrix;
    }

}