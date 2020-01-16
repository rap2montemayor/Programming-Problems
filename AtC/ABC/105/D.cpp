#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll mod = 1e9+7;

int main() {
	ll n,m; cin>>n>>m;
	vector<ll> a(n);
	map<ll,ll> rem;

	rem[0]=1;
	ll sum=0, ans=0;
	for (ll i=0; i<n; i++) {
		cin>>a[i];

		sum = sum+a[i];
		rem[sum%m]++;

		ans += rem[sum%m]-1;
		ans %= mod;
	}
	
	cout << ans << endl;
	return 0;
}
