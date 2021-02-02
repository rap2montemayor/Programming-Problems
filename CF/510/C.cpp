#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g(26);
vector<int> out(26);

string solve() {
	string res = "";
	queue<int> q;
	for (int i = 0; i < 26; ++i)
		if (out[i] == 0)
			q.push(i);

	while (not q.empty()) {
		int idx = q.front();
		res.push_back(char(idx + 'a'));
		q.pop();

		for (int i : g[idx]) {
			--out[i];
			if (out[i] == 0)
				q.push(i);
		}
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	string cur, prev;
	cin >> n >> cur;

	bool rip = false, match = true;
	for (int i = 0; i < n-1; ++i) {
		prev = cur;
		cin >> cur;
		match = true;
		for (int j = 0; j < min(cur.size(), prev.size()); ++j) {
			if (cur[j] != prev[j]) {
				match = false;
				g[prev[j]-'a'].push_back(cur[j]-'a');
				++out[cur[j]-'a'];
				break;
			}
		}
		if (match and prev.size() > cur.size())
			rip = true;
	}


	string ans;
	if (rip) ans = "rip";
	else ans = solve();
	
	if (ans.size() == 26)
		cout << ans << '\n';
	else
		cout << "Impossible\n";
	return 0;
}
