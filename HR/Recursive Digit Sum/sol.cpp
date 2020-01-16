#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll superDigit(ll n) {
    if (n<10) return n;
    ll m=0;
    while (n>0) {
        m+=(n%10);
        n/=10;
    }
    return superDigit(m);
}

ll superDigit(string s) {
    ll n=0;
    for (char c : s)
        n+=c-48;
    return n;
}

int main() {
    string n;
    ll k;
    cin>>n>>k;
    cout << superDigit(superDigit(n)*k) << endl;
    return 0;
}
