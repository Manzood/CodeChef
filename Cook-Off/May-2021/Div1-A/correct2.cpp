#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <random>
#include <limits>
#include <functional>

#ifdef HOME
    #define NOMINMAX
    #include <windows.h>
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

template<class T> bool umin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool umax(T &a, T b) { return a < b ? (a = b, true) : false; }

using namespace std;

long long readInt(long long l, long long r, char endd) {
    long long x = 0;
    int cnt = 0;
    int fi = -1;
    bool is_neg = false;
    while (true) {
	    char g = getchar();
	    if (g == '-') {
		    assert(fi == -1);
		    is_neg = true;
		    continue;
	    }
	    if ('0' <= g && g <= '9') {
		    x *= 10;
		    x += g - '0';
		    if (cnt == 0) {
			    fi = g - '0';
		    }
		    cnt++;
		    assert(fi != 0 || cnt == 1);
		    assert(fi != 0 || is_neg == false);

		    assert(!(cnt > 19 || (cnt == 19 && fi > 1)));
	    }
	    else if (g == endd) {
		    assert(cnt > 0);
		    if (is_neg) {
			    x = -x;
		    }
		    assert(l <= x && x <= r);
		    return x;
	    }
	    else {
		    assert(false);
	    }
    }
}

string readString(int l, int r, char endd) {
    string ret = "";
    int cnt = 0;
    while (true) {
	    char g = getchar();
	    assert(g != -1);
	    if (g == endd) {
		    break;
	    }
	    cnt++;
	    ret += g;
    }
    assert(l <= cnt && cnt <= r);
    return ret;
}
long long readIntSp(long long l, long long r) {
    return readInt(l, r, ' ');
}
long long readIntLn(long long l, long long r) {
    return readInt(l, r, '\n');
}
string readStringLn(int l, int r) {
    return readString(l, r, '\n');
}
string readStringSp(int l, int r) {
    return readString(l, r, ' ');
}

uint32_t lzCount(uint64_t v)
{
#ifdef WIN32
    return static_cast<uint32_t>(__lzcnt64(v));
#else
    return __builtin_clzll(v);
#endif
}


int main(int argc, char** argv)
{
#ifdef HOME
    if(IsDebuggerPresent())
    {
	    freopen("../in.txt", "rb", stdin);
	    freopen("../out.txt", "wb", stdout);
    }
#endif
    int T = readIntLn(1, 100'000);

    forn(tc, T)
    {
	    int64_t X = readIntSp(1, 1'000'000'000'000'000'000ll);
	    int64_t Y = readIntLn(1, 1'000'000'000'000'000'000ll);
	    if (Y % X)
	    {
		    printf("-1\n");
		    continue;
	    }
	    Y /= X;
	    int64_t lv = numeric_limits<int64_t>::max();
	    int32_t res = 0;
	    while (Y)
	    {
		    uint32_t lzc = lzCount(Y);
		    int64_t val = (1ll << (64 - lzc)) - 1;
		    if (val > Y)
		    {
			    val = (1ll << (63 - lzc)) - 1;
			    res += 64 - lzc;
		    }
		    else
			    res += 65 - lzc;

		    if(lv == val)
		    {
			    res = 0;
			    break;
		    }
		    Y -= val;
		    lv = val;
	    }
	    --res;
	    printf("%d\n", res);
    }
    // assert(getchar() == -1);
    return 0;
}
