//
// Created by Mark Hsu on 2019-09-28.
//
#include "Particle.h"

Particle::Particle() {
    setFitness(0);
    setPBestFitness(0);
    for (int i = 0; i < DIMENSION; i++) {
        setVelocity(i, 0);
        setLastVelocity(i, 0);
        setLocation(i, 0);
        setPBestLocation(i, 0);
    }
}

double *Particle::getVelocity() {
    return this->velocity;
}

void Particle::setVelocity(int index, double v) {
    this->velocity[index] = v;
}

double *Particle::getLastVelocity() {
    return this->lastVelocity;
}

void Particle::setLastVelocity(int index, double lv) {
    this->lastVelocity[index] = lv;
}

double *Particle::getLocation() {
    return this->location;
}

void Particle::setLocation(int index, double l) {
    this->location[index] = l;
}

double Particle::getPBestFitness() {
    return this->pBestFitness;
}

void Particle::setPBestFitness(double pb) {
    this->pBestFitness = pb;
}

double *Particle::getPBestLocation() {
    return this->pBestLocation;
}

void Particle::setPBestLocation(int index, double l) {
    this->pBestLocation[index] = l;
}

double Particle::getFitness() {
    return this->fitness;
}

void Particle::setFitness(double f) {
    this->fitness = f;
}
