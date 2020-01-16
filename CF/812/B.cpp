#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <limits>
#define ll long long
using namespace std;


ll stringToBinary(string s) {
    ll out = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '1') out += (ll)1<<(s.length()-i-1);
    return out;
}

int rightBit(ll n, int size) {
    for (int i = 0; i < size; i++)
        if (n & (ll)1<<i) return size-1-i; 
    return 0;
}

int leftBit(ll n, int size) {
    for (int i = 0; i < size; i++)
        if (n & (ll)1<<(size-1-i)) return size-1-i; 
    return 0;
}


ll evalBitmask(ll bitmask, int n, int m, vector<ll> &b) {
    ll result = 0;
    for (int i = 0; i < b.size(); i++) {
        if (bitmask & ((ll)1<<i)) {
            int l = leftBit(b[i], m);
            result += l;
            if (i < b.size()-1) {
                if (bitmask & ((ll)1<<(i+1))) result += l;
                else result += m-l-1;
            }
        }
        else {
            int r = rightBit(b[i], m);
            result += r;
            if (i < b.size()-1) {
                if (bitmask & ((ll)1<<(i+1))) result += m-1-r;
                else result += r;
            }
        }
        if (i < b.size()-1) result++;
    }
    return result;
}

ll timeLights(int n, int m, vector<ll> &b) {
    ll lowest = numeric_limits<ll>::max();
    ll bitmask = 0;

    while (bitmask < 1<<15) {
        ll current = evalBitmask(bitmask, n, m, b); 
        if (current < lowest) lowest = current;
        bitmask += 2;
    }
    return lowest;
}

int main() {
    int n, m;
    vector<ll> b;
    
    cin >> n >> m;
    m += 2;
    b.reserve(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        b.push_back(stringToBinary(s));
    }

    reverse(b.begin(), b.end());
    while (b.back() == 0) {
        b.pop_back();
        n--;
    }

    cout << timeLights(n, m, b) << endl;
    return 0;
}
