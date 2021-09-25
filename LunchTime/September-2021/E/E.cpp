#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

const int inf = 1e9 + 7;

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        vector <vector <int>> lis;
        vector <vector <int>> lds;

        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        // longest increasing subsequence
        vector <int> inc;
        inc.push_back (a[0]);

        for (int i = 1; i < n; i++) {
            // the new array stores the longest increasing subsequence
            // find the index where a[i] belongs
            int ind = lower_bound(inc.begin(), inc.end(), a[i]) - inc.begin();
            if (ind != (int) inc.size()) {
                inc[ind] = a[i];
                if (ind == (int) inc.size() - 1) {
                    lis.push_back (inc);
                }
            } else {
                inc.push_back (a[i]);
                lis.clear();
                lis.push_back (inc);
            }
        }

        vector <int> decr;
        reverse(a.begin(), a.end());
        decr.push_back(a[0]);
        for (int i = 1; i < n; i++) {
            // the new array stores the longest increasing subsequence
            // find the index where a[i] belongs
            int ind = lower_bound(decr.begin(), decr.end(), a[i]) - decr.begin();
            if (ind != (int) decr.size()) {
                decr[ind] = a[i];
                if (ind == (int) inc.size() - 1) {
                    lds.push_back (decr);
                }
                for (int j = 0; j < (int) decr.size(); j++) {
                    printf("%lld ", decr[j]);
                }
                printf("\n");
            } else {
                decr.push_back (a[i]);
                lds.clear();
                lds.push_back (decr);
            }
        }

        // now we have a list of the longest increasing and decreasing subsequences


        int ans = 0;
        for (int i = 0; i < (int) lis.size(); i++) {
            for (int j = 0; j < (int) lis[i].size(); j++) {
                printf("%lld ", lis[i][j]);
            }
            printf("\n");
            for (int j = 0; j < (int) lds.size(); j++) {
                reverse(lds[j].begin(), lds[j].end());
                for (int k = 0; k < (int) lds[j].size(); k++) {
                    printf("%lld ", lds[j][k]);
                }
                printf("\n");
                vector <vector <int>> dp ((int) lis[i].size() + 1, vector <int> ((int) lds[j].size() + 1, 0));
                // compare the two sequences
                for (int k = 0; k <= (int) lis[i].size(); k++) {
                    for (int x = 0; x <= (int) lds[j].size(); x++) {
                        if (k == 0 || x == 0) {
                            dp[k][x] = 0;
                        } else if (lis[i][k-1] == lds[j][x-1]) {
                            dp[k][x] = dp[k-1][x-1] + 1;
                        } else {
                            dp[k][x] = max(dp[k-1][x], dp[k][x-1]);
                        }
                    }
                }
                ans = max (ans, dp[(int)lis[i].size()][(int)lds[j].size()]);
            }
        }

        printf("%lld\n", ans);
    }
}
