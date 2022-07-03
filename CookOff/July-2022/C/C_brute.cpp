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
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &l[i], &r[i]);
    }
    vector<int> thieves;
    for (int i = 0; i < n; i++) {
        // person i is the thief
        bool thief = true;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (l[j] > i + 1 || r[j] < i + 1) thief = false;
        }
        // must point elsewhere, therefore lie
        if (l[i] <= i + 1 && r[i] >= i + 1) thief = false;
        if (thief) thieves.push_back(i);
    }
    printf("%lld\n", (int)thieves.size());
    for (int i = 0; i < (int)thieves.size(); i++) {
        printf("%lld\n", thieves[i] + 1);
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
