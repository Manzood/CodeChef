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
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    bool Awin = false;
    for (int i = n - 1; i >= 0; i--) {
        if (cnt[a[i]] & 1) {
            Awin = true;
        }
    }
    Awin ? printf("Marichka\n") : printf("Zenyk\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
