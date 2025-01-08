#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(x) 42;
#endif
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

// author: Manzood Naqvi
// NOTE: This is a work in progress. It currently does not work as well as I
// want it to, and I have not tested it at all

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class GraphGenerator {
    int n, m;
    bool weighted;
    vector<vector<int>> graph;
    vector<vector<int>> weights;
    vector<pair<int, int>> tree_edges;

   public:
    GraphGenerator(int _n, int _m, bool _weighted = false)
        : n(_n), m(_m), weighted(_weighted) {
        graph.resize(n);
        weights.resize(n, vector<int>(n, 0));
    }

    void generateUnweightedGraph() {
        // make random edges, add them
        // TODO: consider the possibility of self loops and cycles
        set<pair<int, int>> edges;
        for (int i = 0; i < m; i++) {
            pair<int, int> edge;
            do {
                int sourceNode = uniform_int_distribution<int>(0, n - 1)(rng);
                int destNode = uniform_int_distribution<int>(0, n - 1)(rng);
                edge = {sourceNode, destNode};
            } while (edges.count(edge));
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
    }

    void generateWeights(vector<vector<int>>& adj, int range) {
        for (int i = 0; i < n; i++) {
            for (auto x : adj[i]) {
                weights[i][x] = uniform_int_distribution<int>(0, range)(rng);
            }
        }
    }

    void test_PrintGraph(vector<vector<int>>& adj) {
        for (int i = 0; i < (int)adj.size(); i++) {
            printf("%lld: ", i + 1);
            for (auto x : adj[i]) {
                printf("%lld ", x + 1);
            }
            printf("\n");
        }
    }

    // ideally, this function should be able to take in graphs of different
    // kinds and print them using a single interface
    void printGraph() {
        printf("%lld %lld %lld\n", n, m, (int)weighted);
        set<pair<int, int>> edges;
        for (int i = 0; i < n; i++)
            for (auto x : graph[i]) {
                int temp = i;
                if (temp > x) swap(temp, x);
                edges.insert({temp, x});
            }
        vector<pair<int, int>> e;
        for (auto x : edges) e.push_back(x);
        shuffle(e.begin(), e.end(), rng);
        for (auto x : e) printf("%lld %lld\n", x.first + 1, x.second + 1);
    }

    void generateBipartiteGraph() {
        // create two sets of nodes, and start to make edges between them
        vector<int> temp(n);
        iota(temp.begin(), temp.end(), 0);
        shuffle(temp.begin(), temp.end(), rng);
        int temp_index = uniform_int_distribution<int>(1, n - 2)(rng);
        vector<int> set1, set2;
        for (int i = 0; i <= temp_index; i++) {
            set1.push_back(temp[i]);
        }
        for (int i = temp_index + 1; i < n; i++) {
            set2.push_back(temp[i]);
        }
        // make m edges between set 1 and set 2
        set<pair<int, int>> edges;
        for (int i = 0; i < m; i++) {
            pair<int, int> edge;
            do {
                int temp1 =
                    uniform_int_distribution<int>(0, (int)set1.size() - 1)(rng);
                int temp2 =
                    uniform_int_distribution<int>(0, (int)set2.size() - 1)(rng);
                temp1 = set1[temp1];
                temp2 = set2[temp2];
                edge = {temp1, temp2};
            } while (edges.count(edge));
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
    }

    void generateTree() {
        vector<int> temp(n);
        iota(temp.begin(), temp.end(), 0);
        indexed_set s;
        vector<int> already;
        for (auto x : temp) s.insert(x);
        while (s.size()) {
            int rem = (int)s.size();
            int choice = uniform_int_distribution<int>(0, rem - 1)(rng);
            auto it = s.find_by_order(choice);
            if (already.size()) {
                choice = uniform_int_distribution<int>(
                    0, (int)already.size() - 1)(rng);
                graph[already[choice]].push_back(*it);
                graph[*it].push_back(already[choice]);
                tree_edges.push_back({*it, already[choice]});
            }
            already.push_back(*it);
            s.erase(it);
        }
    }

    void printTree() {
        sort(tree_edges.begin(), tree_edges.end());
        for (int i = 0; i < n - 1; i++) {
            printf("%lld %lld\n", tree_edges[i].first + 1,
                   tree_edges[i].second + 1);
        }
    }
};

// Usage: ./Graph_Generator n m is_weighted
int32_t main() {
    // vector <vector <int>> graph = generate_graph (n, m);
    // printgraph (graph);
    printf("1\n");
    int n = uniform_int_distribution<int>(1, 10)(rng);
    int q = uniform_int_distribution<int>(1, 10)(rng);
    printf("%lld %lld\n", n, q);
    GraphGenerator Gen(n, 0);
    Gen.generateTree();
    Gen.printTree();
    for (int i = 0; i < q; i++) {
        int k = uniform_int_distribution<int>(1, n)(rng);
        printf("%lld ", k);
        set<int> used;
        int choice;
        for (int j = 0; j < k; j++) {
            do {
                choice = uniform_int_distribution<int>(1, n)(rng);
            } while (used.count(choice));
            used.insert(choice);
        }
        for (auto x : used) {
            printf("%lld ", x);
        }
        printf("\n");
    }
    // Gen.generateUnweightedGraph();
    // Gen.printGraph();
}
