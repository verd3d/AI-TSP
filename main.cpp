#include "TSP.h"
#include <chrono>   
void bfs(TSP& tsp);
void ucs(TSP& tsp);
void a_star(TSP& tsp);

int main() {
    TSP tsp(10);
    tsp.cities = {
        {0, "B"},
        {1, "C"},
        {2, "T"},
        {3, "P"},
        {4, "Ct"},
        {5, "I"},
        {6, "Cl"},
        {7, "Br"},
        {8, "O"},
        {9, "S"}
    };

    tsp.addDistance(0, 1, 230);
    tsp.addDistance(0, 2, 530);
    tsp.addDistance(0, 3, 120);
    tsp.addDistance(0, 4, 225);
    tsp.addDistance(0, 5, 380);
    tsp.addDistance(0, 6, 445);
    tsp.addDistance(0, 7, 160);
    tsp.addDistance(0, 8, 575);
    tsp.addDistance(0, 9, 275);
    tsp.addDistance(1, 2, 330);
    tsp.addDistance(1, 3, 110);
    tsp.addDistance(1, 4, 300);
    tsp.addDistance(1, 5, 500);
    tsp.addDistance(1, 6, 430);
    tsp.addDistance(1, 7, 190);
    tsp.addDistance(1, 8, 520);
    tsp.addDistance(1, 9, 200);
    tsp.addDistance(2, 3, 420);
    tsp.addDistance(2, 4, 600);
    tsp.addDistance(2, 5, 430);
    tsp.addDistance(2, 6, 100);
    tsp.addDistance(2, 7, 450);
    tsp.addDistance(2, 8, 140);
    tsp.addDistance(2, 9, 340);
    tsp.addDistance(3, 4, 250);
    tsp.addDistance(3, 5, 360);
    tsp.addDistance(3, 6, 300);
    tsp.addDistance(3, 7, 160);
    tsp.addDistance(3, 8, 480);
    tsp.addDistance(3, 9, 220);
    tsp.addDistance(4, 5, 380);
    tsp.addDistance(4, 6, 510);
    tsp.addDistance(4, 7, 290);
    tsp.addDistance(4, 8, 620);
    tsp.addDistance(4, 9, 300);
    tsp.addDistance(5, 6, 360);
    tsp.addDistance(5, 7, 350);
    tsp.addDistance(5, 8, 400);
    tsp.addDistance(5, 9, 400);
    tsp.addDistance(6, 7, 280);
    tsp.addDistance(6, 8, 130);
    tsp.addDistance(6, 9, 220);
    tsp.addDistance(7, 8, 310);
    tsp.addDistance(7, 9, 140);
    tsp.addDistance(8, 9, 240);

    auto start = chrono::high_resolution_clock::now();
    a_star(tsp);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "A* Execution time: " << duration << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    ucs(tsp);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "UCS Execution time: " << duration << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    bfs(tsp);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "BFS Execution time: " << duration << " seconds" << endl;
    return 0;
}
