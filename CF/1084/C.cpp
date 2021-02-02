#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll m = 1e9+7;
ll dothething(vector<ll> &v) {
	if (v.size() == 0) return 0;
	ll ans = 0;
	for (ll i = v.size()-1; i >= 0; --i)
		ans = (ans%m + (v[i]%m * (1+ans)%m))%m;
	return ans;
}

vector<ll> createcounts(string &s) {
	vector<ll> cnts;
	ll cur, i = 0;
	while (i < s.size()) {
		cur = 0;
		for (; i < s.size(); ++i)
			if (s[i] == 'a') break;
		for (; i < s.size(); ++i) {
			if (s[i] == 'a') ++cur;
			if (s[i] == 'b') break;
		}
		if (cur != 0) cnts.push_back(cur);
	}
	return cnts;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s; cin >> s;
	vector<ll> cnts = createcounts(s);
	cout << dothething(cnts) << '\n';
	return 0;
}
