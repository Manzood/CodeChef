#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

constexpr int INF = (int)1e9 + 7;

void solve([[maybe_unused]] int test) {
    int n;
    scanf("%lld", &n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i].second);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i].first);
    }
    vector<int> ans(n, 0), smallest(n, -1);
    sort(a.begin(), a.end());
    int s = INF, ind = -1;
    for (int i = n - 1; i >= 0; i--) {
        smallest[i] = ind;
        if (a[i].second < s) {
            s = a[i].second;
            ind = i;
        }
    }
    int best = 0;
    for (int i = n - 1; i >= 0; i--) {
        int x = smallest[i];
        if (x != -1 && a[x].second < a[i].first) {
            ans[i] = ans[x] + 1;
        }
        best = max(best, ans[i]);
    }
    printf("%lld\n", best);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
