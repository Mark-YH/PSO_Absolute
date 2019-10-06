#include "PSO_Absolute.h"

int main() {
    init();
    for (int i = 0; i < ROUND; i++) {
        calcFitness();
        update();
        move();
        print(i);
    }

    return 0;
}