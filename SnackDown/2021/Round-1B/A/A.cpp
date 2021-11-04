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
        if (n > 4) {
            vector <string> ans(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    ans[i] += '.';
                }
            }
            ans[0][0] = 'Q';
            ans[n-1][n-1] = 'Q';
            for (int i = n - 3; i >= 2; i--) {
                ans[i][n - i - 1] = 'Q';
            }
            for (int i = 0; i < n; i++) {
                cout << ans[i] << "\n";
            }
        } else if (n == 4) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) {
                        if (i == 0 || i == 2) {
                            printf("Q");
                        } else {
                            printf(".");
                        }
                    } else {
                        printf(".");
                    }
                }
                printf("\n");
            }
        } else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) {
                        if (i == 1) {
                            printf("Q");
                        } else {
                            printf(".");
                        }
                    } else {
                        printf(".");
                    }
                }
                printf("\n");
            }
        }
    }
}
