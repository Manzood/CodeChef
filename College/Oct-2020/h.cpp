#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cout << #x << " = " << x << endl;

int32_t main(void) {
    int t; cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        int sum = 0;
        for (int i = 1; i*i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                if (i > 1 && n/i != i) sum += n/i;
            }
            debug(sum);
        }
        if (sum == n) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
