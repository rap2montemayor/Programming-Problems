#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n,k; cin>>n>>k;
    vvi cities(n+1);
    for (ll i=0; i<n-1; i++) {
        ll u,v; cin>>u>>v;
        cities[u].push_back(v);
        cities[v].push_back(u);
    }

    //get fromRoot from 1
    vi fromRoot(n+1), prev(n+1);
    vector<bool> visited(n+1, false);
    queue<pii> q;
    q.push({1,0});
    visited[1] = true;
    while (!q.empty()) {
        ll idx = q.front().first;
        ll dist = q.front().second;
        q.pop();
        fromRoot[idx] = dist;
        for (ll i : cities[idx]) {
            if (!visited[i]) {
                visited[i]=true;
                prev[i] = idx;
                q.push({i,dist+1});
            }
        }
    }

    vi leaves;
    for (ll i=1; i<=n; i++)
        if (cities[i].size()==1)
            leaves.push_back(i);

    vi subtree(n+1,1);
    for (ll i : leaves) {
        ll idx = i, size=0;
        while (idx != 1) {
            subtree[idx] += size;
            idx = prev[idx];
            size++;
        }
    }
    
    
    priority_queue<ll> pq;
    for (ll i=1; i<=n; i++) {
        pq.push(fromRoot[i]-subtree[i]+1);
    }

    ll ans=0;
    for (ll i=0; i<k; i++) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << endl;
    return 0;
}