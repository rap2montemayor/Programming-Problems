#include <iostream>
#include <string>
using namespace std;

long long evalBitmask(int bitmask) {
    string out;
    int firstbit = 30;
    while (firstbit > 0) {
        if (bitmask & (1<<firstbit)) break;
        firstbit--;
    }

    for (int i = firstbit; i >= 0; i--) {
        if (bitmask & (1<<i)) out.push_back('9');
        else out.push_back('0');
    }

    return stoll(out);
}

long long specialMultiple(int n) {
    int bitmask = 1;
    while (bitmask < 1<<30) {
        long long result = evalBitmask(bitmask);
        if (result % n == 0) return result;
        bitmask++;
    }
    return -1;
}

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n;
        cout << specialMultiple(n) << endl;
    }
    return 0;
}
