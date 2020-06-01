#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll modpow(ll b, ll p, ll m) {
    if (p == 0) return 1;

    ll ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = (ans*b) % m;
        b = (b*b) % m;
        p /= 2;
    }
    return ans % m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll B,P,M;
    while (cin>>B>>P>>M)
        cout << modpow(B,P,M) << '\n';
    return 0;
}