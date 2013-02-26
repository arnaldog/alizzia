Particle Swarm Optimization Algorithm

This project is based on Motion-Planning PSO algoritm Project.

The goal for this project is to be embeed in PostgreSQL/PostGIS 
database functions for complex representations and problems 
like scheduling problems, round robin or travelling salesman Problem.

ForwardChecking (FC)
ForwardChecking with Backjumping (FCBJ)
ForwardChecking with Gobal Backjumping (FCGB)

Backtracking (BT)
Backtracking with backjumping (BTBJ)
Backtracking with global back jumping (BTGB)

Hill Climbing (HC)
Hill Climbing with Restart (HC)

Tabu Search (TS)

Simmulated Annieling (SA)

Ant Colony Systems (ACS), 
Ant Systens (AS),
Genetic Algorithms (GA),
Particle Swarm Optimization (PSO)
EvolutiveProgramation (EV)



PARTICLE SWARM OPTIMIZATION:
Algoritm essentials:
	x: particle position
	v: particle velocity (same representation of particle)

	v_{i+1} = w v_i + rho_g phi_g (g - x_i) + rho_p phi_p (p - x_i)
	x_{i+1} = x_i + v_i
	
	Note: In your representation its necessary implement the +, -, and
	scalar multiplication operator overload.

Algoritm parameters:
	w = velocity ponderation (very important parameter)
	phi_g = explotation parameter
	phi_p = exploration parameter
	rho_g = best global position sesg ~ U(0, 1)
	rho_p = best local position sesg ~ U(0, 1)


Suite Usage:
	1. Create your Particle Representation Object 
	   In the example: Route.cpp
		
	1.1. Overload the +, -, * and >, ! operators
	    w = v*omega + (p-x)*(rhop*phip) + (g-x)*(rhog*phig);
	    x = x > w

	    > : update position operator to get the (x_i + v_i) operation.
	    	

	example: 
	Route operator+(const Route &b);
	Route operator*(float m);
	Route operator-(const Route &b);
	Route operator>(const Route &b); // velocity update operator
	void  operator!(); // for print particle object

	1.2. In Particle Object, define a fitnessEvaluation function, init
	Position function and init velocity function:

	float fitnessEvaluation(Route &r);
	void initRandomRoute(Route &r);
	void initRandomVelocity(Route &r);
				
	2. Create your Particle Representation cpp file
	example: RouteParticle.cpp, with the content
			
	#include "Particle_Template.h"
	template class Particle<Route>; 


	3. Create your Swarm Object
	#include "Swarm_Template.h"
	template class Swarm<Route>

	4. Create your Swarm Parametric Object
	Swarm<Route> swarm = Swarm<Route>(swarmSize, iterations, fitness);
	swarm.setParticleSize(particlesSize);

	4.1 declare the fitnessFunctions and velocity and route init functions
	fnRoute objectiveFunction = &Route::fitnessEvaluation;
	fnpRoute initPositionFunction = &Route::initRandomRoute;
	fnpRoute initVelocityFunction = &Route::initRandomVelocity;

	4.2 set the functions for PSO algoritms
	swarm.setFitnessFunction(objectiveFunction);
	swarm.setInitPositionFunction(initPositionFunction);
	swarm.setInitVelocityFunction(initVelocityFunction);

	4.3 Initialize the parameters
	swarm.setPhig(2);
	swarm.setPhip(3);
	swarm.setOmega(2);
	swarm.setRhog(0.1);
	swarm.setRhop(0.1);
	
	4.4 Initialize the swarm, iterate and find best solution

	float prevfitness = swarm.getFitness();
	swarm.iterate();
	swarm.printBestParticle();


Implementation Example:
	minimize the function: f(x) = x^2 + x + 1
	restriction = 10 < x < 100
	objective function: F = f(x) - penalization_sum

	class RealNumber {
		float value;
		RealNumber operator+(float value){
			this.value+=value;
			return this;
		}

		RealNumber operator-(float value){
			this.value-=value;
			return this;
		}

		RealNumber operator*(int value){
			this.value*=value;
			return this;
		}

		RealNumber operator>(RealNumber realNumber){
			this.value+=realNumber.getValue();
			return this;
		}

		void operator!(){
			cout << this.value << endl;
		}

		float fitnessFunction(){
			float x = this.value;
			return pow(x,2) + x + 1;
		}

		void initRandPosition(){
			this.value = RAND()/RAND_MAX;
		}

		void initRandVelocity(){
			this.value = RAND()/RAND_MAX;
		}
	}

	Swarm<Route> swarm = Swarm<Route>(swarmSize, iterations, fitness);
	swarm.setParticleSize(particlesSize);

	fnRoute objectiveFunction = &RealNumber::fitnessFunction;
	fnpRoute initPositionFunction = &RealNumber::initRandPosition;
	fnpRoute initVelocityFunction = &RealNumber::initRandVelocity;

	4.2 set the functions for PSO algoritms
	swarm.setFitnessFunction(objectiveFunction);
	swarm.setInitPositionFunction(initPositionFunction);
	swarm.setInitVelocityFunction(initVelocityFunction);

	4.3 Initialize the parameters
	swarm.setPhig(2);
	swarm.setPhip(3);
	swarm.setOmega(2);
	swarm.setRhog(0.1);
	swarm.setRhop(0.1);
	
	4.4 Initialize the swarm, iterate and find best solution
	swarm.initialize();
	float prevfitness = swarm.getFitness();
	swarm.iterate();
	float finalfitness = swamp.getFitness();
