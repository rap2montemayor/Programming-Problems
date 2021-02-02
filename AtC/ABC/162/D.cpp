#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(string &s) {
	ll r, g, b, ans;
	r = g = b = 0;
	for (char c : s) {
		if (c == 'R') ++r;
		if (c == 'G') ++g;
		if (c == 'B') ++b;
	}
	ans = r*g*b;

	for (ll i = 0; i < s.size(); ++i) {
		for (ll j = i+1; j < s.size(); ++j) {
			if (j+j-i >= s.size()) break;
			//inspired by that meme from a while back
			if ((s[i] ^ s[j] ^ s[j+j-i]) == ('R' ^ 'G' ^ 'B'))
				--ans;
		}
	}

	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n; cin>>n;
    string s; cin>>s;
    cout << solve(s) << endl;
    return 0;
}