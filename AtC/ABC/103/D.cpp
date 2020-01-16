#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> &a, pair<int,int> &b) {
	if (a.first==b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main() {
	int n,m; cin>>n>>m;
	vector<pair<int,int>> requests(m);
	for (int i=0; i<m; i++)
		cin>>requests[i].first>>requests[i].second;
	sort(requests.begin(),requests.end());

	int ans=0;
	int last=0;
	for (int i=0; i<m; i++) {
		if (requests[i].first >= last) {
			ans++;
			last = requests[i].second;
		}
		if (requests[i].second < last)
			last = requests[i].second;
	}
	cout << ans << endl;
	return 0;
}
