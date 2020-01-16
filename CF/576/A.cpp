#include <bits/stdc++.h>
using namespace std;

int power(int n, int x) {
    if (n==1 or x==0) return 1;
    int res=1;
    while (x>0) {
        if (x%2==1)
            res*=n;
        x/=2;
        n*=n;
    }
    return res;
}

int main() {
    int n; cin>>n;
    vector<bool> prime(n+1,true);
    vector<int> ans;
    prime[0] = false;
    prime[1] = false;
    for (int i=2; i<=n; i++)
        for (int j=2; i*j<=n; j++)
            prime[i*j]=false;

    for (int i=2; i<=n; i++) {
        if (!prime[i]) continue;
        else {
            for (int j=1; power(i,j)<=n; j++)
                ans.push_back(power(i,j));
        }
    }
    
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' ';
    cout << endl;
    return 0;
}
