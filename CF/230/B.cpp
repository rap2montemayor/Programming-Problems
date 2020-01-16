#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
bool TPrime(ull n) {
    ull count=2; // one and itself
    for (ull i=2; i*i<=n; i++) {
        if (n%i==0) {
            count+=2;
            if (i*i==n) count--;
            n/=i;
        }
        if (count>3) return false;
    }
    return count==3;
}
int main() {
    ull n; cin>>n;
    vector<ull> v(n);
    for (ull i=0; i<n; i++)
        cin>>v[i];
    for (ull i : v) { 
        if (TPrime(i)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
