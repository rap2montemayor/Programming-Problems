#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct union_find {
	vector<ll> p;
	union_find(ll n) {
		p = vector<ll>(n,-1);
	}

	ll find(ll x) {
		if (p[x] < 0)
			return x;
		else {
			p[x] = find(p[x]);
			return p[x];
		}
	}

  	bool unite(ll x, ll y) {
    	ll xp = find(x);
		ll yp = find(y);
    	if (xp == yp)
			return false;
    	if (p[xp] > p[yp])
			swap(xp,yp);
    	p[xp] += p[yp];
		p[yp] = xp;
    	return true;
  	}

  	ll size(ll x) {
		return -p[find(x)];
	}
};

int main() {
	ll n,m; cin>>n>>m;
	vector<ll> a(m),b(m);
	union_find uf(n+1);
	for (ll i=0; i<m; i++)
		cin>>a[i]>>b[i];
	vector<ll> ans(m);
	ll current = n*(n-1)/2;
	for (ll i=m-1; i>=0; i--) {
		ans[i]=current;
		if (uf.find(a[i]) != uf.find(b[i]))
			current -= uf.size(a[i]) * uf.size(b[i]);
		uf.unite(a[i],b[i]);
	}

	for (ll i : ans) cout << i << endl;
	return 0;
}
