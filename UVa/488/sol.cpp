#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int a,f; cin>>a>>f;
        string out = "";
        
        for (int i=0; i<f; i++) {
            for (int j=1; j<a; j++) {
                for (int k=0; k<j; k++)
                    cout<<j;
                cout<<'\n';
            }
            for (int j=a; j>0; j--) {
                for (int k=0; k<j; k++)
                    cout<<j;
                cout<<'\n';
            }
            
            if (!(t==0 and i==f-1)) cout<<'\n';
        }
    }
    return 0;
}
