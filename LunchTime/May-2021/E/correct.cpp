#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#endif

long long readInt(long long l,long long r,char endd){
	long long x=0;
	int cnt=0;
	int fi=-1;
	bool is_neg=false;
	while(true){
		char g=getchar();
		if(g=='-'){
			assert(fi==-1);
			is_neg=true;
			continue;
		}
		if('0'<=g && g<='9'){
			x*=10;
			x+=g-'0';
			if(cnt==0){
				fi=g-'0';
			}
			cnt++;
			assert(fi!=0 || cnt==1);
			assert(fi!=0 || is_neg==false);

			assert(!(cnt>19 || ( cnt==19 && fi>1) ));
		} else if(g==endd){
			if(is_neg){
				x= -x;
			}
			if(!(l<=x && x<=r))cerr<<l<<"<="<<x<<"<="<<r<<endl;
			assert(l<=x && x<=r);
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(int l,int r,char endd, char minc = 'a', char maxc = 'z'){
	string ret="";
	int cnt=0;
	while(true){
		char g=getchar();
		assert(g!=-1);
		if(g==endd){
			break;
		}
		assert(g >= minc && g <= maxc);
		cnt++;
		ret+=g;
	}
	assert(l<=cnt && cnt<=r);
	return ret;
}
long long readIntSp(long long l,long long r){
	return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
	return readInt(l,r,'\n');
}
string readStringLn(int l,int r, char minc = 'a', char maxc = 'z'){
	return readString(l,r,'\n', minc, maxc);
}
string readStringSp(int l,int r, char minc = 'a', char maxc = 'z'){
	return readString(l,r,' ', minc, maxc);
}
template<class T>
vector<T> readVector(int n, long long l, long long r){
    vector<T> ret(n);
    for(int i = 0; i < n; i++){
        ret[i] = i == n - 1 ? readIntLn(l, r) : readIntSp(l, r);
    }
    return ret;
}

template<class T>
struct segtree{
	int n;
	vector<T> t, A;
	T def;
	inline T combine(T a, T b){
		if(a == -1) return b;
		if(b == -1) return a;
		return A[a] > A[b] ? a : b;
	}
	segtree(vector<T> inp) : n(sz(inp)), A(inp), def(-1){
		t.resize(2 * n, def);
		for(int i = 0; i < n; i++) t[n + i] = i;
		for(int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
	}

	void modify(int p, T value) { // modify A[p] = value
		// value = combine(value, t[p + n]); // if a[p] = combine(a[p], value)
		A[p] = value;
		for (p += n; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
	}

	T query(int l, int r) {  // compute on interval [l, r]
    	r++;
		T resl = def, resr = def;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l&1) resl = combine(resl, t[l++]);
			if (r&1) resr = combine(t[--r], resr);
		}
		return combine(resl, resr);
	}
};

long long get(int n, vector<int> par, string type){
	vector<vector<int>> children(n);
	for(int i = 1; i < n; i++){
		assert(par[i] >= 0 && par[i] < i);
		children[par[i]].push_back(i);
	}
	vector<int> depth(n, 1);
	long long sum = (type[0] - '0');
	for(int i = 1; i < n; i++){
		depth[i] = depth[par[i]] + 1;
		sum += (type[i] - '0') * depth[i];
	}
	vector<int> st(n), en(n);
	stack<int> stk;
	stk.push(0);
	int timer = 0;
	while(!stk.empty()){
		int s = stk.top(); stk.pop();
		st[s] = timer++;
		for(int v : children[s]) stk.push(v);
	}
	for(int s = n - 1; s >= 0; s--){
		en[s] = st[s];
		reverse(all(children[s]));
		for(int v : children[s]) en[s] = en[v];
	}
	segtree<int> stree(vector<int>(n, 0));
	for(int s = n - 1; s >= 0; s--){
		stree.modify(st[s], depth[s]);
		sum -= depth[s];
		if(type[s] == '0'){
			int u = stree.query(st[s], en[s]);
			sum += stree.A[u];
			stree.modify(u, 0);
		}
	}
	return sum;
}


const int SN = 1000000;
int main(){
	int t = readIntLn(1, SN);
	int sn = 0;
	while(t--){
		int n = readIntLn(1, SN);
		sn += n;
		assert(sn <= SN);
		string type = readStringLn(n, n, '0', '1');
        vector<int> par = readVector<int>(n - 1, 0, n);
		reverse(all(par)); par.push_back(0); reverse(all(par));
        for(int i = 1; i < n; i++){
            par[i]--;
        }
		cout << get(n, par, type) << endl;
	}
}
