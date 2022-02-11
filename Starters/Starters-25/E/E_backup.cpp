#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

const int mod = (int)1e9 + 7;

// find the length of a cycle
struct solver {
    vector<bool> visited;
    vector<bool> visiting;
    vector<int> component_pos;
    int ans = 1;
    int test_num;
    pair <int, int> dfs(int node, vector<vector<int>>& adj, int dist, vector <vector <int>>& dp) {
        visited[node] = true;
        visiting[node] = true;
        component_pos[node] = dist;
        pair <int, int> cnt = {1, 0};
        for (auto u : adj[node]) {
            if (test_num == 3) {
                debug (node + 1, u + 1);
            }
            if (visiting[u]) {
                // cycle detected
                // get the answer for the distance of the cycle
                int len = dist - component_pos[u];
                cnt.second = len + 1;
                if (test_num == 3) {
                    // debug (len);
                }
                ans *= dp[len][0];
                ans %= mod;
                visiting[u] = false;
            }
            if (!visited[u]) {
                pair <int, int> temp = dfs (u, adj, dist + 1, dp);
                cnt.first += temp.first;
                cnt.second = max(temp.second, cnt.second);
            }
        }
        visiting[node] = false;
        return cnt;
    }

    void solve([[maybe_unused]] int test) {
        int n, m;
        scanf("%lld%lld", &n, &m);
        ans = 1;
        test_num = test;
        vector<int> a(n);
        vector<vector<int>> adj(n);
        vector <vector <int>> dp (n + 1, vector <int> (2, 0));
        vector <set <int>> s(n);
        visited.resize(n, false);
        visiting.resize(n, false);
        component_pos.resize(n, 0);
        dp[0][0] = 0;
        dp[0][1] = m;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = ((m - 1) * dp[i-1][1] % mod) + ((m - 2) * dp[i-1][0] % mod);
            dp[i][1] = dp[i-1][0];
        }
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            // handle repeats?
            // lambda might be better in this case
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
                pair<int, int> temp = dfs(i, adj, 0, dp);
                int diff = temp.first - temp.second;
                // if (test == 3) debug (temp.first, temp.second);
                for (int j = 0; j < diff; j++) {
                    ans *= (m - 1);
                    ans %= mod;
                }
            }
        }
        printf("%lld\n", ans);
    }
};

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solver sol;
        sol.solve(tt);
    }
}
