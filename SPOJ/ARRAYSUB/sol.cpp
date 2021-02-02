#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int k; cin >> k;

	multiset<int> cur;
	for (int i = 0; i < k; ++i)
		cur.insert(arr[i]);
	cout << *(cur.rbegin()) << ' ';

	for (int i = 0; i < n-k; ++i) {
		cur.erase(cur.find(arr[i]));
		cur.insert(arr[i+k]);
		cout << *(cur.rbegin()) << ' ';
	}

	return 0;
}
