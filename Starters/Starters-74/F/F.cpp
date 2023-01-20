#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

vector<bool> visited;
void dfs1(int node, vector<vector<int>>& adj, vector<int>& order) {
    if (visited[node]) return;
    visited[node] = true;
    for (auto u : adj[node]) dfs1(u, adj, order);
    order.push_back(node);
}

void dfs2(int node, vector<vector<int>>& adj, vector<int>& component,
          vector<int>& components, int c) {
    if (visited[node]) return;
    visited[node] = true;
    if (c == -1) {
        c = node;
        components.push_back(node);
    }
    component[node] = c;
    for (auto u : adj[node]) dfs2(u, adj, component, components, c);
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    swap(n, m);
    vector<pair<int, int>> edges(m);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        scanf("%lld%lld", &edges[i].first, &edges[i].second);
        adj[--edges[i].second].push_back(--edges[i].first);
    }
    vector<int> order;
    visited.assign(n, false);
    for (int i = 0; i < n; i++) dfs1(i, adj, order);
    reverse(order.begin(), order.end());
    vector<vector<int>> transpose(n);
    for (int i = 0; i < n; i++)
        for (auto x : adj[i]) transpose[x].push_back(i);
    vector<int> component(n), components;
    visited.assign(n, false);
    for (auto node : order) dfs2(node, transpose, component, components, -1);
    vector<vector<int>> condensed_graph(n);
    vector<int> indegree(n, 0), sz(n, 0);
    for (int i = 0; i < n; i++)
        for (auto u : adj[i])
            if (component[u] != component[i])
                condensed_graph[component[i]].push_back(component[u]);
    for (int i = 0; i < n; i++) sz[component[i]]++;
    for (int i = 0; i < n; i++)
        for (auto u : condensed_graph[i]) indegree[u]++;
    int ans = 1;
    vector<int> marked_component(n, false);
    for (auto u : components) {
        if (indegree[u] == 0) {
            marked_component[u] = true;
            int val = 1;
            for (int i = 0; i < sz[u]; i++) (val *= 2) %= MOD;
            (val += MOD - 1) %= MOD;
            (ans *= val) %= MOD;
        }
    }
    for (int i = 0; i < n; i++)
        if (!marked_component[component[i]]) (ans *= 2) %= MOD;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) solve(tt);
}
