#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        // starting without binary search
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        int ans = 0;

        for (int i = 0; i + 2 < n; i++) {
            int val = 0;
            val += (a[i+2] - a[i+1]) * (a[i+1] - a[i]);
            // int mid = a[i+1];
            // int mid_ind = i + 1;
            int largest = a[i+2];
            int smallest = a[i];

            ans += val;

            for (int j = i + 3; j < n; j++) {
                largest = a[j];
                // val = (largest - a[mid_ind]) * (a[mid_ind] - smallest);
                // binary search
                int ind = lower_bound(a.begin() + i + 1, a.begin() + j - 1, (smallest + largest) / 2) - a.begin();
                val = (largest - a[ind]) * (a[ind] - smallest);
                if (ind - 1 > i) {
                    val = max ((largest - a[ind - 1]) * (a[ind - 1] - smallest), val);
                }
                ans += val;
            }
        }

        printf("%lld\n", ans);
    }
}
