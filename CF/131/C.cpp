#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<vector<ll>> combination(31, vector<ll>(31, 1));
    for (int i=2; i<31; i++)
        for (int j=1; j<i; j++)
            combination[i][j]=combination[i-1][j]+combination[i-1][j-1];
    ll n,m,t;
    cin>>n>>m>>t;

    ll ans=0;
    for (int i=4; i<t; i++) {
        if (i>n or t-i>m) continue;
        ans+=combination[n][i]*combination[m][t-i];
    }
    cout << ans << endl;
    return 0;
}
