#include <bits/stdc++.h>
using namespace std;

int bsearchlower(vector<int> &v, int n) {
    int l=0,r=v.size()-1,m;
    while (l<r) {
        m=(l+r)/2;
        if (v[m] < n)
            r=m;
        else if (v[m] > n)
            l=m;
        else
            l=m;
    }

    return m;
}

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++)
        cin>>v[i];
    sort(v.begin(), v.end());

    cout << bsearchlower(v, v.back()) << endl;
    return 0;
}
