#include "ClothSystem.h"

// TODO: Initialize here
// This constructor initializes springs based on the grid size
ClothSystem::ClothSystem(int gridSize) : PendulumSystem(gridSize), gridSize(gridSize)
{
	// We create structural springs between adjacent particles
    // For example, if gridSize is 3, we have a 3x3 grid with 9 particles.
    // The indices of particles will be:
    // 0 1 2
    // 3 4 5
    // 6 7 8
    // We create structural springs between particles like (0,1), (1,2), (0,3), (3,6), etc.

	// Nested for loop to loop through each row and column in the cloth (since the cloth is of
	// size gridSize X gridSize)
	for(int i = 0; i < gridSize; i++) {
		for(int j = 0; j < gridSize; j++) {
			// Setting up the structural springs
			if (i < gridSize - 1) {
                std::vector<int> temp;
                temp.push_back(indexOf(i, j));
                temp.push_back(indexOf(i + 1, j));
                structuralSprings.push_back(temp);
            }
            if (j < gridSize - 1) {
                std::vector<int> temp;
                temp.push_back(indexOf(i, j));
                temp.push_back(indexOf(i, j + 1));
                structuralSprings.push_back(temp);
            }

			// Also need to set up the shear and flex springs
		}
 	}

}


// TODO: implement evalF
// for a given state, evaluate f(X,t)
vector<Vector3f> ClothSystem::evalF(vector<Vector3f> state)
{
	// Call the parent's evalF function to compute the pendulum forces
	std::vector<Vector3f> f = PendulumSystem::evalF(state);

	// Then, compute additional forces for the cloth 
    computeStructuralForces(f, state);
    computeShearForces(f, state);
    computeFlexForces(f, state);
    return f;
}

void ClothSystem::computeStructuralForces(std::vector<Vector3f>& f, const std::vector<Vector3f>& state) {
    // Compute structural forces here
    // ...
}

void ClothSystem::computeShearForces(std::vector<Vector3f>& f, const std::vector<Vector3f>& state) {
    // Compute shear forces here
    // ...
}

void ClothSystem::computeFlexForces(std::vector<Vector3f>& f, const std::vector<Vector3f>& state) {
    // Compute flex forces here
    // ...
}


//TODO: render the system (ie draw the particles)
void ClothSystem::draw()
{
    // Draw particles
    glColor3f(0.5f, 0.5f, 0.9f); // Set particle color
    glPointSize(5.0f); // Set point size
    
    glBegin(GL_POINTS);
    for (size_t i = 0; i < m_vVecState.size(); ++i)
    {
        const Vector3f& particle = m_vVecState[i];
        glVertex3f(particle.x(), particle.y(), particle.z());
    }
    glEnd();
    
    // Draw structural springs
    glColor3f(0.9f, 0.5f, 0.5f); // Set spring color
    glLineWidth(2.0f); // Set line width
    
    glBegin(GL_LINES);
    for (size_t i = 0; i < structuralSprings.size(); ++i)
    {
        std::vector<int>& spring = structuralSprings[i];
        
        Vector3f pos1 = m_vVecState[spring[0]];
        Vector3f pos2 = m_vVecState[spring[1]];
        
        glVertex3f(pos1.x(), pos1.y(), pos1.z());
        glVertex3f(pos2.x(), pos2.y(), pos2.z());
    }
    glEnd();
}
// Helper function that gets the index
int ClothSystem::indexOf(int i, int j) {
    return i * gridSize + j;
}

