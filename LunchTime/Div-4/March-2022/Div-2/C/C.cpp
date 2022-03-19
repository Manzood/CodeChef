#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif
const int inf = (int) 1e18;

using namespace std;
#define int long long

int frozen_count;
void bfs (vector <vector <int>>& adj, vector <bool>& frozen, int rem) {
    int n = adj.size();
    queue <int> q;
    vector <bool> visited(n, false);
    vector <int> dist(n, 0);
    for (int i = 0; i < n; i++) {
        if (frozen[i]) {
            q.push(i);
            visited[i] = true;
        }
    }
    while (!q.empty()) {
        if (frozen_count >= n) break;
        int cur = q.front();
        q.pop();
        for (auto u: adj[cur]) {
            if (!visited[u]) {
                dist[u] = dist[cur] + 1;
                if (dist[u] <= rem) {
                    q.push(u);
                    if (!frozen[u]) frozen_count++;
                    frozen[u] = true;
                }
                visited[u] = true;
            }
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n, m, q;
    scanf("%lld%lld%lld", &n, &m, &q);
    vector <vector <int>> adj(n);
    vector <bool> frozen(n, false);
    frozen_count = 0;
    // vector <int> time(n, inf);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cur_time = 0;
    for (int i = 0; i < q; i++) {
        int type, x;
        scanf("%lld%lld", &type, &x);
        if (type == 1) {
            x--;
            if (!frozen[x]) frozen_count++;
            frozen[x] = true;
            // time[x] = min(cur_time, time[x]);
        } else if (type == 2) {
            // make t units of time pass by
            int t = x;
            if (frozen_count < n) bfs(adj, frozen, t);
            cur_time += t;
        } else {
            frozen[--x] ? printf("YES\n") : printf("NO\n");
        }
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
