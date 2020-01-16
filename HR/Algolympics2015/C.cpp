#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	int n=0;
	while (n++<t) {
		int r,c; cin>>r>>c;
		vector<vector<int>> truss(r,vector<int>(c,0));
		string s; getline(cin, s);
		for (int i=0; i<r*2+1; i++) {
			getline(cin,s);
			if (!(i%2)) continue;
			for (int j=0; j<c*2+1; j++) {
				if (!(i%2)) continue;
				if (s[j]=='/') truss[i/2][j/2]=1;
			}
		}

		bool changed=true;
		while (changed) {
			changed=false;
			for (int i=0; i<r; i++) {
				for (int j=0; j<c; j++) {
					for (int i2=i+1; i2<r; i2++) {
						for (int j2=j+1; j2<c; j2++) {
							int supports=0;
							supports+=truss[i][j];
							supports+=truss[i][j2];
							supports+=truss[i2][j];
							supports+=truss[i2][j2];
							if (supports==3) {
								changed=true;
								truss[i][j]=1;
                                truss[i][j2]=1;
                                truss[i2][j]=1;
                                truss[i2][j2]=1;
							}
						}
					}
				}
			}
		}

		bool rigid=true;
		for (vector<int> v : truss) {
			for (int i : v) {
				if (!i) {
					rigid=false;
					break;
				}
			}
			if (!rigid) break;
		}
		
		cout << "Case #" << n << ": ";
		if (rigid) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0;
}
