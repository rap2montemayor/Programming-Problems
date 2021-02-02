#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, q; cin >> n >> q;
	vector<int> a(n+1), b(n+1);
	vector<multiset<int>> k(2e5 + 1);
	multiset<int> even;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		k[b[i]].insert(a[i]);

	}
	for (multiset<int> &ms : k) {
		if (ms.empty()) continue;
		even.insert(*(ms.rbegin()));
	}

	for (int i = 0; i < q; ++i) {
		int c, d; cin >> c >> d;

		even.erase(even.find(*(k[b[c]].rbegin())));
		k[b[c]].erase(k[b[c]].find(a[c]));
		if (not k[b[c]].empty())
			even.insert(*(k[b[c]].rbegin()));

		if (not k[d].empty())
			even.erase(even.find(*(k[d].rbegin())));
		k[d].insert(a[c]);
		even.insert(*(k[d].rbegin()));

		b[c] = d;

		cout << *(even.begin()) << '\n';
	}

	return 0;
}