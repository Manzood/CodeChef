#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long
const int mod = 1e9 + 7;

int logic_for_four (int ind, vector <int>& a) {
    int retval = 1;
    int n = a.size();

    // test with 3 first
    int val = 1;
    set <int> temp;
    for (int i = ind; i < n; i++) {
        // taking 3
        temp.insert(a[i]);
        if (temp.size() == 3) {
            temp.clear();
            val *= 3;
        }
    }
    if ((int) temp.size() > 1) val *= (int) temp.size();
    retval = max (retval, val);

    val = 1;
    temp.clear();
    // consider taking 2
    // and then everything else
    int ind2 = n;
    for (int i = ind; i < n; i++) {
        temp.insert(a[i]);
        if (temp.size() == 2) {
            temp.clear();
            val *= 2;
            ind2 = i + 1;
            break;
        }
    }
    for (int i = ind2; i < n; i++) {
        temp.insert(a[i]);
    }
    if ((int) temp.size() > 1) val *= (int) temp.size();
    retval = max (retval, val);

    val = 1;
    temp.clear();
    // take 2
    // take 2 again
    // then see
    for (int i = ind; i < n; i++) {
        temp.insert(a[i]);
        if (temp.size() == 2) {
            temp.clear();
            val *= 2;
            break;
        }
    }
    retval = max(retval, val);

    return retval;
}

int32_t main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        scanf("%lld", &n);
        vector <int> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        // find the point where there's only 4 remaining

        set <int> temp;
        int ind = n;
        for (int i = n - 1; i >= 0; i--) {
            temp.insert(a[i]);
            ind = i;
            if (temp.size() == 5) {
                break;
            }
        }

        int ans = 1;
        int cnt = 0;
        temp.clear();
        int v1 = 1, v2 = 1;

        for (int i = 0; i < n; i++) {
            // if I have not finished a third by the time I reach ind, continue as if nothing happened
            // otherwise use logic for 4
            if (i >= ind) {
                if (i == ind) {
                    v1 = ans;
                    cnt = temp.size();
                    if (cnt > 1) v1 *= cnt;
                    // debug (cnt);
                    // if (cnt == 0) {
                        // use logic for 4
                        int val = logic_for_four(ind, a);
                        v2 *= val;
                        v2 %= mod;
                        break;
                    // }
                }
                temp.insert(a[i]);

                if (temp.size() == 3) {
                    temp.clear();
                    ans *= 3;
                    ans %= mod;
                }
            }
            temp.insert(a[i]);

            if (temp.size() == 3) {
                temp.clear();
                ans *= 3;
                ans %= mod;
            }
        }

        if (temp.size() >= 2) {
            ans *= (int) temp.size();
            ans %= mod;
        }

        // debug (v1);
        // debug (v2);
        ans = max (ans, v1 * v2);

        printf("%lld\n", ans);
    }
}
