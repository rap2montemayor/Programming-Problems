#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll INF = 2e9;
ll solve(vector<vector<ll>> mat, vector<bool> &removed) {
    ll n = mat.size();
    for (ll k=0; k<n; k++) {
        if (removed[k]) continue;
        for (ll i=0; i<n; i++) {
            if (removed[i]) continue;
            for (ll j=0; j<n; j++) {
                if (removed[j]) continue;
                if (mat[i][k] + mat[k][j] < mat[i][j]) {
                    mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
    }
    ll ans=0;
    for (ll i=0; i<n; i++) {
        if (removed[i]) continue;
        for (ll j=0; j<n; j++) {
            if (removed[j]) continue;
            ans += mat[i][j];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
            cout << mat[i][j] << ' ';
        cout << endl;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n; cin>>n;
    vector<vector<ll>> mat(n,vector<ll>(n));
    vector<bool> removed(n);
    for (ll i=0; i<n; i++)
        for (ll j=0; j<n; j++)
            cin>>mat[i][j];

    for (ll i=0; i<n; i++) {
        cout << solve(mat, removed) << "\n\n";
        ll remove; cin>>remove;
        removed[remove-1] = true;
    }
    // cout << endl;
    
    return 0;
}