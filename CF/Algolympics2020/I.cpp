#include <bits/stdc++.h>
using namespace std;

string choices = "ABCDEFGH";
vector<vector<char>> moves;
vector<string> grid;
bool solved=false;

void solve(int kr, int kc, int fr, int fc) {
	queue<pair<int,int>> q;
	queue<char> qc;
	q.push({kr,kc});
	qc.push('S');

	while (!q.empty()) {
		int r = q.front().first, c = q.front().second;
		char mv = qc.front();
		q.pop();
		qc.pop();

		if (r<0 or c<0 or r>=grid.size() or c>=grid[0].size()) continue;
		if (grid[r][c]=='X') continue;
		if (moves[r][c]!='X') continue;
		moves[r][c]=mv;
		if (r==fr and c==fc) {
			solved=true;
			break;
		}

		for (char move : choices) {
			qc.push(move);
			if (move=='A') q.push({r-1,c-2});
			else if (move=='B') q.push({r-2,c-1});
			else if (move=='C') q.push({r-2,c+1});
			else if (move=='D') q.push({r-1,c+2});
			else if (move=='E') q.push({r+1,c+2});
			else if (move=='F') q.push({r+2,c+1});
			else if (move=='G') q.push({r+2,c-1});
			else if (move=='H') q.push({r+1,c-2});
		}
	}
}

void printMoves(int fr, int fc) {
	char c=moves[fr][fc];
	stack<char> ans;

	while (c != 'S') {
		ans.push(c);
		if (c=='A') fr+=1, fc+=2;
		else if (c=='B') fr+=2, fc+=1;
		else if (c=='C') fr+=2, fc-=1;
		else if (c=='D') fr+=1, fc-=2;
		else if (c=='E') fr-=1, fc-=2;
		else if (c=='F') fr-=2, fc-=1;
		else if (c=='G') fr-=2, fc+=1;
		else if (c=='H') fr-=1, fc+=2;
		c = moves[fr][fc];
	}
	while (!ans.empty()) {
		cout << ans.top();
		ans.pop();
	}
	cout << endl;
}

int main() {
	int t; cin>>t;
	
	while (t--) {
		int r,c; cin>>r>>c;
		int kr, kc, fr, fc;
		moves = vector<vector<char>>(r,vector<char>(c,'X'));
		grid = vector<string>(r);
		solved = false;

		for (int i=0; i<r; i++) {
			cin>>grid[i];
			for (int j=0; j<c; j++) {
				if (grid[i][j]=='K') kr=i, kc=j;
				else if (grid[i][j]=='F') fr=i, fc=j;
			}
		}

		solve(kr, kc, fr, fc);
		if (solved) {
			cout << "Whinny" << endl;
			printMoves(fr,fc);
		}
		else cout << "Neigh" << endl;
	}
	return 0;
}
