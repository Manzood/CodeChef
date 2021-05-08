#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		int n,k;
		scanf("%d%d",&n,&k);
		vector <int> a(n);
		int ans=0;
		for (int i=0;i<n;i++) {
			scanf("%d",&a[i]);
			ans+=max(0,a[i]-k);
		}
		printf("%d\n",ans);
	}
}