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
    string s;
    cin >> s;
    for (int i = 0; i < n / 2; i++) {
        if (s[n - i - 1] < s[i]) {
            swap(s[i], s[n - i - 1]);
        }
    }
    if (is_sorted(s.begin(), s.end())) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
