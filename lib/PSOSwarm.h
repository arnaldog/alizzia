/* 
 * File:   PSOSwarm.h
 * Author: alejandrasuarez
 *
 * Created on 3 de junio de 2011, 0:25
 */

#ifndef PSOSwarm_H
#define	PSOSwarm_H

using namespace std;
#include <iostream>
#include <vector>

/*
 * Context Includes
 */

#include "PSOParticle.h"

template <class T> class PSOSwarm {
public:
    PSOSwarm();
    PSOSwarm(int size, int iterations, float fitness);
    PSOSwarm(const PSOSwarm& orig);
    virtual ~PSOSwarm();

    /*
     * Iterations Methods
     */

    /*
     * Getters and Setters
     */
    
    void initialize();
    void iterate();
    
    void setBestPSOParticleIndex(int bestPSOParticleIndex);
    int getBestPSOParticleIndex() const;

    void setFitness(float fitness);
    float getFitness() const;

    void setIterations(int iterations);
    int getIterations() const;

    void setPopulation(vector<PSOParticle<T> > population);
    vector<PSOParticle<T> > const& getPopulation();
    
    void setSize(int size);
    int getSize() const;

    

    // funcion que le actualiza la velocidad a la partícula
    // pasa por referencia a la particula y le actualiza la velocidad
    // retorna void.
    void updatePSOParticleVelocity(PSOParticle<T> &PSOParticle);

    float evaluateFitness(T &position);
    void evaluateInitPosition(T &position);
    void evaluateInitVelocity(T &velocity);

    void setFitnessFunction(float (T::*f)(T&));
    void setInitPositionFunction(void (T::*f)(T&));
    void setInitVelocityFunction(void (T::*f)(T&));

    void setPSOParticleSize(int PSOParticleSize);
    int getPSOParticleSize() const;
    
    void setRhog(float rhog);
    void setRhop(float rhop);
    void setPhig(float phig);
    void setPhip(float phip);
    void setOmega(float omega);

    void printBestPSOParticle();


private:

    /* PSOSwarm general attributes */
    int size;
    vector < PSOParticle<T> > population;  // PSOParticle template based population
    int PSOParticleSize;
    
    /* PSOSwarm optimization attributes */
    int iterations;
    float omega;
    float phip;
    float phig;
    float rhop;
    float rhog;
    
    float fitness;
    int bestPSOParticleIndex;
    
    float (T::*fitnessFunction) (T&);
    void (T::*initPositionFunction) (T&);
    void (T::*initVelocityFunction) (T&);
};


#endif	/* PSOSwarm_H */
