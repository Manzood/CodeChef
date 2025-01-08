#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) { return weight < other.weight; }
};

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dist = max(abs(x[i] - x[j]), abs(y[i] - y[j]));
            if (x[i] == x[j] || y[i] == y[j]) {
                dist = (dist + 1) / 2;
            }
            Edge cur;
            cur.u = i, cur.v = j, cur.weight = dist;
            edges.push_back(cur);
        }
    }

    for (auto e : edges) {
        debug(test, e.u, e.v, e.weight);
    }

    vector<int> tree_id(n);
    for (int i = 0; i < n; i++) tree_id[i] = i;
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (Edge e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            ans = max(ans, e.weight);

            int old_id = tree_id[e.u], new_id = tree_id[e.v];
            for (int i = 0; i < n; i++) {
                if (tree_id[i] == old_id) tree_id[i] = new_id;
            }
        }
    }

    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
