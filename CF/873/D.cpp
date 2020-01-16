#include <bits/stdc++.h>
using namespace std;

void unsort(vector<int> &v, int &calls, int l=-1, int r=-2) {
    if (calls==1) return;
    if (l==r) return;
    if (l==-1) {
        l=0;
        r=v.size();
    }

    int mid = (l+r)/2;
    int temp=v[mid-1];
    v[mid-1]=v[mid];
    v[mid]=temp;

    if (calls>=3 and mid-l>=2) {
        calls-=2;
        unsort(v,calls,l,mid);
    }
    if (calls>=3 and r-mid>=2) {
        calls-=2;
        unsort(v,calls,mid,r);
    }
}

int main() {
    int n,k; cin>>n>>k;
    
    vector<int> v(n);
    for (int i=0; i<n; i++)
        v[i] = i+1;
    if (k%2==0 or k>=2*n) { 
        cout<<"-1\n";
        return 0;
    }

    unsort(v,k); 
    for (int i : v) cout<<i<<' ';
    cout<<'\n';
    return 0;
}
