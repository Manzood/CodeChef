#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();

        map <vector <int>, int> mp;

        // go through each substring
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i + j < n; j++) {
                vector <int> occurances(26, 0);
                for (int k = i; k <= i + j; k++) {
                    occurances[s[k] - 'a']++;
                }
                ans += mp[occurances];
                mp[occurances]++;
            }
        }

        printf("%lld\n", ans);
    }
}
