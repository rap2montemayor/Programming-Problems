#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n,m; cin>>n>>m;
	vector<vector<ll>> cakes(n,vector<ll>(3,0));
	for (ll i=0; i<n; i++) {
		ll x,y,z; cin>>x>>y>>z;
		cakes[i][0] = x;
		cakes[i][1] = y;
		cakes[i][2] = z;
	}

	ll ans=-1;
	for (ll i=0; i<8; i++) {
		//bitmask add or subtract
		vector<ll> eval(n);
		for (ll j=0; j<n; j++) {
			for (ll k=0; k<3; k++) {
				if (1<<k & i) eval[j]+=cakes[j][k];
				else eval[j]-=cakes[j][k];
			}
		}

		sort(eval.begin(),eval.end(),greater<ll>());
		ll temp=0;
		for (ll j=0; j<m; j++) temp+=eval[j];

		ans = max(ans,temp);
	}
	cout << ans << endl;
	return 0;
}
