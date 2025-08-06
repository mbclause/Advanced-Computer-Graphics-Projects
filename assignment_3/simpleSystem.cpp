
#include "simpleSystem.h"

#include <iostream>

using namespace std;


// set initial position for particle, set num particles to 1
SimpleSystem::SimpleSystem()
{
	Vector3f origin = Vector3f(1, 0, 0);

	m_vVecState.push_back(origin);

	m_numParticles = 1;
}



// calculate derivative
vector<Vector3f> SimpleSystem::evalF(vector<Vector3f> state)
{
	vector<Vector3f> f;

	for(long unsigned int i = 0; i < state.size(); i++)
	{
		//f(x, t) = [-y, x, 0]
		Vector3f vec = Vector3f(-state[i].y(), state[i].x(), 0);

		f.push_back(vec);
	}
	
	return f;
}

// render the system (ie draw the particles)
void SimpleSystem::draw()
{
		// particle position
		Vector3f pos = Vector3f(m_vVecState[0].x(), m_vVecState[0].y(), m_vVecState[0].z());
	  glPushMatrix();
		glTranslatef(pos[0], pos[1], pos[2] );
		glutSolidSphere(0.075f,10.0f,10.0f);
		glPopMatrix();
}
