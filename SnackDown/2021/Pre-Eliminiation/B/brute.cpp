#include "bits/stdc++.h"

#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif

using namespace std;
#define int long long

bool compare_arrays (vector <int> a, vector <int> b) {
    // returns a <= b
    int n = a.size();
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            return false;
        } else if (a[i] < b[i]) {
            return true;
        }
    }
    return true;
}

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        scanf("%lld%lld", &n, &k);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }

        // check for impossibility
        sort (a.begin(), a.end());
        reverse (a.begin(), a.end());

        int len = 1;
        bool impossible = false;
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i-1]) {
                len = 1;
            } else {
                len++;
            }
            if (len > k) {
                impossible = true;
            }
        }

        if (impossible == true) {
            printf("-1\n");
            continue;
        }

        // check all permutations for best possible answer
        vector <int> ans = a;
        reverse (a.begin(), a.end());
        do {
            bool correct = true;
            len = 1;
            for (int i = 1; i < n; i++) {
                if (a[i] < a[i-1]) {
                    len = 1;
                } else {
                    len++;
                }
                if (len > k) {
                    correct = false;
                }
            }

            if (correct) {
                if (compare_arrays (ans, a) == false) {
                    ans = a;
                }
            }

        } while (next_permutation(a.begin(), a.end()));

        for (int i = 0; i < n; i++) {
            printf("%lld ", ans[i]);
        }
        printf("\n");
    }
}
