#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int check(vi &pin, string &s) {
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'o') {
            bool good = false;
            for (int j : pin)
                good = good or j == i;
            if (not good) return 0;
        }
        if (s[i] == 'x') {
            bool good = true;
            for (int j : pin)
                good = good and j != i;
            if (not good) return 0;
        }
    }
    return 1;
}

int solve(int idx, vi &pin, string &s) {
    if (idx == 4) return check(pin, s);
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
        pin[idx] = i;
        ans += solve(idx+1, pin, s);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    vi pin(4, -1);
    cout << solve(0, pin, s) << '\n';
    
    return 0;
}