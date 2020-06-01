#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }
ll getlcm(ll a, ll b) { return a*b / gcd(a,b); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n,t,h[50];
    while (cin>>n>>t) {
        if (n==0) break;
        for (int i=0; i<n; ++i)
            cin>>h[i];
        while (t--) {
            ll target; cin>>target;
            ll ans1 = 0, ans2 = 2e9;
            for (int i=0; i<n; ++i)
            for (int j=i+1; j<n; ++j)
            for (int k=j+1; k<n; ++k)
            for (int l=k+1; l<n; ++l) {
                ll lcm = getlcm(getlcm(getlcm(h[i],h[j]),h[k]),h[l]);
                ll temp = target-target%lcm;

                ans1 = max(ans1, temp);
                if (temp==target) ans2=temp;
                else ans2 = min(ans2,temp+lcm);
            }
            cout << ans1 << ' ' << ans2 << '\n';
        }
    }
    return 0;
}