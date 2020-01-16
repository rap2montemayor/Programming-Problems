#include <bits/stdc++.h>
using namespace std;

void primeFacs(int n) {
    cout<<n<<" = ";
    
    int fac=2;
    int exp=0;
    while (n>1) {
        if (n%fac==0) {
            exp++;
            n/=fac;
        }
        else {
            if (exp==1)
                cout<<fac<<"*";
            if (exp>1)
                cout<<fac<<"^"<<exp<<"*";
            if (fac!=2) fac+=2;
            else fac++;
            exp=0;
        }
    }
    if (exp==1)
        cout<<fac;
    else cout<<fac<<"^"<<exp;
    cout<<endl;
}

int main() {
    for (int i=2;i<=100000;i++)
        primeFacs(i);
    return 0;
}


