#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(ll a, ll b) {
    ll x = a, y = a*(69*b-1), z = 69*a*b; 
    cout << "YES\n";
    cout << x << ' ' << y << ' ' << z << '\n';
}

bool solveable(ll a, ll b) {
    return b != 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll t; cin >> t;
    while (t--) {
        ll a, b; cin >> a >> b;
        if (not solveable(a, b)) cout << "NO\n";
        else solve(a, b);
    }

    return 0;
}