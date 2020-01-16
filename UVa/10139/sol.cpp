#include <bits/stdc++.h>
using namespace std;

int getMultiplicityFac(int n, int p) {
    int result = 0;
    n/=p;
    while (n>0) {
        result += n;
        n/=p;
    }
    return result;
}

int getMultiplicity(int n, int p) {
    int result=0;
    while (n>0) {
        if (n%p==0) result++;
        else break;
        n/=p;
    }
    return result;
}

vector<int> getPrimeFactors(int n) {
    vector<int> primes;
    for (int i=2; i*i<=n; i++) {
        if (n%i==0) {
            while (n%i==0) n/=i;
            primes.push_back(i);
        }
    }
    if (n!=1) primes.push_back(n);

    return primes;
}

int main() {
    int n, m;

    while (cin>>n>>m) {
        bool divisible=true;
        for (int i : getPrimeFactors(m)) {
            if (getMultiplicityFac(n,i) < getMultiplicity(m,i)) {
                divisible=false;
                break;
            }
        }

        if (divisible)
            cout << m << " divides " << n << "!\n";
        else
            cout << m << " does not divide " << n << "!\n";
    }
    return 0;
}
