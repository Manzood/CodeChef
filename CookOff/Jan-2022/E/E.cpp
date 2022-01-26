#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long
constexpr int MAX_N = (int)1e5 + 1;

vector<bool> is_prime(MAX_N, true);
vector<int> last_prime(MAX_N, -1);
void precompute() {
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i < MAX_N; i++) {
        for (int j = 2 * i; j < MAX_N; j += i) {
            is_prime[j] = false;
        }
    }
    int l = -1;
    for (int i = 0; i < MAX_N; i++) {
        if (is_prime[i]) l = i;
        last_prime[i] = l;
    }
}

void solve() {
    int n;
    scanf("%lld", &n);
    int original = n;
    int ans = 0;
    int components = 0;
    while (n) {
        int last = last_prime[n - 1];
        if (components > 0 && n > 3) last = last_prime[n-3];
        // debug (n, last);
        if (n >= 2) {
            int v1 = ((last) * (last + 1)) / 2;
            // each edge can be doubled until the original last prime
            int olp = last_prime[original-1];
            olp *= n / 2;
            if (olp > v1) {
                ans += olp;
                if (n % 2 == 1) ans ++;
                // subtract something else instead of breaking
                break;
            } else {
                ans += v1;
                n -= last + 1;
            }
        } else {
            ans += 2;
            n -= last + 1;
        }
        if (components > 0) {
            ans--;
        }
        components++;
    }
    printf("%lld\n", ans);
}

int32_t main() {
    int t = 1;
    cin >> t;
    precompute();
    last_prime[1] = 1;
    last_prime[0] = 0;
    // debug (is_prime);
    for (int tt = 1; tt <= t; tt++) {
        solve();
    }
}
