#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n,k; cin>>n>>k;
	vector<pair<ll,ll>> sushi(n);
	vector<ll> replace;
	set<ll> toppings;
	for (ll i=0; i<n; i++)
		cin>>sushi[i].second>>sushi[i].first;

	sort(sushi.begin(),sushi.end());
	reverse(sushi.begin(),sushi.end());

	ll ans=0;
	for (ll i=0; i<k; i++) {
		ans+=sushi[i].first;
		if (toppings.count(sushi[i].second))
			replace.push_back(i);
		toppings.insert(sushi[i].second);
	}
	ans+=toppings.size()*toppings.size();

	ll temp = ans-toppings.size()*toppings.size();
	for (ll i=k; i<n; i++) {
		if (toppings.count(sushi[i].second)) continue;
		if (replace.empty()) break;

		toppings.insert(sushi[i].second);
		temp -= sushi[replace.back()].first;
		temp += sushi[i].first;
		replace.pop_back();

		ll bonus=toppings.size()*toppings.size();
		ans = max(ans,temp+bonus);
	}
	cout << ans << endl;

	return 0;
}
