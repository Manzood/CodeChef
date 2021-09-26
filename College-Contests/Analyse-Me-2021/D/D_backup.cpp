#include "bits/stdc++.h"
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
#define int long long

int32_t main () {
    int n, p;
    scanf("%lld%lld", &n, &p);
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    // you can pick at most 1000 items?
    int ansk = 0;
    int ansc = 0;

    int k = min(1000LL, n);
    vector <pair <int, int>> values (n);

    for (int i = 0; i < n; i++) {
        values[i].first = a[i] + (i + 1) * k;
        values[i].second = i;
    }

    sort(values.begin(), values.end());
    vector <int> current_set (k);
    vector <bool> used(k, true);
    int cost = 0;
    for (int i = 0; i < k; i++) {
        current_set[i] = values[i].second;
        cost += values[i].first;
    }

    int cnt = k;
    while (cost > p) {
        // we drop the item that would be most damaging next round
        vector <pair <int, int>> temp;
        for (int i = 0; i < k; i++) {
            if (used[i]) {
                // append to new array
                int index = values[i].second;
                temp.push_back({a[index] + (index + 1) * (k - 1), index});
            }
        }
        sort (temp.begin(), temp.end());
        // remove the one at the end
        used[temp.back().second] = false;
        temp.pop_back();
        cost = 0;
        for (auto t: temp) {
            cost += t.first;
        }

        cnt--;
    }

    ansk = cnt;
    ansc = cost;

    printf("%lld %lld\n", ansk, ansc);
}

