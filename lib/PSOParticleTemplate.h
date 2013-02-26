/*
 * File:   PSOParticle_Template.h
 * Author: alejandrasuarez
 *
 * Created on 3 de junio de 2011, 1:30
 */

#include "PSOParticle.h"

#ifndef PSOParticleTemplate_H
#define	PSOParticleTemplate_H

template <class T> PSOParticle<T>::PSOParticle() {
}
template <class T> void PSOParticle<T>::setBestFitness(float bestFitness) {
    this->bestFitness = bestFitness;
}
template <class T> float PSOParticle<T>::getBestFitness()  {
    return bestFitness;
}
template <class T> void PSOParticle<T>::setFitness(float fitness) {
    this->fitness = fitness;
}
template <class T> float PSOParticle<T>::getFitness()  {
    return fitness;
}

template <class T> void PSOParticle<T>::setBestVelocity(T const& bestVelocity) {
    this->bestVelocity = bestVelocity;
}
template <class T> T const& PSOParticle<T>::getBestVelocity()  {
    return bestVelocity;
}

template <class T> void PSOParticle<T>::setBestPosition(T const& bestPosition) {
    this->bestPosition = bestPosition;
}

template <class T> T const& PSOParticle<T>::getBestPosition()  {
    return bestPosition;
}
template <class T> void PSOParticle<T>::setVelocity(T const& velocity) {
    this->velocity = velocity;
}

template <class T> T const& PSOParticle<T>::getVelocity()  {
    return velocity;
}

template <class T> void PSOParticle<T>::setPosition(T const& position) {
    this->position = position;
}

template <class T> T const& PSOParticle<T>::getPosition() {
    return this->position;
}

template <class T> PSOParticle<T>::PSOParticle(const PSOParticle& orig) {
}

template <class T> PSOParticle<T>::~PSOParticle() {
}

template <class T> void PSOParticle<T>::updatePosition(){
    this->position = this->position > this->velocity;
}

#endif	/* PSOParticleTemplate_H */

