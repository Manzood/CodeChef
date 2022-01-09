#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    int found = 0;
    char c;
    for (int i = 0; i < n; i++) {
        cout << found + 1 << endl;
        cin >> c;
        if (c == '1') found++;
    }
}

int32_t main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
