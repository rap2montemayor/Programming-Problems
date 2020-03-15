#include <bits/stdc++.h>
using namespace std;

bool balanced = true;
int solve() {
	int wl,dl,wr,dr;
	cin>>wl>>dl>>wr>>dr;
	if (wl==0) wl = solve();
	if (wr==0) wr = solve();
	balanced = balanced and wl*dl==wr*dr;
	return wl+wr;
}

int main() {
	int n; cin>>n;
	while (n--) {
		balanced = true;
		solve();
		balanced ? cout << "YES" : cout << "NO";
		n>0 ? cout << "\n\n" : cout << "\n";
	}
	return 0;
}
