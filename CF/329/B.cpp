#include <bits/stdc++.h>
using namespace std;

void bfs(int r, int c, vector<string> &g, vector<vector<int>> &dist) {
	queue<pair<int,int>> q;
	q.push({r,c});
	while (!q.empty()) {
		r = q.front().first, c = q.front().second;
		int d = dist[r][c];
		q.pop();

		//up
		if (r>0) {
			if (g[r-1][c] != 'T' and d+1 < dist[r-1][c]) {
				q.push({r-1,c});
				dist[r-1][c] = d+1;
			}
		}
		//down
		if (r<g.size()-1) {
			if (g[r+1][c] != 'T' and d+1 < dist[r+1][c]) {
				q.push({r+1,c});
				dist[r+1][c] = d+1;
			}
		}
		//left
		if (c>0) {
			if (g[r][c-1] != 'T' and d+1 < dist[r][c-1]) {
				q.push({r,c-1});
				dist[r][c-1] = d+1;
			}
		}
		//right
		if (c<g[0].size()-1) {
			if (g[r][c+1] != 'T' and d+1 < dist[r][c+1]) {
				q.push({r,c+1});
				dist[r][c+1] = d+1;
			}
		}
	}
}

int main() {
	//parse input, get start pos
	int r,c; cin>>r>>c;
	int startr,startc;
	vector<string> g(r);
	for (int i=0; i<r; i++) {
		cin>>g[i];
		for (int j=0; j<c; j++) {
			if (g[i][j] == 'S') {
				startr=i; startc=j;
			}
		}
	}
	
	//get dists from E
	bool done=false;
	vector<vector<int>> dist(r,vector<int>(c,r*c));
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			if (g[i][j] == 'E') {
				dist[i][j] = 0;
				bfs(i,j,g,dist);
				done=true;
				break;
			}
		}
		if (done) break;
	}

	//count breeders whose dist from E is < player
	int sDist = dist[startr][startc];
	int battles = 0;
	for (int i=0; i<r; i++)
		for (int j=0; j<c; j++)
			if (g[i][j] >= '0' and g[i][j] <= '9' and dist[i][j] <= sDist)
				battles += g[i][j]-'0';

	cout << battles << endl;
	return 0;
}
