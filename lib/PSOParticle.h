/*
 * File:   PSOParticle.h
 * Author: alejandrasuarez
 *
 * Created on 3 de junio de 2011, 1:30
 */

#ifndef PSOParticle_H
#define	PSOParticle_H

template <class T> class PSOParticle {

public:
    /* Constructors and others*/
    PSOParticle();
    PSOParticle(const PSOParticle& orig);
    virtual ~PSOParticle();

    /* Concrete Methods */
    void updatePosition();


    /*  Getters and Setters */
    void setBestFitness(float bestFitness);
    float getBestFitness() ;

    void setFitness(float fitness);
    float getFitness() ;

    void setBestVelocity(T const& bestVelocity);
    T const& getBestVelocity() ;

    void setBestPosition(T const& bestPosition);
    T const& getBestPosition() ;

    void setVelocity(T const& velocity);
    T const& getVelocity() ;

    void setPosition(T const& position);
    T const& getPosition();

private:
    T position;
    T velocity;
    T bestPosition;
    T bestVelocity;
    float fitness;
    float bestFitness;

};

#endif	/* PSOParticle_H */

