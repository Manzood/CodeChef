#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

vector<int> path;
int sum = 0;
void dfs(int node, int par, vector<vector<int>>& adj, int dist,
         vector<vector<int>>& paths, vector<int>& p) {
    path.push_back(node);
    sum += p[node];
    paths[(int)path.size()].push_back(sum);
    for (auto u : adj[node]) {
        if (u == par) continue;
        dfs(u, node, adj, dist + 1, paths, p);
    }
    path.pop_back();
    sum -= p[node];
}

void solve([[maybe_unused]] int test) {
    int n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &p[i]);
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> apaths, bpaths;
    dfs(a, -1, adj, 0, apaths, p);
    dfs(b, -1, adj, 0, bpaths, p);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
