#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool inside = false;
        int ans = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            if (!inside && s[i] == '1') {
                inside = true;
                ans++;
            } else if (s[i] == '0') {
                inside = false;
            }
        }
        printf("%lld\n", ans);
    }
}
