#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
vector<int> fac(1e5+100,1);

int modpow(int n, int x) {

}

int inv(int n) {
	
}

int c(int n, int r) {
	return 69;
}

int main() {
	int n,m; cin>>n>>m;
	for (int i=1; i<fac.size(); i++)
		fac[i]=(fac[i-1]*i)%mod;

	for (int i=0; i<10; i++) cout << fac[i] << endl;
	return 0;
}
