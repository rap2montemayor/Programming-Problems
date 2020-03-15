#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
vector<bool> isPrime(1000,true);
vector<int> occurences(1000);

long long solve(int depth) {
	if (depth>7) return 0;
	long long result = 1;
	for (int i : used) result*=i;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	isPrime[0] = isPrime[1] = false;
	for (int i=2; i<1000; i++)
		for (int j=i; i*j<1000; j++)
			isPrime[i*j]=false;
	
	int k,b; cin>>k>>b;
	vector<int> K(k), B(b);
	for (int i=0; i<k; i++) cin>>K[i];
	for (int i=0; i<b; i++) { cin>>B[i]; B[i]--; }

	for (int i=2; i<1000; i++) {

	}
	
	return 0;
}
