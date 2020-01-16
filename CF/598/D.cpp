#include <bits/stdc++.h>
using namespace std;

vector<string> museum;
vector<vector<int>> maxPics;

int dfs(int i, int j) {
	museum[i][j] = 'v'; //visited
	int ans = 0;
	//up
	if (museum[i-1][j] == '*') ans++;
	else if (museum[i-1][j] == '.') ans += dfs(i-1, j);

	//down
	if (museum[i+1][j] == '*') ans++;
	else if (museum[i+1][j] == '.') ans += dfs(i+1, j);

	//left
	if (museum[i][j-1] == '*') ans++;
	else if (museum[i][j-1] == '.') ans += dfs(i, j-1);

	//right
	if (museum[i][j+1] == '*') ans++;
	else if (museum[i][j+1] == '.') ans += dfs(i, j+1);

	maxPics[i][j] = ans;
	return ans;
}

void fill(int i, int j, int n) {
	museum[i][j] = 'n';
	maxPics[i][j] = n; //visited
	if (museum[i-1][j] == 'v') fill(i-1, j, n);
	if (museum[i+1][j] == 'v') fill(i+1, j, n);
	if (museum[i][j-1] == 'v') fill(i, j-1, n);
	if (museum[i][j+1] == 'v') fill(i, j+1, n);
}

int main() {
	int n,m,k; cin>>n>>m>>k;
	museum = vector<string>(n);
	maxPics = vector<vector<int>>(n,vector<int>(m));

	for (int i=0; i<n; i++) cin>>museum[i];

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (museum[i][j] == '.') {
				dfs(i,j);
				fill(i,j,maxPics[i][j]);
			}
		}
	}

	while (k--) {
		int i,j; cin>>i>>j;
		i--; j--;
		cout << maxPics[i][j] << endl;
	}
	return 0;
}
