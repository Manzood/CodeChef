#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int mod = (int) 1e9 + 7;

// bfs
vector <int> assignments;
vector <bool> visited;
queue <int> q;
void bfs (int start_node, vector <vector <int>>& adj) {
    q.push(start_node);
    while (!q.empty()) {
        int node = q.front();
        if (visited[node]) {
            q.pop();
            continue;
        }
        visited[node] = true;
        for (auto u: adj[node]) {
            if (!visited[u]) {
                q.push(u);
                assignments[u]--;
                assignments[u] = max(0LL, assignments[u]);
            }
        }
        q.pop();
    }
}

void solve() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    vector <vector <int>> adj(n);
    vector <set <int>> s(n);
    vector <int> a(n);
    assignments.resize(n, m);
    assignments.assign(n, m);
    visited.resize(n, false);
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        // handle repeats?
        if (s[i].count(a[i] - 1) == 0) {
            adj[i].push_back(a[i] - 1);
            s[i].insert(a[i] - 1);
        }
        if (s[a[i] - 1].count(i) == 0) {
            adj[a[i] - 1].push_back(i);
            s[a[i] - 1].insert(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            assert((int) q.size() == 0);
            bfs(i, adj);
        }
    }
    int ans = 1;
    debug (assignments);
    for (int i = 0; i < n; i++) {
        ans *= assignments[i];
        ans %= mod;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
