
#include "pendulumSystem.h"

#include <iostream>
using namespace std;

const double gravity_const = -9.8;

const double drag_const = 2;

const double spring_const = 10;

const double mass = .2;

const double rest_len = .5;


// gravity force - 𝐅(𝐱_𝑖 , 𝐱′_𝑖 , 𝑚_𝑖 ) = 𝑚_𝑖 * 𝐠
Vector3f gravity = Vector3f(0, mass * gravity_const, 0);





PendulumSystem::PendulumSystem(int numParticles):ParticleSystem(numParticles)
{
	m_numParticles = numParticles;

	// first particle position is 1,0,0
	int x = 1;
	int y = 0;
	int z = 0;
	
	// initialize particle positions and velocities
	for (int i = 0; i < m_numParticles; i++) {
		
		Vector3f particle = Vector3f(x, y, z);

		Vector3f p_velocity = Vector3f::ZERO;

		// m_vVecState.size() will be 2 * m_numParticles
		// position will be at even indices
		m_vVecState.push_back(particle);

		// velocity at odd indices
		m_vVecState.push_back(p_velocity);

		// change x,y coordinates
		x++;

		y++;
	}
}



// TODO: implement evalF
// for a given state, evaluate f(X,t)
vector<Vector3f> PendulumSystem::evalF(vector<Vector3f> state)
{
	// state derivative vector f
	vector<Vector3f> f;

	// first particle is origin
	Vector3f particle1 = Vector3f::ZERO;

	Vector3f particle2;

	// vector of springs
	vector<Vector3f> springs;

	// loop through all velocities in state, which are at odd indices
	// calculate net force
	for(int i = 0; i < m_numParticles; i++)
	{
		Vector3f velocity = state[2 * i + 1];

		// v_i are now at even indices of f
		f.push_back(velocity);

		Vector3f viscous_drag = -drag_const * velocity;

		Vector3f net_force = viscous_drag + gravity;

		// F(x, v) now at odd indices of f
		f.push_back(net_force);
	}

	// calculate spring forces
	for(int i = 0; i < m_numParticles; i++)
	{
		particle2 = state[2 * i];

		// spring force
		// 𝐅(𝐱_𝑖 , 𝐱′_𝑖 , 𝑚_𝑖 ) = -k(||d|| - r) * d / ||d||
		Vector3f d = particle1 - particle2;

		Vector3f spring_force = -spring_const * (d.abs() - rest_len) * 
		(d / d.abs());

		springs.push_back(spring_force);

		particle1 = particle2;
	}

	// simple pendulum, just subtract force of spring from particle
	if(m_numParticles < 2)
	{
		f[1] -= springs[0];
	}

	// if more than one particle
	else
	{
		// for first n - 1 particles
		// subtract force of spring i from particle i
		// add force of spring i + 1
		for(int i = 0; i < m_numParticles; i++)
		{
			f[2 * i + 1] -= springs[i];

			if(i < m_numParticles - 1)
				f[2 * i + 1] += (springs[i + 1]*2);
		}
	}

	return f;
}



// render the system (ie draw the particles)
void PendulumSystem::draw()
{

	Vector3f prevParticle = Vector3f(0,0,0);

	for (int i = 0; i < m_numParticles; i++) {
		//  position of particle i. 
		Vector3f pos = Vector3f(m_vVecState[2*i].x(), m_vVecState[2*i].y(), m_vVecState[2*i].z());

		glLineWidth(3);

		glPushMatrix();

		glTranslatef(pos[0], pos[1], pos[2] );

		glutSolidSphere(0.075f,10.0f,10.0f);

		glPopMatrix();

		// polyline between each particle
		glBegin(GL_LINES);

		glVertex3f(prevParticle.x(), prevParticle.y(), prevParticle.z());

		glVertex3f(pos[0], pos[1], pos[2]);

		glEnd();

		prevParticle = pos;

	}

}
