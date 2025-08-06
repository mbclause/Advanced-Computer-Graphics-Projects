#ifndef CLOTHSYSTEM_H
#define CLOTHSYSTEM_H

#include <vecmath.h>
#include <vector>

#include "particleSystem.h"
#include "pendulumSystem.h"

class ClothSystem: public PendulumSystem
{
///ADD MORE FUNCTION AND FIELDS HERE
public:
	// This is the constructor
	ClothSystem(int gridSize);
	// This is the evalF function that we need to implement for 
	// the cloth system as well
	vector<Vector3f> evalF(vector<Vector3f> state);
	// Also override the draw method for the cloth
	void draw();

private:
	// This the size of the grid we will create
	int gridSize;
	// These are the vectors to hold each type of string
	std::vector<std::vector<int> > structuralSprings;
    std::vector<std::vector<int> > shearSprings;
    std::vector<std::vector<int> > flexSprings;

	// Member functions that calculate the forces for each type of spring
	void computeStructuralForces(std::vector<Vector3f>& f, const std::vector<Vector3f>& state);
    void computeShearForces(std::vector<Vector3f>& f, const std::vector<Vector3f>& state);
    void computeFlexForces(std::vector<Vector3f>& f, const std::vector<Vector3f>& state);
	// given index i, j into a n × n cloth, this helper method returns the linear index into 
	// our vector of particles
	int indexOf(int i, int j);

};


#endif
