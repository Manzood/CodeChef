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
    string s, t;
    if (k < n / 2) {
        printf("-1\n");
        return;
    }
    int rem = k;
    int cur = -1;
    for (int i = 0; rem > (n - i) / 2 && i < n; i++) {
        cur = i;
        if (i & 1) {
            s += 'C';
            t += 'C';
        } else {
            s += 'B';
            t += 'B';
        }
        rem--;
    }
    cur++;
    for (int i = cur; i < n; i++) {
        if (cur & 1) {
            // start from A
            if (i & 1)
                s += 'A';
            else
                s += 'B';
        } else {
            // start from B
            if (i & 1)
                s += 'A';
            else
                s += 'B';
        }
    }
    for (int i = cur; i < n; i++) {
        if (cur & 1) {
            // start from C
            if (i & 1)
                t += 'C';
            else
                t += 'A';
        } else {
            // start from A
            if (i & 1)
                t += 'C';
            else
                t += 'A';
        }
    }
    cout << s << "\n" << t << "\n";
}

int32_t main() {
    int t = 1;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        solve(tt);
    }
}
