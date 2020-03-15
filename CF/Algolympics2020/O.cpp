#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin>>t;
	while (t--) {
		int r,c; cin>>r>>c;
		vector<vector<int>> g(r,vector<int>(c));
		int startr, startc;
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				char c; cin>>c;
				if (c == '.') g[i][j]=-1;
				else if (c == '#') g[i][j]=-2;
				else if (c == 'w') startr=i, startc=j;
			}
		}

		queue<vector<int>> q;
		q.push({startr,startc,0});
		while (!q.empty()) {
			int i=q.front()[0], j=q.front()[1], t=q.front()[2];
			q.pop();

			bool traversed = false;
			if (g[i][j]==-1) g[i][j]=t;
			else traversed = true;
			
			//
			if (i+1<r and g[i+1][j]==-1) {
				q.push(i+1,j,t+1)
			}
		}
	}
	return 0;
}
