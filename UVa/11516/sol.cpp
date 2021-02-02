#include <bits/stdc++.h>
using namespace std;

double eps = 1e-9;

int countrouters(vector<int> &houses, double r) {
	int count = 0, edge = -2e9;
	for (int i = 0; i < houses.size(); ++i) {
		if (houses[i] <= edge) continue;

		++count;
		edge = houses[i] + r * 2;
	}

	return count;
}

double bsearch(vector<int> &houses, int n) {
	double l = 0, r = houses.back(), m;
	while (abs(r-l) > eps) {
		m = (r+l) / 2;
		int a = countrouters(houses, m);
		if (a <= n) r = m;
		else l = m;
	}

	return l;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector<int> houses(m);
		for (int i = 0; i < m; ++i)
			cin >> houses[i];
		sort(houses.begin(), houses.end());

		cout << fixed << setprecision(1) << bsearch(houses, n) << '\n';
	}

	return 0;
}

