#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,h; cin>>n>>h;
	vector<int> a(n),b(n);
	for (int i=0; i<n; i++)
		cin>>a[i]>>b[i];
	
	sort(a.begin(),a.end(),greater<int>());
	sort(b.begin(),b.end(),greater<int>());

	int moves=0;
	for (int i=0; i<n and h>0; i++) {
		if (b[i] < a[0]) break;
		h-=b[i];
		moves++;
	}

	if (h>0) {
		moves += h/a[0];
		if (h%a[0]>0) moves++;
	}
	/*
	while (h>0) {
		h-=a[0];
		moves++;
	}
	*/
	cout << moves << endl;
	
	return 0;
}
