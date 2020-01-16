#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n,m,ans=1; cin>>n>>m;
	ll maxpart=m/n;

	for (ll i=1; i*i<=m; i++) {
		if (m%i==0) {
			//partition gcd is either i or m/i
			if (i <= maxpart) ans = max(ans,i);
			if (m/i <= maxpart) ans = max(ans,m/i);
		}
	}

	cout << ans << endl;
	return 0;
}
