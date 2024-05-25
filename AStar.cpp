#include "TSP.h"

double heuristic(const vector<int>& path, const vector<vector<double>>& distances, int n) {
    unordered_set<int> remaining;
    for (int i = 0; i < n; ++i) {
        if (find(path.begin(), path.end(), i) == path.end()) {
            remaining.insert(i);
        }
    }

    if (remaining.empty()) return 0;

    priority_queue<Edge, vector<Edge>, greater<>> pq;
    for (int city : remaining) {
        for (int other : remaining) {
            if (city != other) {
                pq.push(Edge(city, other, distances[city][other]));
            }
        }
    }

    double mst_cost = 0;
    unordered_map<int, int> parent;
    function<int(int)> find = [&](int city) {
        if (parent[city] == city) return city;
        return parent[city] = find(parent[city]);
        };

    for (int city : remaining) parent[city] = city;

    while (!pq.empty()) {
        Edge edge = pq.top();
        pq.pop();

        int root1 = find(edge.from);
        int root2 = find(edge.to);

        if (root1 != root2) {
            mst_cost += edge.distance;
            parent[root1] = root2;
        }
    }

    return mst_cost;
}

struct AStarPathCost {
    vector<int> path;
    double cost;
    double estimated_total_cost;
    bool operator<(const AStarPathCost& other) const {
        return estimated_total_cost > other.estimated_total_cost;
    }
};

void a_star(TSP& tsp) {
    int n = tsp.cities.size();
    priority_queue<AStarPathCost> pq;
    pq.push({ {0}, 0, heuristic({0}, tsp.distances, n) });
    double min_longest_leg_cost = numeric_limits<double>::max();
    vector<int> best_path;

    while (!pq.empty()) {
        AStarPathCost pc = pq.top();
        pq.pop();

        if (pc.path.size() == n) {
            pc.path.push_back(0); // return to origin
            double longest_leg_cost = calculateLongestLegCost(pc.path, tsp.distances);
            if (longest_leg_cost < min_longest_leg_cost) {
                min_longest_leg_cost = longest_leg_cost;
                best_path = pc.path;
            }
        }
        else {
            for (int i = 1; i < n; ++i) {
                if (find(pc.path.begin(), pc.path.end(), i) == pc.path.end()) {
                    vector<int> new_path = pc.path;
                    new_path.push_back(i);
                    double new_cost = pc.cost + tsp.distances[pc.path.back()][i];
                    double estimated_total_cost = new_cost + heuristic(new_path, tsp.distances, n);
                    pq.push({ new_path, new_cost, estimated_total_cost });
                }
            }
        }
    }

    cout << "A* Best path: ";
    for (int city : best_path) cout << city << " ";
    cout << "\nA* Minimum longest leg cost: " << min_longest_leg_cost << endl;
}
