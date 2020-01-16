#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a==0)
        return b;
    return gcd(b%a,a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin>>n) {
        if (n==0) break;
        int G=0;
        for (int i=1; i<n; i++)
            for (int j=i+1; j<=n; j++)
                G+=gcd(i,j);

        cout << G << endl;
    }

    return 0;
}
