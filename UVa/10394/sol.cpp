#include <bits/stdc++.h>
using namespace std;

vector<bool> isPrime(20000001, true);
void genSieve() {
    isPrime[0] = isPrime[1] = false;
    for (long long i=2; i<isPrime.size(); ++i)
        for (long long j=i; j*i<isPrime.size(); ++j)
            isPrime[i*j] = false;
}

int primePair[100001];
void genPairs() {
    int idx = 1, first = 3;
    while (idx <= 100000) {
        if (isPrime[first] and isPrime[first+2]) {
            primePair[idx] = first;
            idx++;
        }
        first += 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    genSieve(); genPairs();
    int n;
    while (cin>>n)
        cout << '(' << primePair[n] << ", " << primePair[n]+2 << ")\n";
    return 0;
}