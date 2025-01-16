// #include <bits/allocator.h>
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "bits/stdc++.h"
#include "custom/debugger.h"
using namespace std;
using ll = long long int;
mt19937_64 RNG(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (ll &x : a) cin >> x;
        vector<array<int, 60>> pref(n + 1);
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i];
            for (int b = 0; b < 60; ++b) pref[i + 1][b] += (a[i] >> b) & 1;
        }

        ll ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int b = 0; i + (1 << b) - 1 < n; ++b) {
                auto check = [&](int L, int R) {
                    bool good = true;
                    for (int b2 = b + 1; b2 < 60; ++b2) {
                        int x = (a[i] >> b2) & 1;
                        int y = pref[R][b2] - pref[L][b2];
                        if (x == 0)
                            good &= y == 0;
                        else
                            good &= y == (R - L);
                    }
                    return good;
                };

                int L = i - 1 + (1 << b);
                int R = min(n, L + (1 << b));
                // [L, R)

                if (check(L, R)) {
                    ans += R - L;
                    continue;
                }

                int lo = L - 1, hi = R - 1;
                while (lo < hi) {
                    int mid = (lo + hi) / 2;
                    if (check(lo, mid + 1)) {
                        lo = mid + 1;
                    } else {
                        hi = mid;
                    }
                }
                ans += hi - L;
                break;
            }
        }
        cout << ans << '\n';
    }
}
