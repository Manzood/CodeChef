#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        scanf("%d%d", &n, &d);
        int atrisk = 0;
        int others = 0;
        for (int i = 0; i < n; i++) {
            int temp; scanf("%d", &temp);
            if (temp <= 9 || temp >= 80) {
                atrisk++;
            } else {
                others++;
            }
        }
        int ans = (others + d - 1) / d;
        ans += (atrisk + d - 1) / d;
        printf("%d\n", ans);
    }
}