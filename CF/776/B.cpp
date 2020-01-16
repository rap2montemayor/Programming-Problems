#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<bool> v(n+2,true);
    for (int i=2; i<n+2; i++) {
        for (int j=2; i*j<n+2; j++) {
            v[i*j]=false;
        }
    }

    if (n==1) {
        cout << "1\n1\n";
        return 0;
    }
    if (n==2) {
        cout << "1\n1 1\n";
        return 0;
    }
    cout << 2 << endl;
    for (int i=2; i<n+2; i++) {
        if (v[i]) cout << "1 ";
        else cout << "2 ";
    }
    cout << endl;
    return 0;
}
