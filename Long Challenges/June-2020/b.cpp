#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout<<#x<<" = "<<x<<endl;

int main() {
	int t;
	cin>>t;
	while (t--) {
		string s;
		cin>>s;
		int ans=0;
		int i=0;
		while (i<s.size()-1) {
			if ((s[i]=='x' || s[i]=='y') && (s[i]!=s[i+1])) {
				ans++;
				i+=2;
			}
			else {
				i++;
			}
		}
		printf("%d\n",ans);
	}
}