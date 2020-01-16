#include <iostream>
#include <vector>
using namespace std;

long long modexp(long long x, long long e, long long m) {
    if (e == 1) return x%m;
    else if (e == 2) return ((x%m)*(x%m))%m;
    else if (e%2) {
        long long r = modexp(x,e-1,m);
        return ((r%m)*(x%m))%m;
    }
    else {
        long long r = modexp(x,e/2,m);
        return ((r%m)*(r%m))%m;
    }
}
int main() {
    long long n;
    long long oddcount = 0;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long x; cin >> x;
        if (x%2) oddcount++;
    }
    
    long long mod = 1000000007;
    if (oddcount == 0)
        cout << modexp(2,n,mod)-1 << endl;
    else if (oddcount == n)
        cout << 0 << endl;
    else
        cout << modexp(2,n-1,mod)-1 << endl;
    
    return 0;
}
