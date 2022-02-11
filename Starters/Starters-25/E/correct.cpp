#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

long long po(long long x, long long n) {
    long long ans = 1;
    while (n > 0) {
        if (n & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        n /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;

    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        int a[n];

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }

        long long ans = 1;

        int vis[n] = {0};

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int cnt = 0;
                int curr = i;

                while (!vis[curr]) {
                    cnt++;
                    vis[curr] = 1;
                    curr = a[curr];
                }

                if (vis[curr] == 2) {
                    ans *= po(m - 1, cnt);
                    ans %= mod;
                } else {
                    int cyc_len = 1;
                    for (int i = a[curr]; i != curr; i = a[i]) cyc_len++;

                    long long tmp =
                        po(m - 1, cyc_len) + ((cyc_len & 1) ? -1 : 1) * (m - 1);
                    tmp %= mod;
                    ans *= tmp;
                    ans %= mod;

                    ans *= po(m - 1, cnt - cyc_len);
                    ans %= mod;
                }

                curr = i;
                while (vis[curr] != 2) {
                    vis[curr] = 2;
                    curr = a[curr];
                }
            }
        }

        ans %= mod;
        if (ans < 0) ans += mod;

        cout << ans << '\n';
    }

    return 0;
}
