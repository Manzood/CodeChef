#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            sum += a[i];
        }
        bool ans = true;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            if (a[i] > i + 1) ans = false;
        }
        int val = (n * (n + 1)) / 2;
        if (sum > val) ans = false;
        else if ((val - sum) % 2 == 0) ans = false;
        ans ? printf("First\n") : printf("Second\n");
    }
}
