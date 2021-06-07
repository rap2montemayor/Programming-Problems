#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long n; cin >> n;
    cout << n << ' ';
    while (n != 1) cout << (n = (n&1 ? n*3+1 : n/2)) << ' ';
    return 0;
}
