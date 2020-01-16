#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n,k; cin>>n>>k;
	int a[n];
	map<int,int> inSegment;
	set<int> segment;

	for (int i=0; i<n; i++)
		cin>>a[i];

	int maxl=0, maxr=0, maxlen=0;
	int l=0, r=0;
	while (r<n) {
		segment.insert(a[r]);
		inSegment[a[r]]++;
		
		while (segment.size()>k) {
			inSegment[a[l]]--;
			if (inSegment[a[l]]==0) segment.erase(a[l]);
			l++;
		}
		if (r-l>maxlen) {
			maxlen = r-l;
			maxl=l; maxr=r;
		}
		r++;
	}

	cout << maxl+1 << ' ' << maxr+1 << endl;
	return 0;
}
