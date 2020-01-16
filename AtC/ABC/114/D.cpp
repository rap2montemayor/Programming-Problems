#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin>>n;
	vector<int> divs(n+1,1);
	divs[0] = divs[1] = 0;
	for (int i=2; i<=n; i++) {
		int x = i;
		for (int j=2; j<=x; j++) {
			while (x%j==0) {
				x/=j;
				divs[j]++;
			}
		}
	}
	int d75=0,d25=0,d15=0,d5=0,d3=0;
	for (int i : divs) {
		if (i >= 75) d75++;
		if (i >= 25) d25++;
		if (i >= 15) d15++;
		if (i >= 5) d5++;
		if (i >= 3) d3++;
	}

	cout << d75 + d25*(d3-1) + d15*(d5-1) + d5*(d5-1)*(d3-2)/2 << endl;
	return 0;
}
