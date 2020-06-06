#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		long long tom, temp;
		scanf("%lld",&tom);
		temp=tom;
		int count=0;
		while (tom%2==0) {
			tom/=2;
			count++;
		}
		long long val=1;
		for (int i=0;i<count+1;i++) {
			val*=2;
		}
		long long ans=temp/val;
		printf("%lld\n",ans);
	}
}