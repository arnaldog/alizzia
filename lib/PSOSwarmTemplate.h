
/*
 * File:   PSOSwarmTemplate.h
 * Author: arnaldog
 *
 * Created on 3 de junio de 2011, 1:10
 */

#ifndef PSOSwarmTemplate_H
#define	PSOSwarmTemplate_H

#ifdef _OPENMP 
	#include <omp.h> 
#else 
	#define omp_get_thread_num() 0 
#endif

#include "PSOSwarm.h"

/*
 * Templating functions
 */
template <class T> PSOSwarm<T>::PSOSwarm(){
}

template <class T> PSOSwarm<T>::PSOSwarm(int size, int iterations, float fitness){

	/*
	cout << "PSOSwarm size: " << size << endl;
	cout << "PSOSwarm iterations: " << iterations << endl;
	cout << "PSOSwarm fitness: " << fitness << endl;
	*/
	
	this->size = size;
	this->iterations = iterations;
	this->fitness = fitness;
	this->population = vector < PSOParticle<T> > (size);
}

template <class T> PSOSwarm<T>::~PSOSwarm(){
}

template <class T> void PSOSwarm<T>::setBestPSOParticleIndex(int bestPSOParticleIndex) {
	this->bestPSOParticleIndex = bestPSOParticleIndex;
}

template <class T> int PSOSwarm<T>::getBestPSOParticleIndex() const {
	return bestPSOParticleIndex;
}

template <class T> void PSOSwarm<T>::setFitness(float fitness) {
	this->fitness = fitness;
}

template <class T> float PSOSwarm<T>::getFitness() const {
	return fitness;
}

template <class T> void PSOSwarm<T>::setIterations(int iterations) {
	this->iterations = iterations;
}
template <class T> int PSOSwarm<T>::getIterations() const {
	return iterations;
}

template <class T> void PSOSwarm<T>::setPopulation(vector< PSOParticle<T> > population) {
	this->population = population;
}

template <class T> vector<PSOParticle<T> > const& PSOSwarm<T>::getPopulation() {
	return population;
}

template <class T> void PSOSwarm<T>::setSize(int size) {
this->size = size;
}

template <class T> int PSOSwarm<T>::getSize() const {
	return size;
}

template <class T> PSOSwarm<T>::PSOSwarm(const PSOSwarm& orig){
}

template <class T> void PSOSwarm<T>::setFitnessFunction(float (T::*f)(T&)){
	this->fitnessFunction = f;
}

template <class T> float PSOSwarm<T>::evaluateFitness(T &position){
	return ((position).*(this->fitnessFunction))(position);
}

/* Evaluation functions callers */
template <class T> void PSOSwarm<T>::evaluateInitPosition(T &position){
	return ((position).*(this->initPositionFunction))(position);
}

template <class T> void PSOSwarm<T>::evaluateInitVelocity(T &velocity){
	return ((velocity).*(this->initVelocityFunction))(velocity);
}

template <class T> void PSOSwarm<T>::setPSOParticleSize(int PSOParticleSize) {
	this->PSOParticleSize = PSOParticleSize;
}
template <class T> int PSOSwarm<T>::getPSOParticleSize() const {
	return PSOParticleSize;
}

template <class T> void PSOSwarm<T>::setRhog(float rhog) {
	this->rhog = rhog;
}

template <class T> void PSOSwarm<T>::setRhop(float rhop) {
	this->rhop = rhop;
}

template <class T> void PSOSwarm<T>::setPhig(float phig) {
	this->phig = phig;
}

template <class T> void PSOSwarm<T>::setPhip(float phip) {
	this->phip = phip;
}
template <class T> void PSOSwarm<T>::setOmega(float omega) {
	this->omega = omega;
}

template <class T> void PSOSwarm<T>::printBestPSOParticle(){
	int index = this->bestPSOParticleIndex;
	T position = T();
	position = this->population[index].getBestPosition();
}

/* setters for initializer functions */
template <class T> void PSOSwarm<T>::setInitPositionFunction(void (T::*f)(T&)){
	this->initPositionFunction = f;
}

template <class T> void PSOSwarm<T>::setInitVelocityFunction(void (T::*f)(T&)){
	this->initVelocityFunction = f;
}


