#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> x;

void calcsums(vector<int> &lsums, vector<int>&rsums) {
	for (int i = 0; i < min(n, m); ++i) {
		lsums[i] += x[0];
		if (i > 0) lsums[i] += x[i];
		for (int j = i+m; j < x.size(); j += m) {
			lsums[j] += x[j] + lsums[j-m];
			if (x[j] == x[j-m])
				lsums[j] -= x[j];
		}
	}

	for (int i = n-1; i >= max(0, n-m); --i) {
		rsums[i] += x[n-1];
		if (i < n-1) rsums[i] += x[i];
		for (int j = i-m; j >= 0; j -= m) {
			rsums[j] += x[j] + rsums[j+m];
			if (x[j] == x[j+m])
				rsums[j] -= x[j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	x = vector<int>(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];

	vector<int> lsums(n), rsums(n);
	calcsums(lsums, rsums);

	for (int i : lsums) cout << i << ' '; cout << '\n';
	for (int i : rsums) cout << i << ' '; cout << '\n';

	int best = 2e9;
	cout << "idx: xi lsum rsum xil xir xi ans\n";
	for (int i = 0; i < n; ++i) {
		int ans = 0;
		int whyarewestillhere = (m + i - 1) / m;
		int isitjusttosuffer = (n - i - 2 + m) / m;

		ans = rsums[i] - x[i]*isitjusttosuffer;
		ans += x[i]*whyarewestillhere - lsums[i];

		cout << i << ": " << x[i] << ' ' << lsums[i] << ' '
		     << rsums[i] << ' ' << whyarewestillhere << ' '
		     << isitjusttosuffer << ' '
		     << whyarewestillhere-isitjusttosuffer 
		     << ' ' << ans*2 << '\n';

		best = min(best, ans*2);
	}
	cout << '\n';
	cout << best << '\n';

	return 0;
}