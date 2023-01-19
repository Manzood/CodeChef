#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int MOD = (int)1e9 + 7;

vector<int> marked;
int checkcycle(int src, int dest, vector<int>& par, vector<int>& indegree) {
    int cur = src;
    int len = 1;
    marked[cur] = true;
    while (cur != dest) {
        if (indegree[cur] > 1) {
            return -1;
        }
        cur = par[cur];
        len++;
        marked[cur] = true;
        assert(len < (int)3e5);
    }
    return len;
}

vector<bool> visited, visiting;
int ans = 1;
void dfs(int node, vector<vector<int>>& adj, vector<int>& par,
         vector<int>& indegree) {
    if (visited[node]) return;
    visited[node] = true;
    visiting[node] = true;
    for (auto u : adj[node]) {
        if (visiting[u]) {
            int len = checkcycle(node, u, par, indegree);
            if (len != -1) {
                int val = 1;
                for (int i = 0; i < len; i++) {
                    val *= 2;
                    val %= MOD;
                }
                val--;
                if (val < 0) val += MOD;
                ans *= val;
                ans %= MOD;
            }
        } else {
            par[u] = node;
            dfs(u, adj, par, indegree);
        }
    }
    visiting[node] = false;
}

void solve([[maybe_unused]] int test) {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector<pair<int, int>> edges(n);  // second to first
    vector<vector<int>> adj(m);
    vector<int> indegree(m, 0);
    marked.assign(m, false);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &edges[i].first, &edges[i].second);
        adj[--edges[i].second].push_back(--edges[i].first);
        indegree[edges[i].first]++;
    }
    for (int i = 0; i < m; i++)
        if (indegree[i] == 0) marked[i] = true;
    ans = 1;
    visited.assign(m, false);
    visiting.assign(m, false);
    vector<int> par(m, -1);
    for (int i = 0; i < m; i++) {
        if (!visited[i]) {
            dfs(i, adj, par, indegree);
        }
    }
    for (int i = 0; i < m; i++) {
        if (!marked[i]) {
            ans *= 2;
            ans %= MOD;
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
