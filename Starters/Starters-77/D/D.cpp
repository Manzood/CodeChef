#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<int> a(n);
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        b[i] = {a[i], i};
    }
    sort(b.begin(), b.end());
    vector<int> want(n, -1);
    for (int i = 0; i < n; i++) {
        want[b[i].second] = i;
    }
    vector<int> color(n, -1), len(n, 0);
    vector<bool> visited(n, false);
    int colors = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int cur = i;
            int cnt = 0;
            while (!visited[cur]) {
                cnt++;
                visited[cur] = true;
                color[cur] = colors;
                cur = want[cur];
            }
            len[colors] = cnt;
            ++colors;
        }
        assert(color[i] != -1 && color[i] <= n);
    }
    vector<vector<int>> ans;
    vector<int> chosen;
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (len[color[i]] == 1) {
                visited[i] = true;
                continue;
            }
            vector<int> cycle;
            int cur = i;
            while (!visited[cur]) {
                visited[cur] = true;
                cycle.push_back(cur);
                cur = want[cur];
            }
            for (auto x : cycle) {
                chosen.push_back(x);
                ans.push_back(cycle);
            }
            chosen.push_back(i);
            ans.push_back(cycle);
        }
    }
    printf("%lld\n", (int)ans.size());
    assert((int)ans.size() <= (3 * n + 1) / 2);
    for (int i = 0; i < (int)ans.size(); i++) {
        printf("%lld %lld\n", chosen[i] + 1, (int)ans[i].size());
        assert((int)ans[i].size() > 0);
        assert((int)ans[i].size() <= n);
        int val = 0;
        for (auto x : ans[i]) {
            printf("%lld ", x + 1);
            val ^= a[x];
        }
        printf("\n");
        a[chosen[i]] = val;
        // for (auto x : a) {
        //     printf("%lld ", x);
        // }
        // printf("\n");
    }
    for (int i = 0; i < n; i++) {
        assert(a[i] == b[i].first);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
