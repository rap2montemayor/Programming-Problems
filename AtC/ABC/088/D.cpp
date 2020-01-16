#include <bits/stdc++.h>
using namespace std;

int findPath(vector<vector<char>> &g) {
	int h=g.size(),w=g[0].size();
	int len=1;
	
	queue<vector<int>> q;
	q.push({0,0,1});
	g[0][0]='s';
	while (!q.empty()) {
		int i=q.front()[0], j=q.front()[1];
		len = max(len, q.front()[2]);
		q.pop();
		
		//down
		if (i+1 < h) {
			if (g[i+1][j]=='.') {
				q.push({i+1,j,len+1});
				g[i+1][j] = '#';
			}
		}
		//up
		if (i-1 >= 0) {
			if (g[i-1][j]=='.') {
				q.push({i-1,j,len+1});
				g[i-1][j] = '#';
			}
		}
		//right
		if (j+1 < w) {
			if (g[i][j+1]=='.') {
				q.push({i,j+1,len+1});
				g[i][j+1] = '#';
			}
		}
		//left
		if (j-1 >= 0) {
			if (g[i][j-1]=='.') {
				q.push({i,j-1,len+1});
				g[i][j-1] = '#';
			}
		}

		if (i==h-1 and j==w-1) break;
	}

	if (g[h-1][w-1]!='#') len=-1;
	return len;
}

int main() {
	int h,w; cin>>h>>w;
	vector<vector<char>> g(h,vector<char>(w));
	for (int i=0; i<h; i++)
		for (int j=0; j<w; j++)
			cin>>g[i][j];
	int ans=0;
	for (int i=0; i<h; i++)
		for (int j=0; j<w; j++)
			if (g[i][j]!='#') ans++;

	int pathlen = findPath(g);

	if (pathlen==-1) cout << -1 << endl;
	else cout << ans-pathlen << endl;
	return 0;
}
