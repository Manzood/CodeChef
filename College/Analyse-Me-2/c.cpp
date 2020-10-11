#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;
#define sz(x) (int) (x).size()

string t;
string s;

void make(int start, int end, int cur, int n) {
    // if (cur == n) return;
    if (start > end) return;
    int mid = (start + end)/2;
    t += s[mid];
    make(start, mid-1, ++cur, n);
    make(mid+1, end, ++cur, n);
}

int main() {
    int tests = 1;
    cin >> tests;
    while (tests--) {
        int n;
        scanf("%d", &n);
        cin >> s;
        t = "";
        make(0, n-1, 0, n);
        cout << t << "\n";
    }
}