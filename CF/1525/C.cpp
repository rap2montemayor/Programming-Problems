#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAXN = 3e5;
int n, m, bots[MAXN], ans[MAXN];
char dir[MAXN];

bool comp(int a, int b) {
    return bots[a] < bots[b];
}

void thing(vi &v) {
    stack<int> s;
    for (int idx = 0; idx < v.size(); ++idx) {
        int i = v[idx];
        if (dir[i] == 'R') s.push(i);
        else {
            if (s.empty()) s.push(-i);
            else {
                int temp = s.top();
                if (temp < 0)
                    ans[i] = ans[-temp] = abs(bots[i] + bots[-temp]) / 2;
                else
                    ans[i] = ans[temp] = abs(bots[i] - bots[temp]) / 2;
                s.pop();
            }
        }
    }

    // all in s are going right
    for (int idx = v.size()-1; idx >= 0; --idx) {
        int i = v[idx];
        if (ans[i] != -1) continue;
        if (not s.empty() and abs(s.top()) == i)
            s.pop();
        if (s.empty()) break;

        int temp = abs(s.top());
        ans[i] = ans[temp] = min(m-bots[i], m-bots[temp]) + abs(bots[i] - bots[temp]) / 2;
        s.pop();

        // if (dir[i] == 'L') s.push(i);
        // else {
            // if (s.empty()) s.push(-i);
            // else {

            // }
        // }
    }
}

vi odd, even;
void solve() {
    odd.clear(); even.clear();
    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < n; ++i) {
        if (bots[i] & 1) odd.push_back(i);
        else even.push_back(i);
    }

    sort(odd.begin(), odd.end(), comp);
    thing(odd);

    sort(even.begin(), even.end(), comp);
    thing(even);

    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' '; cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> bots[i];
        for (int i = 0; i < n; ++i)
            cin >> dir[i];

        solve();
    }
    
    return 0;
}