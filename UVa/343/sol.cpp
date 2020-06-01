#include <bits/stdc++.h>
using namespace std;

map<char,int> conv;
int convert(int base, string n) {
    int result = 0;
    for (int i=0; i<n.size(); i++)
        result += conv[n[i]] * pow(base,n.size()-i-1);
    return result;
}

bool canConvert(int base, string n) {
    for (char c : n)
        if (conv[c] >= base) return false;
    return true;
} 

void setupConversion() {
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i=0; i<digits.size(); i++)
        conv[digits[i]] = i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    setupConversion();

    string x,y;
    int xbase[37], ybase[37];

    while (cin>>x>>y) {
        memset(xbase,-1,sizeof xbase);
        memset(ybase,-1,sizeof ybase);
        for (int i=2; i<=36; i++) {
            if (canConvert(i,x)) xbase[i] = convert(i,x);
            if (canConvert(i,y)) ybase[i] = convert(i,y);
        }

        int ansx = -1, ansy = -1;
        for (int i=2; i<=36; i++) {
            if (xbase[i] == -1) continue; 
            for (int j=2; j<=36; j++) {
                if (ybase[j] == -1) continue; 
                if (xbase[i] == ybase[j]) {
                    ansx = i;
                    ansy = j;
                    break;
                }
            }
            if (ansx != -1) break;
        }

        if (ansx != -1)
            cout << x << " (base " << ansx << ") = " << y << " (base " << ansy << ")\n";
        else
            cout << x << " is not equal to " << y << " in any base 2..36\n";
    }
    return 0;
}