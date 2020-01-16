#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n,k; cin>>n>>k;
	vector<ll> x(n),y(n);
	for (ll i=0; i<n; i++)
		cin>>x[i]>>y[i];

	ll ans=~(1LL<<63);
	for (ll a=0; a<n; a++) {
		for (ll b=a; b<n; b++) {
			for (ll c=b; c<n; c++) {
				for (ll d=c; d<n; d++) {
					ll right = max({x[a],x[b],x[c],x[d]});
					ll left = min({x[a],x[b],x[c],x[d]});
					ll top = max({y[a],y[b],y[c],y[d]});
					ll bot = min({y[a],y[b],y[c],y[d]});
					ll area = abs((top-bot) * (right-left));
					ll contains=0;
					for (ll m=0; m<n; m++)
						if (x[m]>=left and x[m]<=right and y[m]>=bot and y[m]<=top)
							contains++;
					if (contains>=k and area<ans)
						ans=area;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
