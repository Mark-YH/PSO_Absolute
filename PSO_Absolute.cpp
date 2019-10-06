//
// Created by Mark Hsu on 2019-09-30.
//

#include "PSO_Absolute.h"
#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

Particle particle[POPULATION];
double gBest = UPPER_BOUND;
double gBestLocation[DIMENSION];

void init() {
    for (int i = 0; i < POPULATION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            particle[i].setLocation(j, myRandom(LOWER_BOUND, UPPER_BOUND));
            particle[i].setLastVelocity(j, myRandom(LOWER_VELO_BOUND, UPPER_VELO_BOUND));
            particle[i].setVelocity(j, myRandom(LOWER_VELO_BOUND, UPPER_VELO_BOUND));

        }
        particle[i].setFitness(UPPER_BOUND);
        particle[i].setPBestFitness(UPPER_BOUND);
    }
}

void calcFitness() {
    for (int i = 0; i < POPULATION; i++) {
        double fitness = 0;

        for (int j = 0; j < DIMENSION; j++) {
            if (particle[i].getLocation()[j] < 0) { // negative number
                fitness += abs(particle[i].getLocation()[j]);
            } else { // positive number
                fitness += particle[i].getLocation()[j];
            }
        }

        particle[i].setFitness(fitness);

        // check if it needs to update pBest
        if (particle[i].getPBestFitness() > particle[i].getFitness()) {
            particle[i].setPBestFitness(fitness);
            for (int j = 0; j < DIMENSION; j++) {
                particle[i].setPBestLocation(j, particle[i].getLocation()[j]);
            }
        }

        // check if it needs to update gBest
        if (gBest > particle[i].getPBestFitness()) {
            gBest = particle[i].getPBestFitness();
            for (int j = 0; j < DIMENSION; j++) {
                gBestLocation[j] = particle[i].getPBestLocation()[j];
            }
        }
    }
}

void update() {
    for (int i = 0; i < POPULATION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            particle[i].setVelocity(j,
                                    W * particle[i].getLastVelocity()[j] +
                                    C1 * (myRandom(0, 1)) *
                                    (particle[i].getPBestLocation() - particle[i].getLocation()) +
                                    C2 * (myRandom(0, 1)) *
                                    (gBestLocation[j] - particle[i].getLocation()[j]));
            if (particle[i].getVelocity()[j] > UPPER_VELO_BOUND) {
                particle[i].setVelocity(j, UPPER_VELO_BOUND);
            } else if (particle[i].getVelocity()[j] < LOWER_VELO_BOUND) {
                particle[i].setVelocity(j, LOWER_VELO_BOUND);
            }
        }
    }
}

void move() {
    for (int i = 0; i < POPULATION; i++) {
        for (int j = 0; j < DIMENSION; j++) {
            // move forward
            particle[i].setLocation(j, particle[i].getLocation()[j] + particle[i].getVelocity()[j]);
            // update last velocity after moving forward
            particle[i].setLastVelocity(j, particle[i].getVelocity()[j]);

            // stop the particle which is out of bound
            if (particle[i].getLocation()[j] > UPPER_BOUND) {
                particle[i].setLocation(j, UPPER_BOUND);
            } else if (particle[i].getLocation()[j] < LOWER_BOUND) {
                particle[i].setLocation(j, LOWER_BOUND);
            }
        }
    }
}

void print(int round) {
    if (isFindBest()) {
        cout << "-----\nFind the best case at round " << round << "-----" << endl;
    }
    cout << "gBest: " << abs(gBest) << endl;
    for (int i = 0; i < DIMENSION; i++) {
        cout << setw(10) << setprecision(4) << gBestLocation[i] << ' ';
    }
    cout << endl;
}

bool isFindBest() {
    return gBest == 0;
}

double myRandom(double start, double end) {
    random_device rd;
    static default_random_engine gen = default_random_engine(rd());
    uniform_real_distribution<double> dis(start, end);
    return dis(gen);
}
