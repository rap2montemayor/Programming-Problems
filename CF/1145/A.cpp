#include <bits/stdc++.h>
using namespace std;

bool sorted(vector<int> &v, int l, int r) {
    //[l,r)
    for (int i=l; i<r-1; i++)
        if (v[i] > v[i+1]) return false;

    return true;
}
int main() {
    int n; cin>>n;
    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin>>v[i];
    
    int l=0, r=n;
    while (!sorted(v,l,r)) {
        int mid=(l+r)/2;
        if (sorted(v,l,mid))
            r=mid;
        else
            l=mid;
    }

    cout<<r-l<<'\n';
    return 0;
}