template <class T> void PSOSwarm<T>::updatePSOParticleVelocity(PSOParticle<T> &PSOParticle){

	float omega = this->omega;
	float phip = this->phip;
	float phig = this->phig;

	// PSOParticle propierties
	T v = T(); /* current velocity */
	T p = T(); /* best position of PSOParticle */
	T x = T(); /* current position */
	T g = T(); /* global best position */

	float rhop = (float)rand()/(float)RAND_MAX;
	float rhog = (float)rand()/(float)RAND_MAX;
	float omeg = (float)rand()/(float)RAND_MAX;

	v = PSOParticle.getVelocity();
	p = PSOParticle.getBestPosition();
	x = PSOParticle.getPosition();
	g = this->population[this->getBestPSOParticleIndex()].getBestPosition();

	T w = T();

	w = v*omega + (p-x)*(rhop*phip) + (g-x)*(rhog*phig);

	PSOParticle.setVelocity(w);

	return;
}

/* Concrete Methods */
template <class T> void PSOSwarm<T>::initialize(){

	//cout << "PSOSwarm::initialize(): inicializando particulas..." << endl;
	int i;
	int n;

	n = this->population.size();

	//inicializar cada particula de la poblacion
	#pragma omp parallel for private(i)
	for(i=0; i < n; i++){

		PSOParticle<T> &p = this->population[i];

		/* PSOParticle Initialization */
		T position = T();
		T velocity = T();
		float fitness;

		this->evaluateInitPosition(position);
		this->evaluateInitVelocity(velocity);
		fitness = this->evaluateFitness(position);

		/* PSOParticle position, velocity and fitness setting*/
		p.setPosition(position);
		p.setVelocity(velocity);
		p.setFitness(fitness);

		p.setBestPosition(position);
		p.setBestVelocity(velocity);
		p.setBestFitness(fitness);


		//actualizar la mejor solucion conocida
		if(fitness < this->fitness) {
			//actualizar la mejor solucion de la poblacion
			#pragma omp critical
			{
				this->setFitness(fitness);
				this->bestPSOParticleIndex = i;
			}
		}
	}

}



template <class T> void PSOSwarm<T>::iterate() {
	//criterio de parada: numero de iteraciones.
	int i, j;
	int iterations = this->iterations;
	int population_size = this->population.size();

	PSOParticle<T> p= PSOParticle<T>();
	T position = T();
	T bestVelocity = T();
	float PSOParticleFitness;

	for(j=0; j < iterations; j++){
		// para cada partícula, hacer:

		#pragma omp parallel for private(position, bestVelocity, PSOParticleFitness, p, i) 
		for (i = 0; i < population_size; i++) {

//			cout << "PSOSwarm::iterate(): iterando sobre particula " << i << endl;

			p = this->population[i];

			position = p.getPosition();
			bestVelocity = p.getBestVelocity();

			this->updatePSOParticleVelocity(p);
			p.updatePosition();

			PSOParticleFitness = this->evaluateFitness(position);
			p.setFitness(PSOParticleFitness);

			//if (f(xi) < f(pi)) do:
			if (p.getFitness() < p.getBestFitness()) {
				p.setBestPosition(position);
				p.setBestVelocity(bestVelocity);
				p.setFitness(PSOParticleFitness);
			}

			//if (f(pi) < f(g)) update the PSOSwarm's best known position:
			//g ← pi
			if (PSOParticleFitness < this->fitness) {
					cout << "PSOSwarm::iterate: Updating best PSOParticle:" << i << endl;
					cout << "PSOSwarm::iterate: with fitness: " << PSOParticleFitness << endl;
					this->setFitness(PSOParticleFitness);
					this->setBestPSOParticleIndex(i);
			}

			//debug
			//cout << "PSOSwarm::iterate(): finalmente la particula en esta iteracion quedo como: " << endl;
			//cout << p.toString();
		}

		// debug
		//cout << "PSOSwarm::iterate(): resumen de iteracion " << iteration << ":";
		//cout << " mejor particula: " << this->getBestPSOParticleIndex();
		//cout << " mejor fitness: " << this->fitness << endl;

	}
}




#endif	/* PSOSwarmTemplate_H */

