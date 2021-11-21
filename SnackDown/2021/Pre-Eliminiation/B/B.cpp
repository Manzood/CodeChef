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

        if (k != 1) {
            reverse(a.begin(), a.end());

            bool reached_end = false;
            vector <bool> used (n, false);

            while (!reached_end && !impossible) {
                len = 1;

                for (int i = 1; i < n; i++) {
                    if (a[i] < a[i-1]) {
                        len = 1;
                    } else {
                        len++;
                    }

                    bool found = false;
                    // debug (i, len);
                    if (len > k) {
                        bool done = false;
                        // first try replacing with something bigger at current index - 1

                        int ind = i - 1;
                        for (int j = i; j < n; j++) {
                            if (a[j] > a[ind]) {
                                // swap it in here
                                swap (a[j], a[ind]);
                                used[ind + 1] = true;
                                found = true;
                                done = true;
                                break;
                            }
                        }
                        // if that doesn't work, do the following

                        // make a swap
                        // find the first thing you can switch with g that hasn't been used so far
                        if (!done) {
                            for (int j = i - 1; j >= 0 && !found; j--) {
                                if (!used[j] && a[j] < a[i]) {
                                    // swap (a[j], a[i]);
                                    found = true;
                                    ind = j;
                                    while (a[++ind] <= a[j]);
                                    swap (a[ind], a[j]);
                                    used[j] = true;               // maybe used[j]?
                                    // break;
                                }
                            }
                        }

                        if (!found) impossible = true;
                    }

                    if (found) break;

                    if (i == n - 1) {
                        reached_end = true;
                    }

                    // debug (i, a);
                }
            }
        }

        if (impossible == true) {
            printf("-1\n");
            continue;
        }

        for (int i = 0; i < n; i++) {
            printf("%lld ", a[i]);
        }
        printf("\n");
    }
}
