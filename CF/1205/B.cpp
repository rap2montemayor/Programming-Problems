#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
static int INF = 1e9;

pair<vvi, vvi> groupbybits (vector<ll> &nums) {
	vvi bybits(61), bits(nums.size()) ;
	for (int i = 0; i < bybits.size(); ++i) {
		for (int j = 0; j < nums.size(); ++j) {
			if (((1<<i) & nums[j]) != 0) {
				bybits[i].push_back(j);
				bits[j].push_back(i);
			}
		}
	}

	return {bybits, bits};
}

int bfs(int s, vvi &bybits, vvi &bits) {
	vi dist(bits.size(), INF);
	queue<vi> q;
	q.push({s, 0, -1});
	dist[s] = 0;

	int res = INF;
	while (not q.empty()) {
		int idx = q.front()[0], d = q.front()[1], prev = q.front()[2];
		q.pop();

		vector<bool> visited(bits.size());
		visited[idx] = true;
		for (int i : bits[idx]) {
			for (int j : bybits[i]) {
				if (j == idx or j == prev or visited[j]) continue;
				if (dist[j] != INF) {
					return dist[idx] + dist[j] + 1;
				}
				visited[j] = true;
				dist[j] = d+1;
				if (dist[j] <= 120)
					q.push({j, d+1, idx});
			}
		}
	}

	return res;
}

int dothething(vector<ll> &nums) {
	pair<vvi, vvi> grouped = groupbybits(nums);
	vvi &bybits = grouped.first, &bits = grouped.second;

	int ans = INF;
	for (int i = 0; i < nums.size(); ++i) {
		ans = min(ans, bfs(i, bybits, bits));
	}
	return ans == INF ? -1 : ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<ll> nums(n);
	for (int i = 0; i < n; ++i)
		cin >> nums[i];

	cout << dothething(nums) << '\n';
	return 0;
}