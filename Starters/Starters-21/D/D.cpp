#include "bits/stdc++.h"
#ifdef local
    #include "custom/debugger.h"
#else
    #define debug(x) 42;
#endif
using namespace std;
#define int long long

void solve() {
    int n;
    scanf("%lld", &n);
    vector <int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    sort (a.begin(), a.end());
    int ans = 0;
    int mean = (int) ((double) sum / (double) n); // typecasting could be a source of error, look into it later
    int ind = n / 2;
    if (n % 2 == 0) ind--;
    int cnt = 1;

    int target = mean;
    if (sum % n != 0) target++;

    // first handle mean > median case
    while (target > a[ind]) {
        // compare to a[ind + cnt]
        int diff = a[ind + cnt] - a[ind];
        int new_mean = (int) ((double) (sum + diff * cnt) / (double) n);
        // if ((sum + diff * cnt) % n != 0) new_mean++;
        if (new_mean < a[ind + cnt]) {
            // overshooting, break
            break;
        }
        sum += diff * cnt;
        ans += diff * cnt;
        a[ind] += diff;
        cnt++;
        mean = (int) ((double) sum / (double) n);
        target = mean;
        if (sum % n != 0) target++;
    }

    // handle overshooting
    target = mean;
    if (sum % n != 0) target++;

    // debug (target);
    if (a[ind] < target) {
        int inc = (sum - a[ind] * n) / (n - cnt);
        if ((sum - a[ind] * n) % (n - cnt) != 0) inc++;
        a[ind] += inc;
        ans += inc * cnt;
        mean = (int) ((double) (sum + (inc * cnt)) / (double) n);
        sum += (inc * cnt);
        target = mean;
        if (sum % n != 0) target++;
    }
    // debug (a[ind], sum);

    target = mean;
    if (sum % n != 0) target++;

    while (a[ind] < target) {
        a[ind]++;
        sum += cnt;
        ans += cnt;
        mean = (int) ((double) sum / (double) n);
        target = mean;
        if (sum % n != 0) target++;
    }
    // debug (a[ind], sum);

    // final step, just increase mean until it reaches median
    ans += (a[ind] * n) - sum;
    printf("%lld\n", ans);
}

int32_t main () {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
