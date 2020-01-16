//doesnt work because c++ is just stupid i guess

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> fac(2e5+1,1);
ll m = 1e9+7;

ll modpow(ll n, ll x) {
	if (n==1 or x==0) return 1;
	if (x==1) return n;
	ll res = 1;
	n %= m;
	while (x>0) {
		if (x%2==1) res = (res*n)%m;
		x /= 2;
		n=(n*n)%m;
	}
	return res;
}

ll inverse(ll n) {
	return modpow(n,m-2);
}

ll comb(ll n, ll r) {
	if (n==r or n==0) return 1;
	ll num = fac[n];
	ll denom = (fac[r]*fac[n-r])%m;
	return (num*inverse(denom))%m;
}

int main() {
	for (ll i=1; i<=2e5; i++) fac[i] = (fac[i-1]*i)%m;

	ll n,k; cin>>n>>k;
	vector<ll> balls(n);
	for (ll i=0; i<n; i++) cin>>balls[i];
	sort(balls.begin(),balls.end());

	ll sum=0;
	for (ll i=0; i<=n-k; i++) {
		ll c = comb(n-i-1,k-1);
		sum = (sum - balls[i]*c + balls[n-i-1]*c)%m;
	}

	cout << sum << endl;
	return 0;
}
