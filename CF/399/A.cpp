#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,p,k; cin>>n>>p>>k;
    
    if (p-k > 1) cout << "<< ";
    for (int i=p-k; i<=p+k; i++) {
        if (i <= 0) i=1;
        if (i > n)
            break;
        if (i==p) cout << "(" << i << ") ";
        else cout << i << ' ';
    }
    if (p+k < n) cout << ">>\n";
    else cout << '\n';
    return 0;
}
