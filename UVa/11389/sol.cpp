#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,d,r;
    while (cin>>n>>d>>r) {
        if (n==0 and d==0 and r==0) break;
        vector<int> morn(n), night(n);
        for (int i=0; i<n; i++)
            cin>>morn[i];
        for (int i=0; i<n; i++)
            cin>>night[i];
        sort(morn.begin(), morn.end());
        sort(night.begin(), night.end());
        
        int overtime=0;
        for (int i=0; i<n; i++)
            if (morn[i]+night[n-i-1]>d)
                overtime+=(morn[i]+night[n-i-1])-d;
        cout << overtime*r << endl;
    }
    return 0;
}
