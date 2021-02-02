#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &h, int idx, int s, int b) {
	if (b == 0 or idx == 0) return 0;
	return max(
		solve(h, idx-1, s, b-1) + s*h[idx],
		solve(h, idx-1, s-1, b)
	);
}

int search(vector<int> &h, int n) {
	int ans = h.back();
	for (int i = 1; i <= n; ++i)
		ans = max(solve(h, n-1, i, n-i+1), ans);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> h(n);
		for (int i = 0; i < n; ++i)
			cin >> h[i];
		sort(h.begin(), h.end());

		cout << search(h, n) << '\n';
		
	}
	return 0;
}
