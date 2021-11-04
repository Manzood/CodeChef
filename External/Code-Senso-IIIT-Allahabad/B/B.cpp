#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        string s;
        cin >> s;
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) {
                cnt++;
            }
        }
        n = cnt;
        vector <int> state(n, 0);
        state[0] = 1;
        state[1] = 0;
        for (int i = 2; i < n; i++) {
            if (state[i-1] == 0 || state[i-2] == 0) {
                state[i] = 1;
            }
        }
        if (state[n-1] == 1) {
            printf("SAHID\n");
        } else {
            printf("RAMADHIR\n");
        }
    }
}
