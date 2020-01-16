#include <bits/stdc++.h>
using namespace std;

int main() {
	int h,w; cin>>h>>w;
	vector<vector<int>> a(h,vector<int>(w));
	for (int i=0; i<h; i++)
		for (int j=0; j<w; j++)
			cin>>a[i][j];

	vector<int> x1,y1,x2,y2;
	for (int i=0; i<h; i++) {
		for (int j=0; j<w; j++) {
			if (a[i][j]%2==1) {
				a[i][j]--;
				if (i==h-1 and j==w-1) continue;
				if (j<w-1 or i==h-1) {
					a[i][j+1]++;
					x1.push_back(i+1);
					y1.push_back(j+1);
					x2.push_back(i+1);
					y2.push_back(j+2);
				}
				else {
					a[i+1][j]++;
					x1.push_back(i+1);
					y1.push_back(j+1);
					x2.push_back(i+2);
					y2.push_back(j+1);
				}
			}
		}
	}

	cout << x1.size() << endl;
	for (int i=0; i<x1.size(); i++)
		cout << x1[i] << ' ' << y1[i] << ' ' << x2[i] << ' ' << y2[i] << endl;

	return 0;
}
