
using namespace std;
#include <cstdlib>

#include "../../../lib/PSOSwarm.h"
#include "../../../lib/PSOParticleTemplate.h"
#include "../../../lib/PSOSwarmTemplate.h"

/** YOUR REPRESENTATION OBJECT **/
#include "RealNumber.h"

template class PSOParticle<RealNumber>; 
template class PSOSwarm<RealNumber>; 

/*********************************/


typedef float (RealNumber::*fnRealNumber)(RealNumber &r);
typedef void (RealNumber::*fnpRealNumber)(RealNumber &r);


int main(){

	PSOSwarm<RealNumber> psoSwarm = PSOSwarm<RealNumber>(10, 1, 9999999);

	fnRealNumber of = &RealNumber::fitnessFunction;
	fnpRealNumber f_x_0 = &RealNumber::initRandomPosition;
	fnpRealNumber f_v_0 = &RealNumber::initRandomVelocity;

	psoSwarm.setFitnessFunction(of);
	psoSwarm.setInitPositionFunction(f_x_0);
	psoSwarm.setInitVelocityFunction(f_v_0);

	psoSwarm.setPhig(2);
	psoSwarm.setPhip(3);
	psoSwarm.setOmega(1);
	psoSwarm.setRhog(2);
	psoSwarm.setRhop(2);

	cout << "initializing the PSOSwarm " << endl;
	cout << psoSwarm.getFitness() << endl;

	psoSwarm.initialize();
	
	psoSwarm.iterate();

	cout << psoSwarm.getFitness() << endl;

	return 0;

}
