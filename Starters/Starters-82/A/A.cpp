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
    vector<vector<int>> a(n, vector<int>(n));
    int cur = 1;
    int x = 0, y = 0;
    while (cur <= n * n) {
        a[x][y] = cur;
        cur += 2;
        x++;
        if (x == n) {
            x = 0;
            y++;
        }
    }
    cur = 2;
    while (cur <= n * n) {
        a[x][y] = cur;
        cur += 2;
        x++;
        if (x == n) {
            x = 0;
            y++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%lld ", a[i][j]);
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
