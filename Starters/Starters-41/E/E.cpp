#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector <bool> visited;
int f(int node, int col, vector <vector <int>>& adj, vector <int>& force, vector <int>& a, vector <int>& b) {
    int retval = 0;
    visited[node] = true;
    bool has_children = false;
    for (auto u: adj[node]) {
        if (!visited[u]) {
            has_children = true;
            retval += f(u, b[node], adj, force, a, b);
        }
    }
    if (b[node] != col) retval++;
    if (b[node] == col && has_children) retval++;
    force[node] = retval;
    return retval;
}

// write a dfs

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n), b(n);
    vector <vector <int>> adj(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <int> force(n, 0);
    f(0, -1, adj, force, a, b);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
