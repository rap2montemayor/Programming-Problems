#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k; cin>>n>>k;
    vector<int> factors;
    int factor=2;
    while (n>1) {
        if (factors.size() == k-1) break;
        if (n%factor==0) {
            factors.push_back(factor);
            n/=factor;
        }
        else factor++;
    }
    
    if (n==1) cout << -1 << endl;
    else {
        for (int i : factors) cout << i << ' ';
        cout << n << endl;
    }
    return 0;
}
