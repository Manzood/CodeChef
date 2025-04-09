#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

int color;
void assign_colors(int node, vector<vector<int>>& adj, int par,
                   vector<int>& colors) {
    vector<int> rem;
    for (auto u : adj[node]) {
        if (colors[u] == 0) rem.push_back(u);
    }
    for (int i = 1; i < (int)rem.size(); i += 2) {
        colors[rem[i]] = color;
        colors[rem[i - 1]] = color++;
    }
    for (auto u : adj[node]) {
        if (u != par) {
            assign_colors(u, adj, node, colors);
        }
    }
}

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> p(n, -1);
    string ans;
    vector<int> deg(n, 0);
    vector<vector<int>> adj(n);
    int even = 0;
    for (int i = 1; i < n; i++) {
        scanf("%lld", &p[i]);
        p[i]--;
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
        deg[i]++, deg[p[i]]++;
        if (deg[i] % 2 == 0)
            even++;
        else if (deg[i] > 1)
            even--;
        if (deg[p[i]] % 2 == 0)
            even++;
        else if (deg[p[i]] > 1)
            even--;
        if (even == 0)
            ans += '1';
        else
            ans += '0';
    }
    vector<int> colors(n, 0);
    colors[0] = 1, colors[1] = 1;
    cout << ans << "\n";
    if (ans.back() == '1') {
        color = 2;
        assign_colors(0, adj, -1, colors);
        for (int i = 0; i < n; i++) {
            printf("%lld ", colors[i]);
        }
        printf("\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
