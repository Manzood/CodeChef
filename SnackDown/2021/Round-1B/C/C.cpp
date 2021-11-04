#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int k;
        scanf("%lld", &k);
        vector <int> t1, t2;
        int ans = 0;
        k *= 2;
        // debug (k);
        k--;
        int start = 0, end = k;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (mid * mid + mid == k) {
                ans = mid;
                break;
            }
            if (mid * mid + mid < k) {
                start = mid + 1;
                ans = mid;
            } else {
                end = mid - 1;
            }
        }
        printf("%lld\n", (2 * ans) + 2);
    }
}
