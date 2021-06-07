#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<iii> viii;
typedef vector<viii> vviii;

ll n, m, INF = (1LL<<60);
vviii g;
vi dist;

ll solve() {
    priority_queue<ii> q;
    q.push({0, 0});
    dist[0] = INF;
    while (not q.empty()) {
        ll a = q.top().second, t = -q.top().first;
        q.pop();
        if (dist[a] < t) continue;
        dist[a] = t;
        for (iii &trip: g[a]) {
            ll b = get<0>(trip),
                c = get<1>(trip),
                d = get<2>(trip);
            ll wait = max(ll(sqrt(d))-t, 0LL);
            if (dist[b] == -1 or dist[b] > wait + t + c + d/(wait+t+1)) {
                dist[b] = wait + t + c + d/(wait+t+1);
                q.push({-(wait + t + c + d/(wait+t+1)), b});
            }
        }
    }
    return dist[n-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    g.resize(n);
    dist.resize(n, -1);
    for (int i = 0; i < m; ++i) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        g[a-1].push_back({b-1, c, d});
        g[b-1].push_back({a-1, c, d});
    }
    cout << solve() << '\n';

    return 0;
}