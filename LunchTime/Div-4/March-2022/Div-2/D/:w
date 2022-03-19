#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> parent;
vector<bool> visited;
int dfs(int node, int p, vector<vector<int>>& adj, vector<int>& subtree, vector<int>& deg) {
    visited[node] = true;
    parent[node] = p;
    if (p > -1) subtree[node] = deg[p];
    else subtree[node] = 0;
    if (deg[node] == 1) return subtree[node];
    int retval = 0;
    for (auto u : adj[node]) {
        if (!visited[u]) {
            retval += dfs(u, node, adj, subtree, deg);
            // retval += deg[node];
            deg[node]--;
        }
    }
    subtree[node] = retval;
    return subtree[node];
}

void solve([[maybe_unused]] int test) {
    int n, q;
    scanf("%lld%lld", &n, &q);
    vector<vector<int>> adj(n);
    vector <int> subtree(n, 0);
    vector <int> deg(n, 0);
    parent.resize(n, -1);
    visited.resize(n, false);
    parent.assign(n, -1);
    visited.assign(n, false);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    vector <int> degree = deg;
    int ans = dfs (0, -1, adj, subtree, degree);
    // debug (subtree);
    printf("%lld\n", ans);
    for(int i = 0; i < q; i++) {
        int a, b, c, d;
        scanf("%lld%lld", &a, &b);
        scanf("%lld%lld", &c, &d);
        a--; b--; c--; d--;
        int aval, bval, cval, dval;
        aval = bval = cval = dval = 0;
        if (parent[a] == b) aval = deg[b];
        else aval = deg[a];
        printf("%lld\n", ans + deg[c] + deg[d] - deg[a] - deg[b]);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
