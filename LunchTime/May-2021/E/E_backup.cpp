#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        string s;
        cin >> s;
        vector <vector <int>> adj(n);
        vector <int> parent(n);
        for (int i = 0; i < n - 1; i++) {
            int p;
            scanf("%lld", &p);
            p--;
            adj[p].push_back (i + 1);
            parent[i + 1] = p;
        }
        parent[0] = -1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                int moves = 0;
                int tokens = 0;
                int cur = i;
                int lastzero = cur;
                s[cur] = '0';
                while (parent[cur] != -1) {
                    moves++;
                    cur = parent[cur];
                    if (s[cur] == '1') tokens++;
                    if (s[cur] == '0') lastzero = cur;
                }
                s[lastzero] = '1';
                ans += moves - tokens;
            }
        }
        printf("%lld\n", ans);
    }
}
