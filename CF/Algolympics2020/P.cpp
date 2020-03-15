#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if (b==0)
}

int main() {
	int t; cin>>t;

	while (t--) {
		int k,b; cin>>k>>b;
		
		b-=1;
		bool cool=true;
		for (int j=2; j<max(k,b); j++) {
			if (b%j==0 and k%j==0) {
				cool=false;
				break;
			}
			if (j>2) j++;
		}

		if (cool) cout << "COOL" << endl;
		else cout << "NOT COOL" << endl;
	}

	return 0;
}
