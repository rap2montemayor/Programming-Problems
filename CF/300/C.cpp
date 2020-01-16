#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll m=1000000007;

bool isExcellent(int a, int b, int n, int alen) {
    int res=a*alen + b*(n-alen);
    while (res!=0) {
        if (res%10 != a and res%10 != b)
            return false;
        res/=10;
    }
    return true;
}

ll factorial(ll n) {
    if (n==1) return n;
    ll ans=1;
    for (int i=2; i<=n; i++) ans = (ans%m*i%m)%m;
    return ans;
}

ll pow(ll n, ll x) {
    if (n==1 or x==0) return 1;
    if (x==1) return n;

    int ans=1;
    while (x>0) {
        if (x%2==1) {
            ans = (ans%m*n%m)%m;
            x--;
        }
        ans = (ans%m*ans%m)%m;
        x/=2;
    }

    return ans;
}

ll combination(ll n, ll r) {
    ll num = factorial(n);
    ll denom = (factorial(r)%m * factorial(n-r)%m)%m;

    return (num*pow(denom,m-2))%m;
    //return num/denom;
}

int main() {
    ll a,b,n;
    cin>>a>>b>>n;

    ll ans=0;
    for (int i=0; i<=n; i++) {
        if (isExcellent(a,b,n,i)) {
            ans+=combination(n,i);
            ans%=m;
        }
    }
    cout << ans << endl;
    return 0;
}
