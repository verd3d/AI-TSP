#include "TSP.h"

double calculatePathCost(const vector<int>& path, const vector<vector<double>>& distances) {
    double total_cost = 0;
    for (int i = 0; i < path.size() - 1; ++i) {
        total_cost += distances[path[i]][path[i + 1]];
    }
    total_cost += distances[path.back()][path.front()]; // return to origin
    return total_cost;
}

double calculateLongestLegCost(const vector<int>& path, const vector<vector<double>>& distances) {
    double max_cost = 0;
    for (int i = 0; i < path.size() - 1; ++i) {
        max_cost = max(max_cost, distances[path[i]][path[i + 1]]);
    }
    max_cost = max(max_cost, distances[path.back()][path.front()]); // return to origin
    return max_cost;
}
