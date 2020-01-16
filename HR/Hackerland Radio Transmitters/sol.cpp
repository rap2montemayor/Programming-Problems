#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin>>n>>k;
    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin>>v[i];
    sort(v.begin(), v.end()); 

    int ans=0, i=0;
    while (i<n) {
        ans++;
        int find=v[i]+k;
        while (v[i]<=find and i<n) i++;
        i--;
        find=v[i]+k;
        while (v[i]<=find and i<n) i++;
    }
    cout << ans << endl;
    return 0;
}
