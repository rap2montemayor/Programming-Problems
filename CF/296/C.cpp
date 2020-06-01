#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void countOps(vector<ll> &opCount, vector<vector<ll>> &queries) {
    for (vector<ll> &v : queries) {
        ll x = v[0]-1, y = v[1]-1;
        opCount[x]++;
        opCount[y+1]--;
    }

    for (int i=1; i < opCount.size(); i++)
        opCount[i] += opCount[i-1];
}

void applyOps(vector<vector<ll>> &ops, vector<ll> &opCount, vector<ll> &a) {
    for (ll i=0; i < opCount.size()-1; i++) {
        ll l = ops[i][0]-1, r = ops[i][1]-1, d = ops[i][2];
        a[l] += d * opCount[i];
        a[r+1] -= d * opCount[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n,m,k; cin>>n>>m>>k;
    vector<ll> a(n+1), opCount(m+1);
    vector<vector<ll>> ops(m, vector<ll>(3)), queries(k,vector<ll>(2));
    for (ll i=0; i<n; i++) cin>>a[i];
    for (ll i=0; i<m; i++) cin>>ops[i][0]>>ops[i][1]>>ops[i][2];
    for (ll i=0; i<k; i++) cin>>queries[i][0]>>queries[i][1];

    for (ll i=n-1; i>0; i--) a[i] -= a[i-1];
    
    countOps(opCount, queries);
    applyOps(ops, opCount, a);

    cout << a[0] << ' ';
    for (ll i=1; i<n; i++) {
        a[i] += a[i-1];
        cout << a[i] << ' ';
    }
    cout << endl;
    
    return 0;
}