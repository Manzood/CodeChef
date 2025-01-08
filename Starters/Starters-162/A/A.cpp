#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    if (k == 1 || (n % k == 1 && k == 2)) {
        printf("-1\n");
        return;
    }
    vector<int> a(n);
    for (int i = 0; i < n - 1; i++) {
        a[i] = i + 2;
    }
    a[n - 1] = 1;
    if (n % k == 1) {
        swap(a[1], a[n - 1]);
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", a[i]);
    }
    printf("\n");
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
