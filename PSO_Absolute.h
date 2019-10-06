//
// Created by Mark Hsu on 2019-09-30.
//

#ifndef PSO_PSO_ABSOLUTE_H
#define PSO_PSO_ABSOLUTE_H

#include "Particle.h"

/**
 * LOWER_BOUND and UPPER_BOUND are domain
 * LOWER_VELO_BOUND and UPPER_VELO_BOUND are the bound of velocity
 */
#define LOWER_BOUND -100
#define UPPER_BOUND 100
#define LOWER_VELO_BOUND -10
#define UPPER_VELO_BOUND 10
#define POPULATION 50
#define ROUND 1000000
#define W 1
#define C1 1
#define C2 1

void init();

void calcFitness();

void update();

void move();

void print(int round);

bool isFindBest();

double myRandom(double start, double end);

#endif //PSO_PSO_ABSOLUTE_H
