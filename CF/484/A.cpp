#include <iostream>
using namespace std;

unsigned long long maxpopcount(unsigned long long l, unsigned long long r) {
    if (l == r) return l;
    else {
        unsigned long long pow2 = 1;
        while (pow2*2 <= r) pow2 *= 2;
        if (pow2 <= l) return maxpopcount(l-pow2, r-pow2) + pow2;
        else if (pow2*2 - 1 <= r) return pow2*2 -1;
        else return pow2-1;
    }
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        unsigned long long l, r;
        cin >> l >> r;
        cout << maxpopcount(l, r) << endl;
    }
    return 0;
}

