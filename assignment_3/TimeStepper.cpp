#include "TimeStepper.hpp"
#include <iostream>
#include <string>

using namespace std;


// helper function, prints the state
void  printState(string name, vector<Vector3f> state)
{
	cout << name << endl;

	for(long unsigned int i = 0; i < state.size(); i++)
		state[i].print();
}




//Explicit Euler time integrator
void ForwardEuler::takeStep(ParticleSystem* particleSystem, float stepSize)
{
	//X(t + h) = X + hf (X, t)
	vector<Vector3f> X = particleSystem->getState();

	vector<Vector3f> f = particleSystem->evalF(X);

	vector<Vector3f> X1;

	for(int i = 0; i < 2 * particleSystem->m_numParticles; i++)
	{
		X1.push_back(X[i] + stepSize * f[i]);
	}

	particleSystem->setState(X1);
}




//Trapzoidal rule integrator
void Trapzoidal::takeStep(ParticleSystem* particleSystem, float stepSize)
{
	int size = 2 * particleSystem->m_numParticles;

	vector<Vector3f> X = particleSystem->getState();

	// f0 = f (X, t)
	vector<Vector3f> f0 = particleSystem->evalF(X);

	vector<Vector3f> X1;

	// X + hf0
	for(int i = 0; i < size; i++)
		X1.push_back(X[i] + stepSize * f0[i]);

	// f1 = f (X + hf0, t + h)
	vector<Vector3f> f1 = particleSystem->evalF(X1);

	vector<Vector3f> X2;

	// X(t + h) = X + ℎ/2 (f0 + f1)
	for(int i = 0; i < size; i++)
		X2.push_back(X[i] + (stepSize / 2) * (f0[i] + f1[i]));

	particleSystem->setState(X2);

}




// RK4 is given to you
void RK4::takeStep(ParticleSystem* particleSystem, float stepSize)
{	
	vector<Vector3f> X1 = particleSystem->getState();

	vector<Vector3f> f1 = particleSystem->evalF(X1);

	if (f1.size() >= 1) {		
		vector<Vector3f> X2;
		for (int i = 0; i < 2 * particleSystem->m_numParticles; i++)
		{
			X2.push_back(X1[i] + (stepSize * f1[i] / 2.0));
		}	

		vector<Vector3f> f2 = particleSystem->evalF(X2);	

		vector<Vector3f> X3;
		for (int i = 0; i < 2 * particleSystem->m_numParticles; i++)
		{
			X3.push_back(X1[i] + (stepSize * f2[i] / 2.0));
		}	

		vector<Vector3f> f3 = particleSystem->evalF(X3);

		vector<Vector3f> X4;
		for (int i = 0; i < 2 * particleSystem->m_numParticles; i++)
		{
			X4.push_back(X1[i] + (stepSize * f3[i]));
		}	

		vector<Vector3f> f4 = particleSystem->evalF(X4);

		for (int i = 0; i < 2 * particleSystem->m_numParticles; i++)
		{
			X1[i] = X1[i] + stepSize * ((f1[i] + f2[i] * 2 + f3[i] * 2 + f4[i]) / 6);
		}

	}
	particleSystem->setState(X1);
}


