#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	while (n--) {
		string n; cin>>n;

		int oddMin=-1, evenMin=-1;
		for (int i=0; i<n-1; i++) {
			char temp=s[i];
			if (s[i]%2) { // odd
				oddMin=i+1;
			}
			else { // even
				evenMin=i+1;
			}
		}
	}
	return 0;
}
