#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	string s; cin >> s;

	// [l,r)
	int l = 0, r = 0, pkmns;
	set<char> letters;
	for (char c : s)
		letters.insert(c);
	pkmns = letters.size();

	int pokes = 0;
	map<char, int> cnt;
	while (r < s.size()) {
		if (pokes == pkmns) break;
		if (cnt[s[r]] == 0) ++pokes;
		++cnt[s[r]];
		++r;
	}

	int ans = r - l;
	while (r <= s.size()) {
		while (cnt[s[l]] > 1) {
			--cnt[s[l]];
			++l;
		}
		ans = min(ans, r - l);
		if (r == s.size()) break;
		++cnt[s[r]];
		++r;
	}

	cout << ans << '\n';
	return 0;
}