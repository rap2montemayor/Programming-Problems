#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> w(5001), h(5001), nxt(5001), len(5001, 1);
int solve(int idx = 0) {
	if (len[idx] > 1)
		return len[idx];

	int cur = 1, temp = 1;
	for (int i = 1; i <= n; ++i) {
		if (w[idx] < w[i] and h[idx] < h[i]) {
			temp = 1 + solve(i);
			if (temp > cur) {
				cur = temp;
				len[idx] = cur;
				nxt[idx] = i;
			}
		}
	}

	return cur;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i <= n; ++i)
		cin >> w[i] >> h[i];

	solve();
	vector<int> ans;
	int cur = nxt[0];
	while (cur != 0) {
		ans.push_back(cur);
		cur = nxt[cur];
	}

	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i << ' ';
	cout << '\n';

	return 0;
}