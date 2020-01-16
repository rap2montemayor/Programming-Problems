#include <bits/stdc++.h>
using namespace std;

int greatestBit(int n) {
    int bit=0;
    while (1<<bit < n)
        bit++;
    if (1<<bit == n) return bit;
    else return bit-1;
}

int main() {
    int n;
    int t=1;
    while (cin>>n) {
        if (n < 0) break;
        int gbit=greatestBit(n);
        if (1<<gbit == n) cout << "Case " << t << ": " << gbit << endl;
        else cout << "Case " << t << ": " << gbit+1 << endl;
        t++;
    }
    return 0;
}
