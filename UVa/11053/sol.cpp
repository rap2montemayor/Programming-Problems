#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, a, b;
ll next(ll x) {
    return (a*x*x + b) % n;
}

ll cycleLength() {
    ll p1 = next(0), p2 = next(next(0));
    while (p1 != p2) {
        p1 = next(p1);
        p2 = next(next(p2));
    }

    p2 = next(p1);
    ll length = 1;
    while (p1 != p2) {
        p2 = next(p2);
        length++;
    }

    return length;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (cin >> n >> a >> b) {
        //ll length = cycleLength();
        //cout << n << ' ' << length << ' ' << n-length << endl;
        ll x = 0;
        for (ll i=0; i<10; i++) {
            cout << x << endl;
            x = next(x);
        }
        cout << endl;
    }
     
    return 0;
}
