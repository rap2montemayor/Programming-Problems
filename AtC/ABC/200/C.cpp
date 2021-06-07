#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long n, count[200] = {0};
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        ++count[a%200];
    }

    long long ans = 0;
    for (int i = 0; i < 200; ++i)
        ans += (count[i]*(count[i]-1))/2;
    cout << ans << '\n';
    
    return 0;
}