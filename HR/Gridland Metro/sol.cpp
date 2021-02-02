#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

void squish(vii &v) {
	vii res;
	for (int i = 0; i < v.size()-1; ++i) {
		if (v[i+1].first > v[i].second) {
			res.push_back(v[i]);
			continue;
		}

		v[i+1].first = min(v[i].first, v[i+1].first);
		v[i+1].second = max(v[i].second, v[i+1].second);
	}
	res.push_back(v.back());

	v = res;
}

void process(map<int, vii> &tracks) {
	for (auto &p : tracks) {
		sort(p.second.begin(), p.second.end());
		squish(p.second);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long n, m, ans;
	int k;
	cin >> n >> m >> k;

	map<int, vii> tracks;
	for (int i = 0; i < k; ++i) {
		int r, c1, c2;
		cin >> r >> c1 >> c2;
		tracks[r].push_back({c1, c2});
	}
	process(tracks);

	ans = n*m;
	for (auto &piv : tracks) 
		for (ii &p : piv.second)
			ans -= p.second - p.first + 1;
	cout << ans << '\n';
	return 0;
}