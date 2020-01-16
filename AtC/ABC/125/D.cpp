#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n; cin>>n;
	vector<ll> a(n);
	for (ll i=0; i<n; i++)
		cin>>a[i];
	
	//greedy?
	ll negs=0, zeroes=0, l=1e9+7, ans=0;
	for (ll i : a) {
		l = min(l,abs(i));
		ans += abs(i);
		if (i<0) negs++;
		if (i==0) zeroes++;
	}

	if (zeroes or negs%2==0) cout << ans << endl;
	else cout << ans-2*l << endl;
	return 0;
}
