#include "TSP.h"

void bfs(TSP& tsp) {
    int n = tsp.cities.size();
    queue<vector<int>> q;
    q.push({ 0 }); // Start from city 0
    double min_longest_leg_cost = numeric_limits<double>::max();
    vector<int> best_path;

    while (!q.empty()) {
        vector<int> path = q.front();
        q.pop();

        if (path.size() == n) {
            path.push_back(0); // return to origin
            double longest_leg_cost = calculateLongestLegCost(path, tsp.distances);
            if (longest_leg_cost < min_longest_leg_cost) {
                min_longest_leg_cost = longest_leg_cost;
                best_path = path;
            }
            path.pop_back();
        }
        else {
            for (int i = 1; i < n; ++i) {
                if (find(path.begin(), path.end(), i) == path.end()) {
                    vector<int> new_path = path;
                    new_path.push_back(i);
                    q.push(new_path);
                }
            }
        }
    }

    cout << "BFS Best path: ";
    for (int city : best_path) cout << city << " ";
    cout << "\nBFS Minimum longest leg cost: " << min_longest_leg_cost << endl;
}
