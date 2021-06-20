#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int ans;

pair <int, int> dfs (int node, vector <vector <int>>& adj, string& s) {
    // returns depth of the deepest token
    pair <int, int> current = {0, 0};
    for (auto u: adj[node]) {
        pair <int, int> temp = dfs (u, adj, s);
        if (temp.first > current.first) {
            current = temp;
        } else if (temp.first == current.first) {
            current.second += temp.second;
        }
    }
    if (s[node] == '1') {
        current.first++;
        if (current.second == 0) current.second++;
    } else {
        // debug (node);
        // debug (current.first);
        ans += current.first;
        if (current.second > 1) {
            current.second--;
            current.first++;
        }
    }
    return current;
}

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        int n;
        scanf("%lld", &n);
        string s;
        cin >> s;
        vector <vector <int>> adj(n);
        for (int i = 0; i < n - 1; i++) {
            int p;
            scanf("%lld", &p);
            adj[--p].push_back (i + 1);
        }
        dfs (0, adj, s);
        printf("%lld\n", ans);
    }
}
