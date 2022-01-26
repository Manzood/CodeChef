// #pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#define pii pair<int, int>
#define piii pair<pii, int>
#define vi vector<int>
#define vvi vector<vi>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define f first
#define s second
#define oo 1000000001
#define eb emplace_back
#define pb push_back
#define mpr make_pair
#define size(v) (int)v.size()
#define ln '\n'
#define ull unsigned long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
void solve() {
  int N;
  cin >> N;
  int P = N - 1;
  while (!isPrime(P)) --P;

  if (N % 2 == 0) {
    cout << (1ll * N * P / 2ll) << ln;
  } else {
    cout << (1ll * (N - 1) * P / 2ll + 1) << ln;
  }
}
int main() {
  ios_base::sync_with_stdio(false);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
