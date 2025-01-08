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

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis) {
    if (vis[node]) return;
    vis[node] = true;
    for (auto u : adj[node]) {
        dfs(u, adj, vis);
    }
}
void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &x[i], &y[i]);
    }
    int low = 0, high = (int)1e9 + 7;
    while (low < high) {
        int mid = (low + high) / 2;
        bool connected = true;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (x[i] != x[j] && y[i] != y[j]) {
                    if (max(abs(x[i] - x[j]), abs(y[i] - y[j])) <= mid) {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                } else {
                    int mx = max(abs(x[i] - x[j]), abs(y[i] - y[j]));
                    mx = (mx + 1) / 2;
                    if (mx <= mid) {
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
        }
        vector<bool> vis(n, false);
        dfs(0, adj, vis);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) connected = false;
        }
        if (connected) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    printf("%lld\n", high);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
