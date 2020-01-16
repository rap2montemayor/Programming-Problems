#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll m = 1e9+7;

int main() {
	string s; cin>>s;
	vector<ll> ABC(s.size()), AB(s.size()), A(s.size());
	ll qmarks=1;
	if (s[0]=='A' or s[0]=='?') A[0]=1;
	if (s[0]=='?') qmarks=3;

	for (ll i=1; i<s.size(); i++) {
		A[i] = A[i-1];
		AB[i] = AB[i-1];
		ABC[i] = ABC[i-1];
		if (s[i]=='A')
			A[i] = (A[i-1] + qmarks)%m;
		if (s[i]=='B')
			AB[i] = (AB[i-1] + A[i-1])%m;
		if (s[i]=='C')
			ABC[i] = (ABC[i-1] + AB[i-1])%m;
		if (s[i]=='?') {
			A[i] = ((A[i-1]*3)%m + qmarks)%m;
			AB[i] = ((AB[i-1]*3)%m + A[i-1])%m; 
			ABC[i] = ((ABC[i-1]*3)%m + AB[i-1])%m;
			qmarks = (qmarks*3)%m;
		}
	}
	
	cout << ABC.back() << endl;

	return 0;
}
