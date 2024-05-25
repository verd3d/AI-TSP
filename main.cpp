#include "TSP.h"

void bfs(TSP& tsp);
void ucs(TSP& tsp);
void a_star(TSP& tsp);

int main() {
    TSP tsp(4);
    tsp.cities = {
        {0, "A"},
        {1, "B"},
        {2, "C"},
        {3, "D"}
    };
    tsp.addDistance(0, 1, 10);
    tsp.addDistance(0, 2, 15);
    tsp.addDistance(0, 3, 20);
    tsp.addDistance(1, 2, 35);
    tsp.addDistance(1, 3, 25);
    tsp.addDistance(2, 3, 30);

    bfs(tsp);
    ucs(tsp);
    a_star(tsp);

    return 0;
}
