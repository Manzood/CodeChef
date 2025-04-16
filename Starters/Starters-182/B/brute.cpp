#include "bits/stdc++.h"

#ifdef local
#include "custom/debugger.h"
#else
#define debug(...) 42;
#endif

using namespace std;
#define int long long

bool check(string& s, int k) {
    int n = (int)s.size();
    int len = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1])
            len++;
        else {
            len = 1;
        }
        if (len >= k) return false;
    }
    return true;
}

void solve([[maybe_unused]] int test) {
    int n, k;
    scanf("%lld%lld", &n, &k);
    string s;
    cin >> s;
    if (check(s, k)) {
        printf("YES\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string cpy;
            for (int x = 0; x < i; x++) cpy += s[x];
            for (int x = j; x >= i; x--) cpy += s[x];
            for (int x = j + 1; x < n; x++) cpy += s[x];
            if (check(cpy, k)) {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
}

int32_t main() {
    int t = 1;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
