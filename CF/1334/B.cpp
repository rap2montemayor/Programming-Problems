#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll t,n,x;
vi a, dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>t;
    while (t--) {
        cin>>n>>x;
        a = vi(n);
        for (ll i=0; i<n; i++)
            cin>>a[i];

        sort(a.begin(), a.end());
        ll l=0, r=n-1;
        ll people = 0, money = 0;

        while (r >= 0) {
            if ( a[r] < x )
                break;
            
            money += a[r];
            people++;
            r--;
        }
        l = r;
        while (l >= 0) {
            if ( money+a[l] >= (people+1)*x ) {
                money += a[l];
                people++;
            }
            l--;
        }

        cout << people << '\n';
    }
    return 0;
}