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
        int n = s.size();
        string ans;
        if (s[0] == '1') {
            for (int i = 0; i < n; i++) {
                ans += s[i];
                if (i == 0) ans += '0';
            }
        } else {
            ans = "1";
            ans += s;
        }
        cout << ans << "\n";
    }
}
