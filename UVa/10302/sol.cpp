#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<ll> cubed(50001);
    for (ll i=1; i<=50000; i++)
        cubed[i] = i*i*i +cubed[i-1];

    int n;
    while (cin>>n)
        cout << cubed[n] << endl;
    return 0;
}
