#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m; cin>>n>>m;
    vector<int> dorm(n+1,0);
    for (int i=1; i<n+1; i++) {
        cin>>dorm[i];
        dorm[i]+=dorm[i-1];
    }

    int p1=1,p2=1;
    for (int i=0; i<m; i++) {
        int l; cin>>l;
        while (dorm[p1]<l) p1++;
        if (l-dorm[p1]<1) p1--;
        p2=l-dorm[p1];
        cout<<p1+1<<' '<<p2<<endl;
    }

    return 0;
}
