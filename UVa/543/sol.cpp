#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<bool> sieve(1000001,true);
    vector<int> primes;
    sieve[0] = false;
    sieve[1] = false;
    for (int i=2; i<1000001; i++)
        for (int j=2; i*j<1000001; j++)
            sieve[i*j]=false;
    
    int n = -1;
    while (n!=0) {
        cin>>n;
        for (int i=0; i<n; i++) {
            if (!sieve[i]) continue;
            if (sieve[n-i]) {
                cout << n << " = " << i << " + " << n-i << endl;
                break;
            }
        }
    }
    return 0;
}
