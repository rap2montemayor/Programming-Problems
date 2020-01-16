#include <bits/stdc++.h>
using namespace std;

char s[1000005];
int main() {
	int t; cin>>t;
	while (t--) {
		int n,k; cin>>n>>k;
		cin>>s;

		int moves=0, sorted=0;
		for (int i=0; i<n; i++) {
			if (moves>=k) break;
			
			if (s[i]=='0') {
				if (moves+i-sorted <= k) {
					s[i]='1';
					s[sorted]='0';
					moves+=i-sorted;
				}
				else {
					s[i]='1';
					s[i-k+moves]='0';
					moves=k;	
				}
				sorted++;
			}
		}
		cout << s << endl;
	}
	return 0;
}
