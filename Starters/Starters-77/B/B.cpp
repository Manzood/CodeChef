#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

void solve([[maybe_unused]] int test) {
    int a, b, c;
    vector<int> A(3);
    scanf("%lld%lld%lld", &A[0], &A[1], &A[2]);
    sort(A.begin(), A.end());
    a = A[0];
    b = A[1];
    c = A[2];
    bool possible = true;
    if (abs(b - a) % 2 == 1) possible = false;
    if (abs(c - a) % 2 == 1) possible = false;
    int ans = abs(b - a) / 2;
    ans += abs(c - a) / 2;
    if (!possible) ans = -1;
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
