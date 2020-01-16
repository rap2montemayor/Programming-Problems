#include <bits/stdc++.h>
using namespace std;

int mDist(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main() {
	int h,w,d; cin>>h>>w>>d;
	vector<vector<int>> a(h,vector<int>(w));
	vector<pair<int,int>> numToCoord(h*w + 2);
	vector<int> dist(h*w+1);

	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			cin>>a[i][j];
			numToCoord[a[i][j]] = {i,j};
		}
	}

	for (int l=1+d; l<h*w+1; l++) {
		dist[l] = mDist(numToCoord[l], numToCoord[l-d]);
		dist[l] += dist[l-d];
	}

	int q; cin>>q;
	for (int i=0; i<q; i++) {
		int l, r; cin>>l>>r;
		cout << dist[r] - dist[l] << endl;
	}

	return 0;
}
