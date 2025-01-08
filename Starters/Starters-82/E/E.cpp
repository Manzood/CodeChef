#include "bits/stdc++.h"
using namespace std;
#define int long long

void dfs(int node, int p, vector <vector <int>>& adj, vector <int>& a, vector <int>& parent, vector <int>& dist, vector <int>& sum) {
    parent[node] = p;
    if (p != -1) dist[node] = dist[p] + 1;
    else dist[node] = 0;
    sum[node] += a[node];
    if (p != -1) sum[node] += sum[p];
    for (auto u: adj[node]) {
        if (u != p) {
            dfs(u, node, adj, a, parent, dist, sum);
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n, x, y;
    scanf("%lld%lld%lld", &n, &x, &y);
    x--; y--;
    vector <int> a(n);
    for (int i = 0; i < n; i++) 
        scanf("%lld", &a[i]);
    vector <vector <int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%lld%lld", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector <int> x_parent(n, -1), y_parent(n, -1), x_dist(n, 0), y_dist(n, 0);
    vector <int> x_order, y_order;
    vector <int> x_sum(n, 0), y_sum(n, 0);
    dfs(x, -1, adj, a, x_parent, x_dist, x_sum);
    dfs(y, -1, adj, a, y_parent, y_dist, y_sum);
    vector <pair <int, int>> temp;    
    for (int i = 0; i < n;i++) 
        temp.push_back({x_dist[i], i});
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n ;i++) 
        x_order.push_back(temp[i].second);
    temp.clear();
    for (int i = 0; i < n; i++) 
        temp.push_back({y_dist[i], i});
    sort(temp.begin(), temp.end());
    for (int i = 0; i < n; i++) 
        y_order.push_back(temp[i].second);
    vector <vector <int>> dp(n, vector <int>(n, 0));
    dp[x][y] = x > y;
    int f = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cur = (int) 1e18;
        while (f < n && y_dist[y_order[f]] < x_dist[x_order[i]]) f++;
        if (f == n) break;
        int s = f;
        while (s < n && y_dist[y_order[s]] == x_dist[x_order[i]]) {
            int v1 = x_order[i], v2 = y_order[s];
            if (v1 != x && v2 != y) dp[v1][v2] = dp[x_parent[v1]][y_parent[v2]] + (x_sum[v1] > y_sum[v2]);
            cur = min(cur, dp[v1][v2]);
            s++;
        }
        ans = max(ans, cur);
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
