#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin>>t;
	while (t--) {
		int r,c; cin>>r>>c;
		vector<vector<char>> g(r,vector<char>(c));
		vector<vector<int>> direction(r,vector<int>(c,'0'));
		int startr, startc;
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				cin>>g[i][j];
				if (g[i][j]=='w')
					startr=i, startc=j;
			}
		}

		//r, c, time, direction
		//1 - up 2 - down 3 - left 4 - right
		//5 - ripple left, 6 - ripple right
		queue<vector<int>> q;
		q.push({startr,startc,0,2});
		while (!q.empty()) {
			int i=q.front()[0],
				j=q.front()[1],
				t = q.front()[2],
				dir = q.front()[3];
			q.pop();

			if (direction[i][j]==0) direction[i][j]=dir;
			else if (direction[i][j]==1) {}
			else if (direction[i][j]==2) {}
			else if (direction[i][j]==3) {}
			else if (direction[i][j]==4) {}
			else if (direction[i][j]==5) {}
			else if (direction[i][j]==6) {}

			bool onFloor = i!=r-1 and g[i+1][j]=='#';
			bool canLeft = j!=0 and g[i][j-1]!='#';
			bool canRight = j!=c-1 and g[i][j+1]!='#';
			bool canUp = i!=0 and g[i-1][j]!='#';
			bool onRipple = i!=r-1 and (direction[i+1][j]==5 or direction[i+1][j]==6);

			bool ripFromLeft = canLeft and direction[i][j-1]==6;
			bool ripFromRight = canRight and direction[i][j+1]==5;

			vector<int> goUp({i-1,j,t+1,1});
			vector<int> goDown({i+1,j,t+1,2});
			vector<int> goLeft({i,j-1,t+1,3});
			vector<int> goRight({i,j+1,t+1,4});
			vector<int> rippleLeft({i,j-1,t,5});
			vector<int> rippleRight({i,j+1,t,6});

			if (dir==1) { //up

			}
			else if (dir==2) { //down
				if (not onFloor) q.push(goDown);
				if (onFloor and canLeft) q.push(goLeft);
				if (onFloor and canRight) q.push(goRight);
			}
			else if (dir==3) { //left
				if (not onFloor) q.push(goDown);
				else if (canLeft) q.push(goLeft);
				else if (canRight) q.push(rippleRight);
			}
			else if (dir==4) { //right
				if (not onFloor) q.push(goDown);
				else if (canRight) q.push(goRight);
				else if (canLeft) q.push(rippleLeft);
			}
			else if (dir==5) { //ripple left
				if (not onFloor and not onRipple) { } //nothing
				else if (canLeft and ripFromLeft) {
					if (canUp) q.push(goUp);
				}
				else if (canLeft) q.push(rippleLeft);
			}
			else if (dir==6) { //ripple right
				if (not onFloor and not onRipple) { } //nothing
				else if (canRight and ripFromRight) {
					if (canUp) q.push(goUp);
				}
				else if (canRight) q.push(rippleRight);
			}

			for (vector<int> v : direction) {
				for (int x : v) {
					if (x==1) cout << '^';
					else if (x==2) cout << 'v';
					else if (x==3) cout << '<';
					else if (x==4) cout << '>';
					else if (x==5) cout << '(';
					else if (x==6) cout << ')';
					else cout << '.';
				}
				cout << endl;
			}
			cout << endl;
		}
	}
	return 0;
}
