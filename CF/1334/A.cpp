#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vi p(n+1), c(n+1);

        for (int i=1; i<=n; i++)
            cin>>p[i]>>c[i];

        bool legit=true;
        for (int i=1; i<=n; i++) {
            if (p[i] < c[i]) legit = false;
            if (p[i] < p[i-1]) legit = false;
            if (c[i] < c[i-1]) legit = false;
            if (c[i] > c[i-1] and p[i] <= p[i-1]) legit = false;
        }

        if (legit) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}