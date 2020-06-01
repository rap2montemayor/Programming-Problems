#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &a, vector<int> &b) {
    if (a[0] > b[0]) return true;
    else if (a[0] == b[0]) {
        if (a[1] < b[1]) return true;
        else return false;
    }
    else return false;
}

void solve(vector<int> &a, vector<vector<int>> &zeroes, int n) {
    for (int i=1; i<=n; i++) {
        int l = zeroes[i-1][1], r = zeroes[i-1][2];
        int toChange = (r-l+1)%2==1 ? (l+r)/2 : (l+r-1)/2;
        a[toChange] = i;
    }
}

void genSegments(vector<vector<int>> &zeroes, int l, int r) {
    if (l>r) return;
    zeroes.push_back({r-l+1,l,r});

    int toChange = (r-l+1)%2==1 ? (l+r)/2 : (l+r-1)/2;
    genSegments(zeroes, l, toChange-1);
    genSegments(zeroes, toChange+1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n+1);
        vector<vector<int>> zeroes;
        genSegments(zeroes,1,n);
        sort(zeroes.begin(), zeroes.end(), comp);
        solve(a, zeroes, n);
        for (int i=1; i<=n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}