#include "TSP.h"

struct PathCost {
    vector<int> path;
    double cost;
    double longest_leg_cost;
    bool operator<(const PathCost& other) const {
        return longest_leg_cost > other.longest_leg_cost;
    }
};

void ucs(TSP& tsp) {
    int n = tsp.cities.size();
    priority_queue<PathCost> pq;
    pq.push({ {0}, 0, 0 });
    double min_longest_leg_cost = numeric_limits<double>::max();
    vector<int> best_path;

    while (!pq.empty()) {
        PathCost pc = pq.top();
        pq.pop();

        if (pc.path.size() == n) {
            pc.path.push_back(0); // return to origin
            pc.longest_leg_cost = calculateLongestLegCost(pc.path, tsp.distances);
            if (pc.longest_leg_cost < min_longest_leg_cost) {
                min_longest_leg_cost = pc.longest_leg_cost;
                best_path = pc.path;
            }
        }
        else {
            for (int i = 1; i < n; ++i) {
                if (find(pc.path.begin(), pc.path.end(), i) == pc.path.end()) {
                    vector<int> new_path = pc.path;
                    new_path.push_back(i);
                    double new_cost = pc.cost + tsp.distances[pc.path.back()][i];
                    double new_longest_leg_cost = max(pc.longest_leg_cost, tsp.distances[pc.path.back()][i]);
                    pq.push({ new_path, new_cost, new_longest_leg_cost });
                }
            }
        }
    }

    cout << "UCS Best path: ";
    for (int city : best_path) cout << city << " ";
    cout << "\nUCS Minimum longest leg cost: " << min_longest_leg_cost << endl;
}
