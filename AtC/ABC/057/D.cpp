#include <bits/stdc++.h>
using namespace std;
#define ll long long

double getAverage(vector<ll> &v, ll a) {
	double sum=0;
	for (ll i=0; i<a; i++)
		sum+=v[i];
	return sum/a;
}

int main() {
	vector<vector<ll>> choose(51,vector<ll>(51,1));
	for (ll i=1; i<51; i++)
		for (ll j=1; j<i; j++)
			choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
		
	ll n,a,b; cin>>n>>a>>b;
	vector<ll> v(n);
	for (ll i=0; i<n; i++)
		cin>>v[i];
	sort(v.begin(),v.end(),greater<ll>());

	ll ans=0;
	if (v[a-1]==v[0]) {
		for (ll i=0; v[0]==v[a+i-1] and a+i<=b; i++) {
			ll count1 = count(v.begin(), v.begin()+a+i, v[0]);
			ll count2 = count(v.begin(), v.end(), v[0]);
			ans+=choose[count2][count1];
		}
	}
	else {
		ll count1 = count(v.begin(), v.begin()+a, v[a-1]);
		ll count2 = count(v.begin(), v.end(), v[a-1]);
		ans+=choose[count2][count1];
	}

	cout << fixed << setprecision(20) << getAverage(v,a) << endl;
	cout << ans << endl;
	return 0;
}

