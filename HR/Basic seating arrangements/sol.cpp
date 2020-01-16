#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    vector<ll> facs(100000000);
    ll m=1000000007;
    facs[0]=1;
    for (int i=1; i<100000000; i++)
        facs[i]=(facs[i-1]%m*i%m)%m;
    
    return 0;
    int t; cin>>t;

    while (t--) {
        ll b,g; cin>>b>>g;
        int a1,a2,a3,a4,a5;
        a1=facs[b+g];
        a2=(facs[b+1]%m*facs[g]%m)%m;
        a3=(facs[g+1]%m*facs[b]%m)%m;
        a4=(facs[b]%m*facs[g]%m*2)%m;
        a5=(a2%m+a3%m-a4%m+m)%m;

        cout<<a1<<' '<<a2<<' '<<a3<<' '<<a4<<' '<<a5<<endl;
    }
    return 0;
}
