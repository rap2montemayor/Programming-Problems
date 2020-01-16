#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        int ans=0;
        ll withdraw=0;
        vector<ll> denoms(n+1);
        for (int i=0; i<n; i++)
            cin>>denoms[i];
        denoms[n]=numeric_limits<ll>::max();
        for (int i=0; i<n; i++) {
            if (withdraw+denoms[i] < denoms[i+1]) {
                withdraw+=denoms[i];
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
