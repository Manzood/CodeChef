#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

// the number of prime factors of m
int get_prime_count (int n) {
    int cnt = 0;
    // vector <int> factors;
    while (n % 2 == 0) {
        cnt = 1;
        // factors.push_back (2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            // factors.push_back (i);
            cnt++;
        }
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n > 1) {
        // factors.push_back (n);
        cnt++;
    }
    // debug (factors);
    return cnt;
}

void solve() {
    int n, m;
    scanf("%lld%lld", &n, &m);
    int ans = get_prime_count(m);
    // debug (n, ans);
    while (ans >= 1 && n % ans != 0) {
        ans--;
    }
    printf("%lld\n", ans);
}

int32_t main () {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
