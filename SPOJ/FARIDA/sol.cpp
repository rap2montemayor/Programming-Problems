#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> memo;
ll solve(vector<ll> &a, ll idx, ll ans) {
    if (idx>=a.size()) return ans;
    if (memo[idx]>ans+a[idx]) return memo[idx];
    ll temp=ans;

    temp = max(temp,a[idx]+solve(a,idx+3,ans));
    temp = max(temp,a[idx]+solve(a,idx+2,ans));
    temp = max(temp,solve(a,idx+1,ans));

    memo[idx] = max(temp,ans);
    return memo[idx];
}

int main() {
    ll t; cin>>t;
    for (ll test=1; test<=t; test++) {
        ll n; cin>>n;
        vector<ll> a(n);
        memo = vector<ll>(n+2);
        for (ll i=0; i<n; i++)
            cin>>a[i];

        cout << "Case " << test << ": ";
        cout << solve(a,0,0) << endl;
    }
    return 0;
}
