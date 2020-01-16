#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll totalNums(ll n) {
    if (n<2) return 1;
    for (ll i=0; 1ll<<i <= n; i++) n = n|(1ll<<i);
    return n;
}

ll getOnes(ll n, ll pos) {
    if (n==2) {
        if (pos<3) return 1;
        else return 2;
    }
    if (n==3)
        return pos;

    if (pos <= totalNums(n/2))
        return getOnes(n/2, pos);
    else if (pos > totalNums(n/2)+1)
        return getOnes(n/2, pos - totalNums(n/2) - 1) + n/2 + n%2;
    else
        return getOnes(n/2, totalNums(n/2)) + n%2;
}

ll getNum(ll n, ll pos) {
    if (n==2) {
        if (pos==1 or pos==3) return 1;
        else return 0;
    }
    if (n==3)
        return 1;

    if (pos <= totalNums(n/2)) // left
        return getNum(n/2, pos);
    else if (pos > totalNums(n/2)+1) // right
        return getNum(n/2, pos - totalNums(n/2) - 1);
    else // center
        return n%2;
}

int main() {
    ll n,l,r; cin>>n>>l>>r;

    if (n<2) {
        cout << n << endl;
        return 0;
    }

    while (getNum(n,l)==0) l++;
    while (getNum(n,r)==0) r--;
    cout << getOnes(n,r) - getOnes(n,l) + 1 << endl;
    return 0;
}
