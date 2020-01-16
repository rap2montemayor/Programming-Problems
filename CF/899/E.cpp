#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	int first; cin>>first;
	vector<int> size({1}),val({first}),prev({-1}),next({1});
	priority_queue<pair<int,int>> pq;
	int seg=0;
	for (int i=1; i<n; i++) {
		int x; cin>>x;
		if (val[seg] != x) {
			pq.push({size[seg],-seg});
			size.push_back(0);
			val.push_back(x);
			prev.push_back(seg);
			next.push_back(seg+2);
			seg++;
		}
		size[seg]++;
	}
	pq.push({size[seg],-seg});

	int ans=0;
	while (!pq.empty()) {
		int sz = pq.top().first;
		int idx = -pq.top().second;
		int l = prev[idx];
		int r = next[idx];
		pq.pop();
		if (sz != size[idx]) continue;
		ans++;

		//remove
		if (l>=0) next[l]=r;
		if (r<=seg) prev[r]=l;
		size[idx]=-69;

		//merge
		if (l>=0 and r<=seg) {
			if (val[l] == val[r]) {
				size[l] = size[l]+size[r];
				next[l] = next[r];
				size[r] = -69;
				if (next[r]<=seg) prev[next[r]]=l;
				pq.push({size[l],-l});
			}
		}
	}

	cout << ans << endl;
	return 0;
}
