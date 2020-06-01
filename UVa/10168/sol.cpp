#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime(10000000, true);
void genSieve() {
    isPrime[0] = isPrime[1] = false;
    for (long long i=2; i<isPrime.size(); ++i)
        for (long long j=i; i*j<isPrime.size(); ++j)
            isPrime[i*j] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    genSieve();
    int n;
    while (cin>>n) {
        if (n < 8) cout << "Impossible.\n";
        else {
            if (n%2==0) {
                cout << "2 2 ";
                n -= 4;
            }
            else {
                cout << "3 2 ";
                n -= 5;
            }

            for (int i=2; i<n; i++) {
                if (isPrime[i] and isPrime[n-i]) {
                    cout << i << ' ' << n-i << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}