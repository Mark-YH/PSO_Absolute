//
// Created by Mark Hsu on 2019-09-28.
//

#ifndef PSO_PARTICLE_H
#define PSO_PARTICLE_H

#define DIMENSION 1

class Particle {
public:
    Particle();

    double getPBestFitness();

    void setPBestFitness(double pBest);

    double *getPBestLocation();

    void setPBestLocation(int index, double location);

    double getFitness();

    void setFitness(double fitness);

    double *getVelocity();

    void setVelocity(int index, double velocity);

    double *getLastVelocity();

    void setLastVelocity(int index, double lastVelocity);

    double *getLocation();

    void setLocation(int index, double location);

private:
    double fitness;
    double velocity[DIMENSION];
    double lastVelocity[DIMENSION];
    double location[DIMENSION];
    double pBestFitness;
    double pBestLocation[DIMENSION];
};

#endif //PSO_PARTICLE_H
